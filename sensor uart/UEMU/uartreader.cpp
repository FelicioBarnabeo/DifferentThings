#include "uartreader.h"
#include "device.h"
#include <QDebug>

UartReader::UartReader(QObject *parent) :
    QSerialPort(parent)
{
    setBaudRate(QSerialPort::Baud57600);
    setDataBits(QSerialPort::Data8);
    setParity(QSerialPort::NoParity);
    setStopBits(QSerialPort::OneStop);
    setFlowControl(QSerialPort::NoFlowControl);

    connect(this, &UartReader::readyRead, this, &UartReader::readDataFromSerial);

    for (int i = 0; i<5; ++i) {
        Device *dev =  new Device();
        dev->setAddress(i);

        dev->setState(DeviceStates::Ignored);
        dev->setStateUI("Ignored");
        serialDevices.append(dev);
    }
}

void UartReader::readDataFromSerial(void)
{
    m_buffer.append(this->readAll());

    // get device data one by one
    while (m_buffer.size() >= Frame::Size) {
        if (m_buffer.at(Frame::Start) != Frame::StartMagicNumber ||
             m_buffer.at(Frame::Stop) != Frame::StopMagicNumber) {
            m_buffer.remove(0,1);
            continue;
        }

        QByteArray tmp = m_buffer.left(Frame::Size);
        m_buffer.remove(0,Frame::Size);

        // is it a bad frame? just skip it
        if (tmp.at(Frame::Start) != Frame::StartMagicNumber ||
             tmp.at(Frame::Stop) != Frame::StopMagicNumber) {
            break;
        }

        //fill device
        foreach (QObject *item,  serialDevices) {
            Device *device = qobject_cast<Device*>(item);
            if (device->address() == tmp.at(Frame::Source)) {
                fillDevice(tmp, device);
                break;
            }
        }
    }
}

void UartReader::fillDevice(const QByteArray tmp, Device *device)
{
    device->setAddress(tmp.at(Frame::Source));

    device->setCurrentSamplesCount(tmp.at(Frame::CSamplesCount)*10) ;
    device->setTemperatureSamplesCount(tmp.at(Frame::TSamplesCount)*10);
    device->setVoltageSamplesCount(tmp.at(Frame::VSamplesCount)*10);

    quint32 val;
    val = (static_cast<quint8>(tmp.at(Frame::VByte0)))<<24 |
          (static_cast<quint8>(tmp.at(Frame::VByte1)))<<16 |
          (static_cast<quint8>(tmp.at(Frame::VByte2)))<<8  |
           static_cast<quint8>(tmp.at(Frame::VByte3));
    device->setOutputVoltage(sqrt(val*DeviceInfo::AdcScaleFactorSquare/device->voltageSamplesCount()));

    val = static_cast<quint8>(tmp.at(Frame::CByte0))<<24 |
          static_cast<quint8>(tmp.at(Frame::CByte1))<<16 |
          static_cast<quint8>(tmp.at(Frame::CByte2))<<8  |
          static_cast<quint8>(tmp.at(Frame::CByte3));
    if (val & 0x80000000) {
        val = val & 0x7FFFFFFF;
        device->setOutputCurrent(-sqrt(val*DeviceInfo::AdcScaleFactorSquare/device->currentSamplesCount()));
    } else {
        device->setOutputCurrent(sqrt(val*DeviceInfo::AdcScaleFactorSquare/device->currentSamplesCount()));
    }

    val = static_cast<quint8>(tmp.at(Frame::TByte0))<<24 |
          static_cast<quint8>(tmp.at(Frame::TByte1))<<16 |
          static_cast<quint8>(tmp.at(Frame::TByte2))<<8  |
          static_cast<quint8>(tmp.at(Frame::TByte3));
    device->setTemperature(val*DeviceInfo::AdcScaleFactor/device->temperatureSamplesCount());

    val = static_cast<quint8>(tmp.at(Frame::VMByte0))<<24 |
          static_cast<quint8>(tmp.at(Frame::VMByte1))<<16 |
          static_cast<quint8>(tmp.at(Frame::VMByte2))<<8  |
          static_cast<quint8>(tmp.at(Frame::VMByte3));
    device->setVoltageManifold(val*DeviceInfo::AdcScaleFactor);

    val = static_cast<quint8>(tmp.at(Frame::CMByte0))<<24 |
          static_cast<quint8>(tmp.at(Frame::CMByte1))<<16 |
          static_cast<quint8>(tmp.at(Frame::CMByte2))<<8  |
          static_cast<quint8>(tmp.at(Frame::CMByte3));
    device->setCurrentManifold(val*DeviceInfo::AdcScaleFactor);

    val = static_cast<quint8>(tmp.at(Frame::CDByte0))<<8 |
          static_cast<quint8>(tmp.at(Frame::CDByte1));
    if (val & 0x8000) {
        val = val & 0x7FFF;
        device->setCurrentDirection(-val);
    } else {
        device->setCurrentDirection(val);
    }

    val = static_cast<quint8>(tmp.at(Frame::DDByte0))<<8 |
          static_cast<quint8>(tmp.at(Frame::DDByte1));
    device->setDeltaDuty(-val);

    device->setState(tmp.at(Frame::State));

    switch (device->state()) {
    case DeviceStates::Ignored: device->setStateUI("Ignored"); break;
    case DeviceStates::Prepare: device->setStateUI("Prepare"); break;
    case DeviceStates::Stopped: device->setStateUI("Stopped"); break;
    case DeviceStates::Runned: device->setStateUI("Runned"); break;
    case DeviceStates::Overheat: device->setStateUI("Overheat"); break;
    case DeviceStates::Overload: device->setStateUI("Overload"); break;
    case DeviceStates::Blocked: device->setStateUI("Blocked"); break;
    case DeviceStates::Unblocked: device->setStateUI("Unblocked"); break;
    default: break;
    }

    QString data("  ");
    for (quint8 i=0; i<tmp.count(); ++i) data = data + QString::number((quint8)tmp.at(i),16)+"  ";
    device->setRawData(data.toUpper());

    data.clear();
    data += " " + QString::number((quint8)tmp.at(Frame::VByte0),16);
    data += " " + QString::number((quint8)tmp.at(Frame::VByte1),16);
    data += " " + QString::number((quint8)tmp.at(Frame::VByte2),16);
    data += " " + QString::number((quint8)tmp.at(Frame::VByte3),16);
    device->setRawVoltage(data.toUpper());

    data.clear();
    data += " " + QString::number((quint8)tmp.at(Frame::CByte0),16);
    data += " " + QString::number((quint8)tmp.at(Frame::CByte1),16);
    data += " " + QString::number((quint8)tmp.at(Frame::CByte2),16);
    data += " " + QString::number((quint8)tmp.at(Frame::CByte3),16);
    device->setRawCurrent(data.toUpper());

    data.clear();
    data += " " + QString::number((quint8)tmp.at(Frame::TByte0),16);
    data += " " + QString::number((quint8)tmp.at(Frame::TByte1),16);
    data += " " + QString::number((quint8)tmp.at(Frame::TByte2),16);
    data += " " + QString::number((quint8)tmp.at(Frame::TByte3),16);
    device->setRawTemperature(data.toUpper());

    data.clear();
    data += " " + QString::number((quint8)tmp.at(Frame::CMByte0),16);
    data += " " + QString::number((quint8)tmp.at(Frame::CMByte1),16);
    data += " " + QString::number((quint8)tmp.at(Frame::CMByte2),16);
    data += " " + QString::number((quint8)tmp.at(Frame::CMByte3),16);
    device->setRawCurrentManifold(data.toUpper());

    data.clear();
    data += " " + QString::number((quint8)tmp.at(Frame::VMByte0),16);
    data += " " + QString::number((quint8)tmp.at(Frame::VMByte1),16);
    data += " " + QString::number((quint8)tmp.at(Frame::VMByte2),16);
    data += " " + QString::number((quint8)tmp.at(Frame::VMByte3),16);
    device->setRawVoltageManifold(data.toUpper());

    data.clear();
    data += " " + QString::number((quint8)tmp.at(Frame::CDByte0),16);
    data += " " + QString::number((quint8)tmp.at(Frame::CDByte1),16);
    device->setRawCurrentDirection(data.toUpper());
}

void UartReader::setQmlContext(QQmlContext *arg)
{
    m_ctx = arg;
}

void UartReader::updateContext(void)
{
    m_ctx->setContextProperty("Devices", QVariant::fromValue(this->serialDevices));
}
