/* See LICENSE file for copyright and license details. */

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define CMD(...)   { .v = (const char*[]){ __VA_ARGS__, NULL } }

static const unsigned int borderpx		= 3; 
static const unsigned int snap			= 32;
static const int swallowfloating		= 0; 
static const char *toggle_float_pos		= "50% 50% 80% 80%";
static const int focusonwheel			= 0;
static int floatposgrid_x				= 5;  /* float grid columns */
static int floatposgrid_y				= 5;  /* float grid rows */

static const unsigned int gappih		= 10;
static const unsigned int gappiv		= 10;
static const unsigned int gappoh		= 20;
static const unsigned int gappov		= 20;
static const int smartgaps_fact			= 1;

static const int showbar				= 1; 
static const int topbar					= 1; 
static const int bar_height				= 0; 
static const char statussep				= ';';
static const int vertpad				= 0;
static const int sidepad				= 0;

#define ICONSIZE 						(bh - 12) 
#define ICONSPACING 					12 

static const int statusmon				= 'A';
static const char buttonbar[]			= " ";
static const unsigned int ulinepad		= 5;
static const unsigned int ulinestroke	= 1;
static const unsigned int ulinevoffset	= 0;
static const int ulineall = 0; 

static int tagindicatortype				= INDICATOR_NONE;
static int tiledindicatortype			= INDICATOR_NONE;
static int floatindicatortype			= INDICATOR_TOP_LEFT_SQUARE;

static const char *fonts[]				= { "Noto Sans:size=15",
											"JetBrainsMono Nerd Font:size=15",
											"JetBrainsMono Nerd Font:style=Bold:size=13" };

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

static char tagsoccfgcolor[]			= "#bbbbbb";
static char tagsoccbgcolor[]			= "#222222";

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

static char scratchselfgcolor[]			= "#FFF7D4";
static char scratchselbgcolor[]			= "#77547E";
static char scratchselbordercolor[]		= "#894B9F";
static char scratchselfloatcolor[]		= "#894B9F";

static char scratchnormfgcolor[]		= "#FFF7D4";
static char scratchnormbgcolor[]		= "#664C67";
static char scratchnormbordercolor[]	= "#77547E";
static char scratchnormfloatcolor[]		= "#77547E";

static char ltsymbolfgcolor[]			= "#ffff00";
static char ltsymbolbgcolor[]			= "#222222";
static char stbuttonfgcolor[]			= "#0088BB";
static char stbuttonbgcolor[]			= "#222222";

static char *colors[][ColCount] = {
	[SchemeNorm]		= { normfgcolor,		normbgcolor,		normbordercolor,		normfloatcolor },
	[SchemeSel]			= { selfgcolor,			selbgcolor,			selbordercolor,			selfloatcolor },
	[SchemeTitleNorm]	= { titlenormfgcolor,	titlenormbgcolor,	titlenormbordercolor,	titlenormfloatcolor },
	[SchemeTitleSel]	= { titleselfgcolor,	titleselbgcolor,	titleselbordercolor,	titleselfloatcolor },
	[SchemeTagsNorm]	= { tagsnormfgcolor,	tagsnormbgcolor,	tagsnormbordercolor,	tagsnormfloatcolor },
	[SchemeTagsOcc]		= { tagsoccfgcolor,		tagsoccbgcolor,		c000000,				c000000 },
	[SchemeTagsSel]		= { tagsselfgcolor,		tagsselbgcolor,		tagsselbordercolor,		tagsselfloatcolor },
	[SchemeHidNorm]		= { hidnormfgcolor,		hidnormbgcolor,		c000000,				c000000 },
	[SchemeHidSel]		= { hidselfgcolor,		hidselbgcolor,		c000000,				c000000 },
	[SchemeUrg]			= { urgfgcolor,			urgbgcolor,			urgbordercolor,			urgfloatcolor },
	[SchemeScratchNorm]	= { scratchnormfgcolor,	scratchnormbgcolor,	scratchnormbordercolor,	scratchnormfloatcolor },
	[SchemeScratchSel]  = { scratchselfgcolor,	scratchselbgcolor,	scratchselbordercolor,	scratchselfloatcolor },
	[SchemeLtSymbol]	= { ltsymbolfgcolor, 	ltsymbolbgcolor,	c000000,				c000000 },
	[SchemeStButton]	= { stbuttonfgcolor, 	stbuttonbgcolor,	c000000,				c000000 },
};

static const unsigned int baralpha		= 0x40;
static const unsigned int borderalpha	= OPAQUE;

static const unsigned int alphas[][3]      = {
	[SchemeNorm] 		= { OPAQUE, baralpha, borderalpha },
	[SchemeSel] 		= { OPAQUE, baralpha, borderalpha },
	[SchemeTitleNorm] 	= { OPAQUE, baralpha, borderalpha },
	[SchemeTitleSel] 	= { OPAQUE, baralpha, borderalpha },
	[SchemeTagsNorm] 	= { OPAQUE, baralpha, borderalpha },
	[SchemeTagsOcc] 	= { OPAQUE, baralpha, borderalpha },
	[SchemeTagsSel] 	= { OPAQUE, baralpha, borderalpha },
	[SchemeHidNorm] 	= { OPAQUE, baralpha, borderalpha },
	[SchemeHidSel] 		= { OPAQUE, baralpha, borderalpha },
	[SchemeUrg] 		= { OPAQUE, baralpha, borderalpha },
	[SchemeScratchNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeScratchSel] 	= { OPAQUE, baralpha, borderalpha },
	[SchemeLtSymbol] 	= { OPAQUE, baralpha, borderalpha },
	[SchemeStButton] 	= { OPAQUE, baralpha, borderalpha },
};


static const Launcher launchers[] = {
	/* icon to display      command        */
	{ "surf",               CMD("surf", "duckduckgo.com") },
};

static const char *const autostart[] = {
	"/usr/libexec/polkit-gnome-authentication-agent-1", NULL,
	"/usr/bin/pipewire", NULL,
	"nitrogen", "--restore", NULL,
	"dunst", NULL,
	"picom", "-b", NULL,
	"slstatus", NULL,
	NULL /* terminate */
};


static char *tagicons[][NUMTAGS] =
{
	[DEFAULT_TAGS]        = { "1", "2", "3", "4", "5", "6" },
	[ALT_TAGS_DECORATION] = { "1", "2", "3", "4", "5", "6" },
};

 /*static char *tagicons[][1] = {*/
 /*	[DEFAULT_TAGS]			= { "" },*/
 /*[ALT_TAGS_DECORATION]	= { "" },*/
 /*};*/

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1, .bw = 5)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1, .bw = 5)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1, .bw = 5)
	RULE(.class = "Lxappearance", .isfloating = 1, .floatpos = "50% 50% -1h -1w")
	RULE(.class = "Firefox", .tags = 1 << 1)
	RULE(.class = "spterm", .scratchkey = 't', .isfloating = 1, .floatpos = "50% 50% 80% 80%")
	RULE(.class = "spranger", .scratchkey = 'r', .isfloating = 1, .floatpos = "50% 50% 80% 80%")
};

static const BarRule barrules[] = {
	/* monitor   bar    alignment         widthfunc                 drawfunc                clickfunc                hoverfunc                name */
	{ -1,			0,	BAR_ALIGN_LEFT,		width_stbutton,		draw_stbutton,		click_stbutton,			NULL,			"statusbutton" },
	{ -2,			0,	BAR_ALIGN_LEFT,		width_launcher,		draw_launcher,		click_launcher,			NULL,			"launcher" },
	{ -1,			0,	BAR_ALIGN_LEFT,		width_tags,			draw_tags,			click_tags,				hover_tags,		"tags" },
	{ -1,			0,	BAR_ALIGN_LEFT,		width_ltsymbol,		draw_ltsymbol,		click_ltsymbol,			NULL,			"layout" },
	{ statusmon,	0,	BAR_ALIGN_RIGHT,	width_status2d,		draw_status2d,		click_statuscmd,		NULL,			"status2d" },
	/*{ -1,			0,	BAR_ALIGN_NONE,		width_awesomebar,	draw_awesomebar,	click_awesomebar,		NULL,			"awesomebar" },*/
	{ -1,			0,	BAR_ALIGN_NONE,		width_wintitle,		draw_wintitle,		click_wintitle,			NULL,			"wintitle" },
	{ -2,			1,	BAR_ALIGN_CENTER,	width_status2d_es,	draw_status2d_es,	click_statuscmd_es,		NULL,			"status2d_es" },
};

/* layout(s) */
static const float mfact		= 0.50;
static const int nmaster		= 1; 
static const int resizehints	= 0; 
static const int lockfullscreen	= 1;

static const Layout layouts[] = {
	{ "[]=",	tile }, 
	{ "><>",	NULL },
	{ "[M]",	monocle },
	{ "TTT",	bstack },
	{ "|M|",	centeredmaster },
	{ "|||",	col },
	{ "[D]",	deck },
	{ "HHH",	grid },
	{ ":::",	gaplessgrid },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,						KEY,	view,			{.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,			KEY,	toggleview,		{.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,				KEY,	tag,			{.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask,	KEY,	toggletag,		{.ui = 1 << TAG} },

/* commands */
static const char *termcmd[]	= { "alacritty", NULL };
static const char *roficmd[]	= { "rofi", "-show", "drun", NULL };
static const char *webcmd[]		= { "firefox", NULL };

static const char *sptermcmd[]	= { "t", "alacritty", "--class", "spterm,spterm", NULL};
static const char *spfmcmd[]	= { "r", "alacritty", "--class", "spranger,spranger", "-e", "ranger", NULL};


static const char *mutevol[]	= { "volume", "--toggle", NULL };
static const char *mutemic[]	= { "volume", "--toggle-mic", NULL };
static const char *upvol[]		= { "volume", "--inc", NULL };
static const char *downvol[]	= { "volume", "--dec", NULL };
static const char *upbl[]		= { "brightness", "--inc", NULL };
static const char *downbl[]		= { "brightness", "--dec", NULL };

/* This defines the name of the executable that handles the bar (used for signalling purposes) */
#define STATUSBAR "dwmblocks"

#include <X11/XF86keysym.h>
static const Key keys[] = {
	{ MODKEY,				XK_space,					spawn,				{.v = roficmd } },
	{ MODKEY,				XK_Return,					spawn,				{.v = termcmd } },
	{ MODKEY,				XK_w,						spawn,				{.v = webcmd } },
	{ 0, 					XF86XK_AudioMute, 			spawn, 				{.v = mutevol } },
	{ 0, 					XF86XK_AudioMicMute, 		spawn, 				{.v = mutemic } },
	{ 0, 					XF86XK_AudioLowerVolume, 	spawn, 				{.v = downvol } },
	{ 0, 					XF86XK_AudioRaiseVolume, 	spawn, 				{.v = upvol } },
	{ 0, 					XF86XK_MonBrightnessUp, 	spawn, 				{.v = upbl } },
	{ 0, 					XF86XK_MonBrightnessDown, 	spawn, 				{.v = downbl } },
	{ MODKEY|ShiftMask,		XK_b,						togglebar,			{0} },
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
	{ MODKEY|ShiftMask,		XK_o,						setcfact,			{0} },
	{ MODKEY|ShiftMask,		XK_g,						togglegaps,			{0} },
	{ MODKEY|ControlMask,	XK_z,						showhideclient,		{0} },
	{ MODKEY,				XK_q,						killclient,			{0} },
	{ MODKEY|ShiftMask,		XK_q,						quit,				{0} },
	{ MODKEY|ShiftMask,		XK_r,						quit,				{1} },
	{ MODKEY|ShiftMask,		XK_x,						xrdb,				{.v = NULL } },
	{ MODKEY,				XK_t,						setlayout,			{.v = &layouts[0]} },
	{ MODKEY,				XK_f,						setlayout,			{.v = &layouts[1]} },
	{ MODKEY,				XK_m,						setlayout,			{.v = &layouts[2]} },
	{ MODKEY,				XK_c,						setlayout,			{.v = &layouts[3]} },
	{ MODKEY,				XK_comma,					cyclelayout,		{.i = -1 } },
	{ MODKEY,				XK_period,					cyclelayout,		{.i = +1 } },
	{ MODKEY|ShiftMask,		XK_space,					togglefloating,		{0} },
	{ MODKEY,				XK_grave,					togglescratch,		{.v = sptermcmd } },
	{ MODKEY,				XK_r,						togglescratch,		{.v = spfmcmd } },
	{ MODKEY|ShiftMask,		XK_f,						togglefullscreen,	{0} },
	{ MODKEY|ShiftMask,		XK_s,						togglesticky,		{0} },
	{ MODKEY,				XK_0,						view,				{.ui = ~0 } },
	{ MODKEY|ShiftMask,		XK_0,						tag,				{.ui = ~0 } },
	{ MODKEY,				XK_Left,					viewtoleft,			{0} }, 
	{ MODKEY,				XK_Right,					viewtoright,		{0} }, 
	{ MODKEY|ControlMask,	XK_Left,					tagtoleft,			{0} }, 
	{ MODKEY|ControlMask,	XK_Right,					tagtoright,			{0} }, 
	{ MODKEY|ShiftMask,		XK_Left,					tagandviewtoleft,	{0} }, 
	{ MODKEY|ShiftMask,		XK_Right,					tagandviewtoright,	{0} }, 
	TAGKEYS(				XK_1,											0)
	TAGKEYS(				XK_2,											1)
	TAGKEYS(				XK_3,											2)
	TAGKEYS(				XK_4,											3)
	TAGKEYS(				XK_5,											4)
	TAGKEYS(				XK_6,											5)
};

static const Button buttons[] = {
	{ ClkButton,		0,		Button1,	spawn,			{.v = roficmd } },
	{ ClkLtSymbol,		0,		Button1,	setlayout,		{0} },
	{ ClkLtSymbol,		0,		Button3,	setlayout,		{.v = &layouts[2]} },
	{ ClkWinTitle,		0,		Button1,	togglewin,		{0} },
	{ ClkWinTitle,		0,		Button3,	showhideclient,	{0} },
	{ ClkWinTitle,		0,		Button2,	zoom,			{0} },
	{ ClkStatusText,	0,		Button1,	sigstatusbar,	{.i = 1 } },
	{ ClkStatusText,	0,		Button2,	sigstatusbar,	{.i = 2 } },
	{ ClkStatusText,	0,		Button3,	sigstatusbar,	{.i = 3 } },
	{ ClkStatusText,	0,		Button4,	sigstatusbar,	{.i = 4 } },
	{ ClkStatusText,	0,		Button5,	sigstatusbar,	{.i = 5 } },
	{ ClkClientWin,		MODKEY,	Button1,	movemouse,		{0} },
	{ ClkClientWin,		MODKEY,	Button2,	togglefloating, {0} },
	{ ClkClientWin,		MODKEY,	Button3,	resizemouse,	{0} },
	{ ClkTagBar,		0,		Button1,	view,			{0} },
	{ ClkTagBar,		0,		Button3,	toggleview,		{0} },
	{ ClkTagBar,		MODKEY,	Button1,	tag,			{0} },
	{ ClkTagBar,		MODKEY,	Button3,	toggletag,		{0} },
};

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signame> [<type> <value>]"` */
static const Signal signals[] = {
	/* signum                    function */
	{ "focusstack",              focusstack },
	{ "setmfact",                setmfact },
	{ "togglebar",               togglebar },
	{ "incnmaster",              incnmaster },
	{ "togglefloating",          togglefloating },
	{ "focusmon",                focusmon },
	{ "floatpos",                floatpos },
	{ "viewtoleft",              viewtoleft },
	{ "viewtoright",             viewtoright },
	{ "tagtoleft",               tagtoleft },
	{ "tagtoright",              tagtoright},
	{ "tagandviewtoleft",        tagandviewtoleft },
	{ "tagandviewtoright",       tagandviewtoright },
	{ "rotatestack",             rotatestack },
	{ "setcfact",                setcfact },
	{ "tagmon",                  tagmon },
	{ "zoom",                    zoom },
	{ "incrgaps",                incrgaps },
	{ "incrigaps",               incrigaps },
	{ "incrogaps",               incrogaps },
	{ "incrihgaps",              incrihgaps },
	{ "incrivgaps",              incrivgaps },
	{ "incrohgaps",              incrohgaps },
	{ "incrovgaps",              incrovgaps },
	{ "togglegaps",              togglegaps },
	{ "defaultgaps",             defaultgaps },
	{ "setgaps",                 setgapsex },
	{ "view",                    view },
	{ "viewall",                 viewallex },
	{ "viewex",                  viewex },
	{ "toggleview",              toggleview },
	{ "showhideclient",          showhideclient },
	{ "togglesticky",            togglesticky },
	{ "cyclelayout",             cyclelayout },
	{ "toggleviewex",            toggleviewex },
	{ "tag",                     tag },
	{ "tagall",                  tagallex },
	{ "tagex",                   tagex },
	{ "toggletag",               toggletag },
	{ "toggletagex",             toggletagex },
	{ "togglefullscreen",        togglefullscreen },
	{ "killclient",              killclient },
	{ "xrdb",                    xrdb },
	{ "quit",                    quit },
	{ "setlayout",               setlayout },
	{ "setlayoutex",             setlayoutex },
};

