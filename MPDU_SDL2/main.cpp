#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "button.h"
#include "texturemngr.h"
#include "page.h"
#include "application.h"
#include "buttonevents.h"
#include "geometry.h"
#include <math.h>

using namespace std;
typedef WindowFlags WF;
Application app;

int main()
{      
    app.createWindow("MPDU",0,0,240,320,(FULLSCREEN_DESKTOP | BORDERLESS));

    Element background(0,0,240,320,"background");
    Element topPanel(0,0,240,20,"topPanel");
    Element home_picture(0,0,30,20,"home_picture");
    Button reset(0,290,70,30,"reset","reset");
    reset.onClick = resetclick;
    Button home_button(170,290,70,30,"home_button","home_button");
    home_button.onClick = homeclick;
    Element panel1(68,293,102,27,"panel1");

    Page pageFasade("fasade");
    pageFasade.addElement(&background);
    pageFasade.addElement(&topPanel);
    pageFasade.addElement(&home_picture);
    pageFasade.addElement(&reset);
    pageFasade.addElement(&home_button);
    pageFasade.addElement(&panel1);

    //Button call(20,30,200,45,"call","call_on");
    Button call(20,30,200,45,"Вызов");
    //Внимание , вопрос знатоку, как сделать callback , чтоб возможно было
    //использовать public указатель на функцию как определение функции,сам не понял
    call.onClick = callclick;
    Button lights(20,80,200,45,"lights","lights_on");
    lights.onClick = lightsclick;
    Button shades(20,130,200,45,"shades","shades_on");
    shades.onClick = shadesclick;
    Button irs(20,180,200,45,"irs","irs_on");
    irs.onClick = irsclick;
    Button rueng(60,230,120,35,"rueng","rueng_on");
    rueng.onClick = ruengclick;

    Page pageHome("home");
    pageHome = pageFasade;
    pageHome.addElement(&call);
    pageHome.addElement(&lights);
    pageHome.addElement(&shades);
    pageHome.addElement(&irs);
    pageHome.addElement(&rueng);

    app.window()->addPage(pageHome);
    app.window()->setCurrentPage("home");

    Page pageCall("call","home");
    pageCall = pageFasade;
    Button call_adjutant(30,30,180,100,"call_adjutant","call_adjutant_on");
    Button call_attendant(30,140,180,100,"call_attendant","call_attendant_on");
    pageCall.addElement(&call_adjutant);
    pageCall.addElement(&call_attendant);
    app.window()->addPage(pageCall);

    Page pageLights("lights","home");
    pageLights = pageFasade;
    Button onboard_lights(30,30,180,100,"onboard_lights","onboard_lights_on");
    Button roof_lights(30,140,180,100,"roof_lights","roof_lights_on");
    pageLights.addElement(&onboard_lights);
    pageLights.addElement(&roof_lights);
    app.window()->addPage(pageLights);

    Page pageShades("shades","home");
    pageShades = pageFasade;
    Button left_board(30,30,180,100,"left_side","left_side_on");
    left_board.onClick = boardclick;
    Button right_board(30,140,180,100,"ride_side","ride_side_on");
    right_board.onClick = boardclick;
    pageShades.addElement(&left_board);
    pageShades.addElement(&right_board);
    app.window()->addPage(pageShades);

    Page pageOpen_close("open_close","shades");
    pageOpen_close = pageFasade;
    Button open(30,30,180,100,"open","open_on");
    Button close(30,140,180,100,"close","close_on");
    pageOpen_close.addElement(&open);
    pageOpen_close.addElement(&close);
    app.window()->addPage(pageOpen_close);


    Page pageIrs("irs","home");
    pageIrs = pageFasade;
    Button tv(20,30,200,50,"tv","tv_on");
    Button multimedia(20,90,200,50,"multimedia","multimedia_on");
    multimedia.onClick = mmsclick;
    Button airshow(20,150,200,50,"airshow","airshow_on");
    Button videocamera(20,210,200,50,"videocamera","videocamera_on");
    pageIrs.addElement(&tv);
    pageIrs.addElement(&multimedia);
    pageIrs.addElement(&airshow);
    pageIrs.addElement(&videocamera);
    app.window()->addPage(pageIrs);

    Page pageMms("mms","irs");
    pageMms = pageFasade;
    Button dvd(20,30,200,50,"dvd","dvd_on");
    dvd.onClick = dvdclick;
    Button audio(20,90,200,50,"audio","audio_on");
    audio.onClick = avuclick;
    Button video(20,150,200,50,"video","video_on");
    video.onClick = avuclick;
    Button usb(20,210,200,50,"usb","usb_on");
    usb.onClick = avuclick;
    pageMms.addElement(&audio);
    pageMms.addElement(&dvd);
    pageMms.addElement(&usb);
    pageMms.addElement(&video);
    app.window()->addPage(pageMms);

    Page pagePlayerAVU("avu","mms"); //audio_video_usb
    pagePlayerAVU = pageFasade;

    Button empty(85,30,70,35,"empty","empty_on");
    Button prev_track(30,40,60,60,"prev_track","prev_track_on");
    Button next_track(150,40,60,60,"next_track","next_track_on");
    Button peremot_nazad(20,95,35,70,"peremot_nazad","peremot_nazad_on");
    Button peremot_vpered(185,95,35,70,"peremot_vpered","peremot_vpered_on");
    Button choose_disk(30,160,60,60,"choose_disk","choose_disk_on");
    Button pause(150,160,60,60,"pause","pause_on");
    Button stop(85,195,70,35,"stop","stop_on");
    Button foto(70,235,100,40,"foto","foto_on");
    Button play(85,95,70,70,"play","play_on");

    pagePlayerAVU.addElement(&empty);
    pagePlayerAVU.addElement(&prev_track);
    pagePlayerAVU.addElement(&next_track);
    pagePlayerAVU.addElement(&peremot_nazad);
    pagePlayerAVU.addElement(&peremot_vpered);
    pagePlayerAVU.addElement(&choose_disk);
    pagePlayerAVU.addElement(&pause);
    pagePlayerAVU.addElement(&stop);
    pagePlayerAVU.addElement(&foto);
    pagePlayerAVU.addElement(&play);
    app.window()->addPage(pagePlayerAVU);

    Page pageDvd("dvd","mms");
    pageDvd = pageFasade;

    Button dmenu(70,35,100,40,"menu","menu_on");
    Button dempty(85,80,70,35,"empty","empty_on");
    Button dprev_track(30,90,60,60,"prev_track","prev_track_on");
    Button dnext_track(150,90,60,60,"next_track","next_track_on");
    Button dperemot_nazad(20,145,35,70,"peremot_nazad","peremot_nazad_on");
    Button dperemot_vpered(185,145,35,70,"peremot_vpered","peremot_vpered_on");
    Button dchoose_disk(30,210,60,60,"choose_disk","choose_disk_on");
    Button dpause(150,210,60,60,"pause","pause_on");
    Button dstop(85,245,70,35,"stop","stop_on");
    Button dplay(85,145,70,70,"play","play_on");

    pageDvd.addElement(&dmenu);
    pageDvd.addElement(&dempty);
    pageDvd.addElement(&dprev_track);
    pageDvd.addElement(&dnext_track);
    pageDvd.addElement(&dperemot_nazad);
    pageDvd.addElement(&dperemot_vpered);
    pageDvd.addElement(&dchoose_disk);
    pageDvd.addElement(&dpause);
    pageDvd.addElement(&dstop);
    pageDvd.addElement(&dplay);
    app.window()->addPage(pageDvd);

    //app.window()->setCurrentPage("avu");
    //Load texstures
    //fasade
    app.loadTexsture("russian","image/home/background.png","background");
    app.loadTexsture("russian","image/home/reset_button.png","reset");
    app.loadTexsture("russian","image/home/bottom_panel1.png","panel1");
    app.loadTexsture("russian","image/home/home_button.png","home_button");
    app.loadTexsture("russian","image/home/PANEL.png","topPanel");
    app.loadTexsture("russian","image/home/home_picture.png","home_picture");

    //home
    app.loadTexsture("russian","image/home/call.png","call");
    app.loadTexsture("russian","image/home/irs.png","irs");
    app.loadTexsture("russian","image/home/shades.png","shades");
    app.loadTexsture("russian","image/home/lights.png","lights");
    app.loadTexsture("russian","image/home/RUENG.png","rueng");
    app.loadTexsture("russian","image/home/call_on.png","call_on");
    app.loadTexsture("russian","image/home/irs_on.png","irs_on");
    app.loadTexsture("russian","image/home/shades_on.png","shades_on");
    app.loadTexsture("russian","image/home/lights_on.png","lights_on");
    app.loadTexsture("russian","image/home/RUENG_ON.png","rueng_on");
    //home eng
    app.loadTexsture("english","image/home/callEng.png","call");
    app.loadTexsture("english","image/home/irsEng.png","irs");
    app.loadTexsture("english","image/home/shadesEng.png","shades");
    app.loadTexsture("english","image/home/lightsEng.png","lights");
    app.loadTexsture("english","image/home/RUENG.png","rueng");
    app.loadTexsture("english","image/home/callEng_on.png","call_on");
    app.loadTexsture("english","image/home/irsEng_on.png","irs_on");
    app.loadTexsture("english","image/home/shadesEng_on.png","shades_on");
    app.loadTexsture("english","image/home/lightsEng_on.png","lights_on");
    app.loadTexsture("english","image/home/RUENG_ON.png","rueng_on");
    //call
    app.loadTexsture("russian","image/call/call_adjutant.png","call_adjutant");
    app.loadTexsture("russian","image/call/call_adjutant_on.png","call_adjutant_on");
    app.loadTexsture("russian","image/call/call_attendant.png","call_attendant");
    app.loadTexsture("russian","image/call/call_attendant_on.png","call_attendant_on");
    //call eng
    app.loadTexsture("english","image/call/call_adjutant_eng.png","call_adjutant");
    app.loadTexsture("english","image/call/call_adjutant_eng_on.png","call_adjutant_on");
    app.loadTexsture("english","image/call/call_attendant_eng.png","call_attendant");
    app.loadTexsture("english","image/call/call_attendant_eng_on.png","call_attendant_on");
    //lights
    app.loadTexsture("russian","image/lights/onboard_lights.png","onboard_lights");
    app.loadTexsture("russian","image/lights/onboard_lights_on.png","onboard_lights_on");
    app.loadTexsture("russian","image/lights/roof_lights.png","roof_lights");
    app.loadTexsture("russian","image/lights/roof_lights_on.png","roof_lights_on");
    //lights eng
    app.loadTexsture("english","image/lights/onboard_lights_eng.png","onboard_lights");
    app.loadTexsture("english","image/lights/onboard_lights_eng_on.png","onboard_lights_on");
    app.loadTexsture("english","image/lights/roof_lights_eng.png","roof_lights");
    app.loadTexsture("english","image/lights/roof_lights_eng_on.png","roof_lights_on");
    //shades
    app.loadTexsture("russian","image/shades/left_side.png","left_side");
    app.loadTexsture("russian","image/shades/left_side_on.png","left_side_on");
    app.loadTexsture("russian","image/shades/ride_side.png","ride_side");
    app.loadTexsture("russian","image/shades/ride_side_on.png","ride_side_on");
    //shades eng
    app.loadTexsture("english","image/shades/left_side_eng.png","left_side");
    app.loadTexsture("english","image/shades/left_side_eng_on.png","left_side_on");
    app.loadTexsture("english","image/shades/ride_side_eng.png","ride_side");
    app.loadTexsture("english","image/shades/ride_side_eng_on.png","ride_side_on");
    //open_close
    app.loadTexsture("russian","image/open_close/open.png","open");
    app.loadTexsture("russian","image/open_close/open_on.png","open_on");
    app.loadTexsture("russian","image/open_close/close.png","close");
    app.loadTexsture("russian","image/open_close/close_on.png","close_on");

    //irs
    app.loadTexsture("russian","image/irs/airshow.png","airshow");
    app.loadTexsture("russian","image/irs/airshow_on.png","airshow_on");
    app.loadTexsture("russian","image/irs/multimedia.png","multimedia");
    app.loadTexsture("russian","image/irs/multimedia_on.png","multimedia_on");
    app.loadTexsture("russian","image/irs/tv.png","tv");
    app.loadTexsture("russian","image/irs/tv_on.png","tv_on");
    app.loadTexsture("russian","image/irs/videocamera.png","videocamera");
    app.loadTexsture("russian","image/irs/videocamera_on.png","videocamera_on");
    //irs eng
    app.loadTexsture("english","image/irs/airshow_eng.png","airshow");
    app.loadTexsture("english","image/irs/airshow_eng_on.png","airshow_on");
    app.loadTexsture("english","image/irs/multimedia_eng.png","multimedia");
    app.loadTexsture("english","image/irs/multimedia_eng_on.png","multimedia_on");
    app.loadTexsture("english","image/irs/tv_eng.png","tv");
    app.loadTexsture("english","image/irs/tv_eng_on.png","tv_on");
    app.loadTexsture("english","image/irs/videocamera_eng.png","videocamera");
    app.loadTexsture("english","image/irs/videocamera_eng_on.png","videocamera_on");
    //multimedia
    app.loadTexsture("russian","image/multimedia/audio.png","audio");
    app.loadTexsture("russian","image/multimedia/audio_on.png","audio_on");
    app.loadTexsture("russian","image/multimedia/dvd.png","dvd");
    app.loadTexsture("russian","image/multimedia/dvd_on.png","dvd_on");
    app.loadTexsture("russian","image/multimedia/usb.png","usb");
    app.loadTexsture("russian","image/multimedia/usb_on.png","usb_on");
    app.loadTexsture("russian","image/multimedia/video.png","video");
    app.loadTexsture("russian","image/multimedia/video_on.png","video_on");
    //multimedia eng
    app.loadTexsture("english","image/multimedia/audio_eng.png","audio");
    app.loadTexsture("english","image/multimedia/audio_eng_on.png","audio_on");
    app.loadTexsture("english","image/multimedia/video_eng.png","video");
    app.loadTexsture("english","image/multimedia/video_eng_on.png","video_on");
    //audio_video_usb and dvd menu
    app.loadTexsture("russian","image/audio_video_usb/choose_disk.png","choose_disk");
    app.loadTexsture("russian","image/audio_video_usb/choose_disk_on.png","choose_disk_on");
    app.loadTexsture("russian","image/audio_video_usb/down.png","down");
    app.loadTexsture("russian","image/audio_video_usb/down_on.png","down_on");
    app.loadTexsture("russian","image/audio_video_usb/empty.png","empty");
    app.loadTexsture("russian","image/audio_video_usb/empty_on.png","empty_on");
    app.loadTexsture("russian","image/audio_video_usb/foto.png","foto");
    app.loadTexsture("russian","image/audio_video_usb/foto_on.png","foto_on");
    app.loadTexsture("russian","image/audio_video_usb/next_track.png","next_track");
    app.loadTexsture("russian","image/audio_video_usb/next_track_on.png","next_track_on");
    app.loadTexsture("russian","image/audio_video_usb/pause.png","pause");
    app.loadTexsture("russian","image/audio_video_usb/pause_on.png","pause_on");
    app.loadTexsture("russian","image/audio_video_usb/peremot_nazad.png","peremot_nazad");
    app.loadTexsture("russian","image/audio_video_usb/peremot_nazad_on.png","peremot_nazad_on");
    app.loadTexsture("russian","image/audio_video_usb/peremot_vpered.png","peremot_vpered");
    app.loadTexsture("russian","image/audio_video_usb/peremot_vpered_on.png","peremot_vpered_on");
    app.loadTexsture("russian","image/audio_video_usb/play.png","play");
    app.loadTexsture("russian","image/audio_video_usb/play_on.png","play_on");
    app.loadTexsture("russian","image/audio_video_usb/prev_track.png","prev_track");
    app.loadTexsture("russian","image/audio_video_usb/prev_track_on.png","prev_track_on");
    app.loadTexsture("russian","image/audio_video_usb/stop.png","stop");
    app.loadTexsture("russian","image/audio_video_usb/stop_on.png","stop_on");
    //dvd like avu without foto and with menu buttons
    app.loadTexsture("russian","image/dvd/menu.png","menu");
    app.loadTexsture("russian","image/dvd/menu_on.png","menu_on");
    //dvd eng
    app.loadTexsture("english","image/dvd/menuEng.png","menu");
    app.loadTexsture("english","image/dvd/menuEng_on.png","menu_on");

    app.run();

    return 0;
}


