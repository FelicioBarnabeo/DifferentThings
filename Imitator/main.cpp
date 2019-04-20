#include <QApplication>
#include <QQmlApplicationEngine>
#include "listmodel.h"
#include <QObject>
#include <QDebug>
#include "stdio.h"
#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQmlContext *eng = engine.rootContext();

    ListMod dataModel;
    eng->setContextProperty("dataModel",&dataModel);
    //QObject::connect();
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();


//    QCoreApplication a(argc,argv);
//    QVector<quint8> word = geoValueToArincWord(ArincCodeMessage::alt, 1000);
//    printf("вывод: %x %x %x %x\n",word[0],word[1],word[2],word[3]);
//    word = geoValueToArincWord(ArincCodeMessage::grinvichTime, QTime(3,30,1));
//    printf("вывод: %x %x %x %x\n",word[0],word[1],word[2],word[3]);
//    //if(QDate::isValid())
//    word = geoValueToArincWord(ArincCodeMessage::date,QDate(2016,2,20));
//    printf("вывод: %x %x %x %x\n",word[0],word[1],word[2],word[3]);
//    std::cout.flush();
    //qDebug()<<" "<<word[0]<<" "<<word[1]<<" "<<word[2];
    //qDebug()<<word;
    /*Arinc obj;
    MyThread somethread ;
    QTimer *ptimer = new QTimer(0);
    ptimer->setInterval(1);
    ptimer->moveToThread(&somethread);
    //obj.moveToThread(somethread);
    QObject::connect(&somethread,SIGNAL(started()),ptimer,SLOT(start()));
    QObject::connect(ptimer,SIGNAL(timeout()),&obj,SLOT(checkFifo()),Qt::QueuedConnection);
    QObject::connect(&obj,SIGNAL(MessageReceived()),&obj,SLOT(parseWord()),Qt::QueuedConnection);
    somethread.start();
    //ptimer->stop();
    //delete ptimer;*/
    //return a.exec();

}
