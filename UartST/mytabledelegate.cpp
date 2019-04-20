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

QWidget * m_parent;

MyTableDelegate::MyTableDelegate(QObject *parent) : QStyledItemDelegate(parent)
{
    m_validator = new MyValidator;
}

MyTableDelegate::~MyTableDelegate(){
    delete m_validator;
}

QWidget * MyTableDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QLineEdit *editor = new QLineEdit(parent);
    //setHexValidate();
    //mValidator->setTypeState(MyValidator::Type::DEC);
    editor->setValidator(m_validator);
    m_parent = parent;
    return editor;
}

void MyTableDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const{
    //QString value = index.model()->data(index, Qt::EditRole).toString();
    qDebug()<< "editor int: " <<index.model()->data(index, Qt::EditRole).toInt();
    QString value = QString::number(index.model()->data(index, Qt::EditRole).toInt(), 16);
    QLineEdit *line = qobject_cast<QLineEdit*>(editor);
    qDebug() << Q_FUNC_INFO << "value == " << value << "column = " << index.column() << "row = " << index.row();
    line->setText(value);
}

void MyTableDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QString data = QString::number(index.model()->data(index, Qt::DisplayRole).toInt(), 16);
//    qDebug() << "data= " << data << "number=" << index.model()->data(index, Qt::DisplayRole).toInt()
//             << index.model()->data(index, Qt::DisplayRole).userType()
//             << QVariant::typeToName(index.model()->data(index, Qt::DisplayRole).userType())
//             << index.model()->data(index, Qt::DisplayRole)   ;
    if(option.state & QStyle::State_Selected){
        painter->fillRect(option.rect, option.palette.highlight());
    }

    QLabel *labelData = new QLabel();
    labelData->setText(data);
    labelData->setGeometry(option.rect);

    painter->save();
    //int yOffset = (option.rect.height() - PaintingScaleFactor) / 2;
    //painter->translate(option.rect.x(), option.rect.y() + yOffset);
    //painter->scale(PaintingScaleFactor, PaintingScaleFactor);


    //QApplication::style()->drawControl(QStyle::CE_ItemViewItem, qstyleoption_cast<const QStyleOption*>(&option), painter, labelData);
//    labelData->render(painter->device(), QPoint(option.rect.x(), option.rect.y() + yOffset),
//                    QRegion(0,0,option.rect.width(),option.rect.height()), QWidget::RenderFlag::DrawChildren);
    painter->drawText(option.rect,data);
    painter->restore();
    //QStyledItemDelegate::paint(painter, option, index);
}

//void MyTableDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
//{

//}

void MyTableDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QLineEdit *line = static_cast<QLineEdit*>(editor);
    QString value = line->text();
    int number;
    switch(m_validator->typeState()){
        case MyValidator::ValidateType::HEX :
            number = value.toInt(nullptr, 16);
            qDebug()<< Q_FUNC_INFO << "number = " << number;
            break;
        case MyValidator::ValidateType::BIN :
            number = value.toInt(nullptr, 2);
            break;
        case MyValidator::ValidateType::DEC :
            number = value.toInt(nullptr, 10);
            break;
        case MyValidator::ValidateType::OCT :
            number = value.toInt(nullptr, 8);
            break;
        case MyValidator::ValidateType::ASCII :
            number = value[0].toLatin1();      //ascii format allow only string with length <=1. Convert first char of string to ascii.
            break;
        default:
            break;
    }
    model->setData(index,number);
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

void MyTableDelegate::setHexValidate(){
    m_validator->setTypeState(MyValidator::ValidateType::HEX);
}

void MyTableDelegate::setDecValidate(){
    m_validator->setTypeState(MyValidator::ValidateType::DEC);
}

void MyTableDelegate::setOctValidate(){
    m_validator->setTypeState(MyValidator::ValidateType::OCT);
}

void MyTableDelegate::setBinValidate(){
    m_validator->setTypeState(MyValidator::ValidateType::BIN);
}

void MyTableDelegate::setAsciiValidate(){
    m_validator->setTypeState(MyValidator::ValidateType::ASCII);
}




















