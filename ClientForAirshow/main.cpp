#include <QCoreApplication>
#include "airshowfilesmanager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    AirshowFilesManager localclient;
    localclient.connectToServer("127.0.0.1", 9999);
    return a.exec();
}
