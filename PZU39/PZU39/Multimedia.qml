import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Layouts 1.1
import "."

Item {
    id: root
    width: parent.width
    height: parent.height
    property bool isKaraoke : false;
    MouseArea{
        anchors.fill: parent
        enabled: true;
    }

    TopBar{
        id: topbar
        text: qsTr("МУЛЬТИМЕДИА")+Settings.qstrUpdateHook;
    }

    Rectangle{
        anchors.top: topbar.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        color: Style.bgcolor
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0


        GridLayout{
            id: grid
            columns: 2
            rows: 3
            anchors.top: parent.top
            anchors.topMargin: Screen.pixelDensity*4
            anchors.horizontalCenter: parent.horizontalCenter
            property int cellWidth: root.width*0.4 ;
            property int cellHeight: isKaraoke ? root.height/4.2 : root.height/3;
            rowSpacing: isKaraoke ?  Screen.pixelDensity*2 : Screen.pixelDensity*4
            columnSpacing: Screen.pixelDensity*4
            //flow : GridLayout.TopToBottom
            //layoutDirection: Grid.AlignRight

            MenuButton{
                width: parent.cellWidth
                height: parent.cellHeight
                text: qsTr("CD/DVD")+Settings.qstrUpdateHook;
                onClicked: {
                    Settings.videocameraState = false;
                    Settings.airshowState = false;
                    SerialDevice.sendCommand(Configurator.menuDvdBluRay);
                    pageStack.push(comp4,{"isDvdMenu":"true","header":"CD/DVD"})
                }
            }
            MenuButton{
                width: parent.cellWidth
                height: parent.cellHeight
                text: qsTr("АУДИО")+Settings.qstrUpdateHook;
                onClicked: {
                    Settings.videocameraState = false;
                    Settings.airshowState = false;
                    SerialDevice.sendCommand(Configurator.menuAudio);
                    pageStack.push(comp4,{"isSlideShow":"true","header":qsTr("АУДИО")})
                }
            }
            MenuButton{
                width: parent.cellWidth
                height: parent.cellHeight
                text: qsTr("ВИДЕО")+Settings.qstrUpdateHook;
                onClicked: {
                    Settings.videocameraState = false;
                    Settings.airshowState = false;
                    SerialDevice.sendCommand(Configurator.menuVideo);
                    pageStack.push(comp4,{"isSlideShow":"true","header":qsTr("ВИДЕО")})
                }
            }
            MenuButton{
                width: parent.cellWidth
                height: parent.cellHeight
                text: qsTr("USB")+Settings.qstrUpdateHook;
                onClicked: {
                    Settings.videocameraState = false;
                    Settings.airshowState = false;
                    SerialDevice.sendCommand(Configurator.menuUsb);
                    pageStack.push(comp4,{"header":"USB"})
                }
            }

            MenuButton{
                anchors.horizontalCenter: parent.horizontalCenter
                width: grid.cellWidth
                height: grid.cellHeight
                text: qsTr("КАРАОКЕ")+Settings.qstrUpdateHook;
                onClicked: {
                    Settings.videocameraState = false;
                    Settings.airshowState = false;
                    SerialDevice.sendCommand(Configurator.menuKaraoke);
                    pageStack.push(comp4,{"isDvdMenu":"true","header":qsTr("КАРАОКЕ")})
                }
                visible: isKaraoke
            }

        }

    Component{
        id: comp4
        Player{

        }
    }

    Text{
        id: recCmd;
        width: 100
        height: 100
        font.pointSize: 24
        //color: Qt.transparent.toString();
        color: "black"
        text: SerialDevice.currentCmd;
        anchors.centerIn: parent
    }
}
}
