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
    command.cpp \
    serialdevice.cpp \
    mytabledelegate.cpp \
    myvalidator.cpp \
    standarttablemodel.cpp \
    commandwidget.cpp \
    commandlistmodel.cpp \
    dialogserialportconfig.cpp \
    dialogcommandeditor.cpp \
    ioserialmanager.cpp \
    centralwidget.cpp \
    settings.cpp \
    mytextedit.cpp

HEADERS  += mainwindow.h \
    command.h \
    serialdevice.h \
    mytabledelegate.h \
    myvalidator.h \
    standarttablemodel.h \
    commandwidget.h \
    commandlistmodel.h \
    dialogserialportconfig.h \
    dialogcommandeditor.h \
    ioserialmanager.h \
    centralwidget.h \
    settings.h \
    mytextedit.h

