#include "info.h"
#include <QVBoxLayout>
#include <QMessageBox>

Info::Info(QWidget *parent) : QWidget(parent)
{
    m_tcpSocket = new QTcpSocket;
    m_infoList = new QListWidget;
    m_start = new QPushButton(tr("Запустить"));

    m_infoList->addItem("Выключение электроники");
    m_infoList->addItem("Курение и кислородные маски");
    m_infoList->addItem("Спасательный жилет и ремни");
    m_infoList->item(0)->setSizeHint(QSize(20,100));
    m_infoList->item(1)->setSizeHint(QSize(20,100));
    m_infoList->item(2)->setSizeHint(QSize(20,100));
    m_infoList->setCurrentRow(0);

    m_infoList->setSizeAdjustPolicy(QListWidget::AdjustToContents);
    QVBoxLayout *lay = new QVBoxLayout;
    lay->addWidget(m_infoList);
    lay->addWidget(m_start);
    this->setLayout(lay);

    connect(m_start,&QPushButton::clicked,this,&Info::start);
}

void Info::setServerConfig(QString addr, QString port)
{
    m_serverAddr.setAddress(addr);
    m_serverPort = port.toUInt();
}

void Info::start()
{
    m_tcpSocket->abort();
    m_tcpSocket->connectToHost(m_serverAddr,m_serverPort,QIODevice::WriteOnly);
    if (!m_tcpSocket->waitForConnected(1000)) {
        QMessageBox msgBox(this);
        msgBox.setText(tr("Ошибка соединения."));
        msgBox.exec();
        return;
    };
    QByteArray data;
    data.append(static_cast<char>(m_infoList->currentRow()));
    m_tcpSocket->write(data);
    while(m_tcpSocket->bytesToWrite()) m_tcpSocket->waitForBytesWritten(10);
    m_tcpSocket->disconnect();
    if (!m_tcpSocket->waitForDisconnected(1000)) m_tcpSocket->abort();
}
