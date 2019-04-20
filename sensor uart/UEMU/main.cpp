#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>

#include "uartreader.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setApplicationName("Extra-Damage");
    app.setApplicationVersion("1.2");
    app.setApplicationDisplayName("Extra-Damage");

    UartReader reader;


    if (QGuiApplication::arguments().count()<2) {
        qDebug()<<"specify a device";
        return (-1);
    }

    reader.setPortName(QGuiApplication::arguments().at(1));
    if (!reader.open(QIODevice::ReadOnly)) {
        qDebug()<<"can't open device";
        return (-1);
    }

    QQmlApplicationEngine engine;
    QQmlContext* ctx = engine.rootContext();
    reader.setQmlContext(ctx);
    ctx->setContextProperty("Devices",QVariant::fromValue(reader.serialDevices));
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
