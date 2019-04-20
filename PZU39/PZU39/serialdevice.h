#ifndef SERIALDEVICE_H
#define SERIALDEVICE_H

#include <QtSerialPort/QtSerialPort>

class Configurator;
class QTimer;
class Settings;

namespace SDStates {
enum {
    Default,
    StatusInCheck,
    StatusChecked,
    StatusUnchecked,
    StatusDirectStage1,
};
}

class SerialDevice : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString currentCmd READ currentCmd WRITE setCurrentCmd NOTIFY currentCmdChanged)
public:
    explicit SerialDevice(QObject *parent = 0);
    void turnOn();
    void turnOff();
    void processReceivedMsopState(unsigned char state);
    void catchBpCommand(QString cmd);
    QString currentCmd() const
    {
        return m_currentCmd;
    }

public slots:
    void sendCommand(QString cmd, QString directCmd = "");
    void startSendCmd(QString cmd);
    void stopSendCmd();
    void processCommand();
    void setStatus(int state);
    void close(){
        m_serialPort->flush();
        m_serialPort->clear();
        m_serialPort->setBaudRate(19200);
        m_serialPort->close();
    }

    void setCurrentCmd(QString currentCmd)
    {
        if (m_currentCmd == currentCmd)
            return;

        m_currentCmd = currentCmd;
        emit currentCmdChanged(m_currentCmd);
    }
    void uncheckBpStatus();
    int write(const QString &cmd);
    int writeCmd();
private:
    Configurator *m_configurator;
    QSerialPort *m_serialPort;
    QByteArray m_innerBuffer;
    int m_state;
    QByteArray m_QueueBuffer;
    QString m_cmd;
    QString m_directCmd;
    QTimer *m_waitForAnswerBP;
    QString turnOnCmd;
    QString turnOffCmd;
    Settings *m_settingsInstance;
    QTimer *m_holdBtnTimer;
    QString m_currentCmd;

signals:
void cmdComplete(const QString & cmd);
void currentCmdChanged(QString currentCmd);
void cmdSended(const QString cmd);
void cmdReceived(const QString cmd);
};

#endif // SERIALDEVICE_H
