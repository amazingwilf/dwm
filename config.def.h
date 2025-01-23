/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static int floatposgrid_x           = 5;        /* float grid columns */
static int floatposgrid_y           = 5;        /* float grid rows */
static const char *toggle_float_pos      = "50% 50% 80% 80%"; // default floating position when triggering togglefloating
static const unsigned int gappih    = 15;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 15;       /* vert inner gap between windows */
static const unsigned int gappoh    = 15;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 15;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char buttonbar[]       = " ";
static const char statussep         = ';';      /* separator between status bars */
#define ICONSIZE (bh - 12)   /* icon size */
#define ICONSPACING 10 /* space between icon and title */
static const char *fonts[]          = { "Noto Sans:style=Medium:size=15",
										"JetBrainsMono Nerd Font:size=17",
										"monospace:style=Bold:size=13" };

#include "termcolors.h"

static char normfgcolor[]			= "#bbbbbb";
static char normbgcolor[]			= "#222222";
static char normbordercolor[]		= "#444444";
static char normfloatcolor[]		= "#444444";

static char selfgcolor[]			= "#eeeeee";
static char selbgcolor[]			= "#005577";
static char selbordercolor[]		= "#005577";
static char selfloatcolor[]         = "#005577";

static char scratchnormfgcolor[]    = "#bbbbbb";
static char scratchnormbgcolor[]    = "#222222";
static char scratchnormbordercolor[]    = "#444444";
static char scratchnormfloatcolor[]     = "#444444";

static char scratchselfgcolor[]    = "#eeeeee";
static char scratchselbgcolor[]    = "#005577";
static char scratchselbordercolor[]    = "#005577";
static char scratchselfloatcolor[]     = "#005577";

static char *colors[][4]      = {
	[SchemeNorm]        = { normfgcolor,        normbgcolor,        normbordercolor,        normfloatcolor },
	[SchemeSel]         = { selfgcolor,         selbgcolor,         selbordercolor,         selfloatcolor },
    [SchemeScratchNorm] = { scratchnormfgcolor, scratchnormbgcolor, scratchnormbordercolor, scratchnormfloatcolor },
    [SchemeScratchSel]  = { scratchselfgcolor,  scratchselbgcolor,  scratchselbordercolor,  scratchselfloatcolor },
};

static const unsigned int baralpha = 0xa0;
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][4]      = {
	[SchemeNorm]        = { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeSel]         = { OPAQUE, OPAQUE,   borderalpha, borderalpha },
	[SchemeScratchNorm] = { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeScratchSel]  = { OPAQUE, baralpha, borderalpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	{ .class = "Lxappearance", .isfloating = 1, .floatpos = "50% 50% -1h -1w" },
	{ .class = "firefox", .tags = 1 << 1 },
    { .instance = "spterm", .scratchkey = 't', .isfloating = 1, .floatpos = "50% 50% 80% 80%"},
    { .instance = "spfm", .scratchkey = 'f', .isfloating = 1, .floatpos = "50% 50% 80% 80%" },
};

/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
	/* monitor  bar    alignment         widthfunc              drawfunc              clickfunc           name */
	{ -1,       0,     BAR_ALIGN_LEFT,   width_stbutton,        draw_stbutton,        click_stbutton,     "statusbutton" },
	{ -1,       0,     BAR_ALIGN_LEFT,   width_tags,            draw_tags,            click_tags,         "tags" },
	{ -1,       0,     BAR_ALIGN_LEFT,   width_ltsymbol,        draw_ltsymbol,        click_ltsymbol,     "layout" },
	{ 'A',      0,     BAR_ALIGN_RIGHT,  width_status2d,        draw_status2d,        click_statuscmd,    "status2d" },
	{ -1,       0,     BAR_ALIGN_NONE,   width_wintitle,        draw_wintitle,        click_wintitle,     "wintitle" },
	{  0,       1,     BAR_ALIGN_CENTER, width_status2d_es,     draw_status2d_es,     click_statuscmd_es, "status2d_es" },

};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ "D[]",      deck },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "HHH",      grid },
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask

#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define SCRATCHKEYS(KEY,CMD) \
    { MODKEY,               KEY,    togglescratch,      {.v = CMD } }, \
    { MODKEY|ShiftMask,     KEY,    removescratch,      {.v = CMD } }, \
    { MODKEY|ControlMask,   KEY,    setscratch,         {.v = CMD } }, 


/* commands */
static const char *termcmd[]  = { "ghostty", NULL };
static const char *roficmd[]	= { "rofi", "-show", "drun", "-dpi", "1", NULL };

static const char *sptermcmd[]     = { "t", "ghostty", "--x11-instance-name=spterm", NULL };
static const char *spfmcmd[]        = { "f", "thunar", "--name=spfm", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_space,  spawn,          {.v = roficmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_h,      setcfact,       {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },
	{ MODKEY,                       XK_bracketright,      incrgaps,       {.i = +1 } },
	{ MODKEY,                       XK_bracketleft,      incrgaps,       {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_g,      togglegaps,     {0} },
	{ MODKEY|ControlMask,           XK_g,      defaultgaps,    {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,	                	XK_comma,  cyclelayout,    {.i = -1 } },
	{ MODKEY,                       XK_period, cyclelayout,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_x,      xrdb,           {.v = NULL } },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_Right,  viewnext,       {0} },
	{ MODKEY,                       XK_Left,   viewprev,       {0} },
	{ MODKEY|ShiftMask,             XK_Right,  tagtonext,      {0} },
	{ MODKEY|ShiftMask,             XK_Left,   tagtoprev,      {0} },
    SCRATCHKEYS(                    XK_grave,                  sptermcmd)
    SCRATCHKEYS(                    XK_e,                      spfmcmd)
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ShiftMask,             XK_r,      quit,           {1} }, 
};

/* button definitions */
/* click can be ClkButton, ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkButton,            0,              Button1,        spawn,          {.v = roficmd } },
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1 } },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2 } },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3 } },
	{ ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4 } },
	{ ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5 } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

