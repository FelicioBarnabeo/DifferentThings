#ifndef KEYPRESSEVENT_H
#define KEYPRESSEVENT_H

#include <QObject>
#include "lirc.h"
#include "powersupply.h"


class KeyPressEvent : public QObject
{
    Q_OBJECT
    LircSingleton *driv = LircSingleton::Instance();
    PowerSupplySingleton *power = PowerSupplySingleton::Instance();
protected:
    bool eventFilter(QObject *obj, QEvent *event);
signals:
public slots:
};

#endif // KEYPRESSEVENT_H
