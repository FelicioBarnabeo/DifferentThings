#include "mainwindow.h"
//#include "ui_mainwindow.h"
#include "QMainWindow"
#include <QtWidgets>
#include <QAction>
#include <QFileDialog>
#include <QMenuBar>
#include "adddialog.h"
#include "pluginiowindow.h"

MainWindow::MainWindow()
{
    createMenus();
    setWindowTitle(tr("SerialCon"));
    createBar();
    pluginIOWindow = new PluginIOWindow;
    setCentralWidget(pluginIOWindow);
}

//openAct = new QAction(tr("&Open..."), this);
//fileMenu->addAction(openAct);
//connect(openAct, &QAction::triggered, this, &MainWindow::openFile);

void MainWindow::createMenus(){
    fileMenu = menuBar()->addMenu(tr("&Порт"));
    openAct = new QAction(tr("&Настроить порт"),this);
    fileMenu->addAction(openAct);
    connect(openAct, &QAction::triggered, this, &MainWindow::openPort);
    //sendMenu = menuBar()->addMenu(tr("&Отправить"));
    //fileMenu->addAction(newAct);
    //fileMenu->addAction(openAct);
    //fileMenu->addAction(saveAct);
}

void MainWindow::createBar(){
    fileToolBar = addToolBar(tr("Plugins"));
    QAction *hex   = new QAction(tr("Hex"));
    QAction *bin   = new QAction(tr("Bin"));
    QAction *dec   = new QAction(tr("Dec"));
    QAction *oct   = new QAction(tr("Oct"));
    QAction *ascii = new QAction(tr("ASCII"));
    fileToolBar->addAction(hex);
    fileToolBar->addAction(bin);
    fileToolBar->addAction(dec);
    fileToolBar->addAction(oct);
    fileToolBar->addAction(ascii);
}

void MainWindow::openPort(){
    AddDialog portDialog;
    if(portDialog.exec()){

    }
}


MainWindow::~MainWindow()
{

}
