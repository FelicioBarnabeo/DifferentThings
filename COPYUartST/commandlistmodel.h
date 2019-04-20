#ifndef COMMANDLISTMODEL_H
#define COMMANDLISTMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QList>
#include "command.h"

class CommandListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    CommandListModel(QObject * parent = Q_NULLPTR);
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    //bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    //Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool insertRows(int row, int count, const QModelIndex &parent) override;
    bool removeRows(int row, int count, const QModelIndex &parent) override;
    Command * operator[](int idx);
    QList<Command *> getMsgList() const
    {
        return m_messagesList;
    }
public slots:
    void addCommand(Command *msg);
    void editCommand(QModelIndex idx, Command *msg);
    void deleteCommand(QModelIndex idx);
    void clear();
private:
    QList<Command *> m_messagesList;
    int m_row;
};

#endif // COMMANDLISTMODEL_H
