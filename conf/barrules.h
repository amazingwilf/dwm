static const BarRule barrules[] = {
	/* monitor		bar	alignment			widthfunc		drawfunc		clickfunc			hoverfunc	name */
	{ -1,			0,	BAR_ALIGN_LEFT,		width_stbutton,	draw_stbutton,	click_stbutton,		NULL,		"statusbutton" },
	{ -1,			0,	BAR_ALIGN_LEFT,		width_tags,		draw_tags,		click_tags,			hover_tags,	"tags" },
	{ -1,			0,	BAR_ALIGN_LEFT,		width_ltsymbol,	draw_ltsymbol,	click_ltsymbol,		NULL,		"layout" },
	{ statusmon,	0,	BAR_ALIGN_RIGHT,	width_status2d,	draw_status2d,	click_statuscmd,	NULL,		"status2d" },
	{ -1,			0,	BAR_ALIGN_NONE,		width_wintitle,	draw_wintitle,	click_wintitle,		NULL,		"wintitle" },
};

