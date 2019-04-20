import QtQuick 2.6
import QtQuick.Window 2.0

Window {
    id: mainWindow;
    visible: true;
    width: Screen.pixelDensity*214;
    height: Screen.pixelDensity*134;
    color: "black";

    Image {
        id: splash;
        anchors.fill: parent;
        source: "qrc:/images/splash.jpg"
    }

    Loader {
        id: mainLoader;
        anchors.fill: parent;
        asynchronous: true;
        visible: status === Loader.Ready;
    }

    PauseAnimation {
        id: fakePause;
        duration: 50;
        onRunningChanged: if (!running) mainLoader.source = "main.qml";
    }

    Component.onCompleted: fakePause.start();
}
