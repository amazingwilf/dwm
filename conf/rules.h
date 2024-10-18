static const Rule rules[] = {
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	RULE(.class = "Lxappearance", .isfloating = 1, .iscentered = 1)
	RULE(.class = "Firefox", .tags = 1 << 1)
	RULE(.class = "Thunar", .tags = 1 << 2)
	RULE(.instance = "spterm", .scratchkey = 't', .isfloating = 1, .floatpos = "50% 50% 80% 80%" )
};

