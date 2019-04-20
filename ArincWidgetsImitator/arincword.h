#ifndef ARINCWORD_H
#define ARINCWORD_H

#include <QObject>
#include "geodata.h"


class ArincWord : public QObject
{
    Q_OBJECT
    QVector<quint8> m_currentWord;
    QString m_label;
    int m_timerWord;    
    int m_fd;
public:
    ArincWord();
    explicit ArincWord(const GeoData &word );
    ArincWord(const ArincWord &copy);
    ArincWord& operator=(const ArincWord &copy);
    ~ArincWord();

    void setTimer(const GeoData &geodata)
    {
        m_timerWord = geodata.geoLabelTimeInterval();
    }

    QString setLabelString(const GeoData &geodata)
    {
        m_label = geodata.geoLabelCode();
    }

    void setTimerWord(int rtimer)
    {
        m_timerWord = rtimer;
    }
    void setLabel(QString rlabel)
    {
        m_label = rlabel;
    }
    void setCurrentWord( QVector<quint8> rword)
    {
        m_currentWord = rword;
    }
    QString label() const
    {
        return m_label;
    }
    int timeInterval() const
    {
        return m_timerWord;
    }
    QVector<quint8> currentWord() const
    {
        return m_currentWord;
    }
    int fd() const
    {
        return m_fd;
    }

    void writeWithTimeInterval();
    void writeToBuffer();
    int writeWithInterval(QVector<quint8> word, int timer){}
    int writeWithInterval(int timer){}

    QVector<quint8> readWordFromReceive();
    quint32 grinvichTimeToValueOfWord(QTime grade);
    quint32 dateToValueOfWord(QDate grade);
    QVector<quint8> splitWordToVector(ArincCodeMessage label, int grade,
      bool sign, int matrix, bool parity, Vss vss, Reserve rsrv, NeedBits bits);
    QVector<quint8> createWord(const GeoData &geodata);
public slots:
    void sendWordToDevice();
};



#endif // ARINCWORD_H
