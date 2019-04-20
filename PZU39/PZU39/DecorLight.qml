import QtQuick 2.0
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
        text: qsTr("ДЕКОРАТИВНОЕ")+Settings.qstrUpdateHook;
    }

    Rectangle{
        color: Style.bgcolor
        anchors.top: topbar.bottom
        anchors.bottom: root.bottom
        anchors.left: root.left
        anchors.right: root.right

        ColorWheel{
            id: colorpicker
            anchors.fill: parent
            onText:  qsTr("ВКЛ") + Settings.qstrUpdateHook;
            offText: qsTr("ВЫКЛ")+ Settings.qstrUpdateHook;
            onOnClicked: {SerialDevice.sendCommand(Configurator.lightDecorOn);}
            onOffClicked: {SerialDevice.sendCommand(Configurator.lightDecorOff);}
            onSendColor:
            {
                var str = colorSend.replace('#', Configurator.addressDevice);
                SerialDevice.sendCommand(str);
            }
        }
}
}


