#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "myapplication.h"
#include "powersupply.h"
#include <QQmlContext>
#include "lirc.h"
#include <QWindow>
#include <QScreen>

int main(int argc, char *argv[])
{

//    QFile logFile("logfile.txt");
//    logFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);
//    QTextStream out(&logFile);
//    try{
        qDebug() << "VERSION AN72 02.11.18";

        MyApplication app(argc, argv);
        LircSingleton *driver = LircSingleton::Instance();
        app.getEngine().rootContext()->setContextProperty("mainApp",&app);
        app.getEngine().rootContext()->setContextProperty("batteryClass",app.getBattery());
        app.getEngine().rootContext()->setContextProperty("driver",driver);
        app.getEngine().load(QUrl(QStringLiteral("qrc:/main.qml")));
        return app.exec();
//    }

//    catch(std::exception &e)
//    {
//        out << Q_FUNC_INFO <<  "Exception [" << e.what() << "]. Terminated.";
//        qDebug() << Q_FUNC_INFO <<  "Exception [" << e.what() << "]. Terminated.";
//    }
//    catch(...)
//    {
//        out << Q_FUNC_INFO << "Undefined error . Terminated";
//        qDebug()<< Q_FUNC_INFO << "Undefined error . Terminated";
//    }
    //logFile.close();
    //return 1;
}

