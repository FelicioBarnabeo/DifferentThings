#include "mainwindow.h"
#include "QMainWindow"
#include <QtWidgets>
#include <QAction>
#include <QFileDialog>
#include <QMenuBar>
#include "dialogserialportconfig.h"
#include "centralwidget.h"
#include "ioserialmanager.h"
#include "command.h"
#include "myvalidator.h"
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>

MainWindow::MainWindow()
{
    m_centralWidget = new CentralWidget(this);
    createMenus();
    setWindowTitle(tr("SerialCon"));
    createBar();
    setCentralWidget(m_centralWidget);
    connect(this,&MainWindow::changeValidate,m_centralWidget,&CentralWidget::setValidator);

}

MainWindow::~MainWindow()
{
    delete m_centralWidget;
}

void MainWindow::createMenus()
{
    m_fileMenu = menuBar()->addMenu(tr("&Файл"));
    m_loadPrjAct = new QAction(tr("Открыть проект"),this);
    m_savePrjAct = new QAction(tr("&Сохранить проект"),this);
    m_fileMenu->addAction(m_loadPrjAct);
    m_fileMenu->addAction(m_savePrjAct);

    connect(m_loadPrjAct,&QAction::triggered, this, &MainWindow::loadProject);
    connect(m_savePrjAct, &QAction::triggered, this, &MainWindow::saveProject);

    m_portConfigMenu = menuBar()->addMenu(tr("&Порт"));
    m_configAct = new QAction(tr("&Настроить порт"),this);
    m_portConfigMenu->addAction(m_configAct);
    connect(m_configAct, &QAction::triggered, this, &MainWindow::openPort);
}

bool MainWindow::saveProject()
{
    QFile saveFile;
    saveFile.setFileName(QFileDialog::getSaveFileName(this,tr("Сохранить проект"),"",tr("Files (*.dat *.json")));
    qDebug()<<saveFile.fileName();

    if (!saveFile.open(QIODevice::WriteOnly)) {
      qWarning("Couldn't open save file.");
      return false;
    }

    QJsonObject projectObject;
    write(projectObject);
    QJsonDocument saveDoc(projectObject);
    saveFile.write(saveDoc.toJson());
    return true;
}

bool MainWindow::loadProject()
{
    QFile loadFile;
    loadFile.setFileName(QFileDialog::getOpenFileName(this,tr("Открыть проект"),"",tr("Files (*.dat *.json")));
    qDebug()<<loadFile.fileName();

    if (!loadFile.open(QIODevice::ReadOnly)) {
      qWarning("Couldn't open file.");
      return false;
    }
    QByteArray loadData = loadFile.readAll();
    QJsonDocument loadDoc = QJsonDocument::fromJson(loadData);
    QJsonObject obj = loadDoc.object();
    read(obj);
    return true;
}

void MainWindow::write(QJsonObject &json) const
{
    QJsonObject jsonObject;
    m_centralWidget->write(jsonObject);
    json["IOMSG"] = jsonObject;
}

void MainWindow::read(QJsonObject &json)
{
    QJsonObject obj = json["IOMSG"].toObject();
    m_centralWidget->read(obj);
}



bool MainWindow::newProject()
{
    return true;
}

void MainWindow::createBar()
{
    m_fileToolBar = addToolBar(tr("Plugins"));
    QAction *hex   = new QAction(tr("Hex"),this);
    QAction *bin   = new QAction(tr("Bin"),this);
    QAction *dec   = new QAction(tr("Dec"),this);
    QAction *oct   = new QAction(tr("Oct"),this);
    QAction *ascii = new QAction(tr("ASCII"),this);
    m_fileToolBar->addAction(hex);
    m_fileToolBar->addAction(bin);
    m_fileToolBar->addAction(dec);
    m_fileToolBar->addAction(oct);
    m_fileToolBar->addAction(ascii);
    connect(hex,  &QAction::triggered, this, &MainWindow::setHex);
    connect(bin,  &QAction::triggered, this, &MainWindow::setBin);
    connect(dec,  &QAction::triggered, this, &MainWindow::setDec);
    connect(oct,  &QAction::triggered, this, &MainWindow::setOct);
    connect(ascii,&QAction::triggered, this, &MainWindow::setAscii);
}

void MainWindow::openPort()
{
    SerialPortConfig::openDialog(this);
}
