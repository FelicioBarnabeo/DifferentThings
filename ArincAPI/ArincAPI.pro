TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11
QT     += core
QT     -= gui

SOURCES += \
    ArincAPI.cpp \
    arinc.cpp \
    mythread.cpp \
    loginterface.cpp \
    spidevdriver.cpp


TARGET +=
    target.files = ArincAPI
    target.path  = /home

INSTALLS += target

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    arinc.h \
    mythread.h \
    loginterface.h \
    constants.h \
    spidevdriver.h

