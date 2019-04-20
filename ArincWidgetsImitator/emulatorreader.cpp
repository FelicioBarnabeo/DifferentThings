#include "emulatorreader.h"
#include <mainwindow.h>
#include <QTimer>
#include <geodata.h>
#include <QObject>

EmulatorReader::EmulatorReader()
{

}

void EmulatorReader::initSpidevDevice()
{
//    fd = open_device("/dev/spidev32766.0");
//    set_spi_config(fd);

//    /* software reset */
//    write_bit(fd,0x44,NULL,0);

//    // write aclk to 4Mhz
//    m_uint8_t mas[] = {0x04};
//    write_bit(fd,0x38,mas,1);

//    /*  write transmit control register RATE & TMODE & SELFTEST & TFLIP*/
//    mas[0] = 0x71;
//    write_bit(fd,0x08, mas, 1);
//    /* write receiver1 control register set RFLIP and RATE */
//    mas[0] = 0x81;
//    write_bit(fd,0x10,mas,1);
}

void EmulatorReader::createBuffer()
{
    updateWordList();
    for(auto i = m_wordList.begin(); i != m_wordList.end(); i++)
    {
        m_currentWord = *i;
        QTimer * wordtimer = new QTimer();
        QObject::connect(wordtimer, &QTimer::timeout, this, &EmulatorReader::writeToBuffer );
        wordtimer->start(m_currentWord.timeInterval());
    }
}

void EmulatorReader::writeToBuffer()
{
    QDataStream stream(&m_wordBuffer, QIODevice::WriteOnly);
    stream << m_currentWord.currentWord();
}

void EmulatorReader::updateGeodataList(Ui::MainWindow m_ui)
{
    m_geodataList.clear();

    m_geodataList.append(new GeoData(ArincCodeMessage::lng, m_ui->LongVal->text().toDouble(),
    m_ui->StatusLng->currentIndex(), m_ui->parityLng->isChecked(), m_ui->SignLng->currentIndex()));

    m_geodataList.append(new GeoData(ArincCodeMessage::lat, m_ui->LatVal->text().toDouble(),
    m_ui->StatusLat->currentIndex(), m_ui->parityLat->isChecked(), m_ui->SignLat->currentIndex()));

    m_geodataList.append(new GeoData(ArincCodeMessage::alt, m_ui->AltVal->text().toDouble(),
    m_ui->StatusAlt->currentIndex(), m_ui->parityAlt->isChecked(), m_ui->SignAlt->currentIndex()));

    m_geodataList.append(new GeoData(ArincCodeMessage::distanceToDest, m_ui->DistVal->text().toDouble(),
    m_ui->StatusDist->currentIndex(), m_ui->parityDist->isChecked()));

    m_geodataList.append(new GeoData(ArincCodeMessage::timeToDest, m_ui->TimeToDestVal->time(),
    m_ui->statusTimeToDest->currentIndex(), m_ui->parityTimeToDest->isChecked()));

    m_geodataList.append(new GeoData(ArincCodeMessage::speed, m_ui->SpeedVal->text().toDouble(),
    m_ui->StatusSpeed->currentIndex(), m_ui->paritySpeed->isChecked()));

    m_geodataList.append(new GeoData(ArincCodeMessage::grinvichTime, m_ui->TimeVal->time(),
    m_ui->StatusTime->currentIndex(), m_ui->parityTime->isChecked()));

    m_geodataList.append(new GeoData(ArincCodeMessage::temperature, m_ui->TempVal->text().toDouble(),
    m_ui->StatusTemp->currentIndex(), m_ui->parityTemp->isChecked(), m_ui->SignTemp->currentIndex()));

    m_geodataList.append(new GeoData(ArincCodeMessage::date, m_ui->DateVal->date(),
    m_ui->StatusDate->currentIndex(), m_ui->parityDate->isChecked()));
}

void EmulatorReader::updateWordList()
{
    updateGeodataList();
    for(auto i = m_geodataList.begin(); i != m_geodataList.end(); i++)
    {
        m_wordList.append(ArincWord(static_cast<Geodata>(*i));
    }
}
