#include "standarttablemodel.h"
#include <QDebug>

StandartTableModel::StandartTableModel(QObject *parent): QAbstractTableModel(parent), m_row(1), m_column(1), m_maxColumn(3), m_maxIndex(0)
{
    m_byteArray.resize(16);
}

Qt::ItemFlags StandartTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid()){
        return Qt::ItemIsEnabled;
        //qDebug()<<Q_FUNC_INFO << "flags" << Qt::ItemIsEnabled;
    }
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool StandartTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole)
    {
//        qDebug() << "row = "      << index.row()
//                 << "column = "   << index.column()
//                 << "value = "    << value.toInt()
//                 << "size = "     << m_byteArray.size()
//                 << "maxIndex = " << m_maxIndex;
        if((index.row() * m_maxColumn + index.column()) == m_maxIndex){
            if(m_maxIndex + 1 + m_maxColumn >= m_byteArray.size())
                m_byteArray.resize(m_byteArray.size() + 16);
            if(m_maxIndex + 1 >= m_maxColumn){
                insertRows(index.row(), 1, index);
            }
            else{
                insertColumns(index.column(), 1, index);
            }
        }
        m_byteArray[index.row()*m_maxColumn + index.column()] = static_cast<uchar>(value.toInt());
        qDebug() << "index = "<< index.row()*m_maxColumn + index.column() << "value = "
                 << (uchar)m_byteArray[index.row()*m_maxColumn + index.column()];
        emit dataChanged(index, index);
        return true;
    }
    qDebug() << Q_FUNC_INFO << ": false";
    return false;
}


int StandartTableModel::rowCount(const QModelIndex &parent) const
{
    return m_row;
}

int StandartTableModel::columnCount(const QModelIndex &parent) const
{
    return m_column;
}

QVariant StandartTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()){
        //qDebug()<<Q_FUNC_INFO<<" index not valid";
        return QVariant();
    }

    if (index.row() >= m_byteArray.size()){
        //qDebug()<<Q_FUNC_INFO<<" index row >=";
        return QVariant();
    }

    if (role == Qt::DisplayRole || role == Qt::EditRole){
        //qDebug()<<Q_FUNC_INFO<<" role ==";
        //qDebug()<<"array.at() " << index.row()*m_maxColumn + index.column() << "column == " << index.column();
        qDebug()<< "VALUE = " << (uchar)(m_byteArray[index.row()*m_maxColumn + index.column()]);
        return (uchar)(m_byteArray[index.row()*m_maxColumn + index.column()]);
    }
    else{
        //qDebug()<<Q_FUNC_INFO<<" role !=";
        return QVariant();
    }
}


bool StandartTableModel::insertRows(int position, int rows, const QModelIndex &parent)
{
    beginInsertRows(QModelIndex(), position, position+rows-1);
    qDebug() << "row++";
    m_row++;
    m_maxIndex += m_maxColumn;
    endInsertRows();
    return true;
}

bool StandartTableModel::insertColumns(int column, int count, const QModelIndex &parent)
{
    //beginInsertRows(QModelIndex(), position, position+rows-1);
    qDebug() << "column++";
    beginInsertColumns(QModelIndex(), column, column+count-1);
    m_column++;
    m_maxIndex++;
    endInsertColumns();
    return true;
}

QByteArray StandartTableModel::getAllTableData() const{
    return m_byteArray;
}
