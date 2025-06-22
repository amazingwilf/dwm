/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx		= 2;
static const unsigned int snap			= 32;
static const int attachmode				= 2;
static int floatposgrid_x				= 5;	/* float grid columns */
static int floatposgrid_y				= 5;	/* float grid rows */

static const int showbar				= 1;
static const int topbar					= 1;

#define ICONSIZE (bh - 10)
#define ICONSPACING 10 

static const unsigned int gappih		= 20; 
static const unsigned int gappiv		= 20;
static const unsigned int gappoh		= 10;
static const unsigned int gappov		= 10;
static int smartgaps					= 1;


static const char *fonts[]				= { "NotoSans Nerd Font:size=12",
											"JetBrainsMono Nerd Font:size=11:style=ExtraBold" };
static const char dmenufont[]			= "NotoSans Nerd Font:size=12";

#include "termcolors.h"

static char normfgcolor[]				= "#bbbbbb";
static char normbgcolor[]				= "#222222";
static char normbordercolor[]			= "#444444";

static char selfgcolor[]				= "#eeeeee";
static char selbgcolor[]				= "#005577";
static char selbordercolor[]			= "#005577";

static char ltsymfgcolor[]				= "#dddd00";
static char ltsymbgcolor[]				= "#222222";

static char *colors[][3]				= {
	[SchemeNorm] 	= { normfgcolor,	normbgcolor,	normbordercolor },
	[SchemeSel]		= { selfgcolor,		selbgcolor,		selbordercolor },
	[SchemeLtSym]	= { ltsymfgcolor,	ltsymbgcolor,	NULL },
};

static const unsigned int baralpha		= 0xd0;
static const unsigned int borderalpha	= OPAQUE;
static const unsigned int alphas[][3]	= {
	[SchemeNorm] 	= { OPAQUE, baralpha, borderalpha },
	[SchemeSel]		= { OPAQUE, baralpha, borderalpha },
	[SchemeLtSym]	= { OPAQUE, baralpha, borderalpha },
};

static const char *const autostart[] = {
	"/usr/lib/xfce-polkit/xfce-polkit", NULL,
	"dunst", NULL,
	"nitrogen", "--restore", NULL,
	"picom", "-b", NULL,
	"dwmblocks", NULL,
	NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	{ .class = "Nwg-look", .isfloating = 1, .iscentered = 1 },
	{ .class = "pavucontrol", .isfloating = 1, .iscentered = 1 },
	{ .class = "firefox", .tags = 1 << 1 },
	{ .instance = "spterm", .scratchkey = 't', .isfloating = 1, .floatpos = "50% 50% 80% 80%" },
};

/* layout(s) */
static const float mfact			= 0.50;
static const int nmaster			= 1;	
static const int resizehints		= 0; 
static const int lockfullscreen		= 1;
static const char *toggle_float_pos	= "50% 50% 80% 80%";

#define FORCE_VSPLIT 1
#include "vanitygaps.c"

static const Layout layouts[] = {
	{ "[]=",tile },	/* first entry is default */
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
#define MOD Mod4Mask
#define CTL ControlMask
#define SFT ShiftMask
#define ALT Mod1Mask

#define TAGKEYS(KEY,TAG) \
	{ MOD,			KEY,	view,			{.ui = 1 << TAG} }, \
	{ MOD|CTL,		KEY,	toggleview,		{.ui = 1 << TAG} }, \
	{ MOD|SFT,		KEY,	tag,			{.ui = 1 << TAG} }, \
	{ MOD|CTL|SFT,	KEY,	toggletag,		{.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "dwmblocks"

/* commands */
static const char *termcmd[]	= { "ghostty", "--title=Terminal", NULL };
static const char *dmenucmd[]	= { "dmenu_run", "-p", "Run: ", "-fn", dmenufont, "-nb", "#171717", "-nf", "#61afef", "-sb", "#aa0000", "-sf", "#dddd00", NULL };
static const char *roficmd[]	= { "rofi", "-show", "drun", NULL };
static const char *webcmd[]		= { "firefox", NULL};

static const char *volmute[]	= { "volume", "--toggle", NULL };
static const char *voldown[]	= { "volume", "--dec", NULL };
static const char *volup[]		= { "volume", "--inc", NULL };
static const char *micmute[]	= { "volume", "--toggle-mic" };

static const char *bldown[]		= { "brightness", "--dec", NULL };
static const char *blup[]		= { "brightness", "--inc", NULL };

static const char *sptermcmd[]	= { "t", "ghostty", "--x11-instance-name=spterm", "--title=Scratchpad", NULL };

static const Key keys[] = {
	/* modifier	key	function	argument */
	{ MOD,			XK_Return,	spawn,			{.v = termcmd } },
	{ MOD,			XK_space,	spawn,			{.v = dmenucmd } },
	{ MOD,			XK_r,		spawn,			{.v = roficmd } },
	{ MOD,			XK_w,		spawn,			{.v = webcmd } },

	{ 0,			XK_F1,		spawn,			{.v = volmute } },
	{ 0,			XK_F2,		spawn,			{.v = voldown } },
	{ 0,			XK_F3,		spawn,			{.v = volup } },
	{ 0,			XK_F4,		spawn,			{.v = micmute } },

	{ 0,			XK_F5,		spawn,			{.v = bldown } },
	{ 0,			XK_F6,		spawn,			{.v = blup } },

	{ MOD,			XK_grave,	togglescratch,	{.v = sptermcmd } },

	{ MOD,			XK_j,		focusstack,		{.i = +1 } },
	{ MOD,			XK_k,		focusstack,		{.i = -1 } },

	{ MOD|SFT,		XK_j,		rotatestack,	{.i = +1 } },
	{ MOD|SFT,		XK_k,		rotatestack,	{.i = -1 } },

	{ MOD,			XK_i,		incnmaster,		{.i = +1 } },
	{ MOD,			XK_d,		incnmaster,		{.i = -1 } },

	{ MOD,			XK_h,		setmfact,		{.f = -0.05} },
	{ MOD,			XK_l,		setmfact,		{.f = +0.05} },
	{ MOD|SFT,		XK_h,		setcfact,		{.f = +0.25} },
	{ MOD|SFT,		XK_l,		setcfact,		{.f = -0.25} },
	{ MOD|SFT,		XK_o,		setcfact,		{.f = 0.00} },

	{ MOD,			XK_q,		killclient,		{0} },
	{ MOD|SFT,		XK_q,		quit,			{0} },
	{ MOD|SFT,		XK_r,		quit,			{1} }, 

	{ MOD,			XK_t,		setlayout,		{.v = &layouts[0]} },
	{ MOD,			XK_f,		setlayout,		{.v = &layouts[1]} },
	{ MOD,			XK_m,		setlayout,		{.v = &layouts[2]} },
	{ MOD,			XK_b,		setlayout,		{.v = &layouts[6]} },
	{ MOD,			XK_g,		setlayout,		{.v = &layouts[11]} },
	{ MOD,			XK_comma,	cyclelayout,	{.i = -1 } },
	{ MOD,			XK_period,	cyclelayout,	{.i = +1 } },

	{ MOD|SFT,		XK_b,		togglebar,		{0} },
	{ MOD|SFT,		XK_space,	togglefloating, {0} },
	{ MOD|SFT,		XK_f,		togglefullscr,	{0} },
	{ MOD|SFT,		XK_x,		xrdb,			{.v = NULL } },

	{ MOD,			XK_0,		view,			{.ui = ~0 } },
	{ MOD|SFT,		XK_0,		tag,			{.ui = ~0 } },

	{ MOD,			XK_Right,	viewnext,		{0} },
	{ MOD,			XK_Left,	viewprev,		{0} },
	{ MOD|SFT,		XK_Right,	tagtonext,		{0} },
	{ MOD|SFT,		XK_Left,	tagtoprev,		{0} },

	TAGKEYS(		XK_1,						0)
	TAGKEYS(		XK_2,						1)
	TAGKEYS(		XK_3,						2)
	TAGKEYS(		XK_4,						3)
	TAGKEYS(		XK_5,						4)
	TAGKEYS(		XK_6,						5)
	TAGKEYS(		XK_7,						6)
	TAGKEYS(		XK_8,						7)
	TAGKEYS(		XK_9,						8)
};

/* button definitions */
static const Button buttons[] = {
	{ ClkLtSymbol,		0,		Button1,	setlayout,		{0} },
	{ ClkLtSymbol,		0,		Button3,	setlayout,		{.v = &layouts[2]} },
	{ ClkLtSymbol,		0,		Button4,	cyclelayout,	{.i = +1 } },
	{ ClkLtSymbol,		0,		Button5,	cyclelayout,	{.i = -1 } },

	{ ClkWinTitle,		0,		Button2,	zoom,			{0} },

	{ ClkStatusText,	0,		Button1,	sigstatusbar,	{.i = 1} },
	{ ClkStatusText,	0,		Button2,	sigstatusbar,	{.i = 2} },
	{ ClkStatusText,	0,		Button3,	sigstatusbar,	{.i = 3} },
	{ ClkStatusText,	0,		Button4,	sigstatusbar,	{.i = 4} },
	{ ClkStatusText,	0,		Button5,	sigstatusbar,	{.i = 5} },

	{ ClkClientWin,		MOD,	Button1,	movemouse,		{0} },
	{ ClkClientWin,		MOD,	Button2,	togglefloating, {0} },
	{ ClkClientWin,		MOD,	Button3,	resizemouse,	{0} },

	{ ClkTagBar,		0,		Button1,	view,			{0} },
	{ ClkTagBar,		0,		Button3,	toggleview,		{0} },
	{ ClkTagBar,		MOD,	Button1,	tag,			{0} },
	{ ClkTagBar,		MOD,	Button3,	toggletag,		{0} },
};

