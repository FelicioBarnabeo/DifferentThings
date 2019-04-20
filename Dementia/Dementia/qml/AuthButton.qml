import QtQuick 2.0
import QtQuick.Window 2.0

Rectangle {
    property alias text: itemText.text;
    signal buttonClicked(var data);

    id: button;
    width: Screen.pixelDensity*20;
    height: Screen.pixelDensity*10;
    border.width: 1;
    border.color: SettingsManager.fgInactiveColor;
    color: "transparent"

    Text {
        id: itemText;
        anchors.centerIn: parent;
        font.family: SettingsManager.textFont;
        font.pointSize: SettingsManager.textFontH5;
        color: SettingsManager.fgInactiveColor;
    }

    MouseArea {
        anchors.fill: parent;
        onPressed: {
            itemText.color = SettingsManager.fgActiveTextColor;
            button.color = SettingsManager.fgActiveColor;
            button.border.color = SettingsManager.fgActiveColor;
        }
        onReleased: {
            itemText.color = SettingsManager.fgInactiveColor;
            button.color = "transparent";
            button.border.color = SettingsManager.fgInactiveColor;
            buttonClicked(itemText.text);
        }
    }
}
