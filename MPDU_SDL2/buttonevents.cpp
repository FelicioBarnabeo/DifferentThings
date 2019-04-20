#include "buttonevents.h"

extern Application app;

void callclick(){
    app.window()->toPage("call");
}

void resetclick(){
    app.window()->toParrent();
}

void homeclick(){
    app.window()->toPage("home");
}

void lightsclick(){
    app.window()->toPage("lights");
}

void shadesclick(){
    app.window()->toPage("shades");
}

void boardclick(){
    app.window()->toPage("open_close");
}

void irsclick(){
    app.window()->toPage("irs");
}

void mmsclick(){
    app.window()->toPage("mms");
}

void avuclick(){
    app.window()->toPage("avu");
}

void dvdclick(){
    app.window()->toPage("dvd");
}

void ruengclick(){
    app.changeLanguage();
//    for(auto i=app.window()->pagesBuffer().begin();i<app.window()->pagesBuffer().end();i++)
//    {
//        for(auto var : (*i).second->elements())
//            var->set
//    }
}

ButtonEvents::ButtonEvents()
{

}

ButtonEvents::~ButtonEvents()
{

}

