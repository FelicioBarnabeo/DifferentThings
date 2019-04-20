import QtQuick 2.0
import QtQuick.Window 2.0

Item {
    property int maxVal: 1;
    property int value: 0;
    property bool externalControl: false;

    signal valueDataChanged(var val);

    function setValue(val) {
        externalControl = true;
        naviBar.value = val;
        calcXFromValue();
    }

    function calcXFromValue() {
        chunk.x = naviBar.value * naviBar.width / naviBar.maxVal - chunk.width/2;
    }

    function calcValueFromX() {
        naviBar.value = naviBar.maxVal* (chunk.x + chunk.width/2) / naviBar.width;
        if (naviBar.value < 0) naviBar.value=0;
        else if (naviBar.value > naviBar.maxVal) naviBar.value = maxVal;
        valueDataChanged(naviBar.value);
    }

    id: naviBar;
    height: chunk.height;

    Rectangle {
        id: outline;
        height: 2;
        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.verticalCenter: parent.verticalCenter;
        color: SettingsManager.fgInactiveColor;

        Rectangle {
            id: inline;
            height: 2;
            anchors.left: parent.left;
            width: chunk.x + 2;
            color: SettingsManager.fgActiveColor;
        }

        MouseArea {
            anchors.fill: parent;
            anchors.margins: -Screen.pixelDensity*2;
            onClicked: chunk.x = mouse.x - chunk.width;
        }
    }

    Rectangle {
        id: chunk;
        width: Screen.pixelDensity*5;
        height: Screen.pixelDensity*5;
        radius: Screen.pixelDensity*5;
        color: SettingsManager.fgActiveColor;
        antialiasing: true;
        smooth: true;
        onXChanged: (externalControl) ? externalControl = !externalControl
                                      : calcValueFromX();

        MouseArea {
            anchors.fill: parent;
            anchors.margins: -Screen.pixelDensity*2;
            drag.target: parent;
            drag.axis: Drag.XAxis;
            drag.minimumX: -chunk.width/2;
            drag.maximumX: naviBar.width - chunk.width/2;
            onPressAndHold: calcValueFromX();
        }
    }

    Component.onCompleted: calcXFromValue();

}
