#ifndef BACKLIGHTER_H
#define BACKLIGHTER_H

#include <QProcess>
#include <QString>
#include <QDebug>

class Backlighter {

    Backlighter() = delete;

public:
    static void setScreenBrightness(int value) {
        if (!value) value++;
        QString cmd = QString("sh -c \"echo %1 > "
                              "/sys/class/backlight/"
                              "backlight_lvds/brightness\"").arg(value);

        QProcess proc;
        proc.start(cmd);
        proc.waitForFinished(3000);

        qDebug()<<"setBrightness completed";
    }
};


#endif // BACKLIGHTER_H
