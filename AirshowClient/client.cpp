#include <QHostAddress>
#include <QCoreApplication>
#include "client.h"
#include <QMetaType>
#include <QDebug>

Client::Client(QObject* parent): QTcpSocket(parent)
{
    m_isBusy = false;
    m_file.setFileName(QCoreApplication::applicationDirPath()+"/F.tar");
    m_buffer = new char[100000];

    QObject::connect(this,&Client::readyRead,this,&Client::readNetworkData);
    QObject::connect(this,static_cast<void(QAbstractSocket::*)
                     (QAbstractSocket::SocketError)>(&QAbstractSocket::error),
                     this,&Client::connectionError);

}

Client::~Client(){
    delete[] m_buffer;
}

void Client::disconnectClient(void){
    m_isBusy = false;
    m_file.close();
    this->abort();
    qDebug()<<"Connection state: "<< this->state();
    //this->disconnectFromHost();
}

void Client::readNetworkData()
{
    if (!m_isBusy) {
        if (this->bytesAvailable()<sizeof(quint64))
        {
            return;
        }
        m_isBusy = true;
        this->read((char*)&m_fileSize, sizeof(quint64));
        qDebug()<<"File size: "<<m_fileSize;
    }

    //this->setReadBufferSize(0);
    while (this->bytesAvailable()) {
        if (m_fileSize) {
            m_bytesTotalWrittenToFile = 0;
            m_bytesWrittenToFile = 0;
            m_bytesReadedFromSocket = this->read(m_buffer,100000);
            qDebug()<<"read from socket" << m_bytesReadedFromSocket;

            //m_bytesTotalWrittenToFile = m_file.write(m_buffer,m_bytesReadedFromSocket);
            //qDebug()<<"write to file" << m_bytesTotalWrittenToFile;

            while (m_bytesTotalWrittenToFile != m_bytesReadedFromSocket) {
                m_bytesWrittenToFile = m_file.write(&m_buffer[m_bytesTotalWrittenToFile],
                                                    m_bytesReadedFromSocket-m_bytesTotalWrittenToFile);
                m_bytesTotalWrittenToFile += m_bytesWrittenToFile;
            }
            m_fileSize -= m_bytesReadedFromSocket;
            //qDebug()<<"readed/writed "<<m_bytesReadedFromSocket<<"remaining "<<m_fileSize;
        }
    }

    if (!m_fileSize) {
        qDebug()<<"file ready. disconnect";
        this->disconnectClient();

    }
    else qDebug()<<"Not ready file size = " << m_fileSize;
    //this->disconnectFromHost();
//    m_file.close();
//    m_isBusy = false;
//    this->disconnectFromHost();
}

void Client::connectionError(QAbstractSocket::SocketError err)
{
    this->disconnectClient();
    qDebug()<<"Connection state: "<< this->state();
    qDebug()<<"Connection err: "<< err;
}

void Client::repeatConnect()
{
    //this->connectionError(QAbstractSocket::SocketTimeoutError);
    this->disconnectClient();
    m_file.open(QIODevice::WriteOnly);
    connectToHost(QHostAddress("192.168.1.1"),60000);
    if(!this->waitForConnected())
    {
        qDebug() <<"Errror" << this->error();
        this->disconnectFromHost();
    }
}


