#include "airshow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

static const unsigned char outTowns[8][6] = {
    //           Lat       Lng
/*petersburg 	[+059.80][+030.30]*/	{0x00,0x3B,0x50,0x00,0x1E,0x1E},
/*moskow        [+055.75][+037.50]*/	{0x00,0x37,0x4B,0x00,0x25,0x32},
/*murmansk      [+068.95][+033.10]*/ 	{0x00,0x44,0x5F,0x00,0x21,0x0A},
/*ekaterinburg	[+046.80][+060.70]*/	{0x00,0x2E,0x50,0x00,0x3C,0x46},
/*vladivostok	[+043.15][+131.90]*/	{0x00,0x2B,0x0F,0x00,0x83,0x5A},
/*kazan         [+055.80][+049.10]*/ 	{0x00,0x37,0x50,0x00,0x31,0x0A},
/*surgut        [+061.25][+073.40]*/ 	{0x00,0x3D,0x19,0x00,0x49,0x28},
/*omsk          [+054.95][+073.40]*/ 	{0x00,0x36,0x5F,0x00,0x49,0x28}
};

static const unsigned char inTowns[8][6] = {
/*canberra      [+035.30][+149.12]*/ 	{0x00,0x23,0x1E,0x00,0x95,0x0C},
/*baku          [+040.35][+049.85]*/ 	{0x00,0x28,0x23,0x00,0x31,0x55},
/*buenos-aires	[-034.82][-058.33]*/	{0x01,0x22,0x52,0x01,0x3A,0x21},
/*rio           [-022.90][-043.21]*/ 	{0x01,0x16,0x5A,0x01,0x2B,0x15},
/*liverpool     [+053.40][-003.00]*/	{0x00,0x35,0x28,0x01,0x03,0x00},
/*munich        [+048.14][+011.53]*/ 	{0x00,0x30,0x0E,0x00,0x0B,0x35},
/*toronto       [+043.65][-079.37]*/ 	{0x00,0x2B,0x41,0x01,0x4F,0x25},
/*putian        [+025.35][+119.00]*/ 	{0x00,0x19,0x23,0x00,0x77,0x00}
};

Airshow::Airshow(QWidget *parent) : QWidget(parent)
{
    m_tcpSocket = new QTcpSocket(this);
    m_data = new QByteArray(1,0);

    m_inTown = new QComboBox;
    m_outTown = new QComboBox;
    m_flyTime = new QComboBox;
    m_addFly = new QPushButton(tr("Добавить"));
    m_flyList = new QListWidget;
    m_clearFlyList = new QPushButton(tr("Очистить"));
    m_start = new QPushButton(tr("Запустить"));

    m_outTown->addItems(QStringList()
                       <<"С.Петербург"<<"Москва"<<"Мурманск"
                       <<"Екатеринбург"<<"Владивосток"<<"Казань"
                       <<"Сургут"<<"Омск");

    m_inTown->addItems(QStringList()
                       <<"Канберра"<<"Баку"<<"Буэнос-Айрес"
                       <<"Рио-де-Жанейро"<<"Ливерпуль"<<"Мюнхен"
                       <<"Торонто"<<"Путянь");

    m_flyTime->addItems(QStringList()
                        <<"1 минута"<<"5 минут"<<"10 минут"<<"15 минут");

    QHBoxLayout *lay1 = new QHBoxLayout;
    QVBoxLayout *lay2 = new QVBoxLayout;
    lay1->addWidget(m_outTown);
    lay1->addWidget(m_inTown);
    lay2->addLayout(lay1);
    lay2->addWidget(m_flyTime);
    lay2->addWidget(m_addFly);
    lay2->addWidget(m_flyList);
    lay2->addWidget(m_clearFlyList);
    lay2->addWidget(m_start);
    this->setLayout(lay2);

    connect(m_addFly,&QPushButton::clicked,this,&Airshow::addFly);
    connect(m_clearFlyList,&QPushButton::clicked,this,&Airshow::clearFlies);
    connect(m_start,&QPushButton::clicked,this,&Airshow::startFlies);
}

void Airshow::addFly(void)
{
    if (m_flyList->count()>10) {
        QMessageBox msgBox(this);
        msgBox.setText(tr("Количество полетов максимально."));
        msgBox.exec();
    }
    int idx1 = m_outTown->currentIndex();
    int idx2 = m_inTown->currentIndex();
    int time = m_flyTime->currentIndex();
    if (!time) time=1; else time*=5;
    m_data->append(QByteArray::fromRawData((char*)&outTowns[idx1][0],6));
    m_data->append(QByteArray::fromRawData((char*)&inTowns[idx2][0],6));
    m_data->append(time);
    (*m_data)[0] = static_cast<char>(m_data->size());

    QString str = m_outTown->currentText() + "-" + m_inTown->currentText();
    str += "  [" + m_flyTime->currentText() + "]";
    m_flyList->addItem(str);
}

void Airshow::startFlies(void)
{
    m_tcpSocket->abort();
    m_tcpSocket->connectToHost(m_serverAddr,m_serverPort,QIODevice::WriteOnly);
    if (!m_tcpSocket->waitForConnected(1000)) {
        QMessageBox msgBox(this);
        msgBox.setText(tr("Ошибка соединения."));
        msgBox.exec();
        return;
    };
    m_tcpSocket->write(*m_data);
    while(m_tcpSocket->bytesToWrite()) m_tcpSocket->waitForBytesWritten(10);
    m_tcpSocket->disconnect();
    if (!m_tcpSocket->waitForDisconnected(1000)) m_tcpSocket->abort();
}

void Airshow::clearFlies()
{
    m_data->clear();
    m_data->append(static_cast<char>(0));
    m_flyList->clear();
}

void Airshow::setServerConfig(QString ip, QString port)
{
    m_serverAddr.setAddress(ip);
    m_serverPort = port.toUInt();
}
