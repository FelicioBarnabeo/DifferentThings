TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += std=c99

SOURCES += \
    qt_spidev.c

TARGET = qt_spidev
    target.files  = qt_spidev
    target.path = /home
INSTALLS += target

include(deployment.pri)
qtcAddDeployment()

