#ifndef LOGINTERFACE_H
#define LOGINTERFACE_H


#include <QFile>
#include <QDebug>
#include "constants.h"

typedef QMap<QString,double> MapStringDouble;

class ILogger
{
public:
    virtual void log(MapStringDouble) = 0;
    ILogger(){}
    virtual ~ILogger() {}
};

class ArincMsgLogger : public ILogger
{
public:
    ArincMsgLogger();
    ~ArincMsgLogger();
    void log(MapStringDouble);
    MapStringDouble readLog();
private:
    QFile geologfile;
};

#endif // LOGINTERFACE_H
