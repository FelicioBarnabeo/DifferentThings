#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>
#include <QTranslator>

class SerialDevice;
class QTimer;

class Settings : public QObject
{
    Q_OBJECT
    Q_ENUMS(BrightnessMode)
    Q_PROPERTY(BrightnessMode brtMode READ brtMode WRITE setBrtMode NOTIFY brtModeChanged)
    Q_PROPERTY(int currentZone READ currentZone WRITE setCurrentZone NOTIFY currentZoneChanged)

    Q_PROPERTY(QString lang READ lang WRITE setLang NOTIFY langChanged)
    Q_PROPERTY(QString qstrUpdateHook READ qstrUpdateHook WRITE setQstrUpdateHook NOTIFY qstrUpdateHookChanged)
    Q_PROPERTY(QString textFont READ textFont WRITE setTextFont NOTIFY textFontChanged)
    Q_PROPERTY(QString iconFont READ iconFont WRITE setIconFont NOTIFY iconFontChanged)
    Q_PROPERTY(QString brightnessLevel READ brightnessLevel WRITE setBrightnessLevel NOTIFY brightnessLevelChanged)

    Q_PROPERTY(int iconFontH1 READ iconFontH1 WRITE setIconFontH1 NOTIFY iconFontH1Changed)
    Q_PROPERTY(int iconFontH2 READ iconFontH2 WRITE setIconFontH2 NOTIFY iconFontH1Changed)
    Q_PROPERTY(int iconFontH3 READ iconFontH3 WRITE setIconFontH3 NOTIFY iconFontH3Changed)
    Q_PROPERTY(int iconFontH4 READ iconFontH4 WRITE setIconFontH4 NOTIFY iconFontH4Changed)
    Q_PROPERTY(int iconFontH5 READ iconFontH5 WRITE setIconFontH5 NOTIFY iconFontH5Changed)
    Q_PROPERTY(int iconFontH6 READ iconFontH6 WRITE setIconFontH6 NOTIFY iconFontH6Changed)

    Q_PROPERTY(QString bgColor READ bgColor WRITE setBgColor NOTIFY bgColorChanged)
    Q_PROPERTY(QString fgColor READ fgColor WRITE setFgColor NOTIFY fgColorChanged)
    Q_PROPERTY(QString activeBtnClr READ activeBtnClr WRITE setActiveBtnClr NOTIFY activeBtnClrChanged)
    Q_PROPERTY(QString inactiveBtnClr READ inactiveBtnClr WRITE setInactiveBtnClr NOTIFY inactiveBtnClrChanged)
    Q_PROPERTY(QString borderMenuBtnClr READ borderMenuBtnClr WRITE setBorderMenuBtnClr NOTIFY borderMenuBtnClrChanged)
    Q_PROPERTY(QString barClr READ barClr WRITE setBarClr NOTIFY barClrChanged)

    Q_PROPERTY(QString ttyName READ ttyName WRITE setTtyName NOTIFY ttyNameChanged)
    Q_PROPERTY(int baudrate READ baudrate WRITE setBaudrate NOTIFY baudrateChanged)
    Q_PROPERTY(int databits READ databits WRITE setDatabits NOTIFY databitsChanged)
    Q_PROPERTY(int stopbits READ stopbits WRITE setStopbits NOTIFY stopbitsChanged)
    Q_PROPERTY(int parity READ parity WRITE setParity NOTIFY parityChanged)

    Q_PROPERTY(bool lightUpperState READ lightUpperState WRITE setLightUpperState NOTIFY lightUpperStateChanged)
    Q_PROPERTY(bool lightBortState READ lightBortState WRITE setLightBortState NOTIFY lightBortStateChanged)
    Q_PROPERTY(bool lightNicheState READ lightNicheState WRITE setLightNicheState NOTIFY lightNicheStateChanged)
    Q_PROPERTY(bool lightDecorState READ lightDecorState WRITE setLightDecorState NOTIFY lightDecorStateChanged)
    Q_PROPERTY(bool lightHallUpperState READ lightHallUpperState WRITE setLightHallUpperState NOTIFY lightHallUpperStateChanged)
    Q_PROPERTY(bool lightHallBortState READ lightHallBortState WRITE setLightHallBortState NOTIFY lightHallBortStateChanged)
    Q_PROPERTY(bool lightHallDecorState READ lightHallDecorState WRITE setLightHallDecorState NOTIFY lightHallDecorStateChanged)

    Q_PROPERTY(bool tvState READ tvState WRITE setTvState NOTIFY tvStateChanged)
    Q_PROPERTY(bool airshowState READ airshowState WRITE setAirshowState NOTIFY airshowStateChanged)
    Q_PROPERTY(bool videocameraState READ videocameraState WRITE setVideocameraState NOTIFY videocameraStateChanged)
    Q_PROPERTY(bool hdmiState READ hdmiState WRITE setHdmiState NOTIFY hdmiStateChanged)
    Q_PROPERTY(int currentVolume READ currentVolume WRITE setCurrentVolume NOTIFY currentVolumeChanged)
    Q_PROPERTY(bool menuDvdState READ menuDvdState WRITE setMenuDvdState NOTIFY menuDvdStateChanged)
    Q_PROPERTY(bool menuAudioState READ menuAudioState WRITE setMenuAudioState NOTIFY menuAudioStateChanged)
    Q_PROPERTY(bool menuVideoState READ menuVideoState WRITE setMenuVideoState NOTIFY menuVideoStateChanged)
    Q_PROPERTY(bool menuUSBState READ menuUSBState WRITE setMenuUSBState NOTIFY menuUSBStateChanged)


    int m_currentZone;
    //Language
    QString m_lang;
    QTranslator *m_translator;
    QString m_qstrUpdateHook = "";
    //App style data
    QString m_textFont;
    QString m_iconFont;
    int m_iconFontH1;
    int m_iconFontH2;
    int m_iconFontH3;
    int m_iconFontH4;
    int m_iconFontH5;
    int m_iconFontH6;
    QString m_bgColor;
    QString m_fgColor;
    QString m_activeBtnClr;
    QString m_inactiveBtnClr;
    QString m_borderMenuBtnClr;
    QString m_barClr;
    //Serial data
    QString m_ttyName;
    int m_baudrate;
    int m_databits;
    int m_stopbits;
    int m_parity;

    int m_currentVolume;
    bool m_tvState;
    bool m_airshowState;
    bool m_videocameraState;
    bool m_hdmiState;
    bool m_menuDvdState;
    bool m_menuAudioState;
    bool m_menuVideoState;
    bool m_menuUSBState;
    bool m_lightUpperState;
    bool m_lightBortState;
    bool m_lightNicheState;
    bool m_lightDecorState;

    QSettings *m_settings;
    static Settings * m_instance;
    QString m_brightnessLevel;
    QTimer * m_brtAutoTimer;

    bool m_lightHallUpperState;
    bool m_lightHallBortState;
    bool m_lightHallDecorState;

protected:
    Settings(QObject *parent = 0);
public:
    enum BrightnessMode { Auto, Manual };
    BrightnessMode m_brtMode;
    static Settings *instance();
    int currentZone() const;
    QString lang() const;
    QString textFont() const;
    QString iconFont() const;
    int iconFontH1() const;
    int iconFontH2() const;
    int iconFontH3() const;
    int iconFontH4() const;
    int iconFontH5() const;
    int iconFontH6() const;
    QString bgColor() const;
    QString fgColor() const;
    QString activeBtnClr() const;
    QString inactiveBtnClr() const;
    QString borderMenuBtnClr() const;
    QString barClr() const;
    QString qstrUpdateHook() const;

    QString ttyName() const
    {
        return m_ttyName;
    }

    int baudrate() const
    {
        return m_baudrate;
    }

    int databits() const
    {
        return m_databits;
    }

    int stopbits() const
    {
        return m_stopbits;
    }

    int parity() const
    {
        return m_parity;
    }

    bool tvState() const
    {
        return m_tvState;
    }

    bool airshowState() const
    {
        return m_airshowState;
    }

    bool videocameraState() const
    {
        return m_videocameraState;
    }

    bool hdmiState() const
    {
        return m_hdmiState;
    }

    int currentVolume() const
    {
        return m_currentVolume;
    }

    bool lightUpperState() const
    {
        return m_lightUpperState;
    }

    bool lightBortState() const
    {
        return m_lightBortState;
    }

    bool lightNicheState() const
    {
        return m_lightNicheState;
    }

    bool lightDecorState() const
    {
        return m_lightDecorState;
    }

    QString brightnessLevel() const
    {
        return m_brightnessLevel;
    }

    bool menuDvdState() const
    {
        return m_menuDvdState;
    }

    bool menuAudioState() const
    {
        return m_menuAudioState;
    }

    bool menuVideoState() const
    {
        return m_menuVideoState;
    }

    bool menuUSBState() const
    {
        return m_menuUSBState;
    }

    BrightnessMode brtMode() const
    {
        return m_brtMode;
    }

    bool isShadow();
    bool isAutoBrightnessMode();
    void sync();
    bool lightHallUpperState() const
    {
        return m_lightHallUpperState;
    }

    bool lightHallBortState() const
    {
        return m_lightHallBortState;
    }

    bool lightHallDecorState() const
    {
        return m_lightHallDecorState;
    }

public slots:
    void setCurrentZone(int currentZone);
    void setLang(QString lang);
    void setQstrUpdateHook(QString qstrUpdateHook);
    void setTextFont(QString textFont);
    void setIconFont(QString iconFont);
    void setIconFontH1(int iconFontH1);
    void setIconFontH2(int iconFontH2);
    void setIconFontH3(int iconFontH3);
    void setIconFontH4(int iconFontH4);
    void setIconFontH5(int iconFontH5);
    void setIconFontH6(int iconFontH6);
    void setBgColor(QString bgColor);
    void setFgColor(QString fgColor);
    void setActiveBtnClr(QString activeBtnClr);
    void setInactiveBtnClr(QString inactiveBtnClr);
    void setBorderMenuBtnClr(QString borderMenuBtnClr);
    void setBarClr(QString barClr);
    void setTtyName(QString ttyName);
    void setBaudrate(int baudrate);
    void setDatabits(int databits);
    void setStopbits(int stopbits);
    void setParity(int parity);

    void setHdmiState(bool hdmiState);
    void setCurrentVolume(int currentVolume);
    void setTvState(bool tvOnState);
    void setAirshowState(bool airshowState);
    void setVideocameraState(bool videocameraState);
    void setLightUpperState(bool lightUpperState);
    void setLightBortState(bool lightBortState);
    void setLightNicheState(bool lightNicheState);
    void setLightDecorState(bool lightDecorState);
    void setMenuDvdState(bool menuDvdState);
    void setMenuAudioState(bool menuAudioState);
    void setMenuVideoState(bool menuVideoState);
    void setMenuUSBState(bool menuUSBState);
    void applyBrightness(QString brightnessLevel);
    void applyLanguage();
    void askBPLanguage(SerialDevice *sd);
    void askBPVolume(SerialDevice *sd);
    void askMsopState(SerialDevice *sd);

    void setBrightnessLevel(QString brightnessLevel);
    void setBrtMode(BrightnessMode brtMode);
    void autoReduceBrightness();
    void runAutoBrightnessMode();
    void setLightHallUpperState(bool lightHallUpperState)
    {
        if (m_lightHallUpperState == lightHallUpperState)
            return;

        m_lightHallUpperState = lightHallUpperState;
        emit lightHallUpperStateChanged(m_lightHallUpperState);
    }

    void setLightHallBortState(bool lightHallBortState)
    {
        if (m_lightHallBortState == lightHallBortState)
            return;

        m_lightHallBortState = lightHallBortState;
        emit lightHallBortStateChanged(m_lightHallBortState);
    }

    void setLightHallDecorState(bool lightHallDecorState)
    {
        if (m_lightHallDecorState == lightHallDecorState)
            return;

        m_lightHallDecorState = lightHallDecorState;
        emit lightHallDecorStateChanged(m_lightHallDecorState);
    }

signals:
    void currentZoneChanged(int currentZone);

    void langChanged(QString lang);
    void brightnessLevelChanged(QString brightnessLevel);
    void qstrUpdateHookChanged(QString qstrUpdateHook);
    void textFontChanged(QString textFont);
    void iconFontChanged(QString iconFont);

    void iconFontH1Changed(int iconFontH1);
    void iconFontH2Changed(int iconFontH2);
    void iconFontH3Changed(int iconFontH3);
    void iconFontH4Changed(int iconFontH4);
    void iconFontH5Changed(int iconFontH5);
    void iconFontH6Changed(int iconFontH6);
    void bgColorChanged(QString bgColor);
    void fgColorChanged(QString fgColor);

    void activeBtnClrChanged(QString activeBtnClr);
    void inactiveBtnClrChanged(QString inactiveBtnClr);
    void borderMenuBtnClrChanged(QString borderMenuBtnClr);
    void barClrChanged(QString barClr);
    void ttyNameChanged(QString ttyName);
    void baudrateChanged(int baudrate);
    void databitsChanged(int databits);
    void stopbitsChanged(int stopbits);
    void parityChanged(int parity);

    void tvStateChanged(bool tvOnState);
    void airshowStateChanged(bool airshowState);
    void videocameraStateChanged(bool videcameraState);
    void hdmiStateChanged(bool hdmiState);
    void menuDvdStateChanged(bool menuDvdState);
    void menuAudioStateChanged(bool menuAudioState);
    void menuVideoStateChanged(bool menuVideoState);
    void menuUSBStateChanged(bool menuUSBState);
    void currentVolumeChanged(int currentVolume);
    void lightUpperStateChanged(bool lightUpperState);
    void lightBortStateChanged(bool lightBortState);
    void lightNicheStateChanged(bool lightNicheState);
    void lightDecorStateChanged(bool lightDecorState);
    void brtModeChanged(BrightnessMode brtMode);
    void lightHallUpperStateChanged(bool lightHallUpperState);
    void lightHallBortStateChanged(bool lightHallBortState);
    void lightHallDecorStateChanged(bool lightHallDecorState);
};

#endif // SETTINGS_H
