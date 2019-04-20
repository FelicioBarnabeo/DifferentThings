#ifndef STANDARTTABLEMODEL_H
#define STANDARTTABLEMODEL_H

#include <QAbstractTableModel>

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
    //QVector<QVector<unsigned char> > getAllTableData() const;
    //void setAllTableData(QVector<QVector<unsigned char> > table);
    const QByteArray &getAllTableData() const;
    void setAllTableData(const QByteArray &msg);
private:
    uint m_row;
    uint m_column;
    const uint m_maxColumn;
    uint m_maxIndex;
    //QVector< QVector<unsigned char> > m_tableData;
    QByteArray m_tableData;
};

#endif // STANDARTTABLEMODEL_H
