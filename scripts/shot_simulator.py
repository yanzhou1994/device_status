"""Capture the LVGL simulator window (Windows) to a PNG.

Usage: python tools/shot_simulator.py build/shot.png
"""
import ctypes
import ctypes.wintypes as wt
import sys
import time

from PIL import ImageGrab

TITLE = "LVGL Simulator"


def find_window(title):
    u = ctypes.windll.user32
    u.FindWindowW.restype = ctypes.c_void_p
    u.FindWindowW.argtypes = [wt.LPCWSTR, wt.LPCWSTR]
    return u.FindWindowW(None, title)


def main():
    # Make this process DPI aware so GetClientRect / ImageGrab agree on pixels.
    try:
        ctypes.windll.shcore.SetProcessDpiAwareness(2)
    except Exception:
        ctypes.windll.user32.SetProcessDPIAware()

    out = sys.argv[1] if len(sys.argv) > 1 else "shot.png"
    hwnd = find_window(TITLE)
    if not hwnd:
        print("window not found")
        return 1

    u = ctypes.windll.user32
    u.ShowWindow(ctypes.c_void_p(hwnd), 9)  # SW_RESTORE
    u.SetForegroundWindow(ctypes.c_void_p(hwnd))
    time.sleep(0.5)

    rect = wt.RECT()
    u.GetClientRect(ctypes.c_void_p(hwnd), ctypes.byref(rect))
    origin = wt.POINT(0, 0)
    u.ClientToScreen(ctypes.c_void_p(hwnd), ctypes.byref(origin))

    w = rect.right - rect.left
    h = rect.bottom - rect.top

    # ImageGrab(window=...) captures the window itself, so it also works when
    # another window is on top (a plain screen grab would capture that one).
    try:
        img = ImageGrab.grab(window=hwnd)
    except TypeError:
        img = ImageGrab.grab(bbox=(origin.x, origin.y, origin.x + w, origin.y + h))
    img.save(out)
    print(f"saved {out} {w}x{h}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
