"""Regenerate the Chinese font C arrays of this LVGL Pro project.

LVGL's built-in fonts have no CJK glyphs, so the fonts declared in globals.xml
are baked from the Windows "DengXian" family with lv_font_conv. Only the glyphs
that actually appear in the UI are included, so each font stays small.

The character set is collected automatically from the project sources, so
adding text to a screen and re-running this script is all that is needed.

Requirements: Node.js (npx). The DengXian TTFs are bundled in fonts/ttf/.
Usage:  python scripts/gen_fonts.py
"""

import pathlib
import re
import subprocess
import sys

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


def main() -> int:
    symbols = collect_symbols()
    print(f"{len(symbols)} non-ASCII glyphs: {symbols}")

    for name, size, ttf in FONTS:
        out = ROOT / "fonts" / f"{name}.c"
        print(f"  {out.name} ({size}px)")
        cmd = [
            "npx", "--yes", "lv_font_conv",
            "--font", ttf,
            "--size", str(size),
            "--bpp", "4",
            "--no-compress",
            "--range", "0x20-0x7F",
            "--symbols", symbols,
            "--format", "lvgl",
            "--lv-include", "lvgl.h",
            "-o", str(out),
        ]
        subprocess.run(cmd, check=True, shell=(sys.platform == "win32"))

    print("Done.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
