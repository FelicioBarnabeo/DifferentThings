#ifndef AIRSHOWFILESMANAGER_H
#define AIRSHOWFILESMANAGER_H

#include <QObject>
#include <QAbstractSocket>

QT_BEGIN_NAMESPACE
class QTcpSocket;
class QByteArray;
class QFile;
QT_END_NAMESPACE

class AirshowFilesManager : public QObject
{
    Q_OBJECT
public:
    explicit AirshowFilesManager(QObject *parent = nullptr);
    ~AirshowFilesManager();
    QTcpSocket *clientSocket;
    quint32 imageSize = 0;
    quint32 readedBytes = 0;
    QString imgFilenamePath();
public slots:
    //void read();
    void write();
    void displayError(QAbstractSocket::SocketError socketError);
    void connectToServer(QString serverIP, int port);
private:
    //QFile *arch;
    QString filename;
};

#endif // AIRSHOWFILESMANAGER_H
