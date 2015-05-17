/* See LICENSE file for copyright and license details. */

/* appearance */
static const char *fonts[] = {
  "Bitstream Vera Sans Mono:size=12",
  "Liberation Mono:size=12"
};

static const char dmenufont[] = "Bitstream Vera Sans Mono:size=12";

static const char normbordercolor[] = "#444444";
static const char normbgcolor[]     = "#222222";
static const char normfgcolor[]     = "#bbbbbb";

static const char selbordercolor[]  = "#777777";
static const char selbgcolor[]      = "#444444";
static const char selfgcolor[]      = "#e0e0e0";

/* border pixel of windows */
static const unsigned int borderpx  = 1;
/* snap pixel */
static const unsigned int snap      = 2;

/* systray */
/* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systraypinning = 0;  
/* systray spacing */
static const unsigned int systrayspacing = 2;
/* True: if pinning fails, display systray on the first monitor */
/* False: display systray on the last monitor */
static const Bool systraypinningfailfirst = True;
/* False means no systray */
static const Bool showsystray       = True;

/* bar */
/* False means no bar */
static const Bool showbar           = True;
/* False means bottom bar */
static const Bool topbar            = True; 

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            True,        -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       False,       -1 },
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = True; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[F]",      NULL },
	{ "[T]",      tile },
	{ "[M]",      monocle },
};

/* key definitions */
// left Alt
// #define MODKEY Mod1Mask
// left windows
#define MODKEY Mod4Mask

#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };

// static const char *termcmd[]  = { "st", NULL };
static const char *term[] = { "urxvt", NULL };
static const char *bigterm[]= { "urxvt", "-geometry", "120x48", NULL };
static const char *emacs[] = { "emacs", NULL };
static const char *xmpp[] = { "jitsi", NULL };
static const char *www[] = { "google-chrome", NULL };

static Key keys[] = {
  /* modifier                     key        function        argument */
  { MODKEY,            XK_p,      spawn,          {.v = dmenucmd } },
  { MODKEY,            XK_t,      spawn,          {.v = term } },
  { MODKEY|ShiftMask,  XK_t,      spawn,          {.v = bigterm } },
  { MODKEY,            XK_e,      spawn,          {.v = emacs } },
  { MODKEY|ShiftMask,  XK_x,      spawn,          {.v = xmpp } },
  { MODKEY|ShiftMask,  XK_w,      spawn,          {.v = www } },
  { MODKEY,            XK_b,      togglebar,      {0} },
  { MODKEY,            XK_j,      focusstack,     {.i = +1 } },
  { MODKEY,            XK_k,      focusstack,     {.i = -1 } },
  { MODKEY,            XK_i,      incnmaster,     {.i = +1 } },
  { MODKEY,            XK_d,      incnmaster,     {.i = -1 } },
  { MODKEY,            XK_h,      setmfact,       {.f = -0.05} },
  { MODKEY,            XK_l,      setmfact,       {.f = +0.05} },
  { MODKEY,            XK_Return, zoom,           {0} },
  { MODKEY,            XK_Tab,    view,           {0} },
  { MODKEY|ShiftMask,  XK_c,      killclient,     {0} },
  { MODKEY,            XK_t,      setlayout,      {.v = &layouts[0]} },
  { MODKEY,            XK_f,      setlayout,      {.v = &layouts[1]} },
  { MODKEY,            XK_m,      setlayout,      {.v = &layouts[2]} },
  { MODKEY,            XK_space,  setlayout,      {0} },
  { MODKEY|ShiftMask,  XK_space,  togglefloating, {0} },
  { MODKEY,            XK_0,      view,           {.ui = ~0 } },
  { MODKEY|ShiftMask,  XK_0,      tag,            {.ui = ~0 } },
  { MODKEY,            XK_comma,  focusmon,       {.i = -1 } },
  { MODKEY,            XK_period, focusmon,       {.i = +1 } },
  { MODKEY|ShiftMask,  XK_comma,  tagmon,         {.i = -1 } },
  { MODKEY|ShiftMask,  XK_period, tagmon,         {.i = +1 } },
  TAGKEYS(             XK_F1,                      0)
  TAGKEYS(             XK_F2,                      1)
  TAGKEYS(             XK_F3,                      2)
  TAGKEYS(             XK_F4,                      3)
  TAGKEYS(             XK_F5,                      4)
  TAGKEYS(             XK_F6,                      5)
  TAGKEYS(             XK_F7,                      6)
  TAGKEYS(             XK_F8,                      7)
  TAGKEYS(             XK_F9,                      8)
  { MODKEY|ShiftMask,  XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = term } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

static const char *dwmfifo = "/tmp/dwm.fifo";
static Command commands[] = {
	{ "dmenu",           spawn,          {.v = dmenucmd} },
	{ "term",            spawn,          {.v = term} },
	{ "bigterm",         spawn,          {.v = bigterm } },
	{ "emacs",           spawn,          {.v = emacs } },
	{ "xmpp",            spawn,          {.v = xmpp } },
	{ "www",             spawn,          {.v = www } },
	{ "togglebar",       togglebar,      {0} },
	{ "focusstack+",     focusstack,     {.i = +1} },
	{ "focusstack-",     focusstack,     {.i = -1} },
	{ "incnmaster+",     incnmaster,     {.i = +1} },
	{ "incnmaster-",     incnmaster,     {.i = -1} },
	{ "setmfact+",       setmfact,       {.f = +0.05} },
	{ "setmfact-",       setmfact,       {.f = -0.05} },
	{ "zoom",            zoom,           {0} },
	{ "view",            view,           {0} },
	{ "killclient",      killclient,     {0} },
	{ "setlayout-tiled", setlayout,      {.v = &layouts[0]} },
	{ "setlayout-float", setlayout,      {.v = &layouts[1]} },
	{ "setlayout-mono",  setlayout,      {.v = &layouts[2]} },
	{ "togglelayout",    setlayout,      {0} },
	{ "togglefloating",  togglefloating, {0} },
	{ "viewall",         view,           {.ui = ~0} },
	{ "tag",             tag,            {.ui = ~0} },
	{ "focusmon+",       focusmon,       {.i = +1} },
	{ "focusmon-",       focusmon,       {.i = -1} },
	{ "tagmon+",         tagmon,         {.i = +1} },
	{ "tagmon-",         tagmon,         {.i = -1} },
	{ "view1",           view,           {.ui = 1 << 0} },
	{ "view2",           view,           {.ui = 1 << 1} },
	{ "view3",           view,           {.ui = 1 << 2} },
	{ "view4",           view,           {.ui = 1 << 3} },
	{ "view5",           view,           {.ui = 1 << 4} },
	{ "view6",           view,           {.ui = 1 << 5} },
	{ "view7",           view,           {.ui = 1 << 6} },
	{ "view8",           view,           {.ui = 1 << 7} },
	{ "view9",           view,           {.ui = 1 << 8} },
	{ "toggleview1",     toggleview,     {.ui = 1 << 0} },
	{ "toggleview2",     toggleview,     {.ui = 1 << 1} },
	{ "toggleview3",     toggleview,     {.ui = 1 << 2} },
	{ "toggleview4",     toggleview,     {.ui = 1 << 3} },
	{ "toggleview5",     toggleview,     {.ui = 1 << 4} },
	{ "toggleview6",     toggleview,     {.ui = 1 << 5} },
	{ "toggleview7",     toggleview,     {.ui = 1 << 6} },
	{ "toggleview8",     toggleview,     {.ui = 1 << 7} },
	{ "toggleview9",     toggleview,     {.ui = 1 << 8} },
	{ "tag1",            tag,            {.ui = 1 << 0} },
	{ "tag2",            tag,            {.ui = 1 << 1} },
	{ "tag3",            tag,            {.ui = 1 << 2} },
	{ "tag4",            tag,            {.ui = 1 << 3} },
	{ "tag5",            tag,            {.ui = 1 << 4} },
	{ "tag6",            tag,            {.ui = 1 << 5} },
	{ "tag7",            tag,            {.ui = 1 << 6} },
	{ "tag8",            tag,            {.ui = 1 << 7} },
	{ "tag9",            tag,            {.ui = 1 << 8} },
	{ "toggletag1",      toggletag,      {.ui = 1 << 0} },
	{ "toggletag2",      toggletag,      {.ui = 1 << 1} },
	{ "toggletag3",      toggletag,      {.ui = 1 << 2} },
	{ "toggletag4",      toggletag,      {.ui = 1 << 3} },
	{ "toggletag5",      toggletag,      {.ui = 1 << 4} },
	{ "toggletag6",      toggletag,      {.ui = 1 << 5} },
	{ "toggletag7",      toggletag,      {.ui = 1 << 6} },
	{ "toggletag8",      toggletag,      {.ui = 1 << 7} },
	{ "toggletag9",      toggletag,      {.ui = 1 << 8} },
};
