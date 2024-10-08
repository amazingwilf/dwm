/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx	= 3;
static const unsigned int snap		= 32;
static const unsigned int gappih	= 15;
static const unsigned int gappiv	= 15;
static const unsigned int gappoh	= 15;
static const unsigned int gappov	= 15;
static int smartgaps				= 0;
static const int showbar			= 1;
static const int topbar				= 1;
static const int user_bh			= 8;
static const char buttonbar[]		= "  ";
#define ICONSIZE 					(bh - 16)
#define ICONSPACING 				10
static const char *fonts[]			= { "Noto Sans:style=Medium:size=14",
										"JetBrainsMono Nerd Font:size=24",
										"JetBrainsMono Nerd font:style=ExtraBold:size=12" };

static char normfgcolor[]				= "#cdcdcd";
static char normbgcolor[]				= "#1e2127";
static char normbordercolor[]			= "#5c6370";
static char normfloatcolor[]			= "#5c6370";

static char selfgcolor[]				= "#ffffff";
static char selbgcolor[]				= "#1e2127";
static char selbordercolor[]			= "#61afef";
static char selfloatcolor[]				= "#c678dd";

static char stickyfgcolor[]				= "#cdcdcd";
static char stickybgcolor[]				= "#1e2127";
static char stickybordercolor[]			= "#d19a55";
static char stickyfloatcolor[]			= "#d19a55";

static char scratchnormfgcolor[]		= "#cdcdcd";
static char scratchnormbgcolor[]		= "#1e2127";
static char scratchnormbordercolor[]	= "#5c6370";
static char scratchnormfloatcolor[]		= "#5c6370";

static char scratchselfgcolor[]			= "#ffffff";
static char scratchselbgcolor[]			= "#1e2127";
static char scratchselbordercolor[]		= "#56b6c2";
static char scratchselfloatcolor[]		= "#56b6c2";
	
static char stbuttonfgcolor[]			= "#98c379";
static char stbuttonbgcolor[]			= "#1e2127";
static char stbuttonbordercolor[]		= "#000000";
static char stbuttonfloatcolor[]		= "#000000";

static char ltsymbolfgcolor[]			= "#d19a55";
static char ltsymbolbgcolor[]			= "#1e2127";
static char ltsymbolbordercolor[]		= "#000000";
static char ltsymbolfloatcolor[]		= "#000000";

static char tagsemptyfgcolor[]			= "#5c6370";
static char tagsemptybgcolor[]			= "#1e2127";
static char tagsemptybordercolor[]		= "#000000";
static char tagsemptyfloatcolor[]		= "#000000";

static char tagsoccfgcolor[]			= "#cdcdcd";
static char tagsoccbgcolor[]			= "#1e2127";
static char tagsoccbordercolor[]		= "#000000";
static char tagsoccfloatcolor[]			= "#000000";

static char tagsselfgcolor[]			= "#ffffff";
static char tagsselbgcolor[]			= "#1e2127";
static char tagsselbordercolor[]		= "#000000";
static char tagsselfloatcolor[]			= "#000000";

#include "termcolors.h"

static char *colors[][4]			= {
	/*						fg					bg					border					float		*/
	[SchemeNorm] 		= { normfgcolor,		normbgcolor, 		normbordercolor, 		normfloatcolor	},
	[SchemeSel]			= { selfgcolor,			selbgcolor, 		selbordercolor, 		selfloatcolor	},
	[SchemeSticky] 		= { stickyfgcolor,		stickybgcolor, 		stickybordercolor, 		stickyfloatcolor	},
	[SchemeScratchNorm]	= { scratchnormfgcolor,	scratchnormbgcolor,	scratchnormbordercolor, scratchnormfloatcolor	},
	[SchemeScratchSel]	= { scratchselfgcolor,	scratchselbgcolor, 	scratchselbordercolor, 	scratchselfloatcolor	},
	[SchemeStButton]	= { stbuttonfgcolor,	stbuttonbgcolor, 	stbuttonbordercolor, 	stbuttonfloatcolor	},
	[SchemeLtSymbol]	= { ltsymbolfgcolor,	ltsymbolbgcolor, 	ltsymbolbordercolor, 	ltsymbolfloatcolor	},
	[SchemeTagsEmpty] 	= { tagsemptyfgcolor,	tagsemptybgcolor, 	tagsemptybordercolor, 	tagsemptyfloatcolor	},
	[SchemeTagsOcc] 	= { tagsoccfgcolor,		tagsoccbgcolor, 	tagsoccbordercolor, 	tagsoccfloatcolor	},
	[SchemeTagsSel] 	= { tagsselfgcolor,		tagsselbgcolor, 	tagsselbordercolor, 	tagsselfloatcolor	},
};

static const unsigned int baralpha		= 0xb2;
static const unsigned int borderalpha 	= OPAQUE;
static const unsigned int alphas[][4]	= {
	/*			fg	bg	border	float*/
	[SchemeNorm] 		= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeSel]			= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeSticky] 		= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeScratchNorm]	= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeScratchSel]	= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeStButton]	= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeLtSymbol]	= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeTagsEmpty] 	= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeTagsOcc] 	= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeTagsSel] 	= { OPAQUE, baralpha, borderalpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8" };

static const unsigned int ulinepad	= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	{ .class = "Lxappearance", .isfloating = 1, .floatpos = "50% 50% -1w -1h" },
	{ .class = "Alacritty", .tags = 1 << 0, .isterminal = 1 },
	{ .class = "firefox", .tags = 1 << 1 },
	{ .class = "Thunar", .tags = 1 << 2 },
	{ .title = "Event Tester", .noswallow = 1 },
	{ .class = "spterm", .scratchkey = 't', .isfloating = 1, .floatpos = "50% 50% 80% 80%" },
};

/* layout(s) */
static const float mfact			= 0.50; 
static const int nmaster			= 1;
static const int resizehints 		= 0;
static const int lockfullscreen 	= 1;
static int floatposgrid_x			= 5;
static int floatposgrid_y			= 5;
static const int swallowfloating	= 0;
static const char *toggle_float_pos	= "50% 50% 80% 80%";

#define FORCE_VSPLIT 1	
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol	arrange function */
	{ "[]=",	tile },
	{ "><>",	NULL },
	{ "[M]",	monocle },
	{ "[@]",	spiral },
	{ "[\\]",	dwindle },
	{ "H[]",	deck },
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
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,						KEY,	view,		{.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,			KEY,	toggleview,	{.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,				KEY,	tag,		{.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask,	KEY,	toggletag,	{.ui = 1 << TAG} },

/* commands */
static const char *termcmd[]		= { "alacritty", NULL };
static const char *roficmd[]		= { "rofi", "-show", "drun", NULL };
static const char *webcmd[]			= { "firefox", NULL };
static const char *fmcmd[]			= { "thunar", NULL };
static const char *rangercmd[]		= { "alacritty", "--class", "ranger,ranger", "-e", "ranger", NULL };

static const char *blup[]			= { "brightness", "--inc", NULL };
static const char *bldown[]			= { "brightness", "--dec", NULL };
static const char *volup[]			= { "volume", "--inc", NULL };
static const char *voldown[]		= { "volume", "--dec", NULL };
static const char *volmute[]		= { "volume", "--toggle", NULL };
static const char *micmute[]		= { "volume", "--toggle-mic", NULL };

static const char *spterm[]			= { "t", "alacritty", "--class", "spterm,spterm", NULL };

#include <X11/XF86keysym.h>
static const Key keys[] = {
	/* modifier				key							function			argument */
	{ MODKEY,				XK_Return, 					spawn,				{.v = termcmd } },
	{ Mod1Mask,				XK_F1,						spawn,				{.v = roficmd } },
	{ MODKEY,				XK_w,						spawn,				{.v = webcmd } },
	{ MODKEY,				XK_e,						spawn,				{.v = fmcmd } },
	{ MODKEY|ShiftMask,		XK_e,						spawn,				{.v = rangercmd } },
	{ 0, 					XF86XK_AudioMute, 			spawn, 				{.v = volmute } },
	{ 0, 					XF86XK_AudioMicMute, 		spawn, 				{.v = micmute } },
	{ 0, 					XF86XK_AudioLowerVolume, 	spawn, 				{.v = voldown} },
	{ 0, 					XF86XK_AudioRaiseVolume, 	spawn, 				{.v = volup } },
	{ 0, 					XF86XK_MonBrightnessUp, 	spawn, 				{.v = blup } },
	{ 0, 					XF86XK_MonBrightnessDown, 	spawn, 				{.v = bldown } },
	{ MODKEY,				XK_grave,					togglescratch,		{.v = spterm } },
	{ MODKEY,				XK_j,						focusstack,			{.i = +1 } },
	{ MODKEY,				XK_k,						focusstack,			{.i = -1 } },
	{ MODKEY|ShiftMask,		XK_j,						rotatestack,		{.i = +1 } },
	{ MODKEY|ShiftMask,		XK_k,						rotatestack,		{.i = -1 } },
	{ MODKEY,				XK_i,						incnmaster,			{.i = +1 } },
	{ MODKEY,				XK_d,						incnmaster,			{.i = -1 } },
	{ MODKEY,				XK_h,						setmfact,			{.f = -0.05} },
	{ MODKEY,				XK_l,						setmfact,			{.f = +0.05} },
	{ MODKEY|ShiftMask,		XK_h,						setcfact,			{.f = +0.25} },
	{ MODKEY|ShiftMask,		XK_l,						setcfact,			{.f = -0.25} },
	{ MODKEY|ShiftMask,		XK_o,						setcfact,			{.f =	0.00} },
	{ MODKEY,				XK_equal,					incrgaps,			{.i = +1 } },
	{ MODKEY,				XK_minus,					incrgaps,			{.i = -1 } },
	{ MODKEY|ShiftMask,		XK_g,						togglegaps,			{0} },
	{ MODKEY|ControlMask,	XK_g,						defaultgaps,		{0} },
	{ MODKEY,				XK_q,						killclient,			{0} },
	{ MODKEY|ShiftMask,		XK_q,						quit,				{0} },
	{ MODKEY|ShiftMask,		XK_r,						quit,				{1} }, 
	{ MODKEY,				XK_t,						setlayout,			{.v = &layouts[0]} },
	{ MODKEY,				XK_f,						setlayout,			{.v = &layouts[1]} },
	{ MODKEY,				XK_m,						setlayout,			{.v = &layouts[2]} },
	{ MODKEY,				XK_b,						setlayout,			{.v = &layouts[6]} },
	{ MODKEY,				XK_g,						setlayout,			{.v = &layouts[11]} },
	{ MODKEY,				XK_comma,					cyclelayout,    	{.i = -1 } },
	{ MODKEY,           	XK_period, 					cyclelayout,    	{.i = +1 } },
	{ MODKEY|ShiftMask,		XK_space,					togglefloating,		{0} },
	{ MODKEY|ShiftMask,		XK_b,						togglebar,			{0} },
	{ MODKEY|ShiftMask,		XK_f,						togglefullscr,		{0} },
	{ MODKEY|ShiftMask,		XK_s,						togglesticky,		{0} },
	{ MODKEY,				XK_0,						view,				{.ui = ~0 } },
	{ MODKEY|ShiftMask,		XK_0,						tag,				{.ui = ~0 } },
	{ MODKEY,				XK_Right,					viewnext,			{0} },
	{ MODKEY,				XK_Left,					viewprev,			{0} },
	{ MODKEY|ShiftMask,		XK_Right,					tagtonext,			{0} },
	{ MODKEY|ShiftMask,		XK_Left,					tagtoprev,			{0} },
	TAGKEYS(				XK_1,											0)
	TAGKEYS(				XK_2,											1)
	TAGKEYS(				XK_3,											2)
	TAGKEYS(				XK_4,											3)
	TAGKEYS(				XK_5,											4)
	TAGKEYS(				XK_6,											5)
	TAGKEYS(				XK_7,											6)
	TAGKEYS(				XK_8,											7)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click	event mask			button			function		argument */
	{ ClkButton,		0,			Button1,		spawn,			{.v = roficmd } },
	{ ClkLtSymbol,		0,			Button1,		setlayout,		{0} },
	{ ClkLtSymbol,		0,			Button3,		setlayout,		{.v = &layouts[2]} },
	{ ClkWinTitle,		0,			Button2,		zoom,			{0} },
	{ ClkStatusText,	0,			Button2,		spawn,			{.v = termcmd } },
	{ ClkClientWin,		MODKEY,		Button1,		movemouse,		{0} },
	{ ClkClientWin,		MODKEY,		Button2,		togglefloating, {0} },
	{ ClkClientWin,		MODKEY,		Button3,		resizemouse,	{0} },
	{ ClkTagBar,		0,			Button1,		view,			{0} },
	{ ClkTagBar,		0,			Button3,		toggleview,		{0} },
	{ ClkTagBar,		MODKEY,		Button1,		tag,			{0} },
	{ ClkTagBar,		MODKEY,		Button3,		toggletag,		{0} },
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
