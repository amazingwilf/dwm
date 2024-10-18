#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,						KEY,	view,		{.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,			KEY,	toggleview,	{.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,				KEY,	tag,		{.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask,	KEY,	toggletag,	{.ui = 1 << TAG} },

#include <X11/XF86keysym.h>
static const Key keys[] = {
	/* modifier				key							function			argument */
	{ MODKEY, 				XK_Return,					spawn,				{.v = termcmd } },
	{ MODKEY, 				XK_space,					spawn,				{.v = roficmd } },
	{ MODKEY, 				XK_w,						spawn,				{.v = webcmd } },
	{ MODKEY, 				XK_e,						spawn,				{.v = fmcmd } },
	{ MODKEY,				XK_grave,					togglescratch,		{.v = sptermcmd } },

	{ 0,					XF86XK_AudioMute,			spawn,				{.v = volmute } },
	{ 0,					XF86XK_AudioMicMute,		spawn,				{.v = micmute } },
	{ 0,					XF86XK_AudioLowerVolume,	spawn,				{.v = voldown } },
	{ 0,					XF86XK_AudioRaiseVolume,	spawn,				{.v = volup } },
	{ 0,					XF86XK_MonBrightnessUp,		spawn,				{.v = blup } },
	{ 0,					XF86XK_MonBrightnessDown,	spawn,				{.v = bldown } },

	{ MODKEY,				XK_j,						focusstack,			{.i = +1 } },
	{ MODKEY,				XK_k,						focusstack,			{.i = -1 } },
	{ MODKEY|ShiftMask,		XK_j,						rotatestack,		{.i = +1 } },
	{ MODKEY|ShiftMask,		XK_k,						rotatestack,		{.i = -1 } },
	{ MODKEY,				XK_i,						incnmaster,			{.i = +1 } },
	{ MODKEY,				XK_u,						incnmaster,			{.i = -1 } },
	{ MODKEY,				XK_h,						setmfact,			{.f = -0.05} },
	{ MODKEY,				XK_l,						setmfact,			{.f = +0.05} },
	{ MODKEY|ShiftMask,		XK_h,						setcfact,			{.f = +0.25} },
	{ MODKEY|ShiftMask,		XK_l,						setcfact,			{.f = -0.25} },
	{ MODKEY|ShiftMask,		XK_o,						setcfact,			{0} },

	{ MODKEY,				XK_equal,					incrgaps,			{.i = +1 } },
	{ MODKEY,				XK_minus,					incrgaps,			{.i = -1 } },
	{ MODKEY|ShiftMask,		XK_g,						togglegaps,			{0} },
	{ MODKEY|ControlMask,	XK_g,						defaultgaps,		{0} },

	{ MODKEY,				XK_q,						killclient,			{0} },
	{ MODKEY|ShiftMask,		XK_q,						quit,				{0} },
	{ MODKEY|ShiftMask, 	XK_r,						quit,				{1} },

	{ MODKEY,				XK_t,						setlayout,			{.v = &layouts[0]} },
	{ MODKEY,				XK_f,						setlayout,			{.v = &layouts[1]} },
	{ MODKEY,				XK_m,						setlayout,			{.v = &layouts[2]} },
	{ MODKEY,				XK_b,						setlayout,			{.v = &layouts[3]} },
	{ MODKEY,				XK_c,						setlayout,			{.v = &layouts[4]} },
	{ MODKEY,				XK_d,						setlayout,			{.v = &layouts[5]} },
	{ MODKEY,				XK_g,						setlayout,			{.v = &layouts[6]} },
	{ MODKEY,				XK_comma,					cyclelayout,		{.i = -1 } },
	{ MODKEY,				XK_period,					cyclelayout,		{.i = +1 } },

	{ MODKEY|ShiftMask,		XK_b,						togglebar,			{0} },
	{ MODKEY|ShiftMask,		XK_space,					togglefloating,		{0} },
	{ MODKEY|ShiftMask,		XK_f,						togglefullscreen,	{0} },
	{ MODKEY|ShiftMask,		XK_s,						togglesticky,		{0} },
	{ MODKEY|ShiftMask,		XK_x,						xrdb,				{.v = NULL } },

	{ MODKEY,				XK_0,						view,				{.ui = ~0 } },
	{ MODKEY|ShiftMask,		XK_0,						tag,				{.ui = ~0 } },
	{ MODKEY,				XK_Left,					viewtoleft,			{0} }, 
	{ MODKEY,				XK_Right,					viewtoright,		{0} }, 
	{ MODKEY|ShiftMask,		XK_Left,					tagandviewtoleft,	{0} }, 
	{ MODKEY|ShiftMask,		XK_Right,					tagandviewtoright,	{0} }, 
	{ MODKEY|ControlMask,	XK_Left,					tagtoleft,			{0} }, 
	{ MODKEY|ControlMask,	XK_Right,					tagtoright,			{0} }, 

	TAGKEYS(				XK_1,											0)
	TAGKEYS(				XK_2,											1)
	TAGKEYS(				XK_3,											2)
	TAGKEYS(				XK_4,											3)
	TAGKEYS(				XK_5,											4)
	TAGKEYS(				XK_6,											5)
};

