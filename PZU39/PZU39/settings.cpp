#include "settings.h"
#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <serialdevice.h>
#include <configurator.h>
#include <QTimer>

//Настройки по умолчанию
namespace DefaultSC
{
    QString File = "./SETTINGS.cfg";
    const int currentZone = 1;
    QString language = "ru";
    QString textFont = "";
    QString iconFont = "Ionicons";
    const int iconSizeH1 = 10;
    const int iconSizeH2 = 12;
    const int iconSizeH3 = 16;
    const int iconSizeH4 = 21;
    const int iconSizeH5 = 24;
    const int iconSizeH6 = 32;
    QString bgcolor            = "#32434A";//"#263238"
    QString fgColor            = "#FFFFFF";
    QString inactiveBtnColor   = "transparent";
    QString activeBtnColor     = "#E97F23";
    QString borderMenuBtnColor = "#46505A";
    QString barColor           = "#000000";

    QString ttyname = "/dev/ttyUSB1";
    const int baudrate = 19200;
    const int databits = 8;
    const int stopbits = 1;
    const int parity = 2;

    //App state
    bool lightUpperState = false;
    bool lightBortState  = false;
    bool lightNicheState = false;
    bool lightDecorState = false;
    bool lightHallUpperState = false;
    bool lightHallBortState = false;
    bool lightHallDecorState = false;

    bool tvState = false;
    bool hdmiState = false;
    bool airshowState = false;
    bool videocameraState = false;
    bool menuDvdState = false;
    bool menuAudioState = false;
    bool menuVideoState = false;
    bool menuUSBState = false;
    int currentVolume = 0;
    QString brightnessLevel = "7";
    QString brMode = "Auto";
}

Settings * Settings::m_instance = 0;

Settings * Settings::instance()
{
    if(!m_instance)
        m_instance = new Settings();
    return m_instance;
}

Settings::Settings(QObject *parent): QObject(parent)
{
    m_settings = new QSettings(DefaultSC::File,QSettings::IniFormat);
    //QSettings settings(DefaultSC::File,QSettings::IniFormat);
    m_currentZone      = m_settings->value("CurrentZone"       ,DefaultSC::currentZone).toInt();
    m_lang             = m_settings->value("Language"          ,DefaultSC::language).toString();
    m_textFont         = m_settings->value("TextFont"          ,DefaultSC::textFont).toString();
    m_iconFont         = m_settings->value("IconFont"          ,DefaultSC::iconFont).toString();
    m_iconFontH1       = m_settings->value("IconSizeH1"        ,DefaultSC::iconSizeH1).toInt();
    m_iconFontH2       = m_settings->value("IconSizeH2"        ,DefaultSC::iconSizeH2).toInt();
    m_iconFontH3       = m_settings->value("IconSizeH3"        ,DefaultSC::iconSizeH3).toInt();
    m_iconFontH4       = m_settings->value("IconSizeH4"        ,DefaultSC::iconSizeH4).toInt();
    m_iconFontH5       = m_settings->value("IconSizeH5"        ,DefaultSC::iconSizeH5).toInt();
    m_iconFontH6       = m_settings->value("IconSizeH6"        ,DefaultSC::iconSizeH6).toInt();
    m_bgColor          = m_settings->value("BackgroundColor"   ,DefaultSC::bgcolor).toString();
    m_fgColor          = m_settings->value("ForegroundColor"   ,DefaultSC::fgColor).toString();
    m_inactiveBtnClr   = m_settings->value("InactiveBtnColor"  ,DefaultSC::inactiveBtnColor).toString();
    m_activeBtnClr     = m_settings->value("ActiveBtnColor"    ,DefaultSC::activeBtnColor).toString();
    m_borderMenuBtnClr = m_settings->value("BorderMenuBtnColor",DefaultSC::borderMenuBtnColor).toString();
    m_barClr           = m_settings->value("TopbarColor"       ,DefaultSC::barColor).toString();

    m_ttyName          = m_settings->value("SerialDevName"     ,DefaultSC::ttyname).toString();
    m_baudrate         = m_settings->value("Baudrate"          ,DefaultSC::baudrate).toInt();
    m_databits         = m_settings->value("DataBits"          ,DefaultSC::databits).toInt();
    m_stopbits         = m_settings->value("StopBits"          ,DefaultSC::stopbits).toInt();
    m_parity           = m_settings->value("Parity"            ,DefaultSC::parity).toInt();

    m_currentVolume    = m_settings->value("Volume"            ,DefaultSC::currentVolume).toInt();
    m_airshowState     = m_settings->value("Airshow"           ,DefaultSC::airshowState).toBool();
    m_videocameraState = m_settings->value("Videocamera"       ,DefaultSC::videocameraState).toBool();
    m_menuAudioState   = m_settings->value("MenuDvd"           ,DefaultSC::menuDvdState).toBool();
    m_menuDvdState     = m_settings->value("MenuAudio"         ,DefaultSC::menuAudioState).toBool();
    m_menuVideoState   = m_settings->value("MenuVideo"         ,DefaultSC::menuVideoState).toBool();
    m_menuUSBState     = m_settings->value("MenuUSB"           ,DefaultSC::menuUSBState).toBool();
    m_tvState          = m_settings->value("TvOn"              ,DefaultSC::tvState).toBool();
    m_hdmiState        = m_settings->value("Hdmi"              ,DefaultSC::hdmiState).toBool();
    m_lightUpperState  = m_settings->value("LightUpper"        ,DefaultSC::lightUpperState).toBool();
    m_lightBortState   = m_settings->value("LightBort"         ,DefaultSC::lightBortState).toBool();
    m_lightNicheState  = m_settings->value("LightNiche"        ,DefaultSC::lightBortState).toBool();
    m_lightDecorState  = m_settings->value("LightDecor"        ,DefaultSC::lightDecorState).toBool();
    m_lightHallUpperState = m_settings->value("LightHallUpper" ,DefaultSC::lightHallUpperState).toBool();
    m_lightHallBortState  = m_settings->value("LightHallBort"  ,DefaultSC::lightHallBortState).toBool();
    m_lightHallDecorState = m_settings->value("LightHallDecor" ,DefaultSC::lightDecorState).toBool();

    m_brtAutoTimer = new QTimer;
    connect(m_brtAutoTimer, &QTimer::timeout, this, &Settings::autoReduceBrightness);
    if(m_settings->value("BrightnessMode") == "Auto" )
    {
        setBrtMode(BrightnessMode::Auto);
    }
    else
    {
        setBrtMode(BrightnessMode::Manual);
        m_brightnessLevel  = m_settings->value("BrightnessLevel",DefaultSC::brightnessLevel).toString();
        applyBrightness(m_brightnessLevel);
    }
    m_translator = new QTranslator(this);
    m_translator->load(":/translations/"+this->m_lang+".qm");

    //qApp->installTranslator(m_translator);
    QCoreApplication::instance()->installTranslator(m_translator);
    connect(this,&Settings::langChanged,this,&Settings::applyLanguage);
    connect(this,&Settings::brightnessLevelChanged,this,&Settings::applyBrightness);
}

bool Settings::isShadow()
{
    return m_brightnessLevel!="7";
}

bool Settings::isAutoBrightnessMode()
{
    return m_brtMode==BrightnessMode::Auto;
}

void Settings::runAutoBrightnessMode()
{
    setBrightnessLevel("7");
    m_brtAutoTimer->start(15000);
}

void Settings::autoReduceBrightness()
{
    if(m_brightnessLevel == "7")
    {
        setBrightnessLevel("4");
        return;
    }
    else if(m_brightnessLevel == "4")
    {
        setBrightnessLevel("1");
        m_brtAutoTimer->stop();
        return;
    }
}

void Settings::applyBrightness(QString brightnessLevel)
{
    //qDebug()<<"Brightness == "<< brightnessLevel;
    QFile brFile("/sys/devices/soc0/backlight_lcd.26/backlight/backlight_lcd.26/brightness");
    if(!brFile.open(QIODevice::ReadWrite)){
        qDebug()<<"Can't open file "<<brFile.fileName();
        return;
    }
    brFile.write(brightnessLevel.toStdString().c_str());
    brFile.close();
}

void Settings::applyLanguage()
{
    //qDebug()<<"Apply language "<<m_lang;

    QCoreApplication::instance()->removeTranslator(m_translator);
    delete m_translator;

    m_translator = new QTranslator(this);
    //QString translateName = ":/translations/"+this->m_lang+".qm";
    //qDebug()<<translateName;
    m_translator->load("translations/"+this->m_lang+".qm"); //Важно ставить :/translations/.. либо translations/...

    QCoreApplication::instance()->installTranslator(m_translator);
    //qApp->installTranslator(m_translator);
    emit qstrUpdateHook();
}

void Settings::askBPLanguage(SerialDevice *sd)
{
    sd->sendCommand(Configurator::instance()->getCurrentLanguage());
}

void Settings::askBPVolume(SerialDevice *sd)
{
    sd->sendCommand(Configurator::instance()->getCurrentVolume());
}

void Settings::askMsopState(SerialDevice *sd)
{
    sd->sendCommand(Configurator::instance()->msopLocalAnswer());
}

void Settings::setQstrUpdateHook(QString qstrUpdateHook)
{
    if (m_qstrUpdateHook == qstrUpdateHook)
        return;

    m_qstrUpdateHook = qstrUpdateHook;
    emit qstrUpdateHookChanged(qstrUpdateHook);
}

QString Settings::qstrUpdateHook() const
{
    return m_qstrUpdateHook;
}

int Settings::currentZone() const
{
    return m_currentZone;
}

QString Settings::lang() const
{
    return m_lang;
}

QString Settings::textFont() const
{
    return m_textFont;
}

QString Settings::iconFont() const
{
    return m_iconFont;
}

int Settings::iconFontH1() const
{
    return m_iconFontH1;
}

int Settings::iconFontH2() const
{
    return m_iconFontH2;
}

int Settings::iconFontH3() const
{
    return m_iconFontH3;
}

int Settings::iconFontH4() const
{
    return m_iconFontH4;
}

int Settings::iconFontH5() const
{
    return m_iconFontH5;
}

int Settings::iconFontH6() const
{
    return m_iconFontH6;
}

QString Settings::bgColor() const
{
    return m_bgColor;
}

QString Settings::fgColor() const
{
    return m_fgColor;
}

QString Settings::activeBtnClr() const
{
    return m_activeBtnClr;
}

QString Settings::inactiveBtnClr() const
{
    return m_inactiveBtnClr;
}

QString Settings::borderMenuBtnClr() const
{
    return m_borderMenuBtnClr;
}

QString Settings::barClr() const
{
    return m_barClr;
}

void Settings::setCurrentZone(int currentZone)
{
    if (m_currentZone == currentZone)
        return;

    m_currentZone = currentZone;
    emit currentZoneChanged(currentZone);
}

void Settings::setLang(QString lang)
{
    if (m_lang == lang)
        return;
    m_lang = lang;
    m_settings->setValue("Language",lang);
    emit langChanged(lang);
}

void Settings::setTextFont(QString textFont)
{
    if (m_textFont == textFont)
        return;

    m_textFont = textFont;
    emit textFontChanged(textFont);
}

void Settings::setIconFont(QString iconFont)
{
    if (m_iconFont == iconFont)
        return;

    m_iconFont = iconFont;
    emit iconFontChanged(iconFont);
}

void Settings::setIconFontH1(int iconFontH1)
{
    if (m_iconFontH1 == iconFontH1)
        return;

    m_iconFontH1 = iconFontH1;
    emit iconFontH1Changed(iconFontH1);
}

void Settings::setIconFontH2(int iconFontH2)
{
    if (m_iconFontH1 == iconFontH2)
        return;

    m_iconFontH1 = iconFontH2;
    emit iconFontH1Changed(iconFontH2);
}

void Settings::setIconFontH3(int iconFontH3)
{
    if (m_iconFontH3 == iconFontH3)
        return;

    m_iconFontH3 = iconFontH3;
    emit iconFontH3Changed(iconFontH3);
}

void Settings::setIconFontH4(int iconFontH4)
{
    if (m_iconFontH4 == iconFontH4)
        return;

    m_iconFontH4 = iconFontH4;
    emit iconFontH4Changed(iconFontH4);
}

void Settings::setIconFontH5(int iconFontH5)
{
    if (m_iconFontH5 == iconFontH5)
        return;

    m_iconFontH5 = iconFontH5;
    emit iconFontH5Changed(iconFontH5);
}

void Settings::setIconFontH6(int iconFontH6)
{
    if (m_iconFontH6 == iconFontH6)
        return;

    m_iconFontH6 = iconFontH6;
    emit iconFontH6Changed(iconFontH6);
}

void Settings::setBgColor(QString bgColor)
{
    if (m_bgColor == bgColor)
        return;

    m_bgColor = bgColor;
    emit bgColorChanged(bgColor);
}

void Settings::setFgColor(QString fgColor)
{
    if (m_fgColor == fgColor)
        return;

    m_fgColor = fgColor;
    emit fgColorChanged(fgColor);
}

void Settings::setActiveBtnClr(QString activeBtnClr)
{
    if (m_activeBtnClr == activeBtnClr)
        return;

    m_activeBtnClr = activeBtnClr;
    emit activeBtnClrChanged(activeBtnClr);
}

void Settings::setInactiveBtnClr(QString inactiveBtnClr)
{
    if (m_inactiveBtnClr == inactiveBtnClr)
        return;

    m_inactiveBtnClr = inactiveBtnClr;
    emit inactiveBtnClrChanged(inactiveBtnClr);
}

void Settings::setBorderMenuBtnClr(QString borderMenuBtnClr)
{
    if (m_borderMenuBtnClr == borderMenuBtnClr)
        return;

    m_borderMenuBtnClr = borderMenuBtnClr;
    emit borderMenuBtnClrChanged(borderMenuBtnClr);
}

void Settings::setBarClr(QString barClr)
{
    if (m_barClr == barClr)
        return;

    m_barClr = barClr;
    emit barClrChanged(barClr);
}

void Settings::setTtyName(QString ttyName)
{
    if (m_ttyName == ttyName)
        return;

    m_ttyName = ttyName;
    emit ttyNameChanged(ttyName);
}

void Settings::setBaudrate(int baudrate)
{
    if (m_baudrate == baudrate)
        return;

    m_baudrate = baudrate;
    emit baudrateChanged(baudrate);
}

void Settings::setDatabits(int databits)
{
    if (m_databits == databits)
        return;

    m_databits = databits;
    emit databitsChanged(databits);
}

void Settings::setStopbits(int stopbits)
{
    if (m_stopbits == stopbits)
        return;

    m_stopbits = stopbits;
    emit stopbitsChanged(stopbits);
}

void Settings::setParity(int parity)
{
    if (m_parity == parity)
        return;

    m_parity = parity;
    emit parityChanged(parity);
}

void Settings::setTvState(bool tvState)
{
    if (m_tvState == tvState)
        return;

    m_tvState = tvState;
    emit tvStateChanged(tvState);
}

void Settings::setAirshowState(bool airshowState)
{
//    if (m_airshowState == airshowState)
//        return;
    if(airshowState) this->setVideocameraState(false); //важно присваивать через слот, чтобы сработал сигнал на изменение

    m_airshowState = airshowState;
    emit airshowStateChanged(airshowState);
}

void Settings::setVideocameraState(bool videocameraState)
{
//    if (m_videocameraState == videocameraState)
//        return;
    if(videocameraState) this->setAirshowState(false);
    m_videocameraState = videocameraState;
    emit videocameraStateChanged(videocameraState);
}

void Settings::setCurrentVolume(int currentVolume)
{
    if (m_currentVolume == currentVolume)
        return;

    m_currentVolume = currentVolume;
    m_settings->setValue("Volume",currentVolume);
    emit currentVolumeChanged(currentVolume);
}

void Settings::setLightUpperState(bool lightUpperState)
{
    if (m_lightUpperState == lightUpperState)
        return;
   // m_settings->setValue("LightUpper",lightUpperState);
    m_lightUpperState = lightUpperState;
    emit lightUpperStateChanged(lightUpperState);
}

void Settings::setLightBortState(bool lightBortState)
{
    if (m_lightBortState == lightBortState)
        return;
    //m_settings->setValue("LightBort",lightBortState);
    m_lightBortState = lightBortState;
    emit lightBortStateChanged(lightBortState);
}

void Settings::setLightNicheState(bool lightNicheState)
{
    if (m_lightNicheState == lightNicheState)
        return;
    //m_settings->setValue("LightNiche",lightNicheState);
    m_lightNicheState = lightNicheState;
    emit lightNicheStateChanged(lightNicheState);
}

void Settings::setLightDecorState(bool lightDecorState)
{
    if (m_lightDecorState == lightDecorState)
        return;
   // m_settings->setValue("LightDecor",lightDecorState);
    m_lightDecorState = lightDecorState;
    emit lightDecorStateChanged(lightDecorState);
}

void Settings::setBrightnessLevel(QString brightnessLevel)
{
    if (m_brightnessLevel == brightnessLevel)
        return;
    m_settings->setValue("BrightnessLevel",brightnessLevel);
    m_brightnessLevel = brightnessLevel;
    emit brightnessLevelChanged(brightnessLevel);
}

void Settings::setMenuDvdState(bool menuDvdState)
{
//    if (m_menuDvdState == menuDvdState)
//        return;
    this->setVideocameraState(false);
    this->setAirshowState(false);
    m_menuDvdState = menuDvdState;
    emit menuDvdStateChanged(menuDvdState);
}

void Settings::setMenuAudioState(bool menuAudioState)
{
//    if (m_menuAudioState == menuAudioState)
//        return;
    this->setVideocameraState(false);
    this->setAirshowState(false);
    m_menuAudioState = menuAudioState;
    emit menuAudioStateChanged(menuAudioState);
}

void Settings::setMenuVideoState(bool menuVideoState)
{
//    if (m_menuVideoState == menuVideoState)
//        return;
    this->setVideocameraState(false);
    this->setAirshowState(false);
    m_menuVideoState = menuVideoState;
    emit menuVideoStateChanged(menuVideoState);
}

void Settings::setMenuUSBState(bool menuUSBState)
{
//    if (m_menuUSBState == menuUSBState)
//        return;
    this->setVideocameraState(false);
    this->setAirshowState(false);
    m_menuUSBState = menuUSBState;
    emit menuUSBStateChanged(menuUSBState);
}

void Settings::setHdmiState(bool hdmiState)
{
    if (m_hdmiState == hdmiState)
        return;

    m_hdmiState = hdmiState;
    //m_settings->setValue("Hdmi", true);
    emit hdmiStateChanged(hdmiState);
}

void Settings::sync()
{
    m_settings->sync();
}

void Settings::setBrtMode(BrightnessMode brtMode)
{
    if (m_brtMode == brtMode)
        return;

    m_brtMode = brtMode;
    if(brtMode == BrightnessMode::Manual)
        m_brtAutoTimer->stop();
    else if(brtMode == BrightnessMode::Auto)
        runAutoBrightnessMode();
    emit brtModeChanged(m_brtMode);
}
