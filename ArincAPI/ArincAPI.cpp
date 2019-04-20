#include <QCoreApplication>
#include "arinc.h"
#include <QTimer>
#include "mythread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc,argv);
    Arinc obj;
    MyThread somethread ;
    QTimer *ptimer = new QTimer(0);
    ptimer->setInterval(10);
    ptimer->moveToThread(&somethread);
    //obj.moveToThread(somethread);
    QObject::connect(&somethread,SIGNAL(started()),ptimer,SLOT(start()));
    QObject::connect(ptimer,SIGNAL(timeout()),&obj,SLOT(checkFifo()),Qt::QueuedConnection);
    QObject::connect(&obj,SIGNAL(MessageReceived()),&obj,SLOT(parseWord()),Qt::QueuedConnection);
    somethread.start();
    //ptimer->stop();
    //delete ptimer;
    return a.exec();
}


