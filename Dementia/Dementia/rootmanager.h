#ifndef ROOTMANAGER_H
#define ROOTMANAGER_H

#include <QObject>

class RootManager : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString status READ status WRITE setStatus NOTIFY statusChanged)
    Q_PROPERTY(int progress READ progress WRITE setProgress NOTIFY progressChanged)

    QString m_status;
    int m_progress;

public:
    explicit RootManager(QObject *parent = 0);
    QString status() const;
    int progress() const;

signals:
    void error(void);
    void statusChanged(QString status);
    void progressChanged(int progress);

public slots:
    void updateFirmwareFromUSB(void);
    void updateFirmwareFromServer(void);
    void updateFirmwareFromSSD(void);
    void updateMediaFromUSB(void);
    void updateMediaFromServer(void);
    void updateMediaFromSSD(void);
    void reboot(void);
    void halt(void);

    void setStatus(QString status);
    void setProgress(int progress);
};

#endif // ROOTMANAGER_H
