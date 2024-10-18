static const float mfact				= 0.50; 
static const int nmaster				= 1;
static const int resizehints 			= 0;
static const int lockfullscreen 		= 1;
static const char *toggle_float_pos		= "50% 50% 80% 80%";
static const int swallowfloating		= 0;

static const Layout layouts[] = {
	/* symbol	arrange function */
	{ "[]=",	tile },	
	{ "><>",	NULL },	
	{ "[M]",	monocle },
	{ "TTT",	bstack },
	{ "|M|",	centeredmaster },
	{ "[D]",	deck },
	{ ":::",	gaplessgrid },
};

