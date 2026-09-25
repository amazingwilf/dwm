/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx	= 4;
static const unsigned int snap		= 32;
static int floatposgrid_x			= 5;
static int floatposgrid_y			= 5;
static const char *toggle_float_pos = "50% 50% 80% 80%";
static const int swallowfloating	= 0;

static const unsigned int gappih	= 10;
static const unsigned int gappiv	= 10;
static const unsigned int gappoh	= 20;
static const unsigned int gappov	= 20;
static int smartgaps				= 1;

static const int showbar	= 1;
static const int topbar		= 1;
static const int user_bh	= 10;

#define ICONSIZE (bh - 10)
#define ICONSPACING 10 

static const char *fonts[]	= { "DWM Layout Glyphs:size=14",
								"Noto Sans:size=12" };

#include "colors.h"

static const char *colors[][3]	= {
	[SchemeNorm]		= { white1,	black,	gray },
	[SchemeSel]			= { white2,	black,	blue },
	[SchemeFloat]		= { NULL,	NULL,	magenta },
	[SchemeScratchNorm]	= { NULL,	NULL,	gray },
	[SchemeScratchSel]	= { NULL,	NULL,	red	},
	[SchemeSticky]		= { NULL,	NULL,	yellow },
	[SchemeTagsEmpty]	= { gray,	black,	NULL },
	[SchemeTagsOcc]		= { green,	black,	NULL },
	[SchemeTagsSel]		= { white2,	black,	NULL },
	[SchemeLtSym]		= { yellow,	black,	NULL },
};

static const char *const autostart[] = {
	"/usr/lib/xfce-polkit/sfce-polkit", NULL,
	"superkeys", NULL,
	"nitrogen", "--restore", NULL,
	"sxhkd", NULL,
	"dunst", NULL,
	"slstatus", NULL,
	"picom", "-b", NULL,
	NULL /* terminate */
};

/* tagging */
static const char *tags[] 			= { "1", "2", "3", "4", "5", "6" };
static const int viewontag			= 1;
static const int viewonrulestag 	= 1;

static const unsigned int ulinepad		= 5;
static const unsigned int ulinestroke	= 2;
static const unsigned int ulinevoffset	= 0;
static const int ulineall				= 0;

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	{ .class = "Nwg-look", .isfloating = 1, .floatpos = "50% 50% -1h -1w" },
	{ .class = "firefox", .tags = 1 << 1 },
	{ .class = "Thunar", .isfloating = 1 << 2, .floatpos = "50% 50% 90% 90%" },
	{ .instance = "spterm", .scratchkey = 't', .isfloating = 1, .floatpos = "50% 50% 80% 80%" },
	{ .instance = "floaterm", .isfloating = 1, .floatpos = "50% 50% 80% 80%" },
	{ .class = "kitty", .isterminal = 1 },
	{ .title = "Event Tester", .noswallow = 1, .isfloating = 1 },
};

/* layout(s) */
static const float mfact		= 0.50; 
static const int nmaster		= 1;
static const int resizehints 	= 0;
static const int lockfullscreen	= 1;
static const int refreshrate 	= 120;

#define FORCE_VSPLIT 1
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol	arrange function */
	{ "\ue000",		tile }, 
	{ "\ue001",		monocle },
	{ "\ue00C",		bstack },
	{ "\ue00A",		gaplessgrid },
	{ NULL,			NULL },
};

/* key definitions */
#define MOD Mod4Mask
#define SHIFT ShiftMask
#define CTRL ControlMask
#define ALT Mod1Mask

#define TAGKEYS(KEY,TAG) \
	{ MOD,				KEY,	view,		{.ui = 1 << TAG} }, \
	{ MOD|CTRL,			KEY,	toggleview,	{.ui = 1 << TAG} }, \
	{ MOD|SHIFT,		KEY,	tag,		{.ui = 1 << TAG} }, \
	{ MOD|CTRL|SHIFT,	KEY,	toggletag,	{.ui = 1 << TAG} },

/* commands */
static const char *sptermcmd[] = { "t", "kitty", "--app-id", "spterm", "--title", "Scratchpad", NULL};



static const Key keys[] = {
	/* modifier	key	function	argument */
	{ MOD,			XK_j,		focusstack,		{.i = +1 } },
	{ MOD,			XK_k,		focusstack,		{.i = -1 } },
	{ MOD|SHIFT,	XK_j,		rotatestack,	{.i = +1 } },
	{ MOD|SHIFT,	XK_k,		rotatestack,	{.i = -1 } },
	{ MOD,			XK_i,		incnmaster,		{.i = +1 } },
	{ MOD,			XK_d,		incnmaster,		{.i = -1 } },
	{ MOD,			XK_h,		setmfact,		{.f = -0.05} },
	{ MOD,			XK_l,		setmfact,		{.f = +0.05} },
	{ MOD|SHIFT,	XK_h,		setcfact,		{.f = +0.25} },
	{ MOD|SHIFT,	XK_l,		setcfact,		{.f = -0.25} },
	{ MOD|SHIFT,	XK_o,		setcfact,		{.f =	0.00} },
	{ MOD,			XK_q,		killclient,		{0} },
	{ MOD|SHIFT,	XK_q,		quit,			{0} },
	{ MOD,			XK_t,		setlayout,		{.v = &layouts[0]} },
	{ MOD,			XK_m,		setlayout,		{.v = &layouts[1]} },
	{ MOD,			XK_b,		setlayout,		{.v = &layouts[2]} },
	{ MOD,			XK_g,		setlayout,		{.v = &layouts[3]} },
	{ MOD|SHIFT,	XK_b,		togglebar,		{0} },
	{ MOD,			XK_space,	togglefloating, {0} },
	{ MOD,			XK_f,		togglefullscr,	{0} },
	{ MOD|SHIFT,	XK_g,		togglegaps,		{0} },
	{ MOD,			XK_s,		togglesticky,	{0} },
	{ MOD,			XK_grave,	togglescratch,	{.v = sptermcmd} },
	{ MOD,			XK_0,		view,			{.ui = ~0 } },
	{ MOD|SHIFT,	XK_0,		tag,			{.ui = ~0 } },
	{ MOD,			XK_Right,	viewnext,		{0} },
	{ MOD,			XK_Left,	viewprev,		{0} },
	{ MOD|SHIFT,	XK_Right,	tagtonext,		{0} },
	{ MOD|SHIFT,	XK_Left,	tagtoprev,		{0} },
	TAGKEYS(		XK_1,						0)
	TAGKEYS(		XK_2,						1)
	TAGKEYS(		XK_3,						2)
	TAGKEYS(		XK_4,						3)
	TAGKEYS(		XK_5,						4)
	TAGKEYS(		XK_6,						5)
};

/* button definitions */
static const Button buttons[] = {
	/* click	event mask	button	function	argument */
	{ ClkLtSymbol,	0,		Button1,	setlayout,		{0} },
	{ ClkLtSymbol,	0,		Button3,	setlayout,		{.v = &layouts[2]} },

	{ ClkWinTitle,	0,		Button2,	zoom,			{0} },

	{ ClkClientWin,	MOD,	Button1,	movemouse,		{0} },
	{ ClkClientWin,	MOD,	Button2,	togglefloating, {0} },
	{ ClkClientWin,	MOD,	Button3,	resizemouse,	{0} },

	{ ClkTagBar,	0,		Button1,	view,			{0} },
	{ ClkTagBar,	0,		Button3,	toggleview,		{0} },
	{ ClkTagBar,	MOD,	Button1,	tag,			{0} },
	{ ClkTagBar,	MOD,	Button3,	toggletag,		{0} },
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
