#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>

class Device : public QObject
{
    Q_OBJECT

    Q_PROPERTY(quint16 address READ address WRITE setAddress NOTIFY addressChanged)
    Q_PROPERTY(quint16 state READ state WRITE setState NOTIFY stateChanged)
    Q_PROPERTY(QString stateUI READ stateUI WRITE setStateUI NOTIFY stateUIChanged)
    Q_PROPERTY(quint16 currentSamplesCount READ currentSamplesCount WRITE setCurrentSamplesCount NOTIFY currentSamplesCountChanged)
    Q_PROPERTY(quint16 temperatureSamplesCount READ temperatureSamplesCount WRITE setTemperatureSamplesCount NOTIFY currentSamplesCountChanged)
    Q_PROPERTY(quint16 voltageSamplesCount READ voltageSamplesCount WRITE setVoltageSamplesCount NOTIFY voltageSamplesCountChanged)
    Q_PROPERTY(quint32 voltageManifold READ voltageManifold WRITE setVoltageManifold NOTIFY voltageManifoldChanged)
    Q_PROPERTY(quint32 currentManifold READ currentManifold WRITE setCurrentManifold NOTIFY currentManifoldChanged)
    Q_PROPERTY(qint32 currentDirection READ currentDirection WRITE setCurrentDirection NOTIFY currentDirectionChanged)
    Q_PROPERTY(qint32 deltaDuty READ deltaDuty WRITE setDeltaDuty NOTIFY deltaDutyChanged)
    Q_PROPERTY(double temperature READ temperature WRITE setTemperature NOTIFY temperatureChanged)
    Q_PROPERTY(double outputVoltage READ outputVoltage WRITE setOutputVoltage NOTIFY outputVoltageChanged)
    Q_PROPERTY(double outputCurrent READ outputCurrent WRITE setOutputCurrent NOTIFY outputCurrentChanged)
    Q_PROPERTY(QString rawData READ rawData WRITE setRawData NOTIFY rawDataChanged)
    Q_PROPERTY(QString rawVoltage READ rawVoltage WRITE setRawVoltage NOTIFY rawVoltageChanged)
    Q_PROPERTY(QString rawCurrent READ rawCurrent WRITE setRawCurrent NOTIFY rawCurrentChanged)
    Q_PROPERTY(QString rawTemperature READ rawTemperature WRITE setRawTemperature NOTIFY rawTemperatureChanged)
    Q_PROPERTY(QString rawCurrentManifold READ rawCurrentManifold WRITE setRawCurrentManifold NOTIFY rawCurrentManifoldChanged)
    Q_PROPERTY(QString rawVoltageManifold READ rawVoltageManifold WRITE setRawVoltageManifold NOTIFY rawVoltageManifoldChanged)
    Q_PROPERTY(QString rawCurrentDirection READ rawCurrentDirection WRITE setRawCurrentDirection NOTIFY rawCurrentDirectionChanged)


private:
    quint16 m_address;
    quint16 m_state;
    quint16 m_currentSamplesCount;
    quint16 m_temperatureSamplesCount;
    quint16 m_voltageSamplesCount;
    double  m_outputVoltage;
    double  m_outputCurrent;
    double  m_temperature;

    QString m_stateUI;
    QString m_rawData;

    QString m_rawVoltage;
    QString m_rawCurrent;
    QString m_rawTemperature;

    quint32 m_voltageManifold;
    quint32 m_currentManifold;
    qint32  m_currentDirection;

    QString m_rawCurrentManifold;
    QString m_rawVoltageManifold;
    QString m_rawCurrentDirection;

    qint32 m_deltaDuty;

public:
    explicit Device(QObject *parent = 0);
    Device(quint16 addr, quint16 csc, quint16 tsc, double outV,
                   double outI, quint16 vsc, quint16 st, double temp, QObject* parent = 0);
    quint16 currentSamplesCount(void) const;
    quint16 temperatureSamplesCount(void) const;
    quint16 voltageSamplesCount(void) const;
    quint16 state(void) const;
    quint16 address(void) const;
    double  outputVoltage(void) const;
    double  temperature(void) const;
    double  outputCurrent(void) const;

    QString stateUI() const;
    QString rawData() const;

    QString rawVoltage() const;
    QString rawCurrent() const;
    QString rawTemperature() const;

    quint32 voltageManifold() const;
    quint32 currentManifold() const;
    int32_t currentDirection() const;

    QString rawCurrentManifold() const;
    QString rawVoltageManifold() const;
    QString rawCurrentDirection() const;

    qint32 deltaDuty() const;

signals:
    void addressChanged(quint16 arg);
    void stateChanged(quint16 arg);
    void currentSamplesCountChanged(quint16 arg);
    void temperatureSamplesCountChanged(quint16 arg);
    void voltageSamplesCountChanged(quint16 arg);
    void outputVoltageChanged(double arg);
    void temperatureChanged(double arg);
    void outputCurrentChanged(double arg);

    void stateUIChanged(QString stateUI);
    void rawDataChanged(QString rawData);

    void rawVoltageChanged(QString rawVoltage);
    void rawCurrentChanged(QString rawCurrent);
    void rawTemperatureChanged(QString rawTemperature);

    void voltageManifoldChanged(quint32 voltageManifold);
    void currentManifoldChanged(quint32 currentManifold);
    void currentDirectionChanged(int32_t currentDirection);

    void rawCurrentManifoldChanged(QString rawCurrentManifold);
    void rawVoltageManifoldChanged(QString rawVoltageManifold);
    void rawCurrentDirectionChanged(QString rawCurrentDirection);

    void deltaDutyChanged(qint32 arg);

public slots:
    void setCurrentSamplesCount(const quint16 arg);
    void setTemperatureSamplesCount(const quint16 arg);
    void setOutputVoltage(const double arg);
    void setVoltageSamplesCount(const quint16 arg);
    void setState(const quint16 arg);
    void setTemperature(const double arg);
    void setAddress(const quint16 arg);
    void setOutputCurrent(const double arg);
    void setStateUI(QString stateUI);
    void setRawData(QString rawData);
    void setRawVoltage(QString rawVoltage);
    void setRawCurrent(QString rawCurrent);
    void setRawTemperature(QString rawTemperature);
    void setVoltageManifold(quint32 voltageManifold);
    void setCurrentManifold(quint32 currentManifold);
    void setCurrentDirection(int32_t currentDirection);
    void setRawCurrentManifold(QString rawCurrentManifold);
    void setRawVoltageManifold(QString rawCurrentVoltage);
    void setRawCurrentDirection(QString rawCurrentDirection);
    void setDeltaDuty(qint32 arg);
};

#endif // DEVICES_H
