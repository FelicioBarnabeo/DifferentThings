import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 1.2
import "."

Item {
    id: root
    MouseArea{
        anchors.fill: parent
        enabled: true;
    }

    TopBar{
        id: topbar
        text: qsTr("РУЧНАЯ НАСТРОЙКА")
        isHome: false
    }

    Rectangle{
        anchors.top: topbar.bottom
        anchors.bottom: parent.bottom
        anchors.left: root.left
        anchors.right: root.right
        color: Style.bgcolor

        Text{
            anchors.top: parent.top
            anchors.topMargin: Screen.pixelDensity*5
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("ЯРКОСТЬ");
            font.pointSize: Style.fontSizeH3
            color: "white"
        }

        Slider{
            id: slider
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            tickmarksEnabled: true
            stepSize: 0.34
            width: 200
            height: 50
            onValueChanged: {
                var arg = "7";
                if(slider.value == 0) arg="3";
                if(slider.value == 0.34) arg="4";
                if(slider.value == 0.68) arg="5";
                if(slider.value == 1) arg="7";
                Settings.setBrightnessLevel(arg);
            }
            Component.onCompleted: {
                var arg = Settings.brightnessLevel;
                if(arg=="3") slider.value=0;
                if(arg=="4") slider.value=0.34;
                if(arg=="5") slider.value=0.68;
                if(arg=="7") slider.value=1;
            }
        }
    }

    PlayerButton{
        id: ok
        anchors.bottom: parent.bottom
        anchors.bottomMargin: Screen.pixelDensity*5
        anchors.horizontalCenter: parent.horizontalCenter
        width: Screen.pixelDensity*12
        height: Screen.pixelDensity*12
        onRelease: {
            pageStack.pop(null)
            //if(text=="\uf215") driver.sendCommand("KEY_7","vista_mce");
            //else driver.sendCommand("KEY_8","vista_mce")
        }
        Text{
            color: Style.fgColor
            text: "OK"
            font.pointSize: 14
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter;
            verticalAlignment: Text.AlignVCenter;
        }
    }
}
