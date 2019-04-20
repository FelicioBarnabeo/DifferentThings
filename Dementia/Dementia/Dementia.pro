TEMPLATE = app

QT += qml quick multimedia network

CONFIG += c++11 qtquickcompiler

SOURCES += main.cpp \
    settings.cpp \
    audiogenresmanager.cpp \
    audiofilesmanager.cpp \
    airshowfilesmanager.cpp \
    videofilesmanager.cpp \
    infofilesmanager.cpp \
    gamefilesmanager.cpp \
    rootmanager.cpp \
    helpfilesmanager.cpp \
    specfilesmanager.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    settings.h \
    audiogenresmanager.h \
    audiofilesmanager.h \
    airshowfilesmanager.h \
    videofilesmanager.h \
    infofilesmanager.h \
    gamefilesmanager.h \
    rootmanager.h \
    helpfilesmanager.h \
    backlighter.h \
    specfilesmanager.h

lupdate_only{
SOURCES = qml/*.qml \
          *.cpp
}

TRANSLATIONS = translations/ru.ts translations/en.ts
