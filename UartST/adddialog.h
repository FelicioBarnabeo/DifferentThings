#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QLabel;
class QTextEdit;
class QLineEdit;
class QComboBox;
class QSpinBox;
class QPushButton;
class SerialDevice;
class QErrorMessage;
QT_END_NAMESPACE

class AddDialog:public QDialog
{
    Q_OBJECT
public:
    AddDialog(QWidget *parent = 0);
    ~AddDialog();
public slots:
    void openSerialPort();
private:
    QLabel        *serialPortLabel;
    QComboBox     *serialPortComboBox;
    QLabel        *dataBitsLabel;
    QComboBox     *dataBitsComboBox;
    QLabel        *stopBitsLabel;
    QComboBox     *stopBitsComboBox;
    QLabel        *baudRateLabel;
    QComboBox     *baudRateComboBox;
    QLabel        *parityBitLabel;
    QComboBox     *parityComboBox;
    QLabel        *intervalLabel;
    QSpinBox      *intervalSpinBox;
    QPushButton   *okButton;
    QPushButton   *cancelButton;
    QErrorMessage *portNotify;
    SerialDevice  *serial;
};

#endif // ADDDIALOG_H
