/* See LICENSE file for copyright and license details. */

#define SESSION_FILE "/tmp/dwm-session"

/* appearance */
static const unsigned int borderpx	= 3;
static const unsigned int snap		= 32;

static const unsigned int gappih	= 20;       
static const unsigned int gappiv	= 10;      
static const unsigned int gappoh	= 10;     
static const unsigned int gappov	= 30;    
static int smartgaps				= 0;

static const int showbar			= 0;
static const int topbar				= 1;
static const int user_bh            = 0;
#define ICONSIZE (bh - 10)
#define ICONSPACING 10

static const char *fonts[]			= { "JetBrainsMono Nerd Font:style=ExtraBold:size=22",
										"NotoSans Nerd Font:size=22",
										"JetBrainsMono Nerd Font:style=ExtraBold:size=18"
									};

#include "colors.h"
static const char *colors[][3]		= {
	/*						fg			bg			border	*/
	[SchemeNorm] 		= { gray4,		black, 		gray2  },
	[SchemeSel]			= { white, 		gray3,		blue   },
	[SchemeFloat]		= { white, 		gray3,		purple },
	[SchemeSticky]		= { white, 		gray3,		yellow },
	[SchemeScratchpad]	= { white, 		gray3,		green  },
	[SchemeTagsNorm]	= { gray2, 		black,		black  },
	[SchemeTagsSel]		= { white, 		black,		black  },
	[SchemeLtSymbol]	= { yellow, 	black,		black  },
	[SchemeTitle]		= { gray4, 		black,		black  },

	[SchemeTag1]		= { blue,		black,		black  },
	[SchemeTag2]		= { red,		black,		black  },
	[SchemeTag3]		= { green,		black,		black  },
	[SchemeTag4]		= { orange,		black,		black  },
	[SchemeTag5]		= { purple,		black,		black  },
	[SchemeTag6]		= { yellow,		black,		black  },
	[SchemeTag7]		= { pink,		black,		black  },
	[SchemeTag8]		= { cyan,		black,		black  },
};

static const int tagschemes[] 	= { SchemeTag1, SchemeTag2, SchemeTag3, SchemeTag4, 
									SchemeTag5, SchemeTag6, SchemeTag7, SchemeTag8 };

static const unsigned int baralpha		= 0x10;
static const unsigned int borderalpha	= OPAQUE;

static const unsigned int alphas[][3]      = {
    /*						fg		bg			border*/
	[SchemeNorm]		= { OPAQUE,	baralpha,	borderalpha },
	[SchemeSel]			= { OPAQUE,	baralpha,	borderalpha },
	[SchemeFloat]		= { OPAQUE,	baralpha,	borderalpha },
	[SchemeScratchpad]	= { OPAQUE,	baralpha,	borderalpha },
	[SchemeTagsNorm]	= { OPAQUE,	baralpha,	borderalpha },
	[SchemeTagsSel]		= { OPAQUE,	baralpha,	borderalpha },
	[SchemeLtSymbol]	= { OPAQUE,	baralpha,	borderalpha },
	[SchemeTitle]		= { OPAQUE,	baralpha,	borderalpha },

	[SchemeTag1]		= { OPAQUE,	baralpha,	borderalpha },
	[SchemeTag2]		= { OPAQUE,	baralpha,	borderalpha },
	[SchemeTag3]		= { OPAQUE,	baralpha,	borderalpha },
	[SchemeTag4]		= { OPAQUE,	baralpha,	borderalpha },
	[SchemeTag5]		= { OPAQUE,	baralpha,	borderalpha },
	[SchemeTag6]		= { OPAQUE,	baralpha,	borderalpha },
	[SchemeTag7]		= { OPAQUE,	baralpha,	borderalpha },
	[SchemeTag8]		= { OPAQUE,	baralpha,	borderalpha },
};

static const char *const autostart[] = {
	"/usr/libexec/polkit-gnome-authentication-agent-1", NULL,
	"feh", "--bg-fill", "/usr/share/backgrounds/void2.png", NULL,
	"picom", "-b", NULL,
	"slstatus", NULL,
	NULL /* terminate */
};

/* tagging */
/* static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8" }; */
static char *tags[] = {"", "", "", "", "", "", "", ""};

static const unsigned int ulinepad		= 5;
static const unsigned int ulinestroke	= 1;
static const unsigned int ulinevoffset	= 0;
static const int ulineall 				= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
	{ .class = "Lxappearance", .isfloating = 1, .floatpos = "50% 50% -1h -1w" },
	{ .class = "Alacritty", .tags = 1 << 0 },
	{ .class = "Firefox", .tags = 1 << 1 },
	{ .class = "Thunar", .tags = 1 << 2 },
	{ .class = "spterm", .isfloating = 1, .scratchkey = 't', .floatpos = "50% 50% 80% 80%" },
	{ .class = "Alacritty", .isterminal = 1 },
	{ .title = "Event Tester", .noswallow = 1 },
};

/* layout(s) */
static const float mfact     		= 0.50;
static const int nmaster     		= 1; 
static const int resizehints 		= 0; 
static const int lockfullscreen 	= 1; 
static int floatposgrid_x           = 5; 
static int floatposgrid_y           = 5; 
static const char *toggle_float_pos	= "50% 50% 80% 80%";
static const int swallowfloating	= 0; 


#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "  []=",      tile },
	{ "  ><>",      NULL },
	{ "  [M]",      monocle },
	{ "  [@]",      spiral },
	{ "  [\\]",     dwindle },
	{ "  H[]",      deck },
	{ "  TTT",      bstack },
	{ "  ===",      bstackhoriz },
	{ "  HHH",      grid },
	{ "  ###",      nrowgrid },
	{ "  ---",      horizgrid },
	{ "  :::",      gaplessgrid },
	{ "  |M|",      centeredmaster },
	{ "  >M>",      centeredfloatingmaster },
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
static const char *termcmd[]	= { "alacritty", NULL };
static const char *roficmd[]	= { "rofi", "-show", "drun", NULL };
static const char *ffcmd[]		= { "firefox", NULL };

static const char *mutevol[] 			= { "volume", "--toggle",  NULL };
static const char *mutemic[] 			= { "volume", "--toggle-mic",  NULL };
static const char *upvol[]   			= { "volume", "--inc", NULL };
static const char *downvol[] 			= { "volume", "--dec", NULL };
static const char *upbl[] 				= { "brightness", "--inc", NULL };
static const char *downbl[] 			= { "brightness", "--dec", NULL };

static const char *sptermcmd[] 	= { "t", "alacritty", "--class", "spterm,spterm", NULL};

#include <X11/XF86keysym.h>
static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_space,  spawn,          {.v = roficmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_w,      spawn,          {.v = ffcmd } },
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
	{ MODKEY,                       XK_bracketright,      incrgaps,       {.i = +1 } },
	{ MODKEY,                       XK_bracketleft,      incrgaps,       {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_bracketleft,      togglegaps,     {0} },
	{ MODKEY|ShiftMask,    			XK_bracketright,      defaultgaps,    {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ShiftMask,             XK_r,      quit,           {1} }, 
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_b,      setlayout,      {.v = &layouts[6]} },
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[11]} },
	{ MODKEY,	                	XK_comma,  cyclelayout,    {.i = -1 } },
	{ MODKEY,                       XK_period, cyclelayout,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_grave,  togglescratch,  {.v = sptermcmd } },
	{ MODKEY|ShiftMask,             XK_s,      togglesticky,   {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_Left,   viewtoleft,     {0} },
	{ MODKEY,                       XK_Right,  viewtoright,    {0} }, 
	{ MODKEY|ShiftMask,             XK_Left,   tagandviewtoleft,   {0} },
	{ MODKEY|ShiftMask,             XK_Right,  tagandviewtoright,  {0} }, 
	{ MODKEY|ControlMask,           XK_Left,   tagtoleft,          {0} }, 
	{ MODKEY|ControlMask,           XK_Right,  tagtoright,         {0} }, 
	{ 0, 						XF86XK_AudioMute, 			spawn, {.v = mutevol } },
	{ 0, 						XF86XK_AudioMicMute, 		spawn, {.v = mutemic } },
	{ 0, 						XF86XK_AudioLowerVolume, 	spawn, {.v = downvol } },
	{ 0, 						XF86XK_AudioRaiseVolume, 	spawn, {.v = upvol   } },
	{ 0, 						XF86XK_MonBrightnessUp, 	spawn, {.v = upbl   } },
	{ 0, 						XF86XK_MonBrightnessDown, 	spawn, {.v = downbl   } },
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
