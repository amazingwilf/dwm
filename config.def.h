/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx		= 3; 
static const unsigned int snap			= 32;
static const int attachmode				= 2; 
static const int swallowfloating		= 0;
static const int swterminheritfs		= 1;

static const unsigned int gappih		= 10;
static const unsigned int gappiv		= 10;
static const unsigned int gappoh		= 20;
static const unsigned int gappov		= 20;
static int smartgaps					= 0; 

static const int showbar				= 1; 
static const int topbar					= 1; 
static const int user_bh				= 8;        /* 2 is the default spacing around the bar's font */
static const char buttonbar[]			= " ";

#define ICONSIZE (bh - 12)  /* icon size */
#define ICONSPACING 12 /* space between icon and title */

static const char *fonts[]				= { "Noto Sans:style=Medium:size=16",
											"JetBrainsMono Nerd Font:size=15",
											"JetBrainsMono Nerd Font:style=ExtraBold:size=13" };
static const char dmenufont[]			= "Noto Sans:style=Medium:size=16";

#include "termcolors.h"

static char c000000[]					= "#000000";

static char normfgcolor[]				= "#bbbbbb";
static char normbgcolor[]				= "#222222";
static char normbordercolor[]			= "#444444";
static char normfloatcolor[]			= "#444444";

static char selfgcolor[]				= "#eeeeee";
static char selbgcolor[]				= "#005577";
static char selbordercolor[]			= "#005577";
static char selfloatcolor[]				= "#005577";

static char tagsnormfgcolor[]			= "#bbbbbb";
static char tagsnormbgcolor[]			= "#222222";
static char tagsselfgcolor[]			= "#eeeeee";
static char tagsselbgcolor[]			= "#005577";

static char titlenormfgcolor[]			= "#bbbbbb";
static char titlenormbgcolor[]			= "#222222";
static char titleselfgcolor[]			= "#eeeeee";
static char titleselbgcolor[]			= "#005577";

static char ltsymbolfgcolor[]			= "#ffdd00";
static char ltsymbolbgcolor[]			= "#222222";
static char stbuttonfgcolor[]			= "#007799";
static char stbuttonbgcolor[]			= "#222222";

static char scratchnormbordercolor[]	= "#444444";
static char scratchnormfloatcolor[]		= "#444444";
static char scratchselbordercolor[]		= "#007799";
static char scratchselfloatcolor[]		= "#007799";

static const unsigned int baralpha		= 0x70;
static const unsigned int borderalpha	= OPAQUE;

static char *colors[][4]	= {
	[SchemeNorm]		= { normfgcolor,		normbgcolor,		normbordercolor,			normfloatcolor },
	[SchemeSel]			= { selfgcolor,			selbgcolor,			selbordercolor,				selfloatcolor },
	[SchemeScratchNorm]	= { c000000,			c000000,			scratchnormbordercolor,		scratchnormfloatcolor },
	[SchemeScratchSel]	= { c000000,			c000000,			scratchselbordercolor,		scratchselfloatcolor },
	[SchemeTagsNorm]	= { tagsnormfgcolor,	tagsnormbgcolor,	c000000,					c000000 },
	[SchemeTagsSel]		= { tagsselfgcolor,		tagsselbgcolor,		c000000,					c000000 },
	[SchemeTitleNorm]	= { titlenormfgcolor,	titlenormbgcolor,	c000000,					c000000 },
	[SchemeTitleSel]	= { titleselfgcolor,	titleselbgcolor,	c000000,					c000000 },
	[SchemeLtSymbol]	= { ltsymbolfgcolor,	ltsymbolbgcolor,	c000000,					c000000 },
	[SchemeStButton]	= { stbuttonfgcolor,	stbuttonbgcolor,	c000000,					c000000 },
};

static const unsigned int alphas[][4]	= {
	[SchemeNorm]		= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeSel]			= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeScratchNorm]	= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeScratchSel]	= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeTagsNorm]	= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeTagsSel]		= { OPAQUE, OPAQUE,   borderalpha, borderalpha },
	[SchemeTitleNorm]	= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeTitleSel]	= { OPAQUE, OPAQUE,   borderalpha, borderalpha },
	[SchemeLtSymbol]	= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeStButton]	= { OPAQUE, baralpha, borderalpha, borderalpha },
};

static const char *const autostart[] = {
	"/usr/bin/pipewire", NULL,
	"/usr/libexec/polkit-gnome-authentication-agent-1", NULL,
	"nitrogen", "--restore", NULL,
	"dunst", NULL,
	"picom", "-b", NULL,
	NULL /* terminate */
};

/* tagging */
/* static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8" }; */
static char *tags[]	= { " ", " ", " ", " ", " ", " ", " ", " " };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	{ .class = "Lxappearance", .isfloating = 1 },
	{ .class = "Firefox", .tags = 1 << 1 },
	{ .class = "floaterm", .isfloating = 1, .isterminal = 1 },
	{ .class = "Alacritty", .isterminal = 1 },
	{ .title = "Event Tester", .noswallow = 1 },
	{ .class = "spterm", .scratchkey = 't', .isfloating = 1 }
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

/* commands */
static const char *termcmd[]		= { "alacritty", NULL };
static const char *floatermcmd[]	= { "alacritty", "--class", "floaterm,floaterm", NULL };
static const char *dmenucmd[]		= { "dmenu_run", 
	"-fn", dmenufont, 
	"-nb", normbgcolor, 
	"-nf", normfgcolor, 
	"-sb", selbgcolor, 
	"-sf", selfgcolor, 
	NULL };
static const char *webcmd[]			= { "firefox", NULL };

static const char *sptermcmd[] 		= { "t", "alacritty", "--class", "spterm,spterm", NULL};

#include <X11/XF86keysym.h>
static const char *mutevol[]		= { "volume", "--toggle", NULL };
static const char *mutemic[]		= { "volume", "--toggle-mic", NULL };
static const char *upvol[]			= { "volume", "--inc", NULL };
static const char *downvol[]		= { "volume", "--dec", NULL };
static const char *upbl[]			= { "brightness", "--inc", NULL };
static const char *downbl[]			= { "brightness", "--dec", NULL };


static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_space,  spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = floatermcmd } },
	{ MODKEY,                       XK_w,      spawn,          {.v = webcmd } },

	{ 0, 						XF86XK_AudioMute, 			spawn, {.v = mutevol } },
	{ 0, 						XF86XK_AudioMicMute, 		spawn, {.v = mutemic } },
	{ 0, 						XF86XK_AudioLowerVolume, 	spawn, {.v = downvol } },
	{ 0, 						XF86XK_AudioRaiseVolume, 	spawn, {.v = upvol } },
	{ 0, 						XF86XK_MonBrightnessUp, 	spawn, {.v = upbl } },
	{ 0, 						XF86XK_MonBrightnessDown, 	spawn, {.v = downbl } },

	{ MODKEY,                       XK_b,      togglebar,      {0} },
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
	{ MODKEY|ShiftMask,             XK_g,      togglegaps,     {0} },
	{ MODKEY,                       XK_grave,  togglescratch,  {.v = sptermcmd } },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ShiftMask,             XK_r,      quit,           {1} }, 
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_b,      setlayout,      {.v = &layouts[6]} },
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[11]} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_x,      xrdb,           {.v = NULL } },
	{ MODKEY,                       XK_Right,  viewnext,       {0} },
	{ MODKEY,                       XK_Left,   viewprev,       {0} },
	{ MODKEY|ShiftMask,             XK_Right,  tagtonext,      {0} },
	{ MODKEY|ShiftMask,             XK_Left,   tagtoprev,      {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkButton,		0,		Button1,	spawn,		{.v = dmenucmd } },
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

