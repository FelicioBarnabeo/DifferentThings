#include <QCoreApplication>
#include <QTimer>
#include "client.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Client client;
    QTimer connectTimer;
    connectTimer.setInterval(10000);
    QObject::connect(&connectTimer,&QTimer::timeout,&client,&Client::repeatConnect);
    client.repeatConnect();
    connectTimer.start();
    //connectTimer.singleShot(4000,&client,SLOT(repeatConnect()));

    return a.exec();
}
