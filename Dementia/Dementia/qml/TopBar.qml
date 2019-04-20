import QtQuick 2.0
import QtQuick.Window 2.0

Rectangle {
    property alias title: titleText.text;
    property bool iconEnable: false;

    id: topBar;
    color: SettingsManager.bgInactiveColor;
    height: Screen.pixelDensity*10;
    anchors.left: parent.left;
    anchors.right: parent.right;
    anchors.top: parent.top;

    Text {
        id: titleText;
        anchors.centerIn: parent;
        font.family: SettingsManager.textFont;
        font.pointSize: SettingsManager.textFontH4;
        font.capitalization: Font.AllUppercase;
        color: SettingsManager.fgInactiveColor;
    }

    Text {
        id: backIcon;
        anchors.left: parent.left;
        anchors.top:  parent.top;
        anchors.bottom: parent.bottom;
        width: Screen.pixelDensity*15;
        text: "\uf112";
        font.family: SettingsManager.textFont;
        font.pointSize: SettingsManager.textFontH4;
        font.capitalization: Font.AllUppercase;
        color: SettingsManager.fgInactiveColor;
        horizontalAlignment: Text.AlignHCenter;
        verticalAlignment: Text.AlignVCenter;
        visible: iconEnable;

        MouseArea {
            anchors.fill: parent;
            onClicked: topBar.parent.parent.pop(topBar.parent.idx);
            enabled: iconEnable;
        }
    }

    opacity: 0;

    Behavior on opacity { NumberAnimation { duration: 1000; } }
}
