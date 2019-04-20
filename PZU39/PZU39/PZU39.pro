TEMPLATE = app

QT += qml quick serialport
CONFIG += c++11

SOURCES += main.cpp \
    settings.cpp \
    serialdevice.cpp \
    configurator.cpp \
    keypressevent.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    colordefiner.h \
    settings.h \
    serialdevice.h \
    configurator.h \
    keypressevent.h

lupdate_only{
SOURCES = *.qml
}


TRANSLATIONS = translations/ru.ts translations/en.ts
