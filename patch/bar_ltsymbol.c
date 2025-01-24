int
width_ltsymbol(Bar *bar, BarWidthArg *a)
{
	/*return TEXTW(bar->mon->ltsymbol);*/
	return 85;
}

int
draw_ltsymbol(Bar *bar, BarDrawArg *a)
{
	Fnt *cur;
	cur = drw->fonts;
	drw->fonts = drw->fonts->next; 
	drw->fonts = drw->fonts->next;
	drw_text(drw, a->x, 0, a->w, bh, lrpad / 2, bar->mon->ltsymbol, 0);
	drw->fonts = cur; 
	return 0;
}

int
click_ltsymbol(Bar *bar, Arg *arg, BarClickArg *a)
{
	return ClkLtSymbol;
}
