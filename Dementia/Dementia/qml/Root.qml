import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 1.4

Rectangle {
    property int idx: 71;

    function activate() {
        _topBar.opacity = 1;
    }

    function deactivate() {
        _topBar.opacity = 0;
    }

    id: _root;
    color: "#FF4E586E";

    TopBar {
        id: _topBar;
        iconEnable: true;
        title: "Interima receiving control";
    }

    SimpleView {
        id: _funcView;
        anchors.left: parent.left;
        anchors.top: _topBar.bottom;
        anchors.bottom: parent.bottom;
        anchors.topMargin: Screen.pixelDensity*5;
        anchors.bottomMargin: Screen.pixelDensity*5;
        width: parent.width*0.4;
        model: RootModel {}
        onItemClicked: {
            vkeyboard.open(val);
        }
    }

    Rectangle {
        anchors.left: _funcView.right;
        anchors.right: parent.right;
        anchors.bottom: parent.bottom;
        anchors.top: _topBar.bottom;
        anchors.margins: Screen.pixelDensity*5;
        border.color: "white";
        border.width: 1;
        color: "transparent";
    }

    VKeyboard {
        id: vkeyboard;
        anchors.fill: parent;
    }

    onVisibleChanged: (visible) ? activate() : deactivate();
}
