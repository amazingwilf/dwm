/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx	= 2;
static const unsigned int snap		= 32;
static int floatposgrid_x			= 5;
static int floatposgrid_y			= 5;
static const char *toggle_float_pos	= "50% 50% 80% 80%";

static const unsigned int gappih	= 10;
static const unsigned int gappiv	= 10;
static const unsigned int gappoh	= 20;
static const unsigned int gappov	= 20;
static int smartgaps				= 1;

static const int showbar			= 1;
static const int topbar				= 1;
static const int user_bh			= 8;

#define ICONSIZE (bh - 12)
#define ICONSPACING 10

static const char *fonts[]			= { "IosevkaTerm Nerd Font:size=12:style=Medium",
										"IosevkaTerm Nerd Font Mono:size=10:style=ExtraBold" };
static const char dmenufont[]		= "IosevkaTerm Nerd Font:size=14:style=Medium";

static char normfgcolor[]			= "#bbbbbb";
static char normbgcolor[]			= "#222222";
static char normbordercolor[]		= "#444444";
static char normfloatcolor[]		= "#444444";

static char selfgcolor[]			= "#eeeeee";
static char selbgcolor[]			= "#005577";
static char selbordercolor[]		= "#005577";
static char selfloatcolor[]			= "#005577";

static char tagsselfgcolor[]		= "#eeeeee";
static char tagsselbgcolor[]		= "#005577";

static char tagsoccfgcolor[]		= "#bbbbbb";
static char tagsoccbgcolor[]		= "#222222";

static char tagsemptyfgcolor[]		= "#444444";
static char tagsemptybgcolor[]		= "#222222";

static char ltsymbolfgcolor[]		= "#bbbb00";
static char ltsymbolbgcolor[]		= "#222222";

static char *colors[][4]			= {
	[SchemeNorm]		= { normfgcolor,		normbgcolor,		normbordercolor,	normfloatcolor },
	[SchemeSel]			= { selfgcolor,			selbgcolor,			selbordercolor,		selfloatcolor },
	[SchemeTagsSel]		= { tagsselfgcolor,		tagsselbgcolor,		NULL,				NULL },
	[SchemeTagsOcc]		= { tagsoccfgcolor,		tagsoccbgcolor,		NULL,				NULL },
	[SchemeTagsEmpty]	= { tagsemptyfgcolor,	tagsemptybgcolor,	NULL,				NULL },
	[SchemeLtSymbol]	= { ltsymbolfgcolor,	ltsymbolbgcolor,	NULL,				NULL },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	{ .class = "Nwg-look", .isfloating = 1, .bw = -1, .iscentered = 1, .bw = 5 },
	{ .class = "firefox", .tags = 1 << 1, .bw = -1 },
	{ .instance = "spterm", .scratchkey = 't', .isfloating = 1, .floatpos = "50% 50% 80% 80%", .bw = 5 },
};

/* layout(s) */
static const float mfact		= 0.50;
static const int nmaster		= 1;
static const int resizehints	= 0;
static const int lockfullscreen	= 1;

#define FORCE_VSPLIT 1	/* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	{ "[]=",	tile },	/* first entry is default */
	{ "><>",	NULL },	/* no layout function means floating behavior */
	{ "[M]",	monocle },
	{ "TTT",	bstack },
	{ ":::",	gaplessgrid },
	{ NULL,		NULL },
};

/* key definitions */
#define MOD Mod4Mask
#define SFT ShiftMask
#define CTL ControlMask
#define ALT Mod1Mask

#define TAGKEYS(KEY,TAG) \
	{ MOD,			KEY,	view,			{.ui = 1 << TAG} }, \
	{ MOD|CTL,		KEY,	toggleview,		{.ui = 1 << TAG} }, \
	{ MOD|SFT,		KEY,	tag,			{.ui = 1 << TAG} }, \
	{ MOD|CTL|SFT,	KEY,	toggletag,		{.ui = 1 << TAG} },

/* commands */
static const char *termcmd[] 		= { "ghostty", "--title=Terminal", NULL };
static const char *dmenucmd[]		= { "dmenu_run", "-p", "Run: ", "-fn", dmenufont, "-nb", normbgcolor, "-nf", selbordercolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *webcmd[]			= { "firefox", NULL };

static const char *volmutecmd[]		= { "volume", "--toggle", NULL };
static const char *voldowncmd[]		= { "volume", "--dec", NULL };
static const char *volupcmd[]		= { "volume", "--inc", NULL };
static const char *volmicmutecmd[]	= { "volume", "--toggle-mic", NULL };

static const char *bldowncmd[]		= { "brightness", "--dec", NULL };
static const char *blupcmd[]		= { "brightness", "--inc", NULL };

static const char *sptermcmd[]		= { "t", "ghostty", "--x11-instance-name=spterm", "--title=Scratchpad", NULL};

static const Key keys[] = {
	/* modifier	key	function	argument */
	{ MOD,			XK_Return, 		spawn,				{.v = termcmd } },
	{ MOD,			XK_space,		spawn,				{.v = dmenucmd } },
	{ MOD,			XK_w,			spawn,				{.v = webcmd } },

	{ 0,			XK_F1,			spawn,				{.v = volmutecmd } },
	{ 0,			XK_F2,			spawn,				{.v = voldowncmd } },
	{ 0,			XK_F3,			spawn,				{.v = volupcmd } },
	{ 0,			XK_F4,			spawn,				{.v = volmicmutecmd } },

	{ 0,			XK_F5,			spawn,				{.v = bldowncmd } },
	{ 0,			XK_F6,			spawn,				{.v = blupcmd } },

	{ MOD,			XK_grave,		togglescratch,		{.v = sptermcmd } },
	{ MOD,			XK_j,			focusstack,			{.i = +1 } },
	{ MOD,			XK_k,			focusstack,			{.i = -1 } },
	{ MOD|SFT,		XK_j,			rotatestack,		{.i = +1 } },
	{ MOD|SFT,		XK_k,			rotatestack,		{.i = -1 } },
	{ MOD,			XK_i,			incnmaster,			{.i = +1 } },
	{ MOD,			XK_d,			incnmaster,			{.i = -1 } },
	{ MOD,			XK_h,			setmfact,			{.f = -0.05} },
	{ MOD,			XK_l,			setmfact,			{.f = +0.05} },
	{ MOD|SFT,		XK_h,			setcfact,			{.f = +0.25} },
	{ MOD|SFT,		XK_l,			setcfact,			{.f = -0.25} },
	{ MOD|SFT,		XK_o,			setcfact,			{.f =	0.00} },
	{ MOD,			XK_q,			killclient,			{0} },
	{ MOD|SFT,		XK_q,			quit,				{0} },
	{ MOD|SFT,		XK_r,			quit,				{1} }, 
	{ MOD,			XK_t,			setlayout,			{.v = &layouts[0]} },
	{ MOD,			XK_f,			setlayout,			{.v = &layouts[1]} },
	{ MOD,			XK_m,			setlayout,			{.v = &layouts[2]} },
	{ MOD,			XK_b,			setlayout,			{.v = &layouts[3]} },
	{ MOD,			XK_g,			setlayout,			{.v = &layouts[4]} },
	{ MOD|SFT,		XK_space,		togglefloating,		{0} },
	{ MOD|SFT,		XK_f,			togglefullscr,		{0} },
	{ MOD|SFT,		XK_b,			togglebar,			{0} },
	{ MOD,			XK_0,			view,				{.ui = ~0 } },
	{ MOD|SFT,		XK_0,			tag,				{.ui = ~0 } },
	{ MOD,			XK_Right,		viewnext,			{0} },
	{ MOD,			XK_Left,		viewprev,			{0} },
	{ MOD|SFT,		XK_Right,		tagtonext,			{0} },
	{ MOD|SFT,		XK_Left,		tagtoprev,			{0} },
	{ MOD|SFT,		XK_x,			xrdb,				{.v = NULL } },
	TAGKEYS(		XK_1,								0)
	TAGKEYS(		XK_2,								1)
	TAGKEYS(		XK_3,								2)
	TAGKEYS(		XK_4,								3)
	TAGKEYS(		XK_5,								4)
	TAGKEYS(		XK_6,								5)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	{ ClkLtSymbol,		0,		Button1,	setlayout,		{0} },
	{ ClkLtSymbol,		0,		Button3,	setlayout,		{.v = &layouts[2]} },
	{ ClkWinTitle,		0,		Button2,	zoom,			{0} },
	{ ClkStatusText,	0,		Button2,	spawn,			{.v = termcmd } },
	{ ClkClientWin,		MOD,	Button1,	movemouse,		{0} },
	{ ClkClientWin,		MOD,	Button2,	togglefloating, {0} },
	{ ClkClientWin,		MOD,	Button3,	resizemouse,	{0} },
	{ ClkTagBar,		0,		Button1,	view,			{0} },
	{ ClkTagBar,		0,		Button3,	toggleview,		{0} },
	{ ClkTagBar,		MOD,	Button1,	tag,			{0} },
	{ ClkTagBar,		MOD,	Button3,	toggletag,		{0} },
};

