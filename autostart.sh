#!/usr/bin/env bash

killall -9 polkit-gnome-authentication-agent-1 dunst slstatus

/usr/libexec/polkit-gnome-authentication-agent-1 &
nitrogen --restore
dunst &
picom -b
slstatus &
