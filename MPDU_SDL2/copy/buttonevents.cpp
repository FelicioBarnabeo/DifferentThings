#include "buttonevents.h"

extern Application app;

void callclick(){
    app.window()->toPage("call");
}

void resetclick(){
    app.window()->toPage("home");
}

void homeclick(){
    app.window()->toPage("home");
}

ButtonEvents::ButtonEvents()
{

}

ButtonEvents::~ButtonEvents()
{

}

