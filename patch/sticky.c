void
togglesticky(const Arg *arg)
{
	if (!selmon->sel)
		return;
	Client *c = selmon->sel;
	selmon->sel->issticky = !selmon->sel->issticky;
	if (c->issticky)
		XSetWindowBorder(dpy, c->win, scheme[SchemeSticky][ColBorder].pixel);
	else
	if (c->isfloating)
		XSetWindowBorder(dpy, c->win, scheme[SchemeSel][ColFloat].pixel);
	else
		XSetWindowBorder(dpy, c->win, scheme[SchemeSel][ColBorder].pixel);
	arrange(selmon);
}

