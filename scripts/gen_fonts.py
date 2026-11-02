"""Regenerate the Chinese font C arrays of this LVGL Pro project.

LVGL's built-in fonts have no CJK glyphs, so the fonts declared in globals.xml
are baked from the Windows "DengXian" family with lv_font_conv. Only the glyphs
that actually appear in the UI are included, so each font stays small.

IMPORTANT
---------
The LVGL Pro Editor rebuilds `fonts/<name>_default_data.c` itself whenever it
regenerates assets, and it only bakes what globals.xml asks for. If a `<bin>`
has no `symbols` / `range` attribute the editor falls back to plain ASCII, which
silently wipes every Chinese glyph and makes the preview show blank labels.

So this script does two things:
  1. collects every non-ASCII character used in the project sources,
  2. writes that list back into globals.xml (`range` + `symbols`), then builds
     the C arrays with exactly the same options the editor would use.

Requirements: Node.js (npx). The DengXian TTFs are bundled in fonts/ttf/.
Usage:  python scripts/gen_fonts.py
"""

import pathlib
import re
import subprocess
import sys
from xml.sax.saxutils import escape

ROOT = pathlib.Path(__file__).resolve().parent.parent

# Kept inside the project because globals.xml src_path must be project-relative.
REGULAR = str(ROOT / "fonts" / "ttf" / "DengXian.ttf")
BOLD = str(ROOT / "fonts" / "ttf" / "Dengb.ttf")

# (output file, size, ttf)
FONTS = [
    ("font_title_default_data", 26, BOLD),
    ("font_value_default_data", 30, BOLD),
    ("font_h3_default_data", 18, BOLD),
    ("font_h4_default_data", 16, BOLD),
    ("font_body_default_data", 16, REGULAR),
    ("font_small_default_data", 14, REGULAR),
]

# Source files that may contain user-visible text.
SOURCE_GLOBS = ["*.c", "*.h", "*.xml", "screens/*.c", "screens/*.h", "screens/*.xml"]

ASCII_RANGE = "0x20-0x7F"

GLOBALS_XML = ROOT / "globals.xml"


def strip_comments(text: str) -> str:
    """Drop comments so only real UI strings contribute glyphs."""
    text = re.sub(r"/\*.*?\*/", " ", text, flags=re.S)
    text = re.sub(r"//[^\n]*", " ", text)
    return re.sub(r"<!--.*?-->", " ", text, flags=re.S)


def collect_symbols() -> str:
    chars = set("°")
    for pattern in SOURCE_GLOBS:
        for path in ROOT.glob(pattern):
            if path.parts[-2] == "fonts":
                continue
            text = strip_comments(path.read_text(encoding="utf-8", errors="ignore"))
            for ch in text:
                if ord(ch) > 0x7F:
                    chars.add(ch)
    return "".join(sorted(chars))


def sync_globals(symbols: str) -> bool:
    """Write `range` + `symbols` into every <bin> of globals.xml.

    Returns True when the file had to be rewritten.
    """
    src = GLOBALS_XML.read_text(encoding="utf-8")
    wanted = [
        ("range", ASCII_RANGE),
        ("symbols", escape(symbols, {'"': "&quot;"})),
    ]

    def fix_bin(match: "re.Match") -> str:
        tag = match.group(0)
        for attr, value in wanted:
            pattern = re.compile(rf'\b{attr}="[^"]*"')
            if pattern.search(tag):
                tag = pattern.sub(f'{attr}="{value}"', tag)
            else:
                tag = tag.replace("as_file=", f'{attr}="{value}" as_file=', 1)
        return tag

    out = re.sub(r"<bin\b[^>]*/>", fix_bin, src)
    if out != src:
        GLOBALS_XML.write_text(out, encoding="utf-8", newline="\n")
    return out != src


def main() -> int:
    symbols = collect_symbols()
    print(f"{len(symbols)} non-ASCII glyphs: {symbols}")
    if sync_globals(symbols):
        print("  globals.xml: range/symbols updated")

    for name, size, ttf in FONTS:
        out = ROOT / "fonts" / f"{name}.c"
        print(f"  {out.name} ({size}px)")
        cmd = [
            "npx", "--yes", "lv_font_conv",
            "--font", ttf,
            "--size", str(size),
            "--bpp", "4",
            "--no-compress",
            "--range", ASCII_RANGE,
            "--symbols", symbols,
            "--format", "lvgl",
            "-o", str(out),
        ]
        subprocess.run(cmd, check=True, shell=(sys.platform == "win32"))

    print("Done.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
