import QtQuick 2.0
import QtQuick.Window 2.0
import "."

Item {
    id: root
    property bool isKaraoke : false;

    MouseArea{
        anchors.fill: parent
        enabled: true;
    }

    TopBar{
        id: topbar
        text: qsTr("МУЛЬТИМЕДИА")
    }

    Rectangle{
        anchors.top: topbar.bottom
        anchors.bottom: downbar.top
        anchors.left: root.left
        anchors.right: root.right
        color: Style.bgcolor

        Column{
            anchors.centerIn:  parent
            spacing: Screen.pixelDensity*2
            property int cellWidth: root.width*0.7 ;
            property int cellHeight: root.height/7;
            MenuButton{
                width: parent.cellWidth
                height: parent.cellHeight
                text: qsTr("CD/DVD")
                onClicked: {
                    driver.sendCommand("KEY_1");
                    pageStack.push(comp,{"isDvdMenu":"true","header":qsTr("CD/DVD")})
                }
            }
            MenuButton{
                width: parent.cellWidth
                height: parent.cellHeight
                text: qsTr("АУДИО")
                onClicked: {
                    driver.sendCommand("KEY_4");
                    pageStack.push(comp,{"isSlideShow":"true","header":qsTr("АУДИО")})
                }
            }
            MenuButton{
                width: parent.cellWidth
                height: parent.cellHeight
                text: qsTr("ВИДЕО")
                onClicked: {
                    driver.sendCommand("KEY_5");
                    pageStack.push(comp,{"isSlideShow":"true","header":qsTr("ВИДЕО")})
                }
            }
            MenuButton{
                width: parent.cellWidth
                height: parent.cellHeight
                text: qsTr("USB")
                onClicked: {
                    driver.sendCommand("KEY_6");
                    pageStack.push(comp,{"header":qsTr("USB")})
                }
            }
            MenuButton{
                width: parent.cellWidth
                height: parent.cellHeight
                text: qsTr("КАРАОКЕ")
                onClicked: {
                    driver.sendCommand("KEY_lambda");
                    pageStack.push(comp,{"isDvdMenu":"true","header":qsTr("КАРАОКЕ")})
                }
                visible: isKaraoke
            }
        }
    }
    DownBar{
        id: downbar
    }

    Component{
        id: comp
        Player{

        }
    }
}
