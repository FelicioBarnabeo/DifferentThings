#include "serialdevice.h"
#include "settings.h"

SerialDevice::SerialDevice(QObject* parent): QSerialPort(parent),
    m_mapParity{
        {"NoParity",    Parity::NoParity},
        {"EvenParity",  Parity::EvenParity},
        {"OddParity",   Parity::OddParity},
        {"SpaceParity", Parity::SpaceParity},
        {"MarkParity",  Parity::MarkParity},
        {"UknownParity",Parity::UnknownParity}},

    m_mapDataBits{
        {"Data5",          DataBits::Data5},
        {"Data6",          DataBits::Data6},
        {"Data7",          DataBits::Data7},
        {"Data8",          DataBits::Data8},
        {"UnknownDataBits",DataBits::UnknownDataBits}},

    m_mapStopBits{
        {"OneStop",        StopBits::OneStop},
        {"OneAndHalfStop", StopBits::OneAndHalfStop},
        {"TwoStop",        StopBits::TwoStop},
        {"UnknownStopBits",StopBits::UnknownStopBits}}
{
}

const QString SerialDevice::currentBaudRate() const{
    return QString::number(baudRate());
}

void SerialDevice::setStringBaudRate(QString br){
    setBaudRate(br.toInt());
}

const QString SerialDevice::currentParity() const{
    return m_mapParity.key(parity());
}

void SerialDevice::setStringParity(QString pr){
    setParity(m_mapParity[pr]);
}

const QString SerialDevice::currentDataBits() const{
    return m_mapDataBits.key(dataBits());
}

void SerialDevice::setStringDataBits(QString db){
    setDataBits(m_mapDataBits[db]);
}

const QString SerialDevice::currentStopBits() const{
    return m_mapStopBits.key(stopBits());
}

void SerialDevice::setStringStopBits(QString sb){
    setStopBits(m_mapStopBits[sb]);
}

QList<QString> SerialDevice::listParity() const{
    return m_mapParity.keys();
}

QList<QString> SerialDevice::listStopBits() const{
    return m_mapStopBits.keys();
}

QList<QString> SerialDevice::listDataBits() const{
    return m_mapDataBits.keys();
}
