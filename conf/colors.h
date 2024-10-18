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

static char tagsnormfgcolor[]			= "#444444";
static char tagsnormbgcolor[]			= "#222222";
static char tagsnormbordercolor[]		= "#000000";
static char tagsnormfloatcolor[]		= "#000000";

static char tagsoccfgcolor[]			= "#bbbbbb";
static char tagsoccbgcolor[]			= "#222222";
static char tagsoccbordercolor[]		= "#000000";
static char tagsoccfloatcolor[]			= "#000000";

static char tagsselfgcolor[]			= "#eeeeee";
static char tagsselbgcolor[]			= "#005577";
static char tagsselbordercolor[]		= "#000000";
static char tagsselfloatcolor[]			= "#000000";

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

static char ltsymbolfgcolor[]			= "#ffdd00";
static char ltsymbolbgcolor[]			= "#222222";
static char stbuttonfgcolor[]			= "#66aaee";
static char stbuttonbgcolor[]			= "#222222";

static char *colors[][ColCount] = {
	/*						fg					bg					border					float */
	[SchemeNorm]		= { normfgcolor,		normbgcolor,		normbordercolor,		normfloatcolor },
	[SchemeSel]			= { selfgcolor,			selbgcolor,			selbordercolor,			selfloatcolor },
	[SchemeTitleNorm]	= { titlenormfgcolor, 	titlenormbgcolor, 	titlenormbordercolor, 	titlenormfloatcolor },
	[SchemeTitleSel]	= { titleselfgcolor,	titleselbgcolor,	titleselbordercolor,	titleselfloatcolor },
	[SchemeTagsNorm]	= { tagsnormfgcolor,	tagsnormbgcolor,	tagsnormbordercolor,	tagsnormfloatcolor },
	[SchemeTagsOcc]		= { tagsoccfgcolor,		tagsoccbgcolor,		tagsoccbordercolor,		tagsoccfloatcolor },
	[SchemeTagsSel]		= { tagsselfgcolor,		tagsselbgcolor,		tagsselbordercolor,		tagsselfloatcolor },
	[SchemeUrg]			= { urgfgcolor,			urgbgcolor,			urgbordercolor,			urgfloatcolor },
	[SchemeScratchSel]	= { scratchselfgcolor, 	scratchselbgcolor, 	scratchselbordercolor, 	scratchselfloatcolor },
	[SchemeScratchNorm]	= { scratchnormfgcolor,	scratchnormbgcolor,	scratchnormbordercolor, scratchnormfloatcolor },
	[SchemeLtSymbol] 	= { ltsymbolfgcolor, 	ltsymbolbgcolor, 	"#000000", 				"#000000" },
	[SchemeStButton] 	= { stbuttonfgcolor, 	stbuttonbgcolor, 	"#000000", 				"#000000" },
};

/* alphas */
static const unsigned int baralpha 		= 0xd0;
static const unsigned int borderalpha 	= OPAQUE;

static const unsigned int alphas[][3] 	= {
	/*						fg	    bg	      border	*/
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
	[SchemeLtSymbol] 	= { OPAQUE, baralpha, borderalpha },
	[SchemeStButton] 	= { OPAQUE, baralpha, borderalpha },
};
