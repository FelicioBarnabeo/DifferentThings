#include "colordefiner.h"
#include <QDebug>
#include <QtMath>
#include <QFile>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <QTime>
ColorDefiner::ColorDefiner(QString img,int scalex, int scaley)
{
    qDebug()<<m_image.load(img);
    qDebug()<<m_image.width()<<m_image.height();
    m_image = m_image.scaled(scalex,scaley);
    qDebug()<<m_image.width()<<m_image.height();
    m_rad = m_image.width()/2;
    setCenter(QPoint(scalex/2,scaley/2)); //cx == cy if image circle all square sides equal
    m_file.setFileName("color_map.txt");
    if(!m_file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"Cant open file ";
        return;
    }
}

int ColorDefiner::getAngleByCoordinates(int x, int y, int x0, int y0)
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

QString ColorDefiner::getColor(int x,int y)
{
    QRgb color = m_image.pixel(x,y);
    //qDebug()<<x<<y<<qRed(color)<<qGreen(color)<<qBlue(color);
    return (QColor(color).name());
}

int ColorDefiner::oddAngle(float angle)
{
    return static_cast<int>(angle)>>1<<1;
}

QString ColorDefiner::getColorValue(QString name,int procent){
    //qDebug()<<"name: "<<name<<" procent = "<<procent;
    QColor tmp(name);
    float value,saturation;
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
    //qDebug()<<"Hue:" << tmp.hue()<<" Sat:"<<tmp.saturation()<<" Value:"<<tmp.value();
    return tmp.name();
}


QString ColorDefiner::getColorByRadians(double angle)
{
    //qDebug() << " angle = "<<angle;
    int x = m_rad+cos(angle)*(m_rad-1) ;
    int y = m_rad-sin(angle)*(m_rad-1) ;
    QRgb color = m_image.pixel(x,y);
    //qDebug()<<x<<y<<qRed(color)<<qGreen(color)<<qBlue(color);
    return (QColor(color).name());
}

QString ColorDefiner::getColorByDegrees(int angle)
{
    double radians = qDegreesToRadians(double(angle));
    //return getColorByRadians(radians);
    //qDebug()<< " ang:" << angle;
    //qDebug()<< " angle = "<<angle;
    double x = round(m_center.x()+cos(radians)*(m_rad-1)) ;  //round need 100%
    double y = round(m_center.y()-sin(radians)*(m_rad-1)) ;
    QRgb color = m_image.pixel(x,y);
    //qDebug()<<m_center.x()<<" "<<(m_rad-1)<<" "<<cos(radians);
    //qDebug()<<x<<y<<qRed(color)<<qGreen(color)<<qBlue(color);
    return (QColor(color).name());
}

void ColorDefiner::setRndPoint(QPoint rndPoint)
{
    if (m_rndPoint == rndPoint)
        return;

    m_rndPoint = rndPoint;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    emit rndPointChanged(m_rndPoint);
    QCoreApplication::processEvents();
    //usleep(100000);

}

void ColorDefiner::setRndPoint2(QPoint rndPoint2)
{
    if (m_rndPoint2 == rndPoint2)
        return;

    m_rndPoint2 = rndPoint2;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    emit rndPoint2Changed(m_rndPoint2);
    QCoreApplication::processEvents();
}

void ColorDefiner::randomizePoint(){
    qDebug()<<Q_FUNC_INFO;
    int x,y,a,b;
    for(int i=0; i<1600; i++){
        srand(i);
        x = qrand() % 320;
        y = qrand() % 240;
        a = qrand() % 140 + 85;
        b = qrand() % 240;
        setRndPoint(QPoint(x,y));
        setRndPoint2(QPoint(a,b));
        //qDebug()<<"x = "<<x<<" y= "<<y;
    }
}

bool ColorDefiner::findColor(QString clr)
{
//    QFile file;
//    file.setFileName("color_map.txt");
//    if(!file.open(QIODevice::ReadOnly))
//    {
//        qDebug()<<"Cant open file ";
//        return false;
//    }
    m_file.seek(0);
    QTextStream in(&m_file);
    QString line;
    bool res = false;
    while(in.readLineInto(&line)){
        //qDebug()<<"line = "<<line;
        if(line.contains(clr)){
            res = true;
        }
    }
    if(res)
        qDebug()<<"FINDED"<<clr;
    else qDebug()<<"NOT FINDED"<<clr;
    return res;
}

void ColorDefiner::makeColorWheelMapFile(int degreesStep, int lightStep){
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
    for(int angle = 0; angle<360; angle+=degreesStep){
        for(int currentLight=0; currentLight<=90;currentLight+=lightStep){
            colorname = getColorByDegrees(angle);
            qDebug()<<"colorname = "<<colorname;
            colorname = getColorValue(colorname,currentLight);
            qDebug()<<"color after light = "<<colorname;
            out << " \t\t" <<"KEY_"+colorname<<"\t"<<colorname<<'\n';
        }
    }
    out<<"end codes"<<endl;
}


