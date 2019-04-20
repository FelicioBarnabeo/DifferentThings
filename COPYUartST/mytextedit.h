#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H
#include <QTextEdit>
#include <QObject>
#include "myvalidator.h"
#include <QObject>

class MyValidator;

class MyTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    MyTextEdit(QWidget *parent = Q_NULLPTR);
    virtual void contextMenuEvent(QContextMenuEvent *event);
    void wrBytesToShow(const QByteArray &msg);
    void rBytesToShow(const QByteArray &msg);
    void write(QJsonObject &json) const;
    void read(QJsonObject &json);
    void clearAll();
    ~MyTextEdit();
public slots:
    void setValidatorType(MyValidator::ValidateType type);
private:
    struct Node{
        QString datetime;
        QByteArray msg;
        enum {READ, WRITE} status;
    };
    QList<Node> m_ioMsgArray;
    MyValidator *m_validator;
    QString validMsgToShow(QByteArray msg);
    void repaintIOView();
signals:
    void changeValidator();
};

#endif // MYTEXTEDIT_H
