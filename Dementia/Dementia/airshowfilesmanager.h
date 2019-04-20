#ifndef AIRSHOW_H
#define AIRSHOW_H

#include <QObject>
#include <QAbstractSocket>
#include <QSharedPointer>
#include <QMap>
#include <QUrl>
#include <QTcpSocket>
#include <QFile>
#include <QProcess>
#include <QTimer>

class AirshowFilesManager : public QObject
{
    Q_OBJECT
    QString m_path;
    QString m_lang;
    QMap<QString, QStringList> m_filesNames;
    int m_counter;

    bool m_isBusy;
    bool m_isUnpackFinished;
    bool m_isErrorOccured;

    QTcpSocket *m_clientSocket;
    QProcess *m_unpackProc;

    char* m_buffer;

    QFile m_file;
    quint32 m_fileSize;

    QTimer* m_timeoutTmr;

    void readFilesNames(void);
    void unpack(void);
    void connectionError(QAbstractSocket::SocketError socketError);

public:
    explicit AirshowFilesManager(QString path, QString lang, QObject *parent=0);
    ~AirshowFilesManager();

signals:
    void networkErrorOccured(void);
    void imagesReady(void);

public slots:
    void dataRead(void);
    bool updateImages(QString serverIP, int port);
    QUrl nextImage(void);
    void setLang(QString lang);
    void unpackFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void resetToDefault(void);
    void connectionTimeout();
};

#endif // AIRSHOW_H
