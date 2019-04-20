
#include "keypressevent.h"
#include <QKeyEvent>
#include <QFile>
#include <QString>
#include <QDebug>

using namespace std;

bool KeyPressEvent::eventFilter(QObject *obj, QEvent *event)
{
    Q_UNUSED(obj);
    try
    {
    int t = event->type();
    if(t == QEvent::KeyPress || t == QEvent::KeyRelease
            || t == QEvent::TouchBegin || t == QEvent::TouchUpdate
            || t == QEvent::TouchEnd || t==QEvent::TouchCancel)
    {
        power->reloadIdleTimer();
        if (t == QEvent::KeyPress)
        {
            if(!power->isSuspend()) //If not suspend mode
            {

                QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
                if(!keyEvent->isAutoRepeat())
                {
                    switch(keyEvent->key())
                    {
                    case Qt::Key_VolumeMute :
                        //driv->sendCommand("KEY_VOLUMEOFF","msophex");
                        driv->sendCommand("KEY_MUTE","vista_mce");
                        break;
                    case Qt::Key_Enter: //(OK)16777221
                        driv->sendCommand("KEY_OK","mceusb");
                        break;
                    case Qt::Key_Up : //16777235 = 0x1000013
                        driv->startSend("KEY_UP","vista_mce");
                        break;
                    case Qt::Key_Left://16777234:
                        driv->startSend("KEY_LEFT","vista_mce");
                        break;
                    case Qt::Key_Right://16777236:
                        driv->startSend("KEY_RIGHT","vista_mce");
                        break;
                    case Qt::Key_Down:// 16777237:
                        driv->startSend("KEY_DOWN","vista_mce");
                        break;
                    case Qt::Key_VolumeDown:// 16777328:
                        driv->startSend("KEY_VOLUMEDOWN","vista_mce");
                        break;
                    case Qt::Key_VolumeUp:// 16777330:
                        driv->startSend("KEY_VOLUMEUP","vista_mce");
                        break;
                    default:
                        return false;
                    }
                    return true;
                }
            }
        }
        else if (t == QEvent::KeyRelease)
        {
             if(!power->isSuspend()) //skipping first press key if this key press was wakeup pressing
             {
                 QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
                 if(!keyEvent->isAutoRepeat())
                 {
                     switch(keyEvent->key())
                     {
                     case Qt::Key_VolumeMute ://(KEY_MUTE) - 0x71 - 113
                         break;
                     case Qt::Key_Enter: //(OK)16777221
                         break;
                     case Qt::Key_Up : //16777235 = 0x1000013
                         driv->stopSend("KEY_UP","vista_mce");
                         break;
                     case Qt::Key_Left://16777234:
                         driv->stopSend("KEY_LEFT","vista_mce");
                         break;
                     case Qt::Key_Right://16777236:
                         driv->stopSend("KEY_RIGHT","vista_mce");
                         break;
                     case Qt::Key_Down:// 16777237:
                         driv->stopSend("KEY_DOWN","vista_mce");
                         break;
                     case Qt::Key_VolumeDown:// 16777328:
                         driv->stopSend("KEY_VOLUMEDOWN","vista_mce");
                         break;
                     case Qt::Key_VolumeUp:// 16777330:
                         driv->stopSend("KEY_VOLUMEUP","vista_mce");
                         break;
                     default:
                         return false;
                     }
                     return true;
                 }
             }
             else //skipping first release key if this key press was wakeup pressing
             {
                 power->setIsSuspend(false);
                 return true;
             }
        }
    }
   
    return false;
    }
    catch(...)
    {
        qDebug() << Q_FUNC_INFO << "Undefined exception";
    }
    return false;
}
