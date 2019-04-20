#include "option.h"
#include <QVBoxLayout>
#include <QHostAddress>
#include <QMessageBox>

Option::Option(QWidget *parent) : QWidget(parent)
{
    m_airshowIpLbl = new QLabel(tr("Адрес сервера аэрошоу:"));
    m_airshowPortLbl = new QLabel(tr("Порт сервера аэрошоу:"));
    m_applyBtn = new QPushButton(tr("Применить"));
    m_airshowIp = new QLineEdit(tr("192.168.1.52"));
    m_airshowPort = new QLineEdit(tr("9600"));

    m_infoIpLbl = new QLabel(tr("Адрес сервера инфо:"));
    m_infoPortLbl = new QLabel(tr("Порт сервера инфо:"));
    m_infoIp = new QLineEdit(tr("192.168.1.52"));
    m_infoPort = new QLineEdit(tr("9700"));

    m_verLbl = new QLabel("<b>АвиаМакс 2017. ДНИИ Волна.</b>");

    m_infoIpLbl->setAlignment(Qt::AlignCenter);
    m_infoPortLbl->setAlignment(Qt::AlignHCenter);
    m_infoIp->setAlignment(Qt::AlignCenter);
    m_infoPort->setAlignment(Qt::AlignCenter);

    m_airshowIpLbl->setAlignment(Qt::AlignCenter);
    m_airshowPortLbl->setAlignment(Qt::AlignHCenter);
    m_airshowIp->setAlignment(Qt::AlignCenter);
    m_airshowPort->setAlignment(Qt::AlignCenter);

    m_verLbl->setAlignment(Qt::AlignCenter);

    QVBoxLayout *lay = new QVBoxLayout;
    lay->addWidget(m_airshowIpLbl);
    lay->addWidget(m_airshowIp);
    lay->addWidget(m_airshowPortLbl);
    lay->addWidget(m_airshowPort);
    lay->addStretch(1);
    lay->addWidget(m_infoIpLbl);
    lay->addWidget(m_infoIp);
    lay->addWidget(m_infoPortLbl);
    lay->addWidget(m_infoPort);
    lay->addStretch(4);
    lay->addWidget(m_applyBtn);
    lay->addStretch(4);
    lay->addWidget(m_verLbl);
    this->setLayout(lay);

    connect(m_applyBtn,&QPushButton::clicked,this,&Option::apply);
}

void Option::apply(void)
{
    QHostAddress ipAddr;
    if (!ipAddr.setAddress(m_airshowIp->text())) {
        QMessageBox msgBox(this);
        msgBox.setText(tr("Неправильный адрес сервера аэрошоу."));
        msgBox.exec();
        return;
    }

    if (m_airshowPort->text().toUInt()>65535 || m_airshowPort->text().toUInt()<1025) {
        QMessageBox msgBox(this);
        msgBox.setText(tr("Неправильный порт сервера аэрошоу."));
        msgBox.exec();
        return;
    }

    if (!ipAddr.setAddress(m_infoIp->text())) {
        QMessageBox msgBox(this);
        msgBox.setText(tr("Неправильный адрес сервера инфо."));
        msgBox.exec();
        return;
    }

    if (m_infoPort->text().toUInt()>65535 || m_infoPort->text().toUInt()<1025) {
        QMessageBox msgBox(this);
        msgBox.setText(tr("Неправильный порт сервера инфо."));
        msgBox.exec();
        return;
    }

    emit airshowServerConfigChanged(m_airshowIp->text(),m_airshowPort->text());
    emit infoServerConfigChanged(m_infoIp->text(),m_infoPort->text());
}
