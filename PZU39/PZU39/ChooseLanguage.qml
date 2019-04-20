import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 1.2
import "."

Item {
    id: root
    property bool flagLang : false
    //property int choosenZone: Settings.currentZone;
    MouseArea{
        anchors.fill: parent
        enabled: true;
    }

    TopBar{
        id: topbar
        text: qsTr("ЯЗЫК / LANGUAGE")
        isHome: false
    }

    Rectangle{
        anchors.top: topbar.bottom
        anchors.bottom: parent.bottom
        anchors.left: root.left
        anchors.right: root.right
        color: Style.bgcolor

        Column{
            id: listZone
            spacing: Screen.pixelDensity*5
            anchors.centerIn:  parent
            property int cellWidth: root.width*0.7;
            property int cellHeight: root.height/5;
            ToggleButton{
                id: ruToggle
                text: qsTr("РУССКИЙ")
                width: listZone.cellWidth
                height: listZone.cellHeight
                onClicked:{
                    //console.log("rus click")
                    Settings.setLang("ru");
                    if(enToggle.active) enToggle.active = false;
                    pageStack.clear();
                    pageStack.push(Qt.resolvedUrl("BaseMenu.qml"))
                }

            }

            ToggleButton{
                id: enToggle
                text: qsTr("ENGLISH")
                width: listZone.cellWidth
                height: listZone.cellHeight
                onClicked: {
                    //console.log("eng click")
                    Settings.setLang("en");
                    if(ruToggle.active) ruToggle.active = false;
                    pageStack.clear();
                    pageStack.push(Qt.resolvedUrl("BaseMenu.qml"))
                }
            }
        }

//        PlayerButton{
//            id: toMenu
//            anchors.right: parent.right
//            anchors.bottom: parent.bottom
//            anchors.margins: 2
//            width: Screen.pixelDensity*7.3
//            height: Screen.pixelDensity*7.3
//            text: "\uf2f8"
//            onRelease: pageStack.pop(null)
//        }
    }

}
