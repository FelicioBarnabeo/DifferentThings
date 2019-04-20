#include "settings.h"
#include <QSettings>
#include <QCoreApplication>
#include "backlighter.h"

namespace SC {
const QString File = "./dementia.cfg";

const QString Lang = "ru";          // language
const QString TFont = "Roboto";     // text font
const QString IFont = "Awesome";    // icon font
const QString FGAC = "#00d5c3";     // foregroud active color
const QString FGIC = "#FFFFFF";     // foreground inactive color
const QString FGATC = "#000000";    // foregroud text active color
const QString BGIC = "#242c40";     // background inactive color

const QString AudioRP = "/media/data/audio";    // root path to audio files
const QString VideoRP = "/media/data/video";    // root path to video files
const QString GameRP = "/media/data/game";      // root path to info files
const QString InfoRP = "/media/data/info";      // root path to game files
const QString HelpRP = "/media/data/help";      // root path to help files
const QString AirshowRP = "/media/data/airshow";// root path for airshow files
const QString SpecRP = "/media/data/spec";      // root path to spec files
const QString CamSource = "rtsp://192.168.1.254/axis-media/media.amp";

const QString AirshowServerIP = "192.168.1.1";
const int AirshowServerPort = 60000;
const int AirshowImgSwitchMs = 2000;
const int AirshowImgUpdateMs = 20000;

const int SpecServerPort = 60001;

const int IFH1 = 28;    // icon font H1 font size
const int IFH2 = 26;    // icon font H2 font size
const int IFH3 = 24;    // icon font H3 font size
const int IFH4 = 16;    // icon font H4 font size
const int IFH5 = 14;    // icon font H5 font size

const int TFH1 = 24;    // text font H1 font size
const int TFH2 = 22;    // text font H2 font size
const int TFH3 = 18;    // text font H3 font size
const int TFH4 = 14;    // text font H4 font size
const int TFH5 = 12;    // text font H5 font size

const int AVol = 50;     // audio volume value
const int VVol = 50;     // video volume value
const int GVol = 50;     // game volume value
const int SBrt = 8;

const int Pwd = 661504; // password
}

SettingsManager::SettingsManager(QObject *parent) : QObject(parent)
{
    QSettings settings(SC::File,QSettings::IniFormat);

    m_language = settings.value("language",SC::Lang).toString();

    m_textFont = settings.value("textFont",SC::TFont).toString();
    m_iconFont = settings.value("iconFont",SC::IFont).toString();

    m_iconFontH1 = settings.value("iconFontH1",SC::IFH1).toInt();
    m_iconFontH2 = settings.value("iconFontH2",SC::IFH2).toInt();
    m_iconFontH3 = settings.value("iconFontH3",SC::IFH3).toInt();
    m_iconFontH4 = settings.value("iconFontH4",SC::IFH4).toInt();
    m_iconFontH5 = settings.value("iconFontH5",SC::IFH5).toInt();

    m_textFontH1 = settings.value("textFontH1",SC::TFH1).toInt();
    m_textFontH2 = settings.value("textFontH2",SC::TFH2).toInt();
    m_textFontH3 = settings.value("textFontH3",SC::TFH3).toInt();
    m_textFontH4 = settings.value("textFontH4",SC::TFH4).toInt();
    m_textFontH5 = settings.value("textFontH5",SC::TFH5).toInt();

    m_fgActiveColor = settings.value("fgActiveColor",SC::FGAC).toString();
    m_fgInactiveColor = settings.value("fgInactiveColor",SC::FGIC).toString();
    m_fgActiveTextColor = settings.value("fgActiveTextColor",SC::FGATC).toString();
    m_bgInactiveColor = settings.value("bgInactiveColor",SC::BGIC).toString();

    m_audioVolume = settings.value("audioVolume",SC::AVol).toInt();
    m_videoVolume = settings.value("videoVolume",SC::VVol).toInt();
    m_gameVolume = settings.value("gameVolume",SC::GVol).toInt();
    m_screenBrightness = settings.value("screenBrightness",SC::SBrt).toInt();

    m_password = settings.value("password",SC::Pwd).toInt();

    m_audioRootPath = settings.value("audioRootPath",SC::AudioRP).toString();
    m_videoRootPath = settings.value("videoRootPath",SC::VideoRP).toString();
    m_infoRootPath = settings.value("infoRootPath",SC::InfoRP).toString();
    m_gameRootPath = settings.value("gameRootPath",SC::GameRP).toString();
    m_helpRootPath = settings.value("helpRootPath",SC::HelpRP).toString();
    m_specRootPath = settings.value("specRootPath",SC::SpecRP).toString();
    m_airshowRootPath = settings.value("airshowRootPath",SC::AirshowRP).toString();
    m_camcorderSource = settings.value("camcorderSource",SC::CamSource).toString();

    m_airshowServerIP = settings.value("airshowServerIP",SC::AirshowServerIP).toString();
    m_airshowServerPort = settings.value("airshowServerPort",SC::AirshowServerPort).toInt();
    m_airshowImgSwitchMs = settings.value("airshowImgSwitchMs",SC::AirshowImgSwitchMs).toInt();
    m_airshowImgUpdateMs = settings.value("airshowImgUpdateMs",SC::AirshowImgUpdateMs).toInt();

    m_specServerPort = settings.value("specServerPort",SC::SpecServerPort).toInt();

    Backlighter::setScreenBrightness(m_screenBrightness);

    m_translator = new QTranslator(this);
    m_translator->load(":/translations/" + this->m_language);
    QCoreApplication::instance()->installTranslator(m_translator);
    emit tsStrChanged("");
}

void SettingsManager::recreate(void)
{
    QSettings settings(SC::File, QSettings::IniFormat);
    settings.setValue("language",SC::Lang);
    settings.setValue("textFont",SC::TFont);
    settings.setValue("iconFont",SC::IFont);

    settings.setValue("iconFontH1",SC::IFH1);
    settings.setValue("iconFontH2",SC::IFH2);
    settings.setValue("iconFontH3",SC::IFH3);
    settings.setValue("iconFontH4",SC::IFH4);
    settings.setValue("iconFontH5",SC::IFH5);

    settings.setValue("textFontH1",SC::TFH1);
    settings.setValue("textFontH2",SC::TFH2);
    settings.setValue("textFontH3",SC::TFH3);
    settings.setValue("textFontH4",SC::TFH4);
    settings.setValue("textFontH5",SC::TFH5);

    settings.setValue("audioVolume",SC::AVol);
    settings.setValue("videoVolume",SC::VVol);
    settings.setValue("gameVolume",SC::GVol);
    settings.setValue("screenBrightness",SC::SBrt);

    settings.setValue("password",SC::Pwd);

    settings.setValue("audioRootPath",SC::AudioRP);
    settings.setValue("videoRootPath",SC::VideoRP);
    settings.setValue("infoRootPath",SC::InfoRP);
    settings.setValue("gameRootPath",SC::GameRP);
    settings.setValue("helpRootPath",SC::HelpRP);
    settings.setValue("specRootPath",SC::SpecRP);
    settings.setValue("airshowRootPath",SC::AirshowRP);
    settings.setValue("camcorderSource",SC::CamSource);

    settings.setValue("airshowServerIP",SC::AirshowServerIP);
    settings.setValue("airshowServerPort",SC::AirshowServerPort);
    settings.setValue("airshowImgSwitchMs",SC::AirshowImgSwitchMs);
    settings.setValue("airshowImgUpdateMs",SC::AirshowImgUpdateMs);

    settings.setValue("specServerPort",SC::SpecServerPort);

    settings.sync();
}

void SettingsManager::save(void)
{
    Backlighter::setScreenBrightness(m_screenBrightness);

    QSettings settings(SC::File,QSettings::IniFormat);

    settings.setValue("language",m_language);
    settings.setValue("audioVolume",m_audioVolume);
    settings.setValue("videoVolume",m_videoVolume);
    settings.setValue("gameVolume",m_gameVolume);
    settings.setValue("screenBrightness",m_screenBrightness);

    settings.sync();
    qDebug()<<"Sync is completed";
}

void SettingsManager::apllyTranslation(void)
{
    QCoreApplication::instance()->removeTranslator(m_translator);
    m_translator = new QTranslator(this);
    m_translator->load(":/translations/" + m_language);
    QCoreApplication::instance()->installTranslator(m_translator);
    emit tsStrChanged("");
}

QString SettingsManager::language() const
{
    return m_language;
}

QString SettingsManager::textFont() const
{
    return m_textFont;
}

QString SettingsManager::iconFont() const
{
    return m_iconFont;
}

QString SettingsManager::tsStr() const
{
    return m_tsStr;
}

int SettingsManager::iconFontH1() const
{
    return m_iconFontH1;
}

int SettingsManager::iconFontH2() const
{
    return m_iconFontH2;
}

int SettingsManager::iconFontH3() const
{
    return m_iconFontH3;
}

int SettingsManager::iconFontH4() const
{
    return m_iconFontH4;
}

int SettingsManager::iconFontH5() const
{
    return m_iconFontH5;
}

int SettingsManager::textFontH1() const
{
    return m_textFontH1;
}

int SettingsManager::textFontH2() const
{
    return m_textFontH2;
}

int SettingsManager::textFontH3() const
{
    return m_textFontH3;
}

int SettingsManager::textFontH4() const
{
    return m_textFontH4;
}

int SettingsManager::textFontH5() const
{
    return m_textFontH5;
}

QString SettingsManager::fgInactiveColor() const
{
    return m_fgInactiveColor;
}

QString SettingsManager::bgInactiveColor() const
{
    return m_bgInactiveColor;
}

QString SettingsManager::fgActiveColor() const
{
    return m_fgActiveColor;
}

QString SettingsManager::fgActiveTextColor() const
{
    return m_fgActiveTextColor;
}

QString SettingsManager::audioRootPath() const
{
    return m_audioRootPath;
}

QString SettingsManager::videoRootPath() const
{
    return m_videoRootPath;
}

QString SettingsManager::infoRootPath() const
{
    return m_infoRootPath;
}

QString SettingsManager::gameRootPath() const
{
    return m_gameRootPath;
}

int SettingsManager::gameVolume() const
{
    return m_gameVolume;
}

int SettingsManager::audioVolume() const
{
    return m_audioVolume;
}

int SettingsManager::videoVolume() const
{
    return m_videoVolume;
}

int SettingsManager::airshowImgSwitchMs() const
{
    return m_airshowImgSwitchMs;
}

int SettingsManager::airshowImgUpdateMs() const
{
    return m_airshowImgUpdateMs;
}

int SettingsManager::specServerPort() const
{
    return m_specServerPort;
}

QString SettingsManager::specRootPath() const
{
    return m_specRootPath;
}

int SettingsManager::screenBrightness() const
{
    return m_screenBrightness;
}

QString SettingsManager::airshowServerIP() const
{
    return m_airshowServerIP;
}

int SettingsManager::airshowServerPort() const
{
    return m_airshowServerPort;
}

QString SettingsManager::airshowRootPath() const
{
    return m_airshowRootPath;
}

QString SettingsManager::camcorderSource() const
{
    return m_camcorderSource;
}

QString SettingsManager::helpRootPath() const
{
    return m_helpRootPath;
}

int SettingsManager::password() const
{
    return m_password;
}

void SettingsManager::setLanguage(QString language)
{
    if (m_language == language) return;

    m_language = language;
    emit languageChanged(language);
}


void SettingsManager::setTextFont(QString textFont)
{
    if (m_textFont == textFont) return;

    m_textFont = textFont;
    emit textFontChanged(textFont);
}

void SettingsManager::setIconFont(QString iconFont)
{
    if (m_iconFont == iconFont) return;

    m_iconFont = iconFont;
    emit iconFontChanged(iconFont);
}

void SettingsManager::setTsStr(QString tsStr)
{
    if (m_tsStr == tsStr) return;

    m_tsStr = tsStr;
    emit tsStrChanged(tsStr);
}

void SettingsManager::requestToChangeLanguage(QString language)
{
    m_language = language;
    this->apllyTranslation();
    this->save();
}

void SettingsManager::setIconFontH1(int iconFontH1)
{
    if (m_iconFontH1 == iconFontH1) return;

    m_iconFontH1 = iconFontH1;
    emit iconFontH1Changed(iconFontH1);
}

void SettingsManager::setIconFontH2(int iconFontH2)
{
    if (m_iconFontH2 == iconFontH2) return;

    m_iconFontH2 = iconFontH2;
    emit iconFontH2Changed(iconFontH2);
}

void SettingsManager::setIconFontH3(int iconFontH3)
{
    if (m_iconFontH3 == iconFontH3) return;

    m_iconFontH3 = iconFontH3;
    emit iconFontH3Changed(iconFontH3);
}

void SettingsManager::setIconFontH5(int iconFontH5)
{
    if (m_iconFontH5 == iconFontH5)
        return;

    m_iconFontH5 = iconFontH5;
    emit iconFontH5Changed(iconFontH5);
}

void SettingsManager::setTextFontH1(int textFontH1)
{
    if (m_textFontH1 == textFontH1) return;

    m_textFontH1 = textFontH1;
    emit textFontH1Changed(textFontH1);
}

void SettingsManager::setTextFontH2(int textFontH2)
{
    if (m_textFontH2 == textFontH2) return;

    m_textFontH2 = textFontH2;
    emit textFontH2Changed(textFontH2);
}

void SettingsManager::setTextFontH3(int textFontH3)
{
    if (m_textFontH3 == textFontH3) return;

    m_textFontH3 = textFontH3;
    emit textFontH3Changed(textFontH3);
}

void SettingsManager::setTextFontH4(int textFontH4)
{
    if (m_textFontH4 == textFontH4) return;

    m_textFontH4 = textFontH4;
    emit textFontH4Changed(textFontH4);
}

void SettingsManager::setTextFontH5(int textFontH5)
{
    if (m_textFontH5 == textFontH5) return;

    m_textFontH5 = textFontH5;
    emit textFontH5Changed(textFontH5);
}

void SettingsManager::setFgInactiveColor(QString fgInactiveColor)
{
    if (m_fgInactiveColor == fgInactiveColor) return;

    m_fgInactiveColor = fgInactiveColor;
    emit fgInactiveColorChanged(fgInactiveColor);
}

void SettingsManager::setBgInactiveColor(QString bgInactiveColor)
{
    if (m_bgInactiveColor == bgInactiveColor) return;

    m_bgInactiveColor = bgInactiveColor;
    emit bgInactiveColorChanged(bgInactiveColor);
}

void SettingsManager::setFgActiveColor(QString fgActiveColor)
{
    if (m_fgActiveColor == fgActiveColor) return;

    m_fgActiveColor = fgActiveColor;
    emit fgActiveColorChanged(fgActiveColor);
}

void SettingsManager::setFgActiveTextColor(QString fgActiveTextColor)
{
    if (m_fgActiveTextColor == fgActiveTextColor)
        return;

    m_fgActiveTextColor = fgActiveTextColor;
    emit fgActiveTextColorChanged(fgActiveTextColor);
}

void SettingsManager::setAudioRootPath(QString audioRootPath)
{
    if (m_audioRootPath == audioRootPath)
        return;

    m_audioRootPath = audioRootPath;
    emit audioRootPathChanged(audioRootPath);
}

void SettingsManager::setVideoRootPath(QString videoRootPath)
{
    if (m_videoRootPath == videoRootPath)
        return;

    m_videoRootPath = videoRootPath;
    emit videoRootPathChanged(videoRootPath);
}

void SettingsManager::setInfoRootPath(QString infoRootPath)
{
    if (m_infoRootPath == infoRootPath)
        return;

    m_infoRootPath = infoRootPath;
    emit infoRootPathChanged(infoRootPath);
}

void SettingsManager::setGameRootPath(QString gameRootPath)
{
    if (m_gameRootPath == gameRootPath)
        return;

    m_gameRootPath = gameRootPath;
    emit gameRootPathChanged(gameRootPath);
}

void SettingsManager::setGameVolume(int gameVolume)
{
    if (m_gameVolume == gameVolume)
        return;

    m_gameVolume = gameVolume;
    emit gameVolumeChanged(gameVolume);
}

void SettingsManager::setAudioVolume(int audioVolume)
{
    if (m_audioVolume == audioVolume)
        return;

    m_audioVolume = audioVolume;
    emit audioVolumeChanged(audioVolume);
}

void SettingsManager::setVideoVolume(int videoVolume)
{
    if (m_videoVolume == videoVolume)
        return;

    m_videoVolume = videoVolume;
    emit videoVolumeChanged(videoVolume);
}

void SettingsManager::setAirshowImgSwitchMs(int airshowImgSwitchMs)
{
    if (m_airshowImgSwitchMs == airshowImgSwitchMs)
        return;

    m_airshowImgSwitchMs = airshowImgSwitchMs;
    emit airshowImgSwitchMsChanged(airshowImgSwitchMs);
}

void SettingsManager::setAirshowImgUpdateMs(int airshowImgUpdateMs)
{
    if (m_airshowImgUpdateMs == airshowImgUpdateMs)
        return;

    m_airshowImgUpdateMs = airshowImgUpdateMs;
    emit airshowImgUpdateMsChanged(airshowImgUpdateMs);
}

void SettingsManager::setSpecServerPort(int specServerPort)
{
    if (m_specServerPort == specServerPort)
        return;

    m_specServerPort = specServerPort;
    emit specServerPortChanged(specServerPort);
}

void SettingsManager::setSpecRootPath(QString specRootPath)
{
    if (m_specRootPath == specRootPath)
        return;

    m_specRootPath = specRootPath;
    emit specRootPathChanged(specRootPath);
}

void SettingsManager::setScreenBrightness(int screenBrightness)
{
    if (m_screenBrightness == screenBrightness)
        return;

    m_screenBrightness = screenBrightness;
    emit screenBrightnessChanged(screenBrightness);
}

void SettingsManager::setAirshowServerIP(QString airshowServerIP)
{
    if (m_airshowServerIP == airshowServerIP)
        return;

    m_airshowServerIP = airshowServerIP;
    emit airshowServerIPChanged(airshowServerIP);
}

void SettingsManager::setAirshowServerPort(int airshowServerPort)
{
    if (m_airshowServerPort == airshowServerPort)
        return;

    m_airshowServerPort = airshowServerPort;
    emit airshowServerPortChanged(airshowServerPort);
}

void SettingsManager::setAirshowRootPath(QString airshowRootPath)
{
    if (m_airshowRootPath == airshowRootPath)
        return;

    m_airshowRootPath = airshowRootPath;
    emit airshowRootPathChanged(airshowRootPath);
}

void SettingsManager::setCamcorderSource(QString camcorderSource)
{
    if (m_camcorderSource == camcorderSource)
        return;

    m_camcorderSource = camcorderSource;
    emit camcorderSourceChanged(camcorderSource);
}

void SettingsManager::setHelpRootPath(QString helpRootPath)
{
    if (m_helpRootPath == helpRootPath)
        return;

    m_helpRootPath = helpRootPath;
    emit helpRootPathChanged(helpRootPath);
}

void SettingsManager::setPassword(int password)
{
    if (m_password == password)
        return;

    m_password = password;
    emit passwordChanged(password);
}

void SettingsManager::setIconFontH4(int iconFontH4)
{
    if (m_iconFontH4 == iconFontH4) return;

    m_iconFontH4 = iconFontH4;
    emit iconFontH4Changed(iconFontH4);
}
