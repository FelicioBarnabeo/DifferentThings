#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "colordefiner.h"
#include "settings.h"
#include "serialdevice.h"
#include "configurator.h"
#include "keypressevent.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    KeyPressEvent key_handler;
    QQmlApplicationEngine engine;
    Settings *settings   = Settings::instance();
    Configurator *config = Configurator::instance();
    SerialDevice *device = new SerialDevice();
    settings->askMsopState(device);
    //settings->askBPLanguage(device);
    settings->askBPVolume(device);
    ColorDefiner colorWheelDefiner(":/images/ColorWheel/circle.png",160,160);
    engine.rootContext()->setContextProperty("Settings", settings);
    engine.rootContext()->setContextProperty("Configurator", config);
    engine.rootContext()->setContextProperty("ColorDefiner",&colorWheelDefiner);
    engine.rootContext()->setContextProperty("SerialDevice",device);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    app.installEventFilter(&key_handler);
    return app.exec();
}
