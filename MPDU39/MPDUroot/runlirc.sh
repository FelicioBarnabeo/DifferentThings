#!/bin/sh
rm -rf /var/run/lirc
mkdir /var/run/lirc
lircd -d /dev/lirc0 -H default /home/root/copyr1.lircd.conf
#modprobe lirc_wand
