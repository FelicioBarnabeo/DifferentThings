import QtQuick 2.0
import QtQuick.Window 2.0
import "."

Item {
    id:root

    MouseArea{
        anchors.fill: parent
        enabled: true;
    }

    TopBar{
        id: topbar
        text: qsTr("ШТОРЫ")+Settings.qstrUpdateHook;
    }

//    Timer {
//        id: openDelay;
//        interval: 100;
//        repeat: false;
//        onTriggered: {
//            SerialDevice.sendCommand(Configurator.shadesOpenEnd,"");
//        }
//    }

//    Timer {
//        id: closeDelay;
//        interval: 100;
//        repeat: false;
//        onTriggered: {
//            SerialDevice.sendCommand(Configurator.shadesCloseEnd,"");
//        }
//    }

    Rectangle{
        anchors.top: topbar.bottom
        anchors.bottom: parent.bottom
        anchors.left: root.left
        anchors.right: root.right
        color: Style.bgcolor

            Rectangle{
                id: up
                anchors.top: parent.top
                anchors.topMargin: Screen.pixelDensity*3
                anchors.horizontalCenter: parent.horizontalCenter
                height: Screen.pixelDensity*15
                width: Screen.pixelDensity*40
                radius: width/2
                color: Style.inactiveBtnColor
                border.color: Style.borderMenuBtnColor
                border.width: 3
                Text{
                    anchors.centerIn: parent
                    font.family: Style.fontIcon
                    text: "\uf126"
                    font.pointSize: 18
                    font.bold: true
                    color: Style.fgColor
                }
                MouseArea{
                    anchors.fill: parent
                    anchors.margins: -10
                    onPressed:{
                        parent.color = Style.activeBtnColor
                    }

                    onPressAndHold: {
                        SerialDevice.sendCommand(Configurator.shadesOpenStart, "");
                        SerialDevice.sendCommand(Configurator.shadesBathOpenStart, "");
                        parent.color = Style.activeBtnColor
                    }
                    onReleased: {
                        SerialDevice.sendCommand(Configurator.shadesOpenEnd,"");
                        SerialDevice.sendCommand(Configurator.shadesBathOpenEnd, "");
                        parent.color = Style.inactiveBtnColor
                    }
                }
            }
            Image{
                source: "images/whiteShades.png"
                anchors.centerIn: parent
                width: 50
                height: 50
                antialiasing: true
            }

            Rectangle{
                id:down
                anchors.bottom: parent.bottom
                anchors.bottomMargin: Screen.pixelDensity*3
                anchors.horizontalCenter: parent.horizontalCenter
                height: Screen.pixelDensity*15
                width: Screen.pixelDensity*40
                color: Style.inactiveBtnColor
                border.color: Style.borderMenuBtnColor
                border.width: 3
                radius: width/2
                Text{
                    anchors.centerIn: parent
                    font.family: Style.fontIcon
                    text: "\uf123"
                    font.bold: true
                    font.pointSize: 18
                    color: Style.fgColor
                }
                MouseArea{
                    anchors.fill: parent
                    anchors.margins: -10
                    onPressed:{
                        parent.color = Style.activeBtnColor
                    }
                    onPressAndHold: {
                        parent.color = Style.activeBtnColor
                        SerialDevice.sendCommand(Configurator.shadesCloseStart, "");
                        SerialDevice.sendCommand(Configurator.shadesBathCloseStart, "");
                    }
                    onReleased: {
                        parent.color = Style.inactiveBtnColor
                        SerialDevice.sendCommand(Configurator.shadesCloseEnd, "");
                        SerialDevice.sendCommand(Configurator.shadesBathCloseEnd, "");
                    }
                }
            }
        }
}
