#ifndef COMMAND_H
#define COMMAND_H

#include <QVector>
#include <QString>
#include <QByteArray>
//class QVector;

class Command
{
public:
    Command() = default;
    explicit Command(QString name, int interval, QByteArray message);

    const QString & name() const
    {
        return m_name;
    }
    int intervalTime() const
    {
        return m_sendIntervalTime;
    }
    const QByteArray message() const
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
    void setMessage(QByteArray message)
    {
        m_message = message;
    }

private:
    QString m_name;
    QByteArray m_message;
    int m_sendIntervalTime;
//public slots:

};

#endif // COMMAND_H
