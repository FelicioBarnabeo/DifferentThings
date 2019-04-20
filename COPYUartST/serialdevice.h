#ifndef SERIALDEVICE_H
#define SERIALDEVICE_H

#include <QtSerialPort/QSerialPort>
#include <QMap>
#include <QStringList>

class SerialDevice : public QSerialPort
{
public:
    SerialDevice(QObject *parent = Q_NULLPTR);
    const QString currentBaudRate() const;
    const QString currentParity() const;
    const QString currentDataBits() const;
    const QString currentStopBits() const;
public slots:
    //void setWriteInterval(int value);
    void setStringParity(QString pr);
    void setStringBaudRate(QString br);
    void setStringStopBits(QString sb);
    void setStringDataBits(QString db);
    QList<QString> listParity()   const;
    QList<QString> listStopBits() const;
    QList<QString> listDataBits() const;
private:
    const QMap<QString,Parity>    m_mapParity;
    const QMap<QString,DataBits>  m_mapDataBits;
    const QMap<QString,StopBits>  m_mapStopBits;
};

#endif // SERIALDEVICE_H
