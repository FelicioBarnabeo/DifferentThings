#include "lirc.h"
#include <QDebug>
#include <QFile>
#include <QByteArray>


Lirc::Lirc(QObject *parent): QObject(parent), m_program("/usr/bin/irsend")
{
    m_args.clear();
    m_args<< "SEND_ONCE" << "vista_mce" << "KEY_DOWN";
    m_idxCmd = -1;
}

Lirc::~Lirc(){}

void Lirc::fillCmdList()
{
    QFile cmdfile("lircd.conf");
    if (cmdfile.exists())
    {
        qDebug()<<"Exists";
    }
    QRegExp regex("\\b0[xX][0-9a-fA-F]{6}\\b");
    if(!cmdfile.open(QIODevice::ReadOnly)){
        qDebug()<<"File not opened";
        return;
    }
    QTextStream in(&cmdfile);
    QString line = "";
    while(!line.isNull())
    {
        //qDebug()<<line;
        if((regex.indexIn(line)) > 0){
            listCmd.append(regex.cap().replace("0x",""));
            //qDebug()<< " " << regex.cap();
        }
        line = in.readLine();
    }
    qDebug()<<"size = " << listCmd.size();
}

//void Lirc::writeCmdList()

void Lirc::startSend(QString key, QString device){
    m_args.clear();
    m_args << "SEND_START" << device << key;
    emit sendStarted();
    startProcess();
}

void Lirc::stopSend(QString key, QString device){
    m_args.clear();
    m_args << "SEND_STOP" << device << key;
    emit sendStopped();
    startProcess();
}

void Lirc::sendCommand(QString key,QString device )
{
    //qDebug()<<"key = "<<key;
    m_args.clear();
    m_args << "SEND_ONCE" << device << key;
    emit sendedOnce();
    startProcess();
}

const QString Lirc::getPrevCmd()
{
    if(listCmd.isEmpty())
        return "Empty list!";
    qDebug()<<"GetPrev "<< m_idxCmd;
    if(m_idxCmd > 0){
        //qDebug() << "Cmd = " <<listCmd[currentIdxCmd];
        setIdxCmd(m_idxCmd-1);
        return listCmd[m_idxCmd];
    }
    else return listCmd[0];
}

const QString Lirc::getNextCmd()
{
    if(listCmd.isEmpty())
        return "Empty list!";
    qDebug()<<"GetNext"<< m_idxCmd;
    if(m_idxCmd < (listCmd.size()-1)){
        //qDebug() << "Cmd = " <<listCmd[currentIdxCmd];
        setIdxCmd(m_idxCmd+1);
        return listCmd[m_idxCmd];
    }
    else return listCmd.last();
}

void Lirc::startProcess()
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





