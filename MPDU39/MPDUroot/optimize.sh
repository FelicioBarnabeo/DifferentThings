#!/bin/sh
echo 4 > /sys/devices/soc0/backlight_lcd.29/backlight/backlight_lcd.29/brightness
echo 5 > /proc/sys/vm/laptop_mode
echo 90 > /proc/sys/vm/dirty_ratio
modprobe -r ov5642_camera
echo 1 > /proc/sys/vm/dirty_background_ratio
echo 60000 > /proc/sys/vm/dirty_writeback_centisecs
