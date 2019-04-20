import QtQuick 2.0
import QtQuick.Window 2.0
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
        text: qsTr("ГЛАВНОЕ МЕНЮ")+Settings.qstrUpdateHook;
        isHome: false
        isBack: false
        PlayerButton{
            height: Screen.pixelDensity*6;
            width: Screen.pixelDensity*10;
            anchors.right: parent.right
            anchors.rightMargin: Screen.pixelDensity*2
            anchors.verticalCenter: parent.verticalCenter
            text: "\uf2f7"
            onRelease: pageStack.push(Qt.resolvedUrl("Configuration.qml"))
        }
    }

    Rectangle{
        anchors.top: topbar.bottom
        anchors.bottom: parent.bottom
        anchors.left: root.left
        anchors.right: root.right
        color: Style.bgcolor

        Column{
            spacing: Screen.pixelDensity*4
            anchors.centerIn:  parent
            property int cellWidth: root.width*0.7;
            property int cellHeight: root.height/5;

            MenuButton{
                width: parent.cellWidth
                height: parent.cellHeight
                text: qsTr("ОСВЕЩЕНИЕ")+Settings.qstrUpdateHook;
                onClicked: {
                    if(choosenZone == 1)
                        pageStack.push(comp2,{"isCell":"true","isBort":"true","isBed":"true","isDecor":"true"})
                    else if(choosenZone == 3)
                        pageStack.push(comp2,{"isGlavZal":"true"})
                    else
                        pageStack.push(comp2,{"isCell":"true","isBort":"true","isDecor":"true"})
                }
            }

            MenuButton{
                width: parent.cellWidth
                height: parent.cellHeight
                text: qsTr("РАЗВЛЕЧЕНИЕ")+Settings.qstrUpdateHook;
                onClicked: pageStack.push(Qt.resolvedUrl("Irs.qml"))
            }

            MenuButton{
                visible:  (Settings.currentZone!==3)
                width: parent.cellWidth
                height: parent.cellHeight
                text: qsTr("ШТОРЫ")+Settings.qstrUpdateHook;
                onClicked: pageStack.push(Qt.resolvedUrl("Shades.qml"))
            }
        }
    }

    Keys.onPressed: {
        if(event.key === Qt.Key_Home)
        {
            event.accepted = true;
            pageStack.pop(null)
        }
    }

    //Освещение отличается в разных зонах, поэтому чтобы передавать в стек страницу с выбранными свойствами
    //нужно создать компонент, потому что stack.push не знает что такое Light
    Component{
        id: comp2
        Ligth{

        }
    }
}
