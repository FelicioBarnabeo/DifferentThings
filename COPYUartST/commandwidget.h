#ifndef COMMANDWIDGET_H
#define COMMANDWIDGET_H

#include <QWidget>
#include <QModelIndex>
#include <QJsonObject>
#include <QJsonArray>
#include "command.h"

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class Command;
class QVBoxLayout;
class QHBoxLayout;
class QListView;
class CommandEditor;
class CommandListModel;
QT_END_NAMESPACE

class CommandWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CommandWidget(QWidget *parent = 0);
    ~CommandWidget();
    void write(QJsonObject &json) const;
    void read(QJsonObject &json);

public slots:
    void editButtonHandle();
    void addButtonHandle();
    void deleteButtonHandle();
    void sendButtonHandle();
    void stopSendButtonHandle();
    void clear();
private:
    QPushButton * m_addMessageBtn;
    QLabel * m_commandName;
    QPushButton * m_sendButton;
    QPushButton * m_stopSendButton;
    QPushButton * m_editButton;
    QPushButton * m_deleteButton;
    QVBoxLayout * m_mainLayout;
    QListView * m_commandsList;
    CommandEditor * m_commandEditor;
    CommandListModel *m_model;
signals:
    void edited(QModelIndex idx, Command *cmd);
    void added(Command *cmd);
    void deleted(QModelIndex idx);
    void sendStarted(Command *);
    void sendStopped();
};

#endif // COMMANDWIDGET_H
