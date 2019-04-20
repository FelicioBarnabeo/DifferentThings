#include "specfilesmanager.h"
#include <QTcpSocket>
#include <QFile>
#include <QDebug>

SpecFilesManager::SpecFilesManager(const QString &path, const QString &lang,
                                   int port, QObject *parent)
    :QObject(parent),m_port(port),m_rootPath(path),m_lang(lang)
{
    m_tcpServer = new QTcpServer(this);
    m_tcpServer->listen(QHostAddress::Any,m_port);
    connect(m_tcpServer,&QTcpServer::newConnection,
            this,&SpecFilesManager::serveClient);
}

void SpecFilesManager::setLang(const QString &lang)
{
    m_lang = lang;
}

QString SpecFilesManager::absolutePath() const
{
    return (m_rootPath + "/" + m_lang);
}

void SpecFilesManager::serveClient(void)
{
    QTcpSocket *clientSocket = m_tcpServer->nextPendingConnection();
    connect(clientSocket,&QTcpSocket::disconnected,
            clientSocket,&QTcpSocket::deleteLater);
    connect(clientSocket,&QTcpSocket::readyRead,
            this,&SpecFilesManager::readClientData);
    qDebug()<<"Client connected";
}

void SpecFilesManager::readClientData()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    qDebug()<<"Bytes available"<<clientSocket->bytesAvailable();
    QByteArray data = clientSocket->readAll();
    char val = data.at(data.length()-1);
    QString filename;
    if (val<10) filename = "0" + QString::number(val);
    else filename = QString::number(val);
    filename = this->absolutePath()+"/"+"["+filename+"]";
    if (QFile::exists(filename)) {
        emit playSpecFile("file:"+filename);
        qDebug()<<"Good file to play: "<<filename;
    } else {
        qDebug()<<"Bad file to play: "<<filename;
    }
}
