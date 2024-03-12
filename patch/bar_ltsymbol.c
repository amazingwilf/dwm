int
width_ltsymbol(Bar *bar, BarArg *a)
{
	return TEXTW(bar->mon->ltsymbol);
}

int
draw_ltsymbol(Bar *bar, BarArg *a)
{
	Fnt *cur;
	cur = drw->fonts;
	drw->fonts = drw->fonts->next;
 	drw_setscheme(drw, scheme[SchemeLtSymbol]);
	drw_text(drw, a->x, a->y, a->w, a->h, lrpad / 2, bar->mon->ltsymbol, 0, False);
	drw->fonts = cur; 
	return 0;
}

int
click_ltsymbol(Bar *bar, Arg *arg, BarArg *a)
{
	return ClkLtSymbol;
}

