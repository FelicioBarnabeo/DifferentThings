#!/bin/sh
echo userspace > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
echo userspace > /sys/devices/system/cpu/cpu1/cpufreq/scaling_governor
echo 396000 > /sys/devices/system/cpu/cpu0/cpufreq/scaling_setspeed
echo 396000 > /sys/devices/system/cpu/cpu1/cpufreq/scaling_setspeed
echo 852000 > /sys/devices/system/cpu/cpu0/cpufreq/scaling_setspeed
echo 852000 > /sys/devices/system/cpu/cpu1/cpufreq/scaling_setspeed
