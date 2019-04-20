#include "keypressevent.h"
#include <QKeyEvent>

bool KeyPressEvent::eventFilter(QObject *obj, QEvent *event)
{
    Q_UNUSED(obj)
    int t = event->type();
    if(t == QEvent::KeyPress || t == QEvent::KeyRelease
            || t == QEvent::TouchBegin || t == QEvent::TouchUpdate
            || t == QEvent::TouchEnd || t==QEvent::TouchCancel
            || t==QEvent::MouseButtonPress || t==QEvent::MouseButtonRelease)
    {
        Settings * m_settings = Settings::instance();
        if(m_settings->isAutoBrightnessMode())
            m_settings->runAutoBrightnessMode();
    }
    return QObject::eventFilter(obj,event);
}
