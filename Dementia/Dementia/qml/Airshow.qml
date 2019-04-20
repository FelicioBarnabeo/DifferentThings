import QtQuick 2.0
import QtQuick.Window 2.0
import "."

Item {
    property int idx: 5;
    property int switchTime: SettingsManager.airshowImgSwitchMs;
    property int updateTime: SettingsManager.airshowImgUpdateMs;
    property string serverIP: SettingsManager.airshowServerIP;
    property int serverPort: SettingsManager.airshowServerPort;

    function activate() {
        _topBar.opacity = 1;
        if (!AirshowFilesManager.updateImages(serverIP,serverPort))
            _statusText.visible = true;
        _imgUpdateTimer.start();
    }

    function deactivate() {
        AirshowFilesManager.resetToDefault();
        _topBar.opacity = 0;
        _changeImgTimer.stop();
        _imgUpdateTimer.stop();
        _statusText.visible = false;
        _img.source = "";
    }

    function switchImage() {
        _img.source = AirshowFilesManager.nextImage();
        if (_img.source == "") {
            _statusText.visible = true;
            _changeImgTimer.stop();
        }
    }

    id: _airshow;

    TopBar {
        id: _topBar;
        iconEnable: true;
        title: qsTr("Аэрошоу") + SettingsManager.tsStr;
    }

    Timer {
        id: _changeImgTimer;
        interval: switchTime;
        repeat: true;
        onTriggered: switchImage();
    }

    Timer {
        id: _imgUpdateTimer;
        interval: updateTime;
        repeat: true;
        onTriggered: if (!AirshowFilesManager.updateImages(serverIP,serverPort)) {
                         _statusText.visible = true;
                         _changeImgTimer.stop();
                         _img.source = "";
                     }
    }

    Image {
        id: _img;
        anchors.top: _topBar.bottom;
        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.bottom: parent.bottom;
    }

    Text {
        id: _statusText;
        anchors.centerIn: parent;
        color: SettingsManager.fgInactiveColor;
        font.family: SettingsManager.textFont;
        font.pointSize: SettingsManager.textFontH5;
        text: qsTr("К сожалению данные о полете недоступны.")+SettingsManager.tsStr;
        visible: false;
    }

    Connections {
        target: AirshowFilesManager;
        onNetworkErrorOccured: {
            _statusText.visible = true;
            _changeImgTimer.stop();
            _img.source = "";
        }
        onImagesReady: {
            _statusText.visible = false;
            _changeImgTimer.start();
            switchImage();
        }
    }

    onVisibleChanged: (visible) ? activate() : deactivate();
}
