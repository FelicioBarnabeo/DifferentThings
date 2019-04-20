#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "spidriver.h"
#include <QString>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QtSql/QSqlDatabase>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new EmulatorReader;
    model->updateGeodataList(ui);
    //initSpidevDevice();
    console = new Console(this);
    console->setFocus();
    console->resize(600,200);
    console->move(10,600);
    connect(this,SIGNAL(print_word(QString,QString)),console,SLOT(output(QString,QString)));
    connect(ui->fileSave,SIGNAL(triggered()),this,SLOT(save()));
    connect(ui->openFile,SIGNAL(triggered()),this,SLOT(open()));
    connect(ui->fileSaveAs,SIGNAL(triggered()),this,SLOT(saveAs()));

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("ms31");
    db.setDatabaseName("vss_db");
    db.setUserName("tsaruev");
    db.setPassword("alfa");
    bool ok = db.open();
}


//bool MainWindow::open()
//{
//    QString filename = QFileDialog::getOpenFileName(this);
//    loadFile(filename);
//}

//bool MainWindow::save()
//{
//    //updateRowMap();
//    if(currentFile.isEmpty())
//        return saveAs();
//    else
//        saveFile(currentFile);
//}

//bool MainWindow::saveAs()
//{
//    QFileDialog dialog(this);
//    dialog.setWindowModality(Qt::WindowModal);
//    dialog.setAcceptMode(QFileDialog::AcceptSave);
//    QStringList files;
//    if(dialog.exec())
//        files = dialog.selectedFiles();
//    else
//        return false;
//    currentFile = files.at(0);
//    return saveFile(files.at(0));
//}

//bool MainWindow::saveFile(const QString &filename)
//{

//    QFile file(filename);
//    if(!file.open(QIODevice::WriteOnly))
//    {
//        QMessageBox::warning(this,tr("Application"),
//                             tr("Cannot write file %1:\n%2.")
//                             .arg(filename)
//                             .arg(file.errorString()));
//        return false;
//    }
//    QDataStream out(&file);
//    //QMapIterator<QString,GeoData*> i(rowMap);
//    while(i.hasNext())
//    {
//        i.next();
//        out << i.key() << *(i.value());
//    }

//    file.close();
//}

//bool MainWindow::loadFile(const QString &filename)
//{
//    QFile file(filename);
//    if(!file.open(QIODevice::ReadOnly))
//    {
//        QMessageBox::warning(this,tr("Application"),
//                             tr("cannot open file %1:\n%2.")
//                             .arg(filename)
//                             .arg(file.errorString()));
//    return false;
//    }
//    QDataStream in(&file);
//    //QMap<QString,GeoData*> fileRowMap;
//    while(!in.atEnd())
//    {
//        QString key;
//        in>>key;
//        GeoData value;
//        in>>value;
//        delete rowMap[key];
//        rowMap.insert(key,new GeoData(value));
//    }
////    in >> fileRowMap;
//    QMapIterator<QString,GeoData*> i(rowMap);
//    while(i.hasNext())
//    {
//        i.next();
//        qDebug() << "\n key: " << i.key() << "value: "<< *(i.value());
//    }
//}

//void MainWindow::setCurrentFile(const QString &filename)
//{
//    currentFile = filename;
//}

MainWindow::~MainWindow()
{
}



void MainWindow::on_pushButton_clicked()
{
    model->createBuffer();
    console->clear();


}

//QString label = (*(i.value())).geoLabelCode();
//int timeMs = (*(i.value())).geoLabelTimeInterval();
        /* read receiver1 +++++++++++++buffer FIFO */
        // Нужно подключить приложение arincapi и запустить его
        // Оно сразу начинает считывать буфер FIFO
        // и отправляем на консоль в 16ричном виде

//        QVector<quint8> bufferWord(4);
//        read_bit(fd, 0xA0,bufferWord.data(), 4);
//        QString receiveWord;
//        QString a;
//        for(quint8 var : bufferWord)
//        {
//            receiveWord.append(a.setNum(var,16));
//        }
//        printf("%s : %s\n",label.toStdString().c_str(),receiveWord.toStdString().c_str());
//        qDebug()<< label << " : " << receiveWord;
//        emit print_word(label,receiveWord);

    /* software reset */
    //write_bit(fd,0x44,NULL,0);

    //emit closeTransmit();

