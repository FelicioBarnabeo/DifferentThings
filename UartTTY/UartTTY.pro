QT += core
QT -= gui

CONFIG += c++11

TARGET = UartTTY
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    mtermios.cpp

HEADERS += \
    mtermios.h
