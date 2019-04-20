#ifndef LIRC_H
#define LIRC_H

#include <QObject>
#include <QProcess>
#include <QString>

class LircSingleton : public QObject
{
    Q_OBJECT
private:
    QString m_program;
    QStringList m_args;
    QProcess m_process ;
    static LircSingleton * m_instance;
public:
    ~LircSingleton();
    static LircSingleton* Instance();
protected:
    explicit LircSingleton(QObject *parent = nullptr);
signals:
    void sendedOnce();
    void sendStarted();
    void sendStopped();
public slots:
    void startProcess();
    void startSend(QString key , QString device);
    void stopSend(QString key, QString device);
    void sendCommand(QString key, QString device = "vista_mce");
};

#endif // LIRC_H
