#include "settings.h"

Settings::Settings(QObject *parent) : QObject(parent)
{
     m_settings   = new QSettings("settings.cfg",QSettings::IniFormat);
     m_deviceName = m_settings->value("DeviceName").toString();
     m_baudRate   = m_settings->value("BaudRate").toString();
     m_stopBits   = m_settings->value("StopBits").toString();
     m_dataBits   = m_settings->value("DataBits").toString();
     m_parity     = m_settings->value("Parity").toString();
}
Settings::~Settings()
{
    delete m_settings;
}

Settings * Settings::m_instance = 0;

Settings * Settings::instance()
{
    if(!m_instance)
        m_instance = new Settings();
    return m_instance;
}
