#include "commandlistmodel.h"
#include <QDebug>
#include "command.h"

CommandListModel::CommandListModel(QObject *parent) :
      QAbstractListModel(parent)
    , m_row(0)
{
}

int CommandListModel::rowCount(const QModelIndex &parent) const
{
    return m_row;
}

QVariant CommandListModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    if (!index.isValid()){
        qDebug()<<Q_FUNC_INFO<<" index not valid";
        return QVariant();
    }

    if (row >= m_messagesList.size()){
        //qDebug()<<Q_FUNC_INFO<<" index row >=";
        return QVariant();
    }

    if (role == Qt::DisplayRole || role == Qt::EditRole){
        //qDebug()<<Q_FUNC_INFO<<" role ==";
        return m_messagesList[row]->name();
    }
    else{
        //qDebug()<<Q_FUNC_INFO<<" role !=";
        return QVariant();
    }
}

bool CommandListModel::insertRows(int position, int rows, const QModelIndex &parent)
{
    beginInsertRows(QModelIndex(), position, position+rows-1);
    qDebug() << "row++";
    m_row+=rows;
    endInsertRows();
    return true;
}

bool CommandListModel::removeRows(int position, int rows, const QModelIndex &parent)
{
    beginRemoveRows(parent, position, position+rows-1);
    m_row-=rows;
    endRemoveRows();
    return true;
}

void CommandListModel::addCommand(Command *msg)
{
    //qDebug()<<"Add command";
    insertRows(m_row, 1, this->index(m_row));
    m_messagesList.append(msg);
    //qDebug()<<"ADD &msg: " << &msg;
    //qDebug()<<"MESSAGES SIZE" << m_messagesList.size();
}

void CommandListModel::editCommand(QModelIndex idx, Command *msg)
{
      //qDebug()<<"Edit command";
      m_messagesList[idx.row()] = msg;
      //qDebug()<<"EDIT &msg: " << &msg;
}

void CommandListModel::deleteCommand(QModelIndex idx)
{
    //qDebug()<<"QLISTMODEL delete command";
    delete m_messagesList.at(idx.row());
    m_messagesList.removeAt(idx.row());
    removeRows(m_row, 1, idx);
}

void CommandListModel::clear()
{
    for(Command * cmd: m_messagesList){
        delete cmd;
    }
    m_messagesList.clear();
}

Command * CommandListModel::operator[](int idx){
    if(idx >=0 && idx<m_messagesList.size())
        return m_messagesList[idx];
    else{
        qDebug()<<"Not correct index";
        return nullptr;
    }
}

//Qt::ItemFlags CommandListModel::flags(const QModelIndex &index) const
//{
//    if (!index.isValid()){
//        return Qt::ItemIsEnabled;
//        //qDebug()<<Q_FUNC_INFO << "flags" << Qt::ItemIsEnabled;
//    }
//    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
//}

//bool CommandListModel::setData(const QModelIndex &index, const QVariant &value, int role)
//{
//    int row = index.row();
//    if (index.isValid() && role == Qt::EditRole)
//    {
//        /* Checking index of table. If cursor on last element add row else add column
//         * Column may be added only less then maxColumn times */
//        //m_messagesList[row] = value.toString();
//        emit dataChanged(index, index);
//        return true;
//    }
//    qDebug() << Q_FUNC_INFO << ": false";
//    return false;
//}
