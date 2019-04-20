#ifndef CentralWidget_H
#define CentralWidget_H

#include <QWidget>
#include "myvalidator.h"

QT_BEGIN_NAMESPACE
class QHBoxLayout;
class QVBoxLayout;
class CommandWidget;
class MyTextEdit;
class IOSerialManager;
QT_END_NAMESPACE

class CentralWidget : public QWidget
{
    Q_OBJECT
public:
    CentralWidget(QWidget *parent = 0);
    ~CentralWidget();
    void write(QJsonObject &json) const;
    void read(QJsonObject &json);
public slots:
    void setValidator(MyValidator::ValidateType type);
    void clearAll();
private:
    MyTextEdit * m_messageViewer;
    CommandWidget *m_cmdWidget;
    IOSerialManager *m_ioMngr;
    QHBoxLayout *m_mainLayout;
    QVBoxLayout *m_subMainLayout;
    QVBoxLayout *m_sub2mainLayout;
};

#endif // CentralWidget_H
