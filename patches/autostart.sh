#!/usr/bin/env bash

# Export desktop session
export XDG_CURRENT_DESKTOP='dwm'

# polkit agent
if [[ ! `pidof xfce-polkit` ]]; then
	/usr/lib/xfce-polkit/xfce-polkit &
fi

# Enable Super Keys For Menu
if [[ ! `pidof ksuperkey` ]]; then
	ksuperkey -e 'Super_L=Alt_L|F1' &
	ksuperkey -e 'Super_R=Alt_L|F1' &
fi

# Restore wallpaper
nitrogen --restore

# Launch notification daemon
if [[ `pidof dunst` ]]; then
	pkill dunst
fi

dunst &

# Launch simple status bar


# Launch compositor
killall -q picom
while pgrep -u $UID -x picom >/dev/null; do sleep 1; done
picom  -b

# Start mpd
# exec mpd &

# Fix problems with Java apps
wmname "LG3D"
export _JAVA_AWT_WM_NONREPARENTING=1

