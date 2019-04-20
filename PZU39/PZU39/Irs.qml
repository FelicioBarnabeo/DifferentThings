import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Layouts 1.1
import "."

Item {
    id: root
    width: parent.width
    height: parent.height
    MouseArea{
        anchors.fill: parent
        enabled: true;
    }

    TopBar{
        id: topbar
        text: qsTr("РАЗВЛЕЧЕНИЕ")+Settings.qstrUpdateHook;
    }

    Rectangle{
        anchors.top: topbar.bottom
        anchors.bottom: parent.bottom
        anchors.left: root.left
        anchors.right: root.right
        color: Style.bgcolor

        GridLayout{
            id: grid
            columns: 2
            rows: 3
            anchors.top: parent.top
            anchors.topMargin: Screen.pixelDensity*4
            anchors.horizontalCenter: parent.horizontalCenter
            property int cellWidth: root.width*0.40 ;
            property int cellHeight: root.height/4.2;
            rowSpacing: Screen.pixelDensity*2
            columnSpacing: Screen.pixelDensity*4

            MenuButton{
                width: parent.cellWidth
                height: parent.cellHeight
                state: Settings.hdmiState
                isCheckable: true
                text: qsTr("HDMI")
                fontsize: Style.fontSizeH1
                onClicked: {
                    if(Settings.hdmiState)
                        SerialDevice.sendCommand(Configurator.hdmiOff,Configurator.hdmiDirectOff);
                    else SerialDevice.sendCommand(Configurator.hdmiOn,Configurator.hdmiDirectOn);
                }
            }
            MenuButton{
                width: parent.cellWidth
                height: parent.cellHeight
                state: Settings.tvState
                isCheckable: true
                text: qsTr("TV ВКЛ / ВЫКЛ")+Settings.qstrUpdateHook;
                fontsize: Style.fontSizeH1
                onClicked: {
                    if(Settings.tvState) {
                        SerialDevice.sendCommand(Configurator.tvOff,Configurator.tvDirectOff);
                    }
                    else {
                        SerialDevice.sendCommand(Configurator.tvOn,Configurator.tvDirectOn);
                    }
                }
            }

            MenuButton{
                isCheckable: true
                state: Settings.airshowState
                width: parent.cellWidth
                height: parent.cellHeight
                text: qsTr("АЭРОШОУ")+Settings.qstrUpdateHook;
                fontsize: Style.fontSizeH1
                onClicked: {
                    SerialDevice.sendCommand(Configurator.airshow);
                    console.log("Airshow state = ", Settings.airshowState)
                    console.log("Video state =", Settings.videocameraState)

                }
            }
            MenuButton{
                isCheckable: true
                state: Settings.videocameraState
                width: parent.cellWidth
                height: parent.cellHeight
                text: qsTr("ВИДЕОКАМЕРА")+Settings.qstrUpdateHook;
                fontsize: Style.fontSizeH1
                onClicked: {
                    SerialDevice.sendCommand(Configurator.videocamera);
                    console.log("Video state =", Settings.videocameraState)
                    console.log("Airshow state=",Settings.airshowState)
                }
            }

            MenuButton{
                width: parent.cellWidth
                height: parent.cellHeight
                fontsize: Style.fontSizeH1
                text: qsTr("МУЛЬТИМЕДИА")+Settings.qstrUpdateHook;
                onClicked: {
                    if(choosenZone == 3){pageStack.push(comp3,{"isKaraoke":"true"})}
                    else pageStack.push(Qt.resolvedUrl("Multimedia.qml"))
                    SerialDevice.sendCommand(Configurator.menuEntertainment)
                }
            }

            MenuButton{
                width: parent.cellWidth
                height: parent.cellHeight
                text: qsTr("ГРОМКОСТЬ")+Settings.qstrUpdateHook;
                fontsize: Style.fontSizeH1
                onClicked: {
                    pageStack.push(Qt.resolvedUrl("Volume.qml"))
                }
                //onClicked: driver.sendCommand("KEY_2");
            }
        }
    }

    Component{
        id: comp3
        Multimedia{

        }
    }
}
