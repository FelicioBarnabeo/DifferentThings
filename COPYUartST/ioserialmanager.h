#ifndef IOSERIALMANAGER_H
#define IOSERIALMANAGER_H

#include "serialdevice.h"

class Command;

class IOSerialManager : public QObject
{
    Q_OBJECT
public:
    ~IOSerialManager();
    bool tryOpenPort();
    bool tryOpenReadPort();
    SerialDevice * serialPort() const
    {
        return m_serialPort;
    }
    void setConfiguration(QString portName, QString baudRate, QString dataBits, QString parity, QString stopBits);
    static IOSerialManager * instance();
    //void setDevice();
protected:
        IOSerialManager(QObject *parent = 0);
public slots:
    void sendMessage(Command *cmd) const;
    void readMessage();
    static void handleError(QSerialPort::SerialPortError err);
signals:
    void bytesWrited(const QByteArray &) const;
    void bytesReaded(const QByteArray &);
private:
    SerialDevice *m_serialPort;
    SerialDevice *m_readPort;
    static IOSerialManager *m_instance;
    QByteArray m_readBuf;
};

#endif // IOSERIALMANAGER_H
