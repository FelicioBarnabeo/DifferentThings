#include "geodata.h"
#include <QDebug>

using namespace std;

GeoData::GeoData(ArincCodeMessage label, QVariant value, int status,
                 bool parity, bool sign):
    m_label(label), m_geoValue(value), m_sign(sign), m_status(status),
    m_parity(parity)
{
    //fd = open_device("/dev/spidev32766.0");
    initCodeHash();
    initLabelTimeInterval();
}

void GeoData::initCodeHash()
{
    m_labelCodeHash[0310] = "Latitude";
    m_labelCodeHash[0311] = "Longitude";
    m_labelCodeHash[005]  = "DstToDest";
    m_labelCodeHash[006]  = "TimeToDest";
    m_labelCodeHash[0312] = "Speed";
    m_labelCodeHash[0150] = "GrinvishTime";
    m_labelCodeHash[0213] = "Temperature";
    m_labelCodeHash[0260] = "Date";
    m_labelCodeHash[0203] = "Alt";
}

void GeoData::initLabelTimeInterval()
{
    m_labelTimeInterval[0310] = 100;
    m_labelTimeInterval[0311] = 100;
    m_labelTimeInterval[005]  = 500;
    m_labelTimeInterval[006]  = 500;
    m_labelTimeInterval[0312] = 100;
    m_labelTimeInterval[0150] = 125;
    m_labelTimeInterval[0213] = 250;
    m_labelTimeInterval[0260] = 125;
    m_labelTimeInterval[0203] = 250;
}

////Доделать надо!!
GeoData::GeoData(const GeoData &cop)
{
    m_label = cop.m_label;
    m_geoValue = cop.m_geoValue;
    m_sign = cop.m_sign;
    m_status = cop.m_status;
    m_parity = cop.m_parity;
    m_timer = cop.m_timer;
    m_labelCodeHash = cop.m_labelCodeHash;
    m_labelTimeInterval = cop.m_labelTimeInterval;
    m_vssLength = cop.m_vssLength;
    m_rsrvLength = cop.m_rsrvLength;
    m_bitsLength = cop.m_bitsLength;
}

GeoData & GeoData::operator =(const GeoData &copy)
{
    if(this == &copy) return *this;
    m_label = copy.m_label;
    m_geoValue = copy.m_geoValue;
    m_sign = copy.m_sign;
    m_status = copy.m_status;
    m_parity = copy.m_parity;
    m_timer = copy.m_timer;
    m_labelCodeHash = copy.m_labelCodeHash;
    m_labelTimeInterval = copy.m_labelTimeInterval;
    m_vssLength = copy.m_vssLength;
    m_rsrvLength = copy.m_rsrvLength;
    m_bitsLength = copy.m_bitsLength;
    return *this;
}

QDataStream & operator<<(QDataStream & out, const GeoData & data)
{
    out << data.m_geoValue << data.m_sign << data.m_status << data.m_parity;
    return out;
}

QDataStream & operator>> (QDataStream &in, GeoData & data)
{
    in >> data.m_geoValue >> data.m_sign >> data.m_status >> data.m_parity;
    return in;
}


QDebug & operator<<(QDebug dbg, const GeoData &data)
{
    dbg.nospace()<<"value:"<<data.m_geoValue<<"sign:"<<data.m_sign<<
                   "status:"<<data.m_status<<"parity:"<<data.m_parity;
    return dbg.space();
}

const double Price::latPrice      = 0.000172;  // degree for bit
const double Price::lngPrice      = 0.000172;  // degree for bit
const double Price::altPrice      = 0.3048;    // meters for bit
const double Price::distancePrice = 231.5;     // meters for bit
const double Price::timePrice     = 1;         // 1 minute for bit
const double Price::speedPrice    = 0.2315;    // kilometers for bit
const double Price::tempPrice     = 0.25;      // temp degree for bit






