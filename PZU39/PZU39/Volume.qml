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
        text: qsTr("ГРОМКОСТЬ")
    }

    Rectangle{
        anchors.top: topbar.bottom
        anchors.bottom: parent.bottom
        anchors.left: root.left
        anchors.right: root.right
        color: Style.bgcolor

        PlayerButton {
            text: "\uf209";
            height: Screen.pixelDensity*12;
            width: Screen.pixelDensity*12;
            onKey: if(volumeLine.value != 0) volumeLine.value--;
            anchors.right: volumeLine.left
            anchors.rightMargin: Screen.pixelDensity*5
            anchors.verticalCenter: parent.verticalCenter
        }


        VolumeIndicator{
            id: volumeLine
            width: 120
            anchors.centerIn: parent
        }

        PlayerButton {
            text: "\uf218";
            height: Screen.pixelDensity*12;
            width: Screen.pixelDensity*12;
            onKey: if(volumeLine.value != 10) volumeLine.value++;
            anchors.left: volumeLine.right
            anchors.leftMargin: Screen.pixelDensity*5
            anchors.verticalCenter: parent.verticalCenter
        }
    }

//    Component.onCompleted: {
//        SerialDevice.sendCommand(Configurator.getCurrentVolume);
//    }

    Text{
        id: recCmd;
        width: 100
        height: 100
        font.pointSize: 24
        //color: Qt.transparent.toString();
        color: "black"
        text: SerialDevice.currentCmd;
        anchors.centerIn: parent
    }
}
