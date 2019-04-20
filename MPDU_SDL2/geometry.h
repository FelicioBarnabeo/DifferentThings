#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "button.h"
int lengthHord(int radius, int angleSegment);
int heightSegment(int radius,int angleSegment);
Button *buttonBindCircle(int x0, int y0, int w, int h, int radius, string on, string off, int angleSegment);

class geometry
{
public:
    geometry();
};

#endif // GEOMETRY_H
