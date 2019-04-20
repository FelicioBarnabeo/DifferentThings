import QtQuick 2.0
import QtQuick.Window 2.0
import "."

Item {
    id: root
    width: parent.width
    height: parent.height
    //anchors.fill: parent

    MouseArea{
        anchors.fill: parent
        enabled: true;
    }

    TopBar{
        id: topbar
        text: qsTr("НАСТРОЙКА ЯРКОСТИ")
        isHome: false
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
                    text: qsTr("АВТОМАТИЧЕСКАЯ")+Settings.qstrUpdateHook;
                    onClicked: {
                        Settings.setBrtMode(0);
                        pageStack.pop(null)
                    }
                }

                MenuButton{
                    width: parent.cellWidth
                    height: parent.cellHeight
                    text: qsTr("РУЧНАЯ")+Settings.qstrUpdateHook;
                    onClicked:
                    {
                        Settings.setBrtMode(1);
                        pageStack.push(Qt.resolvedUrl("Brightness.qml"))
                    }
                }
        }
    }
}
