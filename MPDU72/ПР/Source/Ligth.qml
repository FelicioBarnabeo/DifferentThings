import QtQuick 2.0
import QtQuick.Window 2.0
import "."

Item {
    id: root
    //anchors.fill: parent
    property bool isCell: false
    property bool isBort: false
    property bool isBed: false
    property bool isDecor: false
    TopBar{
        id: topbar
        text: qsTr("ОСВЕЩЕНИЕ")
    }

    MouseArea{
        anchors.fill: parent
        enabled: true;
    }

    Rectangle{
        anchors.top: topbar.bottom
        anchors.bottom: downbar.top
        anchors.left: root.left
        anchors.right: root.right

        color: Style.bgcolor
        Column{
            spacing: Screen.pixelDensity*3
            anchors.centerIn:  parent
            property int cellWidth: root.width*0.8 ;
            property int cellHeight: root.height/7;

            MenuButton{
               id: cell
               width: parent.cellWidth
               height: parent.cellHeight
               text: qsTr("ПОТОЛОЧНОЕ")
               visible: root.isCell;
               onClicked: driver.sendCommand("KEY_LIGHT_POT","msophex");
            }
            MenuButton{
               id: bort
               width: parent.cellWidth
               height: parent.cellHeight
               text: qsTr("БОРТОВОЕ")
               visible: root.isBort;
               onClicked: driver.sendCommand("KEY_LIGHT_BORT","msophex");
            }
            MenuButton{
               id:bed
               width: parent.cellWidth
               height: parent.cellHeight
               text: qsTr("ПОДСВЕТ НИШИ")
               visible: root.isBed;
               onClicked: driver.sendCommand("KEY_LIGHT_BED","msophex");
            }
            MenuButton{
               id: decor
               width: parent.cellWidth
               height: parent.cellHeight
               text: qsTr("ДЕКОРАТИВНОЕ")
               visible: root.isDecor;
               onClicked: {
                   pageStack.push(Qt.resolvedUrl("DecorLight.qml"))
               }
            }
//            MenuButton{
//                id: decorKoridor
//                width: parent.cellWidth
//                height: parent.cellHeight
//                text: qsTr("КОРИДОР")
//                visible: root.isDecorKoridor;
//                onClicked:{
//                    pageStack.push(Qt.resolvedUrl("DecorLight.qml"))
//                    //Send code koridor
//                }
//            }
        }
    }

    DownBar{
        id: downbar
    }
}
