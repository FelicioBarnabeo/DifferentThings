TEMPLATE = app
TARGET = mpdu72
QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    myapplication.cpp \
    powersupply.cpp \
    lirc.cpp \
    keypressevent.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
#QML_IMPORT_PATH = "/home/mugen/Projects/build-MPDU_newGeneration-Desktop_Qt_5_10_0_GCC_64bit-Debug"

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    myapplication.h \
    powersupply.h \
    lirc.h \
    keypressevent.h

lupdate_only{
SOURCES = *.qml
}

#TRANSLATIONS = translations/ru.ts translations/en.ts
