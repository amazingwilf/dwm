/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx	= 3; 
static const unsigned int snap		= 32;

static const unsigned int gappih	= 10; 
static const unsigned int gappiv	= 10;
static const unsigned int gappoh	= 15; 
static const unsigned int gappov	= 15;
static int smartgaps				= 1; 

static const int showbar			= 1;
static const int topbar				= 1;
static const int user_bh			= 6;

#define ICONSIZE (bh - 10)
#define ICONSPACING 8

static const char *fonts[]			= { "Iosevka Nerd Font Propo:size=12",
										"JetBrainsMono Nerd Font:style=ExtraBold:size=10" };

#include "termcolors.h"

static char normfgcolor[]		= "#bbbbbb";
static char normbgcolor[]		= "#222222";
static char normbordercolor[]	= "#444444";
static char normfloatcolor[]	= "#444444";

static char selfgcolor[]		= "#eeeeee";
static char selbgcolor[]		= "#005577";
static char selbordercolor[]	= "#005577";
static char selfloatcolor[]		= "#005577";

static char ltsymbolfgcolor[]	= "#eeeeee";
static char ltsymbolbgcolor[]	= "#222222";

static char tagsemptyfgcolor[]	= "#444444";
static char tagsemptybgcolor[]	= "#222222";
static char tagsoccfgcolor[]	= "#bbbbbb";
static char tagsoccbgcolor[]	= "#222222";
static char tagsselfgcolor[]	= "#eeeeee";
static char tagsselbgcolor[]	= "#005577";

static char scratchnormbordercolor[]	= "#444444";
static char scratchnormfloatcolor[]		= "#444444";
static char scratchselbordercolor[]		= "#995577";
static char scratchselfloatcolor[]		= "#006688";

static char *colors[][4]		= {
	[SchemeNorm]		= { normfgcolor,		normbgcolor,		normbordercolor,		normfloatcolor  },
	[SchemeSel]			= { selfgcolor,			selbgcolor,			selbordercolor,			selfloatcolor  },
	[SchemeLtSymbol]	= { ltsymbolfgcolor,	ltsymbolbgcolor,	NULL,					NULL },
	[SchemeTagsEmpty]	= { tagsemptyfgcolor,	tagsemptybgcolor,	NULL,					NULL },
	[SchemeTagsOcc]		= { tagsoccfgcolor,		tagsoccbgcolor,		NULL,					NULL },
	[SchemeTagsSel]		= { tagsselfgcolor,		tagsselbgcolor,		NULL,					NULL },
	[SchemeScratchNorm]	= { NULL,				NULL,				scratchnormbordercolor,	scratchnormfloatcolor },
	[SchemeScratchSel]	= { NULL,				NULL,				scratchselbordercolor,	scratchselfloatcolor },
};


static const char *const autostart[] = {
	"/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1", NULL,
	"nitrogen", "--restore", NULL,
	"dunst", NULL,
	"picom", "-b", NULL,
	"dwmblocks", NULL,
	NULL /* terminate */
};

/* tagging */
// static const char *tags[]			= { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const char *tags[]			= { "", "", "", "", "", "", "", "" };
static const Bool viewontag			= 1;
static const int viewonrulestag 	= 1;

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	{ .class = "Nwg-look", .isfloating = 1, .iscentered = 1 },
	{ .class = "firefox", .tags = 1 << 1 },
	{ .class = "Thunar", .tags = 1 << 2 },
	{ .instance = "spterm", .scratchkey = 't', .isfloating = 1, .floatpos = "50% 50% 80% 80%" },
};

/* layout(s) */
static const float mfact			= 0.50;
static const int nmaster			= 1;
static const int resizehints		= 0;
static const int lockfullscreen		= 1;
static const int refreshrate		= 120; 
static int floatposgrid_x			= 5;
static int floatposgrid_y			= 5; 
static const char *toggle_float_pos	= "50% 50% 80% 80%";

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	{ "[]=",	tile }, 
	{ "><>",	NULL },
	{ "[M]",	monocle },
	{ "[@]",	spiral },
	{ "[\\]",	dwindle },
	{ "D[]",	deck },
	{ "TTT",	bstack },
	{ "===",	bstackhoriz },
	{ "HHH",	grid },
	{ "###",	nrowgrid },
	{ "---",	horizgrid },
	{ ":::",	gaplessgrid },
	{ "|M|",	centeredmaster },
	{ ">M>",	centeredfloatingmaster },
	{ NULL,		NULL },
};

/* key definitions */
#define Super Mod4Mask
#define Shift ShiftMask
#define Ctrl ControlMask
#define Alt Mod1Mask

#define TAGKEYS(KEY,TAG) \
	{ Super,				KEY,	view,			{.ui = 1 << TAG} }, \
	{ Super|Ctrl,			KEY,	toggleview,		{.ui = 1 << TAG} }, \
	{ Super|Shift,			KEY,	tag,			{.ui = 1 << TAG} }, \
	{ Super|Ctrl|Shift,		KEY,	toggletag, 		{.ui = 1 << TAG} },

#define SCRATCHKEYS(KEY,CMD) \
	{ Super,			KEY,	togglescratch,	{.v = CMD} }, \
	{ Super|Shift,		KEY,	removescratch,	{.v = CMD} }, \
	{ Super|Ctrl,		KEY,	setscratch,		{.v = CMD} },


/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "dwmblocks"

/* commands */
static const char *termcmd[]	= { "ghostty", NULL };
static const char *roficmd[]	= { "rofi", "-show", "drun", NULL };
static const char *firefoxcmd[]	= { "firefox", NULL };
static const char *thunarcmd[]	= { "thunar", NULL };

static const char *sptermcmd[]	= { "t", "ghostty", "--x11-instance-name=spterm", "--title=Scratchpad", NULL };

#include <X11/XF86keysym.h>
static const char *mutevol[] 			= { "volume", "--toggle",  NULL };
static const char *mutemic[] 			= { "volume", "--toggle-mic",  NULL };
static const char *upvol[]   			= { "volume", "--inc",  	NULL };
static const char *downvol[] 			= { "volume", "--dec",    	NULL };
static const char *upbl[] 				= { "brightness", "--inc",    NULL };
static const char *downbl[] 			= { "brightness", "--dec",  NULL };

static const Key keys[] = {
	{ Super,				XK_space,		spawn,			{.v = roficmd } },
	{ Super,				XK_Return,		spawn,			{.v = termcmd } },
	{ Super,				XK_w,			spawn,			{.v = firefoxcmd } },
	{ Super,				XK_e,			spawn,			{.v = thunarcmd } },
	{ 0, 						XF86XK_AudioMute, 			spawn, {.v = mutevol } },
	{ 0, 						XF86XK_AudioMicMute, 		spawn, {.v = mutemic } },
	{ 0, 						XF86XK_AudioLowerVolume, 	spawn, {.v = downvol } },
	{ 0, 						XF86XK_AudioRaiseVolume, 	spawn, {.v = upvol   } },
	{ 0, 						XF86XK_MonBrightnessUp, 	spawn, {.v = upbl   } },
	{ 0, 						XF86XK_MonBrightnessDown, 	spawn, {.v = downbl   } },
	{ Super,				XK_j,      focusstack,     {.i = +1 } },
	{ Super,				XK_k,      focusstack,     {.i = -1 } },
	{ Super|Shift,			XK_j,      rotatestack,    {.i = +1 } },
	{ Super|Shift,			XK_k,      rotatestack,    {.i = -1 } },
	{ Super,                       XK_i,      incnmaster,     {.i = +1 } },
	{ Super,                       XK_d,      incnmaster,     {.i = -1 } },
	{ Super,                       XK_h,      setmfact,       {.f = -0.05} },
	{ Super,                       XK_l,      setmfact,       {.f = +0.05} },
	{ Super|Shift,             XK_h,      setcfact,       {.f = +0.25} },
	{ Super|Shift,             XK_l,      setcfact,       {.f = -0.25} },
	{ Super|Shift,             XK_o,      setcfact,       {.f =  0.00} },
	{ Super,                       XK_q,      killclient,     {0} },
	{ Super,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ Super,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ Super,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ Super,		XK_comma,  cyclelayout,    {.i = -1 } },
	{ Super,           XK_period, cyclelayout,    {.i = +1 } },
	{ Super|Shift,             XK_b,      togglebar,      {0} },
	{ Super|Shift,             XK_space,  togglefloating, {0} },
	{ Super|Shift,             XK_f,      togglefullscr,  {0} },
	{ Super|Shift,             XK_x,      xrdb,           {.v = NULL } },
	{ Super,                       XK_0,      view,           {.ui = ~0 } },
	{ Super|Shift,             XK_0,      tag,            {.ui = ~0 } },
	{ Super,                       XK_Right,  viewnext,       {0} },
	{ Super,                       XK_Left,   viewprev,       {0} },
	{ Super|Shift,             XK_Right,  tagtonext,      {0} },
	{ Super|Shift,             XK_Left,   tagtoprev,      {0} },
	SCRATCHKEYS(                    XK_grave,                  sptermcmd)
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ Super|Shift,             XK_q,      quit,           {0} },
	{ Super|Shift,             XK_r,      quit,           {1} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkLtSymbol,          0,              Button4,        cyclelayout,      {.i = +1} },
	{ ClkLtSymbol,          0,              Button5,        cyclelayout,      {.i = -1} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigstatusbar,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigstatusbar,   {.i = 5} },
	{ ClkClientWin,         Super,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         Super,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         Super,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            Super,         Button1,        tag,            {0} },
	{ ClkTagBar,            Super,         Button3,        toggletag,      {0} },
};

