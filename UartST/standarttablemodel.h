#ifndef STANDARTTABLEMODEL_H
#define STANDARTTABLEMODEL_H

#include <QAbstractTableModel>
#include <QByteArray>

class StandartTableModel : public QAbstractTableModel
{
public:
    StandartTableModel(QObject *parent = Q_NULLPTR);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool insertRows(int position, int rows, const QModelIndex &parent  = QModelIndex()) override;
    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;
public slots:
    QByteArray getAllTableData() const;

private:
    QByteArray m_byteArray;
    int m_row;
    int m_column;
    const int m_maxColumn;
    int m_maxIndex;
};

#endif // STANDARTTABLEMODEL_H
