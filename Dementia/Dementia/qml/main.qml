import QtQuick 2.6
import QtQuick.Window 2.0
import QtQuick.Controls 1.5
import QtMultimedia 5.6 as Multimedia

//Window {
Item {
    id: mainWindow;
    //visible: false;
    //color: "transparent"

    //width: Screen.pixelDensity*214;
    //height: Screen.pixelDensity*134;

    FontLoader { source: "qrc:/fonts/roboto.ttf";}
    FontLoader { source: "qrc:/fonts/awe.ttf"; }
    FontLoader { source: "qrc:/fonts/lcd.ttf"; }

    Image {
        anchors.fill: parent;
        source: "qrc:/images/bg.png"
        asynchronous: true;
    }

    Item {
        id: virtualStack;
        anchors.fill: parent;

        function pop(itemIdx) {
            switch (itemIdx) {
            case 0: audio.visible = false; break;
            case 1: camcorder.visible = false; break;
            case 2: info.visible = false; break;
            case 3: help.visible = false; break;
            case 4: video.visible = false; break;
            case 5: airshow.visible = false; break;
            case 6: game.visible = false; break;
            case 7: settings.visible = false; break;

                // !
            case 41:
                videoPlayer.visible = false;
                video.visible = true;
                return;
                // !
            case 71:
                root.visible = false;
                settings.visible = true;
                return;
            }
            mainMenu.visible = true;
        }

        function push(itemIdx) {
            switch (itemIdx) {
            case 0: audio.visible = true; break;
            case 1: camcorder.visible = true; break;
            case 2: info.visible = true; break;
            case 3: help.visible = true; break;
            case 4: video.visible = true; break;
            case 5: airshow.visible = true; break;
            case 6: game.visible = true; break;
            case 7: settings.visible = true; break;

                // !
            case 41:
                audio.externalPause();
                videoPlayer.file = video.currentVideoFile;
                videoPlayer.visible = true;
                video.visible = false;
                return;

                // !
            case 71:
                root.visible = true;
                settings.visible = false;
                return;
            }
            mainMenu.visible = false;
        }

        MainMenu {
            id: mainMenu;
            height:mainWindow.height;
            width: mainWindow.width;
        }

        Audio {
            id: audio;
            height:mainWindow.height;
            width: mainWindow.width;
            visible: false;
        }

        Camcorder {
            id: camcorder;
            height:mainWindow.height;
            width: mainWindow.width;
            visible: false;
        }

        Info {
            id: info;
            height:mainWindow.height;
            width: mainWindow.width;
            visible: false;
        }

        Help {
            id: help;
            height:mainWindow.height;
            width: mainWindow.width;
            visible: false;
        }

        Video {
            id: video;
            height:mainWindow.height;
            width: mainWindow.width;
            visible: false;
        }

        VideoPlayer {
            id: videoPlayer;
            height:mainWindow.height;
            width: mainWindow.width;
            visible: false;
        }

        Airshow {
            id: airshow;
            height:mainWindow.height;
            width: mainWindow.width;
            visible: false;
        }

        Game {
            id: game;
            height:mainWindow.height;
            width: mainWindow.width;
            visible: false;
        }

        Settings {
            id: settings;
            height:mainWindow.height;
            width: mainWindow.width;
            visible: false;
        }

        Root {
            id: root;
            height:mainWindow.height;
            width: mainWindow.width;
            visible: false;
        }

        Component.onCompleted: mainMenu.activate();
    }

    Multimedia.Video {
        id: specOverlay;
        visible: false;
        anchors.fill: parent;
        onStatusChanged: {
            if (status === Multimedia.MediaPlayer.EndOfMedia) {
                specOverlay.stop();
                specOverlay.visible = false;
                virtualStack.visible = true;
            }
        }
    }

    Connections {
        target: SpecFilesManager;
        onPlaySpecFile: {
            audio.externalPause();
            videoPlayer.externalPause();
            virtualStack.visible = false;
            specOverlay.visible = true;
            specOverlay.source = file;
            specOverlay.play();
            console.log(specOverlay.source);
        }
    }
}
