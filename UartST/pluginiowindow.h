#ifndef PLUGINIOWINDOW_H
#define PLUGINIOWINDOW_H

#include <QWidget>
#include <QVector>
#include "command.h"

QT_BEGIN_NAMESPACE
class QTableWidget;
QT_END_NAMESPACE

class PluginIOWindow : public QWidget
{
    Q_OBJECT
public:
    PluginIOWindow(QWidget *parent = 0);
private:
    QTableWidget *m_messageViewer;
    QVector<Command> m_messages;
};

#endif // PLUGINIOWINDOW_H
