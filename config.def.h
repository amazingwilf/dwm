/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx	= 6;
static const unsigned int snap		= 32;
static int floatposgrid_x			= 5;
static int floatposgrid_y			= 5;
static const char *toggle_float_pos	= "50% 50% 80% 80%";

static const unsigned int gappih	= 5;
static const unsigned int gappiv	= 5;
static const unsigned int gappoh	= 15;
static const unsigned int gappov	= 15;
static int smartgaps				= 0;

static const int showbar			= 1;
static const int topbar				= 1;
static const int user_bh			= 10;

#define ICONSIZE (bh - 12)
#define ICONSPACING 10

static const char *fonts[]			= { "DejaVu Sans:style=Book:size=12",
										"JetBrainsMono Nerd Font:size=12",
										"JetBrainsMono Nerd Font:style=ExtraBold:size=10" };

#include "termcolors.h"

static char normfgcolor[]			= "#bbbbbb";
static char normbgcolor[]			= "#222222";
static char normbordercolor[]		= "#444444";

static char selfgcolor[]			= "#eeeeee";
static char selbgcolor[]			= "#005577";
static char selbordercolor[]		= "#005577";

static char tagsemptyfgcolor[]		= "#444444";
static char tagsemptybgcolor[]		= "#222222";

static char tagsoccfgcolor[]		= "#bbbbbb";
static char tagsoccbgcolor[]		= "#222222";

static char tagsselfgcolor[]		= "#eeeeee";
static char tagsselbgcolor[]		= "#005577";

static char ltsymbolfgcolor[]		= "#eeeeee";
static char ltsymbolbgcolor[]		= "#222222";

static char *colors[][3] = {
	/*	fg	bg	border	*/
	[SchemeNorm]			= { normfgcolor,		normbgcolor,		normbordercolor },
	[SchemeSel]				= { selfgcolor,			selbgcolor,			selbordercolor	},
		[SchemeTagsEmpty]	= { tagsemptyfgcolor,	tagsemptybgcolor,	NULL },
		[SchemeTagsOcc]		= { tagsoccfgcolor,		tagsoccbgcolor,		NULL },
		[SchemeTagsSel]		= { tagsselfgcolor,		tagsselbgcolor,		NULL },
		[SchemeLtSymbol]	= { ltsymbolfgcolor,	ltsymbolbgcolor,	NULL },
};

static const unsigned int baralpha 		= 0xe0;
static const unsigned int borderalpha 	= OPAQUE;
static const unsigned int alphas[][3]	= {
	/*	fg	bg	border*/
	[SchemeNorm] 			= { OPAQUE, baralpha, borderalpha },
	[SchemeSel]				= { OPAQUE, baralpha, borderalpha },
	[SchemeTagsEmpty]		= { OPAQUE, baralpha, borderalpha },
	[SchemeTagsOcc]			= { OPAQUE, baralpha, borderalpha },
	[SchemeTagsSel]			= { OPAQUE, baralpha, borderalpha },
	[SchemeLtSymbol]		= { OPAQUE, baralpha, borderalpha },
};

static const char *const autostart[] = {
	"/usr/bin/lxpolkit", NULL,
	"dunst", NULL,
	"nitrogen", "--restore", NULL,
	"picom", "-b", NULL,
	"dwmblocks", NULL,
	NULL /* terminate */
};

/* tagging */
/*static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8" };*/
static char *tags[] = {" ", " ", " ", " ", " ", " ", " ", " "};

static const unsigned int ulinepad		= 5;
static const unsigned int ulinestroke	= 1;
static const unsigned int ulinevoffset	= 0;
static const int ulineall 				= 0;

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	{ .class = "Nwg-look", .isfloating = 1 },
	{ .class = "firefox", .tags = 1 << 1 },
	{ .class = "Thunar", .tags = 1 << 2 },
	{ .instance = "spterm", .scratchkey = 't', .isfloating = 1, .floatpos = "50% 50% 80% 80%" },
};

/* layout(s) */
static const float mfact		= 0.50; 
static const int nmaster		= 1;
static const int resizehints 	= 0;
static const int lockfullscreen	= 1;

#define FORCE_VSPLIT 1	/* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol	arrange function */
	{ "[]=",	tile },	/* first entry is default */
	{ "><>",	NULL },	/* no layout function means floating behavior */
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
#define Mod Mod4Mask
#define Shift ShiftMask
#define Ctrl ControlMask
#define Alt Mod1Mask

#define TAGKEYS(KEY,TAG) \
	{ Mod,				KEY,	view,		{.ui = 1 << TAG} }, \
	{ Mod|Ctrl,			KEY,	toggleview,	{.ui = 1 << TAG} }, \
	{ Mod|Shift,		KEY,	tag,		{.ui = 1 << TAG} }, \
	{ Mod|Ctrl|Shift,	KEY,	toggletag,	{.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "dwmblocks"

/* commands */
#include <X11/XF86keysym.h>
static const char *termcmd[]		= { "ghostty", NULL };
static const char *firefoxcmd[]		= { "firefox", NULL };
static const char *thunarcmd[]		= { "thunar", NULL };

static const char *launchercmd[]	= { "/usr/share/dwm/scripts/launcher", NULL };
static const char *powercmd[]		= { "/usr/share/dwm/scripts/powermenu", NULL };

static const char *mutevol[]		= { "volume", "--toggle", NULL };
static const char *mutemic[]		= { "volume", "--toggle-mic", NULL };
static const char *upvol[]			= { "volume", "--inc", NULL };
static const char *downvol[]		= { "volume", "--dec", NULL };
static const char *upbl[]			= { "brightness", "--inc", NULL };
static const char *downbl[]			= { "brightness", "--dec", NULL };

static const char *sptermcmd[]		= { "t", "ghostty", "--x11-instance-name=spterm", "--title=Scratchpad", NULL };

static const Key keys[] = {
	{ Mod,			XK_Return, 					spawn,			{.v = termcmd } },
	{ Mod,			XK_w,						spawn,			{.v = firefoxcmd } },
	{ Mod,			XK_e,						spawn,			{.v = thunarcmd } },
	{ Mod,			XK_space,					spawn,			{.v = launchercmd } },
	{ Mod,			XK_x,						spawn,			{.v = powercmd } },
	{ 0, 			XF86XK_AudioMute, 			spawn, 			{.v = mutevol } },
	{ 0, 			XF86XK_AudioMicMute, 		spawn, 			{.v = mutemic } },
	{ 0, 			XF86XK_AudioLowerVolume, 	spawn, 			{.v = downvol } },
	{ 0, 			XF86XK_AudioRaiseVolume, 	spawn, 			{.v = upvol } },
	{ 0, 			XF86XK_MonBrightnessUp, 	spawn, 			{.v = upbl	} },
	{ 0, 			XF86XK_MonBrightnessDown, 	spawn, 			{.v = downbl } },
	{ Mod,			XK_grave,					togglescratch,	{.v = sptermcmd } },
	{ Mod|Shift,	XK_b,						togglebar,		{0} },
	{ Mod,			XK_j,						focusstack,		{.i = +1 } },
	{ Mod,			XK_k,						focusstack,		{.i = -1 } },
	{ Mod|Shift,	XK_j,						rotatestack,	{.i = +1 } },
	{ Mod|Shift,	XK_k,						rotatestack,	{.i = -1 } },
	{ Mod,			XK_i,						incnmaster,		{.i = +1 } },
	{ Mod,			XK_d,						incnmaster,		{.i = -1 } },
	{ Mod,			XK_h,						setmfact,		{.f = -0.05} },
	{ Mod,			XK_l,						setmfact,		{.f = +0.05} },
	{ Mod|Shift,	XK_h,						setcfact,		{.f = +0.25} },
	{ Mod|Shift,	XK_l,						setcfact,		{.f = -0.25} },
	{ Mod|Shift,	XK_o,						setcfact,		{.f =	0.00} },
	{ Mod,			XK_Up,						incrgaps,		{.i = +1 } },
	{ Mod,			XK_Down,					incrgaps,		{.i = -1 } },
	{ Mod|Shift,	XK_g,						togglegaps,		{0} },
	{ Mod|Ctrl,		XK_g,						defaultgaps,	{0} },
	{ Mod,			XK_q,						killclient,		{0} },
	{ Mod|Shift,	XK_q,						quit,			{0} },
	{ Mod|Shift,	XK_r,						quit,			{1} }, 
	{ Mod,			XK_t,						setlayout,		{.v = &layouts[0]} },
	{ Mod,			XK_f,						setlayout,		{.v = &layouts[1]} },
	{ Mod,			XK_m,						setlayout,		{.v = &layouts[2]} },
	{ Mod,			XK_comma,					cyclelayout,	{.i = -1 } },
	{ Mod,			XK_period,					cyclelayout,	{.i = +1 } },
	{ Mod|Shift,	XK_space,					togglefloating, {0} },
	{ Mod|Shift,	XK_f,						togglefullscr,	{0} },
	{ Mod,			XK_0,						view,			{.ui = ~0 } },
	{ Mod|Shift,	XK_0,						tag,			{.ui = ~0 } },
	{ Mod,			XK_Right,					viewnext,		{0} },
	{ Mod,			XK_Left,					viewprev,		{0} },
	{ Mod|Shift,	XK_Right,					tagtonext,		{0} },
	{ Mod|Shift,	XK_Left,					tagtoprev,		{0} },
	{ Mod|Shift,	XK_x,						xrdb,			{.v = NULL } },
	TAGKEYS(		XK_1,										0)
	TAGKEYS(		XK_2,										1)
	TAGKEYS(		XK_3,										2)
	TAGKEYS(		XK_4,										3)
	TAGKEYS(		XK_5,										4)
	TAGKEYS(		XK_6,										5)
	TAGKEYS(		XK_7,										6)
	TAGKEYS(		XK_8,										7)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	{ ClkLtSymbol,		0,		Button1,	setlayout,		{0} },
	{ ClkLtSymbol,		0,		Button3,	setlayout,		{.v = &layouts[2]} },
	{ ClkWinTitle,		0,		Button2,	zoom,			{0} },
	{ ClkStatusText,	0,		Button1,	sigstatusbar,	{.i = 1} },
	{ ClkStatusText,	0,		Button2,	sigstatusbar,	{.i = 2} },
	{ ClkStatusText,	0,		Button3,	sigstatusbar,	{.i = 3} },
	{ ClkStatusText,	0,		Button4,	sigstatusbar,	{.i = 4} },
	{ ClkStatusText,	0,		Button5,	sigstatusbar,	{.i = 5} },
	{ ClkClientWin,		Mod,	Button1,	movemouse,		{0} },
	{ ClkClientWin,		Mod,	Button2,	togglefloating, {0} },
	{ ClkClientWin,		Mod,	Button3,	resizemouse,	{0} },
	{ ClkTagBar,		0,		Button1,	view,			{0} },
	{ ClkTagBar,		0,		Button3,	toggleview,		{0} },
	{ ClkTagBar,		Mod,	Button1,	tag,			{0} },
	{ ClkTagBar,		Mod,	Button3,	toggletag,		{0} },
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
	/* signum	function */
	{ "focusstack",		focusstack },
	{ "setmfact",		setmfact },
	{ "togglebar",		togglebar },
	{ "incnmaster",		incnmaster },
	{ "togglefloating", togglefloating },
	{ "focusmon",		focusmon },
	{ "tagmon",			tagmon },
	{ "zoom",			zoom },
	{ "view",			view },
	{ "viewall",		viewall },
	{ "viewex",			viewex },
	{ "toggleview",		view },
	{ "toggleviewex",	toggleviewex },
	{ "tag",			tag },
	{ "tagall",			tagall },
	{ "tagex",			tagex },
	{ "toggletag",		tag },
	{ "toggletagex",	toggletagex },
	{ "killclient",		killclient },
	{ "quit",			quit },
	{ "setlayout",		setlayout },
	{ "setlayoutex",	setlayoutex },
};
