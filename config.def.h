/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx		= 2;
static const unsigned int snap			= 32;
static const unsigned int gappih		= 15;
static const unsigned int gappiv		= 15;
static const unsigned int gappoh		= 15;
static const unsigned int gappov		= 15;
static const int smartgaps_fact			= 0;
static const int showbar				= 1;
static const int topbar					= 1;
static const int bar_height				= 36;
static const int vertpad				= 0;
static const int sidepad				= 0;
#define ICONSIZE (bh - 10)
#define ICONSPACING 10
static const int statusmon				= 'A';
static const char buttonbar[]			= "";
static const unsigned int ulinepad 		= 5;
static const unsigned int ulinestroke	= 1;
static const unsigned int ulinevoffset	= 0;
static const int ulineall= 0;

static int tagindicatortype				= INDICATOR_NONE;
static int tiledindicatortype			= INDICATOR_NONE;
static int floatindicatortype			= INDICATOR_NONE;

static const char statussep				= ';'; 
static const char *fonts[]				= { "Noto Sans:size=16",
											"JetBrainsMono Nerd Font:style=ExtraBold:size=14" };

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

static char tagsoccfgcolor[]			= "#bbbbbb";
static char tagsoccbgcolor[]			= "#222222";
static char tagsoccbordercolor[]		= "#444444";
static char tagsoccfloatcolor[]			= "#db8fd9";

static char tagsselfgcolor[]			= "#eeeeee";
static char tagsselbgcolor[]			= "#005577";
static char tagsselbordercolor[]		= "#005577";
static char tagsselfloatcolor[]			= "#005577";

static char urgfgcolor[]				= "#bbbbbb";
static char urgbgcolor[]				= "#222222";
static char urgbordercolor[]			= "#ff0000";
static char urgfloatcolor[]				= "#db8fd9";

static char scratchselfgcolor[]			= "#FFF7D4";
static char scratchselbgcolor[]			= "#77547E";
static char scratchselbordercolor[]		= "#894B9F";
static char scratchselfloatcolor[]		= "#894B9F";

static char scratchnormfgcolor[]		= "#FFF7D4";
static char scratchnormbgcolor[]		= "#664C67";
static char scratchnormbordercolor[]	= "#77547E";
static char scratchnormfloatcolor[]		= "#77547E";

static char stickyfgcolor[]				= "#bbbbbb";
static char stickybgcolor[]				= "#222222";
static char stickybordercolor[]			= "#ff0000";
static char stickyfloatcolor[]			= "#db8fd9";

static char ltsymbolfgcolor[]			= "#bbbbbb";
static char ltsymbolbgcolor[]			= "#222222";
static char ltsymbolbordercolor[]		= "#ff0000";
static char ltsymbolfloatcolor[]		= "#db8fd9";

static char *colors[][ColCount] = {
	[SchemeNorm]		= { normfgcolor,		normbgcolor,		normbordercolor,		normfloatcolor },
	[SchemeSel]			= { selfgcolor,			selbgcolor,			selbordercolor,			selfloatcolor },
	[SchemeTitleNorm]	= { titlenormfgcolor,	titlenormbgcolor,	titlenormbordercolor,	titlenormfloatcolor },
	[SchemeTitleSel]	= { titleselfgcolor,	titleselbgcolor,	titleselbordercolor,	titleselfloatcolor },
	[SchemeTagsNorm]	= { tagsnormfgcolor,	tagsnormbgcolor,	tagsnormbordercolor,	tagsnormfloatcolor },
	[SchemeTagsOcc]		= { tagsoccfgcolor,		tagsoccbgcolor,		tagsoccbordercolor,		tagsoccfloatcolor },
	[SchemeTagsSel]		= { tagsselfgcolor,		tagsselbgcolor,		tagsselbordercolor,		tagsselfloatcolor },
	[SchemeUrg]			= { urgfgcolor,			urgbgcolor,			urgbordercolor,			urgfloatcolor },
	[SchemeScratchSel]	= { scratchselfgcolor,	scratchselbgcolor,	scratchselbordercolor,	scratchselfloatcolor },
	[SchemeScratchNorm]	= { scratchnormfgcolor,	scratchnormbgcolor,	scratchnormbordercolor,	scratchnormfloatcolor },
	[SchemeSticky]		= { stickyfgcolor,		stickybgcolor,		stickybordercolor,		stickyfloatcolor },
	[SchemeLtSymbol]	= { ltsymbolfgcolor,	ltsymbolbgcolor,	ltsymbolbordercolor,	ltsymbolfloatcolor },
};

static const unsigned int baralpha 		= 0xd0;
static const unsigned int borderalpha 	= OPAQUE;

static const unsigned int alphas[][3] 	= {
	[SchemeNorm]		= { OPAQUE, baralpha, borderalpha },
	[SchemeSel]			= { OPAQUE, baralpha, borderalpha },
	[SchemeTitleNorm]	= { OPAQUE, baralpha, borderalpha },
	[SchemeTitleSel]	= { OPAQUE, baralpha, borderalpha },
	[SchemeTagsNorm]	= { OPAQUE, baralpha, borderalpha },
	[SchemeTagsOcc]		= { OPAQUE, baralpha, borderalpha },
	[SchemeTagsSel]		= { OPAQUE, baralpha, borderalpha },
	[SchemeUrg]			= { OPAQUE, baralpha, borderalpha },
	[SchemeScratchSel]	= { OPAQUE, baralpha, borderalpha },
	[SchemeScratchNorm]	= { OPAQUE, baralpha, borderalpha },
	[SchemeSticky]		= { OPAQUE, baralpha, borderalpha },
	[SchemeLtSymbol]	= { OPAQUE, baralpha, borderalpha },
};


static const char *const autostart[] = {
	"/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1", NULL,
	"dunst", NULL,
	"nitrogen", "--restore", NULL,
	NULL 
};


static char *tagicons[][NUMTAGS] =
{
	[DEFAULT_TAGS]        = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};

static const Rule rules[] = {
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	RULE(.class = "Lxappearance", .isfloating = 1, .iscentered = 1 )
	RULE(.class = "firefox", .tags = 1 << 1 )
	RULE(.instance = "spterm", .scratchkey = 't', .isfloating = 1, .iscentered = 1 )
};

static const BarRule barrules[] = {
	{ -1,			0,	BAR_ALIGN_LEFT,		width_stbutton,		draw_stbutton,		click_stbutton,		NULL,			"statusbutton" },
	{ -1,			0,	BAR_ALIGN_LEFT,		width_tags,			draw_tags,			click_tags,			hover_tags,		"tags" },
	{ -1,			0,	BAR_ALIGN_LEFT,		width_ltsymbol,		draw_ltsymbol,		click_ltsymbol,		NULL,			"layout" },
	{ statusmon,	0,	BAR_ALIGN_RIGHT,	width_status2d,		draw_status2d,		click_status2d,		NULL,			"status2d" },
	{ -1,			0,	BAR_ALIGN_NONE,		width_wintitle,		draw_wintitle,		click_wintitle,		NULL,			"wintitle" },
	{ -2,			1,	BAR_ALIGN_CENTER,	width_status2d_es,	draw_status2d_es,	click_status2d,		NULL,			"status2d_es" },
};

static const float mfact     		= 0.50;
static const int nmaster     		= 1; 
static const int resizehints 		= 0; 
static const int lockfullscreen		= 1;
static const int swallowfloating	= 0;
static int floatposgrid_x			= 5;
static int floatposgrid_y			= 5;
static const char *toggle_float_pos	= "50% 50% 80% 80%";


static const Layout layouts[] = {
	{ "[]=",	tile },
	{ "><>",	NULL },
	{ "[M]",	monocle },
	{ "|||",	col },
	{ "TTT",	bstack },
	{ "HHH",	gaplessgrid },
};


#define Super Mod4Mask
#define Shift ShiftMask
#define Control ControlMask
#define Alt Mod1Mask

#define TAGKEYS(KEY,TAG) \
	{ Super,				KEY,	view,			{.ui = 1 << TAG} }, \
	{ Super|Control,		KEY,	toggleview,		{.ui = 1 << TAG} }, \
	{ Super|Shift,			KEY,	tag,			{.ui = 1 << TAG} }, \
	{ Super|Control|Shift,	KEY,	toggletag,		{.ui = 1 << TAG} },



#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static const char *termcmd[]		= { "alacritty", NULL };
static const char *roficmd[]		= { "rofi", "-show", "drun", NULL };
static const char *webcmd[]			= { "firefox", NULL };
static const char *fmcmd[]			= { "thunar", NULL };

static const char *scratchpadcmd[]	= { "t", "alacritty", "--class", "spterm,spterm", NULL};

static const char *bldown[]			= { "backlight", "--dec", NULL };
static const char *blup[]			= { "backlight", "--inc", NULL };
static const char *kbdown[]			= { "keylights", "--dec", NULL };
static const char *kbup[]			= { "keylights", "--inc", NULL };

#include <X11/XF86keysym.h>
static const Key keys[] = {
	{ Super,				XK_space,					spawn,				{.v = roficmd } },
	{ Super,				XK_Return,					spawn,				{.v = termcmd } },
	{ Super,				XK_w,						spawn,				{.v = webcmd } },
	{ Super,				XK_e,						spawn,				{.v = fmcmd } },
	{ 0,					XF86XK_MonBrightnessDown,	spawn,				{.v = bldown } },
	{ 0,					XF86XK_MonBrightnessUp,		spawn,				{.v = blup } },
	{ 0,					XF86XK_KbdBrightnessDown,	spawn,				{.v = kbdown } },
	{ 0,					XF86XK_KbdBrightnessUp,		spawn,				{.v = kbup } },
	{ Super|Shift,			XK_b,						togglebar,			{0} },
	{ Super,				XK_j,						focusstack,			{.i = +1 } },
	{ Super,				XK_k,						focusstack,			{.i = -1 } },
	{ Super|Shift,			XK_j,						rotatestack,		{.i = +1 } },
	{ Super|Shift,			XK_k,						rotatestack,		{.i = -1 } },
	{ Super,				XK_i,						incnmaster,			{.i = +1 } },
	{ Super,				XK_d,						incnmaster,			{.i = -1 } },
	{ Super|Shift,			XK_h,						setcfact,			{.f = +0.25} },
	{ Super|Shift,			XK_l,						setcfact,			{.f = -0.25} },
	{ Super|Shift,			XK_o,						setcfact,			{0} },
	{ Super,				XK_bracketright,			incrgaps,			{.i = +1 } },
	{ Super,				XK_bracketleft,				incrgaps,			{.i = -1 } },
	{ Super|Shift,			XK_bracketleft,				togglegaps,			{0} },
	{ Super|Shift,			XK_bracketright,			defaultgaps,		{0} },
	{ Super,				XK_q,						killclient,			{0} },
	{ Super|Shift,			XK_q,						quit,				{0} },
	{ Super|Shift,			XK_r,						quit,				{1} },
	{ Super|Shift,			XK_F5,						xrdb,				{.v = NULL } },
	{ Super,				XK_t,						setlayout,			{.v = &layouts[0]} },
	{ Super,				XK_f,						setlayout,			{.v = &layouts[1]} },
	{ Super,				XK_m,						setlayout,			{.v = &layouts[2]} },
	{ Super,				XK_c,						setlayout,			{.v = &layouts[3]} },
	{ Super,				XK_b,						setlayout,			{.v = &layouts[4]} },
	{ Super,				XK_g,						setlayout,			{.v = &layouts[5]} },
	{ Super,				XK_comma,					cyclelayout,		{.i = -1 } },
	{ Super,				XK_period,					cyclelayout,		{.i = +1 } },
	{ Super|Shift,			XK_space,					togglefloating,		{0} },
	{ Super,				XK_grave,					togglescratch,		{.v = scratchpadcmd } },
	{ Super|Control,		XK_grave,					setscratch,			{.v = scratchpadcmd } },
	{ Super|Shift,			XK_grave,					removescratch,		{.v = scratchpadcmd } },
	{ Super|Shift,			XK_f,						togglefullscreen,	{0} },
	{ Super|Shift,			XK_s,						togglesticky,		{0} },
	{ Super,				XK_0,						view,				{.ui = ~0 } },
	{ Super|Shift,			XK_0,						tag,				{.ui = ~0 } },
	{ Super,				XK_Left,					viewtoleft,			{0} },
	{ Super,				XK_Right,					viewtoright,		{0} }, 
	{ Super|Control,		XK_Left,					tagtoleft,			{0} }, 
	{ Super|Control,		XK_Right,					tagtoright,			{0} },
	{ Super|Shift,			XK_Left,					tagandviewtoleft,	{0} }, 
	{ Super|Shift,			XK_Right,					tagandviewtoright,	{0} },
	{ Super|Control,		XK_bracketleft,				setborderpx,		{.i = -1 } },
	{ Super|Control,		XK_bracketright,			setborderpx,		{.i = +1 } },
	{ Super|Control,		XK_numbersign,				setborderpx,		{.i = 0 } },
	TAGKEYS(				XK_1,											0)
	TAGKEYS(				XK_2,											1)
	TAGKEYS(				XK_3,											2)
	TAGKEYS(				XK_4,											3)
	TAGKEYS(				XK_5,											4)
	TAGKEYS(				XK_6,											5)
	TAGKEYS(				XK_7,											6)
	TAGKEYS(				XK_8,											7)
	TAGKEYS(				XK_9,											8)
};


static const Button buttons[] = {
	{ ClkButton,		0,			Button1,	spawn,				{.v = roficmd } },
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

static const Signal signals[] = {
		{ "cyclelayout",             cyclelayout },
		{ "defaultgaps",             defaultgaps },
		{ "floatpos",                floatpos },
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
		{ "quit",                    quit },
		{ "rotatestack",             rotatestack },
		{ "setborderpx",             setborderpx },
		{ "setcfact",                setcfact },
		{ "setgaps",                 setgapsex },
		{ "setlayout",               setlayout },
		{ "setlayoutex",             setlayoutex },
		{ "setmfact",                setmfact },
		{ "tag",                     tag },
		{ "tagall",                  tagallex },
		{ "tagandviewtoleft",        tagandviewtoleft },
		{ "tagandviewtoright",       tagandviewtoright },
		{ "tagex",                   tagex },
		{ "tagmon",                  tagmon },
		{ "tagtoleft",               tagtoleft },
		{ "tagtoright",              tagtoright},
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
		{ "viewtoleft",              viewtoleft },
		{ "viewtoright",             viewtoright },
		{ "xrdb",                    xrdb },
		{ "zoom",                    zoom },
};

