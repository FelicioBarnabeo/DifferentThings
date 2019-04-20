#ifndef SENDERWIDGET_H
#define SENDERWIDGET_H

#include <QTableWidget>

QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
class QSpinBox;
class QGroupBox;
class QRadioButton;
class QLineEdit;
class QTableView;
class MyTableDelegate;
class Command;
QT_END_NAMESPACE

class SenderWidget : public QTabWidget
{
    Q_OBJECT
public:
    SenderWidget(QWidget *parent = 0);
private:
    //PluginIOWindow *newAddressTab;
    MyTableDelegate *m_delegate;
    QGroupBox*    m_sendGroup;
    QLabel*       m_nameLabel;
    QLabel*       m_dataLabel;
    QLabel*       m_intervalLabel;
    QLineEdit*    m_nameEdit;
    QTableView*   m_messageTable;
    QSpinBox*     m_intervalBox;
    QPushButton*  m_okButton;
    QPushButton*  m_cancelButton;

    QRadioButton *m_hexButton;
    QRadioButton *m_decButton;
    QRadioButton *m_octButton;
    QRadioButton *m_binButton;
    QRadioButton *m_asciiButton;
public slots:
    void acceptMessage();
signals:
    void addMessage(Command *command);
};

#endif // SENDERWIDGET_H
