#include "command.h"

Command::Command(QString name, int interval, QByteArray msg):
    m_name(name)
  , m_message(msg)
  , m_sendIntervalTime(interval)
{
}

void Command::write(QJsonObject &json) const
{
    json["name"] = m_name;
    json["message"] = QString(m_message.toHex());
    json["interval"] = m_sendIntervalTime;
}

void Command::read(QJsonObject &json)
{
    m_name = json["name"].toString();
    m_message = QByteArray::fromHex(json["message"].toString().toLatin1());
    m_sendIntervalTime = json["interval"].toInt();
}
