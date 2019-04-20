#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "geodata.h"
#include <QList>
#include <QMap>
#include "consolewidget.h"
#include <QDebug>
#include <QDataStream>
#include <QLayoutItem>
#include <QTableWidget>
#include "arincword.h"
#include "emulatorreader.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    friend class EmulatorReader;
    QTableWidget *table;
    EmulatorReader *model;
    QString currentFile;
    Ui::MainWindow *ui;
    Console *console;
    int fd;
    bool saveFile(const QString &filename);
    bool loadFile(const QString &filename);


public:
    explicit MainWindow(QWidget *parent = 0);
    auto  getUi(){
        return ui;
    }
    //void setCurrentFile(const QString &filename);
    ~MainWindow();
    //friend QDataStream & operator<<(QDataStream & out, const QMap<QString,GeoData*> data);
    //friend QDataStream & operator>>(QDataStream & in, QMap<QString,GeoData*> data);
private slots:
    void on_pushButton_clicked();
//    bool save();
//    bool saveAs();
//    bool open();
signals:
    void print_word(QString label, QString word);
    void closeTransmit();

};

#endif // MAINWINDOW_H
