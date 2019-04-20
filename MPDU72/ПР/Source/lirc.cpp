#include "lirc.h"
#include <QDebug>

LircSingleton * LircSingleton::m_instance = 0;

LircSingleton::LircSingleton(QObject *parent): QObject(parent), m_program("/usr/bin/irsend")
{
    m_args.clear();
    m_args<< "SEND_ONCE" << "vista_mce" << "KEY_DOWN";
}

LircSingleton::~LircSingleton(){}

LircSingleton *LircSingleton::Instance()
{
    if(m_instance==0)
    {
        m_instance = new LircSingleton();
    }
    return m_instance;
}

void LircSingleton::startSend(QString key, QString device){
    m_args.clear();
    m_args << "SEND_START" << device << key;
    emit sendStarted();
    startProcess();
}

void LircSingleton::stopSend(QString key, QString device){
    m_args.clear();
    m_args << "SEND_STOP" << device << key;
    emit sendStopped();
    startProcess();
}

void LircSingleton::sendCommand(QString key,QString device )
{
    //qDebug()<<"key = "<<key;
    m_args.clear();
    m_args << "SEND_ONCE" << device << key;
    emit sendedOnce();
    startProcess();

}

void LircSingleton::startProcess()
{
    //qDebug()<< "send signal: "<< m_args;
    try{
        if(m_process.state() > 0){
            //qDebug()<<"Process kill";
            m_process.kill(); //throw QProcess::FailedToStart;
            m_process.waitForFinished(100);
        }
        m_process.start(m_program, m_args);
    }
    catch(...){
        qDebug() << Q_FUNC_INFO << "Undefined exception";
    }
}




