#ifndef SERIALPORTCONFIG_H
#define SERIALPORTCONFIG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QComboBox;
class QSpinBox;
class QPushButton;
class SerialDevice;
class IOSerialManager;
QT_END_NAMESPACE

class SerialPortConfig: public QDialog
{
    Q_OBJECT
public:

public slots:
    static void openDialog(QWidget *parent = Q_NULLPTR);
    void acceptData();
private:
    IOSerialManager *m_mngr;
    SerialPortConfig(QWidget *parent = 0);
    ~SerialPortConfig();
    QLabel        *m_serialPortLabel;
    QComboBox     *m_serialPortComboBox;
    QLabel        *m_readPortLabel;
    QComboBox     *m_readPortComboBox;
    QLabel        *m_dataBitsLabel;
    QComboBox     *m_dataBitsComboBox;
    QLabel        *m_stopBitsLabel;
    QComboBox     *m_stopBitsComboBox;
    QLabel        *m_baudRateLabel;
    QComboBox     *m_baudRateComboBox;
    QLabel        *m_parityBitLabel;
    QComboBox     *m_parityComboBox;
    QPushButton   *m_okButton;
    QPushButton   *m_cancelButton;
};

#endif // SERIALPORTCONFIG_H
