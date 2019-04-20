#include "mainwindow.h"
#include <QApplication>
#include "consolewidget.h"
#include "servervss.h"
#include "emulatorreader.h"

//остановился на открытии и записи в файл значений полей
//нужно добавить работу с базой sql sql mapper
//или xml парсинг
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    EmulatorReader emulator;
    emulator.updateGeodataList(window.getUi());
    QByteArray arr = emulator.getBuffer();
    ServerVss server(quint16(2345), arr);
    window.show();
    a.setStyleSheet("QCheckBox::indicator\
    {\
        width: 23px;\
        height: 23px;\
        color: red;\
    }");
    a.setStyle("fusion");
    return a.exec();
}
