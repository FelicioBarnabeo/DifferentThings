TEMPLATE = app

QT += qml quick widgets
CONFIG += c++11
CONFIG -= console #delete
CONFIG += app_bundle#delete
QT     += core#delete
QT     += gui#delete

SOURCES += main.cpp \
    spidriver.cpp \
    listmodel.cpp \
    geodata.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    spidriver.h \
    listmodel.h \
    geodata.h
