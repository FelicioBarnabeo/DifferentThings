#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "button.h"
#include "texturemngr.h"
#include "page.h"
#include "application.h"
#include "buttonevents.h"

using namespace std;

Application app;

int main()
{      
    app.createWindow("MPDU",0,0,240,320);

    Page pageHome("home");
    Element background(0,0,240,320,"background");
    Element topPanel(0,0,240,15,"topPanel");
    Element home_picture(0,0,30,15,"home_picture");

    Button call(20,20,200,45,"call","call_on");
    //Внимание , вопрос знатоку, как сделать callback , чтоб возможно было
    //использовать public указатель на функцию как определение функции,сам не понял
    call.onClick = callclick;
    Button lights(20,70,200,45,"lights","lights_on");
    Button shades(20,120,200,45,"shades","shades_on");
    Button irs(20,170,200,45,"irs","irs_on");
    Button rueng(60,220,120,35,"rueng","rueng_on");

    Button reset(0,290,70,30,"reset","reset");
    reset.onClick = resetclick;
    Button home_button(170,290,70,30,"home_button","home_button");
    home_button.onClick = homeclick;
    Element panel1(68,293,102,27,"panel1");

    pageHome.addElement(&background);
    pageHome.addElement(&topPanel);
    pageHome.addElement(&home_picture);

    pageHome.addElement(&call);
    pageHome.addElement(&lights);
    pageHome.addElement(&shades);
    pageHome.addElement(&irs);
    pageHome.addElement(&rueng);

    pageHome.addElement(&reset);
    pageHome.addElement(&home_button);
    pageHome.addElement(&panel1);

    app.window()->addPage(pageHome);
    app.window()->setCurrentPage("home");

    Page pageCall("call");
    Button call_adjutant(40,20,160,100,"call_adjutant","call_adjutant_on");
    Button call_attendant(40,130,160,100,"call_attendant","call_attendant_on");
    pageCall.addElement(&background);
    pageCall.addElement(&topPanel);
    pageCall.addElement(&home_picture);

    pageCall.addElement(&call_adjutant);
    pageCall.addElement(&call_attendant);

    pageCall.addElement(&reset);
    pageCall.addElement(&home_button);
    pageCall.addElement(&panel1);
    app.window()->addPage(pageCall);


//    Page pageAv("audeo&video");
//    Page pageBoards("boards");
//    Page pageLights("lights");
//    Page pageMultimedia("multimedia");
//    Page pageSection("section");

    //home
    app.loadTexsture("image/home/background.png","background");
    app.loadTexsture("image/home/call.png","call");
    app.loadTexsture("image/home/irs.png","irs");
    app.loadTexsture("image/home/shades.png","shades");
    app.loadTexsture("image/home/lights.png","lights");
    app.loadTexsture("image/home/RUENG.png","rueng");
    app.loadTexsture("image/home/call_on.png","call_on");
    app.loadTexsture("image/home/irs_on.png","irs_on");
    app.loadTexsture("image/home/shades_on.png","shades_on");
    app.loadTexsture("image/home/lights_on.png","lights_on");
    app.loadTexsture("image/home/RUENG_ON.png","rueng_on");

    app.loadTexsture("image/home/reset_button.png","reset");
    app.loadTexsture("image/home/bottom_panel1.png","panel1");
    app.loadTexsture("image/home/home_button.png","home_button");
    app.loadTexsture("image/home/PANEL.png","topPanel");
    app.loadTexsture("image/home/home_picture.png","home_picture");

    //call
    app.loadTexsture("image/call/call_adjutant.png","call_adjutant");
    app.loadTexsture("image/call/call_adjutant.png","call_adjutant_on");
    app.loadTexsture("image/call/call_adjutant.png","call_attendant");
    app.loadTexsture("image/call/call_adjutant.png","call_attendant_on");

    app.run();

    return 0;
}


