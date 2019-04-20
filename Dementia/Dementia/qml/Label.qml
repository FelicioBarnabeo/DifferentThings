import QtQuick 2.0
import QtQuick.Window 2.0

Rectangle {
    property alias labelText: _labelText.text;

    border.color: SettingsManager.fgActiveColor;
    border.width: 1;
    radius: height;
    color: "transparent";

    Text {
        id: _labelText;
        anchors.centerIn: parent;
        font.family: SettingsManager.textFont;
        font.pointSize: SettingsManager.textFontH4;
        color: SettingsManager.fgInactiveColor;
    }
}
