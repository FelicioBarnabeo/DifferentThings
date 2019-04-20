import QtQuick 2.0
import QtQuick.Window 2.0

import "."

Item {
    id: root
    focus: true
    MouseArea{
        anchors.fill: parent
        enabled: true;
    }

    TopBar{
        id: topbar
        text: qsTr("ГЛАВНОЕ МЕНЮ")
    }


    Keys.onPressed: {
        if(event.key === Qt.Key_Home)
        {
            event.accepted = true;
            pageStack.pop(null)
        }
    }

    Rectangle{
        id: rect
        anchors.top: topbar.bottom
        anchors.bottom: downbar.top
        anchors.left: root.left
        anchors.right: root.right
        color: Style.bgcolor

        Column{
            anchors.centerIn:  parent
            //anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: Screen.pixelDensity*2
            spacing: Screen.pixelDensity*2

            property int cellWidth: root.width*0.8 ;
            property int cellHeight: root.height/5;

            MenuButton{
                width: parent.cellWidth
                height: parent.cellHeight
                text: qsTr("МУЛЬТИМЕДИА")
                onClicked: {
                    //if(choosenZone == 3){pageStack.push(comp,{"isKaraoke":"true","header":qsTr("Мультимедиа")})}
                    pageStack.push(Qt.resolvedUrl("Multimedia.qml"))
                }
            }
            MenuButton{
                width: parent.cellWidth
                height: parent.cellHeight
                text: qsTr("АЭРОШОУ")
                onClicked: driver.sendCommand("KEY_3");
            }
        }
    }


    Component{

        id: comp
        Multimedia{

        }
    }
    DownBar{
        id: downbar
    }

}
