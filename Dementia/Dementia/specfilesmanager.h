#ifndef SPECFILESMANAGER_H
#define SPECFILESMANAGER_H

#include <QObject>
#include <QTcpServer>

class SpecFilesManager : public QObject
{
    Q_OBJECT
    QTcpServer *m_tcpServer;
    int m_port;
    QString m_rootPath;
    QString m_lang;
public:
    explicit SpecFilesManager(const QString &path, const QString &lang,
                              int port, QObject *parent = 0);

signals:
    void playSpecFile(const QString &file);

public slots:
    void setLang(const QString& lang);
    QString absolutePath(void) const;
    void serveClient(void);
    void readClientData(void);
};

#endif // SPECFILESMANAGER_H
