#include "loginterface.h"



ArincMsgLogger::ArincMsgLogger()
{
    geologfile.setFileName("geologfile.dat");
//    try
//    {
//        geologfile.open(QIODevice::WriteOnly);
//    }
//    catch(...)
//    {
//        throw("Cant open geologfile.dat for write");
//    }

    if(!geologfile.open(QIODevice::WriteOnly)) /*| QIODevice::Text | QIODevice::Append))*/
    {
        qDebug()<<"Cant open logfile.txt for write";
        exit(1);
    }
}

void ArincMsgLogger::log(MapStringDouble msg)
{
    QMapIterator<QString,double> i(msg);
    QDataStream out(&geologfile);
    out << msg;
    geologfile.flush();
}

ArincMsgLogger::~ArincMsgLogger()
{
    geologfile.close();
}

MapStringDouble ArincMsgLogger::readLog()
{
    MapStringDouble data;
    QDataStream in(&geologfile);
    in >> data;
    qDebug()<<"data = "<<data<<endl;
    return data;
    //QMapIterator<QString,double> i;
}
