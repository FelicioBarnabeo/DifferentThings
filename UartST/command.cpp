#include "command.h"

Command::Command(QString name, int interval, QByteArray message):
      m_name(name)
    , m_message(message)
    , m_sendIntervalTime(interval)
{

}
