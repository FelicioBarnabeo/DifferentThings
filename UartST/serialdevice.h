#ifndef SERIALDEVICE_H
#define SERIALDEVICE_H

#include <QtSerialPort/QSerialPort>
#include <QMap>
#include <QStringList>

class SerialDevice : public QSerialPort
{
public:
    SerialDevice(QObject *parent = Q_NULLPTR);
    const QString currentBaudRate();
    const QString currentParity();
    const QString currentDataBits();
    const QString currentStopBits();
    const QString currentWriteInterval();
public slots:
    void setWriteInterval(int value);
    void setStringParity(QString pr);
    void setStringBaudRate(QString br);
    void setStringStopBits(QString sb);
    void setStringDataBits(QString db);
    QList<QString> listParity()   const;
    QList<QString> listStopBits() const;
    QList<QString> listDataBits() const;
private:
    int m_writeInterval;
    const QMap<QString,Parity>    m_mapParity;
    const QMap<QString,DataBits>  m_mapDataBits;
    const QMap<QString,StopBits>  m_mapStopBits;
};

#endif // SERIALDEVICE_H
