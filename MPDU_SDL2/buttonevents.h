#ifndef BUTTONEVENTS_H
#define BUTTONEVENTS_H

#include "application.h"

void callclick();
void resetclick();
void homeclick();
void lightsclick();
void shadesclick();
void boardclick();
void irsclick();
void mmsclick();
void avuclick();
void dvdclick();
void ruengclick();

class ButtonEvents
{
public:
    ButtonEvents();
    ~ButtonEvents();
};

#endif // BUTTONEVENTS_H
