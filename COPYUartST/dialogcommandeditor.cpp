#include "dialogcommandeditor.h"
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
#include <QErrorMessage>

Command* CommandEditor::m_command = nullptr;

CommandEditor::CommandEditor(Command *cmd, QWidget *parent) :
      QDialog(parent)
    , m_delegate(new MyTableDelegate)
    , m_tableModel(new StandartTableModel)
{
    qDebug()<<Q_FUNC_INFO;
    m_delegate->setHexValidate();
    //It is important to zero m_command because it is static and contain previous initialization
    m_command = nullptr;
    QVBoxLayout* mainLayout = new QVBoxLayout();

    m_hexButton   = new QRadioButton(tr("HEX"),this);
    m_decButton   = new QRadioButton(tr("DEC"),this);
    m_binButton   = new QRadioButton(tr("BIN"),this);
    m_octButton   = new QRadioButton(tr("OCT"),this);
    m_asciiButton = new QRadioButton(tr("ASCII"),this);

    QHBoxLayout* radioFormats = new QHBoxLayout();
    radioFormats->addWidget(m_hexButton);
    radioFormats->addWidget(m_decButton);
    radioFormats->addWidget(m_binButton);
    radioFormats->addWidget(m_octButton);
    radioFormats->addWidget(m_asciiButton);
    m_hexButton->setChecked(true);

    connect(m_hexButton,   &QRadioButton::toggled, m_delegate, &MyTableDelegate::setHexValidate);
    connect(m_hexButton,   &QRadioButton::toggled, this,       &CommandEditor::updateTable);

    connect(m_decButton,   &QRadioButton::toggled, m_delegate, &MyTableDelegate::setDecValidate);
    connect(m_decButton,   &QRadioButton::toggled, this,       &CommandEditor::updateTable);

    connect(m_octButton,   &QRadioButton::toggled, m_delegate, &MyTableDelegate::setOctValidate);
    connect(m_octButton,   &QRadioButton::toggled, this,       &CommandEditor::updateTable);

    connect(m_binButton,   &QRadioButton::toggled, m_delegate, &MyTableDelegate::setBinValidate);
    connect(m_binButton,   &QRadioButton::toggled, this,       &CommandEditor::updateTable);

    connect(m_asciiButton, &QRadioButton::toggled, m_delegate, &MyTableDelegate::setAsciiValidate);
    connect(m_asciiButton, &QRadioButton::toggled, this,       &CommandEditor::updateTable);

    mainLayout->addLayout(radioFormats);

    QVBoxLayout* sendLayout = new QVBoxLayout();
    m_sendGroup     = new QGroupBox(tr("Send configuration"),this);
    m_nameLabel     = new QLabel(tr("Name"),this);
    m_dataLabel     = new QLabel(tr("Message"),this);
    m_intervalLabel = new QLabel(tr("Interval"),this);
    m_nameEdit      = new QLineEdit();
    //m_nameEdit->setParent(this, );

    m_messageTable  = new QTableView(this);
    m_messageTable->setItemDelegate(m_delegate);
    m_messageTable->setModel(m_tableModel);

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

    m_okButton      = new QPushButton(tr("Ok"),this);
    m_cancelButton  = new QPushButton(tr("Cancel"),this);
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(m_okButton);
    buttonLayout->addWidget(m_cancelButton);
    mainLayout->addLayout(buttonLayout);
    connect(m_okButton,     &QPushButton::clicked, this, &CommandEditor::acceptMessage);
    connect(m_cancelButton, &QPushButton::clicked, this, &CommandEditor::reject);
    setLayout(mainLayout);

    if(cmd)
    {
        m_command = cmd;
        qDebug()<<"Add m_nameEdit";
        m_nameEdit->setText(cmd->name());
        qDebug()<<"Add value";
        m_intervalBox->setValue(cmd->intervalTime());
        qDebug()<<"Add table";
        m_tableModel->setAllTableData(cmd->message());
        qDebug()<<"End add table";
    }
}

CommandEditor::~CommandEditor()
{
    delete m_tableModel;
    delete m_delegate;
    qDebug()<<Q_FUNC_INFO;
}

void CommandEditor::updateTable()
{
    qDebug()<<"update table";
    m_messageTable->viewport()->repaint();
}

void CommandEditor::setCommandData(Command *cmd)
{
    qDebug()<<Q_FUNC_INFO;
    if(cmd)
    {
        m_command = cmd;
        m_nameEdit->setText(cmd->name());
        m_intervalBox->setValue(cmd->intervalTime());
        m_tableModel->setAllTableData(cmd->message());
    }
}

Command* CommandEditor::showDialog(Command *cmd, QWidget *parent)
{
    qDebug()<<Q_FUNC_INFO;
    CommandEditor dialog(cmd, parent);
    dialog.exec();
    return CommandEditor::m_command;
}

void CommandEditor::acceptMessage()
{
    /* If call static_cast<StandartTableModel>(m_messageTable->model)
     * StandartTableModel constructor calls and all table data dissapear */

    QErrorMessage *msg = new QErrorMessage();
    qDebug()<<"M_COMMAND != nullptr :" << m_command;
    if(m_nameEdit->text() == "")
    {
        qDebug()<<"LENGTH = "<<m_nameEdit->text().length();
        msg->showMessage(QString(tr("Name empty ")));
        return;
    }
    QByteArray messageArray = m_tableModel->getAllTableData();
    if(m_command == nullptr)
    {
        qDebug()<<"M_COMMAND == nullptr :";
        m_command = new Command(m_nameEdit->text(), m_intervalBox->value(), messageArray);
    }
    else
    {
        for (auto i : m_command->message())
            qDebug()<<"command message :" << i;

        m_command->setName(m_nameEdit->text());
        m_command->setIntervaltime(m_intervalBox->value());
        m_command->setMessage(messageArray);
    }
    this->accept();
    qDebug()<<"MSG ACCEPTED";
}




