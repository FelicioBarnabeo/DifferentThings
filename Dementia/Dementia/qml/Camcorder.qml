import QtQuick 2.0
import QtQuick.Window 2.0
import QtMultimedia 5.4

Item {
    property int idx: 1;

    function activate() {
        _topBar.opacity = 1;
        _statusText.visible = true;
        _statusText.text = qsTr("Трансляция загружается");
        _stream.source = SettingsManager.camcorderSource;
        _stream.play();
    }

    function deactivate() {
        _topBar.opacity = 0;
        _stream.stop();
        _stream.source = "";
        _statusText.visible = false;
    }

    id: _camcorder;

    TopBar {
        id: _topBar;
        iconEnable: true;
        title: qsTr("Видеокамера") + SettingsManager.tsStr;
    }

    Video {
        id: _stream;
        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.top: _topBar.bottom;
        anchors.bottom: parent.bottom;
        fillMode: VideoOutput.Stretch;
        onErrorChanged: {
            _statusText.visible = true;
            _statusText.text = qsTr("К сожалению трансляции недоступна");
        }

        onStatusChanged: {
            console.log("status",status);
            switch(status)  {
            case MediaPlayer.Loaded:
            case MediaPlayer.Buffered:
                _statusText.visible= false;
                break;
            case MediaPlayer.Stalled:
            case MediaPlayer.EndOfMedia:
            case MediaPlayer.UnknownStatus:
            case MediaPlayer.InvalidMedia:
                _statusText.visible = true;
                _statusText.text = qsTr("К сожалению трансляции недоступна");
                break;
            }
        }
    }

    Text {
        id: _statusText;
        anchors.centerIn: parent;
        color: SettingsManager.fgInactiveColor;
        font.family: SettingsManager.textFont;
        font.pointSize: SettingsManager.textFontH5;
    }

    onVisibleChanged: (visible) ? activate() : deactivate();

    Component.onCompleted: _camcorder.deactivate();
}

