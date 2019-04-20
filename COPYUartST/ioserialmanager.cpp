#include "ioserialmanager.h"
#include "command.h"
#include <QErrorMessage>
#include <QDebug>
#include "settings.h"

IOSerialManager::IOSerialManager(QObject *parent)
    : QObject(parent)
    , m_serialPort(new SerialDevice)
    , m_readPort(new SerialDevice)
{
    Settings *st = Settings::instance();
    setConfiguration(st->deviceName(),st->baudRate(),st->dataBits(),st->parity(),st->stopBits());

    QObject::connect(m_serialPort,static_cast<void(QSerialPort::*)
                     (QSerialPort::SerialPortError)>(&QSerialPort::error),
                     this,&IOSerialManager::handleError);
    connect(m_serialPort, &SerialDevice::readyRead, this, &IOSerialManager::readMessage);
}

IOSerialManager::~IOSerialManager()
{
    m_serialPort->close();
    m_readPort->close();
    delete m_serialPort;
    delete m_readPort;
}

void IOSerialManager::handleError(QSerialPort::SerialPortError err)
{
    qDebug()<<"Err = "<<err;
}

void IOSerialManager::setConfiguration(QString portName, QString baudRate, QString dataBits, QString parity, QString stopBits)
{
    m_serialPort->setStringBaudRate(baudRate);
    m_serialPort->setStringDataBits(dataBits);
    m_serialPort->setStringParity(parity);
    m_serialPort->setPortName(portName);
    m_serialPort->setStringStopBits(stopBits);
}

IOSerialManager* IOSerialManager::m_instance = 0;

IOSerialManager *IOSerialManager::instance()
{
    if(!m_instance){
        m_instance = new IOSerialManager();
    }
    return m_instance;
}

bool IOSerialManager::tryOpenPort(){
    m_serialPort->close();
    return m_serialPort->open(QIODevice::ReadWrite);
}

bool IOSerialManager::tryOpenReadPort(){
    m_readPort->close();
    return m_readPort->open(QIODevice::ReadWrite);
}

void IOSerialManager::sendMessage(Command *cmd) const
{
    const QString sequence = cmd->message().toHex().toUpper();
    qDebug()<<"Sequence = " << sequence;
    int writed_bits = m_serialPort->write(cmd->message());
//    if(writed_bits < 0){
//        QErrorMessage *msg = new QErrorMessage();
//         if(!m_serialPort->isOpen())
//            msg->showMessage("Device not open");
//         else msg->showMessage(m_serialPort->errorString());
//    }
    qDebug()<<"Writed bits = "<<writed_bits ;
    m_serialPort->waitForBytesWritten(100);
    if(writed_bits == cmd->message().size())
        emit bytesWrited(cmd->message());
    else
        qDebug()<< "Missing write few bytes";
}

void IOSerialManager::readMessage()
{
    while(m_serialPort->bytesAvailable()){
        m_readBuf.append(m_serialPort->readAll());
        m_serialPort->waitForReadyRead(20);
    }
    emit bytesReaded(m_readBuf);
    m_readBuf.clear();
}
