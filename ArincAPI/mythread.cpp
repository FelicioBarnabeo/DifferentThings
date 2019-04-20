#include "mythread.h"
#include <QDebug>
#include <QCoreApplication>

MyThread::MyThread():QThread()
{
    moveToThread(this);
}

void MyThread::run()
{
    //Arinc obj;
    //quint32 word = convert_data_word32_to20(obj.receive1Fifo());
    //printf("%d",word);
//    qDebug() << "current thread is: "<< QThread::currentThread()<<"main thread is" \
//             << QCoreApplication::instance()->thread();
    exec();
}

