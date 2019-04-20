#include "servervss.h"
#include <QTcpSocket>
#include "QtWebSockets/QWebSocketServer"
#include "QtWebSockets/QWebSocket"
#include <QTimer>


ServerVss::ServerVss(quint16 port, QByteArray &arr,  QObject *parent) : m_buf(arr), QTcpServer(parent)
{
    m_pWebSocketServer = new QWebSocketServer(QStringLiteral("VSS Server"), QWebSocketServer::NonSecureMode, this);
    listen(QHostAddress::Any, port);
    connect(m_pWebSocketServer, &QWebSocketServer::newConnection, this, &ServerVss::onNewConnection);
}


void ServerVss::onNewConnection(){
    QWebSocket * clientSocket = m_pWebSocketServer->nextPendingConnection();
    clientSocket->sendBinaryMessage(m_buf);
    //clientSocket->writedata();
}
