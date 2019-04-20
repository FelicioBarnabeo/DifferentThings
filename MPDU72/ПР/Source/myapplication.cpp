#include "myapplication.h"
#include "powersupply.h"
#include <QObject>
#include <QTouchEvent>
#include <QMouseEvent>
#include <QQuickWindow>
#include <QScreen>
#include <QDebug>
#include <QQmlComponent>

MyApplication::MyApplication(int &argc, char **argv):QGuiApplication(argc,argv)//, m_language("ru"), m_langEmptyStr("")
{
        //m_translator = new QTranslator();
//        if(!m_translator->load("translations/" + m_language + ".qm"))
//            //qDebug()<<"Translator successfully loaded";
//            qDebug()<<"Error load translator";
//            //qApp->exit(1);
//        this->instance()->installTranslator(m_translator);
        power_supply = PowerSupplySingleton::Instance();
        installEventFilter(&key_handler);
        connect(power_supply,SIGNAL(wakeUpSystem()),this,SLOT(wakeUp()));
        timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),power_supply,SLOT(checkBatteryStatus()));
        //power_supply->checkBatteryStatus();
        timer->start(9000);
        //connect(this, &MyApplication::languageChanged, this, &MyApplication::applyChangeLanguage);
}

MyApplication::~MyApplication()
{
    //delete m_translator;
    //timer->stop();
    //delete timer;
}

//void MyApplication::MyApplication::applyChangeLanguage()
//{
//    this->instance()->removeTranslator(m_translator);
//    delete m_translator;
//    m_translator = new QTranslator(this);
//    m_translator->load("translations/" + m_language + ".qm");
//    this->instance()->installTranslator(m_translator);
//    emit langEmptyStrChanged("");
//    //qDebug()<<"Changed lang" << m_language;
//}


void MyApplication::wakeUp()
{
    //qDebug()<<"wakeup application";
    QWindow *window =  qApp->focusWindow();
    power_supply->checkBatteryStatus();
    //window->resize(window->width(),window->height());
    window->show();
    qApp->processEvents();
    timer->start();
}




