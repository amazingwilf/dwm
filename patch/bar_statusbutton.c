int
width_stbutton(Bar *bar, BarArg *a)
{
	return TEXTW(buttonbar);
}

int
draw_stbutton(Bar *bar, BarArg *a)
{
	Fnt *cur;
	cur = drw->fonts;

	drw->fonts = drw->fonts->next; 
	drw->fonts = drw->fonts->next; 
	drw_setscheme(drw, scheme[SchemeHidSel]);
	drw_text(drw, a->x, a->y, a->w, a->h, lrpad / 2, buttonbar, 0, False);
	drw->fonts = cur; 
    return 0;
}

int
click_stbutton(Bar *bar, Arg *arg, BarArg *a)
{
	return ClkButton;
}

