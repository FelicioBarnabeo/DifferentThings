#include "mytextedit.h"
#include <QMenu>
#include <QContextMenuEvent>
#include <QJsonObject>
#include <QJsonArray>
#include "myvalidator.h"
#include <QDebug>
#include <QDateTime>

MyTextEdit::MyTextEdit(QWidget *parent) : QTextEdit(parent), m_validator(new MyValidator())
{
    this->setReadOnly(true);
    connect(this, &MyTextEdit::changeValidator, this, &MyTextEdit::repaintIOView );
}

MyTextEdit::~MyTextEdit(){
    delete m_validator;
}

void MyTextEdit::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu *menu = createStandardContextMenu();
    QAction *clear = new QAction(tr("Очистить всё"));
    menu->addAction(clear);
    connect(clear, &QAction::triggered, this, &MyTextEdit::clearAll);
    menu->exec(event->globalPos());
    delete menu;
}

QString MyTextEdit::validMsgToShow(QByteArray msg){
    int representFormat = m_validator->formatNumber();
    QString data;

    if(m_validator->typeState() == MyValidator::ValidateType::ASCII){
        for(QChar symbol : msg){
            //qDebug()<<Q_FUNC_INFO<<"QCHAR = " << symbol;
            data.append(symbol);
            data.append("  ");
            //data = index.model()->data(index, role).toString();
        }
    }
    else{
        for(uchar i : msg){
            data += QString::number(i, representFormat)+"  ";
            qDebug()<<Q_FUNC_INFO<<"data = " << data;
        }
    }
    return data;
}

void MyTextEdit::repaintIOView()
{
    qDebug()<<Q_FUNC_INFO;
    this->clear();
    for(auto node : m_ioMsgArray){
        setTextColor(QColor("green"));
        insertPlainText(node.datetime);
        setTextColor(QColor(node.status ? "blue" : "red"));
        insertPlainText(validMsgToShow(node.msg)+"\n");
    }
}

void MyTextEdit::wrBytesToShow(const QByteArray & msg){
    setTextColor(QColor("green"));
    QString dtm = QDateTime::currentDateTimeUtc().toString("dd.MM.yyyy hh:mm:ss")+ " "+"[TX] - ";
    insertPlainText(dtm);
    m_ioMsgArray.append(Node{dtm, msg, Node::WRITE});
    setTextColor(QColor("blue"));
    insertPlainText(validMsgToShow(msg)+"\n");
}

void MyTextEdit::rBytesToShow(const QByteArray &msg){
    setTextColor(QColor("green"));
    QString dtm = QDateTime::currentDateTimeUtc().toString("dd.MM.yyyy hh:mm:ss")+ " "+"[RX] - ";
    insertPlainText(dtm);
    m_ioMsgArray.append(Node{dtm, msg, Node::READ});
    setTextColor(QColor("red"));
    insertPlainText(validMsgToShow(msg)+"\n");
}

void MyTextEdit::write(QJsonObject &json) const
{
    QJsonArray msgArray;
    for(auto node: m_ioMsgArray){
        QJsonObject tempJson;
        tempJson["Date"] = node.datetime;
        tempJson["Msg"] = QString(node.msg.toHex());
        tempJson["Status"] = node.status;
        msgArray.append(tempJson);
    }
    json["Messages"] = msgArray;
}

void MyTextEdit::read(QJsonObject &json)
{
    clearAll();
    QJsonArray array = json["Messages"].toArray();
    qDebug()<<"size = "<<array.size();
    for (int i = 0; i < array.size(); ++i){
        qDebug()<<"i = "<<i;
        QJsonObject jObj = array[i].toObject();
        Node tmp;
        tmp.datetime = jObj["Date"].toString();
        tmp.msg = QByteArray::fromHex(jObj["Msg"].toString().toLatin1());
        tmp.status =  jObj["Status"].toInt() ? Node::WRITE : Node::READ;
        m_ioMsgArray.append(tmp);
    }
    repaintIOView();
}

void MyTextEdit::clearAll()
{
    m_ioMsgArray.clear();
    this->clear();
}

void MyTextEdit::setValidatorType(MyValidator::ValidateType type)
{
    m_validator->setTypeState(type);
    emit changeValidator();
}
