#include "arinc.h"
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <QCoreApplication>

const double GeoParse::latPrice      = 0.000172;  // degree for bit
const double GeoParse::lngPrice      = 0.000172;  // degree for bit
const double GeoParse::altPrice      = 0.0003048; // kilometers for bit
const double GeoParse::distancePrice = 0.2315;    // kilometers for bit
const double GeoParse::timePrice     = 1;         // 1 minute for bit
const double GeoParse::speedPrice    = 0.2315;    // kilometers for bit
const double GeoParse::tempPrice     = 0.25;      // temp degree for bit

GeoData::GeoData()
{
    try
    {
        logger = QSharedPointer<ILogger>(new ArincMsgLogger());
    }
    catch(...)
    {
        qDebug() << "cant create logger";
    }

//    if(!logger)
//    {
//        qDebug() << "cant create logger";
//        exit(1);
//    }
    m_GeoCoordinates.insert("Latitude",0);
    m_GeoCoordinates.insert("Longitude",0);
    m_GeoCoordinates.insert("Alt",0);
}

GeoData::~GeoData()
{
    logger.clear();
}

SpiConfigure::SpiConfigure()
{
    dev = openSpiDevice("/dev/spidev32766.0"); //Need change to settings customization file
    setMode(SpiModes::notCpohNotCpol);
    setSpiFrequency(Config::spiFreq);
    setBitsPerWord(Config::bitsPerWord);
}
SpiConfigure::SpiConfigure(QString devname)
{
    dev = openSpiDevice(devname);
    setMode(SpiModes::notCpohNotCpol);
    setSpiFrequency(Config::spiFreq);
    setBitsPerWord(Config::bitsPerWord);
}

SpiConfigure::~SpiConfigure()
{
    close(dev);
}

int SpiConfigure::openSpiDevice(QString devname)
{
    dev = open_device(devname.toLatin1().constData());
    return dev;
}

const int & SpiConfigure::device() const
{
    return dev;
}

Config SpiConfigure::BitsPerWord() const
{
    return CurrentBitsPerWord;
}
Errors SpiConfigure::setBitsPerWord(Config bits)
{
    int ret = 0;
    ret = ioctl(dev, SPI_IOC_WR_BITS_PER_WORD, &bits);
    if(ret<0)
        return Errors::failSetBitsPerWord;
    return Errors::noErrors;
}

Config SpiConfigure::LsbFirst() const
{
    return CurrentLsb;
}
Errors SpiConfigure::setLsbFirst(Config flag)
{
    int ret = ioctl(dev,SPI_IOC_WR_LSB_FIRST, &flag);
    if(ret<0)
        return Errors::failSetLsb;
    CurrentLsb = flag;
    return Errors::noErrors;
}

SpiModes SpiConfigure::Mode() const
{
    return CurrentMode;
}
Errors SpiConfigure::setMode(SpiModes mode){
    int ret = 0;
    static quint8 modus = 0;
    switch (mode)
    {
    case SpiModes::notCpohNotCpol:
        modus = SPI_MODE_0;
        ret = ioctl(dev, SPI_IOC_WR_MODE, &modus);
        if (ret < 0)
            return Errors::failSetMode;
        CurrentMode = SpiModes::notCpohNotCpol;
    break;

    case SpiModes::cpha:
        modus = SPI_MODE_1;
        ret = ioctl(dev, SPI_IOC_WR_MODE, &modus);
        if (ret < 0)
            return Errors::failSetMode;
        CurrentMode = SpiModes::cpha;
        break;

    case SpiModes::cpol:
        modus = SPI_MODE_2;
        ret = ioctl(dev, SPI_IOC_WR_MODE, &modus);
        if (ret < 0)
            return Errors::failSetMode;
        CurrentMode = SpiModes::cpol;
    break;

    case SpiModes::cphaAndCpol:
        modus = SPI_MODE_3;
        ret = ioctl(dev, SPI_IOC_WR_MODE, &modus);
        if (ret < 0)
            return Errors::failSetMode;
        CurrentMode = SpiModes::cphaAndCpol;
    break;

    default:
        break;
    }
    return Errors::noErrors;
}

Config SpiConfigure::SpiFrequency() const
{
    return CurrentSpiFreq;
}
Errors SpiConfigure::setSpiFrequency(Config freq)
{
    int ret = 0;
    ret = ioctl(dev, SPI_IOC_WR_MAX_SPEED_HZ, &freq);
    if(ret<0)
        return Errors::failSetSpiFreq;
    return Errors::noErrors;
}

//check 29 bit of word and that check if data word < 0
bool check_minus(QVector<quint8> wordArray)
{
    return (wordArray[0]  &  16); //16 = 10000
}

//check 30,31 bits of word and return true only if 11
bool isLegalWord(QVector<quint8> wordArray)
{
    return ((wordArray[0] & 96) == 96);   //96 = 1100000
}
//check 30,31 bits of word that data and return true only if 00
bool isLegalData(QVector<quint8> wordArray)
{
    return ( (wordArray[0] & 96) == 0);
}

//Return usefull data  from arinc 4 byte message.
//Length of data get from length parameter
quint32 convert_data_word32(QVector<quint8> wordArray,ArincDataLength length, bool sign = false,int msb = 20)
{
    printf("%s","Thats convert : ");
    int shift = msb - static_cast<int>(length);
    quint32 word = 0;
    word |= wordArray[0];
    word <<= 8;
    word |= wordArray[1];
    word <<= 8;
    word |= wordArray[2];
     printf("after cut word == %x\n",word);
    int i = (( 1 << (24-msb)) -1);         // bin 1111
    i <<= msb;                        // bin 11110000 00000000 00000000
    word &= ~i;
     printf("after ~i word == %x\n",word);
    word >>= shift;
     printf("after shift word == %x\n",word);
    //printf("word == %x\n",word);
    if(sign)
    {
        // if word < 0 then need to convert to additional code
        int k = (1 << static_cast<int>(length)) - 1;    //bin 1111 11111111 11111111
        word ^= k;
        word++;
         printf("after sign word == %x\n",word);
        return word;
    }
    printf("final word == %x\n",word);
    return word;
}

//Copy constructor
Arinc::Arinc(const Arinc &object):QObject(),LookUpTable(object.LookUpTable)
{
        setAclk(object.Aclk());
        //SetTransmitControlBit(object.transmitControlBit());
        setReceive1ControlBit(object.receive1ControlBit());
        setReceive1ControlBit(object.receive2ControlBit());
        setLookUpTable(LookUpTable);
}

Arinc & Arinc::operator =(const Arinc &rhs)
{
    if(this == &rhs) return *this;
    LookUpTable = rhs.LookUpTable;
    setAclk(rhs.Aclk());
    //SetTransmitControlBit(object.transmitControlBit());
    setReceive1ControlBit(rhs.receive1ControlBit());
    setReceive1ControlBit(rhs.receive2ControlBit());
    setLookUpTable(rhs.LookUpTable);
    return *this;
}

//Default constructor
Arinc::Arinc()
{
    //MasterReset();
    //SoftReset();
    LookUpTable.resize(static_cast<int>(WordLength::lableTable32));
    CurrentMsg.resize(static_cast<int>(WordLength::arincWord4));
    Rec1Control.resize(static_cast<int>(WordLength::regBit1));
    Rec1BufferStatus.resize(static_cast<int>(WordLength::regBit1));
    Rec2Control.resize(static_cast<int>(WordLength::regBit1));
    Rec2BufferStatus.resize(static_cast<int>(WordLength::regBit1));
    TransmitControl.resize(static_cast<int>(WordLength::regBit1));
    TransmitStatus.resize(static_cast<int>(WordLength::regBit1));    
    setAclk(4);
    //SetTransmitControlBit(TransmitControlFlags::RATE);
    setReceive1ControlBit(ReceiverControlFlags::rate);
    setReceive1ControlBit(ReceiverControlFlags::labrec);
    setReceive1ControlBit(ReceiverControlFlags::rFlip);
    writeLabelToMemory(ArincCodeMessage::alt);
    writeLabelToMemory(ArincCodeMessage::date);
    writeLabelToMemory(ArincCodeMessage::grinvichTime);
    writeLabelToMemory(ArincCodeMessage::distanceToDest);
    writeLabelToMemory(ArincCodeMessage::lat);
    writeLabelToMemory(ArincCodeMessage::lng);
    writeLabelToMemory(ArincCodeMessage::speed);
    writeLabelToMemory(ArincCodeMessage::temperature);
    writeLabelToMemory(ArincCodeMessage::timeToDest);
    //setLookUpTable(LookUpTable);
}

//Read 1 4-byte message from Receive FIFO
QVector<quint8> Arinc::receive1Fifo()
{
    QVector<quint8> message(4);
    int res = read_bit(spiDevice.device(),static_cast<quint8>(Registers::rdMsgFromRec1Fifo),message.data(),static_cast<int>(WordLength::arincWord4));
    //if (res < 0)
    //    return ;
    CurrentMsg = message;
    return message;
}

//Write LookUpTable in LabelMemory and to current message
Errors Arinc::setLookUpTable(QVector<quint8> Table)
{
  if(Table.size() != static_cast<quint8>(WordLength::lableTable32))
    return Errors::wrongLableTableSize;
  int res = write_bit(spiDevice.device(),static_cast<quint8>(Registers::wrLabelToRec1Lmemory),Table.data(),Table.size());
  if (res < 0)
      return Errors::failSetLookUp;
  LookUpTable = Table;
  return Errors::noErrors;
}

//Get LookUpTable from object
QVector<quint8>  Arinc::getLookUpTable() const
{
    return LookUpTable;
}

//Clear Look-up table
Errors Arinc::clearLookUpTable()
{
    for(int i=0;i<LookUpTable.size();i++)
        LookUpTable[i] = static_cast<quint8>(Registers::empty);
    return setLookUpTable(LookUpTable);
}

//Write label to LookUpTable and rewrite it to LabelMemory
Errors Arinc::writeLabelToMemory(ArincCodeMessage msg)
{
    quint8 code = static_cast<quint8>(Registers::full) - static_cast<quint8>(msg) ;
    int idxTable = static_cast<quint8>(code/8);
    int idxBit = 7-static_cast<quint8>(code%8);
    LookUpTable[idxTable] = LookUpTable[idxTable] | (1<<idxBit);
    return setLookUpTable(LookUpTable);
}

//Remove label from LookUpTable and rewrite it to LabelMemory
Errors Arinc::clearLabelFromMemory(ArincCodeMessage msg)
{
    quint8 code = static_cast<quint8>(Registers::full) - static_cast<quint8>(msg) ;
    int idxTable = static_cast<quint8>(code/8);
    int idxBit = 7-static_cast<quint8>(code%8);
    LookUpTable[idxTable] = LookUpTable[idxTable] & (~(1<<idxBit));
    return setLookUpTable(LookUpTable);
}

// Read receive 1 control register
QVector<quint8> Arinc::receive1ControlBit() const
{
    return Rec1Control;
}

// Set receive 1 control register
Errors Arinc::setReceive1ControlBit(ReceiverControlFlags flag)
{
    QVector<quint8> byte = receive1ControlBit();
    byte[0] |= static_cast<quint8>(flag);
    int res = write_bit(spiDevice.device(), static_cast<quint8>(Registers::wrRec1Control),byte.data(),static_cast<int>(WordLength::regBit1));
    if(res<0)
        return Errors::failSetRec1ConBit;
    Rec1Control = byte;
    return Errors::noErrors;
}
// Set receive 1 control register
Errors Arinc::setReceive1ControlBit(QVector<quint8> byte)
{
    int res = write_bit(spiDevice.device(), static_cast<quint8>(Registers::wrRec1Control),byte.data(),static_cast<int>(WordLength::regBit1));
    if(res<0)
        return Errors::failSetRec1ConBit;
    Rec1Control = byte;
    return Errors::noErrors;
}

// Read receive 2 control register
QVector<quint8> Arinc::receive2ControlBit() const
{
    return Rec2Control;
}

// Set receive 2 control register
Errors Arinc::setReceive2ControlBit(ReceiverControlFlags flag)
{
    QVector<quint8> byte = receive1ControlBit();
    byte[0] |= static_cast<quint8>(flag);
    int res = write_bit(spiDevice.device(), static_cast<quint8>(Registers::wrRec2Control) ,byte.data(),static_cast<int>(WordLength::regBit1));
    if(res<0)
        return Errors::failSetRec2ConBit;
    Rec2Control = byte;
    return Errors::noErrors;
}
// Set receive 2 control register
Errors Arinc::setReceive2ControlBit(QVector<quint8> byte)
{
    int res = write_bit(spiDevice.device(), static_cast<quint8>(Registers::wrRec2Control) ,byte.data(),static_cast<int>(WordLength::regBit1));
    if(res<0)
        return Errors::failSetRec2ConBit;
    Rec2Control = byte;
    return Errors::noErrors;
}

// Read transmit control register
QVector<quint8> Arinc::transmitControlBit() const
{
    return TransmitControl;
}

// Set transmit control register
Errors Arinc::setTransmitControlBit(TransmitControlFlags tcl)
{
    QVector<quint8> byte = transmitControlBit();
    byte[0] |= static_cast<quint8>(tcl);
    int res = write_bit(spiDevice.device(),static_cast<quint8>(Registers::wrTransmitControl),byte.data(),static_cast<int>(WordLength::regBit1));
    if(res<0)
        return Errors::failSetTransmitConBit;
    TransmitControl = byte;
    return Errors::noErrors;
}

//Set aclk division register
Errors Arinc::setAclk(int Mhz)
{
    if(Mhz <= 1 && Mhz >= 30)
        return Errors::wrongAclk;
    QVector<quint8> byte = {static_cast<quint8>(Mhz)};
    int res = write_bit(spiDevice.device(),static_cast<quint8>(Registers::wrAclk),byte.data(),static_cast<int>(WordLength::regBit1));
    if(res<0)
        return Errors::failSetAclk;
    CurrentAclk = Mhz;
    return Errors::noErrors;
}

//Read aclk division register
int Arinc::Aclk() const
{
    return CurrentAclk;
}

//Check status of Receive1 FIFO
QVector<quint8> Arinc::receive1StatusRegister() const
{
    QVector<quint8> byte(1);
    int res = read_bit(spiDevice.device(),static_cast<quint8>(Registers::rdRec1Stat),byte.data(),static_cast<int>(WordLength::regBit1));
    return byte;
}

void Arinc::checkFifo()
{
    QVector<quint8> byte = receive1StatusRegister();
    if(byte[0] != 1)       // buffer not empty
    {
        //printf("отправлено\n");
//        qDebug() << endl<<"checkfifo thread is: "<< QThread::currentThread()<<"main thread is" \
//                 << QCoreApplication::instance()->thread();
        emit MessageReceived();
    }
    return;
}

void Arinc::parseWord()
{
    quint32 word = 0;
    double grade = 0;
    QVector<quint8> message = receive1Fifo();
//    qDebug() <<endl<< "parseword thread is: "<< QThread::currentThread()<<"main thread is" \
//             << QCoreApplication::instance()->thread();
    switch (message[3])       //3 - index of arinc word which is label
    {
    case static_cast<int>(ArincCodeMessage::lat):
        if(isLegalWord(message))
        {
            word = convert_data_word32(message,ArincDataLength::latLength,check_minus(message));
            grade = static_cast<double>(word) * static_cast<double>(GeoParse::latPrice);      //0,000172 price for 1 bit to degree of latitude
            geo.setLatitude(grade);
            printf("%f = Come lat\n",grade);
        }
        break;
    case static_cast<int>(ArincCodeMessage::lng):
        if(isLegalWord(message))
        {
            word = convert_data_word32(message,ArincDataLength::longLength,check_minus(message));
            grade = static_cast<double>(word) * static_cast<double>(GeoParse::lngPrice);      //0,000172 price for 1 bit to degree of longitide
            geo.setLongitude(grade);
            printf("%f = Come lng\n",grade);
        }
        break;
    case static_cast<int>(ArincCodeMessage::alt):
        if(isLegalWord(message))
        {
            word = convert_data_word32(message,ArincDataLength::altLength,check_minus(message));
            grade = static_cast<double>(word) * static_cast<double>(GeoParse::altPrice);
            geo.setAlt(grade);
            printf("%f = Come alt\n", grade);
        }
        break;
    case static_cast<int>(ArincCodeMessage::distanceToDest):
        if(isLegalWord(message))
        {
            word = convert_data_word32(message,ArincDataLength::distanceLength);
            grade = static_cast<double>(word)*static_cast<double>(GeoParse::distancePrice);
            geo.setKmToDest(grade);
            printf("%f = Come kmtodest\n", grade);
        }
        break;
    case static_cast<int>(ArincCodeMessage::timeToDest):
        if(isLegalWord(message))
        {
            word = convert_data_word32(message,ArincDataLength::timeLength);
            grade  = static_cast<int>(word)*static_cast<double>(GeoParse::timePrice);
            int hour = grade/60;
            int min = static_cast<int>(grade)%60;
            QTime time = QTime(hour,min);
            geo.setTimeToDest(time);
            printf("%f = Come timetodest\n", grade);
        }
        break;
    case static_cast<int>(ArincCodeMessage::speed):
        if(isLegalWord(message))
        {
            word = convert_data_word32(message,ArincDataLength::speedLength);
            grade = static_cast<double>(word)*static_cast<double>(GeoParse::speedPrice);  //km in hour
            geo.setSpeed(grade);
            printf("%f = Come speed\n", grade);
        }
        break;
    case static_cast<int>(ArincCodeMessage::temperature):
        if(isLegalWord(message))
        {
            word = convert_data_word32(message,ArincDataLength::tempLength,check_minus(message));
            grade = (static_cast<double>(word))*(static_cast<double>(GeoParse::tempPrice));
            geo.setTemperature(grade);
            printf("%f = Come temp\n", grade);
        }
        break;
    case static_cast<int>(ArincCodeMessage::grinvichTime):
        if(isLegalWord(message))
        {
            word = convert_data_word32(message,ArincDataLength::grinvichLength);
            int sec = word & 63;                    //bin 63     =  11 1111
            int min = ((word & 4032) >> 6);         //bin 4032   =  1111 1100 0000
            int hour = ((word & 126976) >> 12);     //bin 126976 =  1 1111 0000 0000 0000
            QTime time = QTime(hour,min,sec);
            geo.setGrinvichTime(time);
            qDebug() << endl<< time ;
            printf("%f hr %f min %f sec = Come grtime\n",time.hour(),time.minute(),time.minute());
        }
        break; 
    case static_cast<int>(ArincCodeMessage::date):
        if(isLegalData(message))
        {
            word = convert_data_word32(message,ArincDataLength::dateLength, false,21);
            int day = ((word & 393216)>>17)*10 + ((word & 122880)>>13);
            int month = ((word & 4096)>>12)*10 + (( word & 3840)>>8);
            int year = ((word & 240)>>4)*10 + (word & 15);
            QDate date = QDate(year,month,day);
            geo.setDate(date);
            qDebug() <<endl << date;
            printf("%f year %f month %f day  = Come date\n", date.year(),date.month(),date.day());
        }
        break;
    default:
        break;
    }
    return;
}

//Check status of Receive2 FIFO
QVector<quint8> Arinc::receive2StatusRegister() const
{
    QVector<quint8> byte(1);
    int res = read_bit(spiDevice.device(),static_cast<quint8>(Registers::rdRec2Stat),byte.data(),static_cast<int>(WordLength::regBit1));
    return byte;
}

//Check status of transmit FIFO
QVector<quint8> Arinc::transmitStatusRegister() const
{
    QVector<quint8> byte(1);
    int res = read_bit(spiDevice.device(),static_cast<quint8>(Registers::rdTransmitStat),byte.data(),static_cast<int>(WordLength::regBit1));
    return byte;
}

//Clears the Transmit and Receive FIFO and Priority Label Registers
Errors Arinc::softReset()
{
    int res = write_bit(spiDevice.device(),static_cast<quint8>(Registers::wrSoftReset),nullptr,static_cast<int>(WordLength::emptyWord));
    if(res<0)
        return Errors::failSoftReset;
    return Errors::noErrors;
}

Errors Arinc::masterReset()
{
    int res = write_bit(spiDevice.device(),static_cast<quint8>(Registers::wrMasterReset),nullptr,static_cast<int>(WordLength::emptyWord));
    if(res<0)
        return Errors::failMasterReset;
    return Errors::noErrors;
}


