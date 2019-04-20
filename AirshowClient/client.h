#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QFile>

class Client : public QTcpSocket
{
    Q_OBJECT
    QFile m_file;
    qint64 m_bytesWrittenToFile, m_bytesReadedFromSocket, m_bytesTotalWrittenToFile;
    quint64 m_fileSize;
    char *m_buffer;
    bool m_isBusy; // flag that check if begin size of packet read or not

private slots:
    void readNetworkData(void);
    void connectionError(QAbstractSocket::SocketError err);
    void disconnectClient(void);
public:
    Client(QObject* parent=0);
    ~Client();
public slots:
    void repeatConnect(void);
};

#endif // CLIENT_H
