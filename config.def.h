/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;
static const unsigned int snap      = 32;
static int floatposgrid_x           = 5; 
static int floatposgrid_y           = 5;
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const char *toggle_float_pos = "50% 50% 80% 80%"; 

static const unsigned int gappih = 10; 
static const unsigned int gappiv = 10;
static const unsigned int gappoh = 20;
static const unsigned int gappov = 20;
static int smartgaps             = 0; 

static const int showbar = 1;
static const int topbar  = 1;
static const int user_bh = 12;

#define ICONSIZE (bh - 12)
#define ICONSPACING 8

static const char *fonts[] = { "DWM Layout Glyphs:style=Medium:size=16",
                               "NotoSans Nerd Font:size=12" };

#include "colors.h"

static const char *colors[][3] = {
	/*                      fg      bg     border   */
	[SchemeNorm]        = { gray4,  black, gray2 },
	[SchemeSel]         = { white,  black, blue },
	[SchemeFloat]       = { NULL,   NULL,  pink },
	[SchemeTagEmpty]    = { gray3,  black, NULL },
	[SchemeTagSel]      = { white,  black, NULL },
    [SchemeTag1]        = { blue,   black, NULL },
    [SchemeTag2]        = { red,    black, NULL },
    [SchemeTag3]        = { green,  black, NULL },
    [SchemeTag4]        = { orange, black, NULL },
    [SchemeTag5]        = { purple, black, NULL },
    [SchemeTag6]        = { pink,   black, NULL },
	[SchemeLtSym]       = { yellow, black, NULL },
	[SchemeScratchNorm] = { NULL,   NULL,  gray2 },
	[SchemeScratchSel]  = { NULL,   NULL,  green },
	[SchemeSticky]      = { NULL,   NULL,  red },
};

static const int tagschemes[] = { SchemeTag1, SchemeTag2, SchemeTag3,
                                  SchemeTag4, SchemeTag5, SchemeTag6 };

static const char *const autostart[] = {
	"/usr/lib/xfce-polkit/xfce-polkit", NULL,
	"nitrogen", "--restore", NULL,
	"dunst", NULL,
	"superkeys", NULL,
	"autolock", NULL,
	"picom", "-b", NULL,
	"dwmblocks", NULL,
	NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6" };

static const unsigned int ulinepad		= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall				= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	{ .class = "Nwg-look", .isfloating = 1, .floatpos = "50% 50% -1h -1w" },
	{ .class = "firefox", .tags = 1 << 1 },
	{ .class = "com.mitchellh.ghostty", .isterminal = 1 },
	{ .title = "Event Tester", .noswallow = 1, .isfloating = 1 },
	{ .instance = "spterm", .scratchkey = 't', .isfloating = 1, .floatpos = "50% 50% 80% 80%" },
};

/* layout(s) */
static const float mfact        = 0.50;
static const int nmaster        = 1;
static const int resizehints    = 0;
static const int lockfullscreen = 1; 
static const int refreshrate    = 120; 

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "\ue000", tile },
	{ "\ue001", monocle },
	{ "\ue00c", bstack },
	{ "\ue00a", gaplessgrid },
	{ "\ue006", centeredmaster },
	{ NULL,     NULL },
};

/* key definitions */
#define MOD Mod4Mask
#define ALT Mod1Mask
#define SHIFT ShiftMask
#define CTRL ControlMask

#define TAGKEYS(KEY,TAG) \
	{ MOD,             KEY,      view,           {.ui = 1 << TAG} }, \
	{ MOD|CTRL,        KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MOD|SHIFT,       KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MOD|CTRL|SHIFT,  KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "dwmblocks"

/* commands */
static const char *termcmd[]  = { "ghostty", NULL };
static const char *roficmd[]  = { "rofi", "-show", "drun", "-kb-cancel", "Alt-F1", NULL };
static const char *webcmd[]   = { "firefox", NULL };
static const char *lockcmd[]  = { "betterlockscreen", "-l", NULL };

#include <X11/XF86keysym.h>
static const char *mutevol[]  = { "volume", "--toggle", NULL };
static const char *mutemic[]  = { "volume", "--toggle-mic", NULL };
static const char *upvol[]    = { "volume", "--inc", NULL };
static const char *downvol[]  = { "volume", "--dec", NULL };
static const char *upbl[]     = { "brightness", "--inc", NULL };
static const char *downbl[]   = { "brightness", "--dec", NULL };

static const char *sptermcmd[] = { "t", "ghostty", "--x11-instance-name=spterm", "--title=Scratchpad", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ ALT,            XK_F1,                     spawn,          {.v = roficmd } },
	{ MOD,            XK_Return,                 spawn,          {.v = termcmd } },
	{ MOD,            XK_w,                      spawn,          {.v = webcmd } },
	{ CTRL|ALT,       XK_l,                      spawn,          {.v = lockcmd } },
	{ 0,              XF86XK_AudioMute,          spawn,          {.v = mutevol } },
	{ 0,              XF86XK_AudioMicMute,       spawn,          {.v = mutemic } },
	{ 0,              XF86XK_AudioLowerVolume,   spawn,          {.v = downvol } },
	{ 0,              XF86XK_AudioRaiseVolume,   spawn,          {.v = upvol } },
	{ 0,              XF86XK_MonBrightnessUp,    spawn,          {.v = upbl } },
	{ 0,              XF86XK_MonBrightnessDown,  spawn,          {.v = downbl } },
	{ MOD,            XK_j,                      focusstack,     {.i = +1 } },
	{ MOD,            XK_k,                      focusstack,     {.i = -1 } },
	{ MOD,            XK_i,                      incnmaster,     {.i = +1 } },
	{ MOD,            XK_d,                      incnmaster,     {.i = -1 } },
	{ MOD,            XK_h,                      setmfact,       {.f = -0.05} },
	{ MOD,            XK_l,                      setmfact,       {.f = +0.05} },
	{ MOD|SHIFT,      XK_h,                      setcfact,       {.f = +0.25} },
	{ MOD|SHIFT,      XK_l,                      setcfact,       {.f = -0.25} },
	{ MOD|SHIFT,      XK_o,                      setcfact,       {.f =  0.00} },
	{ MOD,            XK_q,                      killclient,     {0} },
	{ MOD|SHIFT,      XK_q,                      quit,           {0} },
	{ MOD,            XK_t,                      setlayout,      {.v = &layouts[0]} },
	{ MOD,            XK_m,                      setlayout,      {.v = &layouts[1]} },
	{ MOD,            XK_b,                      setlayout,      {.v = &layouts[2]} },
	{ MOD,            XK_g,                      setlayout,      {.v = &layouts[3]} },
	{ MOD,            XK_c,                      setlayout,      {.v = &layouts[4]} },
	{ MOD,            XK_f,                      togglefullscr,  {0} },
	{ MOD,            XK_s,                      togglesticky,   {0} },
	{ MOD|SHIFT,      XK_b,                      togglebar,      {0} },
	{ MOD|SHIFT,      XK_space,                  togglefloating, {0} },
	{ MOD|SHIFT,      XK_g,                      togglegaps,     {0} },
	{ MOD,            XK_grave,                  togglescratch,  {.v = sptermcmd } },
	{ MOD,            XK_0,                      view,           {.ui = ~0 } },
	{ MOD|SHIFT,      XK_0,                      tag,            {.ui = ~0 } },
	{ MOD,            XK_Right,                  viewnext,       {0} },
	{ MOD,            XK_Left,                   viewprev,       {0} },
	{ MOD|SHIFT,      XK_Right,                  tagtonext,      {0} },
	{ MOD|SHIFT,      XK_Left,                   tagtoprev,      {0} },
	TAGKEYS(          XK_1,                                       0)
	TAGKEYS(          XK_2,                                       1)
	TAGKEYS(          XK_3,                                       2)
	TAGKEYS(          XK_4,                                       3)
	TAGKEYS(          XK_5,                                       4)
	TAGKEYS(          XK_6,                                       5)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click             event mask   button          function        argument */
	{ ClkLtSymbol,       0,           Button1,        setlayout,      {0} },
	{ ClkLtSymbol,       0,           Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,       0,           Button2,        zoom,           {0} },
	{ ClkStatusText,     0,           Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,     0,           Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,     0,           Button3,        sigstatusbar,   {.i = 3} },
	{ ClkStatusText,     0,           Button4,        sigstatusbar,   {.i = 4} },
	{ ClkStatusText,     0,           Button5,        sigstatusbar,   {.i = 5} },
	{ ClkClientWin,      MOD,         Button1,        movemouse,      {0} },
	{ ClkClientWin,      MOD,         Button2,        togglefloating, {0} },
	{ ClkClientWin,      MOD,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,         0,           Button1,        view,           {0} },
	{ ClkTagBar,         0,           Button3,        toggleview,     {0} },
	{ ClkTagBar,         MOD,         Button1,        tag,            {0} },
	{ ClkTagBar,         MOD,         Button3,        toggletag,      {0} },
};

