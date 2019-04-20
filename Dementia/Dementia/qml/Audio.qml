import QtQuick 2.0
import QtQuick.Window 2.0
import QtMultimedia 5.4

Item {
    property int idx: 0;

    function externalPause() {
        _playerControl.playState = false;
    }

    function activate() {
        _topBar.opacity = 1;
        _separator.y = _audioFrame.y - Screen.pixelDensity*5;
        _leftTab.y = 0;
        _rightTab.x = _separator.x+1;
        _playerTab.opacity = 1;
    }

    function deactivate() {
        _topBar.opacity = 0;
        _separator.y = _audio.height + Screen.pixelDensity*15;
        _leftTab.y = -_audioFrame.height - Screen.pixelDensity*10;
        _rightTab.x = _audioFrame.width + Screen.pixelDensity*10;
        _playerTab.opacity = 0;
    }

    id: _audio;

    TopBar {
        id: _topBar;
        iconEnable: true;
        title: qsTr("Аудио") + SettingsManager.tsStr;
    }

    Audio {
        property bool random: false;
        id: _player;
        volume: SettingsManager.audioVolume/100;
        onPositionChanged: _playerControl.setProgressPosition(position);
        onDurationChanged: {
            _playerControl.setProgressPosition(0);
            _playerControl.duration = _player.duration;
        }
        onStatusChanged: {
            if (status === Audio.EndOfMedia) {
                if (loops === Audio.Infinite) return;
                if (random) _playerControl.play(2);
                else _playerControl.play(+1);
            }
        }
    }

    Item {
        id: _audioFrame;
        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.bottom: parent.bottom;
        anchors.top: _topBar.bottom;
        clip: true;

        Item {
            id: _leftTab;
            anchors.left: parent.left;
            anchors.right: _separator.left;
            height: _audioFrame.height - Screen.pixelDensity*10;
            y: -_audioFrame.height - Screen.pixelDensity*10;

            Label {
                id: _genresLabel;
                height: Screen.pixelDensity*8;
                width: parent.width/2;
                anchors.top: parent.top;
                anchors.topMargin: Screen.pixelDensity*5;
                anchors.horizontalCenter: parent.horizontalCenter;
                labelText: qsTr("Жанр") + SettingsManager.tsStr;
            }

            SimpleView {
                id: _audioGenres;
                itemAlign: Text.AlignHCenter;
                anchors.left: parent.left;
                anchors.right: parent.right;
                anchors.bottom: parent.bottom;
                anchors.top: _genresLabel.bottom;
                anchors.topMargin: Screen.pixelDensity*5;

                onItemClicked: {
                    _playerControl.playState = false;
                    _playerControl.setProgressPosition(0);
                    _player.stop();
                    AudioFilesManager.setExtPath(val);
                }
            }

            Behavior on y { NumberAnimation { duration: 800; } }
        }

        Item {
            id: _rightTab;
            anchors.top: parent.top;
            height: _audioFrame.height*0.7;
            width: _audioFrame.width - _separator.x-1;
            x: _audioFrame.width + Screen.pixelDensity*10;

            Label {
                id: _filesLabel;
                height: Screen.pixelDensity*8;
                width: parent.width/2;
                anchors.top: parent.top;
                anchors.topMargin: Screen.pixelDensity*5;
                anchors.horizontalCenter: parent.horizontalCenter;
                labelText: qsTr("Название") + SettingsManager.tsStr;
            }

            Text {
                text: qsTr("В этом жанре нет файлов")+ SettingsManager.tsStr;
                font.family: SettingsManager.textFont;
                font.pointSize: SettingsManager.textFontH4;
                color: SettingsManager.fgInactiveColor;
                anchors.centerIn: parent;
                visible: (_audioFiles.count === 0);
            }

            SimpleView {
                id: _audioFiles;
                anchors.left: parent.left;
                anchors.right: parent.right;
                anchors.bottom: parent.bottom;
                anchors.top: _filesLabel.bottom;
                anchors.topMargin: Screen.pixelDensity*5;
                itemAlign: Text.AlignLeft;
                slice: true;
                sliceCount: 4;
                onItemClicked: _playerControl.play(0);
            }

            Behavior on x { NumberAnimation { duration: 800; } }
        }

        Rectangle {
            id: _separator;
            x: parent.width/3;
            y: _audio.height + Screen.pixelDensity*15;
            width: 1;
            height: parent.height - Screen.pixelDensity*10;

            Behavior on y { NumberAnimation { duration: 1000; } }
        }

        Item {
            id: _playerTab;
            anchors.top: _rightTab.bottom;
            anchors.left: _separator.right;
            anchors.bottom: parent.bottom;
            anchors.right: parent.right;
            anchors.margins: Screen.pixelDensity*5;

            opacity: 0;

            AudioPlayerControl {
                function play(type) {
                    if (_audioFiles.currentIndex === -1) return;
                    switch (type) {
                        // play prev
                    case -1:
                        if (_audioFiles.currentIndex) _audioFiles.currentIndex--;
                        break;
                        // play next & loop
                    case 1:
                        if (_audioFiles.currentIndex !== _audioFiles.count - 1)
                            _audioFiles.currentIndex++;
                        else _audioFiles.currentIndex = 0;
                        break;
                        // play random
                    case 2:
                        var randomIndex = Math.random() * (_audioFiles.count-1);
                        _audioFiles.currentIndex = randomIndex;
                        break;
                    }

                    var source = AudioFilesManager.absolutePath();
                    source = "file:" + source
                            + "/" +_audioFiles.model[_audioFiles.currentIndex];
                    _player.source = source;
                    _player.play();
                    playState = true;
                }

                function togglePlaybackState(newState) {
                    if (_audioFiles.currentIndex === -1) return;
                    var curState = _player.playbackState;

                    if (curState === Audio.PlayingState && !newState)
                        _player.pause();
                    else if (curState === Audio.PausedState && newState)
                        _player.play();
                    else if (curState === Audio.StoppedState && newState)
                        play(0);
                }

                id: _playerControl;
                anchors.fill: parent;
                onPlayStateChanged: togglePlaybackState(playState);
                onPrev: play(-1);
                onNext: play(+1);
                onRandomStateChanged: _player.random = randomState;
                onVol: _player.volume = value/100;
                onSeek: _player.seek(pos);
                onLoopStateChanged: (loopState)
                                    ? _player.loops = Audio.Infinite
                                    : _player.loops = 1;
            }

            Behavior on opacity { NumberAnimation { duration: 1200; } }
        }
    }

    Connections {
        target: AudioFilesManager;
        onModelOutdated: _audioFiles.model = AudioFilesManager.model();
    }

    Connections {
        target: AudioGenresManager;
        onModelOutdated: {
            _audioGenres.model = AudioGenresManager.model();
            AudioFilesManager.setExtPath(_audioGenres.model[0]);
        }
    }

    onVisibleChanged: (visible) ? activate() : deactivate();

    Component.onCompleted: {
        _audioGenres.model = AudioGenresManager.model();
        AudioFilesManager.setExtPath(_audioGenres.model[0]);
        _audio.deactivate();
    }
}
