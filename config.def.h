/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx		= 3;
static const unsigned int snap			= 32;
static const int swallowfloating		= 0; 
static const int swterminheritfs		= 1; 
static int floatposgrid_x				= 5; 
static int floatposgrid_y				= 5;
static const char *toggle_float_pos		= "50% 50% 80% 80%"; // default floating position when triggering togglefloating

static const unsigned int gappih		= 15;
static const unsigned int gappiv		= 15;
static const unsigned int gappoh		= 15;
static const unsigned int gappov		= 15;
static int smartgaps					= 0;

static const int showbar				= 1;
static const int topbar					= 1;
static const int user_bh				= 8;

static const char *fonts[]				= { "Iosevka:size=12",
											"JetBrainsMono Nerd Font:size=12",
											"JetBrainsMono Nerd Font:style=ExtraBold:size=10" };

#include "termcolors.h"

static char normfgcolor[]				= "#bbbbbb";
static char normbgcolor[]				= "#222222";
static char normbordercolor[]			= "#444444";
static char normfloatcolor[]			= "#444444";

static char selfgcolor[]				= "#eeeeee";
static char selbgcolor[]				= "#005577";
static char selbordercolor[]			= "#005577";
static char selfloatcolor[]				= "#005577";

static char scratchnormbordercolor[]	= "#444444";
static char scratchnormfloatcolor[]		= "#444444";
static char scratchselbordercolor[]		= "#005577";
static char scratchselfloatcolor[]		= "#005577";

static char stickybordercolor[]			= "#dddd00";
static char stickyfloatcolor[]			= "#dddd00";

static char tagsemptyfgcolor[]			= "#444444";
static char tagsemptybgcolor[]			= "#222222";
static char tagsoccfgcolor[]			= "#bbbbbb";
static char tagsoccbgcolor[]			= "#222222";
static char tagsselfgcolor[]			= "#eeeeee";
static char tagsselbgcolor[]			= "#005577";

static char ltsymbolfgcolor[]			= "#dddd00";
static char ltsymbolbgcolor[]			= "#222222";

static char *colors[][4] = {
       [SchemeNorm]			= { normfgcolor,		normbgcolor,		normbordercolor,		normfloatcolor },
       [SchemeSel]			= { selfgcolor,			selbgcolor,			selbordercolor,			selfloatcolor },
       [SchemeScratchNorm]	= { NULL,				NULL,				scratchnormbordercolor,	scratchnormfloatcolor },
       [SchemeScratchSel]	= { NULL,				NULL,				scratchselbordercolor,	scratchselfloatcolor },
       [SchemeSticky]		= { NULL,				NULL,				stickybordercolor,		stickyfloatcolor },
       [SchemeTagsEmpty]	= { tagsemptyfgcolor,	tagsemptybgcolor,	NULL,					NULL },
       [SchemeTagsOcc]		= { tagsoccfgcolor,		tagsoccbgcolor,		NULL,					NULL },
       [SchemeTagsSel]		= { tagsselfgcolor,		tagsselbgcolor,		NULL,					NULL },
       [SchemeLtSymbol]		= { ltsymbolfgcolor,	ltsymbolbgcolor,	NULL,					NULL },
};

static const unsigned int baralpha		= 0xd0;
static const unsigned int borderalpha	= OPAQUE;
static const unsigned int alphas[][4]	= {
    [SchemeNorm]			= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeSel]				= { OPAQUE, OPAQUE,   borderalpha, borderalpha },
    [SchemeScratchNorm]		= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeScratchSel]		= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeSticky]			= { OPAQUE, baralpha, borderalpha, borderalpha },
    [SchemeTagsEmpty]		= { OPAQUE, baralpha, borderalpha, borderalpha },
    [SchemeTagsOcc]			= { OPAQUE, baralpha, borderalpha, borderalpha },
    [SchemeTagsSel]			= { OPAQUE, OPAQUE,   borderalpha, borderalpha },
};

static const char *const autostart[] = {
	"/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1", NULL,
	"nitrogen", "--restore", NULL,
	"dunst", NULL,
	"superkeys", NULL,
	"picom", "-b", NULL,
	"dwmblocks", NULL,
	NULL /* terminate */
};

/* tagging */
static const char *tags[]	= { "1", "2", "3", "4", "5", "6", "7", "8" };

static const Rule rules[]	= {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	{ .class = "Nwg-look", .isfloating = 1, .iscentered = 1 },
	{ .class = "pavucontrol", .isfloating = 1, .iscentered = 1 },
	{ .class = "firefox", .tags = 1 << 1 },
	{ .class = "Thunar", .tags = 1 << 2 },
	{ .class = "com.mitchellh.ghostty", .isterminal = 1 },
	{ .class = "st", .isterminal = 1 },
	{ .class = "Alacritty", .isterminal = 1 },
	{ .class = "kitty", .isterminal = 1 },
	{ .title = "Event Tester", .noswallow = 1 },
	{ .instance = "spterm", .scratchkey = 't', .isfloating = 1, .floatpos = "50% 50% 80% 80%" },
	{ .instance = "calcurse", .isfloating = 1, .floatpos = "50% 50% 80% 80%" },
	{ .instance = "floaterm", .isfloating = 1, .floatpos = "50% 50% 80% 80%" },
};

/* layout(s) */
static const float mfact		= 0.50;
static const int nmaster		= 1;
static const int resizehints	= 0;
static const int lockfullscreen	= 1;

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
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
#define Mod Mod4Mask
#define Shift ShiftMask
#define Ctrl ControlMask
#define Alt Mod1Mask

#define TAGKEYS(KEY,TAG) \
	{ Mod,				KEY,	view,		{.ui = 1 << TAG} }, \
	{ Mod|Ctrl,			KEY,	toggleview,	{.ui = 1 << TAG} }, \
	{ Mod|Shift,		KEY,	tag,		{.ui = 1 << TAG} }, \
	{ Mod|Ctrl|Shift, 	KEY,	toggletag,	{.ui = 1 << TAG} },

#define SCRATCHKEYS(KEY,CMD) \
	{ Mod,				KEY,	togglescratch,		{.v = CMD} }, \
	{ Mod|Shift,		KEY,	removescratch,		{.v = CMD} }, \
	{ Mod|Ctrl,			KEY,	setscratch,			{.v = CMD} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "dwmblocks"

/* commands */
static const char *termcmd[]		= { "ghostty", "--title=Terminal", NULL };
static const char *firefoxcmd[]		= { "firefox", NULL };
static const char *thunarcmd[]		= { "thunar", NULL };

static const char *launchercmd[] 	= { "/usr/share/archcraft/dwm/scripts/rofi_launcher", NULL };
static const char *powercmd[] 		= { "/usr/share/archcraft/dwm/scripts/rofi_powermenu", NULL };

static const char *volmute[]		= { "volume", "--toggle", NULL };
static const char *voldown[]		= { "volume", "--dec", NULL };
static const char *volup[]			= { "volume", "--inc", NULL };
static const char *micmute[]		= { "volume", "--toggle-mic", NULL };
static const char *bldown[]			= { "brightness", "--dec", NULL };
static const char *blup[]			= { "brightness", "--inc", NULL };

static const char *sptermcmd[]		= { "t", "ghostty", "--x11-instance-name=spterm", "--title=Scratchpad", NULL };

static const Key keys[] = {
	{ Mod,			XK_Return, 	spawn,				{.v = termcmd } },
	{ Mod,			XK_w,		spawn,				{.v = firefoxcmd } },
	{ Mod,			XK_e,		spawn,				{.v = thunarcmd } },
	{ Alt,			XK_F1,		spawn,				{.v = launchercmd } },
	{ 0,			XK_F12,		spawn,				{.v = powercmd } },
	{ 0,			XK_F1,		spawn,				{.v = volmute } },
	{ 0,			XK_F2,		spawn,				{.v = voldown } },
	{ 0,			XK_F3,		spawn,				{.v = volup } },
	{ 0,			XK_F4,		spawn,				{.v = micmute } },
	{ 0,			XK_F5,		spawn,				{.v = bldown } },
	{ 0,			XK_F6,		spawn,				{.v = blup } },
	{ Mod,			XK_j,		focusstack,			{.i = +1 } },
	{ Mod,			XK_k,		focusstack,			{.i = -1 } },
	{ Mod,			XK_i,		incnmaster,			{.i = +1 } },
	{ Mod,			XK_d,		incnmaster,			{.i = -1 } },
	{ Mod,			XK_h,		setmfact,			{.f = -0.05} },
	{ Mod,			XK_l,		setmfact,			{.f = +0.05} },
	{ Mod|Shift,	XK_h,		setcfact,			{.f = +0.25} },
	{ Mod|Shift,	XK_l,		setcfact,			{.f = -0.25} },
	{ Mod|Shift,	XK_o,		setcfact,			{.f =	0.00} },
	{ Mod|Shift,	XK_g,		togglegaps,			{0} },
	{ Mod,			XK_q,		killclient,			{0} },
	{ Mod,			XK_t,		setlayout,			{.v = &layouts[0]} },
	{ Mod,			XK_f,		setlayout,			{.v = &layouts[1]} },
	{ Mod,			XK_m,		setlayout,			{.v = &layouts[2]} },
	{ Mod,			XK_b,		setlayout,			{.v = &layouts[6]} },
	{ Mod,			XK_g,		setlayout,			{.v = &layouts[11]} },
	{ Mod,			XK_comma,	cyclelayout,		{.i = -1 } },
	{ Mod,			XK_period,	cyclelayout,		{.i = +1 } },
	{ Mod|Shift,	XK_b,		togglebar,			{0} },
	{ Mod|Shift,	XK_space,	togglefloating,		{0} },
	{ Mod|Shift,	XK_f,		togglefullscr,		{0} },
	{ 0,			XK_F11,		togglefullscr,		{0} },
	{ Mod|Shift,	XK_s,		togglesticky,		{0} },
	{ Mod|Shift,	XK_x,		xrdb,				{.v = NULL } },
	{ Mod,			XK_0,		view,				{.ui = ~0 } },
	{ Mod|Shift,	XK_0,		tag,				{.ui = ~0 } },
	{ Mod,			XK_Right,	viewnext,			{0} },
	{ Mod,			XK_Left,	viewprev,			{0} },
	{ Mod|Shift,	XK_Right,	tagtonext,			{0} },
	{ Mod|Shift,	XK_Left,	tagtoprev,			{0} },
	SCRATCHKEYS(	XK_grave,						sptermcmd)
	TAGKEYS(		XK_1,							0)
	TAGKEYS(		XK_2,							1)
	TAGKEYS(		XK_3,							2)
	TAGKEYS(		XK_4,							3)
	TAGKEYS(		XK_5,							4)
	TAGKEYS(		XK_6,							5)
	TAGKEYS(		XK_7,							6)
	TAGKEYS(		XK_8,							7)
	{ Mod|Shift,	XK_q,		quit,				{0} },
	{ Mod|Shift,	XK_r,		quit,				{1} }, 
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
