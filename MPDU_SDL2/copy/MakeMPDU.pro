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
    buttonevents.cpp

LIBS += -L /usr/lib/x86_64-linux-gnu/ -lSDL2 \
        -L /usr/lib/x86_64-linux-gnu/ -lSDL2_image \
        -L /usr/lib/x86_64-linux-gnu/ -lSDL2_mixer \
        -L /usr/lib/x86_64-linux-gnu/ -lSDL2_ttf

INCLUDEPATH += /usr/include/SDL2/

include(deployment.pri)
qtcAddDeployment()

DISTFILES += \
    image/audio_video_usb/DOWN_P.png \
    image/audio_video_usb/DOWN_R.png \
    image/audio_video_usb/FOTO_P.png \
    image/audio_video_usb/FOTO_R.png \
    image/audio_video_usb/NAZAD_P.png \
    image/audio_video_usb/NAZAD_R.png \
    image/audio_video_usb/NAZAD1_P.png \
    image/audio_video_usb/NAZAD1_R.png \
    image/audio_video_usb/NAZAD3_P.png \
    image/audio_video_usb/NAZAD3_R.png \
    image/audio_video_usb/PLAY_P.png \
    image/audio_video_usb/PLAY_R.png \
    image/audio_video_usb/PUSTO_P.png \
    image/audio_video_usb/PUSTO_R.png \
    image/audio_video_usb/STOP_P.png \
    image/audio_video_usb/STOP_R.png \
    image/audio_video_usb/UP_P.png \
    image/audio_video_usb/UP_R.png \
    image/audio_video_usb/VPERED_P.png \
    image/audio_video_usb/VPERED_R.png \
    image/audio_video_usb/VPERED1_P.png \
    image/audio_video_usb/VPERED1_R.png \
    image/audio_video_usb/VPERED3_P.png \
    image/audio_video_usb/VPERED3_R.png \
    image/call/call_adjutant_eng_on.png \
    image/call/call_adjutant_eng.png \
    image/call/call_adjutant_on.png \
    image/call/call_adjutant.png \
    image/call/call_attendant_eng_on.png \
    image/call/call_attendant_eng.png \
    image/call/call_attendant_on.png \
    image/call/call_attendant.png \
    image/dvd/menu_eng_on.png \
    image/dvd/menu_eng.png \
    image/dvd/menu_on.png \
    image/dvd/menu.png \
    image/dvd/menuEng_on.png \
    image/dvd/menuEng.png \
    image/dvd/NAZAD_P.png \
    image/dvd/NAZAD_R.png \
    image/dvd/NAZAD1_P.png \
    image/dvd/NAZAD1_R.png \
    image/dvd/NAZAD3_P.png \
    image/dvd/NAZAD3_R.png \
    image/dvd/PLAY_P.png \
    image/dvd/PLAY_R.png \
    image/dvd/PUSTO_P.png \
    image/dvd/PUSTO_R.png \
    image/dvd/STOP_P.png \
    image/dvd/STOP_R.png \
    image/dvd/UP_P.png \
    image/dvd/UP_R.png \
    image/dvd/VPERED_P.png \
    image/dvd/VPERED_R.png \
    image/dvd/VPERED1_P.png \
    image/dvd/VPERED1_R.png \
    image/dvd/VPERED3_P.png \
    image/dvd/VPERED3_R.png \
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
    image/jalousie/left_side_eng_on.png \
    image/jalousie/left_side_eng.png \
    image/jalousie/left_side_on.png \
    image/jalousie/left_side.png \
    image/jalousie/starboard_eng_on.png \
    image/jalousie/starboard_eng.png \
    image/jalousie/starboard_on.png \
    image/jalousie/starboard.png \
    image/left_right_board/down_on.png \
    image/left_right_board/down.png \
    image/left_right_board/up_on.png \
    image/left_right_board/up.png \
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
    image/section/bottom_panel1.png \
    image/section/bottom_panel2.png \
    image/section/bottom_panel3.png \
    image/section/home_button.png \
    image/section/home_picture.png \
    image/section/knop1.png \
    image/section/knop2.png \
    image/section/knop3.png \
    image/section/KNOPhome.png \
    image/section/KNOPnazad.png \
    image/section/KRUG.png \
    image/section/PANEL.png \
    image/section/reset_button.png \
    image/section/round.png \
    resources/fonts/marlett.ttf \
    resources/fonts/Scada/Scada.jpg \
    resources/fonts/Scada/Scada-Bold.ttf \
    resources/fonts/Scada/Scada-BoldItalic.ttf \
    resources/fonts/Scada/Scada-Italic.ttf \
    resources/fonts/Scada/Scada-Regular.ttf \
    resources/fonts/sketchy.ttf

HEADERS += \
    button.h \
    texturemngr.h \
    page.h \
    window.h \
    application.h \
    buttonevents.h



