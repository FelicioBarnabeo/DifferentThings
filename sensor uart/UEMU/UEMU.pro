TEMPLATE = app

QT += qml quick serialport

SOURCES += main.cpp \
    device.cpp \
    uartreader.cpp

RESOURCES += qml.qrc

CONFIG += c++11

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    device.h \
    uartreader.h
