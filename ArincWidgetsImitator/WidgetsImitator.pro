#-------------------------------------------------
#
# Project created by QtCreator 2016-02-24T10:37:51
#
#-------------------------------------------------

QT       += core gui sql network websockets
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET +=
    target.files = WidgetsImitator
    target.path = /home

INSTALLS += target


TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    geodata.cpp \
    spidriver.cpp \
    consolewidget.cpp \
    arincword.cpp \
    servervss.cpp \
    emulatorreader.cpp

HEADERS  += mainwindow.h \
    geodata.h \
    spidriver.h \
    consolewidget.h \
    arincword.h \
    servervss.h \
    emulatorreader.h

FORMS    += mainwindow.ui

DISTFILES += \
    MyStyle.qss
