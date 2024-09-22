static const char col_black[]			= "#000000";
static const char col_gray1[]			= "#1e2127";
static const char col_gray2[]			= "#5c6370";
static const char col_gray3[]			= "#cdcdcd";
static const char col_gray4[]			= "#ffffff";
static const char col_red[]				= "#e06c75";
static const char col_green[]			= "#98c379";
static const char col_yellow[]			= "#d19a55";
static const char col_blue[]			= "#61afef";
static const char col_magenta[]			= "#c678dd";
static const char col_cyan[]			= "#56b6c2";
static const char *colors[][4]			= {
	/*						fg				bg			border		float		*/
	[SchemeNorm] 		= { col_gray3,		col_gray1, 	col_gray2, 	col_gray2	},
	[SchemeSel]			= { col_gray4,		col_gray1, 	col_blue,	col_magenta	},
	[SchemeSticky] 		= { col_gray3,		col_gray1, 	col_yellow,	col_yellow  },
	[SchemeScratchNorm]	= { col_gray3,		col_gray1, 	col_gray2, 	col_gray2	},
	[SchemeScratchSel]	= { col_gray4,		col_gray1, 	col_cyan,	col_cyan	},
	[SchemeStButton]	= { col_blue,		col_gray1,	col_black, 	col_black	},
	[SchemeLtSymbol]	= { col_yellow,		col_gray1, 	col_black, 	col_black	},
	[SchemeTagsEmpty] 	= { col_gray2,		col_gray1, 	col_black, 	col_black	},
	[SchemeTagsOcc] 	= { col_gray3,		col_gray1, 	col_black, 	col_black	},
	[SchemeTagsSel] 	= { col_gray4,		col_gray1,	col_black, 	col_black	},
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

