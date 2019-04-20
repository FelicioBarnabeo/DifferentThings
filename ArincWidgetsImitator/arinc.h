#ifndef ARINC_H
#define ARINC_H

#include "spidevdriver.h"
#include "constants.h"
//#include <qt5/QtCore/QtGlobal>
#include <QObject>
#include <QTime>
#include <QDate>
#include <QSharedPointer>

class GeoData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double Latitude READ Latitude WRITE setLatitude NOTIFY LatitudeChanged)
    Q_PROPERTY(double Longitude READ Longitude WRITE setLongitude NOTIFY LongitudeChanged)
    Q_PROPERTY(double KmToDest READ KmToDest WRITE setKmToDest NOTIFY KmToDestChanged)
    Q_PROPERTY(QTime  TimeToDest READ TimeToDest WRITE setTimeToDest NOTIFY TimeToDestChanged)
    Q_PROPERTY(double Speed READ Speed WRITE setSpeed NOTIFY SpeedChanged)
    Q_PROPERTY(QTime  GrinvichTime READ GrinvichTime WRITE setGrinvichTime NOTIFY GrinvichTimeChanged)
    Q_PROPERTY(double Temperature READ Temperature WRITE setTemperature NOTIFY TemperatureChanged)
    Q_PROPERTY(QDate  Date READ Date WRITE setDate NOTIFY DateChanged)
    Q_PROPERTY(double Alt READ Alt WRITE setAlt NOTIFY AltChanged)
    Q_PROPERTY(MapStringDouble GeoCoordinates READ GeoCoordinates WRITE setGeoCoordinates NOTIFY GeoCoordinatesChanged)

public:
    GeoData();
    ~GeoData();

    double Latitude() const
    {
        return m_Latitude;
    }
    double Longitude() const
    {
        return m_Longitude;
    }

    double KmToDest() const
    {
        return m_KmToDest;
    }

    QTime TimeToDest() const
    {
        return m_TimeToDest;
    }

    double Speed() const
    {
        return m_Speed;
    }

    QTime GrinvichTime() const
    {
        return m_GrinvichTime;
    }

    double Temperature() const
    {
        return m_Temperature;
    }

    QDate Date() const
    {
        return m_Date;
    }

    double Alt() const
    {
        return m_Alt;
    }

    MapStringDouble GeoCoordinates() const
    {
        return m_GeoCoordinates;
    }

public slots:
    void setLatitude(double arg)
    {
        if (m_Latitude == arg)
            return;
        m_GeoCoordinates["Latitude"] = arg;
        m_Latitude = arg;
        logger->log(m_GeoCoordinates);
        emit GeoCoordinatesChanged(m_GeoCoordinates);
    }
    void setLongitude(double arg)
    {
        if (m_Longitude == arg)
            return;
        m_GeoCoordinates["Longitude"] = arg;
        m_Longitude = arg;
        logger->log(m_GeoCoordinates);
        emit GeoCoordinatesChanged(m_GeoCoordinates);
    }

    void setAlt(double arg)
    {
        if (m_Alt == arg)
            return;
        m_GeoCoordinates["Alt"] = arg;
        m_Alt = arg;
        logger->log(m_GeoCoordinates);
        emit GeoCoordinatesChanged(m_GeoCoordinates);
    }

    void setKmToDest(double arg)
    {
        if (m_KmToDest == arg)
            return;

        m_KmToDest = arg;
        emit KmToDestChanged(arg);
    }

    void setTimeToDest(QTime arg)
    {
        if (m_TimeToDest == arg)
            return;

        m_TimeToDest = arg;
        emit TimeToDestChanged(arg);
    }

    void setSpeed(double arg)
    {
        if (m_Speed == arg)
            return;

        m_Speed = arg;
        emit SpeedChanged(arg);
    }

    void setGrinvichTime(QTime arg)
    {
        if (m_GrinvichTime == arg)
            return;

        m_GrinvichTime = arg;
        emit GrinvichTimeChanged(arg);
    }

    void setTemperature(double arg)
    {
        if (m_Temperature == arg)
            return;

        m_Temperature = arg;
        emit TemperatureChanged(arg);
    }

    void setDate(QDate arg)
    {
        if (m_Date == arg)
            return;

        m_Date = arg;
        emit DateChanged(arg);
    }

    void setGeoCoordinates(MapStringDouble arg)
    {
        if (m_GeoCoordinates==arg)
            return;
        m_GeoCoordinates = arg;
        emit GeoCoordinatesChanged(arg);
    }

signals:
    void LatitudeChanged(double arg);
    void LongitudeChanged(double arg);
    void KmToDestChanged(double arg);
    void TimeToDestChanged(QTime arg);
    void SpeedChanged(double arg);
    void GrinvichTimeChanged(QTime arg);
    void TemperatureChanged(double arg);
    void DateChanged(QDate arg);
    void AltChanged(double arg);
    void GeoCoordinatesChanged(MapStringDouble arg);

private:
    QSharedPointer<ILogger> logger;
    double m_Latitude;
    double m_Longitude;
    double m_KmToDest;
    QTime m_TimeToDest;
    double m_Speed;
    QTime m_GrinvichTime;
    double m_Temperature;
    QDate m_Date;
    double m_Alt;
    MapStringDouble m_GeoCoordinates;
};

class SpiConfigure
{
public:
    SpiConfigure();
    SpiConfigure(QString devname);
    ~SpiConfigure();
    int openSpiDevice(QString devname);
    const int & device() const;
    Errors setMode(SpiModes mode);
    SpiModes Mode() const;
    Errors setBitsPerWord(Config bits);
    Config BitsPerWord() const;
    Errors setSpiFrequency(Config freq);
    Config SpiFrequency() const;
    Errors setLsbFirst(Config flag);
    Config LsbFirst() const;
private:
    int dev;
    SpiModes CurrentMode;
    Config CurrentSpiFreq;
    Config CurrentBitsPerWord;
    Config CurrentLsb;
};

class Arinc : public QObject
{
    Q_OBJECT
public slots:
    void checkFifo();
    void parseWord();
signals:
    void MessageReceived();
private:
    SpiConfigure spiDevice;
    GeoData geo;
    int CurrentAclk;
    QVector<quint8> LookUpTable;
    QVector<quint8> CurrentMsg;
    QVector<quint8> Rec1Control;
    QVector<quint8> Rec2Control;
    QVector<quint8> TransmitControl;
    QVector<quint8> Rec1BufferStatus;
    QVector<quint8> Rec2BufferStatus;
    QVector<quint8> TransmitStatus;

public:
    Arinc();
    Arinc(const Arinc &);
    ~Arinc(){}
    Arinc & operator=(const Arinc &rhs);
    Errors setAclk(int Mhz);
    int Aclk() const;
    // Receive control
    QVector<quint8> receive1ControlBit() const;
    Errors setReceive1ControlBit(ReceiverControlFlags flag);
    Errors setReceive1ControlBit(QVector<quint8> byte);
    QVector<quint8> receive2ControlBit() const;
    Errors setReceive2ControlBit(ReceiverControlFlags flag);
    Errors setReceive2ControlBit(QVector<quint8> byte);
    // Receive status
    QVector<quint8> receive1StatusRegister() const;
    QVector<quint8> receive2StatusRegister() const;
    // Transmit control
    QVector<quint8> transmitControlBit() const;
    Errors setTransmitControlBit(TransmitControlFlags flag);
    // Transmit status
    QVector<quint8> transmitStatusRegister() const;
    // Set and get Look-up table for receive only allowing message
    QVector<quint8> getLookUpTable() const;
    Errors setLookUpTable(QVector<quint8> Table);
    Errors writeLabelToMemory(ArincCodeMessage msg);
    Errors clearLabelFromMemory(ArincCodeMessage msg);
    Errors clearLookUpTable();
    // Read receiver1 buffer FIFO
    QVector<quint8> receive1Fifo();
    // Software reset
    Errors softReset();
    // Master reset
    Errors masterReset();
};

#endif // ARINC_H

