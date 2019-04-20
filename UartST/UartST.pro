#-------------------------------------------------
#
# Project created by QtCreator 2016-12-14T13:14:36
#
#-------------------------------------------------

QT       += widgets serialport
CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UartST
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    adddialog.cpp \
    senderwidget.cpp \
    command.cpp \
    serialdevice.cpp \
    mytabledelegate.cpp \
    myvalidator.cpp \
    pluginiowindow.cpp \
    standarttablemodel.cpp

HEADERS  += mainwindow.h \
    adddialog.h \
    senderwidget.h \
    command.h \
    serialdevice.h \
    mytabledelegate.h \
    myvalidator.h \
    pluginiowindow.h \
    standarttablemodel.h

