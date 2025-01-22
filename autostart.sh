#!/usr/bin/env bash

killall -9 polkit-gnome-authentication-agent-1 picom slstatus

xrandr -s 1920x1080
/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1 &
feh --bg-fill /usr/share/backgrounds/planets.jpg
picom -b
slstatus &

