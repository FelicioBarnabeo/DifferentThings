#ifndef GEODATA_H
#define GEODATA_H

#include <QObject>
#include <QHash>
#include <QString>
#include <QVector>
#include <QVariant>
#include <QTime>
#include <QDate>
#include "spidriver.h"
#include <QDataStream>


enum class ArincCodeMessage
{
    lat             = 0310,  // Latitude
    lng             = 0311,  //Longitude
    distanceToDest  = 005,   //Miles to destination
    timeToDest      = 006,   //Time to destination
    speed           = 0312,  //Current speed
    grinvichTime    = 0150,  //Time by grinvich
    temperature     = 0213,  //Temperature
    date            = 0260,  //Date
    alt             = 0203,  //Absolute high
};



enum class MatrixOfSustain
{
    refuse,
    test  ,
    notdata,
    normal,
};

enum class MatrixOfSustainForDate
{
    normal,
    test,
    notdata,
    notuse,
};

enum class LatSign
{
    north,
    south,
};

enum class LngSign
{
    east,
    west,
};

enum class AltSign
{
    plus,
    minus
};

enum class Vss
{
    latVssId = 0,
    lngVssId = 0,
    distanceToDestVssId = 2,
    timeToDestVssId = 2,
    speedVssId = 2,
    timeVssId = 2,
    tempVssId = 2,
    dateVssId = 2,
    altVssId = 2,
};

enum class Reserve
{
    latReserve = 0,
    lngReserve = 0,
    distanceToDestReserve = 0,
    timeToDestReserve = 6,
    speedReserve = 3,
    timeReserve = 1,
    tempReserve = 7,
    dateReserve = 0,
    altReserve = 1,
};

enum class NeedBits
{
    latBits = 20,
    lngBits = 20,
    distanceToDestBits = 18,
    timeToDestBits = 12,
    speedToDestBits = 15,
    timeBits = 17,
    tempBits = 11,
    dateBits = 19,
    altBits = 17,
};



class Price
{
public:
    Price();
    const static  double latPrice;
    const static  double lngPrice;
    const static  double altPrice ;
    const static  double distancePrice;
    const static  double timePrice;
    const static  double speedPrice;
    const static  double tempPrice ;
};


class GeoData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(ArincCodeMessage label READ label WRITE setLabel NOTIFY labelChanged)
    Q_PROPERTY(QVariant geoValue READ geoValue WRITE setGeoValue NOTIFY geoValueChanged)
    Q_PROPERTY(bool sign READ sign WRITE setSign NOTIFY signChanged)
    Q_PROPERTY(int status READ status WRITE setStatus NOTIFY statusChanged)
    Q_PROPERTY(bool parity READ parity WRITE setParity NOTIFY parityChanged)
    Q_PROPERTY(int timer READ timer WRITE setTimer NOTIFY timerChanged)
    //Assosiate label code number(int) with label name(qstring) and send interval timing(int)
    QHash<int,QString> m_labelCodeHash;
    QHash<int,int> m_labelTimeInterval;
    // Hash need for converting string names of geo labels getting from table
    // to 8-bit arinc code    
    ArincCodeMessage m_label;
    Vss m_vssLength;
    Reserve m_rsrvLength;
    NeedBits m_bitsLength;
    QVariant m_geoValue;
    int m_sign;
    int m_status;
    int m_timer;
    bool m_parity;
    void initCodeHash();
    void initLabelTimeInterval();
public:
    GeoData(){}
    explicit GeoData(ArincCodeMessage label, QVariant value,
                     int status, bool parity, bool sign = 0);
    // Необходимо создать конструкторы копирования присваивания
    // и копирования и присваивания с правой ссылкой
    GeoData(const GeoData &copy);
    GeoData & operator =(const GeoData &copy);
    ~GeoData(){}

    friend QDataStream & operator<<(QDataStream &out, const GeoData &data);
    friend QDataStream & operator>>(QDataStream &in, GeoData &data);
    //friend QDataStream & operator<<(QDataStream &out, const GeoData *ptr);
    //friend QDataStream & operator>>(QDataStream &in, GeoData *ptr);
    friend QDebug & operator<<(QDebug dbg, const GeoData &data);
    Vss vssLength()
    {
        return m_vssLength;
    }
    Reserve rsrvLength()
    {
        return m_rsrvLength;
    }
    NeedBits bitsLength()
    {
        return m_bitsLength;
    }

    QString geoLabelCode() const
    {
        return m_labelCodeHash[static_cast<int>(m_label)];
    }
    int geoLabelTimeInterval() const
    {
        return m_labelTimeInterval[static_cast<int>(m_label)];
    }
    ArincCodeMessage label() const
    {
        return m_label;
    }
    QVariant geoValue() const
    {
        return m_geoValue;
    }

    bool parity() const
    {
        return m_parity;
    }

    int status() const
    {
        return m_status;
    }

    bool sign() const
    {
        return m_sign;
    }

    int timer() const
    {
        return m_timer;
    }

public slots:

    void setLabel(ArincCodeMessage arg)
    {
        if (static_cast<int>(m_label) == static_cast<int>(arg))
            return;

        m_label = arg;
        emit labelChanged(arg);
    }

    void setLabel( Vss arg)
    {
        if (static_cast<int>(m_vssLength) == static_cast<int>(arg))
            return;

        m_vssLength = arg;
        emit vssLengthChanged(arg);
    }

    void setLabel(Reserve arg)
    {
        if (static_cast<int>(m_rsrvLength) == static_cast<int>(arg))
            return;

        m_rsrvLength = arg;
        emit rsrvLengthChanged(arg);
    }

    void setLabel(NeedBits arg)
    {
        if (static_cast<int>(m_bitsLength) == static_cast<int>(arg))
            return;

        m_bitsLength = arg;
        emit bitsLengthChanged(arg);
    }

    void setGeoValue(QVariant arg)
    {
        if (m_geoValue == arg)
            return;

        m_geoValue = arg;
        emit geoValueChanged(arg);
    }

    void setParity(bool arg)
    {
        if (m_parity == arg)
            return;

        m_parity = arg;
        emit parityChanged(arg);
    }

    void setStatus(int arg)
    {
        if (m_status == arg)
            return;

        m_status = arg;
        emit statusChanged(arg);
    }

    void setSign(bool arg)
    {
        if (m_sign == arg)
            return;

        m_sign = arg;
        emit signChanged(arg);
    }

    void setTimer(int arg)
    {
        if (m_timer == arg)
            return;

        m_timer = arg;
        emit timerChanged(arg);
    }

signals:
    void labelChanged(ArincCodeMessage arg);
    void vssLengthChanged(Vss arg);
    void rsrvLengthChanged(Reserve arg);
    void bitsLengthChanged(NeedBits arg);
    void geoValueChanged(QVariant arg);
    void parityChanged(bool arg);
    void statusChanged(int arg);
    void signChanged(bool arg);
    void timerChanged(int arg);
};



#endif // GEODATA_H
