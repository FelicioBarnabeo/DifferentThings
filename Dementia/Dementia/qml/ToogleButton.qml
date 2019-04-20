import QtQuick 2.0

Rectangle {
    property bool checked: false;
    property alias itemTextSize: itemText.font.pointSize;
    property alias text: itemText.text;

    signal buttonClicked(var checked);

    function check() {
        checked = true;
        itemText.color = SettingsManager.fgActiveTextColor;
        button.color = SettingsManager.fgActiveColor;
        button.border.color = SettingsManager.fgActiveColor;
    }

    function uncheck() {
        checked = false;
        itemText.color = SettingsManager.fgInactiveColor;
        button.color = "transparent";
        button.border.color = SettingsManager.fgInactiveColor;
    }

    id: button;
    border.width: 1;
    border.color: SettingsManager.fgInactiveColor;
    color: "transparent"

    Text {
        id: itemText;
        anchors.centerIn: parent;
        font.family: SettingsManager.textFont;
        color: SettingsManager.fgInactiveColor;
    }

    MouseArea {
        anchors.fill: parent;
        onClicked: {
            if (!checked) {
                checked = true;
                itemText.color = SettingsManager.fgActiveTextColor;
                button.color = SettingsManager.fgActiveColor;
                button.border.color = SettingsManager.fgActiveColor;
                buttonClicked(checked);
            }
        }
    }
}
