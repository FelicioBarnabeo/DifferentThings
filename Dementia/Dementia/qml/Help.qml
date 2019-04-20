import QtQuick 2.0
import QtQuick.Window 2.0

Item {
    property int idx: 3;

    function activate() {
        _topBar.opacity = 1;
        _contentsFrame.opacity = 1;
    }

    function deactivate() {
        _topBar.opacity = 0;
        _contentsFrame.opacity = 0;
    }

    id: _help;

    TopBar {
        id: _topBar;
        iconEnable: true;
        title: qsTr("Помощь") + SettingsManager.tsStr;
    }

    Label {
       id: _dataLabel;
       height: Screen.pixelDensity*8;
       width: parent.width*0.4;
       anchors.top: _topBar.bottom;
       anchors.topMargin: Screen.pixelDensity*5;
       anchors.horizontalCenter: _dataFrame.horizontalCenter;
       labelText: qsTr("Описание") + ":" + SettingsManager.tsStr;
    }

    Flickable {
        id: _dataFrame;
        anchors.left: _contentsFrame.right;
        anchors.right: parent.right;
        anchors.top: _dataLabel.bottom;
        anchors.bottom: parent.bottom;
        anchors.margins: Screen.pixelDensity*5;
        clip: true;
        contentHeight: _data.height;
        contentWidth: width;
        Text {
            id: _data;
            width: parent.width;
            wrapMode: Text.WordWrap;
            horizontalAlignment: Text.AlignJustify;
            color: SettingsManager.fgInactiveColor;
            font.family: SettingsManager.textFont;
            font.pointSize: SettingsManager.textFontH5;
            textFormat: Text.StyledText;
        }
    }

    Item {
        id: _contentsFrame;
        width: parent.width*0.3;
        anchors.top: _topBar.bottom;
        anchors.bottom: parent.bottom;
        anchors.left: parent.left;

        Label {
           id: _contentsLabel;
           height: Screen.pixelDensity*8;
           width: parent.width*0.8;
           anchors.top: parent.top;
           anchors.topMargin: Screen.pixelDensity*5;
           anchors.horizontalCenter: parent.horizontalCenter;
           labelText: qsTr("Содержание") + ":" + SettingsManager.tsStr;
        }

        SimpleView {
            id: _contentsView;
            itemAlign: Text.AlignHCenter;
            anchors.left: parent.left;
            anchors.right: parent.right;
            anchors.top: _contentsLabel.bottom;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: Screen.pixelDensity*5;
            anchors.topMargin: Screen.pixelDensity*5;
            onItemClicked: {
                _data.text = HelpFilesManager.text(currentIndex);
            }
        }

        Rectangle {
            color: SettingsManager.fgInactiveColor;
            width: 1;
            anchors.top: parent.top;
            anchors.bottom: parent.bottom;
            anchors.right: parent.right;
        }

        Behavior on opacity { NumberAnimation { duration: 600; } }
    }

    Connections {
        target: HelpFilesManager;
        onModelOutdated: {
            _contentsView.model = HelpFilesManager.contentsModel();
            _contentsView.currentIndex = 0;
            _data.text = HelpFilesManager.text(0);
        }
    }

    onVisibleChanged: (visible) ? activate() : deactivate();

    Component.onCompleted: {
        _contentsView.model = HelpFilesManager.contentsModel();
        _contentsView.currentIndex = 0;
        _data.text = HelpFilesManager.text(0);
        deactivate();
    }
}

