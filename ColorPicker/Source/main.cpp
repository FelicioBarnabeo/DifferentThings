#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "colordefiner.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    ColorDefiner colorWheel("circle.png",160,160);
    //colorWheel.makeColorWheelMapFile(2,10);
    engine.rootContext()->setContextProperty("ClrDef",&colorWheel);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));    
    return app.exec();
}
