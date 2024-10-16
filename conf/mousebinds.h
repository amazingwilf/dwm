static const Button buttons[] = {
	/* click			event mask	button		function			argument */
	{ ClkButton,		0,			Button1,	spawn,				{.v = roficmd } },
	{ ClkLtSymbol,		0,			Button1,	setlayout,			{0} },
	{ ClkLtSymbol,		0,			Button3,	setlayout,			{.v = &layouts[2]} },
	{ ClkWinTitle,		0,			Button2,	zoom,				{0} },
	{ ClkStatusText,	0,			Button1,	sigstatusbar,		{.i = 1 } },
	{ ClkStatusText,	0,			Button2,	sigstatusbar,		{.i = 2 } },
	{ ClkStatusText,	0,			Button3,	sigstatusbar,		{.i = 3 } },
	{ ClkClientWin,		MODKEY,		Button1,	movemouse,			{0} },
	{ ClkClientWin,		MODKEY,		Button2,	togglefloating, 	{0} },
	{ ClkClientWin,		MODKEY,		Button3,	resizemouse,		{0} },
	{ ClkTagBar,		0,			Button1,	view,				{0} },
	{ ClkTagBar,		0,			Button3,	toggleview,			{0} },
	{ ClkTagBar,		MODKEY,		Button1,	tag,				{0} },
	{ ClkTagBar,		MODKEY,		Button3,	toggletag,			{0} },
};

