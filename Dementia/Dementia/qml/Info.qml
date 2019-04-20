import QtQuick 2.0
import QtQuick.Window 2.0

Item {
    property int idx: 2;

    function activate() {
        _topBar.opacity = 1;
    }

    function deactivate() {
        _topBar.opacity = 0;
        hideContents();
    }

    function showContents() {
        _dataView.interactive = false;
        _contentsView.currentIndex = _dataView.currentIndex;
        _contentsFrame.isEnabled = true;
        _contentsFrame.x = 0;
    }

    function hideContents() {
        _dataView.interactive = true;
        _contentsFrame.isEnabled = false;
        _contentsFrame.x = - _contentsView.width - Screen.pixelDensity*10;
    }

    id: _info;

    TopBar {
        id: _topBar;
        iconEnable: true;
        title: qsTr("Информация") + SettingsManager.tsStr;
    }

    ListView {
        id: _dataView;
        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.top: _topBar.bottom;
        anchors.bottom: parent.bottom;
        orientation: ListView.Horizontal;
        snapMode: ListView.SnapOneItem;
        highlightRangeMode: ListView.StrictlyEnforceRange
        delegate: Image {
            source: model.modelData;
            width: _dataView.width;
            height: _dataView.height;
            MouseArea {
                anchors.fill: parent;
                onClicked: (_contentsFrame.isEnabled)
                           ? hideContents()
                           : showContents();
            }
        }
    }

    Rectangle {
        property bool isEnabled: false;
        id: _contentsFrame;
        width: parent.width/2;
        anchors.top: _topBar.bottom;
        anchors.bottom: parent.bottom;
        x: - width - Screen.pixelDensity*10;
        color: SettingsManager.bgInactiveColor.replace("#","#B0");

        Label {
           id: _contentsLabel;
           height: Screen.pixelDensity*8;
           width: parent.width/2;
           anchors.top: parent.top;
           anchors.topMargin: Screen.pixelDensity*5;
           anchors.horizontalCenter: parent.horizontalCenter;
           labelText: qsTr("Содержание") + ":" + SettingsManager.tsStr;
        }

        SimpleView {
            id: _contentsView;
            anchors.left: parent.left;
            anchors.right: parent.right;
            anchors.top: _contentsLabel.bottom;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: Screen.pixelDensity*5;
            anchors.topMargin: Screen.pixelDensity*5;
            onItemClicked: {
                _dataView.positionViewAtIndex(_contentsView.currentIndex,
                                              ListView.Beginning);
                _dataView.currentIndex = _contentsView.currentIndex;
            }
        }

        Behavior on x { NumberAnimation { duration: 400; } }
    }

    Connections {
        target: InfoFilesManager;
        onModelOutdated: {
            _contentsView.model = InfoFilesManager.contentsModel();
            _dataView.model = InfoFilesManager.dataModel();
        }
    }

    onVisibleChanged: (visible) ? activate() : deactivate();

    Component.onCompleted: {
        _contentsView.model = InfoFilesManager.contentsModel();
        _dataView.model = InfoFilesManager.dataModel();
        _info.deactivate();
    }
}

