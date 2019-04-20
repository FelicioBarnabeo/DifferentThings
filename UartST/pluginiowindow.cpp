#include "pluginiowindow.h"
#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QBoxLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QGroupBox>
#include "senderwidget.h"
#include "mytabledelegate.h"

PluginIOWindow::PluginIOWindow(QWidget *parent) : QWidget(parent)
{

    SenderWidget *sw = new SenderWidget();
    m_messageViewer = new QTableWidget(10,10,this);
//    messageViewer->setText("Send:\n");
//    messageViewer->setText("Receice:\n");

    QHBoxLayout *mainLayout = new QHBoxLayout;
    QVBoxLayout *subMainLayout = new QVBoxLayout;
    subMainLayout->addWidget(m_messageViewer);
    mainLayout->addLayout(subMainLayout,4);

    //QComboBox *sendFormatComboBox = new QComboBox();
    //QComboBox *dataComboBox = new QComboBox();
    QVBoxLayout *sub2mainLayout = new QVBoxLayout;
    QPushButton *addMessagePushButton = new QPushButton(tr("Add Message"));
    //QGroupBox* messagesGBox = new QGroupBox(tr("Messages"));

    for(auto message : m_messages){
        QGridLayout *messageLayout = new QGridLayout;
        messageLayout->addWidget(new QLabel(message.name()), 0, 0);
        messageLayout->addWidget(new QPushButton(tr("Send")), 0, 1);
        messageLayout->addWidget(new QPushButton(tr("Edit")), 0, 2);
        messageLayout->addWidget(new QPushButton(tr("Del")), 0, 3);
        //messageLayout->addWidget(new QLabel(tr()), 0, 1);
    }
    sub2mainLayout->addWidget(addMessagePushButton);

    mainLayout->addLayout(sub2mainLayout,1);

    //subMainLayout->addSpacing(100);
    setLayout(mainLayout);

    connect(addMessagePushButton,&QPushButton::clicked,sw,&SenderWidget::show);

}

//PluginIOWindow::
