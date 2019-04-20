import QtQuick 2.0
import QtQuick.Window 2.0

Item {
    property int idx: 4;
    property bool infoEnabled: false;
    property string currentVideoFile: "";

    function activate() {
        topBar.opacity = 1;
        videoFrame.opacity = 1;
        infoBtn.y = infoBtn.parent.height/2 - infoBtn.height/2;
        playBtn.y = playBtn.parent.height/2 - infoBtn.height/2;
        hideInfo();
    }

    function deactivate() {
        topBar.opacity = 0;
        videoFrame.opacity = 0;
        infoBtn.y = infoBtn.parent.height + Screen.pixelDensity*20;
        playBtn.y = playBtn.parent.height + Screen.pixelDensity*20;
        hideInfo();
    }

    function hideInfo() {
        infoEnabled = false;
        infoCover.source = "";

        infoTab.x = infoTab.parent.width/2;
        infoTab.y = infoTab.parent.height/2;
        infoTab.width = 0;
        infoTab.height = 0;
        infoTab.opacity = 0;
        videoView.opacity = 1;
    }

    function showInfo() {
        var coverFile = "file:/" + VideoFilesManager.absolutePath()+"/"
                + videoView.model[videoView.currentIndex] + "/cover.jpg.medium";

        infoEnabled = true;
        infoCover.source = coverFile;

        infoTab.x = infoTab.parent.width*0.1;
        infoTab.y = infoTab.parent.height*0.2;
        infoTab.width = infoTab.parent.width*0.8;
        infoTab.height = infoTab.parent.height*0.5;
        infoTab.opacity = 1;
        videoView.opacity = 0;
    }

    id: video

    TopBar {
        id: topBar;
        iconEnable: true;
        title: qsTr("Видео") + SettingsManager.tsStr;
    }

    Item {
        id: videoFrame;
        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.bottom: parent.bottom;
        anchors.top: topBar.bottom;

        Text {
            id: hintLabel;
            anchors.left: parent.left;
            anchors.right: parent.right;
            anchors.top: parent.top;
            anchors.topMargin: Screen.pixelDensity*5;
            horizontalAlignment: Text.AlignHCenter;
            font.family: SettingsManager.textFont;
            font.pointSize: SettingsManager.textFontH4;
            font.bold: true;
            color: SettingsManager.fgInactiveColor;
            text: videoView.model[videoView.currentIndex];
        }

        ListView {
            property int activeItemWidth: Screen.pixelDensity*52;   //  H/W ~ 1.5
            property int activeItemHeight: Screen.pixelDensity*80;  //  H/W ~ 1.5
            property int preActiveItemWidth: activeItemWidth/1.3;
            property int preActiveItemHeight: activeItemHeight/1.3;
            property int inActiveItemWidth: activeItemWidth/2;
            property int inActiveItemHeight: activeItemHeight/2;

            property int curIdx: videoView.currentIndex;
            property int prevIdx: curIdx-1;
            property int nextIdx: curIdx+1;

            id: videoView;
            anchors.left: parent.left;
            anchors.leftMargin: Screen.pixelDensity*5;
            anchors.right: parent.right;
            anchors.rightMargin: Screen.pixelDensity*5;
            anchors.top: hintLabel.bottom;
            anchors.topMargin: Screen.pixelDensity*5;
            height: parent.height*0.7;
            orientation: ListView.Horizontal;
            spacing: Screen.pixelDensity*5;
            clip: true;
            cacheBuffer: 2400;

            preferredHighlightBegin: width /2 - activeItemWidth/2
            preferredHighlightEnd: width /2 + activeItemWidth/2;
            highlightRangeMode: ListView.StrictlyEnforceRange

            delegate: Item {
                width: if (videoView.curIdx === index)
                            return (videoView.activeItemWidth);
                        else if (videoView.prevIdx === index ||
                                 videoView.nextIdx === index)
                            return (videoView.preActiveItemWidth);
                        else return (videoView.inActiveItemWidth);

                height: if (videoView.curIdx === index)
                           return (videoView.activeItemHeight);
                       else if (videoView.prevIdx === index ||
                                videoView.nextIdx === index)
                           return (videoView.preActiveItemHeight);
                       else return (videoView.inActiveItemHeight);

                anchors.verticalCenter: parent.verticalCenter;
                Rectangle {
                    anchors.fill: parent;
                    color: "transparent";
                    border.width: 2;
                    border.color: (index === videoView.currentIndex)
                                  ? SettingsManager.fgActiveColor
                                  : SettingsManager.fgInactiveColor;
                    Image {
                        asynchronous: true;
                        anchors.fill: parent;
                        anchors.margins: 2;
                        source: {
                            var path = "file:/" +
                                    VideoFilesManager.absolutePath() +
                                    "/" + model.modelData;

                            if (videoView.curIdx === index)
                                return (path + "/cover.jpg.large");
                            else if (videoView.prevIdx === index ||
                                     videoView.nextIdx === index)
                                return (path + "/cover.jpg.medium");
                            else return (path + "/cover.jpg.small");
                        }
                    }
                }
                MouseArea {
                    anchors.fill: parent;
                    onClicked: {
                        if (videoView.currentIndex === index) showInfo();
                        else videoView.currentIndex = index;
                    }
                }
            }

            Behavior on opacity { NumberAnimation { duration: 600; } }
        }

        Item {
            id: controlTab;
            anchors.top: videoView.bottom;
            anchors.bottom: parent.bottom;
            anchors.left: parent.left;
            anchors.right: parent.right;

            Button {
                id: playBtn;
                width: parent.width*0.25;
                height: Screen.pixelDensity*10;
                y: parent.height + Screen.pixelDensity*20;
                x: parent.width/2 - width - Screen.pixelDensity*5;
                circleType: false;
                itemTextSize: SettingsManager.textFontH5;
                itemFont: SettingsManager.textFont;
                icon: qsTr("Воспроизвести") + SettingsManager.tsStr;
                onItemClicked: {
                    var file = "file:" + VideoFilesManager.absolutePath()+"/"
                            + videoView.model[videoView.currentIndex] + "/file";

                    video.currentVideoFile = file;
                    video.parent.push(41);
                }

                Behavior on y { NumberAnimation { duration: 600; } }
            }

            Button {
                id: infoBtn;
                width: parent.width*0.25;
                height: Screen.pixelDensity*10;
                y: parent.height+ Screen.pixelDensity*20;
                x: parent.width/2 + Screen.pixelDensity*5;
                circleType: false;
                itemTextSize: SettingsManager.textFontH5;
                itemFont: SettingsManager.textFont;
                icon: qsTr("Информация") + SettingsManager.tsStr;
                onItemClicked: (infoEnabled) ? hideInfo() : showInfo();

                Behavior on y { NumberAnimation { duration: 600; } }
            }
        }

        Rectangle {
            id: infoTab;
            border.color: SettingsManager.fgInactiveColor;
            border.width: 1;
            color: "transparent";
            clip: true;
            opacity: 0;

            Image {
                id: infoCover;
                anchors.top: parent.top;
                anchors.bottom: parent.bottom;
                anchors.left: parent.left;
                anchors.margins: 2;
                fillMode: Image.PreserveAspectFit
            }

            Text {
                anchors.top: parent.top;
                anchors.bottom: parent.bottom;
                anchors.left: infoCover.right;
                anchors.right: parent.right;
                anchors.margins: Screen.pixelDensity*5;
                horizontalAlignment: Text.AlignJustify;
                verticalAlignment: Text.AlignVCenter;
                wrapMode: Text.WordWrap;
                font.family: SettingsManager.textFont;
                font.pointSize: SettingsManager.textFontH5;
                color: SettingsManager.fgInactiveColor;
                text: VideoFilesManager.getDescOf(videoView.model[videoView.currentIndex]);
            }

            MouseArea {
                anchors.fill: parent;
                onClicked: hideInfo();
            }

            Behavior on x { NumberAnimation { duration: 600; } }
            Behavior on y { NumberAnimation { duration: 600; } }
            Behavior on width { NumberAnimation { duration: 600; } }
            Behavior on height { NumberAnimation { duration: 600; } }
            Behavior on opacity { NumberAnimation { duration: 600; } }
        }

        Behavior on opacity { NumberAnimation { duration: 800; } }
    }

    Connections {
        target: VideoFilesManager;
        onModelOutdated: videoView.model = VideoFilesManager.model();
    }

    onVisibleChanged: (visible) ? activate() : deactivate();

    Component.onCompleted: {
        videoView.model = VideoFilesManager.model();
        videoView.currentIndex = videoView.count/2;
        video.deactivate();
    }
}
