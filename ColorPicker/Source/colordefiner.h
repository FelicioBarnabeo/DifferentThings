#ifndef COLORDEFINER_H
#define COLORDEFINER_H
#include <QObject>
#include <QImage>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <QCoreApplication>
#include <QFile>

class ColorDefiner: public QObject {
    Q_OBJECT
    Q_PROPERTY(int rad READ rad CONSTANT)
    Q_PROPERTY(QPoint center READ center CONSTANT)
    Q_PROPERTY(QPoint rndPoint READ rndPoint WRITE setRndPoint NOTIFY rndPointChanged)
    Q_PROPERTY(QPoint rndPoint2 READ rndPoint2 WRITE setRndPoint2 NOTIFY rndPoint2Changed)
public:
    ColorDefiner(QObject* parent =0): QObject(parent){}
    ColorDefiner(QString img,int scalex, int scaley);

    int rad() const
    {
        return m_rad;
    }

    QPoint center() const
    {
        return m_center;
    }

    QPoint rndPoint() const
    {
        return m_rndPoint;
    }

    QPoint rndPoint2() const
    {
        return m_rndPoint2;
    }

public slots:
    int getAngleByCoordinates(int x, int y, int x0, int y0);
    int oddAngle(float angle);
    QString getColor(int x,int y);
    QString getColorByRadians(double angle);
    QString getColorByDegrees(int angle);

    void randomizePoint();
    bool findColor(QString clr);

    void makeColorWheelMapFile(int degreesStep=2, int lightStep=10);

    QString getColorValue(QString name,int procent);
    void setRad(int rad)
    {
        m_rad = rad;
    }
    void setCenter(QPoint center)
    {
        m_center = center;
    }
    void setRndPoint(QPoint rndPoint);
    void setRndPoint2(QPoint rndPoint2);

signals:
    void rndPointChanged(QPoint rndPoint);
    void rndPoint2Changed(QPoint rndPoint2);

private:
    QImage m_image;
    int m_rad;
    QPoint m_center;
    QPoint m_rndPoint;
    QPoint m_rndPoint2;
    QFile m_file;
};


#endif // COLORDEFINER_H
