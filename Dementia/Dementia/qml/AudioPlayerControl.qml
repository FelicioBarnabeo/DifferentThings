import QtQuick 2.0
import QtQuick.Window 2.0

Item {
    property int position: 0;
    property alias duration: progressBar.maxVal;
    property bool playState: false;
    property bool randomState: false;
    property bool loopState: false;

    signal next();
    signal prev();
    signal vol(var value);
    signal seek(var pos);

    function setProgressPosition(val) {
        progressBar.setValue(val);
    }

    function activate() {
        var tier1Size = playBtn.size*0.7;
        var tier2Size = playBtn.size*0.5;

        var tier1Left = playBtn.x - tier1Size - Screen.pixelDensity*5;
        var tier1Right = playBtn.x + playBtn.size + Screen.pixelDensity*5;
        var tier2Left = tier1Left - tier2Size - Screen.pixelDensity*5;
        var tier2Right = tier1Right + tier1Size + Screen.pixelDensity*5;

        prevBtn.size = tier1Size;
        nextBtn.size = tier1Size;
        randomBtn.size = tier2Size;
        loopBtn.size = tier2Size;

        prevBtn.x = tier1Left;
        nextBtn.x = tier1Right;
        randomBtn.x = tier2Left;
        loopBtn.x = tier2Right;
    }

    function deactivate() {
        var size = audioPlayerControl.height*0.6;
        prevBtn.size = size;
        nextBtn.size = size;
        randomBtn.size = size;
        loopBtn.size = size;

        var x = audioPlayerControl.width/2 - size/2;
        prevBtn.x = x;
        nextBtn.x = x;
        randomBtn.x = x;
        loopBtn.x = x;
    }

    id: audioPlayerControl;

    Button {
        id: playBtn;
        anchors.top: parent.top;
        size: parent.height*0.6;
        itemTextSize: SettingsManager.iconFontH3;
        x: parent.width/2 - size/2;
        icon: (playState)  ? "\uF04C" : " \uF04B";
        onItemClicked: playState = !playState;
    }

    Button {
        id: prevBtn;
        anchors.verticalCenter: playBtn.verticalCenter;
        size: parent.height*0.6;
        x: parent.width/2 - size/2;
        itemTextSize: SettingsManager.iconFontH4;
        icon: "\uF049";
        onItemClicked: audioPlayerControl.prev();

        Behavior on x { NumberAnimation { duration: 800; } }
        Behavior on size { NumberAnimation { duration: 800; } }
    }

    Button {
        id: nextBtn;
        anchors.verticalCenter: playBtn.verticalCenter;
        size: parent.height*0.6;
        itemTextSize: SettingsManager.iconFontH4;
        x: parent.width/2 - size/2;
        icon: "\uF050";
        onItemClicked: audioPlayerControl.next();

        Behavior on x { NumberAnimation { duration: 800; } }
        Behavior on size { NumberAnimation { duration: 800; } }
    }


    Button {
        id: randomBtn;
        anchors.verticalCenter: playBtn.verticalCenter;
        size: parent.height*0.6;
        itemTextSize: SettingsManager.iconFontH5;
        x: parent.width/2 - size/2;
        icon: (randomState) ? "\uF15D" :"\uF074";
        onItemClicked: randomState = !randomState;

        Behavior on x { NumberAnimation { duration: 800; } }
        Behavior on size { NumberAnimation { duration: 800; } }
    }

    Button {
        id: loopBtn;
        anchors.verticalCenter: playBtn.verticalCenter;
        size: parent.height*0.6;
        itemTextSize: SettingsManager.iconFontH5;
        x: parent.width/2 - size/2;
        icon: (loopState) ? "\uF03A" : "\uF079";
        onItemClicked: loopState = !loopState;

        Behavior on x { NumberAnimation { duration: 800; } }
        Behavior on size { NumberAnimation { duration: 800; } }
    }

    NaviBar {
        id: progressBar;
        anchors.left: parent.left;
        anchors.bottom: parent.bottom;
        width: 2*parent.width/3;
        maxVal: 100;
        onValueDataChanged: audioPlayerControl.seek(value);
    }

    Text {
        anchors.bottom: progressBar.top;
        anchors.bottomMargin: Screen.pixelDensity;
        anchors.horizontalCenter: progressBar.horizontalCenter;
        text: qsTr("Навигация") + SettingsManager.tsStr;
        font.family: SettingsManager.textFont;
        font.pointSize: SettingsManager.textFontH5;
        color: SettingsManager.fgInactiveColor;
    }

    NaviBar {
        id: volumeBar;
        anchors.right: parent.right
        anchors.bottom: parent.bottom;
        width: parent.width/3 - Screen.pixelDensity*10;
        maxVal: 100;
        value: SettingsManager.audioVolume;
        onValueDataChanged: vol(value);
    }

    Text {
        anchors.bottom: volumeBar.top;
        anchors.bottomMargin: Screen.pixelDensity;
        anchors.horizontalCenter: volumeBar.horizontalCenter;
        text: qsTr("Громкость") + SettingsManager.tsStr;
        font.family: SettingsManager.textFont;
        font.pointSize: SettingsManager.textFontH5;
        color: SettingsManager.fgInactiveColor;
    }

    onVisibleChanged: (visible) ? audioPlayerControl.activate()
                                : audioPlayerControl.deactivate();

    Component.onCompleted: audioPlayerControl.deactivate();
}
