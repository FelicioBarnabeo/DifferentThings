#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myvalidator.h"
#include <QJsonObject>

class IOSerialManager;
class CentralWidget;
class Command;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow();
    ~MainWindow();
    void write(QJsonObject &json) const;
    void read(QJsonObject &json);
public slots:
    void setHex()  {m_validType = MyValidator::ValidateType::HEX;   changeValidate(MyValidator::ValidateType::HEX);}
    void setDec()  {m_validType = MyValidator::ValidateType::DEC;   changeValidate(MyValidator::ValidateType::DEC);}
    void setBin()  {m_validType = MyValidator::ValidateType::BIN;   changeValidate(MyValidator::ValidateType::BIN);}
    void setOct()  {m_validType = MyValidator::ValidateType::OCT;   changeValidate(MyValidator::ValidateType::OCT);}
    void setAscii(){m_validType = MyValidator::ValidateType::ASCII; changeValidate(MyValidator::ValidateType::ASCII);}

private:
    CentralWidget *m_centralWidget;
    void createMenus();
    void createBar();
    QMenu *m_fileMenu;
    QMenu *m_portConfigMenu;
    QMenu *m_filterMenu;
    QToolBar *m_fileToolBar;
    QAction *m_configAct;
    QAction *m_loadPrjAct;
    QAction *m_savePrjAct;
    MyValidator::ValidateType m_validType;
    enum SaveFormat {
        Json, Binary
    };

private slots:
    void openPort();
    bool saveProject();
    bool newProject();
    bool loadProject();
signals:
    void changeValidate(MyValidator::ValidateType);

};

#endif // MAINWINDOW_H
