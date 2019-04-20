import QtQuick 2.0
import QtQuick.Window 2.0

Item {
    property bool playState: true;
    property real volume: 0;
    property alias duration: _progressBar.maxVal;
    signal exit();
    signal seek(var pos);

    function setProgressPosition(val) {
        _progressBar.setValue(val);
    }

    id: videoPlayerControl;
    visible: false;

    Rectangle {
        id: _volBarFrame;
        anchors.top: parent.top;
        anchors.bottom: _progressBarFrame.top;
        anchors.right: parent.right;
        width: Screen.pixelDensity*20;
        color: "#A0000000";

        Button {
            id: _exit;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.top: parent.top;
            anchors.topMargin: Screen.pixelDensity*5;
            size: Screen.pixelDensity*12;
            itemTextSize: SettingsManager.iconFontH5;
            onItemClicked: videoPlayerControl.exit();
            icon: "\uf112";
        }

        Button {
            id: _playPause;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.top: _exit.bottom;
            anchors.topMargin: Screen.pixelDensity*5;
            size: Screen.pixelDensity*12;
            itemTextSize: SettingsManager.iconFontH5;
            icon: (playState)  ? "\uF04C" : "\uF04B";
            onItemClicked: playState = !playState;
        }

        Text {
            id: _volUpTitle;
            font.family: SettingsManager.iconFont;
            font.pointSize: SettingsManager.iconFontH5;
            color: SettingsManager.fgInactiveColor;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.top: _playPause.bottom;
            anchors.topMargin: Screen.pixelDensity*10;
            text: "\uf028"
        }

        VNaviBar {
            id: _volBar;
            anchors.bottom: _volDownTitle.top;
            anchors.bottomMargin: Screen.pixelDensity*2;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.top: _volUpTitle.bottom;
            anchors.topMargin: Screen.pixelDensity*2;
            maxVal: 100;
            value: SettingsManager.videoVolume;
            onValueDataChanged: volume = value/100;
        }

        Text {
            id: _volDownTitle;
            font.family: SettingsManager.iconFont;
            font.pointSize: SettingsManager.iconFontH5;
            color: SettingsManager.fgInactiveColor;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.bottom: parent.bottom;
            text: "\uf027";
        }
    }

    Rectangle {
        id: _progressBarFrame;
        anchors.bottom: parent.bottom;
        anchors.left: parent.left;
        anchors.right: parent.right;
        height: Screen.pixelDensity*20;
        color: "#A0000000";

        NaviBar {
            id: _progressBar;
            anchors.left: parent.left;
            anchors.leftMargin: Screen.pixelDensity*6;
            anchors.right: parent.right;
            anchors.rightMargin: Screen.pixelDensity*6;
            anchors.verticalCenter: parent.verticalCenter;
            maxVal: 100;
            value: 50;
            onValueDataChanged: videoPlayerControl.seek(value);
        }
    }
}
