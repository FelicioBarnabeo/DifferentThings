#include "mytabledelegate.h"
#include "myvalidator.h"
#include <QLineEdit>
#include <QModelIndex>
#include <QString>
#include <QDebug>
#include <QLabel>
#include <QPainter>
#include <QPaintDevice>
#include <QStyleOptionViewItem>
#include <QApplication>
#include <QStyle>


MyTableDelegate::MyTableDelegate(QObject *parent) : QStyledItemDelegate(parent), m_validator(new MyValidator)
{
    m_representFormat = m_validator->formatNumber();
}

MyTableDelegate::~MyTableDelegate(){
    delete m_validator;
}

void MyTableDelegate::updateRepresentFormat()
{
    m_representFormat = m_validator->formatNumber();
}

QString MyTableDelegate::dataFormatString(const QModelIndex &index, int role) const
{
    QString data;
    if(m_validator->typeState() == MyValidator::ValidateType::ASCII){
        QChar symbol = index.model()->data(index, role).toChar();
        //qDebug()<<Q_FUNC_INFO<<"QCHAR = " << symbol;
        data[0] = symbol;
        //data = index.model()->data(index, role).toString();
    }
    else{
        data = QString::number(index.model()->data(index, role).toInt(), m_representFormat);
        qDebug()<<Q_FUNC_INFO<<"data = " << data;
    }
    return data;
}

QWidget * MyTableDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QLineEdit *editor = new QLineEdit(parent);
    editor->setValidator(m_validator);
    return editor;
}

void MyTableDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const{
    //qDebug()<< "editor int: " <<index.model()->data(index, Qt::EditRole).toInt();
    QString data = dataFormatString(index, Qt::EditRole);
    qDebug()<<Q_FUNC_INFO << index.row() <<" "<< index.column() << "STRING = " << data;
    QLineEdit *line = qobject_cast<QLineEdit*>(editor);
    //qDebug() << Q_FUNC_INFO << "value == " << value << "column = " << index.column() << "row = " << index.row();
    line->setText(data);
}

void MyTableDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    //QString data = QString::number(index.model()->data(index, Qt::DisplayRole).toInt(), m_representFormat);
    QString data = dataFormatString(index, Qt::DisplayRole);
//    qDebug() << "data= " << data << "number=" << index.model()->data(index, Qt::DisplayRole).toInt()
//             << index.model()->data(index, Qt::DisplayRole).userType()
//             << QVariant::typeToName(index.model()->data(index, Qt::DisplayRole).userType())
//             << index.model()->data(index, Qt::DisplayRole)   ;
    if(option.state & QStyle::State_Selected){
        painter->fillRect(option.rect, option.palette.highlight());
    }
    painter->save();
    painter->drawText(option.rect,data);
    painter->restore();
    //int yOffset = (option.rect.height() - PaintingScaleFactor) / 2;
    //painter->translate(option.rect.x(), option.rect.y() + yOffset);
    //painter->scale(PaintingScaleFactor, PaintingScaleFactor);

    //QApplication::style()->drawControl(QStyle::CE_ItemViewItem, qstyleoption_cast<const QStyleOption*>(&option), painter, labelData);
//    labelData->render(painter->device(), QPoint(option.rect.x(), option.rect.y() + yOffset),
//                    QRegion(0,0,option.rect.width(),option.rect.height()), QWidget::RenderFlag::DrawChildren);

    //QStyledItemDelegate::paint(painter, option, index);
}

void MyTableDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QLineEdit *line = static_cast<QLineEdit*>(editor);
    QString value = line->text();
    if(m_validator->typeState() == MyValidator::ValidateType::ASCII){
        char number = value[0].toLatin1();
        model->setData(index,number);
    }
    else{
        int number = value.toInt(nullptr,m_representFormat);
        model->setData(index,number);
    }
    return;
}

void MyTableDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

void  MyTableDelegate::clearDelegate(){
    if(m_validator != nullptr) delete m_validator;
}

void MyTableDelegate::setValidator(MyValidator *val){
    m_validator = val;
}

void MyTableDelegate::setHexValidate()
{
    if(m_validator->typeState() != MyValidator::ValidateType::HEX)
    {
        //qDebug()<<"SET HEX VALID";
        m_validator->setTypeState(MyValidator::ValidateType::HEX);
        updateRepresentFormat();
        //emit sigValidateChanged();
    }
    else return;
}

void MyTableDelegate::setDecValidate()
{
    if(m_validator->typeState() != MyValidator::ValidateType::DEC)
    {
        //qDebug()<<"SET DEC VALID";
        m_validator->setTypeState(MyValidator::ValidateType::DEC);
        updateRepresentFormat();
        //emit sigValidateChanged();
    }
    else return;
}

void MyTableDelegate::setOctValidate()
{
    if(m_validator->typeState() != MyValidator::ValidateType::OCT)
    {
        //qDebug()<<"SET OCT VALID";
        m_validator->setTypeState(MyValidator::ValidateType::OCT);
        updateRepresentFormat();
        //emit sigValidateChanged();
    }
    else return;
}

void MyTableDelegate::setBinValidate()
{
    if(m_validator->typeState() != MyValidator::ValidateType::BIN)
    {
        //qDebug()<<"SET BIN VALID";
        m_validator->setTypeState(MyValidator::ValidateType::BIN);
        updateRepresentFormat();
        //emit sigValidateChanged();
    }
    else return;
}

void MyTableDelegate::setAsciiValidate()
{
    if(m_validator->typeState() != MyValidator::ValidateType::ASCII)
    {
        //qDebug()<<"SET ASCII VALID";
        m_validator->setTypeState(MyValidator::ValidateType::ASCII);
        updateRepresentFormat();
        //emit sigValidateChanged();
    }
    else return;
}




















