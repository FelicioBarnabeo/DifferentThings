TEMPLATE = app
CONFIG -= console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    button.cpp \
    texturemngr.cpp \
    page.cpp \
    window.cpp \
    application.cpp \
    buttonevents.cpp \
    geometry.cpp

LIBS += -L /usr/lib/x86_64-linux-gnu/ -lSDL2 \
        -L /usr/lib/x86_64-linux-gnu/ -lSDL2_image \

INCLUDEPATH += /usr/include/SDL2/ \

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    button.h \
    texturemngr.h \
    page.h \
    window.h \
    application.h \
    buttonevents.h \
    geometry.h

DISTFILES += \
    image/audio_video_usb/choose_disk_on.png \
    image/audio_video_usb/choose_disk.png \
    image/audio_video_usb/down_on.png \
    image/audio_video_usb/down.png \
    image/audio_video_usb/empty_on.png \
    image/audio_video_usb/empty.png \
    image/audio_video_usb/foto_on.png \
    image/audio_video_usb/foto.png \
    image/audio_video_usb/next_track_on.png \
    image/audio_video_usb/next_track.png \
    image/audio_video_usb/pause_on.png \
    image/audio_video_usb/pause.png \
    image/audio_video_usb/peremot_nazad_on.png \
    image/audio_video_usb/peremot_nazad.png \
    image/audio_video_usb/peremot_vpered_on.png \
    image/audio_video_usb/peremot_vpered.png \
    image/audio_video_usb/play_on.png \
    image/audio_video_usb/play.png \
    image/audio_video_usb/prev_track_on.png \
    image/audio_video_usb/prev_track.png \
    image/audio_video_usb/stop_on.png \
    image/audio_video_usb/stop.png \
    image/audio_video_usb/UP_P.png \
    image/audio_video_usb/UP_R.png \
    image/call/call_adjutant_eng_on.png \
    image/call/call_adjutant_eng.png \
    image/call/call_adjutant_on.png \
    image/call/call_adjutant.png \
    image/call/call_attendant_eng_on.png \
    image/call/call_attendant_eng.png \
    image/call/call_attendant_on.png \
    image/call/call_attendant.png \
    image/dvd/choose_disk_on.png \
    image/dvd/choose_disk.png \
    image/dvd/down_on.png \
    image/dvd/down.png \
    image/dvd/menu_on.png \
    image/dvd/menu.png \
    image/dvd/menuEng_on.png \
    image/dvd/menuEng.png \
    image/dvd/next_track_on.png \
    image/dvd/next_track.png \
    image/dvd/pause_on.png \
    image/dvd/pause.png \
    image/dvd/peremot_nazad_on.png \
    image/dvd/peremot_nazad.png \
    image/dvd/peremot_vpered_on.png \
    image/dvd/peremot_vpered.png \
    image/dvd/play_on.png \
    image/dvd/play.png \
    image/dvd/prev_track_on.png \
    image/dvd/prev_track.png \
    image/dvd/stop_on.png \
    image/dvd/stop.png \
    image/home/background.png \
    image/home/bottom_panel1.png \
    image/home/bottom_panel2.png \
    image/home/bottom_panel3.png \
    image/home/call_on.png \
    image/home/call.png \
    image/home/callEng_on.png \
    image/home/callEng.png \
    image/home/home_button.png \
    image/home/home_picture.png \
    image/home/irs_on.png \
    image/home/irs.png \
    image/home/irsEng_on.png \
    image/home/irsEng.png \
    image/home/lights_on.png \
    image/home/lights.png \
    image/home/lightsEng_on.png \
    image/home/lightsEng.png \
    image/home/PANEL.png \
    image/home/reset_button.png \
    image/home/RUENG_ON.png \
    image/home/RUENG.png \
    image/home/shades_on.png \
    image/home/shades.png \
    image/home/shadesEng_on.png \
    image/home/shadesEng.png \
    image/irs/airshow_eng_on.png \
    image/irs/airshow_eng.png \
    image/irs/airshow_on.png \
    image/irs/airshow.png \
    image/irs/multimedia_eng_on.png \
    image/irs/multimedia_eng.png \
    image/irs/multimedia_on.png \
    image/irs/multimedia.png \
    image/irs/tv_eng_on.png \
    image/irs/tv_eng.png \
    image/irs/tv_on.png \
    image/irs/tv.png \
    image/irs/videocamera_eng_on.png \
    image/irs/videocamera_eng.png \
    image/irs/videocamera_on.png \
    image/irs/videocamera.png \
    image/lights/onboard_lights_eng_on.png \
    image/lights/onboard_lights_eng.png \
    image/lights/onboard_lights_on.png \
    image/lights/onboard_lights.png \
    image/lights/rof_lights_on.png \
    image/lights/roof_lights_eng_on.png \
    image/lights/roof_lights_eng.png \
    image/lights/roof_lights_on .png \
    image/lights/roof_lights_on.png \
    image/lights/roof_lights.png \
    image/multimedia/audio_eng_on.png \
    image/multimedia/audio_eng.png \
    image/multimedia/audio_on.png \
    image/multimedia/audio.png \
    image/multimedia/dvd_on.png \
    image/multimedia/dvd.png \
    image/multimedia/usb_on.png \
    image/multimedia/usb.png \
    image/multimedia/video_eng_on.png \
    image/multimedia/video_eng.png \
    image/multimedia/video_on.png \
    image/multimedia/video.png \
    image/open_close/close_on.png \
    image/open_close/close.png \
    image/open_close/open_on.png \
    image/open_close/open.png \
    image/shades/left_side_eng_on.png \
    image/shades/left_side_eng.png \
    image/shades/left_side_on.png \
    image/shades/left_side.png \
    image/shades/ride_side_eng_on.png \
    image/shades/ride_side_eng.png \
    image/shades/ride_side_on.png \
    image/shades/ride_side.png



