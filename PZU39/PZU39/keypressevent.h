#ifndef KEYPRESSEVENT_H
#define KEYPRESSEVENT_H

#include <QObject>
#include "settings.h"

class KeyPressEvent : public QObject
{
    Q_OBJECT
protected:
    bool eventFilter(QObject *obj, QEvent *event);
signals:
public slots:
};

#endif // KEYPRESSEVENT_H
