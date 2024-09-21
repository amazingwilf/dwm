static const char col_black[]			= "#000000";
static const char col_gray1[]			= "#101010";
static const char col_gray2[]			= "#48489e";
static const char col_gray3[]			= "#acada1";
static const char col_gray4[]			= "#cfd0c2";
static const char col_red[]				= "#dc2966";
static const char col_green[]			= "#8fc029";
static const char col_yellow[]			= "#d4c96e";
static const char col_blue[]			= "#55bcce";
static const char col_magenta[]			= "#9358fe";
static const char col_cyan[]			= "#56b7a5";
static const char col_dblue[]			= "#0101a1";
static const char col_dred[]			= "#aa0101";
static const char *colors[][4]			= {
	/*						fg				bg			border		float		*/
	[SchemeNorm] 		= { col_gray3,		col_gray1, 	col_gray2, 	col_gray2	},
	[SchemeSel]			= { col_gray4,		col_gray1, 	col_blue,	col_green	},
	[SchemeSticky] 		= { col_gray3,		col_gray1, 	col_yellow,	col_yellow },
	[SchemeScratchNorm]	= { col_gray3,		col_gray1, 	col_gray2, 	col_gray2	},
	[SchemeScratchSel]	= { col_gray4,		col_gray1, 	col_cyan,	col_cyan	},
	[SchemeStButton]	= { col_blue,		col_dred,	col_black, 	col_black	},
	[SchemeLtSymbol]	= { col_magenta,	col_gray1, 	col_black, 	col_black	},
	[SchemeTagsEmpty] 	= { col_gray2,		col_gray1, 	col_black, 	col_black	},
	[SchemeTagsOcc] 	= { col_gray3,		col_gray1, 	col_black, 	col_black	},
	[SchemeTagsSel] 	= { col_gray4,		col_dblue,	col_black, 	col_black	},
};

static const unsigned int baralpha		= 0xf0;
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
	[SchemeTagsSel] 	= { OPAQUE, OPAQUE,	  borderalpha, borderalpha },
};

