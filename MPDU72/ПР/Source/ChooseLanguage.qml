import QtQuick 2.0
import QtQuick.Window 2.0
import "."

Item {
    id: root
    anchors.fill: parent
    property string mainLanguage : mainApp.language;
    MouseArea{
        anchors.fill: parent
        enabled: true;
    }

    TopBar{
        id: topbar
        text: qsTr("ЯЗЫК / LANGUAGE")
    }

    Rectangle{
        anchors.top: topbar.bottom
        anchors.bottom: root.bottom
        anchors.left: root.left
        anchors.right: root.right
        color: Style.bgcolor

        Column{
            id: listZone
            spacing: Screen.pixelDensity*3
            anchors.centerIn:  parent
            property int cellWidth: root.width*0.9;
            property int cellHeight: root.height/7;
            MenuButton{
                text: qsTr("РУССКИЙ")
                width: listZone.cellWidth
                height: listZone.cellHeight
                onClicked:{
                    //console.log("rus click")
                    mainApp.setLanguage("ru");
                    loader.source = "Zones.qml"
                }
            }

            MenuButton{
                text: qsTr("ENGLISH")
                width: listZone.cellWidth
                height: listZone.cellHeight
                onClicked: {
                    //console.log("eng click")
                    mainApp.setLanguage("en");
                    loader.source = "Zones.qml";
                }
            }
        }
    }

    Loader{
        focus: true
        id: loader;
        active: true
        anchors.fill: parent
    }

}
