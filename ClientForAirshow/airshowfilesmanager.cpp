#include "airshowfilesmanager.h"
#include <QTcpSocket>
#include <QBuffer>
#include <QDataStream>
#include <QDebug>
#include <QFile>
#include <QObject>

AirshowFilesManager::AirshowFilesManager(QObject *parent) : QObject(parent)
{
    clientSocket = new QTcpSocket(this);
    qDebug() << "AirshowFiles socket =" << clientSocket->socketDescriptor();
    //readedBlock  = new QSharedPointer<char>(new char[100000]);
    filename     = "/home/mugen/received/1.tar";
}

AirshowFilesManager::~AirshowFilesManager()
{
    delete clientSocket;
    //delete readedBlock;
}

QString AirshowFilesManager::imgFilenamePath()
{

}

void AirshowFilesManager::connectToServer(QString serverIP, int port)
{
    typedef void (QAbstractSocket::*QAbstractSocketErrorSignal)(QAbstractSocket::SocketError);
    QObject::connect(clientSocket, static_cast<QAbstractSocketErrorSignal>(&QAbstractSocket::error), this, &AirshowFilesManager::displayError);
    connect(clientSocket, &QTcpSocket::connected, this, &AirshowFilesManager::write);
    clientSocket->connectToHost(serverIP, port);
    if(clientSocket->waitForConnected())
        qDebug()<<"socket state" << clientSocket->ConnectedState <<"clientSocket"<< clientSocket->socketDescriptor();
    else
        qDebug()<<"client connection error";
    //QObject::connect(clientSocket, &QIODevice::readyRead, this, &AirshowFilesManager::read);


}


void AirshowFilesManager::write()
{
    quint8 arr[10] = {0,};
    arr[1] = 47;
    arr[2] = 35;
    arr[3] = 133;
    arr[4] = 55;
    arr[9] = 17;
    int writedbytes = clientSocket->write((char*)(arr),10);
    clientSocket->waitForBytesWritten();
    qDebug()<< "Client array writed : " << writedbytes << "bytes";
    //clientSocket->flush();
}

//void AirshowFilesManager::read()
//{
//    qDebug()<<"AirshowFilesManager readyRead begin";
//    if( imageSize == 0 )
//    {
//        if( clientSocket->bytesAvailable() < sizeof(quint32) )
//            return;
//        char bufForSize[4];
//        int countReadBytes = 0;
//        countReadBytes = clientSocket->read(bufForSize, sizeof(quint32));
//        imageSize = *(quint32*)bufForSize;
//        qDebug()<< "Client imageSize read = " << imageSize;
//        //arch.setFileName(filename);
//        arch = new QFile(filename);
//        arch->open(QIODevice::WriteOnly);
//    }

//    size_t currentReadBytes = 0;
//      /* if send many files */

////    if( readedBytes < imageSize)
////    {
////        if((readedBytes + clientSocket->bytesAvailable()) >= imageSize)
////            currentReadBytes = clientSocket->read(readedBlock, imageSize - readedBytes);
////        else
////            currentReadBytes = clientSocket->read(readedBlock,10000);

////        readedBytes += currentReadBytes;
////        image.write(readedBlock,currentReadBytes);
////    }
//    currentReadBytes = clientSocket->read(readedBlock->data(),100000);
//    readedBytes += currentReadBytes;
//    //qDebug()<<"current read = " << currentReadBytes << "readed bytes = "<<readedBytes << " image size =" << imageSize;
//    arch->write(readedBlock->data(),currentReadBytes);

//    if(readedBytes == imageSize)
//    {
//        qDebug()<<"Client read all bytes from tar";
//        readedBytes = 0;
//        imageSize = 0;
//        arch->close();
//        delete arch;
//        clientSocket->flush();
//    }
//    //qDebug()<<"read bytes dataSize = " <<dataSize;
////    *data = clientSocket->read( dataSize );
////    QBuffer buffer(data);
////    buffer.open( QIODevice::ReadOnly );

////    QImageReader reader(&buffer, "JPG");
////    QImage image = reader.read();

////    if( !image.isNull() )
////       image.save("/home/mugen/1.jpeg");
////    else
////       qDebug()<<"Invalid image received!";

////    dataSize = 0;

////    if(clientSocket.bytesAvailable() <= 0)
////        return;
////    //if (clientSocket.state() == QAbstractSocket::ConnectedState)  {
////        //clientSocket.waitForReadyRead();
////    while(clientSocket.bytesAvailable()){
////        qDebug()<<"Bytes available "<<clientSocket.bytesAvailable();
////        *data += clientSocket.readAll();
////    }
////    qDebug()<<"data read bytes = " << data->size();
//}

void AirshowFilesManager::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        qDebug()<< tr("Client") <<
                   tr("The host was not found. Please check the host name and port settings.");
        break;
    case QAbstractSocket::ConnectionRefusedError:
        qDebug()<< tr("Fortune Client")<<
                   tr("The connection was refused by the peer. "
                      "Make sure the server is running, "
                      "and check that the host name and port "
                      "settings are correct.");
        break;
    default:
        qDebug()<< tr("Client")<<
                   tr("The following error occurred: %1.").arg(clientSocket->errorString());
    }

}
