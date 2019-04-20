#ifndef INFO_H
#define INFO_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QtNetwork/QTcpSocket>
#include <QHostAddress>

class Info : public QWidget
{
    Q_OBJECT
    QHostAddress m_serverAddr;
    quint16 m_serverPort;
    QTcpSocket *m_tcpSocket;
    QListWidget *m_infoList;
    QPushButton *m_start;
public:
    explicit Info(QWidget *parent = 0);

public slots:
    void setServerConfig(QString addr, QString port);
    void start(void);
};

#endif // INFO_H
