#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>

class Settings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString deviceName READ deviceName WRITE setDeviceName NOTIFY deviceNameChanged)
    Q_PROPERTY(QString parity READ parity WRITE setParity NOTIFY parityChanged)
    Q_PROPERTY(QString stopBits READ stopBits WRITE setStopBits NOTIFY stopBitsChanged)
    Q_PROPERTY(QString dataBits READ dataBits WRITE setDataBits NOTIFY dataBitsChanged)
    Q_PROPERTY(QString baudRate READ baudRate WRITE setbaudRate NOTIFY baudRateChanged)
    QSettings *m_settings;
    static Settings * m_instance;

    QString m_deviceName;
    QString m_parity;
    QString m_stopBits;
    QString m_dataBits;
    QString m_baudRate;

public:
    static Settings * instance();


    QString deviceName() const
    {
        return m_deviceName;
    }

    QString parity() const
    {
        return m_parity;
    }

    QString stopBits() const
    {
        return m_stopBits;
    }

    QString dataBits() const
    {
        return m_dataBits;
    }

    QString baudRate() const
    {
        return m_baudRate;
    }

    ~Settings();
public slots:

    void setDeviceName(QString deviceName)
    {
        if (m_deviceName == deviceName)
            return;

        m_deviceName = deviceName;
        m_settings->setValue("DeviceName",deviceName);
        emit deviceNameChanged(deviceName);
    }

    void setParity(QString parity)
    {
        if (m_parity == parity)
            return;

        m_parity = parity;
        m_settings->setValue("Parity",parity);
        emit parityChanged(parity);
    }

    void setStopBits(QString stopBits)
    {
        if (m_stopBits == stopBits)
            return;

        m_stopBits = stopBits;
        m_settings->setValue("StopBits",stopBits);
        emit stopBitsChanged(stopBits);
    }

    void setDataBits(QString dataBits)
    {
        if (m_dataBits == dataBits)
            return;

        m_dataBits = dataBits;
        m_settings->setValue("DataBits",dataBits);
        emit dataBitsChanged(dataBits);
    }

    void setbaudRate(QString baudRate)
    {
        if (m_baudRate == baudRate)
            return;

        m_baudRate = baudRate;
        m_settings->setValue("BaudRate",baudRate);
        emit baudRateChanged(baudRate);
    }

signals:
    void deviceNameChanged(QString deviceName);
    void parityChanged(QString parity);
    void stopBitsChanged(QString stopBits);
    void dataBitsChanged(QString dataBits);
    void baudRateChanged(QString baudRate);

protected:
    Settings(QObject *parent = 0);
};

#endif // SETTINGS_H
