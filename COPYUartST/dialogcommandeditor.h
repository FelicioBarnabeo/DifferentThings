#ifndef SENDERWIDGET_H
#define SENDERWIDGET_H

#include <QDialog>

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
class StandartTableModel;
QT_END_NAMESPACE

class CommandEditor : public QDialog
{
    Q_OBJECT
public:
    static Command * showDialog(Command *cmd = nullptr, QWidget *parent = 0) ;
    explicit CommandEditor(Command * cmd = nullptr, QWidget *parent = 0);
    ~CommandEditor();
private:
    MyTableDelegate *m_delegate;
    StandartTableModel *m_tableModel;
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
    static Command * m_command;
public slots:
    void acceptMessage();
    void setCommandData(Command *cmd);
    void updateTable();
signals:
    void returnCmd(Command *command);
};

#endif // SENDERWIDGET_H
