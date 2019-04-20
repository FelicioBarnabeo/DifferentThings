import QtQuick 2.0

Rectangle {
    property alias text: noteText.text;
    function show() { note.visible = true; }
    function hide() { note.visible = false; }

    id: note;
    visible: false;
    anchors.centerIn: parent;
    border.color: SettingsManager.fgInactiveColor;
    border.width: 1;
    color: SettingsManager.bgInactiveColor;
    height: parent.height*0.2;
    width: parent.width*0.5;

    Text {
        id: noteText;
        font.family: SettingsManager.textFont;
        font.pointSize: SettingsManager.textFontH4;
        color: SettingsManager.fgInactiveColor;
        anchors.centerIn: parent;
    }

}
