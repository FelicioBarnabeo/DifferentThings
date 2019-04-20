#include "device.h"

Device::Device(QObject *parent) :
    Device(0,0,0,0,0,0,0,0, parent)
{
    // nothing to do here
}

Device::Device(quint16 addr, quint16 csc, quint16 tsc, double outV,
               double outI, quint16 vsc, quint16 st, double temp, QObject* parent):
    m_address(addr),  m_currentSamplesCount(csc), m_temperatureSamplesCount(tsc),
    m_outputVoltage(outV), m_outputCurrent(outI), m_voltageSamplesCount(vsc),
    m_temperature(temp), m_state(st), m_rawData(" "), m_rawCurrent(" "),
    m_rawTemperature(" "), m_rawVoltage(" "), m_currentDirection(0),
    m_currentManifold(0), m_voltageManifold(0), m_rawCurrentDirection(" "),
    m_rawVoltageManifold(" "), m_rawCurrentManifold(" "), m_deltaDuty(0)
{
    // nothing to do here
}

void Device::setCurrentSamplesCount(const quint16 arg)
{
    if (m_currentSamplesCount != arg) {
        m_currentSamplesCount = arg;
        emit currentSamplesCountChanged(arg);
    }
}

void Device::setTemperatureSamplesCount(const quint16 arg)
{
    if (m_temperatureSamplesCount != arg) {
        m_temperatureSamplesCount = arg;
        emit temperatureSamplesCountChanged(arg);
    }
}

void Device::setOutputVoltage(double arg)
{
    if (m_outputVoltage != arg) {
        m_outputVoltage = arg;
        emit outputVoltageChanged(arg);
    }
}

void Device::setOutputCurrent(double arg)
{
    if (m_outputCurrent != arg) {
        m_outputCurrent = arg;
        emit outputCurrentChanged(arg);
    }
}

void Device::setStateUI(QString stateUI)
{
    if (m_stateUI == stateUI)
        return;

    m_stateUI = stateUI;
    emit stateUIChanged(stateUI);
}

void Device::setRawData(QString rawData)
{
    if (m_rawData == rawData)
        return;

    m_rawData = rawData;
    emit rawDataChanged(rawData);
}

void Device::setRawVoltage(QString rawVoltage)
{
    if (m_rawVoltage == rawVoltage)
        return;

    m_rawVoltage = rawVoltage;
    emit rawVoltageChanged(rawVoltage);
}

void Device::setRawCurrent(QString rawCurrent)
{
    if (m_rawCurrent == rawCurrent)
        return;

    m_rawCurrent = rawCurrent;
    emit rawCurrentChanged(rawCurrent);
}

void Device::setRawTemperature(QString rawTemperature)
{
    if (m_rawTemperature == rawTemperature)
        return;

    m_rawTemperature = rawTemperature;
    emit rawTemperatureChanged(rawTemperature);
}

void Device::setVoltageManifold(quint32 voltageManifold)
{
    if (m_voltageManifold == voltageManifold)
        return;

    m_voltageManifold = voltageManifold;
    emit voltageManifoldChanged(voltageManifold);
}

void Device::setCurrentManifold(quint32 currentManifold)
{
    if (m_currentManifold == currentManifold)
        return;

    m_currentManifold = currentManifold;
    emit currentManifoldChanged(currentManifold);
}

void Device::setCurrentDirection(int32_t currentDirection)
{
    if (m_currentDirection == currentDirection)
        return;

    m_currentDirection = currentDirection;
    emit currentDirectionChanged(currentDirection);
}

void Device::setRawCurrentManifold(QString rawCurrentManifold)
{
    if (m_rawCurrentManifold == rawCurrentManifold)
        return;

    m_rawCurrentManifold = rawCurrentManifold;
    emit rawCurrentManifoldChanged(rawCurrentManifold);
}

void Device::setRawCurrentDirection(QString rawCurrentDirection)
{
    if (m_rawCurrentDirection == rawCurrentDirection)
        return;

    m_rawCurrentDirection = rawCurrentDirection;
    emit rawCurrentDirectionChanged(rawCurrentDirection);
}

void Device::setDeltaDuty(qint32 arg)
{
    if (m_deltaDuty == arg)
        return;

    m_deltaDuty = arg;
    emit deltaDutyChanged(arg);
}

void Device::setRawVoltageManifold(QString rawVoltageManifold)
{
    if (m_rawVoltageManifold == rawVoltageManifold)
        return;

    m_rawVoltageManifold = rawVoltageManifold;
    emit rawVoltageManifoldChanged(rawVoltageManifold);
}

void Device::setVoltageSamplesCount(const quint16 arg)
{
    if (m_voltageSamplesCount != arg) {
        m_voltageSamplesCount = arg;
        emit voltageSamplesCountChanged(arg);
    }
}

void Device::setState(quint16 arg)
{
    if (m_state != arg) {
        m_state = arg;
        emit stateChanged(arg);
    }
}

void Device::setTemperature(double arg)
{
    if (m_temperature != arg) {
        m_temperature = arg;
        emit temperatureChanged(arg);
    }
}

void Device::setAddress(quint16 arg)
{
    if (m_address != arg) {
        m_address = arg;
        emit addressChanged(arg);
    }
}

quint16 Device::currentSamplesCount() const
{
    return m_currentSamplesCount;
}

quint16 Device::temperatureSamplesCount() const
{
    return m_temperatureSamplesCount;
}

double Device::outputVoltage() const
{
    return m_outputVoltage;
}

double Device::outputCurrent() const
{
    return m_outputCurrent;
}

QString Device::stateUI() const
{
    return m_stateUI;
}

QString Device::rawData() const
{
    return m_rawData;
}

QString Device::rawVoltage() const
{
    return m_rawVoltage;
}

QString Device::rawCurrent() const
{
    return m_rawCurrent;
}

QString Device::rawTemperature() const
{
    return m_rawTemperature;
}

quint32 Device::voltageManifold() const
{
    return m_voltageManifold;
}

quint32 Device::currentManifold() const
{
    return m_currentManifold;
}

int32_t Device::currentDirection() const
{
    return m_currentDirection;
}

QString Device::rawCurrentManifold() const
{
    return m_rawCurrentManifold;
}

QString Device::rawVoltageManifold() const
{
    return m_rawVoltageManifold;
}

QString Device::rawCurrentDirection() const
{
    return m_rawCurrentDirection;
}

qint32 Device::deltaDuty() const
{
    return m_deltaDuty;
}

quint16 Device::voltageSamplesCount() const
{
    return m_voltageSamplesCount;
}

quint16 Device::state() const
{
    return m_state;
}

double Device::temperature() const
{
    return m_temperature;
}

quint16 Device::address() const
{
    return m_address;
}
