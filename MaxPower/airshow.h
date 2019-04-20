#ifndef AIRSHOW_H
#define AIRSHOW_H

#include <QWidget>
#include <QListWidget>
#include <QComboBox>
#include <QPushButton>
#include <QtNetwork/QTcpSocket>
#include <QHostAddress>

class Airshow : public QWidget
{
    Q_OBJECT
    QComboBox *m_inTown, *m_outTown, *m_flyTime;
    QPushButton *m_addFly, *m_clearFlyList, *m_start;
    QListWidget *m_flyList;
    QTcpSocket *m_tcpSocket;
    QByteArray *m_data;
    QHostAddress m_serverAddr;
    quint16 m_serverPort;

public:
    explicit Airshow(QWidget *parent = 0);

public slots:
    void addFly(void);
    void startFlies(void);
    void clearFlies(void);
    void setServerConfig(QString ip, QString port);
};

#endif // AIRSHOW_H
