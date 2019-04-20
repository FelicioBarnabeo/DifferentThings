import QtQuick 2.0

Rectangle {
    property int size: 0;
    property alias itemTextSize: itemText.font.pointSize;
    property alias icon: itemText.text;
    property alias itemFont: itemText.font.family;
    property bool circleType: true;

    signal itemClicked();

    id: button;
    width: if (circleType) return (size);
    height: if (circleType) return (size);
    radius: if (circleType) return (size); else return(0);
    border.width: 1;
    border.color: SettingsManager.fgInactiveColor;
    color: "transparent"

    Text {
        id: itemText;
        font.family: SettingsManager.iconFont;
        anchors.centerIn: parent;
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
            itemClicked();
        }
    }
}
