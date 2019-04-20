import QtQuick 2.0
import QtQuick.Window 2.0

Rectangle {
    signal keyEvent(var key);

    property int size: Screen.pixelDensity*17;
    property alias key: vkeyText.text;
    property alias altkey: valtkeyText.text;
    property bool alt: false;

    id: vkey;
    width: size;
    height: size*0.7;
    color: "#FFF2F2F2";
    radius: Screen.pixelDensity;
    border.width: 1;
    border.color: "black";

    Text {
        id: vkeyText;
        anchors.centerIn: parent;
        color: "black";
        visible: !alt;
    }

    Text {
        id: valtkeyText;
        anchors.centerIn: parent;
        color: "black";
        visible: alt;
    }

    MouseArea {
        anchors.fill: parent;
        onClicked: (alt) ? parent.keyEvent(valtkeyText.text)
                         : parent.keyEvent(vkeyText.text);
        onPressed: parent.color = "grey";
        onReleased: parent.color = "#FFF2F2F2";
    }
}
