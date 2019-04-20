#include "standarttablemodel.h"
#include <QDebug>

StandartTableModel::StandartTableModel(QObject *parent):
    QAbstractTableModel(parent), m_row(1), m_column(1), m_maxColumn(8), m_maxIndex(0)
{
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
    int row = index.row();
    int col = index.column();
    uint curIdx = row * m_maxColumn + col;
    if (index.isValid() && role == Qt::EditRole)
    {        
        /* Checking index of table. If cursor on last element add row else add column
         * Column may be added only less then maxColumn times */
        qDebug()<< "last = " << row*m_maxColumn+col << "max= " << m_maxIndex
                << "size = " << m_tableData.size();

        if(curIdx >= m_maxIndex){
            if(curIdx == m_row*m_maxColumn-1){
                insertRows(row, 1, index);
                m_tableData.append(nullptr);

            }
            else if(m_column < m_maxColumn){
                insertColumns(col, 1, index);
            }
            m_maxIndex = curIdx;
            m_tableData.append(m_maxIndex+1-m_tableData.size(),uchar(0));
        }
        qDebug()<<"Row = "<<row<<"Col= "<<col<<"Row*m_maxColumn+col="<<row*m_maxColumn+ col;
//        if(row*m_maxColumn+col >= (m_tableData.size()-1)){
//            m_tableData.resize(row*m_maxColumn+col+1);
//        }
         m_tableData[row*m_maxColumn+ col] = value.toChar().toLatin1();
         qDebug()<<"SIZE == "<<m_tableData.size() << "MAX_INDEX = " << m_maxIndex;
        qDebug() << "index = "<< row*m_maxColumn + col << "value = "<< m_tableData[row*m_maxColumn + col] << "\n";
        emit dataChanged(index, index);
        return true;
    }
    //qDebug() << Q_FUNC_INFO << ": false";
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
    uint row = index.row();
    uint col = index.column();
    if (!index.isValid()){
        //qDebug()<<Q_FUNC_INFO<<" index not valid";
        return QVariant();
    }

    if (row*m_maxColumn+col >= m_tableData.size()){
        //qDebug()<<Q_FUNC_INFO<<" index row >=";
        return QVariant();
    }

    if (role == Qt::DisplayRole || role == Qt::EditRole){
//        qDebug()<<Q_FUNC_INFO<<" role ==";
//        qDebug()<<"array.at() " << index.row()*m_maxColumn + index.column() << "column == " << index.column();
//        qDebug()<< "VALUE = " << m_tableData[row*col+ col];

        return static_cast<uchar>(m_tableData[row*m_maxColumn+col]);
    }
    else{
        //qDebug()<<Q_FUNC_INFO<<" role !=";
        return QVariant();
    }
}

bool StandartTableModel::insertRows(int position, int count, const QModelIndex &parent)
{
    beginInsertRows(QModelIndex(), position, position+count-1);
    qDebug() << "row++";
    m_row += count;
    endInsertRows();
    return true;
}

//доработать, ошибка после добавления в command editor нескольких комманд и нажатия кнопки edit
bool StandartTableModel::insertColumns(int column, int count, const QModelIndex &parent)
{
    qDebug() << "column++" << column << " " << count ;
    beginInsertColumns(QModelIndex(), column, column+count-1);
    m_column += count;
    endInsertColumns();
    return true;
}

const QByteArray & StandartTableModel::getAllTableData() const{
    qDebug()<<Q_FUNC_INFO << "table size = " << m_tableData.size();
    return m_tableData;
}

void StandartTableModel::setAllTableData(const QByteArray & table)
{
    qDebug()<<Q_FUNC_INFO;
    m_tableData = table;
    uint mod = m_tableData.size() % m_maxColumn;
    uint div = m_tableData.size() / m_maxColumn;
    uint rowSize = (mod) ? div + 1 : div;
    uint colSize = m_tableData.size()<=m_maxColumn ? m_tableData.size() : m_maxColumn;
    qDebug()<<"rowsize = "<< rowSize << "colSize = "<< colSize;

    insertColumns(m_column, colSize-m_column);
    insertRows(m_row, rowSize-m_row);

    m_maxIndex = m_tableData.size() - 1;
    qDebug()<< "m_row = "<< m_row << "m_column = "<< m_column << "maxindex = "<< m_maxIndex;
}
