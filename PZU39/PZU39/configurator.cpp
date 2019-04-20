#include "settings.h"
#include "configurator.h"
#include <QDebug>

namespace DevicesAddress {
    const QString BP1  = "F0";
    const QString PZU1 = "F2";
    const QString PZU2 = "F3";
    const QString PZU3 = "F4";
}

namespace MenuCmd {
    const QString MLight   = "3600";
    const QString MShades  = "3601";
    const QString MIrs     = "3602";
    const QString MDvd     = "3700";
    const QString MUsb     = "3701";
    const QString MVideo   = "3702";
    const QString MAudio   = "3703";
    const QString MKaraoke = "3704";
}

namespace MMCCmd {
    const QString MVideocamera   = "3801";
    const QString MAirshow       = "3802";

    const QString MDvdUp         = "3900";
    const QString MDvdDown       = "3901";
    const QString MDvdLeft       = "3902";
    const QString MDvdRight      = "3903";
    const QString MDvdOk         = "3904";
    const QString MDvdVolumeUp   = "3905";
    const QString MDvdVolumeDown = "3906";
    const QString MDvdPause      = "3907";
    const QString MDvdStop       = "3908";
    const QString MDvdRewind     = "3909";
    const QString MDvdForward    = "390A";
    const QString MDvdFastRwd    = "390B";
    const QString MDvdFastFfd    = "390C";
    const QString MDvdPlay       = "390D";
    const QString MDvdEject      = "390E";
    const QString MDvdMenu       = "390F";

    const QString MAvuUp         = "3A00";
    const QString MAvuDown       = "3A01";
    const QString MAvuLeft       = "3A02";
    const QString MAvuRight      = "3A03";
    const QString MAvuOk         = "3A04";
    const QString MAvuVolumeUp   = "3A05";
    const QString MAvuVolumeDown = "3A06";
    const QString MAvuPause      = "3A07";
    const QString MAvuStop       = "3A08";
    const QString MAvuRewind     = "3A09";
    const QString MAvuForward    = "3A0A";
    const QString MAvuFastFfd    = "3A0B";
    const QString MAvuFastRwd    = "3A0C";
    const QString MAvuPlay       = "3A0D";
    const QString MAvuSlideShow  = "3A0E";
}

namespace ServiceCmd {
    const QString AskCrntVlm         = "3B3B";     //out
    const QString AskCrntState       = "3C00";     //out
    const QString AskDirectCrntState = "0D";     //out
    const QString AskCrntLang        = "3D00";     //out

    const QString InStateCmd         = "F03C#1";
    const QString InOkCmd            = "F03C#2";
    const QString InLangRu           = "F03D#1";
    const QString InLangEng          = "F03D#2";
    const QString InMenuDvd          = "F037#0";
    const QString InMenuUsb          = "F037#1";
    const QString InMenuVideo        = "F037#2";
    const QString InMenuAudio        = "F037#3";
    const QString InVideocamera      = "F038#1";
    const QString InAirshow          = "F038#2";

    const QString InVlm0             = "F03B#0";
    const QString InVlm1             = "F03B#1";
    const QString InVlm2             = "F03B#2";
    const QString InVlm3             = "F03B#3";
    const QString InVlm4             = "F03B#4";
    const QString InVlm5             = "F03B#5";
    const QString InVlm6             = "F03B#6";
    const QString InVlm7             = "F03B#7";
    const QString InVlm8             = "F03B#8";
    const QString InVlm9             = "F03B#9";
    const QString InVlm10            = "F03B#A";

    const QString OutVlm             = "F#3B0$";
}

namespace Msop {
    const QString MsopAnswer        = "40";
    const QString BedroomHdmiOn     = "0417";
    const QString BedroomHdmiOff    = "0407";
    const QString BedroomTvOn       = "0418";
    const QString BedroomTvOff      = "0408";
    ///for testing !!!!!!!!
//    const QString BedroomLUpperOn   = "0712";
//    const QString BedroomLUpperOff  = "0702";
//    const QString BedroomLBortOn    = "0713";
//    const QString BedroomLBortOff   = "0703";
//    const QString BedroomLBedOn     = "0711";
//    const QString BedroomLBedOff    = "0701";
 ////////////////////////

    const QString DecorOn           = "EEEEEE";
    const QString DecorOff          = "DDDDDD";
    const QString BedroomLUpperOn   = "0415";
    const QString BedroomLUpperOff  = "0405";
    const QString BedroomLBortOn    = "0416";
    const QString BedroomLBortOff   = "0406";
    const QString BedroomLBedOn     = "0412";
    const QString BedroomLBedOff    = "0402";

    const QString WorkroomHdmiOn    = "0715";
    const QString WorkroomHdmiOff   = "0705";
    const QString WorkroomTvOn      = "0716";
    const QString WorkroomTvOff     = "0706";
    const QString WorkroomLUpperOn  = "0713";
    const QString WorkroomLUpperOff = "0703";
    const QString WorkroomLBortOn   = "0714";
    const QString WorkroomLBortOff  = "0704";

    const QString KoridorLUpperOn   = "1117";
    const QString KoridorLUpperOff  = "1107";
    const QString KoridorLBortOn    = "1118";
    const QString KoridorLBortOff   = "1108";

    const QString GlavzalHdmiOn     = "1311";
    const QString GlavzalHdmiOff    = "1301";
    const QString GlavzalTvOn       = "1316";
    const QString GlavzalTvOff      = "1306";
    const QString GlavzalLUpperOn   = "1313";
    const QString GlavzalLUpperOff  = "1303";
    const QString GlavzalLBortOn    = "1314";
    const QString GlavzalLBortOff   = "1304";

    //const QString LDecorOn    = "0x??";  //Декоративное освещение через ethernet
    //const QString LDecorOff   = "0x??";

    //Direct
    const QString BedroomAddress        = "84";
    const QString BedroomLDUpperOn     = "841805";
    const QString BedroomLDUpperOff    = "841905";
    const QString BedroomLDBortOn      = "841806";
    const QString BedroomLDBortOff     = "841906";
    const QString BedroomLDBedOn       = "841802";
    const QString BedroomLDBedOff      = "841902";

    const QString BedroomHdmiDOn       = "841807";
    const QString BedroomHdmiDOff      = "841907";
    const QString BedroomTvDOn         = "841808";
    const QString BedroomTvDOff        = "841908";
    const QString BedroomSDOpenStart   = "841803";
    const QString BedroomSDOpenEnd     = "841903";
    const QString BedroomSDCloseStart  = "841804";
    const QString BedroomSDCloseEnd    = "841904";

    const QString BathroomAdress       = "86";
    const QString BathroomSDOpenStart  = "861804";
    const QString BathroomSDOpenEnd    = "861904";
    const QString BathroomSDCloseStart = "861805";
    const QString BathroomSDCloseEnd   = "861905";

//    //For Testing!!!!!!!!!
//    //Direct test command for current MSOP
//    const QString BedroomAddress       = "87";
//    const QString BedroomLDUpperOn     = "871802";
//    const QString BedroomLDUpperOff    = "871902";
//    const QString BedroomLDBortOn      = "871803";
//    const QString BedroomLDBortOff     = "871903";
//    const QString BedroomLDBedOn       = "871801";
//    const QString BedroomLDBedOff      = "871901";
//    ////////////////////////////////////////////////

    const QString WorkroomArdress      = "87";
    const QString WorkroomHdmiDOn      = "871805";
    const QString WorkroomHdmiDOff     = "871905";
    const QString WorkroomTvDOn        = "871806";
    const QString WorkroomTvDOff       = "871906";
    const QString WorkroomLDUpperOn    = "871803";
    const QString WorkroomLDUpperOff   = "871903";
    const QString WorkroomLDBortOn     = "871804";
    const QString WorkroomLDBortOff    = "871904";
    const QString WorkroomSDOpenStart  = "871801";
    const QString WorkroomSDOpenEnd    = "871901";
    const QString WorkroomSDCloseStart = "871802";
    const QString WorkroomSDCloseEnd   = "871902";

    const QString KoridorAdress        = "91";
    const QString KoridorLDUpperOn     = "911807";
    const QString KoridorLDUpperOff    = "911907";
    const QString KoridorLDBortOn      = "911808";
    const QString KoridorLDBortOff     = "911908";

    const QString GlavzalAdress        = "93";
    const QString GlavzalHdmiDOn       = "931801";
    const QString GlavzalHdmiDOff      = "931901";
    const QString GlavzalTvDOn         = "931806";
    const QString GlavzalTvDOff        = "931906";
    const QString GlavzalLDUpperOn     = "931803";
    const QString GlavzalLDUpperOff    = "931903";
    const QString GlavzalLDBortOn      = "931804";
    const QString GlavzalLDBortOff     = "931904";
}

Configurator * Configurator::m_instance = 0;

Configurator *Configurator::instance()
{
    if(!m_instance){
        m_instance = new Configurator();
    }
    return m_instance;
}

Configurator::Configurator(QObject *parent): QObject(parent)
{
    Settings *settings = Settings::instance();
    m_currentZone = settings->currentZone();
    switch (m_currentZone) {
    case 1:
        m_addressDevice = DevicesAddress::PZU1;
        break;
    case 2:
        m_addressDevice = DevicesAddress::PZU2;
        break;
    case 3:
        m_addressDevice = DevicesAddress::PZU3;
        break;
    default:
        m_addressDevice = DevicesAddress::PZU1;
        break;
    }
    //qDebug()<<"ADress device = " << m_addressDevice;
    init();

}

void Configurator::init(){
    m_HallSwitched       = false;
    m_menuLight          = m_addressDevice + MenuCmd::MLight;
    m_menuAudio          = m_addressDevice + MenuCmd::MAudio;
    m_menuDvdBluRay      = m_addressDevice + MenuCmd::MDvd;
    m_menuUsb            = m_addressDevice + MenuCmd::MUsb;
    m_menuVideo          = m_addressDevice + MenuCmd::MVideo;
    m_menuEntertainment  = m_addressDevice + MenuCmd::MIrs;
    m_menuShaders        = m_addressDevice + MenuCmd::MShades;
    m_menuKaraoke        = m_addressDevice + MenuCmd::MKaraoke;

    m_videocamera        = m_addressDevice + MMCCmd::MVideocamera;
    m_airshow            = m_addressDevice + MMCCmd::MAirshow;

    m_dvdUp              = m_addressDevice + MMCCmd::MDvdUp;
    m_dvdDown            = m_addressDevice + MMCCmd::MDvdDown;
    m_dvdRight           = m_addressDevice + MMCCmd::MDvdRight;
    m_dvdLeft            = m_addressDevice + MMCCmd::MDvdLeft;
    m_dvdOk              = m_addressDevice + MMCCmd::MDvdOk;
    m_dvdVolumeUp        = m_addressDevice + MMCCmd::MDvdVolumeUp;
    m_dvdVolumeDown      = m_addressDevice + MMCCmd::MDvdVolumeDown;
    m_dvdPause           = m_addressDevice + MMCCmd::MDvdPause;
    m_dvdStop            = m_addressDevice + MMCCmd::MDvdStop;
    m_dvdRewind          = m_addressDevice + MMCCmd::MDvdRewind;
    m_dvdForward         = m_addressDevice + MMCCmd::MDvdForward;
    m_dvdFastForward     = m_addressDevice + MMCCmd::MDvdFastFfd;
    m_dvdFastRewind      = m_addressDevice + MMCCmd::MDvdFastRwd;
    m_dvdPlay            = m_addressDevice + MMCCmd::MDvdPlay;
    m_dvdEject           = m_addressDevice + MMCCmd::MDvdEject;
    m_dvdDiskMenu        = m_addressDevice + MMCCmd::MDvdMenu;

    m_avuUp              = m_addressDevice + MMCCmd::MAvuUp;
    m_avuDown            = m_addressDevice + MMCCmd::MAvuDown;
    m_avuRight           = m_addressDevice + MMCCmd::MAvuRight;
    m_avuLeft            = m_addressDevice + MMCCmd::MAvuLeft;
    m_avuOk              = m_addressDevice + MMCCmd::MAvuOk;
    m_avuVolumeUp        = m_addressDevice + MMCCmd::MAvuVolumeUp;
    m_avuVolumeDown      = m_addressDevice + MMCCmd::MAvuVolumeDown;
    m_avuPause           = m_addressDevice + MMCCmd::MAvuPause;
    m_avuStop            = m_addressDevice + MMCCmd::MAvuStop;
    m_avuRewind          = m_addressDevice + MMCCmd::MAvuRewind;
    m_avuForward         = m_addressDevice + MMCCmd::MAvuForward;
    m_avuFastForward     = m_addressDevice + MMCCmd::MAvuFastFfd;
    m_avuFastRewind      = m_addressDevice + MMCCmd::MAvuFastRwd;
    m_avuPlay            = m_addressDevice + MMCCmd::MAvuPlay;
    m_avuSlideShow       = m_addressDevice + MMCCmd::MAvuSlideShow;

    m_getCurrentVolume   = m_addressDevice + ServiceCmd::AskCrntVlm;
    m_getCurrentState    = m_addressDevice + ServiceCmd::AskCrntState;
    m_getCurrentLanguage = m_addressDevice + ServiceCmd::AskCrntLang;


    QString deviceNumber = m_addressDevice.right(1);
    //qDebug()<<"deviceNumber = " << deviceNumber;

    m_currentState       = QString(ServiceCmd::InStateCmd).   replace(4,1,deviceNumber);
    m_commandComplete    = QString(ServiceCmd::InOkCmd).      replace(4,1,deviceNumber);
    m_currentLanguageRU  = QString(ServiceCmd::InLangRu).     replace(4,1,deviceNumber);
    m_currentLanguageENG = QString(ServiceCmd::InLangEng).    replace(4,1,deviceNumber);
    m_stateDvdBluray     = QString(ServiceCmd::InMenuDvd).    replace(4,1,deviceNumber);
    m_stateUSB           = QString(ServiceCmd::InMenuUsb).    replace(4,1,deviceNumber);
    m_stateVideo         = QString(ServiceCmd::InMenuVideo).  replace(4,1,deviceNumber);
    m_stateAudio         = QString(ServiceCmd::InMenuAudio).  replace(4,1,deviceNumber);
    m_stateVideocamera   = QString(ServiceCmd::InVideocamera).replace(4,1,deviceNumber);
    m_stateAirshow       = QString(ServiceCmd::InAirshow).    replace(4,1,deviceNumber);
    m_stateUSB           = m_stateUSB.replace(1,1,deviceNumber);
    m_stateVideo         = m_stateVideo.replace(1,1,deviceNumber);
    m_stateAudio         = m_stateAudio.replace(1,1,deviceNumber);
    m_stateDvdBluray     = m_stateDvdBluray.replace(1,1,deviceNumber);
    m_stateVideocamera   = m_stateVideocamera.replace(1,1,deviceNumber);
    m_stateAirshow       = m_stateAirshow.replace(1,1,deviceNumber);

    m_currentVolume0     = QString(ServiceCmd::InVlm0).       replace(4,1,deviceNumber);
    m_currentVolume1     = QString(ServiceCmd::InVlm1).       replace(4,1,deviceNumber);
    m_currentVolume2     = QString(ServiceCmd::InVlm2).       replace(4,1,deviceNumber);
    m_currentVolume3     = QString(ServiceCmd::InVlm3).       replace(4,1,deviceNumber);
    m_currentVolume4     = QString(ServiceCmd::InVlm4).       replace(4,1,deviceNumber);
    m_currentVolume5     = QString(ServiceCmd::InVlm5).       replace(4,1,deviceNumber);
    m_currentVolume6     = QString(ServiceCmd::InVlm6).       replace(4,1,deviceNumber);
    m_currentVolume7     = QString(ServiceCmd::InVlm7).       replace(4,1,deviceNumber);
    m_currentVolume8     = QString(ServiceCmd::InVlm8).       replace(4,1,deviceNumber);
    m_currentVolume9     = QString(ServiceCmd::InVlm9).       replace(4,1,deviceNumber);
    m_currentVolume10    = QString(ServiceCmd::InVlm10).      replace(4,1,deviceNumber);
    m_outVlm             = QString(ServiceCmd::OutVlm).       replace(1,1,deviceNumber);

    m_currentVolume0     = m_currentVolume0.replace(1,1,deviceNumber);
    m_currentVolume1     = m_currentVolume1.replace(1,1,deviceNumber);
    m_currentVolume2     = m_currentVolume2.replace(1,1,deviceNumber);
    m_currentVolume3     = m_currentVolume3.replace(1,1,deviceNumber);
    m_currentVolume4     = m_currentVolume4.replace(1,1,deviceNumber);
    m_currentVolume5     = m_currentVolume5.replace(1,1,deviceNumber);
    m_currentVolume6     = m_currentVolume6.replace(1,1,deviceNumber);
    m_currentVolume7     = m_currentVolume7.replace(1,1,deviceNumber);
    m_currentVolume8     = m_currentVolume8.replace(1,1,deviceNumber);
    m_currentVolume9     = m_currentVolume9.replace(1,1,deviceNumber);
    m_currentVolume10    = m_currentVolume10.replace(1,1,deviceNumber);

    switch (m_currentZone)
    {
    case 1:                          //Bedroom and Bathroom
        m_tvOn            = m_addressDevice + Msop::BedroomTvOn;
        m_tvOff           = m_addressDevice + Msop::BedroomTvOff;
        m_hdmiOn          = m_addressDevice + Msop::BedroomHdmiOn;
        m_hdmiOff         = m_addressDevice + Msop::BedroomHdmiOff;
        m_lightUpperOn    = m_addressDevice + Msop::BedroomLUpperOn;
        m_lightUpperOff   = m_addressDevice + Msop::BedroomLUpperOff;
        m_lightBortOn     = m_addressDevice + Msop::BedroomLBortOn;
        m_lightBortOff    = m_addressDevice + Msop::BedroomLBortOff;
        m_lightOverBedOn  = m_addressDevice + Msop::BedroomLBedOn;
        m_lightOverBedOff = m_addressDevice + Msop::BedroomLBedOff;

        //direct

        m_localAddressDevice    = Msop::BedroomAddress;
        m_tvDirectOn            = Msop::BedroomTvDOn;
        m_tvDirectOff           = Msop::BedroomTvDOff;
        m_hdmiDirectOn          = Msop::BedroomHdmiDOn;
        m_hdmiDirectOff         = Msop::BedroomHdmiDOff;
        m_lightDirectUpperOn    = Msop::BedroomLDUpperOn;
        m_lightDirectUpperOff   = Msop::BedroomLDUpperOff;
        m_lightDirectBortOn     = Msop::BedroomLDBortOn;
        m_lightDirectBortOff    = Msop::BedroomLDBortOff;
        m_lightDirectOverBedOn  = Msop::BedroomLDBedOn;
        m_lightDirectOverBedOff = Msop::BedroomLDBedOff;

        //Bedroom and bathroom jalousie works together
        m_shadesOpenStart       = Msop::BedroomSDOpenStart  ;//+ Msop::BathroomSDOpenStart;
        m_shadesOpenEnd         = Msop::BedroomSDOpenEnd    ;//+ Msop::BathroomSDOpenEnd;
        m_shadesCloseStart      = Msop::BedroomSDCloseStart ;//+ Msop::BathroomSDCloseStart;
        m_shadesCloseEnd        = Msop::BedroomSDCloseEnd   ;//+ Msop::BathroomSDCloseEnd;

        m_shadesBathOpenStart   = Msop::BathroomSDOpenStart;
        m_shadesBathOpenEnd     = Msop::BathroomSDOpenEnd;
        m_shadesBathCloseStart  = Msop::BathroomSDCloseStart;
        m_shadesBathCloseEnd    = Msop::BathroomSDCloseEnd;
        break;
    case 2:                          //Workroom
        m_tvOn                  = m_addressDevice + Msop::WorkroomTvOn;
        m_tvOff                 = m_addressDevice + Msop::WorkroomTvOff;
        m_hdmiOn                = m_addressDevice + Msop::WorkroomHdmiOn;
        m_hdmiOff               = m_addressDevice + Msop::WorkroomHdmiOff;
        m_lightUpperOn          = m_addressDevice + Msop::WorkroomLUpperOn;
        m_lightUpperOff         = m_addressDevice + Msop::WorkroomLUpperOff;
        m_lightBortOn           = m_addressDevice + Msop::WorkroomLBortOn;
        m_lightBortOff          = m_addressDevice + Msop::WorkroomLBortOff;
        //direct

        m_localAddressDevice    = Msop::WorkroomArdress;
        m_tvDirectOn            = Msop::WorkroomTvDOn;
        m_tvDirectOff           = Msop::WorkroomTvDOff;
        m_hdmiDirectOn          = Msop::WorkroomHdmiDOn;
        m_hdmiDirectOff         = Msop::WorkroomHdmiDOff;
        m_lightDirectUpperOn    = Msop::WorkroomLDUpperOn;
        m_lightDirectUpperOff   = Msop::WorkroomLDUpperOff;
        m_lightDirectBortOn     = Msop::WorkroomLDBortOn;
        m_lightDirectBortOff    = Msop::WorkroomLDBortOff;

        m_shadesOpenStart       = Msop::WorkroomSDOpenStart;
        m_shadesOpenEnd         = Msop::WorkroomSDOpenEnd;
        m_shadesCloseStart      = Msop::WorkroomSDCloseStart;
        m_shadesCloseEnd        = Msop::WorkroomSDCloseEnd;
        break;
    case 3:
        m_tvOn                  = m_addressDevice + Msop::GlavzalTvOn;
        m_tvOff                 = m_addressDevice + Msop::GlavzalTvOff;
        m_hdmiOn                = m_addressDevice + Msop::GlavzalHdmiOn;
        m_hdmiOff               = m_addressDevice + Msop::GlavzalHdmiOff;
        m_lightUpperOn          = m_addressDevice + Msop::GlavzalLUpperOn;
        m_lightUpperOff         = m_addressDevice + Msop::GlavzalLUpperOff;
        m_lightBortOn           = m_addressDevice + Msop::GlavzalLBortOn;
        m_lightBortOff          = m_addressDevice + Msop::GlavzalLBortOff;
        m_lightHallUpperOn      = m_addressDevice + Msop::KoridorLUpperOn;
        m_lightHallUpperOff     = m_addressDevice + Msop::KoridorLUpperOff;
        m_lightHallBortOn       = m_addressDevice + Msop::KoridorLBortOn;
        m_lightHallBortOff      = m_addressDevice + Msop::KoridorLBortOff;
        //direct
        m_localAddressDevice      = Msop::GlavzalAdress;
        m_tvDirectOn              = Msop::GlavzalTvDOn;
        m_tvDirectOff             = Msop::GlavzalTvDOff;
        m_hdmiDirectOn            = Msop::GlavzalHdmiDOn;
        m_hdmiDirectOff           = Msop::GlavzalHdmiDOff;
        m_lightDirectUpperOn      = Msop::GlavzalLDUpperOn;
        m_lightDirectUpperOff     = Msop::GlavzalLDUpperOff;
        m_lightDirectBortOn       = Msop::GlavzalLDBortOn;
        m_lightDirectBortOff      = Msop::GlavzalLDBortOff;
        m_lightHallDirectUpperOn  = Msop::KoridorLDUpperOn;
        m_lightHallDirectUpperOff = Msop::KoridorLDUpperOff;
        m_lightHallDirectBortOn   = Msop::KoridorLDBortOn;
        m_lightHallDirectBortOff  = Msop::KoridorLDBortOff;
        break;
    default:
        m_addressDevice         = DevicesAddress::PZU1;
        break;
    }
    m_lightDecorOn    = m_addressDevice + Msop::DecorOn;
    m_lightDecorOff   = m_addressDevice + Msop::DecorOff;
    m_askDirectState     =  m_localAddressDevice + ServiceCmd::AskDirectCrntState;
    m_msopLocalAnswer    =  m_localAddressDevice + Msop::MsopAnswer;
}

void Configurator::switchToLightKoridor(){
    m_HallSwitched          = true;
    setLocalAddressDevice(Msop::KoridorAdress);
    setAskDirectState(Msop::KoridorAdress + ServiceCmd::AskDirectCrntState);
    setMsopLocalAnswer(Msop::KoridorAdress + Msop::MsopAnswer);
}

void Configurator::switchToLightGlavzal(){
    m_HallSwitched          = false;
    setLocalAddressDevice(Msop::GlavzalAdress);
    setAskDirectState(Msop::GlavzalAdress + ServiceCmd::AskDirectCrntState);
    setMsopLocalAnswer(Msop::GlavzalAdress + Msop::MsopAnswer);
}
