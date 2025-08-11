/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static int floatposgrid_x           = 5;        /* float grid columns */
static int floatposgrid_y           = 5;        /* float grid rows */
static const char *toggle_float_pos      = "50% 50% 80% 80%"; // default floating position when triggering togglefloating
static const unsigned int gappih    = 5;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 5;       /* vert inner gap between windows */
static const unsigned int gappoh    = 15;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 15;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh            = 10;        /* 2 is the default spacing around the bar's font */
#define ICONSIZE (bh - 12)  /* icon size */
#define ICONSPACING 10 /* space between icon and title */
static const char *fonts[]          = { "DejaVu Sans:style=Book:size=12",
										"JetBrainsMono Nerd Font:style=ExtraBold:size=10" };

#include "termcolors.h"

static char normfgcolor[]           = "#bbbbbb";
static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char selfgcolor[]            = "#eeeeee";
static char selbgcolor[]            = "#005577";
static char selbordercolor[]        = "#005577";
static char tagsemptyfgcolor[]      = "#444444";
static char tagsemptybgcolor[]      = "#222222";
static char tagsoccfgcolor[]		= "#bbbbbb";
static char tagsoccbgcolor[]        = "#222222";
static char tagsselfgcolor[]        = "#eeeeee";
static char tagsselbgcolor[]        = "#005577";
static char ltsymbolfgcolor[]       = "#eeeeee";
static char ltsymbolbgcolor[]       = "#222222";
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm]		= { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]		= { selfgcolor,  selbgcolor,  selbordercolor  },
	   [SchemeTagsEmpty]	= { tagsemptyfgcolor,	tagsemptybgcolor,	NULL },
	   [SchemeTagsOcc]		= { tagsoccfgcolor,		tagsoccbgcolor,		NULL },
	   [SchemeTagsSel]		= { tagsselfgcolor,		tagsselbgcolor,		NULL },
	   [SchemeLtSymbol]		= { ltsymbolfgcolor,	ltsymbolbgcolor,	NULL },
};

static const unsigned int baralpha = 0xe0;
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][3]      = {
    /*               fg      bg        border*/
    [SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsEmpty]  = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsOcc]  = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsSel]  = { OPAQUE, baralpha, borderalpha },
	[SchemeLtSymbol]  = { OPAQUE, baralpha, borderalpha },
};

static const char *const autostart[] = {
	"/usr/bin/lxpolkit", NULL,
	"dunst", NULL,
	"nitrogen", "--restore", NULL,
	"picom", "-b", NULL,
	NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8" };

static const unsigned int ulinepad	= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 1;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	{ .class = "Nwg-look", .isfloating = 1 },
	{ .class = "firefox", .tags = 1 << 1 },
	{ .instance = "spterm", .scratchkey = 't', .isfloating = 1, .floatpos = "50% 50% 80% 80%" },
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

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "dwmblocks"

/* commands */
#include <X11/XF86keysym.h>
static const char *termcmd[]	= { "ghostty", NULL };
static const char *firefoxcmd[]	= { "firefox", NULL };

static const char *launchercmd[]	= { "/usr/share/dwm/scripts/launcher", NULL };
static const char *powercmd[]		= { "/usr/share/dwm/scripts/powermenu", NULL };

static const char *mutevol[]	= { "volume", "--toggle", NULL };
static const char *mutemic[]	= { "volume", "--toggle-mic", NULL };
static const char *upvol[]		= { "volume", "--inc", NULL };
static const char *downvol[]	= { "volume", "--dec", NULL };
static const char *upbl[]		= { "brightness", "--inc", NULL };
static const char *downbl[]		= { "brightness", "--dec", NULL };

static const char *sptermcmd[]	= { "t", "ghostty", "--x11-instance-name=spterm", "--title=Scratchpad", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_w,      spawn,          {.v = firefoxcmd } },
	{ MODKEY,                       XK_space,  spawn,          {.v = launchercmd } },
	{ MODKEY,                       XK_x,  spawn,          {.v = powercmd } },
	{ 0, 						XF86XK_AudioMute, 			spawn, {.v = mutevol } },
	{ 0, 						XF86XK_AudioMicMute, 		spawn, {.v = mutemic } },
	{ 0, 						XF86XK_AudioLowerVolume, 	spawn, {.v = downvol } },
	{ 0, 						XF86XK_AudioRaiseVolume, 	spawn, {.v = upvol } },
	{ 0, 						XF86XK_MonBrightnessUp, 	spawn, {.v = upbl   } },
	{ 0, 						XF86XK_MonBrightnessDown, 	spawn, {.v = downbl } },
	{ MODKEY,                       XK_grave,  togglescratch,  {.v = sptermcmd } },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,      rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      rotatestack,    {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_h,      setcfact,       {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },
	{ MODKEY,                       XK_Up,     incrgaps,       {.i = +1 } },
	{ MODKEY,                       XK_Down,   incrgaps,       {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_g,      togglegaps,     {0} },
	{ MODKEY|ControlMask,           XK_g,      defaultgaps,    {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,		XK_comma,  cyclelayout,    {.i = -1 } },
	{ MODKEY,           XK_period, cyclelayout,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_Right,  viewnext,       {0} },
	{ MODKEY,                       XK_Left,   viewprev,       {0} },
	{ MODKEY|ShiftMask,             XK_Right,  tagtonext,      {0} },
	{ MODKEY|ShiftMask,             XK_Left,   tagtoprev,      {0} },
	{ MODKEY|ShiftMask,             XK_x,      xrdb,           {.v = NULL } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ShiftMask,             XK_r,      quit,           {1} }, 
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigstatusbar,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigstatusbar,   {.i = 5} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

void
setlayoutex(const Arg *arg)
{
	setlayout(&((Arg) { .v = &layouts[arg->i] }));
}

void
viewex(const Arg *arg)
{
	view(&((Arg) { .ui = 1 << arg->ui }));
}

void
viewall(const Arg *arg)
{
	view(&((Arg){.ui = ~0}));
}

void
toggleviewex(const Arg *arg)
{
	toggleview(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagex(const Arg *arg)
{
	tag(&((Arg) { .ui = 1 << arg->ui }));
}

void
toggletagex(const Arg *arg)
{
	toggletag(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagall(const Arg *arg)
{
	tag(&((Arg){.ui = ~0}));
}

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signame> [<type> <value>]"` */
static Signal signals[] = {
	/* signum           function */
	{ "focusstack",     focusstack },
	{ "setmfact",       setmfact },
	{ "togglebar",      togglebar },
	{ "incnmaster",     incnmaster },
	{ "togglefloating", togglefloating },
	{ "focusmon",       focusmon },
	{ "tagmon",         tagmon },
	{ "zoom",           zoom },
	{ "view",           view },
	{ "viewall",        viewall },
	{ "viewex",         viewex },
	{ "toggleview",     view },
	{ "toggleviewex",   toggleviewex },
	{ "tag",            tag },
	{ "tagall",         tagall },
	{ "tagex",          tagex },
	{ "toggletag",      tag },
	{ "toggletagex",    toggletagex },
	{ "killclient",     killclient },
	{ "quit",           quit },
	{ "setlayout",      setlayout },
	{ "setlayoutex",    setlayoutex },
};
