TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    qtspi.c

TARGET +=
    target.files = qtspidev
    target.path  = /home

INSTALLS += target

include(deployment.pri)
qtcAddDeployment()

