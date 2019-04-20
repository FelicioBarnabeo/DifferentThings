#include "serialdevice.h"
#include "settings.h"
#include "configurator.h"
#include <QDebug>


SerialDevice::SerialDevice(QObject *parent) : QObject(parent)
{
    m_settingsInstance = Settings::instance();
    m_serialPort = new QSerialPort(this);
    m_serialPort->setPortName(m_settingsInstance->ttyName());
    m_serialPort->setBaudRate(m_settingsInstance->baudrate());
    m_serialPort->setDataBits(QSerialPort::DataBits(m_settingsInstance->databits()));
    m_serialPort->setStopBits(QSerialPort::StopBits(m_settingsInstance->stopbits()));
    m_serialPort->setParity(QSerialPort::Parity(m_settingsInstance->parity()));
    if(! m_serialPort->open(QIODevice::ReadWrite)){
        qDebug()<<"Error. Cant open serial port "<<m_serialPort->portName();
        qDebug()<<m_serialPort->errorString();
    }
    m_serialPort->clear();
    m_state = SDStates::Default;
    m_configurator = Configurator::instance();
    m_waitForAnswerBP = new QTimer;
    m_holdBtnTimer = new QTimer;
    connect(m_waitForAnswerBP, &QTimer::timeout, this, &SerialDevice::uncheckBpStatus);
    connect(m_serialPort, &QSerialPort::readyRead, this, &SerialDevice::processCommand);
    connect(m_holdBtnTimer,&QTimer::timeout, this, &SerialDevice::writeCmd);
}

int SerialDevice::write(const QString & cmd)
{
    qDebug()<<"CMD writed = "<<cmd;
    m_innerBuffer.clear();
    int res = m_serialPort->write(QByteArray::fromHex(cmd.toLatin1())); //from "0xFFAA" -> Bytearray(FF, AA)
    m_serialPort->waitForBytesWritten(150);
    emit cmdSended(cmd);
    return res;
}


int SerialDevice::writeCmd()
{
    m_innerBuffer.clear();
    int res = m_serialPort->write(QByteArray::fromHex(m_cmd.toLatin1())); //from "0xFFAA" -> Bytearray(FF, AA)
    m_serialPort->waitForBytesWritten(150);
    emit cmdSended(m_cmd);
    return res;
}


void SerialDevice::sendCommand(QString cmd, QString directCmd)
{
    //qDebug()<<Q_FUNC_INFO<< " "<<cmd << " "<< directCmd;
    m_cmd = cmd;
    m_directCmd = directCmd;
    if ( cmd == m_configurator->lightUpperOn()      ||
         cmd == m_configurator->lightUpperOff()     ||
         cmd == m_configurator->lightBortOn()       ||
         cmd == m_configurator->lightBortOff()      ||
         cmd == m_configurator->lightOverBedOn()    ||
         cmd == m_configurator->lightOverBedOff()   ||
         cmd == m_configurator->lightHallBortOn()   ||
         cmd == m_configurator->lightHallBortOff()  ||
         cmd == m_configurator->lightHallUpperOn()  ||
         cmd == m_configurator->lightHallUpperOff() ||
         cmd == m_configurator->tvOn()              ||
         cmd == m_configurator->tvOff()             ||
         cmd == m_configurator->hdmiOn()            ||
         cmd == m_configurator->hdmiOff()           ||
         cmd == m_configurator->askDirectState() )
    {
        m_state = SDStates::StatusInCheck;
        write(m_configurator->getCurrentState());
        m_waitForAnswerBP->start(200);
        return;
    }
    else
    {
        m_state = SDStates::Default;
        write(cmd);
        return;
    }
}


void SerialDevice::startSendCmd(QString cmd)
{
    m_cmd = cmd;
    m_holdBtnTimer->start(100);
}

void SerialDevice::stopSendCmd()
{
    m_holdBtnTimer->stop();
}

void SerialDevice::processReceivedMsopState(unsigned char state)
{
    //Settings *settings = Settings::instance();
    int channelNmbNiche, channelNmbBort, channelNmbUpper, channelNmbTv, channelNmbHdmi;
    if(!m_configurator->hallSwitched())
    {
        channelNmbUpper = m_configurator->lightDirectUpperOn().right(1).toInt();
        channelNmbBort  = m_configurator->lightDirectBortOn().right(1).toInt();
        channelNmbNiche = m_configurator->lightDirectOverBedOn().right(1).toInt();
    }
    else{
        channelNmbUpper = m_configurator->lightHallDirectUpperOn().right(1).toInt();
        channelNmbBort = m_configurator->lightHallDirectBortOn().right(1).toInt();
        channelNmbNiche = m_configurator->lightDirectOverBedOn().right(1).toInt();
    }
    channelNmbTv    = m_configurator->tvOn().right(1).toInt();
    channelNmbHdmi  = m_configurator->hdmiOn().right(1).toInt();
    bool isUpper = state & (1 << (channelNmbUpper-1));
    bool isBort = state & (1 << (channelNmbBort-1));
    bool isNiche = state & (1 << (channelNmbNiche-1));
    bool isTv = state & (1 << (channelNmbTv-1));
    bool isHdmi = state & (1 << (channelNmbHdmi-1));
    if(!m_configurator->hallSwitched())
    {
        m_settingsInstance->setLightUpperState(isUpper);
        m_settingsInstance->setLightBortState(isBort);
        m_settingsInstance->setLightNicheState(isNiche);
    }
    else
    {
        m_settingsInstance->setLightHallUpperState(isUpper);
        m_settingsInstance->setLightHallBortState(isBort);
    }
    m_settingsInstance->setTvState(isTv);
    m_settingsInstance->setHdmiState(isHdmi);
    m_settingsInstance->sync();
    return;
}

//inverse msop, need fix this
void SerialDevice::catchBpCommand( QString cmd)
{
    if(cmd == m_configurator->msopLocalAnswer())
    {
        sendCommand(m_configurator->askDirectState(),m_configurator->askDirectState());
        return;
    }
    if(cmd == m_configurator->tvOn())               {m_settingsInstance->setTvState(true);   m_settingsInstance->sync();            return;}
    if(cmd == m_configurator->tvOff())              {m_settingsInstance->setTvState(false);  m_settingsInstance->sync();            return;}
    if(cmd == m_configurator->hdmiOn())             {m_settingsInstance->setHdmiState(true); m_settingsInstance->sync();            return;}
    if(cmd == m_configurator->hdmiOff())            {m_settingsInstance->setHdmiState(false);  m_settingsInstance->sync();          return;}
    if(cmd == m_configurator->lightHallUpperOn())   {m_settingsInstance->setLightHallUpperState(true); m_settingsInstance->sync();  return;}
    if(cmd == m_configurator->lightHallUpperOff())  {m_settingsInstance->setLightHallUpperState(false); m_settingsInstance->sync(); return;}
    if(cmd == m_configurator->lightHallBortOn())    {m_settingsInstance->setLightHallBortState(true); m_settingsInstance->sync();   return;}
    if(cmd == m_configurator->lightHallBortOff())   {m_settingsInstance->setLightHallBortState(false); m_settingsInstance->sync();  return;}
    if(cmd == m_configurator->lightUpperOn())       {m_settingsInstance->setLightUpperState(true); m_settingsInstance->sync();      return;}
    if(cmd == m_configurator->lightUpperOff())      {m_settingsInstance->setLightUpperState(false);m_settingsInstance->sync();      return;}
    if(cmd == m_configurator->lightBortOn())        {m_settingsInstance->setLightBortState(true); m_settingsInstance->sync();       return;}
    if(cmd == m_configurator->lightBortOff())       {m_settingsInstance->setLightBortState(false);m_settingsInstance->sync();       return;}
    if(cmd == m_configurator->lightOverBedOn())     {m_settingsInstance->setLightNicheState(true); m_settingsInstance->sync();      return;}
    if(cmd == m_configurator->lightOverBedOff())    {m_settingsInstance->setLightNicheState(false); m_settingsInstance->sync();     return;}
    //if(cmd == m_configurator->lightDecorOn())       {m_settingsInstance->setLightDecorState(true);  m_settingsInstance->sync();     return;}
    //if(cmd == m_configurator->lightDecorOff())      {m_settingsInstance->setLightDecorState(false); m_settingsInstance->sync();     return;}
    if(cmd == m_configurator->stateAirshow())       {m_settingsInstance->setAirshowState(true);    m_settingsInstance->sync();      return;}
    if(cmd == m_configurator->stateVideocamera())   {m_settingsInstance->setVideocameraState(true); m_settingsInstance->sync();     return;}
    if(cmd == m_configurator->stateDvdBluray())     {m_settingsInstance->setMenuDvdState(true);   m_settingsInstance->sync();       return;}
    if(cmd == m_configurator->stateAudio())         {m_settingsInstance->setMenuAudioState(true); m_settingsInstance->sync();      return;}
    if(cmd == m_configurator->stateVideo())         {m_settingsInstance->setMenuVideoState(true);  m_settingsInstance->sync();      return;}
    if(cmd == m_configurator->stateUSB())           {m_settingsInstance->setMenuUSBState(true);   m_settingsInstance->sync();       return;}
    if(cmd == m_configurator->currentLanguageRU())  {m_settingsInstance->setLang("ru");        m_settingsInstance->sync();          return;}
    if(cmd == m_configurator->currentLanguageENG()) {m_settingsInstance->setLang("en");        m_settingsInstance->sync();          return;}
    if(cmd == m_configurator->currentVolume0())     {m_settingsInstance->setCurrentVolume(0);  m_settingsInstance->sync();          return;}
    if(cmd == m_configurator->currentVolume1())     {m_settingsInstance->setCurrentVolume(1);  m_settingsInstance->sync();          return;}
    if(cmd == m_configurator->currentVolume2())     {m_settingsInstance->setCurrentVolume(2);  m_settingsInstance->sync();          return;}
    if(cmd == m_configurator->currentVolume3())     {m_settingsInstance->setCurrentVolume(3);  m_settingsInstance->sync();          return;}
    if(cmd == m_configurator->currentVolume4())     {m_settingsInstance->setCurrentVolume(4);  m_settingsInstance->sync();          return;}
    if(cmd == m_configurator->currentVolume5())     {m_settingsInstance->setCurrentVolume(5);  m_settingsInstance->sync();          return;}
    if(cmd == m_configurator->currentVolume6())     {m_settingsInstance->setCurrentVolume(6);  m_settingsInstance->sync();          return;}
    if(cmd == m_configurator->currentVolume7())     {m_settingsInstance->setCurrentVolume(7);  m_settingsInstance->sync();          return;}
    if(cmd == m_configurator->currentVolume8())     {m_settingsInstance->setCurrentVolume(8);  m_settingsInstance->sync();          return;}
    if(cmd == m_configurator->currentVolume9())     {m_settingsInstance->setCurrentVolume(9);  m_settingsInstance->sync();          return;}
    if(cmd == m_configurator->currentVolume10())    {m_settingsInstance->setCurrentVolume(10);  m_settingsInstance->sync();         return;}
}

void SerialDevice::processCommand(){
    while(m_serialPort->bytesAvailable() > 0 )
        m_innerBuffer.append(m_serialPort->readAll());
    //qDebug()<<"Readed: "<<m_innerBuffer.toHex().toUpper();
    while(m_innerBuffer.size() > 1)
    {
    switch (m_state)
    {
        case SDStates::StatusInCheck:
        {
            //qDebug()<<"in check";
            if(m_innerBuffer.size() < 3) return;
            //qDebug()<<"m_configurator.currentState = "<<m_configurator->currentState();
             while(m_innerBuffer.left(3).toHex().toUpper() !=  m_configurator->currentState()) {
                m_innerBuffer.remove(0,1);
                if (m_innerBuffer.size()<3) return;
            }
            m_waitForAnswerBP->stop();
            m_state = SDStates::StatusChecked;
            m_innerBuffer.remove(0,3);
            if(m_cmd != m_configurator->askDirectState())  // if msop send 8440 and is BP than not need send (840D - askDirectState)
            {
                write(m_cmd);
            }
            else{
                m_state = SDStates::Default;
            }
            break;
        }
        case SDStates::StatusChecked:
        {
            if (m_innerBuffer.size()<3) return;
            while (QString(m_innerBuffer.left(3).toHex().toUpper()) != m_configurator->commandComplete())
            {
                m_innerBuffer.remove(0,1);
                if (m_innerBuffer.size()<3) return;
            }
            m_state = SDStates::Default;
            m_innerBuffer.remove(0,3);
            break;
        }
        case SDStates::StatusUnchecked:
        {
            if(m_innerBuffer.size() < 2) return;
            while(m_innerBuffer.left(1).toHex().toUpper() != m_configurator->localAddressDevice())
            {
                m_innerBuffer.remove(0,1);
                if(m_innerBuffer.size() < 2) return;
            }
            m_innerBuffer.remove(0,2);
            write(m_configurator->askDirectState());
            m_state = SDStates::StatusDirectStage1;
            break;
        }
        case SDStates::StatusDirectStage1:
        {
            if(m_innerBuffer.size() < 4)
            {
                return;
            }
            while(m_innerBuffer.left(1).toHex().toUpper() != m_configurator->localAddressDevice()){
                m_innerBuffer.remove(0,1);
                if(m_innerBuffer.size() < 4) return;
            }
            //if receive 4 bytes than stop timer for reserve sending 840D - askDirectState
            //m_msopAnswerTimer->stop();
            m_state = SDStates::Default;
            //make uchar = 11111111 if all channels turn on
            unsigned char arg = m_innerBuffer.at(2);
            if (m_innerBuffer.at(3) & 0x01){
                arg = arg | 0x80;
            }
            m_innerBuffer.remove(0,4);
            processReceivedMsopState(arg);
            break;
        }

        default:
            if(m_innerBuffer.size() < 3) {
                return;
            }
            while(m_innerBuffer.left(1).toHex().toUpper() != "F0" && m_innerBuffer.left(2).toHex().toUpper() != m_configurator->askDirectState())
            {
                m_innerBuffer.remove(0,1);
                if(m_innerBuffer.size() < 3) return;
            }
            if( m_innerBuffer.left(1).toHex().toUpper() == "F0")
            {
                QString cmd = m_innerBuffer.toHex().toUpper().left(6);
                cmd.replace(0,2,m_configurator->addressDevice().toLatin1());
                qDebug()<<cmd;
                catchBpCommand(cmd);
                m_innerBuffer.remove(0,3);
            }
            else
            {
                m_state = SDStates::StatusDirectStage1;
                //sendCommand(m_configurator->askDirectState());
                m_innerBuffer.remove(0,2);
            }
            break;
    }
    }
}

void SerialDevice::uncheckBpStatus()
{
    //qDebug()<<"UNCHEK BP";
    m_waitForAnswerBP->stop();
    //if outer interact with msop(bv100, mpdu, bv67)
    if(m_cmd == m_configurator->askDirectState())
    {
        m_state = SDStates::Default;
        //m_state = SDStates::StatusDirectStage1;
    }
    //if inner interact with pzu
    else
    {
        m_state = SDStates::StatusUnchecked;
        write(m_directCmd);
    }
}

void SerialDevice::setStatus(int state)
{
    m_state = state;
}
