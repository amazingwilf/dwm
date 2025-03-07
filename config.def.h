/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int vertpad            = 10;       /* vertical padding of bar */
static const int sidepad            = 10;       /* horizontal padding of bar */
static const int user_bh            = 8;        /* 2 is the default spacing around the bar's font */
#define ICONSIZE (bh - 18)  /* icon size */
#define ICONSPACING 8 /* space between icon and title */
static const char buttonbar[]       = " ";
static const char *fonts[]          = { "NotoSans Nerd Font:size=12",
                                        "JetBrainsMono Nerd Font:size=14",
                                        "JetBrainsMono Nerd Font:style=ExtraBold:size=10" };

static char c000000[]               = "#000000";

static char normfgcolor[]           = "#bbbbbb";
static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";

static char selfgcolor[]            = "#eeeeee";
static char selbgcolor[]            = "#005577";
static char selbordercolor[]        = "#005577";

static char floatfgcolor[]          = "#eeeeee";
static char floatbgcolor[]          = "#005577";
static char floatbordercolor[]      = "#005577";

static char stbuttonfgcolor[]       = "#eeeeee";
static char stbuttonbgcolor[]       = "#005577";

static char ltsymbolfgcolor[]       = "#eeeeee";
static char ltsymbolbgcolor[]       = "#222222";

static char tagsselfgcolor[]        = "#eeeeee";
static char tagsselbgcolor[]        = "#005577";

static char tagsemptyfgcolor[]      = "#444444";
static char tagsemptybgcolor[]      = "#222222";

static char tag1fgcolor[]           = "#aaffff";
static char tag2fgcolor[]           = "#bbeeee";
static char tag3fgcolor[]           = "#ffaaff";
static char tag4fgcolor[]           = "#99aacc";
static char tag5fgcolor[]           = "#cc55dd";
static char tag6fgcolor[]           = "#00ccdd";

static char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm]        = { normfgcolor,        normbgcolor,        normbordercolor },
	[SchemeSel]         = { selfgcolor,         selbgcolor,         selbordercolor },
    [SchemeFloat]       = { floatfgcolor,       floatbgcolor,       floatbordercolor },
    [SchemeStButton]    = { stbuttonfgcolor,    stbuttonbgcolor,    c000000 },
    [SchemeLtSymbol]    = { ltsymbolfgcolor,    ltsymbolbgcolor,    c000000 },
    [SchemeTagsSel]     = { tagsselfgcolor,     tagsselbgcolor,     c000000 },
    [SchemeTagsEmpty]   = { tagsemptyfgcolor,   tagsemptybgcolor,   c000000 },
    [SchemeTag1]        = { tag1fgcolor,        tagsemptybgcolor,   c000000 },
    [SchemeTag2]        = { tag2fgcolor,        tagsemptybgcolor,   c000000 },
    [SchemeTag3]        = { tag3fgcolor,        tagsemptybgcolor,   c000000 },
    [SchemeTag4]        = { tag4fgcolor,        tagsemptybgcolor,   c000000 },
    [SchemeTag5]        = { tag5fgcolor,        tagsemptybgcolor,   c000000 },
    [SchemeTag6]        = { tag6fgcolor,        tagsemptybgcolor,   c000000 },
};

static const int tagschemes[] = { SchemeTag1, SchemeTag2, SchemeTag3,
                                  SchemeTag4, SchemeTag5, SchemeTag6 };

static const unsigned int baralpha      = 0xd0;
static const unsigned int borderalpha   = OPAQUE;

static const unsigned int alphas[][3]   = {
    /*               fg      bg        border*/
    [SchemeNorm]        = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]         = { OPAQUE, baralpha, borderalpha },
	[SchemeFloat]       = { OPAQUE, baralpha, borderalpha },
	[SchemeStButton]    = { OPAQUE, baralpha, borderalpha },
	[SchemeLtSymbol]    = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsSel]     = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsEmpty]   = { OPAQUE, baralpha, borderalpha },
	[SchemeTag1]        = { OPAQUE, baralpha, borderalpha },
	[SchemeTag2]        = { OPAQUE, baralpha, borderalpha },
	[SchemeTag3]        = { OPAQUE, baralpha, borderalpha },
	[SchemeTag4]        = { OPAQUE, baralpha, borderalpha },
	[SchemeTag5]        = { OPAQUE, baralpha, borderalpha },
	[SchemeTag6]        = { OPAQUE, baralpha, borderalpha },
};

static const char *const autostart[] = {
    "/usr/bin/pipewire", NULL,
	"/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1", NULL,
    "nitrogen", "--restore", NULL,
    "picom", "-b", NULL,
	NULL /* terminate */
};

/* tagging */
static const char *tags[]       = { "·", "·", "·", "·", "·",  "·" };
static const char *alttags[]    = { " ", " ", " ", " ", " ", " " };

static const unsigned int ulinepad	= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	{ .class = "Lxappearance", .isfloating = 1, .floatpos = "50% 50% -1h -1w", .bw = -1 },
	{ .class = "firefox", .tags = 1 << 1, .bw = -1 },
};

/* layout(s) */
static const float mfact            = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster            = 1;    /* number of clients in master area */
static const int resizehints        = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen     = 1; /* 1 will force focus on the fullscreen window */
static int floatposgrid_x           = 5;        /* float grid columns */
static int floatposgrid_y           = 5;        /* float grid rows */
static const char *toggle_float_pos = "50% 50% 80% 80%"; // default floating position when triggering togglefloating

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "TTT",      bstack },
	{ "HHH",      gaplessgrid },
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

/* commands */
static const char *termcmd[]    = { "ghostty", "--title=Terminal", NULL };
static const char *roficmd[]    = { "rofi", "-show", "drun", NULL };
static const char *firefoxcmd[] = { "firefox", NULL };

#include <X11/XF86keysym.h>
static const char *mutevol[] 			= { "/usr/share/archcraft/dwm/scripts/dwm_volume", "--toggle",  NULL };
static const char *mutemic[] 			= { "/usr/share/archcraft/dwm/scripts/dwm_volume", "--toggle-mic",  NULL };
static const char *upvol[]   			= { "/usr/share/archcraft/dwm/scripts/dwm_volume", "--inc",  	NULL };
static const char *downvol[] 			= { "/usr/share/archcraft/dwm/scripts/dwm_volume", "--dec",    	NULL };
static const char *upbl[] 				= { "/usr/share/archcraft/dwm/scripts/dwm_brightness", "--inc",    NULL };
static const char *downbl[] 			= { "/usr/share/archcraft/dwm/scripts/dwm_brightness", "--dec",  NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_space,  spawn,          {.v = roficmd } },
	{ MODKEY,                       XK_w,      spawn,          {.v = firefoxcmd } },

	{ 0, 						XF86XK_AudioMute, 			spawn, {.v = mutevol } },
	{ 0, 						XF86XK_AudioMicMute, 		spawn, {.v = mutemic } },
	{ 0, 						XF86XK_AudioLowerVolume, 	spawn, {.v = downvol } },
	{ 0, 						XF86XK_AudioRaiseVolume, 	spawn, {.v = upvol   } },
	{ 0, 						XF86XK_MonBrightnessUp, 	spawn, {.v = upbl   } },
	{ 0, 						XF86XK_MonBrightnessDown, 	spawn, {.v = downbl   } },



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
	{ MODKEY|ShiftMask,             XK_g,      togglegaps,     {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_b,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[4]} },
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
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ShiftMask,             XK_r,      quit,           {1} }, 
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkButton,		    0,		        Button1,	    spawn,		    {.v = roficmd } },
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

