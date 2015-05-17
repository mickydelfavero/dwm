#dwm - dynamic window manager#

dwm is an extremely fast, small, and dynamic window manager for X.

### My dwm setup ###

This is my dwm setup, I've started from git clone http://git.suckless.org/dwm and porting some patches in that order:

1. dwm-6.1-attachabove.diff
2. dwmfifo.diff
3. dwm-6.1-pertag.diff
4. dwm-6.1-runorraise.diff
5. dwm-6.1-save_floats.diff
6. dwm-6.1-single_window_no_border.diff
7. dwm-6.1-statusallmons.diff
8. dwm-6.1-swapfocus.diff
9. dwm-6.1-systray.diff

I've also made a small improvement based on suggestion taken from https://www.mail-archive.com/dwm@suckless.org/msg01872.html to raise focused window.

Default layout is *float*

### Keys ###

*MODKEY* is *left-windows* key

MODKEY p           | dmenu
MODKEY t           | urxvt
MODKEY Shift t     | urxvt -geometry 120x48
MODKEY e           | emacs
MODKEY Shift x     | jitsi
MODKEY Shift w     | chrome
MODKEY b           | togglebar
MODKEY j           | focusstack +1
MODKEY k           | focusstack -1
MODKEY i           | incmaster +1
MODKEY d           | incmaster -1
MODKEY h           | setmfact -0.05
MODKEY l           | setmfact +0.05
MODKEY Return      | zoom
MODKEY Tab         | view
MODKEY c           | killclient
MODKEY t           | setlayout (tile)
MODKEY f           | setlayout (float)
MODKEY m           | setlayout (monocle)
MODKEY Space       | setlayout defaul (float)
MODKEY Shift Space | togglefloating
MODKEY 0           | view
MODKEY Shift 0     | tag
MODKEY Comma       | tagmon -1
MODKEY Period      | tagmon +1
MODKEY Shift q     | quit

### Tags ###

From *F1* to *F9*
