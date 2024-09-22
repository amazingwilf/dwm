#!/usr/bin/env bash

killall -9 polkit-gnome-authentication-agent-1 dunst slstatus ksuperkey

/usr/libexec/polkit-gnome-authentication-agent-1 &
nitrogen --restore
ksuperkey -e 'Super_L=Alt_L|F1' &
dunst &
picom -b
slstatus &
