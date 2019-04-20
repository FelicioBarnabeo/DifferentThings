#ifndef EMULATORREADER_H
#define EMULATORREADER_H

#include <QList>
#include <QMap>
#include <QString>
#include "arincword.h"

namespace Ui {
class MainWindow;
}

QT_FORWARD_DECLARE_CLASS(GeoData)
QT_FORWARD_DECLARE_CLASS(MainWindow)



class EmulatorReader
{
    Q_OBJECT
private:
    QList<ArincWord> m_wordList;
    QList<GeoData*> m_geodataList;
    QByteArray m_wordBuffer;
    ArincWord m_currentWord;
public:
    EmulatorReader();

    void createBuffer();
    QByteArray getBuffer() const
    {
        return m_wordBuffer;
    }
    void updateGeodataList(Ui::MainWindow m_ui);
    void updateWordList();
    void initSpidevDevice();
public slots:
    void writeToBuffer();

};

#endif // EMULATORREADER_H
