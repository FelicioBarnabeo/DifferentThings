import QtQuick 2.0
import QtQuick.Window 2.0
import "."

Item {
    id: root
    width: parent.width
    height: parent.height
    property bool isDvdMenu: false
    property bool isSlideShow: false
    property string header: ""

    MouseArea{
        anchors.fill: parent
        enabled: true;
    }

    TopBar{
        id: topbar
        text: qsTr(header)+Settings.qstrUpdateHook;
    }

    Rectangle
    {
        id: window
        anchors.top: topbar.bottom
        anchors.bottom: root.bottom
        anchors.left: root.left
        anchors.right: root.right
        color: Style.bgcolor

            Row{
                id: firstRow
                height: Screen.pixelDensity*12
                anchors.top: parent.top
                anchors.topMargin: Screen.pixelDensity*7
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: Screen.pixelDensity*5


                PlayerButton
                {
                    id: fastRightForward
                    width: Screen.pixelDensity*10
                    height: Screen.pixelDensity*10

                    text: "\uf4ab"
                    onKey: { if(isDvdMenu) SerialDevice.sendCommand(Configurator.dvdFastForward);
                        else SerialDevice.sendCommand(Configurator.avuFastForward);}
                    onRelease: SerialDevice.stopSendCmd();
                    onHoldKey:
                    {
                        if(isDvdMenu) SerialDevice.startSendCmd(Configurator.dvdFastForward);
                        else
                        {
                            SerialDevice.startSendCmd(Configurator.avuFastForward);
                            console.log("FAST FORWARD RIGHT PRESS");
                        }
                    }
                }

                PlayerButton{
                    id: stop
                    width: Screen.pixelDensity*10
                    height: Screen.pixelDensity*10
                    text: "\uf24f"
                    onKey: { if(isDvdMenu) SerialDevice.sendCommand(Configurator.dvdStop);
                            else SerialDevice.sendCommand(Configurator.avuStop);}
                }

                PlayerButton{
                    id: up
                    width: Screen.pixelDensity*10
                    height: Screen.pixelDensity*10
                    text: "\uf10d"
                    onKey: {if(isDvdMenu) SerialDevice.sendCommand(Configurator.dvdUp);
                                     else SerialDevice.sendCommand(Configurator.avuUp);}
                    onRelease:  SerialDevice.stopSendCmd();
                    onHoldKey:  {if(isDvdMenu) SerialDevice.startSendCmd(Configurator.dvdUp);
                                         else  SerialDevice.startSendCmd(Configurator.avuUp);}
                }

                PlayerButton{
                    id: pause
                    width: Screen.pixelDensity*10
                    height: Screen.pixelDensity*10
                    text: "\uf478"
                    onKey: { if(isDvdMenu) SerialDevice.sendCommand(Configurator.dvdPause);
                        else SerialDevice.sendCommand(Configurator.avuPause);}
                }

                PlayerButton{
                    id: fastLeftForward
                    width: Screen.pixelDensity*10
                    height: Screen.pixelDensity*10

                    text: "\uf4ad"
                    onKey: { if(isDvdMenu) SerialDevice.sendCommand(Configurator.dvdFastRewind);
                        else SerialDevice.sendCommand(Configurator.avuFastRewind);}
                    onRelease: SerialDevice.stopSendCmd();
                    onHoldKey: { if(isDvdMenu) SerialDevice.startSendCmd(Configurator.dvdFastRewind);
                        else SerialDevice.startSendCmd(Configurator.avuFastRewind);}
                }

            }

            Row{
                id: secondRow
                anchors.top : firstRow.bottom
                anchors.topMargin: Screen.pixelDensity*7
                height: Screen.pixelDensity*12
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: Screen.pixelDensity*5

                PlayerButton{
                    id: leftForward
                    width: Screen.pixelDensity*10
                    height: Screen.pixelDensity*10

                    text: "\uf4a1"
                    onKey: { if(isDvdMenu) SerialDevice.sendCommand(Configurator.dvdRewind);
                        else SerialDevice.sendCommand(Configurator.avuRewind);}
                    onRelease: SerialDevice.stopSendCmd();
                    onHoldKey: { if(isDvdMenu) SerialDevice.startSendCmd(Configurator.dvdRewind);
                        else SerialDevice.startSendCmd(Configurator.avuRewind);}

                }

                PlayerButton{
                    id: left
                    width: Screen.pixelDensity*10
                    height: Screen.pixelDensity*10
                    text: "\uf107"
                    onKey: {if(isDvdMenu) SerialDevice.sendCommand(Configurator.dvdLeft);
                                     else SerialDevice.sendCommand(Configurator.avuLeft);}
                    onRelease:  SerialDevice.stopSendCmd();
                    onHoldKey:  {if(isDvdMenu) SerialDevice.startSendCmd(Configurator.dvdLeft);
                                         else  SerialDevice.startSendCmd(Configurator.avuLeft);}
                }

                PlayerButton{
                    id: play
                    width: Screen.pixelDensity*10
                    height: Screen.pixelDensity*10
                    text: "\uf215"
                    onKey: {
                        if(isDvdMenu) SerialDevice.sendCommand(Configurator.dvdPlay);
                                 else SerialDevice.sendCommand(Configurator.avuPlay);
                    }
                }

                PlayerButton{
                    id: right
                    width: Screen.pixelDensity*10
                    height: Screen.pixelDensity*10
                    text: "\uf10a"
                    onKey: {if(isDvdMenu) SerialDevice.sendCommand(Configurator.dvdRight);
                                     else SerialDevice.sendCommand(Configurator.avuRight);}
                    onRelease:  SerialDevice.stopSendCmd();
                    onHoldKey:  {if(isDvdMenu) SerialDevice.startSendCmd(Configurator.dvdRight);
                                         else  SerialDevice.startSendCmd(Configurator.avuRight);}
                }

                PlayerButton{
                    id: rightForward
                    width: Screen.pixelDensity*10
                    height: Screen.pixelDensity*10
                    text: "\uf427"
                    onKey: { if(isDvdMenu) SerialDevice.sendCommand(Configurator.dvdForward);
                        else SerialDevice.sendCommand(Configurator.avuForward);}
                    onRelease: SerialDevice.stopSendCmd();
                    onHoldKey: { if(isDvdMenu) SerialDevice.startSendCmd(Configurator.dvdForward);
                        else SerialDevice.startSendCmd(Configurator.avuForward);}
                }

            }

//            Row{
//                id: thirdRow
//                anchors.top : secondRow.bottom
//                anchors.topMargin: Screen.pixelDensity*4
//                height: Screen.pixelDensity*12
//                anchors.horizontalCenter: parent.horizontalCenter
//                spacing: Screen.pixelDensity*5
                PlayerButton{
                    visible: isDvdMenu
                    id: eject
                    width: Screen.pixelDensity*20
                    height: Screen.pixelDensity*10
                    text: "\uf131"
                    anchors.left: parent.left
                    anchors.leftMargin: Screen.pixelDensity*7
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: Screen.pixelDensity*4
                    onKey: SerialDevice.sendCommand(Configurator.dvdEject)
                }

                PlayerButton{
                    id: down
                    width: Screen.pixelDensity*10
                    height: Screen.pixelDensity*10
                    text: "\uf104"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: Screen.pixelDensity*4
                    onKey: {if(isDvdMenu) SerialDevice.sendCommand(Configurator.dvdDown);
                                     else SerialDevice.sendCommand(Configurator.avuDown);}
                    onRelease:  SerialDevice.stopSendCmd();
                    onHoldKey:  {if(isDvdMenu) SerialDevice.startSendCmd(Configurator.dvdDown);
                                         else  SerialDevice.startSendCmd(Configurator.avuDown);}
                }

                PlayerButton{
                    id: menuSlide
                    width: Screen.pixelDensity*20
                    height: Screen.pixelDensity*10
                    text: isDvdMenu ? "\uf394" : "\uf2d3"
                    visible: (isSlideShow || isDvdMenu)
                    anchors.right: parent.right
                    anchors.rightMargin: Screen.pixelDensity*7
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: Screen.pixelDensity*4
                    onKey: {if(isDvdMenu) SerialDevice.sendCommand(Configurator.dvdDiskMenu);
                        else SerialDevice.sendCommand(Configurator.avuSlideShow);}
                }
            }
}

