/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx	= 2;
static const unsigned int snap		= 32; 
static const unsigned int gappih	= 10; 
static const unsigned int gappiv	= 10;
static const unsigned int gappoh	= 10;
static const unsigned int gappov	= 10;
static int smartgaps				= 1;
static const int showbar			= 1; 
static const int topbar				= 1;
static const char *fonts[]			= { "Noto Sans:size=11" };
static const char col_gray1[]		= "#050505";
static const char col_gray2[]		= "#545454";
static const char col_gray3[]		= "#abb2bf";
static const char col_gray4[]		= "#dedede";
static const char col_blue[]		= "#61afef";
static const char col_cyan[]		= "#004466";
static const char *colors[][3]		= {
	/*					fg			bg			border	*/
	[SchemeNorm]	= { col_gray3,	col_gray1,	col_gray2 },
	[SchemeSel]		= { col_gray4,	col_cyan,	col_blue },
	[SchemeTitle]	= { col_gray4,	col_gray1,	NULL },
};

static const char *const autostart[] = {
	"/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1", NULL,
	"dunst", NULL,
	"nitrogen", "--restore", NULL,
	"slstatus", NULL,
	"picom", "-b", NULL,
	NULL /* terminate */
};

/* tagging */
static const char *tags[]	= { "1", "2", "3", "4", "5", "6", "7", "8" };

static const Rule rules[]	= {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	{ .class = "Nwg-look", .isfloating = 1, .floatpos = "50% 50% -1h -1w" },
	{ .instance = "floaterm", .isfloating = 1, .floatpos = "50% 50% 80% 80%" },
	{ .class = "firefox", .tags = 1 << 1 },
	{ .class = "Thunar", .tags = 1 << 2 },
	{ .instance = "spterm", .scratchkey = 't', .isfloating = 1, .floatpos = "50% 50% 80% 80%" },
};

/* layout(s) */
static const float mfact		= 0.50;
static const int nmaster		= 1;
static const int resizehints	= 0;
static int floatposgrid_x		= 5; 
static int floatposgrid_y		= 5;
static const int lockfullscreen	= 1;
static const int refreshrate	= 120;

#define FORCE_VSPLIT 1
#include "vanitygaps.c"

static const Layout layouts[]	= {
	/* symbol	arrange function */
	{ "[]=",	tile },
	{ "><>",	NULL },
	{ "[M]",	monocle },
	{ "TTT",	bstack },
	{ "HHH",	gaplessgrid },
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
	{ Super|Ctrl|Shift,		KEY,	toggletag,		{.ui = 1 << TAG} },

/* commands */
static const char *termcmd[]		= { "ghostty", NULL };
static const char *floatermcmd[]	= { "ghostty", "--x11-instance-name=floaterm", NULL };
static const char *fulltermcmd[]	= { "ghostty", "--fullscreen", NULL };
static const char *roficmd[]		= { "rofi", "-show", "drun", NULL };
static const char *firefoxcmd[]		= { "firefox", NULL };
static const char *thunarcmd[]		= { "thunar", NULL };

static const char *sptermcmd[]		= { "t", "ghostty", "--x11-instance-name=spterm", "--title=Scratchpad", NULL };

static const Key keys[] = {
	/* modifier			key					function			argument */
	{ Super,			XK_Return, 			spawn,				{.v = termcmd } },
	{ Super|Shift,		XK_Return, 			spawn,				{.v = floatermcmd } },
	{ Super|Shift,		XK_t, 				spawn,				{.v = fulltermcmd } },
	{ Super,			XK_space,			spawn,				{.v = roficmd } },
	{ Super,			XK_w,				spawn,				{.v = firefoxcmd } },
	{ Super,			XK_e,				spawn,				{.v = thunarcmd } },
	{ Super,			XK_s,				togglescratch,		{.v = sptermcmd } },
	{ Super,			XK_j,				focusstack,			{.i = +1 } },
	{ Super,			XK_k,				focusstack,			{.i = -1 } },
	{ Super|Shift,		XK_j,				rotatestack,		{.i = +1 } },
	{ Super|Shift,		XK_k,				rotatestack,		{.i = -1 } },
	{ Super,			XK_i,				incnmaster,			{.i = +1 } },
	{ Super,			XK_d,				incnmaster,			{.i = -1 } },
	{ Super,			XK_h,				setmfact,			{.f = -0.05} },
	{ Super,			XK_l,				setmfact,			{.f = +0.05} },
	{ Super|Shift,		XK_h,				setcfact,			{.f = +0.25} },
	{ Super|Shift,		XK_l,				setcfact,			{.f = -0.25} },
	{ Super|Shift,		XK_o,				setcfact,			{.f =  0.00} },
	{ Super,			XK_q,				killclient,			{0} },
	{ Super|Shift,		XK_q,				quit,				{0} },
	{ Super|Shift,		XK_r,				quit,				{1} },
	{ Super,			XK_t,				setlayout,			{.v = &layouts[0]} },
	{ Super,			XK_f,				setlayout,			{.v = &layouts[1]} },
	{ Super,			XK_m,				setlayout,			{.v = &layouts[2]} },
	{ Super,			XK_b,				setlayout,			{.v = &layouts[3]} },
	{ Super,			XK_g,				setlayout,			{.v = &layouts[4]} },
	{ Super|Shift,		XK_space,			togglefloating,		{0} },
	{ Super|Shift,		XK_b,				togglebar,			{0} },
	{ Super|Shift,		XK_f,				togglefullscr,		{0} },
	{ Super|Shift,		XK_g,				togglegaps,			{0} },
	{ Super,			XK_0,				view,				{.ui = ~0 } },
	{ Super|Shift,		XK_0,				tag,				{.ui = ~0 } },
	{ Super,			XK_Left,			rotatetags,			{.i = -1 } },
	{ Super,			XK_Right,			rotatetags,			{.i = +1 } },
	TAGKEYS(			XK_1,									0)
	TAGKEYS(			XK_2,									1)
	TAGKEYS(			XK_3,									2)
	TAGKEYS(			XK_4,									3)
	TAGKEYS(			XK_5,									4)
	TAGKEYS(			XK_6,									5)
	TAGKEYS(			XK_7,									6)
	TAGKEYS(			XK_8,									7)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click			event mask	button		function			argument */
	{ ClkLtSymbol,		0,			Button1,	setlayout,			{0} },
	{ ClkLtSymbol,		0,			Button3,	setlayout,			{.v = &layouts[2]} },
	{ ClkWinTitle,		0,			Button2,	zoom,				{0} },
	{ ClkStatusText,	0,			Button2,	spawn,				{.v = termcmd } },
	{ ClkClientWin,		Super,		Button1,	movemouse,			{0} },
	{ ClkClientWin,		Super,		Button2,	togglefloating,		{0} },
	{ ClkClientWin,		Super,		Button3,	resizemouse,		{0} },
	{ ClkTagBar,		0,			Button1,	view,				{0} },
	{ ClkTagBar,		0,			Button3,	toggleview,			{0} },
	{ ClkTagBar,		Super,		Button1,	tag,				{0} },
	{ ClkTagBar,		Super,		Button3,	toggletag,			{0} },
};

