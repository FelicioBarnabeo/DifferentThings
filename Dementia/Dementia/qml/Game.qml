import QtQuick 2.0
import QtQuick.Window 2.0

Item {
    property int idx: 6;

    function activate() {
        _topBar.opacity = 1;
    }

    function deactivate() {
        _topBar.opacity = 0;
    }

    id: _game;

    TopBar {
        id: _topBar;
        iconEnable: true;
        title: qsTr("Игры") + SettingsManager.tsStr;
    }

    GridView {
        id: _gamesView;
        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.bottom: parent.bottom;
        anchors.top: _topBar.bottom;
        anchors.margins: Screen.pixelDensity*2;

        cellWidth: width/5;
        cellHeight: width/4;
        clip: true;
        delegate: Item {
            id: _delegateItem;
            width: parent.width/5;
            height: parent.width/4;

            Column {
                anchors.centerIn: parent;
                spacing: Screen.pixelDensity*2;
                Image {
                    id: _icon;
                    source: "file:" + GameFilesManager.absolutePath() + "/" +
                            model.modelData + "/" + "icon.png";
                    width: _delegateItem.width*0.7;
                    height: width;
                    anchors.horizontalCenter: parent.horizontalCenter;
                }

                Text {
                    text: model.modelData;
                    font.family: SettingsManager.textFont;
                    font.pointSize: SettingsManager.textFontH5;
                    color: SettingsManager.fgInactiveColor;
                    wrapMode: Text.WordWrap;
                    height: _delegateItem.height*0.2;
                    width: _delegateItem.width;
                    horizontalAlignment: Text.AlignHCenter;
                    verticalAlignment: Text.AlignVCenter;
                }
            }

            MouseArea {
                anchors.fill: parent;
                onClicked: {
                    _gameLoader.setSource("file:" +
                                          GameFilesManager.absolutePath() + "/" +
                                          model.modelData + "/" + "Game.qml",
                                          {lang: SettingsManager.language,
                                           soundVol: SettingsManager.gameVolume});
                }
            }
        }
    }

    Loader {
        id: _gameLoader;
        anchors.fill: parent;
        asynchronous: true;
        onLoaded: {
            _gamesView.visible = false;
            _topBar.visible = false;
        }
    }

    Connections {
        target: _gameLoader.item;
        onExit: {
            _gamesView.visible = true;
            _topBar.visible=true;
            _gameLoader.sourceComponent = undefined;
        }
    }

    Connections {
        target: GameFilesManager;
        onModelOutdated: _gamesView.model = GameFilesManager.model();
    }

    onVisibleChanged: (visible) ? activate() : deactivate();

    Component.onCompleted: {
        _gamesView.model = GameFilesManager.model();
        _game.deactivate();
    }
}

