#include "listmodel.h"
#include "spidriver.h"
#include "unistd.h"
#include <QDebug>
#include <QString>

void ListMod::addRow(GeoData * row)
{
    beginInsertRows(QModelIndex(), m_geoList.count(), m_geoList.count());
    m_geoList << row;
    endInsertRows();
}

ListMod::ListMod(QObject *parent) : QAbstractListModel(parent)
{
//    fd = open_device("/dev/spidev32766.0");
//    set_spi_config(fd);

//    // write aclk to 4Mhz
//    uint8_t mas[] = {0x04};
//    write_bit(fd,0x38,mas,1);

//    // write transmit control register
//    mas[0] = 0x21;
//    write_bit(fd,0x08, mas, 1);

    m_roles = roleNames();
    addRow(new GeoData("Широта", 50,  "Северная", MatrixOfSustain::normal ,true));
    //    addRow(new GeoData("Долгота",                100,  "Востоная", "норм.",true));
//    addRow(new GeoData("Расстояние до КПМ(км)",  500,           0, "норм.",true));
//    addRow(new GeoData("Время до КПМ(мин)",       60,           0, "норм.",true));
//    addRow(new GeoData("Скорость(км.ч)",         700,           0, "норм.",true));
//    addRow(new GeoData("Высота(м)",             5000,           0, "норм.",true));
//    addRow(new GeoData("Температура снаружи",      5,      "Плюс", "норм.",true));
//    addRow(new GeoData("Время текущее",QTime(12,0,0),           0, "норм.",true));
//    addRow(new GeoData("Дата",      QDate(2016,2,20),           0, "норм.",true));
}

ListMod::~ListMod()
{
    close(fd);
}

//void ListMod::removeRow(int row, const QModelIndex &parent)
//{
//    delete(m_geoList[row]);
//    m_geoList.removeAt(row);
//}

//QVariant ListMod::data(const QModelIndex &idx, int role) const
//{
//    int columnId = role - Qt::UserRole - 1;
//    QModelIndex index = this->index(idx.row(),columnId);
//    if(index.row() < 0 || index.row() > m_geoList.count())
//    {
//        return QVariant();
//    }
//    switch(role)
//    {
//    case geoName:
//        return m_geoList[index.row()]->geoName();
//    case geoValue:
//        return m_geoList[index.row()]->geoValue();
//    case sign:
//        return m_geoList[index.row()]->sign();
//    case matrixSustain:
//        return static_cast<int>(m_geoList[index.row()]->matrixSustain());
//    case parity:
//        return m_geoList[index.row()]->parity();
//   default:
//        return QVariant();
//    }
//    return QVariant();
//}

//bool ListMod::setData(const QModelIndex &index, const QVariant &value, int role)
//{
//    bool res = true;
//    switch(role)
//    {
//    case geoName:
//        m_geoList[index.row()]->setGeoName(value.toString());
////        dataChanged(const QModelIndex &topLeft,
////                    const QModelIndex &bottomRight, const QVector<int> &roles);
//        break;
//    case geoValue:
//        m_geoList[index.row()]->setGeoValue(value.toDouble());
//        //dataChanged(&index, &index, roles);
//        break;
//    case sign:
//        m_geoList[index.row()]->setSign(value.toString());
//        break;
//    case matrixSustain:
//        m_geoList[index.row()]->setMatrixSustain(value.toString());
//        break;
//    case parity:
//        m_geoList[index.row()]->setParity(value.toBool());
//        break;
//    default:
//        res = false;
//        break;
//    }
//    return res;
//}

QHash<int,QByteArray> ListMod::roleNames() const
{
    QHash<int,QByteArray> m_roles;
    m_roles[geoName]       = "geoname";
    m_roles[geoValue]      = "geovalue";
    m_roles[sign]          = "sign";
    m_roles[matrixSustain] = "matrixSustain";
    m_roles[parity]        = "parity";
    return m_roles;
}

int ListMod::rowCount(const QModelIndex &parent) const
{
    return m_geoList.count();
}

int ListMod::columnCount(const QModelIndex &parent) const
{
    return m_roles.count();
}

QString ListMod::getName(int row) const
{
    QVariant name = this->data(this->index(row,0),geoName);
    qDebug() << "GeoLabel: " << name.toString();// << "Code:" << code;
    return name.toString();
}

int ListMod::getLabelCode(int row) const
{
    int code = m_geoList[0]->geoLabelCode(getName(row));
    return code;
}


void ListMod::sendRowFromTable(const int row) const
{
    uint8_t mas[4];
    int code = getLabelCode(row);
    mas[3] = static_cast<uint8_t>(code);
    mas[0] = 0xFF;
    mas[1] = 0xAA;
    mas[2] = 0xCC;
    write_bit(fd,0x0C,mas,4);

}

void ListMod::sendDataFromTable() const
{

//       // QVariant msg = data();
//          mas[0] = msg.toInt(&ok,16);
//          write_bit(fd,0x0C,mas,4);
}


