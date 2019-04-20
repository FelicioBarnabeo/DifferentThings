#include "colordefiner.h"
#include <QtMath>
#include <QRgb>

ColorDefiner::ColorDefiner(QQuickItem* parent): QQuickItem(parent){

}

void ColorDefiner::loadImage(const QString img, const int scalex, const int scaley)
{
    Q_INIT_RESOURCE(qml);
    qDebug()<<m_image.load(img);
    qDebug()<<m_image.width()<<m_image.height();
    m_image = m_image.scaled(scalex,scaley);
    qDebug()<<m_image.width()<<m_image.height();
    //m_rad = m_image.width()/2;
    //setCenter(QPoint(scalex/2,scaley/2)); rad and center properties initialize from qml
}

int ColorDefiner::getAngleByCoordinates(int x, int y, int x0, int y0) const
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

QString ColorDefiner::getColor(int x, int y) const
{
    QRgb color = m_image.pixel(x,y);
    //qDebug()<<"x" << x << "y" << y << "color:"<<QColor(color).name(); //qRed(color)<<qGreen(color)<<qBlue(color);
    return (QColor(color).name());
}



int ColorDefiner::oddAngle(float angle) const
{
    return static_cast<int>(angle)>>1<<1;
}

QString ColorDefiner::getColorValue(QString name, int procent) const
{
    //qDebug()<<Q_FUNC_INFO << "name" << name <<"procent = "<<procent;
    QColor tmp(name);
    float value;
    value = (float)(2.55*(100-procent));
    tmp = tmp.fromHsv(tmp.hue(), 255, value);
//    if(procent >= 50){
//        value = (float)((procent-50)/(-50.0)+1)*255;
//        tmp = tmp.fromHsv(tmp.hue(),255,value);
//    }
//    else{
//        saturation = (float)(procent)/50*255;
//        tmp = tmp.fromHsv(tmp.hue(),saturation,255);

//    }
    //qDebug()<<tmp.hue()<<tmp.saturation()<<tmp.value();
    //qDebug();
    return tmp.name();
}

QString ColorDefiner::getColorByRadians(double angle) const
{
    //qDebug() << " angle = "<<angle;
    int x = m_center.x()+cos(angle)*(m_rad-1) ;
    int y = m_center.y()-sin(angle)*(m_rad-1) ;
    QRgb color = m_image.pixel(x,y);
    //qDebug()<<x<<y<<qRed(color)<<qGreen(color)<<qBlue(color);
    return (QColor(color).name());
}
QString ColorDefiner::getColorByDegrees(int angle) const
{
    double radians = qDegreesToRadians(double(angle));
    //qDebug()<<"radians == "<<radians;
    double x = round(m_center.x()+cos(radians)*(m_rad-1)) ;  //round need 100%
    double y = round(m_center.y()-sin(radians)*(m_rad-1)) ;
    QRgb color = m_image.pixel(x,y);
    //qDebug()<<x<<y<<qRed(color)<<qGreen(color)<<qBlue(color);
    //qDebug()<<m_center.x()<<" "<<(m_rad-1)<<" "<<cos(radians);
    //qDebug()<< Q_FUNC_INFO << "x=" << x << " y=" << y << " angle = "<<angle << " color ="<<QColor(color).name();
    //qDebug();
    return (QColor(color).name());
}

void ColorDefiner::makeColorWheelMap(int degreesStep, int lightStep) const
{
    if(degreesStep == 0)
    {
        qDebug()<<"Degrees step must be greater than zero!";
        return;
    }
    QString filename = "color_map.txt";
    QFile file(filename);
    if(!file.open(QIODevice::ReadWrite))
    {
        qDebug()<<"Cant open file "<<filename;
        return;
    }
    QTextStream out(&file);
    out<<"begin codes"<<endl;
    QString colorname;
    int count = 0 ;
    for(int angle = 0; angle<360; angle+=degreesStep){
        for(int currentLight=0; currentLight<=90; currentLight+=lightStep){
            colorname = getColorByDegrees(angle);
            colorname = getColorValue(colorname,currentLight);
            out << " \t\t" <<"KEY_"+colorname<<"\t"<<colorname<<'\n';
            //out << " \t\t" << count << " " << angle << " "<<currentLight<<" "<<colorname<<'\n';
            count++;
        }
    }
    out<<"end codes"<<endl;
}
