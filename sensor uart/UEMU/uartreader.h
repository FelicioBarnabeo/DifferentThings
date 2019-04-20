#ifndef UARTREADER_H
#define UARTREADER_H

#include <QtSerialPort/QSerialPort>
#include "device.h"
#include <QQmlContext>

namespace Frame {
enum  {
    Start,
    Source,

    VByte0,
    VByte1,
    VByte2,
    VByte3,

    CByte0,
    CByte1,
    CByte2,
    CByte3,

    TByte0,
    TByte1,
    TByte2,
    TByte3,

    VMByte0,
    VMByte1,
    VMByte2,
    VMByte3,

    CMByte0,
    CMByte1,
    CMByte2,
    CMByte3,

    CDByte0,
    CDByte1,

    DDByte0,
    DDByte1,

    VSamplesCount,
    CSamplesCount,
    TSamplesCount,

    State,
    Stop,

    Size = 31,
    StartMagicNumber = -1,
    StopMagicNumber = -2,
};
}

namespace DeviceInfo {
enum {
    VoltageScaleFactor = 10,
    CurrentScaleFactor = 10,
    TemperatureScaleFactor = 10,
    FloatScaleFactor = 1000,
};

static double AdcScaleFactor = 0.0008056640625L;
static double AdcScaleFactorSquare = 0.000000649094581604L;
}

namespace DeviceStates {
enum {
    Prepare = 0x01,
    Stopped,
    Runned,
    Overheat,
    Overload,
    Blocked,
    Unblocked,
    Ignored = 0x77
};
}

class UartReader : public QSerialPort
{
    Q_OBJECT

private:
    QByteArray m_buffer;
    QQmlContext *m_ctx;

public:
    explicit UartReader(QObject *parent = 0);
    void fillDevice(const QByteArray tmp, Device *device);

    QList<QObject*> serialDevices;
    void setQmlContext(QQmlContext *arg);

    void updateContext(void);

signals:

public slots:
    void readDataFromSerial(void);
};

#endif // UARTREADER_H
