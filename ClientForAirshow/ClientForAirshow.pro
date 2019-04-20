QT += core network
QT -= gui

CONFIG += qt c++11

TARGET = ClientForAirshow
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    airshowfilesmanager.cpp

HEADERS += \
    airshowfilesmanager.h
