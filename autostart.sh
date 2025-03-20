#!/usr/bin/env bash

export XDG_CURRENT_DESKTOP='dwm'

if [[ ! `pidof pipewire` ]]; then
	/usr/bin/pipewire &
fi

if [[ ! `pidof polkit-gnome-authentication-agent-1` ]]; then
	/usr/libexec/polkit-gnome-authenticationagent-1 &
fi

if [[ ! `pidof sxhkd` ]]; then
	sxhkd &
fi


nitrogen --restore

if [[ `pidof dunst` ]]; then
	pkill dunst
fi

dunst &

killall -q picom
while pgrep -u $UID -x picom >/dev/null; do sleep 1; done
picom -b

# if [[ `pidof slstatus` ]]; then
# 	pkill slstatus
# fi

# slstatus &
