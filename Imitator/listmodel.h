#ifndef ListMod_H
#define ListMod_H

#include <QObject>
#include <QQmlContext>
#include <QAbstractListModel>
#include <QSharedPointer>
#include "geodata.h"

//typedef QMap<> MapStringInt;
class ListMod : public QAbstractListModel
{
    Q_OBJECT
    //ListMod(const ListMod &);
    //ListMod & operator=(const ListMod &a);
    QQmlContext *m_eng;
    QList<GeoData *> m_geoList;
    QHash<int,QByteArray> m_roles;
    int fd; //file descriptor for connect to arinc device from spi

public:
    explicit ListMod(QObject *parent = 0);
    ~ListMod();

    QVariant data(const QModelIndex &idx, int role = Qt::DisplayRole) const{};
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole){};
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    void setQmlContext(QQmlContext *context);
    void addRow(GeoData *);

    enum Roles
    {
        geoName = Qt::UserRole + 1,
        geoValue,
        sign,
        matrixSustain,
        parity,
    };

public slots:
    void sendRowFromTable(const int row) const;
    void sendDataFromTable() const;
    QString getName(int row) const;
    int getLabelCode(int row) const;
    //void removeRow(int row, const QModelIndex &parent);

protected:
    QHash<int,QByteArray> roleNames() const;
signals:
    void dataChanged(const QModelIndex &topLeft,
                     const QModelIndex &bottomRight, const QVector<int> &roles);
};

#endif // ListMod_H
