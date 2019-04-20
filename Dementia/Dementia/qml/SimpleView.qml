import QtQuick 2.0
import QtQuick.Window 2.0

ListView {
    signal itemClicked(var val);
    property int itemAlign: 0;
    property bool slice: false;
    property int sliceCount: 0;

    id: simpleView;
    clip: true;
    focus: true;

    delegate: Item {
        width: simpleView.width;
        height: Screen.pixelDensity*8;
        Rectangle {
            width: separator.width;
            height: parent.height;
            anchors.horizontalCenter: parent.horizontalCenter;
            color: (simpleView.currentIndex == index) ?
                       SettingsManager.fgActiveColor: "transparent";
            Behavior on color { ColorAnimation { duration: 500}}

        }

        Text {
            id: itemText;
            anchors.left: separator.left;
            anchors.right: separator.right;
            anchors.verticalCenter: parent.verticalCenter;
            text: (slice) ? model.modelData.slice(0,-sliceCount) : model.modelData;
            font.family: SettingsManager.textFont;
            font.pointSize: SettingsManager.textFontH5;
            color: (simpleView.currentIndex == index) ?
                       SettingsManager.fgActiveTextColor:SettingsManager.fgInactiveColor;
            horizontalAlignment: simpleView.itemAlign;
            elide: Text.ElideRight;
        }

        Rectangle {
            id: separator;
            color: SettingsManager.fgInactiveColor;
            width: parent.width - Screen.pixelDensity*10;
            height: 1;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.bottom: parent.bottom;
        }
        MouseArea {
            anchors.fill: parent;
            onClicked: {
                simpleView.currentIndex = index;
                itemClicked(model.modelData);
            }
        }

    }


}
