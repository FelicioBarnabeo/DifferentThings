#!/bin/sh
echo 0 > /sys/class/graphics/fbcon/cursor_blink
fbset -left 60
#. /home/root/bq27.sh
. /home/root/optimize.sh
#. /home/root/powerSwitch.sh
. /home/root/runlirc.sh
cd /home/root && exec prog.sh

