import QtQuick 2.2
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import "."

Item {
    id: root
    property int choosenZone: 0;

    MouseArea{
        anchors.fill: parent
        enabled: true;
    }

    TopBar{
        id: topbar
        text: qsTr("ВЫБОР ЗОНЫ")
    }

    Keys.onPressed: {
        if(event.key === Qt.Key_Home)
        {
            event.accepted = true;
            pageStack.pop(null)
        }
    }

    Rectangle{
        anchors.top: topbar.bottom
        anchors.bottom: downbar.top
        anchors.left: root.left
        anchors.right: root.right
        color: Style.bgcolor
        Column{
            id: listZone
            spacing: Screen.pixelDensity*3
            anchors.centerIn:  parent
            property real cellWidth: root.width*0.95;
            property int cellHeight: root.height/7;


            MenuButton{
                text: qsTr("СПАЛЬНЯ ГП")
                width: listZone.cellWidth
                height:listZone.cellHeight
                onClicked: {
                    choosenZone = 1;
                    pageStack.push(comp,{"isEntertainment":"true","isLight":"true","isShades":"true"});
                }
            }
            MenuButton{
                text: qsTr("РАБОЧИЙ КАБИНЕТ ГП");
                width: listZone.cellWidth
                height: listZone.cellHeight
                onClicked: {
                    choosenZone = 2;
                    pageStack.push(comp,{"isEntertainment":"true","isLight":"true","isShades":"true"})
                }
            }
            MenuButton{
                text: qsTr("ГЛАВНЫЙ ЗАЛ");
                width: listZone.cellWidth
                height: listZone.cellHeight
                onClicked: {
                    choosenZone = 3;
                    pageStack.push(comp,{"isEntertainment":"true","isLight":"true"})
                }
            }
        }

    }

    DownBar{
        id: downbar
        onKey: loader.source = "ChooseLanguage.qml";
        isHome: false
    }

    Loader{
        id: loader
        anchors.fill: parent
    }

    StackView{
        id: pageStack
        anchors.fill: parent
    }

    Component{
        id: comp
        BaseMenu{

        }
    }




}

