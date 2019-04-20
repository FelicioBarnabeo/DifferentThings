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
        calcYFromValue();
    }

    function calcYFromValue() {
        chunk.y = (1 - (naviBar.value/maxVal)) * height - chunk.height/2;
    }

    function calcValueFromY() {
        naviBar.value = (1 - (1 - (naviBar.height - chunk.y - chunk.height/2) /naviBar.height)) * maxVal;
        if (naviBar.value < 0) naviBar.value=0;
        else if (naviBar.value > naviBar.maxVal) naviBar.value = maxVal;
        valueDataChanged(naviBar.value);
    }

    id: naviBar;
    width: chunk.width;

    Rectangle {
        id: outline;
        width: 2;
        anchors.top: parent.top;
        anchors.bottom: parent.bottom;
        anchors.horizontalCenter: parent.horizontalCenter;
        color: SettingsManager.fgInactiveColor;

        Rectangle {
            id: inline;
            width: 2;
            anchors.bottom: parent.bottom;
            height: parent.height - (chunk.y + chunk.width/2);
            color: SettingsManager.fgActiveColor;
        }

        MouseArea {
            anchors.fill: parent;
            anchors.margins: -Screen.pixelDensity*2;
            onClicked: chunk.y = mouse.y - chunk.height;
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
        onYChanged: (externalControl) ? externalControl = !externalControl
                                      : calcValueFromY();

        MouseArea {
            anchors.fill: parent;
            anchors.margins: -Screen.pixelDensity*5;
            drag.target: parent;
            drag.axis: Drag.YAxis;
            drag.minimumY: -chunk.height/2;
            drag.maximumY: naviBar.height - chunk.height/2;
            onPressAndHold: calcValueFromY();
        }
    }

    Component.onCompleted: calcYFromValue();

}
