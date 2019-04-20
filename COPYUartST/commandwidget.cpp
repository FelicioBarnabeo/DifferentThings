#include "commandwidget.h"
#include "command.h"
#include "dialogcommandeditor.h"
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include "commandlistmodel.h"
#include <QModelIndex>
#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>

CommandWidget::CommandWidget(QWidget *parent) :
    QWidget(parent)
    , m_addMessageBtn(new QPushButton(tr("Add Message"), this))
    , m_commandName(new QLabel)
    , m_sendButton(new QPushButton(tr("Send"), this))
    , m_stopSendButton(new QPushButton(tr("Stop"), this))
    , m_editButton(new QPushButton(tr("Edit"), this))
    , m_deleteButton(new QPushButton(tr("Delete"), this))
    , m_mainLayout(new QVBoxLayout)
    , m_commandsList(new QListView(this))
    , m_commandEditor(new CommandEditor)
    , m_model(new CommandListModel(this))
{
    m_mainLayout->addWidget(m_addMessageBtn,1);
    m_mainLayout->addWidget(m_commandsList);
    QHBoxLayout *toolCommand = new QHBoxLayout;
    toolCommand->addWidget(m_sendButton);
    toolCommand->addWidget(m_stopSendButton);
    toolCommand->addWidget(m_editButton);
    toolCommand->addWidget(m_deleteButton);
    m_mainLayout->addLayout(toolCommand);
    setLayout(m_mainLayout);

    m_commandsList->setModel(m_model);
    //m_commandsList->setMovement(QListView::Movement::Free);
    //m_commandsList->setBatchSize(2);
    connect(m_addMessageBtn,  &QPushButton::clicked, this, &CommandWidget::addButtonHandle);
    connect(m_editButton,     &QPushButton::clicked, this, &CommandWidget::editButtonHandle);
    connect(m_deleteButton,   &QPushButton::clicked, this, &CommandWidget::deleteButtonHandle);
    connect(m_sendButton,     &QPushButton::clicked, this, &CommandWidget::sendButtonHandle);
    connect(m_stopSendButton, &QPushButton::clicked, this, &CommandWidget::stopSendButtonHandle);

    connect(this, &CommandWidget::added,   m_model, &CommandListModel::addCommand);
    connect(this, &CommandWidget::edited,  m_model, &CommandListModel::editCommand);
    connect(this, &CommandWidget::deleted, m_model, &CommandListModel::deleteCommand);
}

CommandWidget::~CommandWidget()
{
    delete m_addMessageBtn;
    delete m_commandName;
    delete m_sendButton;
    delete m_stopSendButton;
    delete m_editButton;
    delete m_deleteButton;
    delete m_mainLayout;
    delete m_commandsList;
    delete m_commandEditor;
}

void CommandWidget::clear()
{
    m_model->clear();
}

void CommandWidget::write(QJsonObject &json) const
{
    QJsonArray jsonArray;
    foreach(Command * cmd, m_model->getMsgList()){
        QJsonObject jsonObj;
        cmd->write(jsonObj);
        jsonArray.append(jsonObj);
    }
    json["CommandList"] = jsonArray;
}

void CommandWidget::read(QJsonObject &json)
{
    QJsonArray array = json["CommandList"].toArray();
    for(int i=0; i<array.size(); i++){
        QJsonObject jObj = array[i].toObject();
        Command *cmd = new Command();
        cmd->read(jObj);
        m_model->addCommand(cmd);
    }
}

void CommandWidget::addButtonHandle()
{
    Command * temp = CommandEditor::showDialog(nullptr, this);
    if(temp != nullptr)
        emit added(temp);
    else qDebug()<<"Not added";
}

void CommandWidget::editButtonHandle()
{
    QModelIndex index = m_commandsList->currentIndex();
    if(index.isValid())
    {
        //qDebug()<<"ROW valid = " << index.row();
        Command * temp = CommandEditor::showDialog(m_model->operator [](index.row()), this);
        if(temp != nullptr)
            emit edited(index, temp);
        else qDebug()<<"Not edited";
    }
    else
        qDebug()<<"ROW no valid = " << index.row();
}

void CommandWidget::deleteButtonHandle()
{
    QModelIndex index = m_commandsList->currentIndex();
    if(index.isValid())
        emit deleted(index);
    else
        qDebug()<<"Not deleted";
}

void CommandWidget::sendButtonHandle()
{
    QModelIndex index = m_commandsList->currentIndex();
    if(index.isValid())
    {
        //qDebug()<<"ROW valid = " << index.row();
        Command * temp = m_model->operator [](index.row());
        if(temp != nullptr)
            emit sendStarted(temp);
        else qDebug()<<"Not correct command!";
    }
    else
        qDebug()<<"ROW no valid = " << index.row();
}

void CommandWidget::stopSendButtonHandle()
{
    emit sendStopped();
}

