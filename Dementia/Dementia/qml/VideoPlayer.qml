import QtQuick 2.0
import QtMultimedia 5.6 as Multimedia

Rectangle {
    property int idx: 41;
    property string file: "";

    function externalPause() {
        video.pause();
    }

    function exit() {
        videoPlayerControl.visible = false;
        videoPlayerControl.playState = true;
        video.stop();
        videoPlayer.parent.pop(idx);
    }

    function play() {
        video.source = file;
        video.play();
    }

    id: videoPlayer;
    color: "black";

    MouseArea {
        anchors.fill: parent;
        onClicked: videoPlayerControl.visible = !videoPlayerControl.visible;
    }

    Multimedia.Video {
        id: video;
        anchors.fill: parent;
        volume: SettingsManager.videoVolume/100;
        onPositionChanged: videoPlayerControl.setProgressPosition(position);
        onStatusChanged: {
            if (status === Multimedia.MediaPlayer.EndOfMedia) {
                videoPlayer.exit()
            } else if (status === Multimedia.MediaPlayer.Loaded ||
                    status === Multimedia.MediaPlayer.Buffered) {
                videoPlayerControl.setProgressPosition(0);
                videoPlayerControl.duration = video.duration;
            }
        }

        VideoPlayerControl {
            id : videoPlayerControl;
            anchors.fill: parent;
            onPlayStateChanged: (playState) ? video.play() : video.pause();
            onVolumeChanged: video.volume = volume;
            onExit: videoPlayer.exit();
            onSeek: video.seek(pos);
        }
    }

    onVisibleChanged: if (visible) videoPlayer.play();
}
