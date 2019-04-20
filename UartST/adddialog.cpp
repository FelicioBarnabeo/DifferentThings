#include "adddialog.h"
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QGridLayout>
#include <QtSerialPort/QSerialPortInfo>
#include "serialdevice.h"
#include <QErrorMessage>
#include <QDebug>

QLabel        *serialPortLabel;
QComboBox     *serialPortComboBox;
QLabel        *dataBitsLabel;
QComboBox     *dataBitsComboBox;
QLabel        *stopBitsLabel;
QComboBox     *stopBitsComboBox;
QLabel        *baudRateLabel;
QComboBox     *baudRateComboBox;
QLabel        *parityBitLabel;
QComboBox     *parityComboBox;
QLabel        *intervalLabel;
QSpinBox      *intervalSpinBox;
QPushButton   *okButton;
QPushButton   *cancelButton;
QErrorMessage *portNotify;
SerialDevice  *serial;

AddDialog::AddDialog(QWidget *parent)
    : QDialog(parent)
    , serialPortLabel(new QLabel(tr("Serial port")))
    , serialPortComboBox(new QComboBox())
    , dataBitsLabel  (new QLabel(tr("Data bits")))
    , dataBitsComboBox  (new QComboBox())
    , stopBitsLabel  (new QLabel(tr("Stop bits")))
    , stopBitsComboBox  (new QComboBox())
    , baudRateLabel  (new QLabel(tr("Baud rate")))
    , baudRateComboBox  (new QComboBox())
    , parityBitLabel (new QLabel(tr("Parity")))
    , parityComboBox    (new QComboBox())
    , intervalLabel  (new QLabel(tr("Interval")))
    , intervalSpinBox   (new QSpinBox())
    , okButton       (new QPushButton(tr("OK")))
    , cancelButton   (new QPushButton(tr("Cancel")))
    , portNotify        (new QErrorMessage)
    , serial            (new SerialDevice)
{
    const auto infos = QSerialPortInfo::availablePorts();
    for(const QSerialPortInfo &info : infos)
        serialPortComboBox->addItem(info.portName());

    const auto info_speed = QSerialPortInfo::standardBaudRates();
    for(const int &info : info_speed)
        baudRateComboBox->addItem(QString::number(info));
    baudRateComboBox->setCurrentText("115200");

    parityComboBox->addItems(serial->listParity());
    parityComboBox->setCurrentText("NoParity");

    dataBitsComboBox->addItems(serial->listDataBits());
    dataBitsComboBox->setCurrentText("Data8");

    stopBitsComboBox->addItems(serial->listStopBits());
    stopBitsComboBox->setCurrentText("OneStop");

    intervalSpinBox->setRange(0,10000);
    intervalSpinBox->setValue(1000);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    QGridLayout *dialogLayout = new QGridLayout;
    dialogLayout->addWidget(serialPortLabel,    0, 0);
    dialogLayout->addWidget(serialPortComboBox, 0, 1);
    dialogLayout->addWidget(parityBitLabel,     0, 2);
    dialogLayout->addWidget(parityComboBox,     0, 3);
    dialogLayout->addWidget(baudRateLabel,      1, 0);
    dialogLayout->addWidget(baudRateComboBox,   1, 1);
    dialogLayout->addWidget(stopBitsLabel,      1, 2);
    dialogLayout->addWidget(stopBitsComboBox,   1, 3);
    dialogLayout->addWidget(dataBitsLabel,      2, 0);
    dialogLayout->addWidget(dataBitsComboBox,   2, 1);
    dialogLayout->addWidget(intervalLabel,      2, 2);
    dialogLayout->addWidget(intervalSpinBox,    2, 3);

    QBoxLayout *buttonsLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    buttonsLayout->addWidget(okButton);
    buttonsLayout->addWidget(cancelButton);

    mainLayout->addLayout(dialogLayout);
    mainLayout->addLayout(buttonsLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Настрока порта"));
    serialPortComboBox->setFocus();

    connect(okButton,&QPushButton::clicked,this,&QDialog::accept);
    connect(this,&QDialog::accepted,this,&AddDialog::openSerialPort);
    connect(cancelButton, &QAbstractButton::clicked,this,&QDialog::reject);
}

AddDialog::~AddDialog(){
    //delete portNotify;
}

void AddDialog::openSerialPort()
{
    serial->setStringBaudRate(baudRateComboBox->currentText());
    serial->setStringDataBits(dataBitsComboBox->currentText());
    serial->setStringParity(parityComboBox->currentText());
    serial->setPortName(serialPortComboBox->currentText());
    serial->setStringStopBits(stopBitsComboBox->currentText());
    serial->setWriteInterval(intervalSpinBox->value());
    if(serial->open(QIODevice::ReadWrite)){
        portNotify->showMessage(QString(tr("Connected to ")+"%1 : %2, %3, %4, %5")
            .arg(serial->portName()).arg(serial->currentBaudRate()).arg(serial->currentDataBits())
            .arg(serial->currentParity()).arg(serial->currentStopBits()));
        //qDebug() << "Serial port"<< serial->portName() << "opened";
    }
    else{
        portNotify->showMessage(QString(tr("Can't open ")+"%1"+tr(" port")).arg(serial->portName()));
    }
}
