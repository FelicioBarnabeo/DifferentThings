#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H

#include <QGuiApplication>
#include "keypressevent.h"
#include "powersupply.h"
#include <QObject>
#include <QQmlApplicationEngine>
#include <QTimer>
#include <QTranslator>

class MyApplication : public QGuiApplication
{
    Q_OBJECT
    //Q_PROPERTY(QString language READ language WRITE setLanguage NOTIFY languageChanged)
    //Q_PROPERTY(QString langEmptyStr READ langEmptyStr WRITE setLangEmptyStr NOTIFY langEmptyStrChanged)
public:
    explicit MyApplication(int &argc,char **argv);
    ~MyApplication();
    QQmlApplicationEngine & getEngine(){return engine;}
    PowerSupplySingleton* getBattery(){return power_supply;}


//    QString language() const
//    {
//        return m_language;
//    }

//    QString langEmptyStr() const
//    {
//        return m_langEmptyStr;
//    }

private:
    QTimer *timer;
    KeyPressEvent key_handler;
    PowerSupplySingleton *power_supply ;
    QQmlApplicationEngine engine;
    QTranslator * m_translator;

//    QString m_language;
//    QString m_langEmptyStr;

signals:

//void languageChanged(QString language);

//void langEmptyStrChanged(QString langEmptyStr);

public slots:
    //void applyChangeLanguage();
    void wakeUp();
//    void setLanguage(QString language)
//    {
//        if (m_language == language){
//            //qDebug()<<"m_language = " << m_language << "language = "<<language;
//            return;
//        }
//        //qDebug()<<"m_language = " << m_language <<"language = "<<language;
//        m_language = language;
//        emit languageChanged(language);
//    }
//    void setlangEmptyStr(QString langEmptyStr)
//    {
//        if (m_langEmptyStr == langEmptyStr)
//            return;

//        m_langEmptyStr = langEmptyStr;
//        emit langEmptyStrChanged(langEmptyStr);
//    }
//    void setLangEmptyStr(QString langEmptyStr)
//    {
//        if (m_langEmptyStr == langEmptyStr)
//            return;

//        m_langEmptyStr = langEmptyStr;
//        emit langEmptyStrChanged(langEmptyStr);
//    }
};

#endif // MYAPPLICATION_H
