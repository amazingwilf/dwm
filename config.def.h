/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx		= 4;   /* border pixel of windows */
static const unsigned int snap			= 32;  /* snap pixel */
static const int swallowfloating		= 0;   /* 1 means swallow floating windows by default */
static const unsigned int gappih		= 20;  /* horiz inner gap between windows */
static const unsigned int gappiv		= 20;  /* vert inner gap between windows */
static const unsigned int gappoh		= 20;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov		= 20;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact			= 1;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int showbar				= 1;   /* 0 means no bar */
static const int topbar					= 1;   /* 0 means bottom bar */
static const int bar_height				= 44;  /* 0 means derive from font, >= 1 explicit height */
static const int vertpad				= 20;  /* vertical padding of bar */
static const unsigned int colorfultag	= 1;  /* 0 means use SchemeSel for selected tag */
static const int sidepad				= 20;  /* horizontal padding of bar */
#define ICONSIZE 20								/* icon size */
#define ICONSPACING 5  							/* space between icon and title */
static const int focusonwheel			= 0;
static int floatposgrid_x				= 5;  /* float grid columns */
static int floatposgrid_y				= 5;  /* float grid rows */
static const int statusmon				= 'A';
static const char buttonbar[]			= "";
static const unsigned int ulinepad		= 5;         /* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;     /* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;     /* how far above the bottom of the bar the line should appear */
static const int ulineall = 0;                  /* 1 to show underline on all tags, 0 for just the active ones */

/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype				= INDICATOR_NONE;
static int tiledindicatortype			= INDICATOR_NONE;
static int floatindicatortype			= INDICATOR_TOP_LEFT_SQUARE;
static const char *fonts[]				= { "Merge One:size=17",
											"JetBrainsMono Nerd Font:size=18" };
static const char dmenufont[]			= "Merge One:size=15";

static char c000000[]					= "#000000"; // placeholder value

static char normfgcolor[]				= "#bbbbbb";
static char normbgcolor[]				= "#222222";
static char normbordercolor[]			= "#444444";
static char normfloatcolor[]			= "#db8fd9";

static char selfgcolor[]				= "#eeeeee";
static char selbgcolor[]				= "#005577";
static char selbordercolor[]			= "#005577";
static char selfloatcolor[]				= "#005577";

static char titlenormfgcolor[]			= "#bbbbbb";
static char titlenormbgcolor[]			= "#222222";
static char titlenormbordercolor[]		= "#444444";
static char titlenormfloatcolor[]		= "#db8fd9";

static char titleselfgcolor[]			= "#eeeeee";
static char titleselbgcolor[]			= "#005577";
static char titleselbordercolor[]		= "#005577";
static char titleselfloatcolor[]		= "#005577";

static char tagsnormfgcolor[]			= "#bbbbbb";
static char tagsnormbgcolor[]			= "#222222";
static char tagsnormbordercolor[]		= "#444444";
static char tagsnormfloatcolor[]		= "#db8fd9";

static char tagsselfgcolor[]			= "#eeeeee";
static char tagsselbgcolor[]			= "#005577";
static char tagsselbordercolor[]		= "#005577";
static char tagsselfloatcolor[]			= "#005577";

static char hidnormfgcolor[]			= "#005577";
static char hidselfgcolor[]				= "#227799";
static char hidnormbgcolor[]			= "#222222";
static char hidselbgcolor[]				= "#222222";

static char urgfgcolor[]				= "#bbbbbb";
static char urgbgcolor[]				= "#222222";
static char urgbordercolor[]			= "#ff0000";
static char urgfloatcolor[]				= "#db8fd9";

static char scratchnormfgcolor[]		= "#bbbbbb";
static char scratchnormbgcolor[]		= "#222222";
static char scratchnormbordercolor[]	= "#444444";
static char scratchnormfloatcolor[]		= "#444444";

static char scratchselfgcolor[]			= "#eeeeee";
static char scratchselbgcolor[]			= "#222222";
static char scratchselbordercolor[]		= "#ff0044";
static char scratchselfloatcolor[]		= "#ff0044";

static char stickyfgcolor[]				= "#bbbbbb";
static char stickybgcolor[]				= "#222222";
static char stickybordercolor[]			= "#88ff00";
static char stickyfloatcolor[]			= "#88ff00";

static char ltsymbolfgcolor[]			= "#ffff00";
static char ltsymbolbgcolor[]			= "#222222";
static char ltsymbolbordercolor[]		= "#000000";
static char ltsymbolfloatcolor[]		= "#000000";

static char stbuttonfgcolor[]			= "#eeeeee";
static char stbuttonbgcolor[]			= "#ff0000";
static char stbuttonbordercolor[]		= "#000000";
static char stbuttonfloatcolor[]		= "#000000";

static char tag1fg[]					= "#ff8000";
static char tag2fg[]					= "#ffff00";
static char tag3fg[]					= "#80ff00";
static char tag4fg[]					= "#00ff00";
static char tag5fg[]					= "#00ff80";
static char tag6fg[]					= "#00ffff";
static char tag7fg[]					= "#0080ff";
static char tag8fg[]					= "#ff00ff";
static char tag9fg[]					= "#ff0080";

static const unsigned int baralpha = 0xe0;
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][3] = {
	/*						fg		bg		  border     */
	[SchemeNorm]		= { OPAQUE, baralpha, borderalpha },
	[SchemeSel]			= { OPAQUE, baralpha, borderalpha },
	[SchemeTitleNorm]	= { OPAQUE, baralpha, borderalpha },
	[SchemeTitleSel]	= { OPAQUE, baralpha, borderalpha },
	[SchemeTagsNorm]	= { OPAQUE, baralpha, borderalpha },
	[SchemeTagsSel]		= { OPAQUE, baralpha, borderalpha },
	[SchemeTagNorm01]	= { OPAQUE, baralpha, borderalpha },
	[SchemeTagNorm02]	= { OPAQUE, baralpha, borderalpha },
	[SchemeTagNorm03]	= { OPAQUE, baralpha, borderalpha },
	[SchemeTagNorm04]	= { OPAQUE, baralpha, borderalpha },
	[SchemeTagNorm05]	= { OPAQUE, baralpha, borderalpha },
	[SchemeTagNorm06]	= { OPAQUE, baralpha, borderalpha },
	[SchemeTagNorm07]	= { OPAQUE, baralpha, borderalpha },
	[SchemeTagNorm08]	= { OPAQUE, baralpha, borderalpha },
	[SchemeTagNorm09]	= { OPAQUE, baralpha, borderalpha },
	[SchemeTagSel01]	= { OPAQUE, baralpha, borderalpha },
	[SchemeTagSel02]	= { OPAQUE, baralpha, borderalpha },
	[SchemeTagSel03]	= { OPAQUE, baralpha, borderalpha },
	[SchemeTagSel04]	= { OPAQUE, baralpha, borderalpha },
	[SchemeTagSel05]	= { OPAQUE, baralpha, borderalpha },
	[SchemeTagSel06]	= { OPAQUE, baralpha, borderalpha },
	[SchemeTagSel07]	= { OPAQUE, baralpha, borderalpha },
	[SchemeTagSel08]	= { OPAQUE, baralpha, borderalpha },
	[SchemeTagSel09]	= { OPAQUE, baralpha, borderalpha },
	[SchemeHidNorm]		= { OPAQUE, baralpha, borderalpha },
	[SchemeHidSel]		= { OPAQUE, baralpha, borderalpha },
	[SchemeUrg]			= { OPAQUE, baralpha, borderalpha },
	[SchemeScratchNorm]	= { OPAQUE, baralpha, borderalpha },
	[SchemeScratchSel]	= { OPAQUE, baralpha, borderalpha },
	[SchemeSticky]		= { OPAQUE, baralpha, borderalpha },
	[SchemeLtSymbol]	= { OPAQUE, baralpha, borderalpha },
	[SchemeStButton]	= { OPAQUE, baralpha, borderalpha },
};


static const int normtagschemes[] = { SchemeTagNorm01, SchemeTagNorm02, SchemeTagNorm03,
									SchemeTagNorm04, SchemeTagNorm05, SchemeTagNorm06,
									SchemeTagNorm07, SchemeTagNorm08, SchemeTagNorm09 };

static const int seltagschemes[] = { SchemeTagSel01, SchemeTagSel02, SchemeTagSel03,
                    				SchemeTagSel04, SchemeTagSel05, SchemeTagSel06,
                        			SchemeTagSel07, SchemeTagSel08, SchemeTagSel09 };

static char *colors[][ColCount] = {
	/* 						fg					bg					border					float */
	[SchemeNorm]		= { normfgcolor,		normbgcolor,		normbordercolor,		normfloatcolor },
	[SchemeSel]			= { selfgcolor,			selbgcolor,			selbordercolor,			selfloatcolor },
	[SchemeTitleNorm]	= { titlenormfgcolor,	titlenormbgcolor,	titlenormbordercolor,	titlenormfloatcolor },
	[SchemeTitleSel]	= { titleselfgcolor,	titleselbgcolor,	titleselbordercolor,	titleselfloatcolor },
	[SchemeTagsNorm]	= { tagsnormfgcolor,	tagsnormbgcolor,	tagsnormbordercolor,	tagsnormfloatcolor },
	[SchemeTagsSel]		= { tagsselfgcolor,		tagsselbgcolor,		tagsselbordercolor,		tagsselfloatcolor },
	[SchemeTagNorm01]	= { tag1fg,				tagsnormbgcolor,	c000000,				c000000 },
	[SchemeTagNorm02]	= { tag2fg,				tagsnormbgcolor,	c000000,				c000000 },
	[SchemeTagNorm03]	= { tag3fg,				tagsnormbgcolor,	c000000,				c000000 },
	[SchemeTagNorm04]	= { tag4fg,				tagsnormbgcolor,	c000000,				c000000 },
	[SchemeTagNorm05]	= { tag5fg,				tagsnormbgcolor,	c000000,				c000000 },
	[SchemeTagNorm06]	= { tag6fg,				tagsnormbgcolor,	c000000,				c000000 },
	[SchemeTagNorm07]	= { tag7fg,				tagsnormbgcolor,	c000000,				c000000 },
	[SchemeTagNorm08]	= { tag8fg,				tagsnormbgcolor,	c000000,				c000000 },
	[SchemeTagNorm09]	= { tag9fg,				tagsnormbgcolor,	c000000,				c000000 },
	[SchemeTagSel01]	= { tag1fg,				tagsselbgcolor,		c000000,				c000000 },
	[SchemeTagSel02]	= { tag2fg,				tagsselbgcolor,		c000000,				c000000 },
	[SchemeTagSel03]	= { tag3fg,				tagsselbgcolor,		c000000,				c000000 },
	[SchemeTagSel04]	= { tag4fg,				tagsselbgcolor,		c000000,				c000000 },
	[SchemeTagSel05]	= { tag5fg,				tagsselbgcolor,		c000000,				c000000 },
	[SchemeTagSel06]	= { tag6fg,				tagsselbgcolor,		c000000,				c000000 },
	[SchemeTagSel07]	= { tag7fg,				tagsselbgcolor,		c000000,				c000000 },
	[SchemeTagSel08]	= { tag8fg,				tagsselbgcolor,		c000000,				c000000 },
	[SchemeTagSel09]	= { tag9fg,				tagsselbgcolor,		c000000,				c000000 },
	[SchemeHidNorm]		= { hidnormfgcolor,		hidnormbgcolor,		c000000,				c000000 },
	[SchemeHidSel]		= { hidselfgcolor,		hidselbgcolor,		c000000,				c000000 },
	[SchemeUrg]			= { urgfgcolor,			urgbgcolor,			urgbordercolor,			urgfloatcolor },
	[SchemeScratchNorm]	= { scratchnormfgcolor,	scratchnormbgcolor,	scratchnormbordercolor,	scratchnormfloatcolor },
	[SchemeScratchSel]	= { scratchselfgcolor,	scratchselbgcolor,	scratchselbordercolor,	scratchselfloatcolor },
	[SchemeSticky]		= { stickyfgcolor,		stickybgcolor,		stickybordercolor,		stickyfloatcolor },
	[SchemeLtSymbol]	= { ltsymbolfgcolor,	ltsymbolbgcolor,	ltsymbolbordercolor,	ltsymbolfloatcolor },
	[SchemeStButton]	= { stbuttonfgcolor,	stbuttonbgcolor,	stbuttonbordercolor,	stbuttonfloatcolor },
};

static const char *const autostart[] = {
	"/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1", NULL,
	"nitrogen", "--restore", NULL,
	"picom", NULL,
	NULL /* terminate */
};


/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */
/* static char *tagicons[][NUMTAGS] = { */
/* 	[DEFAULT_TAGS]        = { "1", "2", "3", "4", "5", "6", "7", "8", "9" }, */
/* 	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" }, */
/* 	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" }, */
/* }; */


 static char *tagicons[][1] = {
 	[DEFAULT_TAGS] = { "⭘" },
	[ALTERNATIVE_TAGS]	= { "⭘" },
	[ALT_TAGS_DECORATION]	= { "ﱣ" }
 };

/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	RULE(.class = "Gimp", .tags = 1 << 4)
	RULE(.class = "Firefox", .tags = 1 << 7)
	RULE(.class = "Nitrogen", .isfloating = 1, .floatpos = "50% 50%")
	RULE(.class = "Lxappearance", .isfloating = 1, .floatpos = "50% 50%")
	RULE(.class = "Pcmanfm", .isfloating = 1, .floatpos = "50% 50%")
	RULE(.title = "spterm", .isfloating = 1, .floatpos = "50% 50% 70% 70%", .scratchkey = 't')
};

/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
	/* monitor   bar    alignment         widthfunc                drawfunc                clickfunc                name */
	{ -1,        0,     BAR_ALIGN_LEFT,   width_stbutton,          draw_stbutton,          click_stbutton,          "statusbutton" },
	{ -1,        0,     BAR_ALIGN_LEFT,   width_tags,              draw_tags,              click_tags,              "tags" },
	{ -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,          draw_ltsymbol,          click_ltsymbol,          "layout" },
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_status2d,          draw_status2d,          click_statuscmd,         "status2d" },
	{ -1,        0,     BAR_ALIGN_NONE,   width_awesomebar,        draw_awesomebar,        click_awesomebar,        "awesomebar" },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */



static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "TTT",      bstack },
	{ "|M|",      centeredmaster },
	{ "HHH",      grid },
	{ ":::",      gaplessgrid },
	{ NULL,       NULL },
};

/* key definitions */
#include <X11/XF86keysym.h>
#define Mod Mod4Mask
#define Alt Mod1Mask
#define Sft ShiftMask
#define Ctl ControlMask

#define TAGKEYS(KEY,TAG) \
	{ Mod,			KEY,	view,		{.ui = 1 << TAG} }, \
	{ Mod|Ctl,		KEY,	toggleview,	{.ui = 1 << TAG} }, \
	{ Mod|Sft,		KEY,	tag,		{.ui = 1 << TAG} }, \
	{ Mod|Ctl|Sft,	KEY,	toggletag,	{.ui = 1 << TAG} },



/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenu[]		= { "dmenu_run", "-h", "48", NULL };
static const char *fileman[]	= { "pcmanfm", NULL };
static const char *launcher[]	= { "launcher", NULL };
static const char *term[]		= { "st", NULL };
static const char *web[]		= { "firefox", NULL };

static const char *volup[]		= { "volume", "--inc", NULL };
static const char *voldown[]	= { "volume", "--dec", NULL };
static const char *volmute[]	= { "volume", "--toggle", NULL };

/*First arg only serves to match against key in rules*/
static const char *scratchterm[] = {"t", "st", "-t", "spterm", NULL};

static void scratchtermex(const Arg *arg) {
	togglescratch(&((Arg) { .v = scratchterm }));
}

/* This defines the name of the executable that handles the bar (used for signalling purposes) */
#define STATUSBAR "dwmblocks"

static Key keys[] = {
	/* modifier		key					function			argument */
	{ Mod,			XK_Return,			spawn,				{.v = term } },
	{ Mod,			XK_space,			spawn,				{.v = launcher } },
	{ Mod,			XK_d,				spawn,				{.v = dmenu } },
	{ Mod,			XK_f,				spawn,				{.v = fileman } },
	{ Mod,			XK_w,				spawn,				{.v = web} },

	{ 0,			XF86XK_AudioMute,		spawn,				{.v = volmute } },
	{ 0,			XF86XK_AudioLowerVolume, spawn,				{.v = voldown } },
	{ 0,			XF86XK_AudioRaiseVolume, spawn,				{.v = volup } },

	{ Mod,			XK_grave,			togglescratch,		{.v = scratchterm } },
	{ Mod|Sft,		XK_grave,			removescratch,		{.v = scratchterm } },
	{ Mod|Ctl,		XK_grave,			setscratch,			{.v = scratchterm } },

	{ Mod,			XK_Tab,				focusstack,			{.i = +1 } },
	{ Mod|Ctl,		XK_Tab,				focusstack,			{.i = -1 } },

	{ Mod,			XK_h,				focusdir,			{.i = 0 } }, // left
	{ Mod,			XK_l,				focusdir,			{.i = 1 } }, // right
	{ Mod,			XK_k,				focusdir,			{.i = 2 } }, // up
	{ Mod,			XK_j,				focusdir,			{.i = 3 } }, // down

	{ Mod|Alt,		XK_h,				setmfact,			{.f = -0.05} },
	{ Mod|Alt,		XK_l,				setmfact,			{.f = +0.05} },
	{ Mod|Alt,		XK_k,				setcfact,			{.f = +0.25} },
	{ Mod|Alt,		XK_j,				setcfact,			{.f = -0.25} },
	{ Mod|Alt,		XK_o,				setcfact,			{0} },

	{ Mod|Ctl,		XK_h,				placedir,			{.i = 0 } }, // left
	{ Mod|Ctl,		XK_l,				placedir,			{.i = 1 } }, // right
	{ Mod|Ctl,		XK_k,				placedir,			{.i = 2 } }, // up
	{ Mod|Ctl,		XK_j,				placedir,			{.i = 3 } }, // down

	{ Ctl|Alt,		XK_i,				incnmaster,			{.i = +1 } },
	{ Ctl|Alt,		XK_d,				incnmaster,			{.i = -1 } },

	{ Mod,			XK_Left,			shiftview,			{ .i = -1 } },
	{ Mod,			XK_Right,			shiftview,			{ .i = +1 } },
	{ Ctl|Alt,		XK_Left,			cyclelayout,		{.i = -1 } },
	{ Ctl|Alt,		XK_Right,			cyclelayout,		{.i = +1 } },

	{ Mod,			XK_Up,				incrgaps,			{.i = +1 } },
	{ Mod,			XK_Down,			incrgaps,			{.i = -1 } },
	{ Mod,			XK_Insert,			togglegaps,			{0} },
	{ Mod,			XK_Home,			defaultgaps,		{0} },

	{ Mod,			XK_q,				killclient,			{0} },
	{ Mod|Sft,		XK_q,				quit,				{0} },
	{ Mod|Sft,		XK_r,				quit,				{1} },

	{ Ctl|Alt,		XK_t,				setlayout,			{.v = &layouts[0]} },
	{ Ctl|Alt,		XK_f,				setlayout,			{.v = &layouts[1]} },
	{ Ctl|Alt,		XK_m,				setlayout,			{.v = &layouts[2]} },
	{ Ctl|Alt,		XK_b,				setlayout,			{.v = &layouts[3]} },
	{ Ctl|Alt,		XK_c,				setlayout,			{.v = &layouts[4]} },
	{ Ctl|Alt,		XK_g,				setlayout,			{.v = &layouts[5]} },
	{ Ctl|Alt,		XK_h,				setlayout,			{.v = &layouts[6]} },
	{ Ctl|Alt,		XK_m,				setlayout,			{.v = &layouts[7]} },

	{ Mod|Sft,		XK_space,			togglefloating,		{0} },
	{ Mod|Sft,		XK_b,				togglebar,			{0} },
	{ Mod|Sft,		XK_f,				togglefullscreen,	{0} },
	{ Mod|Sft,		XK_n,				togglecolorfultag,	{0} },
	{ Mod|Sft,		XK_s,				togglesticky,		{0} },
	{ Mod|Sft,		XK_z,				showhideclient,		{0} },

	{ Mod,			XK_0,				view,				{.ui = ~0 } },
	{ Mod|Sft,		XK_0,				tag,				{.ui = ~0 } },

	TAGKEYS(XK_1, 0)
	TAGKEYS(XK_2, 1)
	TAGKEYS(XK_3, 2)
	TAGKEYS(XK_4, 3)
	TAGKEYS(XK_5, 4)
	TAGKEYS(XK_6, 5)
	TAGKEYS(XK_7, 6)
	TAGKEYS(XK_8, 7)
	TAGKEYS(XK_9, 8)
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkButton,            0,                   Button1,        spawn,          {.v = dmenu } },
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,                   Button3,        showhideclient, {0} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                   Button1,        sigstatusbar,   {.i = 1 } },
	{ ClkStatusText,        0,                   Button2,        sigstatusbar,   {.i = 2 } },
	{ ClkStatusText,        0,                   Button3,        sigstatusbar,   {.i = 3 } },
	/* placemouse options, choose which feels more natural:
	 *    0 - tiled position is relative to mouse cursor
	 *    1 - tiled postiion is relative to window center
	 *    2 - mouse pointer warps to window center
	 *
	 * The moveorplace uses movemouse or placemouse depending on the floating state
	 * of the selected client. Set up individual keybindings for the two if you want
	 * to control these separately (i.e. to retain the feature to move a tiled window
	 * into a floating position).
	 */
	{ ClkClientWin,		Mod,		Button1,        moveorplace,    {.i = 1} },
	{ ClkClientWin,		Mod,		Button2,        togglefloating, {0} },
	{ ClkClientWin,		Mod,		Button3,        resizemouse,    {0} },
	{ ClkClientWin,		Mod|Sft,	Button3,        dragcfact,      {0} },
	{ ClkClientWin,		Mod|Sft,	Button1,        dragmfact,      {0} },
	{ ClkTagBar,		0,			Button1,        view,           {0} },
	{ ClkTagBar,		0,			Button3,        toggleview,     {0} },
	{ ClkTagBar,		Mod,		Button1,        tag,            {0} },
	{ ClkTagBar,		Mod,		Button3,        toggletag,      {0} },
};

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signame> [<type> <value>]"` */
static Signal signals[] = {
	/* signum                    function */
	{ "cyclelayout",             cyclelayout },
	{ "defaultgaps",             defaultgaps },
	{ "focusdir",				 focusdir },
	{ "focusmon",                focusmon },
	{ "focusstack",              focusstack },
	{ "incnmaster",              incnmaster },
	{ "incrgaps",                incrgaps },
	{ "incrigaps",               incrigaps },
	{ "incrihgaps",              incrihgaps },
	{ "incrivgaps",              incrivgaps },
	{ "incrogaps",               incrogaps },
	{ "incrohgaps",              incrohgaps },
	{ "incrovgaps",              incrovgaps },
	{ "killclient",              killclient },
	{ "placedir",                placedir },
	{ "quit",                    quit },
	{ "scratchtermex",           scratchtermex },
	{ "setcfact",                setcfact },
	{ "setgaps",                 setgapsex },
	{ "setlayout",               setlayout },
	{ "setlayoutex",             setlayoutex },
	{ "setmfact",                setmfact },
	{ "shiftview",               shiftview },
	{ "tag",                     tag },
	{ "tagall",                  tagallex },
	{ "tagex",                   tagex },
	{ "tagmon",                  tagmon },
	{ "togglebar",               togglebar },
	{ "togglefloating",          togglefloating },
	{ "togglefullscreen",        togglefullscreen },
	{ "togglegaps",              togglegaps },
	{ "togglesticky",            togglesticky },
	{ "toggletag",               toggletag },
	{ "toggletagex",             toggletagex },
	{ "toggleview",              toggleview },
	{ "toggleviewex",            toggleviewex },
	{ "view",                    view },
	{ "viewall",                 viewallex },
	{ "viewex",                  viewex },
	{ "xrdb",                    xrdb },
	{ "zoom",                    zoom },
};


