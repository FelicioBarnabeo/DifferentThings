#ifndef COLORDEFINER_H
#define COLORDEFINER_H

#include <QObject>
#include <QImage>
#include <QRgb>
#include <QDebug>
#include <QColor>
#include "math.h"
#include <QtMath>
#include <QFile>
#include <QTextStream>

class ColorDefiner: public QObject {
    Q_OBJECT

    QImage m_image;
public:
    ColorDefiner(QObject* parent =0): QObject(parent){}
    ColorDefiner(QString img,int scalex, int scaley, QObject* parent =0): QObject(parent)
    {
        qDebug()<<m_image.load(img);
        qDebug()<<m_image.width()<<m_image.height();
        m_image = m_image.scaled(scalex,scaley);
        qDebug()<<m_image.width()<<m_image.height();
    }

public slots:
    int getAngleByCoordinates(int x, int y, int x0, int y0)
    {
        int xx = x-x0;
        int yy = y0-y;
        float angle = (xx || yy) ? atan2(yy,xx) : 0;
        //qDebug()<<"cpp angle = "<<angle;
        if(angle < M_PI /-2)
            angle = angle + 2*M_PI;
        float degrees = qRadiansToDegrees(angle);
        //qDebug()<<"cpp degrees = "<<degrees;
        return degrees;
    }
    int oddAngle(float angle){
        return static_cast<int>(angle)>>1<<1;
    }

    QString getColor(int x,int y)
    {
        QRgb color = m_image.pixel(x,y);
        //qDebug()<<x<<y<<qRed(color)<<qGreen(color)<<qBlue(color);
        return (QColor(color).name());
    }
    QString getColorByRadians(double radius, double angle)
    {
        //qDebug() << " angle = "<<angle;
        int x = radius+cos(angle)*radius ;
        int y = radius-sin(angle)*radius ;
        QRgb color = m_image.pixel(x,y);
        //qDebug()<<x<<y<<qRed(color)<<qGreen(color)<<qBlue(color);
        return (QColor(color).name());
    }
    QString getColorByDegrees(int centerx, int centery, double radius, int angle)
    {
        double radians = qDegreesToRadians(double(angle));
        //qDebug()<< " angle = "<<angle;
        double x = round(centerx+cos(radians)*radius) ;  //round need 100%
        double y = round(centery-sin(radians)*radius) ;
        QRgb color = m_image.pixel(x,y);
        //qDebug()<<x<<y<<qRed(color)<<qGreen(color)<<qBlue(color);
        return (QColor(color).name());
    }

    void makeColorWheelMap(double radius, int degreesStep=1, int lightStep=1){
        if(degreesStep == 0)
        {
            //qDebug()<<"Degrees step must be greater than zero!";
            return;
        }
        int centerx = radius;
        int centery = radius;
        QString filename = "color_map.txt";
        QFile file(filename);
        if(!file.open(QIODevice::ReadWrite))
        {
            //qDebug()<<"Cant open file "<<filename;
            return;
        }
        QTextStream out(&file);
        out<<"begin codes"<<endl;
        QString colorname;
        for(int angle = 0; angle<360; angle+=degreesStep){
            for(int currentLight=10; currentLight<=90; currentLight+=lightStep){
                colorname = getColorByDegrees(centerx, centery, radius, angle);
                colorname = getColorValue(colorname,currentLight);
                out << " \t\t" <<"KEY_"+colorname<<"\t"<<colorname<<'\n';
            }
        }
        out<<"end codes"<<endl;
    }

    QString getColorValue(QString name,int procent){
        //qDebug()<<"procent = "<<procent;
        QColor tmp(name);
        float value;//,saturation;
        value = (float)(2.55*(100-procent));
        tmp = tmp.fromHsv(tmp.hue(), 255, value);
//        if(procent >= 50){
//            value = (float)((procent-50)/(-50.0)+1)*255;
//            tmp = tmp.fromHsv(tmp.hue(),255,value);
//        }
//        else{
//            saturation = (float)(procent)/50*255;
//            tmp = tmp.fromHsv(tmp.hue(),saturation,255);

//        }
        //qDebug()<<tmp.hue()<<tmp.saturation()<<tmp.value();
        return tmp.name();
    }
};


#endif // COLORDEFINER_H
