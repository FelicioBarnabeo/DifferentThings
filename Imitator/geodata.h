#ifndef GEODATA_H
#define GEODATA_H

#include <QObject>
#include <QHash>
#include <QString>
#include <QVector>
#include <QVariant>
#include <QTime>
#include <QDate>


enum class ArincCodeMessage
{
    lat             = 0310,  // Latitude
    lng             = 0311,  //Longtitude
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

enum class IdVss
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
quint32 grinvichTimeToWord(QTime grade);
quint32 dateToWord(QDate grade);
QVector<quint8> splitWordToVector(ArincCodeMessage label, int grade, bool sign, int matrix,
                bool parity, IdVss vss, Reserve rsrv, NeedBits bits);

QVector<quint8> geoValueToArincWord(ArincCodeMessage label, QVariant value);

class GeoData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString geoName READ geoName WRITE setGeoName NOTIFY geoNameChanged)
    Q_PROPERTY(QVariant geoValue READ geoValue WRITE setGeoValue NOTIFY geoValueChanged)
    Q_PROPERTY(QString sign READ sign WRITE setSign NOTIFY signChanged)
    Q_PROPERTY(MatrixOfSustain matrixSustain READ matrixSustain WRITE setMatrixSustain NOTIFY matrixSustainChanged)
    Q_PROPERTY(bool parity READ parity WRITE setParity NOTIFY parityChanged)
    // Hash need for converting string names of geo labels getting from table
    // to 8-bit arinc code
    QHash<QString,int> m_labelCodeHash;
    QString m_geoName;
    QVariant m_geoValue;
    bool m_parity;
    MatrixOfSustain m_matrixSustain;
    QString m_sign;

public:
    GeoData(){}
    explicit GeoData(QObject *parent = 0){}
    explicit GeoData(QString name, QVariant value, QString sign, MatrixOfSustain sustain, bool parity);
    ~GeoData(){}

    int geoLabelCode(QString label) const
    {
        return m_labelCodeHash[label];
    }
    QString geoName() const
    {
        return m_geoName;
    }
    QVariant geoValue() const
    {
        return m_geoValue;
    }

    bool parity() const
    {
        return m_parity;
    }

    MatrixOfSustain matrixSustain() const
    {
        return m_matrixSustain;
    }

    QString sign() const
    {
        return m_sign;
    }

public slots:
    void setGeoName(QString arg)
    {
        if (m_geoName == arg)
            return;

        m_geoName = arg;
        emit geoNameChanged(arg);
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

    void setMatrixSustain(MatrixOfSustain arg)
    {
        if (static_cast<int>(m_matrixSustain) == static_cast<int>(arg))
            return;

        m_matrixSustain = arg;
        emit matrixSustainChanged(arg);
    }

    void setSign(QString arg)
    {
        if (m_sign == arg)
            return;

        m_sign = arg;
        emit signChanged(arg);
    }

signals:
    void geoNameChanged(QString arg);
    void geoValueChanged(QVariant arg);
    void parityChanged(bool arg);
    void matrixSustainChanged(MatrixOfSustain arg);
    void signChanged(QString arg);
};

#endif // GEODATA_H
