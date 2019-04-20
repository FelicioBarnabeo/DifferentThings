#ifndef CONFIGURATOR_H
#define CONFIGURATOR_H

#include <QObject>

class Configurator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString addressDevice READ addressDevice WRITE setAddressDevice NOTIFY addressDeviceChanged)
    Q_PROPERTY(QString localAddressDevice READ localAddressDevice WRITE setLocalAddressDevice NOTIFY localAddressDeviceChanged)
    Q_PROPERTY(QString msopLocalAnswer READ msopLocalAnswer WRITE setMsopLocalAnswer NOTIFY msopLocalAnswerChanged)
    Q_PROPERTY(QString menuLight READ menuLight WRITE setMenuLight NOTIFY menuLightChanged)
    Q_PROPERTY(QString menuShaders READ menuShaders WRITE setMenuShaders NOTIFY menuShadersChanged)
    Q_PROPERTY(QString menuEntertainment READ menuEntertainment WRITE setMenuEntertainment NOTIFY menuEntertainmentChanged)
    Q_PROPERTY(QString menuDvdBluRay READ menuDvdBluRay WRITE setMenuDvdBluRay NOTIFY menuDvdBluRayChanged)
    Q_PROPERTY(QString menuUsb READ menuUsb WRITE setMenuUsb NOTIFY menuUsbChanged)
    Q_PROPERTY(QString menuVideo READ menuVideo WRITE setMenuVideo NOTIFY menuVideoChanged)
    Q_PROPERTY(QString menuAudio READ menuAudio WRITE setMenuAudio NOTIFY menuAudioChanged)
    Q_PROPERTY(QString menuKaraoke READ menuKaraoke WRITE setMenuKaraoke NOTIFY menuKaraokeChanged)

    Q_PROPERTY(QString videocamera READ videocamera WRITE setVideocamera NOTIFY videocameraChanged)
    Q_PROPERTY(QString airshow READ airshow WRITE setAirshow NOTIFY airshowChanged)

    Q_PROPERTY(QString dvdUp READ dvdUp WRITE setDvdUp NOTIFY dvdUpChanged)
    Q_PROPERTY(QString dvdDown READ dvdDown WRITE setDvdDown NOTIFY dvdDownChanged)
    Q_PROPERTY(QString dvdRight READ dvdRight WRITE setDvdRight NOTIFY dvdRightChanged)
    Q_PROPERTY(QString dvdLeft READ dvdLeft WRITE setDvdLeft NOTIFY dvdLeftChanged)
    Q_PROPERTY(QString dvdOk READ dvdOk WRITE setDvdOk NOTIFY dvdOkChanged)
    Q_PROPERTY(QString dvdVolumeUp READ dvdVolumeUp WRITE setDvdVolumeUp NOTIFY dvdVolumeUpChanged)
    Q_PROPERTY(QString dvdVolumeDown READ dvdVolumeDown WRITE setDvdVolumeDown NOTIFY dvdVolumeDownChanged)
    Q_PROPERTY(QString dvdPause READ dvdPause WRITE setDvdPause NOTIFY dvdPauseChanged)
    Q_PROPERTY(QString dvdStop READ dvdStop WRITE setDvdStop NOTIFY dvdStopChanged)
    Q_PROPERTY(QString dvdRewind READ dvdRewind WRITE setDvdRewind NOTIFY dvdRewindChanged)
    Q_PROPERTY(QString dvdForward READ dvdForward WRITE setDvdForward NOTIFY dvdForwardChanged)
    Q_PROPERTY(QString dvdFastForward READ dvdFastForward WRITE setDvdFastForward NOTIFY dvdFastForwardChanged)
    Q_PROPERTY(QString dvdFastRewind READ dvdFastRewind WRITE setDvdFastRewind NOTIFY dvdFastRewindChanged)
    Q_PROPERTY(QString dvdPlay READ dvdPlay WRITE setDvdPlay NOTIFY dvdPlayChanged)
    Q_PROPERTY(QString dvdEject READ dvdEject WRITE setDvdEject NOTIFY dvdEjectChanged)
    Q_PROPERTY(QString dvdDiskMenu READ dvdDiskMenu WRITE setDvdDiskMenu NOTIFY dvdDiskMenuChanged)

    Q_PROPERTY(QString avuUp   READ avuUp WRITE setAvuUp NOTIFY avuUpChanged)
    Q_PROPERTY(QString avuDown READ avuDown WRITE setAvuDown NOTIFY avuDownChanged)
    Q_PROPERTY(QString avuRight READ avuRight WRITE setAvuRight NOTIFY avuRightChanged)
    Q_PROPERTY(QString avuLeft READ avuLeft WRITE setAvuLeft NOTIFY avuLeftChanged)
    Q_PROPERTY(QString avuOk   READ avuOk WRITE setAvuOk NOTIFY avuOkChanged)
    Q_PROPERTY(QString avuVolumeUp READ avuVolumeUp WRITE setAvuVolumeUp NOTIFY avuVolumeUpChanged)
    Q_PROPERTY(QString avuVolumeDown READ avuVolumeDown WRITE setAvuVolumeDown NOTIFY avuVolumeDownChanged)
    Q_PROPERTY(QString avuPause READ avuPause WRITE setAvuPause NOTIFY avuPauseChanged)
    Q_PROPERTY(QString avuStop READ avuStop WRITE setAvuStop NOTIFY avuStopChanged)
    Q_PROPERTY(QString avuRewind READ avuRewind WRITE setAvuRewind NOTIFY avuRewindChanged)
    Q_PROPERTY(QString avuForward READ avuForward WRITE setAvuForward NOTIFY avuForwardChanged)
    Q_PROPERTY(QString avuFastForward READ avuFastForward WRITE setAvuFastForward NOTIFY avuFastForwardChanged)
    Q_PROPERTY(QString avuFastRewind READ avuFastRewind WRITE setAvuFastRewind NOTIFY avuFastRewindChanged)
    Q_PROPERTY(QString avuPlay READ avuPlay WRITE setAvuPlay NOTIFY avuPlayChanged)
    Q_PROPERTY(QString avuSlideShow READ avuSlideShow WRITE setAvuSlideShow NOTIFY avuSlideShowChanged)

    Q_PROPERTY(QString getCurrentVolume READ getCurrentVolume WRITE setGetCurrentVolume NOTIFY getCurrentVolumeChanged)
    Q_PROPERTY(QString currentVolume READ currentVolume WRITE setCurrentVolume NOTIFY currentVolumeChanged)
    Q_PROPERTY(QString getCurrentState READ getCurrentState WRITE setGetCurrentState NOTIFY getCurrentStateChanged)
    Q_PROPERTY(QString currentState READ currentState WRITE setCurrentState NOTIFY currentStateChanged)
    Q_PROPERTY(QString askDirectState READ askDirectState WRITE setAskDirectState NOTIFY askDirectStateChanged)
    Q_PROPERTY(QString commandComplete READ commandComplete WRITE setCommandComplete NOTIFY commandCompleteChanged)
    Q_PROPERTY(QString getCurrentLanguage READ getCurrentLanguage WRITE setGetCurrentLanguage NOTIFY getCurrentLanguageChanged)
    Q_PROPERTY(QString currentLanguageRU READ currentLanguageRU WRITE setCurrentLanguageRU NOTIFY currentLanguageRUChanged)
    Q_PROPERTY(QString currentLanguageENG READ currentLanguageENG WRITE setCurrentLanguageENG NOTIFY currentLanguageENGChanged)
    Q_PROPERTY(QString stateDvdBluray READ stateDvdBluray WRITE setStateDvdBluray NOTIFY stateDvdBlurayChanged)
    Q_PROPERTY(QString stateUSB READ stateUSB WRITE setStateUSB NOTIFY stateUSBChanged)
    Q_PROPERTY(QString stateVideo READ stateVideo WRITE setStateVideo NOTIFY stateVideoChanged)
    Q_PROPERTY(QString stateAudio READ stateAudio WRITE setStateAudio NOTIFY stateAudioChanged)
    Q_PROPERTY(QString stateVideocamera READ stateVideocamera WRITE setStateVideocamera NOTIFY stateVideocameraChanged)
    Q_PROPERTY(QString stateAirshow READ stateAirshow WRITE setStateAirshow NOTIFY stateAirshowChanged)
    Q_PROPERTY(QString currentVolume0 READ currentVolume0 WRITE setCurrentVolume0 NOTIFY currentVolume0Changed)
    Q_PROPERTY(QString currentVolume1 READ currentVolume1 WRITE setCurrentVolume1 NOTIFY currentVolume1Changed)
    Q_PROPERTY(QString currentVolume2 READ currentVolume2 WRITE setCurrentVolume2 NOTIFY currentVolume2Changed)
    Q_PROPERTY(QString currentVolume3 READ currentVolume3 WRITE setCurrentVolume3 NOTIFY currentVolume3Changed)
    Q_PROPERTY(QString currentVolume4 READ currentVolume4 WRITE setCurrentVolume4 NOTIFY currentVolume4Changed)
    Q_PROPERTY(QString currentVolume5 READ currentVolume5 WRITE setCurrentVolume5 NOTIFY currentVolume5Changed)
    Q_PROPERTY(QString currentVolume6 READ currentVolume6 WRITE setCurrentVolume6 NOTIFY currentVolume6Changed)
    Q_PROPERTY(QString currentVolume7 READ currentVolume7 WRITE setCurrentVolume7 NOTIFY currentVolume7Changed)
    Q_PROPERTY(QString currentVolume8 READ currentVolume8 WRITE setCurrentVolume8 NOTIFY currentVolume8Changed)
    Q_PROPERTY(QString currentVolume9 READ currentVolume9 WRITE setCurrentVolume9 NOTIFY currentVolume9Changed)
    Q_PROPERTY(QString currentVolume10 READ currentVolume10 WRITE setCurrentVolume10 NOTIFY currentVolume10Changed)
    Q_PROPERTY(QString outVlm READ outVlm WRITE setOutVlm NOTIFY outVlmChanged)

    Q_PROPERTY(QString tvOn READ tvOn WRITE setTvOn NOTIFY tvOnChanged)
    Q_PROPERTY(QString tvOff READ tvOff WRITE setTvOff NOTIFY tvOffChanged)
    Q_PROPERTY(QString hdmiOn READ hdmiOn WRITE setHdmiOn NOTIFY hdmiOnChanged)
    Q_PROPERTY(QString hdmiOff READ hdmiOff WRITE setHdmiOff NOTIFY hdmiOffChanged)
    Q_PROPERTY(QString lightUpperOn READ lightUpperOn WRITE setLightUpperOn NOTIFY lightUpperOnChanged)
    Q_PROPERTY(QString lightUpperOff READ lightUpperOff WRITE setLightUpperOff NOTIFY lightUpperOffChanged)
    Q_PROPERTY(QString lightBortOn READ lightBortOn WRITE setLightBortOn NOTIFY lightBortOnChanged)
    Q_PROPERTY(QString lightBortOff READ lightBortOff WRITE setLightBortOff NOTIFY lightBortOffChanged)
    Q_PROPERTY(QString lightOverBedOn READ lightOverBedOn WRITE setLightOverBedOn NOTIFY lightOverBedOnChanged)
    Q_PROPERTY(QString lightOverBedOff READ lightOverBedOff WRITE setLightOverBedOff NOTIFY lightOverBedOffChanged)
    Q_PROPERTY(QString lightDecorOn READ lightDecorOn WRITE setLightDecorOn NOTIFY lightDecorOnChanged)
    Q_PROPERTY(QString lightDecorOff READ lightDecorOff WRITE setLightDecorOff NOTIFY lightDecorOffChanged)

    Q_PROPERTY(QString tvDirectOn READ tvDirectOn WRITE setTvDirectOn NOTIFY tvDirectOnChanged)
    Q_PROPERTY(QString tvDirectOff READ tvDirectOff WRITE setTvDirectOff NOTIFY tvDirectOffChanged)
    Q_PROPERTY(QString hdmiDirectOn READ hdmiDirectOn WRITE setHdmiDirectOn NOTIFY hdmiDirectOnChanged)
    Q_PROPERTY(QString hdmiDirectOff READ hdmiDirectOff WRITE setHdmiDirectOff NOTIFY hdmiDirectOffChanged)
    Q_PROPERTY(QString lightDirectUpperOn READ lightDirectUpperOn WRITE setLightDirectUpperOn NOTIFY lightDirectUpperOnChanged)
    Q_PROPERTY(QString lightDirectUpperOff READ lightDirectUpperOff WRITE setLightDirectUpperOff NOTIFY lightDirectUpperOffChanged)
    Q_PROPERTY(QString lightDirectBortOn READ lightDirectBortOn WRITE setLightDirectBortOn NOTIFY lightDirectBortOnChanged)
    Q_PROPERTY(QString lightDirectBortOff READ lightDirectBortOff WRITE setLightDirectBortOff NOTIFY lightDirectBortOffChanged)
    Q_PROPERTY(QString lightDirectOverBedOn READ lightDirectOverBedOn WRITE setLightDirectOverBedOn NOTIFY lightDirectOverBedOnChanged)
    Q_PROPERTY(QString lightDirectOverBedOff READ lightDirectOverBedOff WRITE setLightDirectOverBedOff NOTIFY lightDirectOverBedOffChanged)
    Q_PROPERTY(QString lightDirectDecorOn READ lightDirectDecorOn WRITE setLightDirectDecorOn NOTIFY lightDirectDecorOnChanged)
    Q_PROPERTY(QString lightDirectDecorOff READ lightDirectDecorOff WRITE setLightDirectDecorOff NOTIFY lightDirectDecorOffChanged)
    Q_PROPERTY(QString lightHallUpperOn READ lightHallUpperOn WRITE setLightHallUpperOn NOTIFY lightHallUpperOnChanged)
    Q_PROPERTY(QString lightHallUpperOff READ lightHallUpperOff WRITE setLightHallUpperOff NOTIFY lightHallUpperOffChanged)
    Q_PROPERTY(QString lightHallBortOn READ lightHallBortOn WRITE setLightHallBortOn NOTIFY lightHallBortOnChanged)
    Q_PROPERTY(QString lightHallBortOff READ lightHallBortOff WRITE setLightHallBortOff NOTIFY lightHallBortOffChanged)
    Q_PROPERTY(QString lightHallDirectUpperOn READ lightHallDirectUpperOn WRITE setLightHallDirectUpperOn NOTIFY lightHallDirectUpperOnChanged)
    Q_PROPERTY(QString lightHallDirectUpperOff READ lightHallDirectUpperOff WRITE setLightHallDirectUpperOff NOTIFY lightHallDirectUpperOffChanged)
    Q_PROPERTY(QString lightHallDirectBortOn READ lightHallDirectBortOn WRITE setLightHallDirectBortOn NOTIFY lightHallDirectBortOnChanged)
    Q_PROPERTY(QString lightHallDirectBortOff READ lightHallDirectBortOff WRITE setLightHallDirectBortOff NOTIFY lightHallDirectBortOffChanged)

    Q_PROPERTY(QString shadesOpenStart READ shadesOpenStart WRITE setShadesOpenStart NOTIFY shadesOpenStartChanged)
    Q_PROPERTY(QString shadesOpenEnd READ shadesOpenEnd WRITE setShadesOpenEnd NOTIFY shadesOpenEndChanged)
    Q_PROPERTY(QString shadesCloseStart READ shadesCloseStart WRITE setShadesCloseStart NOTIFY shadesCloseStartChanged)
    Q_PROPERTY(QString shadesCloseEnd READ shadesCloseEnd WRITE setShadesCloseEnd NOTIFY shadesCloseEndChanged)
    Q_PROPERTY(QString shadesBathOpenStart READ shadesBathOpenStart WRITE setShadesBathOpenStart NOTIFY shadesBathOpenStartChanged)
    Q_PROPERTY(QString shadesBathOpenEnd READ shadesBathOpenEnd WRITE setShadesBathOpenEnd NOTIFY shadesBathOpenEndChanged)
    Q_PROPERTY(QString shadesBathCloseStart READ shadesBathCloseStart WRITE setShadesBathCloseStart NOTIFY shadesBathCloseStartChanged)
    Q_PROPERTY(QString shadesBathCloseEnd READ shadesBathCloseEnd WRITE setShadesBathCloseEnd NOTIFY shadesBathCloseEndChanged)

    int m_currentZone;
    QString m_addressDevice;
    QString m_localAddressDevice;

    QString m_menuLight;
    QString m_menuShaders;
    QString m_menuEntertainment;    
    QString m_menuDvdBluRay;
    QString m_menuUsb;
    QString m_menuVideo;
    QString m_menuAudio;
    QString m_menuKaraoke;

    QString m_videocamera;
    QString m_airshow;

    QString m_tvOn;
    QString m_tvOff;
    QString m_hdmiOn;
    QString m_hdmiOff;
    QString m_tvDirectOn;
    QString m_tvDirectOff;
    QString m_hdmiDirectOn;
    QString m_hdmiDirectOff;

    QString m_dvdUp;
    QString m_dvdDown;
    QString m_dvdRight;
    QString m_dvdLeft;
    QString m_dvdOk;
    QString m_dvdVolumeUp;
    QString m_dvdVolumeDown;
    QString m_dvdPause;
    QString m_dvdStop;
    QString m_dvdRewind;
    QString m_dvdForward;
    QString m_dvdFastForward;
    QString m_dvdFastRewind;
    QString m_dvdPlay;
    QString m_dvdEject;
    QString m_dvdDiskMenu;

    QString m_avuUp;
    QString m_avuDown;
    QString m_avuRight;
    QString m_avuLeft;
    QString m_avuOk;
    QString m_avuVolumeUp;
    QString m_avuVolumeDown;
    QString m_avuPause;
    QString m_avuStop;
    QString m_avuRewind;
    QString m_avuForward;
    QString m_avuFastForward;
    QString m_avuFastRewind;
    QString m_avuPlay;
    QString m_avuSlideShow;

    QString m_getCurrentVolume;
    QString m_currentVolume;      //in (answer bp1 to pzu#)
    QString m_getCurrentState;
    QString m_currentState;       //in
    QString m_askDirectState;
    QString m_commandComplete;    //in
    QString m_getCurrentLanguage;
    QString m_currentLanguageRU;  //in
    QString m_currentLanguageENG; //in
    QString m_stateDvdBluray;     //in
    QString m_stateUSB;           //in
    QString m_stateVideo;         //in
    QString m_stateAudio;         //in
    QString m_stateVideocamera;   //in
    QString m_stateAirshow;       //in

    QString m_lightUpperOn;
    QString m_lightUpperOff;
    QString m_lightBortOn;
    QString m_lightBortOff;
    QString m_lightOverBedOn;
    QString m_lightOverBedOff;
    QString m_lightDecorOn;
    QString m_lightDecorOff;
    QString m_lightDirectUpperOn;
    QString m_lightDirectUpperOff;
    QString m_lightDirectBortOn;
    QString m_lightDirectBortOff;
    QString m_lightDirectOverBedOn;
    QString m_lightDirectOverBedOff;
    QString m_lightDirectDecorOn;
    QString m_lightDirectDecorOff;
    bool m_HallSwitched;

    QString m_shadesOpenStart;
    QString m_shadesOpenEnd;
    QString m_shadesCloseStart;
    QString m_shadesCloseEnd;
    QString m_shadesBathOpenStart;
    QString m_shadesBathOpenEnd;
    QString m_shadesBathCloseStart;
    QString m_shadesBathCloseEnd;

    QString m_currentVolume1;
    QString m_currentVolume2;
    QString m_currentVolume3;
    QString m_currentVolume4;
    QString m_currentVolume5;
    QString m_currentVolume6;
    QString m_currentVolume7;
    QString m_currentVolume8;
    QString m_currentVolume9;
    QString m_currentVolume10;
    QString m_currentVolume0;
    QString m_outVlm;
    static Configurator *m_instance;
    void init();

    QString m_msopLocalAnswer;

    QString m_lightHallUpperOn;

    QString m_lightHallUpperOff;

QString m_lightHallBortOn;

QString m_lightHallBortOff;

QString m_lightHallDirectUpperOn;

QString m_lightHallDirectUpperOff;

QString m_lightHallDirectBortOn;

QString m_lightHallDirectBortOff;

protected:
    Configurator(QObject *parent = 0);

public:
    static Configurator *instance();
    bool hallSwitched() const
    {
        return m_HallSwitched;
    }
    QString addressDevice() const
    {
        return m_addressDevice;
    }
    QString localAddressDevice() const
    {
        return m_localAddressDevice;
    }
    QString menuLight() const
    {
        return m_menuLight;
    }

    QString menuShaders() const
    {
        return m_menuShaders;
    }

    QString menuEntertainment() const
    {
        return m_menuEntertainment;
    }


    QString menuDvdBluRay() const
    {
        return m_menuDvdBluRay;
    }

    QString menuUsb() const
    {
        return m_menuUsb;
    }

    QString menuVideo() const
    {
        return m_menuVideo;
    }

    QString menuAudio() const
    {
        return m_menuAudio;
    }

    QString videocamera() const
    {
        return m_videocamera;
    }

    QString airshow() const
    {
        return m_airshow;
    }

    QString dvdUp() const
    {
        return m_dvdUp;
    }

    QString dvdDown() const
    {
        return m_dvdDown;
    }

    QString dvdRight() const
    {
        return m_dvdRight;
    }

    QString dvdLeft() const
    {
        return m_dvdLeft;
    }

    QString dvdOk() const
    {
        return m_dvdOk;
    }

    QString dvdVolumeUp() const
    {
        return m_dvdVolumeUp;
    }

    QString dvdVolumeDown() const
    {
        return m_dvdVolumeDown;
    }

    QString dvdPause() const
    {
        return m_dvdPause;
    }

    QString dvdStop() const
    {
        return m_dvdStop;
    }

    QString dvdRewind() const
    {
        return m_dvdRewind;
    }

    QString dvdForward() const
    {
        return m_dvdForward;
    }

    QString dvdFastForward() const
    {
        return m_dvdFastForward;
    }

    QString dvdFastRewind() const
    {
        return m_dvdFastRewind;
    }

    QString dvdPlay() const
    {
        return m_dvdPlay;
    }

    QString dvdEject() const
    {
        return m_dvdEject;
    }

    QString dvdDiskMenu() const
    {
        return m_dvdDiskMenu;
    }

    QString avuUp() const
    {
        return m_avuUp;
    }

    QString avuDown() const
    {
        return m_avuDown;
    }

    QString avuRight() const
    {
        return m_avuRight;
    }

    QString avuLeft() const
    {
        return m_avuLeft;
    }

    QString avuOk() const
    {
        return m_avuOk;
    }

    QString avuVolumeUp() const
    {
        return m_avuVolumeUp;
    }

    QString avuVolumeDown() const
    {
        return m_avuVolumeDown;
    }

    QString avuPause() const
    {
        return m_avuPause;
    }

    QString avuStop() const
    {
        return m_avuStop;
    }

    QString avuRewind() const
    {
        return m_avuRewind;
    }

    QString avuForward() const
    {
        return m_avuForward;
    }

    QString avuFastForward() const
    {
        return m_avuFastForward;
    }

    QString avuFastRewind() const
    {
        return m_avuFastRewind;
    }

    QString avuPlay() const
    {
        return m_avuPlay;
    }

    QString avuSlideShow() const
    {
        return m_avuSlideShow;
    }

    QString getCurrentVolume() const
    {
        return m_getCurrentVolume;
    }

    QString currentVolume() const
    {
        return m_currentVolume;
    }

    QString getCurrentState() const
    {
        return m_getCurrentState;
    }

    QString currentState() const
    {
        return m_currentState;
    }

    QString commandComplete() const
    {
        return m_commandComplete;
    }

    QString getCurrentLanguage() const
    {
        return m_getCurrentLanguage;
    }

    QString currentLanguageRU() const
    {
        return m_currentLanguageRU;
    }

    QString currentLanguageENG() const
    {
        return m_currentLanguageENG;
    }

    QString stateDvdBluray() const
    {
        return m_stateDvdBluray;
    }

    QString stateUSB() const
    {
        return m_stateUSB;
    }

    QString stateVideo() const
    {
        return m_stateVideo;
    }

    QString stateAudio() const
    {
        return m_stateAudio;
    }

    QString stateVideocamera() const
    {
        return m_stateVideocamera;
    }

    QString stateAirshow() const
    {
        return m_stateAirshow;
    }

    QString lightUpperOn() const
    {
        return m_lightUpperOn;
    }

    QString lightUpperOff() const
    {
        return m_lightUpperOff;
    }

    QString lightBortOn() const
    {
        return m_lightBortOn;
    }

    QString lightBortOff() const
    {
        return m_lightBortOff;
    }

    QString lightOverBedOn() const
    {
        return m_lightOverBedOn;
    }

    QString lightOverBedOff() const
    {
        return m_lightOverBedOff;
    }

    QString lightDecorOn() const
    {
        return m_lightDecorOn;
    }

    QString lightDecorOff() const
    {
        return m_lightDecorOff;
    }

    QString lightDirectUpperOn() const
    {
        return m_lightDirectUpperOn;
    }

    QString lightDirectUpperOff() const
    {
        return m_lightDirectUpperOff;
    }

    QString lightDirectBortOn() const
    {
        return m_lightDirectBortOn;
    }

    QString lightDirectBortOff() const
    {
        return m_lightDirectBortOff;
    }

    QString lightDirectOverBedOn() const
    {
        return m_lightDirectOverBedOn;
    }

    QString lightDirectOverBedOff() const
    {
        return m_lightDirectOverBedOff;
    }

    QString lightDirectDecorOn() const
    {
        return m_lightDirectDecorOn;
    }

    QString lightDirectDecorOff() const
    {
        return m_lightDirectDecorOff;
    }

    QString shadesOpenStart() const
    {
        return m_shadesOpenStart;
    }

    QString shadesOpenEnd() const
    {
        return m_shadesOpenEnd;
    }

    QString shadesCloseStart() const
    {
        return m_shadesCloseStart;
    }

    QString shadesCloseEnd() const
    {
        return m_shadesCloseEnd;
    }

    Q_INVOKABLE QString currentVolume1() const
    {
        return m_currentVolume1;
    }

    Q_INVOKABLE QString currentVolume2() const
    {
        return m_currentVolume2;
    }

    Q_INVOKABLE QString currentVolume3() const
    {
        return m_currentVolume3;
    }

    Q_INVOKABLE QString currentVolume4() const
    {
        return m_currentVolume4;
    }

    Q_INVOKABLE QString currentVolume5() const
    {
        return m_currentVolume5;
    }

    Q_INVOKABLE QString currentVolume6() const
    {
        return m_currentVolume6;
    }

    Q_INVOKABLE QString currentVolume7() const
    {
        return m_currentVolume7;
    }

    Q_INVOKABLE QString currentVolume8() const
    {
        return m_currentVolume8;
    }

    Q_INVOKABLE QString currentVolume9() const
    {
        return m_currentVolume9;
    }

    Q_INVOKABLE QString currentVolume10() const
    {
        return m_currentVolume10;
    }

    Q_INVOKABLE QString currentVolume0() const
    {
        return m_currentVolume0;
    }

    QString menuKaraoke() const
    {
        return m_menuKaraoke;
    }

    QString askDirectState() const
    {
        return m_askDirectState;
    }

    QString tvOn() const
    {
        return m_tvOn;
    }

    QString tvOff() const
    {
        return m_tvOff;
    }

    QString tvDirectOn() const
    {
        return m_tvDirectOn;
    }

    QString tvDirectOff() const
    {
        return m_tvDirectOff;
    }

    QString hdmiOn() const
    {
        return m_hdmiOn;
    }

    QString hdmiOff() const
    {
        return m_hdmiOff;
    }

    QString hdmiDirectOn() const
    {
        return m_hdmiDirectOn;
    }

    QString hdmiDirectOff() const
    {
        return m_hdmiDirectOff;
    }

    QString outVlm() const
    {
        return m_outVlm;
    }

    QString msopLocalAnswer() const
    {
        return m_msopLocalAnswer;
    }

    QString shadesBathOpenStart() const
    {
        return m_shadesBathOpenStart;
    }

    QString shadesBathOpenEnd() const
    {
        return m_shadesBathOpenEnd;
    }

    QString shadesBathCloseStart() const
    {
        return m_shadesBathCloseStart;
    }

    QString shadesBathCloseEnd() const
    {
        return m_shadesBathCloseEnd;
    }

    QString lightHallUpperOn() const
    {
        return m_lightHallUpperOn;
    }

    QString lightHallUpperOff() const
    {
        return m_lightHallUpperOff;
    }

    QString lightHallBortOn() const
    {
        return m_lightHallBortOn;
    }

    QString lightHallBortOff() const
    {
        return m_lightHallBortOff;
    }

    QString lightHallDirectUpperOn() const
    {
        return m_lightHallDirectUpperOn;
    }

    QString lightHallDirectUpperOff() const
    {
        return m_lightHallDirectUpperOff;
    }

    QString lightHallDirectBortOn() const
    {
        return m_lightHallDirectBortOn;
    }

    QString lightHallDirectBortOff() const
    {
        return m_lightHallDirectBortOff;
    }

public slots:

    const QString callVolumeFunc(QObject * obj, int volLvl) const
    {
        QString retVal;
        std::string funcName("currentVolume" + std::to_string(volLvl));
        QMetaObject::invokeMethod(obj, funcName.c_str(),
                                  Qt::DirectConnection,Q_RETURN_ARG(QString, retVal));
        return retVal;
    }

    void setAddressDevice(QString addressDevice)
    {
        if (m_addressDevice == addressDevice)
            return;

        m_addressDevice = addressDevice;
        emit addressDeviceChanged(addressDevice);
    }
    void setMenuLight(QString menuLight)
    {
        if (m_menuLight == menuLight)
            return;

        m_menuLight = menuLight;
        emit menuLightChanged(menuLight);
    }

    void setMenuShaders(QString menuShaders)
    {
        if (m_menuShaders == menuShaders)
            return;

        m_menuShaders = menuShaders;
        emit menuShadersChanged(menuShaders);
    }

    void setMenuEntertainment(QString menuEntertainment)
    {
        if (m_menuEntertainment == menuEntertainment)
            return;

        m_menuEntertainment = menuEntertainment;
        emit menuEntertainmentChanged(menuEntertainment);
    }

    void setMenuDvdBluRay(QString menuDvdBluRay)
    {
        if (m_menuDvdBluRay == menuDvdBluRay)
            return;

        m_menuDvdBluRay = menuDvdBluRay;
        emit menuDvdBluRayChanged(menuDvdBluRay);
    }

    void setMenuUsb(QString menuUsb)
    {
        if (m_menuUsb == menuUsb)
            return;

        m_menuUsb = menuUsb;
        emit menuUsbChanged(menuUsb);
    }

    void setMenuVideo(QString menuVideo)
    {
        if (m_menuVideo == menuVideo)
            return;

        m_menuVideo = menuVideo;
        emit menuVideoChanged(menuVideo);
    }

    void setMenuAudio(QString menuAudio)
    {
        if (m_menuAudio == menuAudio)
            return;

        m_menuAudio = menuAudio;
        emit menuAudioChanged(menuAudio);
    }

    void setVideocamera(QString videocamera)
    {
        if (m_videocamera == videocamera)
            return;

        m_videocamera = videocamera;
        emit videocameraChanged(videocamera);
    }

    void setAirshow(QString airshow)
    {
        if (m_airshow == airshow)
            return;

        m_airshow = airshow;
        emit airshowChanged(airshow);
    }

    void setTvOn(QString tvOn)
    {
        if (m_tvOn == tvOn)
            return;

        m_tvOn = tvOn;
        emit tvOnChanged(tvOn);
    }

    void setTvOff(QString tvOff)
    {
        if (m_tvOff == tvOff)
            return;

        m_tvOff = tvOff;
        emit tvOffChanged(tvOff);
    }

    void setDvdUp(QString dvdUp)
    {
        if (m_dvdUp == dvdUp)
            return;

        m_dvdUp = dvdUp;
        emit dvdUpChanged(dvdUp);
    }

    void setDvdDown(QString dvdDown)
    {
        if (m_dvdDown == dvdDown)
            return;

        m_dvdDown = dvdDown;
        emit dvdDownChanged(dvdDown);
    }

    void setDvdRight(QString dvdRight)
    {
        if (m_dvdRight == dvdRight)
            return;

        m_dvdRight = dvdRight;
        emit dvdRightChanged(dvdRight);
    }

    void setDvdLeft(QString dvdLeft)
    {
        if (m_dvdLeft == dvdLeft)
            return;

        m_dvdLeft = dvdLeft;
        emit dvdLeftChanged(dvdLeft);
    }

    void setDvdOk(QString dvdOk)
    {
        if (m_dvdOk == dvdOk)
            return;

        m_dvdOk = dvdOk;
        emit dvdOkChanged(dvdOk);
    }

    void setDvdVolumeUp(QString dvdVolumeUp)
    {
        if (m_dvdVolumeUp == dvdVolumeUp)
            return;

        m_dvdVolumeUp = dvdVolumeUp;
        emit dvdVolumeUpChanged(dvdVolumeUp);
    }

    void setDvdVolumeDown(QString dvdVolumeDown)
    {
        if (m_dvdVolumeDown == dvdVolumeDown)
            return;

        m_dvdVolumeDown = dvdVolumeDown;
        emit dvdVolumeDownChanged(dvdVolumeDown);
    }

    void setDvdPause(QString dvdPause)
    {
        if (m_dvdPause == dvdPause)
            return;

        m_dvdPause = dvdPause;
        emit dvdPauseChanged(dvdPause);
    }

    void setDvdStop(QString dvdStop)
    {
        if (m_dvdStop == dvdStop)
            return;

        m_dvdStop = dvdStop;
        emit dvdStopChanged(dvdStop);
    }

    void setDvdRewind(QString dvdRewind)
    {
        if (m_dvdRewind == dvdRewind)
            return;

        m_dvdRewind = dvdRewind;
        emit dvdRewindChanged(dvdRewind);
    }

    void setDvdForward(QString dvdForward)
    {
        if (m_dvdForward == dvdForward)
            return;

        m_dvdForward = dvdForward;
        emit dvdForwardChanged(dvdForward);
    }

    void setDvdFastForward(QString dvdFastForward)
    {
        if (m_dvdFastForward == dvdFastForward)
            return;

        m_dvdFastForward = dvdFastForward;
        emit dvdFastForwardChanged(dvdFastForward);
    }

    void setDvdFastRewind(QString dvdFastRewind)
    {
        if (m_dvdFastRewind == dvdFastRewind)
            return;

        m_dvdFastRewind = dvdFastRewind;
        emit dvdFastRewindChanged(dvdFastRewind);
    }

    void setDvdPlay(QString dvdPlay)
    {
        if (m_dvdPlay == dvdPlay)
            return;

        m_dvdPlay = dvdPlay;
        emit dvdPlayChanged(dvdPlay);
    }

    void setDvdEject(QString dvdEject)
    {
        if (m_dvdEject == dvdEject)
            return;

        m_dvdEject = dvdEject;
        emit dvdEjectChanged(dvdEject);
    }

    void setDvdDiskMenu(QString dvdDiskMenu)
    {
        if (m_dvdDiskMenu == dvdDiskMenu)
            return;

        m_dvdDiskMenu = dvdDiskMenu;
        emit dvdDiskMenuChanged(dvdDiskMenu);
    }

    void setAvuUp(QString avuUp)
    {
        if (m_avuUp == avuUp)
            return;

        m_avuUp = avuUp;
        emit avuUpChanged(avuUp);
    }

    void setAvuDown(QString avuDown)
    {
        if (m_avuDown == avuDown)
            return;

        m_avuDown = avuDown;
        emit avuDownChanged(avuDown);
    }

    void setAvuRight(QString avuRight)
    {
        if (m_avuRight == avuRight)
            return;

        m_avuRight = avuRight;
        emit avuRightChanged(avuRight);
    }

    void setAvuLeft(QString avuLeft)
    {
        if (m_avuLeft == avuLeft)
            return;

        m_avuLeft = avuLeft;
        emit avuLeftChanged(avuLeft);
    }

    void setAvuOk(QString avuOk)
    {
        if (m_avuOk == avuOk)
            return;

        m_avuOk = avuOk;
        emit avuOkChanged(avuOk);
    }

    void setAvuVolumeUp(QString avuVolumeUp)
    {
        if (m_avuVolumeUp == avuVolumeUp)
            return;

        m_avuVolumeUp = avuVolumeUp;
        emit avuVolumeUpChanged(avuVolumeUp);
    }

    void setAvuVolumeDown(QString avuVolumeDown)
    {
        if (m_avuVolumeDown == avuVolumeDown)
            return;

        m_avuVolumeDown = avuVolumeDown;
        emit avuVolumeDownChanged(avuVolumeDown);
    }

    void setAvuPause(QString avuPause)
    {
        if (m_avuPause == avuPause)
            return;

        m_avuPause = avuPause;
        emit avuPauseChanged(avuPause);
    }

    void setAvuStop(QString avuStop)
    {
        if (m_avuStop == avuStop)
            return;

        m_avuStop = avuStop;
        emit avuStopChanged(avuStop);
    }

    void setAvuRewind(QString avuRewind)
    {
        if (m_avuRewind == avuRewind)
            return;

        m_avuRewind = avuRewind;
        emit avuRewindChanged(avuRewind);
    }

    void setAvuForward(QString avuForward)
    {
        if (m_avuForward == avuForward)
            return;

        m_avuForward = avuForward;
        emit avuForwardChanged(avuForward);
    }

    void setAvuFastForward(QString avuFastForward)
    {
        if (m_avuFastForward == avuFastForward)
            return;

        m_avuFastForward = avuFastForward;
        emit avuFastForwardChanged(avuFastForward);
    }

    void setAvuFastRewind(QString avuFastRewind)
    {
        if (m_avuFastRewind == avuFastRewind)
            return;

        m_avuFastRewind = avuFastRewind;
        emit avuFastRewindChanged(avuFastRewind);
    }

    void setAvuPlay(QString avuPlay)
    {
        if (m_avuPlay == avuPlay)
            return;

        m_avuPlay = avuPlay;
        emit avuPlayChanged(avuPlay);
    }

    void setAvuSlideShow(QString avuSlideShow)
    {
        if (m_avuSlideShow == avuSlideShow)
            return;

        m_avuSlideShow = avuSlideShow;
        emit avuSlideShowChanged(avuSlideShow);
    }

    void setGetCurrentVolume(QString getCurrentVolume)
    {
        if (m_getCurrentVolume == getCurrentVolume)
            return;

        m_getCurrentVolume = getCurrentVolume;
        emit getCurrentVolumeChanged(getCurrentVolume);
    }

    void setCurrentVolume(QString currentVolume)
    {
        if (m_currentVolume == currentVolume)
            return;

        m_currentVolume = currentVolume;
        emit currentVolumeChanged(currentVolume);
    }

    void setGetCurrentState(QString getCurrentState)
    {
        if (m_getCurrentState == getCurrentState)
            return;

        m_getCurrentState = getCurrentState;
        emit getCurrentStateChanged(getCurrentState);
    }

    void setCurrentState(QString currentState)
    {
        if (m_currentState == currentState)
            return;

        m_currentState = currentState;
        emit currentStateChanged(currentState);
    }

    void setCommandComplete(QString commandComplete)
    {
        if (m_commandComplete == commandComplete)
            return;

        m_commandComplete = commandComplete;
        emit commandCompleteChanged(commandComplete);
    }

    void setGetCurrentLanguage(QString getCurrentLanguage)
    {
        if (m_getCurrentLanguage == getCurrentLanguage)
            return;

        m_getCurrentLanguage = getCurrentLanguage;
        emit getCurrentLanguageChanged(getCurrentLanguage);
    }

    void setCurrentLanguageRU(QString currentLanguageRU)
    {
        if (m_currentLanguageRU == currentLanguageRU)
            return;

        m_currentLanguageRU = currentLanguageRU;
        emit currentLanguageRUChanged(currentLanguageRU);
    }

    void setCurrentLanguageENG(QString currentLanguageENG)
    {
        if (m_currentLanguageENG == currentLanguageENG)
            return;

        m_currentLanguageENG = currentLanguageENG;
        emit currentLanguageENGChanged(currentLanguageENG);
    }

    void setStateDvdBluray(QString stateDvdBluray)
    {
        if (m_stateDvdBluray == stateDvdBluray)
            return;

        m_stateDvdBluray = stateDvdBluray;
        emit stateDvdBlurayChanged(stateDvdBluray);
    }

    void setStateUSB(QString stateUSB)
    {
        if (m_stateUSB == stateUSB)
            return;

        m_stateUSB = stateUSB;
        emit stateUSBChanged(stateUSB);
    }

    void setStateVideo(QString stateVideo)
    {
        if (m_stateVideo == stateVideo)
            return;

        m_stateVideo = stateVideo;
        emit stateVideoChanged(stateVideo);
    }

    void setStateAudio(QString stateAudio)
    {
        if (m_stateAudio == stateAudio)
            return;

        m_stateAudio = stateAudio;
        emit stateAudioChanged(stateAudio);
    }

    void setStateVideocamera(QString stateVideocamera)
    {
        if (m_stateVideocamera == stateVideocamera)
            return;

        m_stateVideocamera = stateVideocamera;
        emit stateVideocameraChanged(stateVideocamera);
    }

    void setStateAirshow(QString stateAirshow)
    {
        if (m_stateAirshow == stateAirshow)
            return;

        m_stateAirshow = stateAirshow;
        emit stateAirshowChanged(stateAirshow);
    }

    void setLightUpperOn(QString lightUpperOn)
    {
        if (m_lightUpperOn == lightUpperOn)
            return;

        m_lightUpperOn = lightUpperOn;
        emit lightUpperOnChanged(lightUpperOn);
    }

    void setLightUpperOff(QString lightUpperOff)
    {
        if (m_lightUpperOff == lightUpperOff)
            return;

        m_lightUpperOff = lightUpperOff;
        emit lightUpperOffChanged(lightUpperOff);
    }

    void setLightBortOn(QString lightBortOn)
    {
        if (m_lightBortOn == lightBortOn)
            return;

        m_lightBortOn = lightBortOn;
        emit lightBortOnChanged(lightBortOn);
    }

    void setLightBortOff(QString lightBortOff)
    {
        if (m_lightBortOff == lightBortOff)
            return;

        m_lightBortOff = lightBortOff;
        emit lightBortOffChanged(lightBortOff);
    }

    void setLightOverBedOn(QString lightOverBedOn)
    {
        if (m_lightOverBedOn == lightOverBedOn)
            return;

        m_lightOverBedOn = lightOverBedOn;
        emit lightOverBedOnChanged(lightOverBedOn);
    }

    void setLightOverBedOff(QString lightOverBedOff)
    {
        if (m_lightOverBedOff == lightOverBedOff)
            return;

        m_lightOverBedOff = lightOverBedOff;
        emit lightOverBedOffChanged(lightOverBedOff);
    }

    void setLightDecorOn(QString lightDecorOn)
    {
        if (m_lightDecorOn == lightDecorOn)
            return;

        m_lightDecorOn = lightDecorOn;
        emit lightDecorOnChanged(lightDecorOn);
    }

    void setLightDecorOff(QString lightDecorOff)
    {
        if (m_lightDecorOff == lightDecorOff)
            return;

        m_lightDecorOff = lightDecorOff;
        emit lightDecorOffChanged(lightDecorOff);
    }

    void setLightDirectUpperOn(QString lightDirectUpperOn)
    {
        if (m_lightDirectUpperOn == lightDirectUpperOn)
            return;

        m_lightDirectUpperOn = lightDirectUpperOn;
        emit lightDirectUpperOnChanged(lightDirectUpperOn);
    }

    void setLightDirectUpperOff(QString lightDirectUpperOff)
    {
        if (m_lightDirectUpperOff == lightDirectUpperOff)
            return;

        m_lightDirectUpperOff = lightDirectUpperOff;
        emit lightDirectUpperOffChanged(lightDirectUpperOff);
    }

    void setLightDirectBortOn(QString lightDirectBortOn)
    {
        if (m_lightDirectBortOn == lightDirectBortOn)
            return;

        m_lightDirectBortOn = lightDirectBortOn;
        emit lightDirectBortOnChanged(lightDirectBortOn);
    }

    void setLightDirectBortOff(QString lightDirectBortOff)
    {
        if (m_lightDirectBortOff == lightDirectBortOff)
            return;

        m_lightDirectBortOff = lightDirectBortOff;
        emit lightDirectBortOffChanged(lightDirectBortOff);
    }

    void setLightDirectOverBedOn(QString lightDirectOverBedOn)
    {
        if (m_lightDirectOverBedOn == lightDirectOverBedOn)
            return;

        m_lightDirectOverBedOn = lightDirectOverBedOn;
        emit lightDirectOverBedOnChanged(lightDirectOverBedOn);
    }

    void setLightDirectOverBedOff(QString lightDirectOverBedOff)
    {
        if (m_lightDirectOverBedOff == lightDirectOverBedOff)
            return;

        m_lightDirectOverBedOff = lightDirectOverBedOff;
        emit lightDirectOverBedOffChanged(lightDirectOverBedOff);
    }

    void setLightDirectDecorOn(QString lightDirectDecorOn)
    {
        if (m_lightDirectDecorOn == lightDirectDecorOn)
            return;

        m_lightDirectDecorOn = lightDirectDecorOn;
        emit lightDirectDecorOnChanged(lightDirectDecorOn);
    }

    void setLightDirectDecorOff(QString lightDirectDecorOff)
    {
        if (m_lightDirectDecorOff == lightDirectDecorOff)
            return;

        m_lightDirectDecorOff = lightDirectDecorOff;
        emit lightDirectDecorOffChanged(lightDirectDecorOff);
    }

    void setShadesOpenStart(QString shadesOpenStart)
    {
        if (m_shadesOpenStart == shadesOpenStart)
            return;

        m_shadesOpenStart = shadesOpenStart;
        emit shadesOpenStartChanged(shadesOpenStart);
    }

    void setShadesOpenEnd(QString shadesOpenEnd)
    {
        if (m_shadesOpenEnd == shadesOpenEnd)
            return;

        m_shadesOpenEnd = shadesOpenEnd;
        emit shadesOpenEndChanged(shadesOpenEnd);
    }

    void setShadesCloseStart(QString shadesCloseStart)
    {
        if (m_shadesCloseStart == shadesCloseStart)
            return;

        m_shadesCloseStart = shadesCloseStart;
        emit shadesCloseStartChanged(shadesCloseStart);
    }

    void setShadesCloseEnd(QString shadesCloseEnd)
    {
        if (m_shadesCloseEnd == shadesCloseEnd)
            return;

        m_shadesCloseEnd = shadesCloseEnd;
        emit shadesCloseEndChanged(shadesCloseEnd);
    }

    void setCurrentVolume1(QString currentVolume1)
    {
        if (m_currentVolume1 == currentVolume1)
            return;

        m_currentVolume1 = currentVolume1;
        emit currentVolume1Changed(currentVolume1);
    }

    void setCurrentVolume2(QString currentVolume2)
    {
        if (m_currentVolume2 == currentVolume2)
            return;

        m_currentVolume2 = currentVolume2;
        emit currentVolume2Changed(currentVolume2);
    }

    void setCurrentVolume3(QString currentVolume3)
    {
        if (m_currentVolume3 == currentVolume3)
            return;

        m_currentVolume3 = currentVolume3;
        emit currentVolume3Changed(currentVolume3);
    }

    void setCurrentVolume4(QString currentVolume4)
    {
        if (m_currentVolume4 == currentVolume4)
            return;

        m_currentVolume4 = currentVolume4;
        emit currentVolume4Changed(currentVolume4);
    }

    void setCurrentVolume5(QString currentVolume5)
    {
        if (m_currentVolume5 == currentVolume5)
            return;

        m_currentVolume5 = currentVolume5;
        emit currentVolume5Changed(currentVolume5);
    }

    void setCurrentVolume6(QString currentVolume6)
    {
        if (m_currentVolume6 == currentVolume6)
            return;

        m_currentVolume6 = currentVolume6;
        emit currentVolume6Changed(currentVolume6);
    }

    void setCurrentVolume7(QString currentVolume7)
    {
        if (m_currentVolume7 == currentVolume7)
            return;

        m_currentVolume7 = currentVolume7;
        emit currentVolume7Changed(currentVolume7);
    }

    void setCurrentVolume8(QString currentVolume8)
    {
        if (m_currentVolume8 == currentVolume8)
            return;

        m_currentVolume8 = currentVolume8;
        emit currentVolume8Changed(currentVolume8);
    }

    void setCurrentVolume9(QString currentVolume9)
    {
        if (m_currentVolume9 == currentVolume9)
            return;

        m_currentVolume9 = currentVolume9;
        emit currentVolume9Changed(currentVolume9);
    }

    void setCurrentVolume10(QString currentVolume10)
    {
        if (m_currentVolume10 == currentVolume10)
            return;

        m_currentVolume10 = currentVolume10;
        emit currentVolume10Changed(currentVolume10);
    }

    void setCurrentVolume0(QString currentVolume0)
    {
        if (m_currentVolume0 == currentVolume0)
            return;

        m_currentVolume0 = currentVolume0;
        emit currentVolume0Changed(currentVolume0);
    }

    void switchToLightKoridor();
    void switchToLightGlavzal();

    void setMenuKaraoke(QString menuKaraoke)
    {
        if (m_menuKaraoke == menuKaraoke)
            return;

        m_menuKaraoke = menuKaraoke;
        emit menuKaraokeChanged(menuKaraoke);
    }

    void setAskDirectState(QString askDirectState)
    {
        if (m_askDirectState == askDirectState)
            return;

        m_askDirectState = askDirectState;
        emit askDirectStateChanged(askDirectState);
    }

    void setLocalAddressDevice(QString localAddressDevice)
    {
        if (m_localAddressDevice == localAddressDevice)
            return;

        m_localAddressDevice = localAddressDevice;
        emit localAddressDeviceChanged(localAddressDevice);
    }

    void setHdmiOn(QString hdmiOn)
    {
        if (m_hdmiOn == hdmiOn)
            return;

        m_hdmiOn = hdmiOn;
        emit hdmiOnChanged(m_hdmiOn);
    }

    void setHdmiOff(QString hdmiOff)
    {
        if (m_hdmiOff == hdmiOff)
            return;

        m_hdmiOff = hdmiOff;
        emit hdmiOffChanged(m_hdmiOff);
    }

    void setTvDirectOn(QString tvDirectOn)
    {
        if (m_tvDirectOn == tvDirectOn)
            return;

        m_tvDirectOn = tvDirectOn;
        emit tvDirectOnChanged(m_tvDirectOn);
    }

    void setTvDirectOff(QString tvDirectOff)
    {
        if (m_tvDirectOff == tvDirectOff)
            return;

        m_tvDirectOff = tvDirectOff;
        emit tvDirectOffChanged(m_tvDirectOff);
    }

    void setHdmiDirectOn(QString hdmiDirectOn)
    {
        if (m_hdmiDirectOn == hdmiDirectOn)
            return;

        m_hdmiDirectOn = hdmiDirectOn;
        emit hdmiDirectOnChanged(m_hdmiDirectOn);
    }

    void setHdmiDirectOff(QString hdmiDirectOff)
    {
        if (m_hdmiDirectOff == hdmiDirectOff)
            return;

        m_hdmiDirectOff = hdmiDirectOff;
        emit hdmiDirectOffChanged(m_hdmiDirectOff);
    }

    void setOutVlm(QString outVlm)
    {
        if (m_outVlm == outVlm)
            return;

        m_outVlm = outVlm;
        emit outVlmChanged(m_outVlm);
    }

    void setMsopLocalAnswer(QString msopLocalAnswer)
    {
        if (m_msopLocalAnswer == msopLocalAnswer)
            return;

        m_msopLocalAnswer = msopLocalAnswer;
        emit msopLocalAnswerChanged(m_msopLocalAnswer);
    }

    void setShadesBathOpenStart(QString shadesBathOpenStart)
    {
        if (m_shadesBathOpenStart == shadesBathOpenStart)
            return;

        m_shadesBathOpenStart = shadesBathOpenStart;
        emit shadesBathOpenStartChanged(m_shadesBathOpenStart);
    }

    void setShadesBathOpenEnd(QString shadesBathOpenEnd)
    {
        if (m_shadesBathOpenEnd == shadesBathOpenEnd)
            return;

        m_shadesBathOpenEnd = shadesBathOpenEnd;
        emit shadesBathOpenEndChanged(m_shadesBathOpenEnd);
    }

    void setShadesBathCloseStart(QString shadesBathCloseStart)
    {
        if (m_shadesBathCloseStart == shadesBathCloseStart)
            return;

        m_shadesBathCloseStart = shadesBathCloseStart;
        emit shadesBathCloseStartChanged(m_shadesBathCloseStart);
    }

    void setShadesBathCloseEnd(QString shadesBathCloseEnd)
    {
        if (m_shadesBathCloseEnd == shadesBathCloseEnd)
            return;

        m_shadesBathCloseEnd = shadesBathCloseEnd;
        emit shadesBathCloseEndChanged(m_shadesBathCloseEnd);
    }

    void setLightHallUpperOn(QString lightHallUpperOn)
    {
        if (m_lightHallUpperOn == lightHallUpperOn)
            return;

        m_lightHallUpperOn = lightHallUpperOn;
        emit lightHallUpperOnChanged(m_lightHallUpperOn);
    }

    void setLightHallUpperOff(QString lightHallUpperOff)
    {
        if (m_lightHallUpperOff == lightHallUpperOff)
            return;

        m_lightHallUpperOff = lightHallUpperOff;
        emit lightHallUpperOffChanged(m_lightHallUpperOff);
    }

    void setLightHallBortOn(QString lightHallBortOn)
    {
        if (m_lightHallBortOn == lightHallBortOn)
            return;

        m_lightHallBortOn = lightHallBortOn;
        emit lightHallBortOnChanged(m_lightHallBortOn);
    }

    void setLightHallBortOff(QString lightHallBortOff)
    {
        if (m_lightHallBortOff == lightHallBortOff)
            return;

        m_lightHallBortOff = lightHallBortOff;
        emit lightHallBortOffChanged(m_lightHallBortOff);
    }

    void setLightHallDirectUpperOn(QString lightHallDirectUpperOn)
    {
        if (m_lightHallDirectUpperOn == lightHallDirectUpperOn)
            return;

        m_lightHallDirectUpperOn = lightHallDirectUpperOn;
        emit lightHallDirectUpperOnChanged(m_lightHallDirectUpperOn);
    }

    void setLightHallDirectUpperOff(QString lightHallDirectUpperOff)
    {
        if (m_lightHallDirectUpperOff == lightHallDirectUpperOff)
            return;

        m_lightHallDirectUpperOff = lightHallDirectUpperOff;
        emit lightHallDirectUpperOffChanged(m_lightHallDirectUpperOff);
    }

    void setLightHallDirectBortOn(QString lightHallDirectBortOn)
    {
        if (m_lightHallDirectBortOn == lightHallDirectBortOn)
            return;

        m_lightHallDirectBortOn = lightHallDirectBortOn;
        emit lightHallDirectBortOnChanged(m_lightHallDirectBortOn);
    }

    void setLightHallDirectBortOff(QString lightHallDirectBortOff)
    {
        if (m_lightHallDirectBortOff == lightHallDirectBortOff)
            return;

        m_lightHallDirectBortOff = lightHallDirectBortOff;
        emit lightHallDirectBortOffChanged(m_lightHallDirectBortOff);
    }

signals:
    void addressDeviceChanged(QString addressDevice);
    void menuLightChanged(QString menuLight);
    void menuShadersChanged(QString menuShaders);
    void menuEntertainmentChanged(QString menuEntertainment);
    void menuDvdBluRayChanged(QString menuDvdBluRay);
    void menuUsbChanged(QString menuUsb);
    void menuVideoChanged(QString menuVideo);
    void menuAudioChanged(QString menuAudio);
    void videocameraChanged(QString videocamera);
    void airshowChanged(QString airshow);

    void dvdUpChanged(QString dvdUp);
    void dvdDownChanged(QString dvdDown);
    void dvdRightChanged(QString dvdRight);
    void dvdLeftChanged(QString dvdLeft);
    void dvdOkChanged(QString dvdOk);
    void dvdVolumeUpChanged(QString dvdVolumeUp);
    void dvdVolumeDownChanged(QString dvdVoluneDown);
    void dvdPauseChanged(QString dvdPause);
    void dvdStopChanged(QString dvdStop);
    void dvdRewindChanged(QString dvdRewind);
    void dvdForwardChanged(QString dvdForward);
    void dvdFastForwardChanged(QString dvdFastForward);
    void dvdFastRewindChanged(QString dvdFastRewind);
    void dvdPlayChanged(QString dvdPlay);
    void dvdEjectChanged(QString dvdEject);
    void dvdDiskMenuChanged(QString dvdDiskMenu);
    void avuUpChanged(QString avuUp);
    void avuDownChanged(QString avuDown);
    void avuRightChanged(QString avuRight);
    void avuLeftChanged(QString avuLeft);
    void avuOkChanged(QString avuOk);
    void avuVolumeUpChanged(QString avuVolumeUp);
    void avuVolumeDownChanged(QString avuVolumeDown);
    void avuPauseChanged(QString avuPause);
    void avuStopChanged(QString avuStop);
    void avuRewindChanged(QString avuRewind);
    void avuForwardChanged(QString avuForward);
    void avuFastForwardChanged(QString avuFastForward);
    void avuFastRewindChanged(QString avuFastRewind);
    void avuPlayChanged(QString avuPlay);
    void avuSlideShowChanged(QString avuSlideShow);
    void getCurrentVolumeChanged(QString getCurrentVolume);
    void currentVolumeChanged(QString currentVolume);
    void getCurrentStateChanged(QString getCurrentState);
    void currentStateChanged(QString currentState);
    void commandCompleteChanged(QString commandComplete);
    void getCurrentLanguageChanged(QString getCurrentLanguage);
    void currentLanguageRUChanged(QString currentLanguageRU);
    void currentLanguageENGChanged(QString currentLanguageENG);
    void stateDvdBlurayChanged(QString stateDvdBluray);
    void stateUSBChanged(QString stateUSB);
    void stateVideoChanged(QString stateVideo);
    void stateAudioChanged(QString stateAudio);
    void stateVideocameraChanged(QString stateVideocamera);
    void stateAirshowChanged(QString stateAirshow);
    void stateTvOnChanged(QString stateTvOn);
    void stateTvOffChanged(QString stateTvOff);
    void lightUpperOnChanged(QString lightUpperOn);
    void lightUpperOffChanged(QString lightUpperOff);
    void lightBortOnChanged(QString lightBortOn);
    void lightBortOffChanged(QString lightBortOff);
    void lightOverBedOnChanged(QString lightOverBedOn);
    void lightOverBedOffChanged(QString lightOverBedOff);
    void lightDecorOnChanged(QString lightDecorOn);
    void lightDecorOffChanged(QString lightDecorOff);
    void lightDirectUpperOnChanged(QString lightDirectUpperOn);
    void lightDirectUpperOffChanged(QString lightDirectUpperOff);
    void lightDirectBortOnChanged(QString lightDirectBortOn);
    void lightDirectBortOffChanged(QString lightDirectBortOff);
    void lightDirectOverBedOnChanged(QString lightDirectOverBedOn);
    void lightDirectOverBedOffChanged(QString lightDirectOverBedOff);
    void lightDirectDecorOnChanged(QString lightDirectDecorOn);
    void lightDirectDecorOffChanged(QString lightDirectDecorOff);
    void shadesOpenStartChanged(QString shadesOpenStart);
    void shadesOpenEndChanged(QString shadesOpenEnd);
    void shadesCloseStartChanged(QString shadesCloseStart);
    void shadesCloseEndChanged(QString shadesCloseEnd);
    void currentVolume1Changed(QString currentVolume1);
    void currentVolume2Changed(QString currentVolume2);
    void currentVolume3Changed(QString currentVolume3);
    void currentVolume4Changed(QString currentVolume4);
    void currentVolume5Changed(QString currentVolume5);
    void currentVolume6Changed(QString currentVolume6);
    void currentVolume7Changed(QString currentVolume7);
    void currentVolume8Changed(QString currentVolume8);
    void currentVolume9Changed(QString currentVolume9);
    void currentVolume10Changed(QString currentVolume10);
    void currentVolume0Changed(QString currentVolume0);
    void menuKaraokeChanged(QString menuKaraoke);
    void askDirectStateChanged(QString askDirectState);
    void localAddressDeviceChanged(QString localAddressDevice);

    void tvOnChanged(QString tvOn);
    void tvOffChanged(QString tvOff);
    void tvDirectOnChanged(QString tvDirectOn);
    void tvDirectOffChanged(QString tvDirectOff);
    void hdmiOnChanged(QString hdmiOn);
    void hdmiOffChanged(QString hdmiOff);
    void hdmiDirectOnChanged(QString hdmiDirectOn);
    void hdmiDirectOffChanged(QString hdmiDirectOff);
    void outVlmChanged(QString outVlm);
    void msopLocalAnswerChanged(QString msopLocalAnswer);
    void shadesBathOpenStartChanged(QString shadesBathOpenStart);
    void shadesBathOpenEndChanged(QString shadesBathOpenEnd);
    void shadesBathCloseStartChanged(QString shadesBathCloseStart);
    void shadesBathCloseEndChanged(QString shadesBathCloseEnd);
    void lightHallUpperOnChanged(QString lightHallUpperOn);
    void lightHallUpperOffChanged(QString lightHallUpperOff);
    void lightHallBortOnChanged(QString lightHallBortOn);
    void lightHallBortOffChanged(QString lightHallBortOff);
    void lightHallDirectUpperOnChanged(QString lightHallDirectUpperOn);
    void lightHallDirectUpperOffChanged(QString lightHallDirectUpperOff);
    void lightHallDirectBortOnChanged(QString lightHallDirectBortOn);
    void lightHallDirectBortOffChanged(QString lightHallDirectBortOff);
};

#endif // CONFIGURATOR_H
