/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx	= 2;
static const unsigned int snap		= 32;
static int floatposgrid_x			= 5;
static int floatposgrid_y			= 5;
static const char *toggle_float_pos = "50% 50% 90% 90%"; 

static const unsigned int gappih	= 10;
static const unsigned int gappiv	= 10;
static const unsigned int gappoh	= 10;
static const unsigned int gappov	= 10;
static int smartgaps				= 1;

static const int showbar			= 1;
static const int topbar				= 1;
static const int user_bh			= 10;

#define ICONSIZE (bh - 10)
#define ICONSPACING 10

static const char *fonts[]			= { "Adwaita Sans:size=12",
										"JetBrainsMono Nerd Font:style=ExtraBold:size=10" };
static const char dmenufont[]		= "Adwaita Sans:size=12";

static const char col_gray1[]		= "#1e222a";
static const char col_gray2[]		= "#545862";
static const char col_gray3[]		= "#abb2bf";
static const char col_gray4[]		= "#c8ccd4";
static const char col_yellow[]		= "#e5c07b";
static const char col_blue[]		= "#61afef";
static const char col_sel[]			= "#000090";
static const char *colors[][3]		= {
	/*					fg			bg			border   */
	[SchemeNorm]	= { col_gray3,	col_gray1,	col_gray2 },
	[SchemeSel]		= { col_gray4,	col_sel,	col_blue },
	[SchemeLtSym]	= { col_yellow,	col_gray1,	NULL },
};

static const char *const autostart[] = {
	"/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1", NULL,
	"nitrogen", "--restore", NULL,
	"dunst", NULL,
	"picom", "-b", NULL,
	"slstatus", NULL,
	NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

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
	{ "TTT",	bstack },
	{ "HHH",	gaplessgrid },
	{ NULL,		NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,							KEY,	view,		{.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,				KEY,	toggleview,	{.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,					KEY,	tag,		{.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask,		KEY,	toggletag,	{.ui = 1 << TAG} },

/* commands */
static const char *termcmd[]	= { "ghostty", NULL };
static const char *dmenucmd[]	= { "dmenu_run", "-p", "Run: ", "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_sel, "-sf", col_gray4, NULL };
static const char *roficmd[]	= { "rofi", "-show", "drun", NULL };
static const char *firefoxcmd[]	= { "firefox", NULL };

static const char *volmutecmd[]	= { "volume", "--toggle", NULL };
static const char *voldowncmd[]	= { "volume", "--dec", NULL };
static const char *volupcmd[]	= { "volume", "--inc", NULL };
static const char *micmutecmd[]	= { "volume", "--toggle-mic", NULL };
static const char *bldowncmd[]	= { "brightness", "--dec", NULL };
static const char *blupcmd[]	= { "brightness", "--inc", NULL };

static const char *sptermcmd[]	= { "t", "ghostty", "--x11-instance-name=spterm", "--title=Scratchpad", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_space,  spawn,          {.v = roficmd } },
	{ MODKEY,                       XK_w,      spawn,          {.v = firefoxcmd } },

	{ 0,							XK_F1,	   spawn,		   {.v = volmutecmd } },
	{ 0,							XK_F2,	   spawn,		   {.v = voldowncmd } },
	{ 0,							XK_F3,	   spawn,		   {.v = volupcmd } },
	{ 0,							XK_F4,	   spawn,		   {.v = micmutecmd } },
	{ 0,							XK_F5,	   spawn,		   {.v = bldowncmd } },
	{ 0,							XK_F6,	   spawn,		   {.v = blupcmd } },

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
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_b,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_grave,  togglescratch,  {.v = sptermcmd} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
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
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

