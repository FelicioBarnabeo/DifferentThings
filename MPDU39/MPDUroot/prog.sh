#echo 0 > /sys/class/graphics/fbcon/cursor_blink
#fbset -left 60
export QT_QPA_EVDEV_TOUCHSCREEN_PARAMETERS=rotate=270
#export QT_QPA_EGLFS_ROTATE=270=1
#export QT_EGLFS_IMX6_NO_FB_MULTI_BUFFER=1
/home/root/interface_mpdu --platform eglfs 
