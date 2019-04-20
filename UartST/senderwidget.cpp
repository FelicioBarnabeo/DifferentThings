#include "senderwidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QGroupBox>
#include <QTableWidget>
#include <QLineEdit>
#include "mytabledelegate.h"
#include "standarttablemodel.h"
#include "command.h"
#include "myvalidator.h"
#include <QDebug>

SenderWidget::SenderWidget(QWidget *parent) : QTabWidget(parent), m_delegate(new MyTableDelegate)
{    
    QVBoxLayout* mainLayout = new QVBoxLayout(parent);

    m_hexButton   = new QRadioButton(tr("HEX"));
    m_decButton   = new QRadioButton(tr("DEC"));
    m_binButton   = new QRadioButton(tr("BIN"));
    m_octButton   = new QRadioButton(tr("OCT"));
    m_asciiButton = new QRadioButton(tr("ASCII"));

    QHBoxLayout* radioFormats = new QHBoxLayout(parent);
    radioFormats->addWidget(m_hexButton);
    radioFormats->addWidget(m_decButton);
    radioFormats->addWidget(m_binButton);
    radioFormats->addWidget(m_octButton);
    radioFormats->addWidget(m_asciiButton);

    connect(m_hexButton,   &QRadioButton::toggled, m_delegate, &MyTableDelegate::setHexValidate);
    connect(m_decButton,   &QRadioButton::toggled, m_delegate, &MyTableDelegate::setDecValidate);
    connect(m_octButton,   &QRadioButton::toggled, m_delegate, &MyTableDelegate::setOctValidate);
    connect(m_binButton,   &QRadioButton::toggled, m_delegate, &MyTableDelegate::setBinValidate);
    connect(m_asciiButton, &QRadioButton::toggled, m_delegate, &MyTableDelegate::setAsciiValidate);

    m_hexButton->setChecked(true);
    mainLayout->addLayout(radioFormats);

    QVBoxLayout* sendLayout = new QVBoxLayout(parent);
    m_sendGroup     = new QGroupBox(tr("Send configuration"));
    m_nameLabel     = new QLabel(tr("Name"));
    m_dataLabel     = new QLabel(tr("Message"));
    m_intervalLabel = new QLabel(tr("Interval"));
    m_nameEdit      = new QLineEdit();

    StandartTableModel *tableModel = new StandartTableModel();

    //delegate->setHexValidate();
    m_messageTable  = new QTableView(this);
    m_messageTable->setItemDelegate(m_delegate);
    m_messageTable->setModel(tableModel);

    m_intervalBox   = new QSpinBox();
    m_intervalBox->setRange(0,10000);
    m_intervalBox->setValue(1000);
    sendLayout->addWidget(m_nameLabel);
    sendLayout->addWidget(m_nameEdit);
    sendLayout->addWidget(m_dataLabel);
    sendLayout->addWidget(m_messageTable);
    sendLayout->addWidget(m_intervalLabel);
    sendLayout->addWidget(m_intervalBox);
    m_sendGroup->setLayout(sendLayout);
    mainLayout->addWidget(m_sendGroup);

    m_okButton      = new QPushButton(tr("Ok"));
    m_cancelButton  = new QPushButton(tr("Cancel"));
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(m_okButton);
    buttonLayout->addWidget(m_cancelButton);
    mainLayout->addLayout(buttonLayout);

    connect(m_okButton, &QPushButton::clicked, this, &SenderWidget::acceptMessage);
    setLayout(mainLayout);
}

void SenderWidget::acceptMessage()
{
    QByteArray messageArray = static_cast<StandartTableModel>(m_messageTable->model()).getAllTableData();
    for(int i=0; i< messageArray.size(); i++)
        qDebug()<< "i = " << i << " "<< static_cast<uchar>(messageArray[i]) ;
    //for(auto i : messageArray)

    //Command *command = new Command(m_nameEdit->text, m_intervalBox->value(), messageArray);

    this->close();
}


