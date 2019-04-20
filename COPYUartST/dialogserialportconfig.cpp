#include "dialogserialportconfig.h"
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QGridLayout>
#include <QtSerialPort/QSerialPortInfo>
#include "ioserialmanager.h"
#include "serialdevice.h"
#include <QDebug>
#include <QErrorMessage>
#include "settings.h"

SerialPortConfig::SerialPortConfig(QWidget *parent )
    : QDialog(parent)
    , m_mngr              (IOSerialManager::instance())
    , m_serialPortLabel   (new QLabel(tr("Serial port")))
    , m_serialPortComboBox(new QComboBox())
    , m_readPortLabel     (new QLabel(tr("Read port")))
    , m_readPortComboBox  (new QComboBox())
    , m_dataBitsLabel     (new QLabel(tr("Data bits")))
    , m_dataBitsComboBox  (new QComboBox())
    , m_stopBitsLabel     (new QLabel(tr("Stop bits")))
    , m_stopBitsComboBox  (new QComboBox())
    , m_baudRateLabel     (new QLabel(tr("Baud rate")))
    , m_baudRateComboBox  (new QComboBox())
    , m_parityBitLabel    (new QLabel(tr("Parity")))
    , m_parityComboBox    (new QComboBox())
    , m_okButton          (new QPushButton(tr("OK")))
    , m_cancelButton      (new QPushButton(tr("Cancel")))
{
    Settings * settings = Settings::instance();
    const auto infos = QSerialPortInfo::availablePorts();
    for(const QSerialPortInfo &info : infos)
    {
        m_serialPortComboBox->addItem(info.portName());
        m_readPortComboBox->addItem(info.portName());
    }
    m_serialPortComboBox->setCurrentText(settings->deviceName());

    const auto info_speed = QSerialPortInfo::standardBaudRates();
    for(const int &info : info_speed)
        m_baudRateComboBox->addItem(QString::number(info));
    m_baudRateComboBox->setCurrentText(settings->baudRate());

    SerialDevice serialPort;
    m_parityComboBox->addItems(serialPort.listParity());
    m_parityComboBox->setCurrentText(settings->parity());

    m_dataBitsComboBox->addItems(serialPort.listDataBits());
    m_dataBitsComboBox->setCurrentText(settings->dataBits());

    m_stopBitsComboBox->addItems(serialPort.listStopBits());
    m_stopBitsComboBox->setCurrentText(settings->stopBits());

    QVBoxLayout *mainLayout   = new QVBoxLayout;
    QGridLayout *dialogLayout = new QGridLayout;
    dialogLayout->addWidget(m_serialPortLabel,    0, 0);
    dialogLayout->addWidget(m_serialPortComboBox, 0, 1);
    dialogLayout->addWidget(m_readPortLabel,      0, 2);
    dialogLayout->addWidget(m_readPortComboBox,   0, 3);
    dialogLayout->addWidget(m_baudRateLabel,      1, 0);
    dialogLayout->addWidget(m_baudRateComboBox,   1, 1);
    dialogLayout->addWidget(m_stopBitsLabel,      1, 2);
    dialogLayout->addWidget(m_stopBitsComboBox,   1, 3);
    dialogLayout->addWidget(m_dataBitsLabel,      2, 0);
    dialogLayout->addWidget(m_dataBitsComboBox,   2, 1);
    dialogLayout->addWidget(m_parityBitLabel,     2, 2);
    dialogLayout->addWidget(m_parityComboBox,     2, 3);


    QBoxLayout *buttonsLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    buttonsLayout->addWidget(m_okButton);
    buttonsLayout->addWidget(m_cancelButton);

    mainLayout->addLayout(dialogLayout);
    mainLayout->addLayout(buttonsLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Настрока порта"));
    m_serialPortComboBox->setFocus();

    connect(m_okButton, &QPushButton::clicked, this, &SerialPortConfig::acceptData);
    connect(m_cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);
}

SerialPortConfig::~SerialPortConfig()
{
    delete  m_serialPortLabel;
    delete  m_serialPortComboBox;
    delete  m_dataBitsLabel;
    delete  m_dataBitsComboBox;
    delete  m_stopBitsLabel;
    delete  m_stopBitsComboBox;
    delete  m_baudRateLabel;
    delete  m_baudRateComboBox;
    delete  m_parityBitLabel;
    delete  m_parityComboBox;
    delete  m_okButton;
    delete  m_cancelButton;
    qDebug()<<"SerialPortConfig deleted";
}

void SerialPortConfig::acceptData()
{
    QErrorMessage *portNotify = new QErrorMessage(this);
    SerialDevice *sp = m_mngr->serialPort();
    Settings *st = Settings::instance();
    qDebug()<<"open serial port";
    m_mngr->setConfiguration( m_serialPortComboBox->currentText(), m_baudRateComboBox->currentText(),
                              m_dataBitsComboBox->currentText(),   m_parityComboBox->currentText(),
                              m_stopBitsComboBox->currentText());
    st->setDeviceName(m_serialPortComboBox->currentText());
    st->setbaudRate(m_baudRateComboBox->currentText());
    st->setDataBits(m_dataBitsComboBox->currentText());
    st->setParity(m_parityComboBox->currentText());
    st->setStopBits(m_stopBitsComboBox->currentText());

    if(m_mngr->tryOpenPort()){
        portNotify->showMessage(QString(tr("Connected to ")+"%1 : %2, %3, %4, %5")
            .arg(sp->portName()).arg(sp->currentBaudRate()).arg(sp->currentDataBits())
            .arg(sp->currentParity()).arg(sp->currentStopBits()));
        this->accept();
    }
    else {
        portNotify->showMessage(QString(tr("Can't open ")+"%1"+tr(" port") + "%2")
        .arg(sp->portName())
        .arg(sp->errorString()));
    }
    //delete portNotify;
}

void SerialPortConfig::openDialog(QWidget * parent)
{
    SerialPortConfig dialog(parent);
    dialog.exec();
    qDebug()<<"openDialog ended";
}
