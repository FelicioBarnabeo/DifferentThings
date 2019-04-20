TEMPLATE = lib
TARGET = ColorSlider
QT += qml quick
CONFIG += qt plugin c++11

# Input
SOURCES += \
    colorslider_plugin.cpp \
    colordefiner.cpp

HEADERS += \
    colorslider_plugin.h \
    colordefiner.h

DISTFILES += ColorSlider.qml

DESTDIR = ColorSlider

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

pluginfiles.files += \
    qmldir \
    ColorSlider.qml \
    circle.png \

pluginfiles.path +=


qmldir.files = qmldir
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir pluginfiles
}

RESOURCES += qml.qrc
