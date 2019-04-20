#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QTranslator>

class SettingsManager : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString language READ language WRITE setLanguage NOTIFY languageChanged)

    Q_PROPERTY(int iconFontH1 READ iconFontH1 WRITE setIconFontH1 NOTIFY iconFontH1Changed)
    Q_PROPERTY(int iconFontH2 READ iconFontH2 WRITE setIconFontH2 NOTIFY iconFontH2Changed)
    Q_PROPERTY(int iconFontH3 READ iconFontH3 WRITE setIconFontH3 NOTIFY iconFontH3Changed)
    Q_PROPERTY(int iconFontH4 READ iconFontH4 WRITE setIconFontH4 NOTIFY iconFontH4Changed)
    Q_PROPERTY(int iconFontH5 READ iconFontH5 WRITE setIconFontH5 NOTIFY iconFontH5Changed)

    Q_PROPERTY(int textFontH1 READ textFontH1 WRITE setTextFontH1 NOTIFY textFontH1Changed)
    Q_PROPERTY(int textFontH2 READ textFontH2 WRITE setTextFontH2 NOTIFY textFontH2Changed)
    Q_PROPERTY(int textFontH3 READ textFontH3 WRITE setTextFontH3 NOTIFY textFontH3Changed)
    Q_PROPERTY(int textFontH4 READ textFontH4 WRITE setTextFontH4 NOTIFY textFontH4Changed)
    Q_PROPERTY(int textFontH5 READ textFontH5 WRITE setTextFontH5 NOTIFY textFontH5Changed)

    Q_PROPERTY(QString fgInactiveColor READ fgInactiveColor WRITE setFgInactiveColor NOTIFY fgInactiveColorChanged)
    Q_PROPERTY(QString bgInactiveColor READ bgInactiveColor WRITE setBgInactiveColor NOTIFY bgInactiveColorChanged)
    Q_PROPERTY(QString fgActiveColor READ fgActiveColor WRITE setFgActiveColor NOTIFY fgActiveColorChanged)
    Q_PROPERTY(QString fgActiveTextColor READ fgActiveTextColor WRITE setFgActiveTextColor NOTIFY fgActiveTextColorChanged)

    Q_PROPERTY(QString textFont READ textFont WRITE setTextFont NOTIFY textFontChanged)
    Q_PROPERTY(QString iconFont READ iconFont WRITE setIconFont NOTIFY iconFontChanged)

    Q_PROPERTY(QString tsStr READ tsStr WRITE setTsStr NOTIFY tsStrChanged)

    Q_PROPERTY(int password READ password WRITE setPassword NOTIFY passwordChanged)

    Q_PROPERTY(QString audioRootPath READ audioRootPath WRITE setAudioRootPath NOTIFY audioRootPathChanged)
    Q_PROPERTY(QString videoRootPath READ videoRootPath WRITE setVideoRootPath NOTIFY videoRootPathChanged)
    Q_PROPERTY(QString infoRootPath READ infoRootPath WRITE setInfoRootPath NOTIFY infoRootPathChanged)
    Q_PROPERTY(QString gameRootPath READ gameRootPath WRITE setGameRootPath NOTIFY gameRootPathChanged)
    Q_PROPERTY(QString helpRootPath READ helpRootPath WRITE setHelpRootPath NOTIFY helpRootPathChanged)
    Q_PROPERTY(QString specRootPath READ specRootPath WRITE setSpecRootPath NOTIFY specRootPathChanged)
    Q_PROPERTY(QString airshowRootPath READ airshowRootPath WRITE setAirshowRootPath NOTIFY airshowRootPathChanged)

    Q_PROPERTY(QString camcorderSource READ camcorderSource WRITE setCamcorderSource NOTIFY camcorderSourceChanged)

    Q_PROPERTY(int gameVolume READ gameVolume WRITE setGameVolume NOTIFY gameVolumeChanged)
    Q_PROPERTY(int audioVolume READ audioVolume WRITE setAudioVolume NOTIFY audioVolumeChanged)
    Q_PROPERTY(int videoVolume READ videoVolume WRITE setVideoVolume NOTIFY videoVolumeChanged)
    Q_PROPERTY(int screenBrightness READ screenBrightness WRITE setScreenBrightness NOTIFY screenBrightnessChanged)

    Q_PROPERTY(int specServerPort READ specServerPort WRITE setSpecServerPort NOTIFY specServerPortChanged)

    Q_PROPERTY(QString airshowServerIP READ airshowServerIP WRITE setAirshowServerIP NOTIFY airshowServerIPChanged)
    Q_PROPERTY(int airshowServerPort READ airshowServerPort WRITE setAirshowServerPort NOTIFY airshowServerPortChanged)
    Q_PROPERTY(int airshowImgSwitchMs READ airshowImgSwitchMs WRITE setAirshowImgSwitchMs NOTIFY airshowImgSwitchMsChanged)
    Q_PROPERTY(int airshowImgUpdateMs READ airshowImgUpdateMs WRITE setAirshowImgUpdateMs NOTIFY airshowImgUpdateMsChanged)

    QString m_language;

    QString m_textFont;
    QString m_iconFont;

    QTranslator *m_translator;
    QString m_tsStr;

    int m_iconFontH1;
    int m_iconFontH2;
    int m_iconFontH3;
    int m_iconFontH4;
    int m_iconFontH5;

    int m_textFontH1;
    int m_textFontH2;
    int m_textFontH3;
    int m_textFontH4;
    int m_textFontH5;

    QString m_fgInactiveColor;
    QString m_bgInactiveColor;
    QString m_fgActiveColor;
    QString m_fgActiveTextColor;

    QString m_audioRootPath;
    QString m_videoRootPath;
    QString m_infoRootPath;
    QString m_gameRootPath;
    QString m_helpRootPath;
    QString m_specRootPath;
    QString m_airshowRootPath;
    QString m_camcorderSource;

    int m_gameVolume;
    int m_audioVolume;
    int m_videoVolume;
    int m_screenBrightness;

    int m_password;

    QString m_airshowServerIP;
    int m_airshowServerPort;
    int m_airshowImgSwitchMs;
    int m_airshowImgUpdateMs;

    int m_specServerPort;

public:
    explicit SettingsManager(QObject *parent = 0);

    QString language() const;

    QString textFont() const;
    QString iconFont() const;

    QString tsStr() const;

    int password() const;

    int iconFontH1() const;
    int iconFontH2() const;
    int iconFontH3() const;
    int iconFontH4() const;
    int iconFontH5() const;

    int textFontH1() const;
    int textFontH2() const;
    int textFontH3() const;
    int textFontH4() const;
    int textFontH5() const;

    QString fgInactiveColor() const;
    QString bgInactiveColor() const;
    QString fgActiveColor() const;
    QString fgActiveTextColor() const;

    QString audioRootPath() const;
    QString videoRootPath() const;
    QString infoRootPath() const;
    QString gameRootPath() const;
    QString helpRootPath() const;
    QString specRootPath() const;
    QString airshowRootPath() const;
    QString camcorderSource() const;

    int gameVolume() const;
    int audioVolume() const;
    int videoVolume() const;
    int screenBrightness() const;

    QString airshowServerIP() const;
    int airshowServerPort() const;
    int airshowImgSwitchMs() const;
    int airshowImgUpdateMs() const;

    int specServerPort() const;

signals:
    void languageChanged(QString language);

    void textFontChanged(QString textFont);
    void iconFontChanged(QString iconFont);

    void tsStrChanged(QString tsStr);

    void passwordChanged(int password);

    void iconFontH1Changed(int iconFontH1);
    void iconFontH2Changed(int iconFontH2);
    void iconFontH3Changed(int iconFontH3);
    void iconFontH4Changed(int iconFontH4);
    void iconFontH5Changed(int iconFontH5);

    void textFontH1Changed(int textFontH1);
    void textFontH2Changed(int textFontH2);
    void textFontH3Changed(int textFontH3);
    void textFontH4Changed(int textFontH4);
    void textFontH5Changed(int textFontH5);

    void fgInactiveColorChanged(QString fgInactiveColor);
    void bgInactiveColorChanged(QString bgInactiveColor);
    void fgActiveColorChanged(QString fgActiveColor);
    void fgActiveTextColorChanged(QString fgActiveTextColor);

    void audioRootPathChanged(QString audioRootPath);
    void videoRootPathChanged(QString videoRootPath);
    void infoRootPathChanged(QString infoRootPath);
    void gameRootPathChanged(QString gameRootPath);
    void helpRootPathChanged(QString helpRootPath);
    void specRootPathChanged(QString specRootPath);
    void airshowRootPathChanged(QString airshowRootPath);
    void camcorderSourceChanged(QString camcorderSource);

    void gameVolumeChanged(int gameVolume);
    void audioVolumeChanged(int audioVolume);
    void videoVolumeChanged(int videoVolume);
    void screenBrightnessChanged(int screenBrightness);

    void airshowServerIPChanged(QString airshowServerIP);
    void airshowServerPortChanged(int airshowServerPort);
    void airshowImgSwitchMsChanged(int airshowImgSwitchMs);
    void airshowImgUpdateMsChanged(int airshowImgUpdateMs);

    void specServerPortChanged(int specServerPort);

public slots:
    void save(void);
    void recreate(void);

    void apllyTranslation(void);
    void requestToChangeLanguage(QString language);

    void setLanguage(QString language);

    void setTextFont(QString textFont);
    void setIconFont(QString iconFont);

    void setTsStr(QString tsStr);

    void setPassword(int password);

    void setIconFontH1(int iconFontH1);
    void setIconFontH2(int iconFontH2);
    void setIconFontH3(int iconFontH3);
    void setIconFontH4(int iconFontH4);
    void setIconFontH5(int iconFontH5);

    void setTextFontH1(int textFontH1);
    void setTextFontH2(int textFontH2);
    void setTextFontH3(int textFontH3);
    void setTextFontH4(int textFontH4);
    void setTextFontH5(int textFontH5);

    void setFgInactiveColor(QString fgInactiveColor);
    void setBgInactiveColor(QString bgInactiveColor);
    void setFgActiveColor(QString fgActiveColor);
    void setFgActiveTextColor(QString fgActiveTextColor);

    void setAudioRootPath(QString audioRootPath);
    void setVideoRootPath(QString videoRootPath);
    void setInfoRootPath(QString infoRootPath);
    void setGameRootPath(QString gameRootPath);
    void setHelpRootPath(QString helpRootPath);
    void setSpecRootPath(QString specRootPath);
    void setAirshowRootPath(QString airshowRootPath);
    void setCamcorderSource(QString camcorderSource);

    void setGameVolume(int gameVolume);
    void setAudioVolume(int audioVolume);
    void setVideoVolume(int videoVolume);
    void setScreenBrightness(int screenBrightness);

    void setAirshowServerIP(QString airshowServerIP);
    void setAirshowServerPort(int airshowServerPort);
    void setAirshowImgSwitchMs(int airshowImgSwitchMs);
    void setAirshowImgUpdateMs(int airshowImgUpdateMs);
    void setSpecServerPort(int specServerPort);
};
#endif // SETTINGS_H
