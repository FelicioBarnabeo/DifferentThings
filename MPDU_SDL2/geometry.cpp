#include "geometry.h"
#include <math.h>
#include <iostream>

int lengthHord(int radius, int angleSegment)
{
    double rad_angle = M_PI*angleSegment/180;
    return 2*radius*sin(rad_angle/2);  //round double to int
}

int heightSegment(int radius,int angleSegment)
{
    double rad_angle = M_PI*angleSegment/180;
    return radius*(1-cos(rad_angle/2)); //round to int
}

Button* buttonBindCircle(int x0, int y0,int w, int h, int radius,
           std::string on, std::string off, int angleSegment){
    int lHord = lengthHord(radius,angleSegment);
    int hSegment = heightSegment(radius,angleSegment);
    double half_rad_angle = M_PI*(angleSegment/2)/180;
    double rad_angle = M_PI*angleSegment/180;
    int xlHord = x0-(radius-hSegment)*cos(half_rad_angle);
    int ylHord = y0-(radius-hSegment)*sin(half_rad_angle);
    int xd = (lHord/2)*cos(rad_angle);
    int yd = (lHord/2)*sin(rad_angle);
    xlHord-=xd;
    ylHord-=yd;

    std::cout<<"xlHord = "<<xlHord << " ylHord = "<<ylHord<< std::endl;
    Button * button = new Button(xlHord,ylHord,w,h,on,off);
    return button;
}


geometry::geometry()
{

}
