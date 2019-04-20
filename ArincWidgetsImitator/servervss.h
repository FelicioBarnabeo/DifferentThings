#ifndef SERVERVSS_H
#define SERVERVSS_H

#include <QTcpServer>
#include <QWebSocketServer>

class ServerVss : public QTcpServer
{
    Q_OBJECT
private:
    QWebSocketServer *m_pWebSocketServer;
    QByteArray & m_buf;
public:
    explicit ServerVss(quint16 port, QByteArray &arr, QObject * parent = Q_NULLPTR);

public slots:
    void onNewConnection();
};

#endif // SERVERVSS_H
