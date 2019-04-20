import QtQuick 2.0
import ColorSlider 1.0
import "."
import QtQuick.Window 2.0

Item {
    id: root

    MouseArea{
        anchors.fill: parent
        enabled: true;
    }

    TopBar{
        id: topbar
        text: qsTr("ДЕКОРАТИВНОЕ")
    }

    Rectangle{
        //id: colorRect
        color: Style.bgcolor
        anchors.top: topbar.bottom
        anchors.topMargin: Screen.pixelDensity*3
        anchors.bottom: root.bottom
        anchors.left: root.left
        anchors.right: root.right
        ColorSlider{
            id: colorpicker
            anchors.fill: parent
            onText: qsTr("ВКЛ")
            offText: qsTr("ВЫКЛ")
            onOnClicked:  { driver.sendCommand("KEY_DECOR_ON",     "colorMngr") }
            onOffClicked: { driver.sendCommand("KEY_DECOR_OFF",    "colorMngr") }
            onSendColor: { driver.sendCommand("KEY_"+currentColor, "colorMngr")
                           /*console.log("SendColor:", currentColor)*/}
        }

    DownBar{
        id: downbar
    }
}
}


