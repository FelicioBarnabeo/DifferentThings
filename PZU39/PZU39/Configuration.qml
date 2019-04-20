import QtQuick 2.0
import QtQuick.Window 2.0
import "."

Item{
    id: root
    width: parent.width
    height: parent.height

    MouseArea{
        anchors.fill: parent
        enabled: true;
    }

    TopBar{
        id: topbar
        text: qsTr("КОНФИГУРАЦИЯ")+Settings.qstrUpdateHook;
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
            text: qsTr("ВЫБОР ЯЗЫКА")+Settings.qstrUpdateHook;
            onClicked: pageStack.push(Qt.resolvedUrl("ChooseLanguage.qml"))
        }

        MenuButton{
            width: parent.cellWidth
            height: parent.cellHeight
            text: qsTr("ЯРКОСТЬ")+Settings.qstrUpdateHook;
            onClicked: pageStack.push(Qt.resolvedUrl("ChooseBrgt.qml"))
        }
    }
}
}

