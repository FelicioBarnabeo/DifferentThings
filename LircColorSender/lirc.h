#ifndef LIRC_H
#define LIRC_H

#include <QObject>
#include <QProcess>
#include <QString>

class Lirc : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int idxCmd READ idxCmd WRITE setIdxCmd NOTIFY idxCmdChanged)
private:
    QString m_program;
    QStringList m_args;
    QProcess m_process ;
    QStringList listCmd;
    //static int currentIdxCmd;
    int m_idxCmd;

public:
    explicit Lirc(QObject *parent = 0);
    ~Lirc();
    void fillCmdList();
    int idxCmd() const
    {
        return m_idxCmd;
    }

signals:
    void sendedOnce();
    void sendStarted();
    void sendStopped();
    void idxCmdChanged(int idxCmd);

public slots:
    void startProcess();
    void startSend(QString key , QString device);
    void stopSend(QString key, QString device);
    void sendCommand(QString key, QString device = "vista_mce");
    const QString getNextCmd();
    const QString getPrevCmd();

    void setIdxCmd(int idxCmd)
    {
        if (m_idxCmd == idxCmd)
            return;

        m_idxCmd = idxCmd;
        emit idxCmdChanged(m_idxCmd);
    }
};

#endif // LIRC_H
