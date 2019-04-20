#!/bin/sh
echo 111 > /sys/class/gpio/export  #(экспортирует для управления вывод управления режимом включения заряда)
echo out > /sys/class/gpio/gpio111/direction  #(настраивает данный вывод как выход)
echo 0 > /sys/class/gpio/gpio111/value  #(включает режим заряда АКБ и одновременно отключает выдачу питания в USB порт)

echo 9 > /sys/class/gpio/export   #(экспортирует вывод управления режимом переключения заряда 2А/500мА)
echo out > /sys/class/gpio/gpio9/direction  #(настраивает данный вывод как выход)
echo 0 > /sys/class/gpio/gpio9/value  #(переключает режим заряда АКБ на 2А) 
