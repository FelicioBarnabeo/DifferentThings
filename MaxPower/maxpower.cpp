#include "maxpower.h"
#include "airshow.h"
#include "info.h"
#include "option.h"
#include <QHBoxLayout>
#include <QTabWidget>

MaxPower::MaxPower(QWidget *parent): QWidget(parent)
{
    QHBoxLayout *lay = new QHBoxLayout;
    QTabWidget *tabs = new QTabWidget;
    Info *infoTab = new Info;
    Airshow *airshowTab = new Airshow;
    Option *optionTab = new Option;
    tabs->addTab(infoTab,tr("Спец.Инфо"));
    tabs->addTab(airshowTab,tr("Аэрошоу"));
    tabs->addTab(optionTab,tr("Настройки"));
    lay->addWidget(tabs);
    this->setLayout(lay);

    connect(optionTab,&Option::airshowServerConfigChanged,
            airshowTab,&Airshow::setServerConfig);
    connect(optionTab,&Option::infoServerConfigChanged,
            infoTab,&Info::setServerConfig);
}

MaxPower::~MaxPower()
{
}
