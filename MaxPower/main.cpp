#include "maxpower.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("MaxPower [ver 1.8]");
    MaxPower w;
    w.show();

    return a.exec();
}
