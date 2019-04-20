#ifndef COMMAND_H
#define COMMAND_H

#include <QString>
#include <QByteArray>
#include <QJsonObject>

class Command
{
public:
    Command() = default;
    explicit Command(QString name, int interval, QByteArray msg);

    const QString & name() const
    {
        return m_name;
    }
    int intervalTime() const
    {
        return m_sendIntervalTime;
    }

    QByteArray message() const
    {
        return m_message;
    }

    void setName(QString name)
    {
        m_name = name;
    }
    void setIntervaltime(int time)
    {
        m_sendIntervalTime = time;
    }

    void setMessage(QByteArray msg)
    {
        m_message = msg;
    }

    void write(QJsonObject &json) const;
    void read(QJsonObject &json);

private:
    QString m_name;
    QByteArray m_message;
    int m_sendIntervalTime;

};

#endif // COMMAND_H
