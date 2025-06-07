/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx	= 3;
static const unsigned int snap		= 32;

static int floatposgrid_x			= 5;
static int floatposgrid_y			= 5;
static const char *toggle_float_pos	= "50% 50% 80% 80%";

static const unsigned int gappih	= 10;
static const unsigned int gappiv	= 10;
static const unsigned int gappoh	= 10;
static const unsigned int gappov	= 10;
static int smartgaps				= 1;

static const int showbar			= 1;
static const int topbar				= 1;
static const int user_bh			= 6;

#define ICONSIZE (bh - 10)
#define ICONSPACING 10

static const char *fonts[]			= { "Inter:size=11",
										"Hack Nerd Font:style=Bold:size=9" };
static const char dmenufont[]		= "Inter:size=11";

static char normfgcolor[]			= "#bbbbbb";
static char normbgcolor[]			= "#222222";
static char normbordercolor[]		= "#444444";
static char normfloatcolor[]		= "#444444";

static char selfgcolor[]			= "#eeeeee";
static char selbgcolor[]			= "#005577";
static char selbordercolor[]		= "#005577";
static char selfloatcolor[]			= "#005577";

static char statusfgcolor[]			= "#eeeeee";
static char statusbgcolor[]			= "#222222";

static char ltsymfgcolor[]			= "#dddd00";
static char ltsymbgcolor[]			= "#222222";

static char tagsemptyfgcolor[]		= "#444444";
static char tagsemptybgcolor[]		= "#222222";
static char tagsoccfgcolor[]		= "#bbbbbb";
static char tagsoccbgcolor[]		= "#222222";
static char tagsselfgcolor[]		= "#eeeeee";
static char tagsselbgcolor[]		= "#005577";

static char *colors[][4]			= {
	[SchemeNorm]		= { normfgcolor,		normbgcolor,		normbordercolor,	normfloatcolor },
	[SchemeSel]			= { selfgcolor,			selbgcolor,			selbordercolor,		selfloatcolor },
	[SchemeStatus]		= { statusfgcolor,		statusbgcolor,		NULL,				NULL },
	[SchemeLtSym]		= { ltsymfgcolor,		ltsymbgcolor,		NULL,				NULL },
	[SchemeTagsEmpty]	= { tagsemptyfgcolor,	tagsemptybgcolor,	NULL,				NULL },
	[SchemeTagsOcc]		= { tagsoccfgcolor,		tagsoccbgcolor,		NULL,				NULL },
	[SchemeTagsSel]		= { tagsselfgcolor,		tagsselbgcolor,		NULL,				NULL },
};

static const unsigned int baralpha			= 0xc0;
static const unsigned int borderalpha		= OPAQUE;

static const unsigned int alphas[][4]      = {
	[SchemeNorm]		= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeSel]			= { OPAQUE, OPAQUE,   borderalpha, borderalpha },
	[SchemeStatus]		= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeLtSym]		= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeTagsEmpty]	= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeTagsOcc]		= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeTagsSel]		= { OPAQUE, baralpha, borderalpha, borderalpha },
};

static const char *const autostart[] 		= {
	"/usr/lib/xfce-polkit/xfce-polkit",  NULL,
	"dunst", NULL,
	"nitrogen", "--restore", NULL,
	"picom", "-b", NULL,
	"slstatus", NULL,
	NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8" };

static const unsigned int ulinepad		= 5;
static const unsigned int ulinestroke	= 2;
static const unsigned int ulinevoffset	= 0;
static const int ulineall				= 0;

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	{ .class = "Lxappearance", .isfloating = 1, .iscentered = 1 },
	{ .class = "firefox", .tags = 1 << 1 },
	{ .class = "Thunar", .tags = 1 << 2 },
	{ .instance = "spterm", .scratchkey = 't', .isfloating = 1, .floatpos = "50% 50% 80% 80%" }
};

/* layout(s) */
static const float mfact		= 0.50;
static const int nmaster		= 1; 
static const int resizehints	= 0; 
static const int lockfullscreen	= 1;
static const int attachmode		= 2;

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
static const char *termcmd[]	= { "ghostty", "--title=Terminal", NULL };
static const char *dmenucmd[]	= { "dmenu_run", "-p", "Run: ", "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *webcmd[]		= { "firefox", NULL };
static const char *fmcmd[]		= { "thunar", NULL };

static const char *sptermcmd[]	= { "t", "ghostty", "--x11-instance-name=spterm", "--title=Scratchpad", NULL};

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_space,  spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_w,      spawn,          {.v = webcmd } },
	{ MODKEY,                       XK_e,      spawn,          {.v = fmcmd } },
	{ MODKEY,                       XK_grave,  togglescratch,  {.v = sptermcmd } },
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
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ShiftMask,             XK_r,      quit,           {1} }, 
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,						XK_Down,   cyclelayout,    {.i = -1 } },
	{ MODKEY,						XK_Up,     cyclelayout,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_x,      xrdb,           {.v = NULL } },
	{ 0,                            XK_F10,    togglebar,      {0} },
	{ 0,                            XK_F11,    togglefullscr,  {0} },
	{ 0,                            XK_F12,    togglefloating, {0} },
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

