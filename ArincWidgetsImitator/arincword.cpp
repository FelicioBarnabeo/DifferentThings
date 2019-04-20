#include "arincword.h"
#include <QDebug>
#include <QTimer>
#include "unistd.h"

ArincWord::ArincWord()
{
    m_fd = open_device("/dev/spidev32766.0");
}

ArincWord::ArincWord(const GeoData &word )
{
    m_fd = open_device("/dev/spidev32766.0");
    createWord(word);
    setTimer(word);
    setLabelString(word);
}

ArincWord::ArincWord(const ArincWord &copy)
{
    m_fd = copy.fd();
    m_currentWord = copy.currentWord();
    m_timerWord = copy.timeInterval();
    m_label = copy.label();
}

ArincWord & ArincWord::operator =(const ArincWord &copy)
{
    m_fd = copy.fd();
    m_currentWord = copy.currentWord();
    m_timerWord = copy.timeInterval();
    m_label = copy.label();
}

ArincWord::~ArincWord()
{
    close(m_fd);
}


//Grade сделать типом double ! тут происходит неявное приведение из quint32 и double в int
//Смотреть функцию createWord
QVector<quint8> ArincWord::splitWordToVector(ArincCodeMessage label, int grade, bool sign,
int matrix, bool parity, Vss vss, Reserve rsrv, NeedBits bits)
{
    QVector<quint8> resultWord(4);
    if(sign)
    {
        qDebug()<<"Sign worked\n";
        resultWord[0] |= (1<<4);
        quint32 prefix = (1<<static_cast<int>(bits)) -1; //11111..11
        prefix <<= static_cast<int>(vss);
        prefix <<= static_cast<int>(rsrv);
        grade ^= prefix; //reverse code for signing bytes
        grade++;  // additional code for negative
    }

    grade <<= static_cast<int>(vss);
    grade <<= static_cast<int>(rsrv);
    resultWord[3] |= static_cast<int>(label);
    resultWord[2] = grade & ((1<<8)-1);
    grade >>= 8;
    resultWord[1] = grade & ((1<<8)-1);
    grade >>= 8;
    resultWord[0] |= (grade & ((1<<8)-1));
    if(parity) //add parity bit
        resultWord[0] += (1<<7);
    resultWord[0] += (static_cast<quint8>(matrix))<<5; //add matrix of sustain
    printf("splitwordtovector : %x %x %x %x \n",resultWord[0],resultWord[1],resultWord[2],resultWord[3]);
    return resultWord;
}


quint32 ArincWord::grinvichTimeToValueOfWord(QTime grade)
{
    quint32 word = 0;
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

quint32 ArincWord::dateToValueOfWord(QDate grade)
{
    quint32 word=0;
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

// Функция : логика создания слова из данных полученных с полей таблицы.
//  Такие данные для label как : price, vssid, reserve, needbits
//  получены из  классов enum как константы для соответствующих label.
// Можно (нужно ли?) изменить программу , чтобы они были членами класса geodata
//  и создавались бы в конструкторе при считывании полей таблицы из формы
// Для парсинга используются функция  splitWordToVector
QVector<quint8> ArincWord::createWord(const GeoData &geodata)
{
    double grade;
    switch(geodata.label())
    {
    case ArincCodeMessage::lat:
        printf("grade lat: \n");
        grade = geodata.geoValue().toDouble() / Price::latPrice;
        printf("geodata lat sign : %x \n ",geodata.sign());
        m_currentWord = splitWordToVector(geodata.label(), grade, geodata.sign(),
               3 - geodata.status(),geodata.parity(),
               Vss::latVssId,Reserve::latReserve,NeedBits::latBits);
        break;
    case ArincCodeMessage::lng:
        printf("grade lng: \n");
        printf("geodata lng sign : %x \n",geodata.sign());
        grade = geodata.geoValue().toDouble() / Price::lngPrice;
        m_currentWord = splitWordToVector(geodata.label(), grade, geodata.sign(),
               3 - geodata.status(),geodata.parity(),
               Vss::lngVssId,Reserve::lngReserve,NeedBits::lngBits);
        break;
    case ArincCodeMessage::distanceToDest:
        printf("grade dist: \n");
        grade = geodata.geoValue().toDouble() / Price::distancePrice;
        m_currentWord = splitWordToVector(geodata.label(),grade,false,
               3 - geodata.status(), geodata.parity(),
        Vss::distanceToDestVssId,Reserve::distanceToDestReserve,NeedBits::distanceToDestBits);
        break;
    case ArincCodeMessage::timeToDest:
        printf("grade timeToDest: \n");
        grade = geodata.geoValue().toTime().hour()*60 + geodata.geoValue().toTime().minute();
        //grade = geodata.geoValue().toInt() / Price::timePrice;
        m_currentWord = splitWordToVector(geodata.label(), grade,false,
               3 - geodata.status(), geodata.parity(),
        Vss::timeToDestVssId,Reserve::timeToDestReserve,NeedBits::timeToDestBits);
        break;
    case ArincCodeMessage::speed:
        printf("grade speed: \n");
        grade = geodata.geoValue().toDouble() / Price::speedPrice;
        m_currentWord = splitWordToVector(geodata.label(), grade, false,
               3 - geodata.status(), geodata.parity(),
        Vss::speedVssId,Reserve::speedReserve,NeedBits::speedToDestBits);
        break;
    case ArincCodeMessage::grinvichTime:
        printf("grade grinvichTime: \n");
        m_currentWord = splitWordToVector(geodata.label(),
               grinvichTimeToValueOfWord(geodata.geoValue().toTime()),false,
               3 - geodata.status(), geodata.parity(),Vss::timeVssId,
               Reserve::timeReserve,NeedBits::timeBits);
        break;
    case ArincCodeMessage::temperature:
        printf("grade temperature: \n");
        grade = geodata.geoValue().toDouble() / Price::tempPrice;
        m_currentWord = splitWordToVector(geodata.label(), grade, false, 3 - geodata.status(),
               geodata.parity(), Vss::tempVssId,
               Reserve::tempReserve,NeedBits::tempBits);
        break;
    case ArincCodeMessage::date:
        printf("grade date: \n");
        m_currentWord = splitWordToVector(geodata.label(),
        dateToValueOfWord(geodata.geoValue().toDate()),false,
        geodata.status(),geodata.parity(),
        Vss::dateVssId, Reserve::dateReserve, NeedBits::dateBits);
        break;
    case ArincCodeMessage::alt:
        printf("grade alt: \n");
        grade = geodata.geoValue().toDouble() / Price::altPrice;
        m_currentWord = splitWordToVector(geodata.label(), grade,geodata.sign(),
        3 - geodata.status(),geodata.parity(),
        Vss::altVssId,Reserve::altReserve,NeedBits::altBits);
        break;
    default:
        ;
    }
    //std::cout.flush();
    return m_currentWord;
}

void ArincWord::writeWithTimeInterval()
{
    QTimer *ptimer = new QTimer(this);
    //connect(ptimer,SIGNAL(timeout()),this,SLOT(sendWordToDevice()));
    ptimer->start(m_timerWord);
}

void ArincWord::sendWordToDevice()
{
    write_bit(m_fd,0x0C,m_currentWord.data(),4);
}

QVector<quint8> ArincWord::readWordFromReceive()
{
    QVector<quint8> bufferWord(4);
    read_bit(m_fd, 0xA0,bufferWord.data(), 4);
    return bufferWord;
}

