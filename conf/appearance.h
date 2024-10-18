/* general */
static const unsigned int borderpx		= 2;
static const unsigned int snap			= 32;
static const unsigned int gappih		= 20;

/* gaps */
static const unsigned int gappiv		= 20;
static const unsigned int gappoh		= 20;
static const unsigned int gappov		= 20;
static const int smartgaps_fact			= 1;

/* autostart */
static const char autostartblocksh[]	= "autostart_blocking.sh";
static const char autostartsh[]			= "autostart.sh";
static const char dwmdir[]				= "dwm";
static const char localshare[]			= ".local/share";

/* status bar */
#define STATUSBAR 						"dwmblocks"
#define ICONSIZE 						(bh - 18)
#define ICONSPACING 					10	
static const int showbar				= 1;
static const int topbar					= 1;
static const int vertpad				= 0;
static const int sidepad				= 0;
static const int focusonwheel			= 0;
static int floatposgrid_x				= 5;
static int floatposgrid_y				= 5;
static const int statusmon				= 'A';
static const int horizpadbar			= 2;
static const int vertpadbar				= 10;
static const char buttonbar[]			= " ";

/* indicators */
static int tagindicatortype				= INDICATOR_NONE;
static int tiledindicatortype			= INDICATOR_NONE;
static int floatindicatortype			= INDICATOR_TOP_LEFT_SQUARE;

/* fonts */
static const char *fonts[]				= { "Noto Sans:style=Medium:size=15",
											 "JetBrainsMono Nerd Font:style=ExtraBold:size=17",
											 "JetBrainsMono Nerd Font:size=18" };
/* tags */
static char *tagicons[][NUMTAGS] =
{
	[DEFAULT_TAGS]	= { "", "", "", "", "", "" },
};

