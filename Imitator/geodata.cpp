#include "geodata.h"
#include <QDebug>

GeoData::GeoData(QString name, QVariant value, QString sign, MatrixOfSustain matrixSustain,
                 bool parity):
    m_geoName(name), m_geoValue(value), m_sign(sign), m_matrixSustain(matrixSustain),
    m_parity(parity)
{
    m_labelCodeHash["Latitude"]     = 0310;
    m_labelCodeHash["Longitude"]    = 0311;
    m_labelCodeHash["DstToDest"]    = 005;
    m_labelCodeHash["TimeToDest"]   = 006;
    m_labelCodeHash["Speed"]        = 0312;
    m_labelCodeHash["GrinvishTime"] = 0150;
    m_labelCodeHash["Temperature"]  = 0213;
    m_labelCodeHash["Date"]         = 0260;
    m_labelCodeHash["Alt"]          = 0203;
}

QVector<quint8> splitWordToVector(ArincCodeMessage label, int grade, bool sign, int matrix, \
                       bool parity, IdVss vss, Reserve rsrv, NeedBits bits)
{
    QVector<quint8> resultWord(4);
    if(sign)
    {
        qDebug()<<"Sign worked\n";
        resultWord[0]+=(1<<4);
        quint32 prefix = (1<<static_cast<int>(bits)) -1; //11111..11
        prefix <<= static_cast<int>(vss);
        prefix <<= static_cast<int>(rsrv);
        grade ^= prefix; //reverse code for signing bytes
        grade++;  // additional code for negative
    }

    grade <<= static_cast<int>(vss);
    grade <<= static_cast<int>(rsrv);
    qDebug()<<"grade after shift: \n"<<grade;
    resultWord[3] |= static_cast<int>(label);
    resultWord[2] = grade & ((1<<8)-1);
    grade >>= 8;
    resultWord[1] = grade & ((1<<8)-1);
    grade >>= 8;
    resultWord[0] = grade & ((1<<8)-1);
    if(parity) //add parity bit
        resultWord[0] += (1<<7);
    resultWord[0] += (static_cast<quint8>(matrix))<<5; //add matrix of sustain
    return resultWord;
}


quint32 grinvichTimeToWord(QTime grade)
{
    quint32 word ;
    word |= grade.hour();
    //printf("grinvich word hour: %x \n",word);
    word <<= 6;
    word |= grade.minute();
    //printf("grinvich word minute: %x \n",word);
    word <<= 6;
    word |= grade.second();
    //printf("grinvich word secondes: %x \n",word);
    return word;
}

quint32 dateToWord(QDate grade)
{
    quint32 word;
    word |= (grade.day() / 10);
    //printf("dateword day: %x \n",word);
    word <<= 4;
    word |= (grade.day() % 10);
    //printf("dateword day: %x \n",word);
    word <<= 1;
    word |= (grade.month() / 10);
    //printf("dateword month: %x \n",word);
    word <<= 4;
    word |= (grade.month() % 10);
    //printf("dateword month: %x \n",word);
    word <<= 4;
    word |= ((grade.year() / 10) % 10);
    //printf("dateword year: %x \n",word);
    word <<= 4;
    word |= (grade.year() % 10);
    //printf("dateword year: %x \n",word);
    return word;
}

QVector<quint8> geoValueToArincWord(ArincCodeMessage label, QVariant value)
{

    double grade;

    QVector<quint8> resultWord(4);
    quint8 word = 0;

    switch(label)
    {

    case ArincCodeMessage::lat:
        grade = value.toDouble() / Price::latPrice;
        return splitWordToVector(label, grade,static_cast<bool>(LatSign::north),
                                static_cast<int>(MatrixOfSustain::normal),true,
                        IdVss::latVssId,Reserve::latReserve,NeedBits::latBits);
        break;
    case ArincCodeMessage::lng:
        grade = value.toDouble() / Price::lngPrice;
        return splitWordToVector(label,grade,static_cast<bool>(LngSign::west),
                                static_cast<int>(MatrixOfSustain::normal),true,
                         IdVss::lngVssId,Reserve::lngReserve,NeedBits::lngBits);
        break;
    case ArincCodeMessage::distanceToDest:
        grade = value.toDouble() / Price::distancePrice;
        return splitWordToVector(label,grade,false,
                                 static_cast<int>(MatrixOfSustain::normal),true,
        IdVss::distanceToDestVssId,Reserve::distanceToDestReserve,NeedBits::distanceToDestBits);
        break;
    case ArincCodeMessage::timeToDest:
        grade = value.toInt() / Price::timePrice;
        return splitWordToVector(label, grade,false,
                                static_cast<int>(MatrixOfSustain::normal),true,
        IdVss::timeToDestVssId,Reserve::timeToDestReserve,NeedBits::timeToDestBits);
        break;
    case ArincCodeMessage::speed:
        grade = value.toDouble() / Price::speedPrice;
        return splitWordToVector(label, grade,false,
                                static_cast<int>(MatrixOfSustain::normal),true,
        IdVss::speedVssId,Reserve::speedReserve,NeedBits::speedToDestBits);
        break;
    case ArincCodeMessage::grinvichTime:
        return splitWordToVector(label, grinvichTimeToWord(value.toTime()),false,
                                 static_cast<int>(MatrixOfSustain::normal),true,
               IdVss::timeVssId,Reserve::timeReserve,NeedBits::timeBits);
        break;
    case ArincCodeMessage::temperature:
        grade = value.toDouble() / Price::tempPrice;
        return splitWordToVector(label, grade,false,
                                 static_cast<int>(MatrixOfSustain::normal),true,
        IdVss::tempVssId,Reserve::tempReserve,NeedBits::tempBits);
        break;
    case ArincCodeMessage::date:
        return splitWordToVector(label, dateToWord(value.toDate()),false,
                       static_cast<int>(MatrixOfSustainForDate::normal),true,
        IdVss::dateVssId, Reserve::dateReserve, NeedBits::dateBits);
        break;
    case ArincCodeMessage::alt:
        grade = value.toDouble() / Price::altPrice;
        qDebug()<<"grade after dev: \n"<<grade;
        return splitWordToVector(label, grade,static_cast<bool>(AltSign::plus),
                                 static_cast<int>(MatrixOfSustain::normal),true,
        IdVss::altVssId,Reserve::altReserve,NeedBits::altBits);
        break;
    default:
        return resultWord;
    }
    return resultWord;
}

const double Price::latPrice      = 0.000172;  // degree for bit
const double Price::lngPrice      = 0.000172;  // degree for bit
const double Price::altPrice      = 0.3048;    // meters for bit
const double Price::distancePrice = 231.5;     // meters for bit
const double Price::timePrice     = 1;         // 1 minute for bit
const double Price::speedPrice    = 0.2315;    // kilometers for bit
const double Price::tempPrice     = 0.25;      // temp degree for bit






