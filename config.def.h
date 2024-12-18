/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx		= 3;
static const unsigned int snap			= 32;
static int floatposgrid_x				= 5; 
static int floatposgrid_y				= 5;
static const int attachmode				= 2; 
static const char *toggle_float_pos     = "50% 50% 80% 80%"; 
static const unsigned int gappih		= 10;  
static const unsigned int gappiv		= 10; 
static const unsigned int gappoh		= 20;
static const unsigned int gappov		= 20;
static int smartgaps					= 0;
static const int showbar				= 1;
static const int topbar					= 1; 
static const int vertpad				= 20;
static const int sidepad				= 20; 
static const int user_bh				= 8;        /* 2 is the default spacing around the bar's font */
static const char buttonbar[]			= " ";
#define ICONSIZE (bh - 12)
#define ICONSPACING 12
static const char *fonts[]				= { "Noto Sans:style=Medium:size=16",
											"JetBrainsMono Nerd Font:size=18",
											"Noto Sans:size=14",
											"JetBrainsMono Nerd Font:style=ExtraBold:size=13" };
static const char dmenufont[]			= "Noto Sans:size=15";

#include "termcolors.h"

static char c000000[]					= "#000000";

static char normfgcolor[]				= "#bbbbbb";
static char normbgcolor[]				= "#222222";
static char normbordercolor[]			= "#444444";
static char normfloatcolor[]			= "#444444";

static char selfgcolor[]				= "#eeeeee";
static char selbgcolor[]				= "#005588";
static char selbordercolor[]			= "#005577";
static char selfloatcolor[]				= "#005577";

static char scratchnormbordercolor[]	= "#444444";
static char scratchnormfloatcolor[]		= "#444444";
static char scratchselbordercolor[]		= "#007799";
static char scratchselfloatcolor[]		= "#007799";

static char stbuttonfgcolor[]			= "#bbbbbb";
static char stbuttonbgcolor[]			= "#222222";
static char ltsymbolfgcolor[]			= "#dddd00";
static char ltsymbolbgcolor[]			= "#222222";

static char tagsemptyfgcolor[]			= "#444444";
static char tagsemptybgcolor[]			= "#222222";
static char tagsoccfgcolor[]			= "#bbbbbb";
static char tagsoccbgcolor[]			= "#222222";
static char tagsselfgcolor[]			= "#eeeeee";
static char tagsselbgcolor[]			= "#005577";

static char titlenormfgcolor[]			= "#bbbbbb";
static char titlenormbgcolor[]			= "#222222";
static char titleselfgcolor[]			= "#eeeeee";
static char titleselbgcolor[]			= "#005577";

static char dmenunormfgcolor[]			= "#bbbbbb";
static char dmenunormbgcolor[]			= "#222222";
static char dmenuselfgcolor[]			= "#ffff00";
static char dmenuselbgcolor[]			= "#dd0000";

static const unsigned int baralpha		= 0xd0;
static const unsigned int borderalpha	= OPAQUE;

static char *colors[][4]				= {

	[SchemeNorm]		= { normfgcolor,		normbgcolor,		normbordercolor,		normfloatcolor },
	[SchemeSel]			= { selfgcolor,			selbgcolor,			selbordercolor,			selfloatcolor },
	[SchemeScratchNorm]	= { c000000,			c000000,			scratchnormbordercolor,	normfloatcolor },
	[SchemeScratchSel]	= { c000000,			c000000,			scratchselbordercolor,	selfloatcolor },
	[SchemeTagsEmpty]	= { tagsemptyfgcolor,	tagsemptybgcolor,	c000000,				c000000 },
	[SchemeTagsOcc]		= { tagsoccfgcolor,		tagsoccbgcolor,		c000000,				c000000 },
	[SchemeTagsSel]		= { tagsselfgcolor,		tagsselbgcolor,		c000000,				c000000 },
	[SchemeTitleNorm]	= { titlenormfgcolor,	titlenormbgcolor,	c000000,				c000000 },
	[SchemeTitleSel]	= { titleselfgcolor,	titleselbgcolor,	c000000,				c000000 },
	[SchemeStButton]	= { stbuttonfgcolor,	stbuttonbgcolor,	c000000,				c000000 },
	[SchemeLtSymbol]	= { ltsymbolfgcolor,	ltsymbolbgcolor,	c000000,				c000000 },
};

static const unsigned int alphas[][4]      = {
	[SchemeNorm]		= { OPAQUE, baralpha, borderalpha, borderalpha},
	[SchemeSel]			= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeScratchNorm]	= { OPAQUE, baralpha, borderalpha, borderalpha},
	[SchemeScratchSel]	= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeTagsEmpty]	= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeTagsOcc]		= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeTagsSel]		= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeTitleNorm]	= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeTitleSel]	= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeStButton]	= { OPAQUE, baralpha, borderalpha, borderalpha },
	[SchemeLtSymbol]	= { OPAQUE, baralpha, borderalpha, borderalpha },
};

static const char *const autostart[] = {
	"/usr/bin/pipewire", NULL,
	"/usr/libexec/polkit-gnome-authentication-agent-1", NULL,
	"nitrogen", "--restore", NULL,
	"picom", "-b", NULL,
	NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	{ .class = "Lxappearance", .isfloating =1, .floatpos = "50% 50% -1h -1w" },
	{ .class = "Firefox", .tags = 1 << 1 },
	{ .class = "spterm", .scratchkey = 't', .isfloating = 1, .floatpos = "50% 50% 80% 80%" },
};

/* layout(s) */
static const float mfact		= 0.50;
static const int nmaster		= 1;
static const int resizehints	= 0;
static const int lockfullscreen	= 1;

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[]	= {
	{ "[]=",	tile }, 
	{ "><>",	NULL },
	{ "[M]",	monocle },
	{ "TTT",	bstack },
	{ ":::",	gaplessgrid },
	{ NULL,	 	NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,						KEY,	view,			{.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,			KEY,	toggleview,		{.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,				KEY,	tag,			{.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask,	KEY,	toggletag,		{.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[]	= { "dmenu_run", 
	"-fn", dmenufont, 
	"-nb", dmenunormbgcolor, 
	"-nf", dmenunormfgcolor, 
	"-sb", dmenuselbgcolor, 
	"-sf", dmenuselfgcolor, 
	NULL };

static const char *termcmd[]	= { "alacritty", NULL };
static const char *webcmd[]		= { "firefox", NULL };
static const char *gpickcmd[]	= { "colorpicker", NULL };

#include <X11/XF86keysym.h>
static const char *mutevol[]	= { "volume", "--toggle", NULL };
static const char *mutemic[]	= { "volume", "--toggle-mic", NULL };
static const char *upvol[]		= { "volume", "--inc", NULL };
static const char *downvol[]	= { "volume", "--dec", NULL };
static const char *upbl[]		= { "brightness", "--inc", NULL };
static const char *downbl[]		= { "brightness", "--dec", NULL };

static const char *sptermcmd[]	= { "t", "alacritty", "--class", "spterm.spterm", NULL };

static const Key keys[] = {
	{ MODKEY,					XK_Return,					spawn,				{.v = termcmd } },
	{ MODKEY,					XK_space,					spawn,				{.v = dmenucmd } },
	{ MODKEY,					XK_w,						spawn,				{.v = webcmd } },
	{ MODKEY,					XK_p,						spawn,				{.v = gpickcmd } },
	{ MODKEY|ShiftMask,			XK_Return,					togglescratch,		{.v = sptermcmd } },
	{ 0, 						XF86XK_AudioMute, 			spawn,				{.v = mutevol } },
	{ 0, 						XF86XK_AudioMicMute, 		spawn,				{.v = mutemic } },
	{ 0, 						XF86XK_AudioLowerVolume, 	spawn,				{.v = downvol } },
	{ 0, 						XF86XK_AudioRaiseVolume, 	spawn,				{.v = upvol   } },
	{ 0, 						XF86XK_MonBrightnessUp, 	spawn,				{.v = upbl   } },
	{ 0, 						XF86XK_MonBrightnessDown, 	spawn,				{.v = downbl   } },
	{ MODKEY,					XK_j,						focusstack,			{.i = +1 } },
	{ MODKEY,					XK_k,						focusstack,			{.i = -1 } },
	{ MODKEY|ShiftMask,			XK_j,						rotatestack,		{.i = +1 } },
	{ MODKEY|ShiftMask,			XK_k,						rotatestack,		{.i = -1 } },
	{ MODKEY,					XK_i,						incnmaster,			{.i = +1 } },
	{ MODKEY,					XK_d,						incnmaster,			{.i = -1 } },
	{ MODKEY,					XK_h,						setmfact,			{.f = -0.05} },
	{ MODKEY,					XK_l,						setmfact,			{.f = +0.05} },
	{ MODKEY|ShiftMask,			XK_h,						setcfact,			{.f = +0.25} },
	{ MODKEY|ShiftMask,			XK_l,						setcfact,			{.f = -0.25} },
	{ MODKEY|ShiftMask,			XK_o,						setcfact,			{.f =  0.00} },
	{ MODKEY|ShiftMask,			XK_space,					togglefloating, 	{0} },
	{ MODKEY|ShiftMask,			XK_b,						togglebar,      	{0} },
	{ MODKEY|ShiftMask,			XK_f,						togglefullscr,		{0} },
	{ MODKEY|ShiftMask,			XK_g,						togglegaps,     	{0} },
	{ MODKEY|ShiftMask,			XK_x,						xrdb,				{.v = NULL } },
	{ MODKEY,					XK_q,						killclient,     	{0} },
	{ MODKEY|ShiftMask,			XK_q,						quit,				{0} },
	{ MODKEY|ShiftMask,			XK_r,						quit,				{1} }, 
	{ MODKEY,					XK_t,						setlayout,			{.v = &layouts[0]} },
	{ MODKEY,					XK_f,						setlayout,			{.v = &layouts[1]} },
	{ MODKEY,					XK_m,						setlayout,			{.v = &layouts[2]} },
	{ MODKEY,					XK_b,						setlayout,			{.v = &layouts[3]} },
	{ MODKEY,					XK_g,						setlayout,			{.v = &layouts[4]} },
	{ MODKEY,					XK_0,						view,				{.ui = ~0 } },
	{ MODKEY,					XK_Right,					viewnext,			{0} },
	{ MODKEY,					XK_Left,					viewprev,			{0} },
	{ MODKEY|ShiftMask,			XK_Right,					tagtonext,			{0} },
	{ MODKEY|ShiftMask,			XK_Left,					tagtoprev,			{0} },
	{ MODKEY|ShiftMask,			XK_0,						tag,				{.ui = ~0 } },
	TAGKEYS(					XK_1,											0)
	TAGKEYS(					XK_2,											1)
	TAGKEYS(					XK_3,											2)
	TAGKEYS(					XK_4,											3)
	TAGKEYS(					XK_5,											4)
	TAGKEYS(					XK_6,											5)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	{ ClkButton,		0,				Button1,	spawn,				{.v = dmenucmd } },
	{ ClkLtSymbol,		0,				Button1,	setlayout,			{0} },
	{ ClkLtSymbol,		0,				Button3,	setlayout,			{.v = &layouts[2]} },
	{ ClkWinTitle,		0,				Button2,	zoom,				{0} },
	{ ClkStatusText,	0,				Button2,	spawn,				{.v = termcmd } },
	{ ClkClientWin,		MODKEY,			Button1,	movemouse,			{0} },
	{ ClkClientWin,		MODKEY,			Button2,	togglefloating,		{0} },
	{ ClkClientWin,		MODKEY,			Button3,	resizemouse,		{0} },
	{ ClkTagBar,		0,				Button1,	view,				{0} },
	{ ClkTagBar,		0,				Button3,	toggleview,			{0} },
	{ ClkTagBar,		MODKEY,			Button1,	tag,				{0} },
	{ ClkTagBar,		MODKEY,			Button3,	toggletag,			{0} },
};

