import QtQuick 2.0
import QtQuick.Window 2.0

Item {

    signal itemClicked(var itemIdx);

    function activate() {
        var itemSize = audioItem.size;
        var strokeOneY = (mainMenuFrame.height>>2) - (itemSize>>2);
        var strokeTwoY = mainMenuFrame.height - (mainMenuFrame.height>>2) - (itemSize);

        audioItem.y = strokeOneY;
        cameraItem.y = strokeOneY;
        infoItem.y = strokeOneY;
        helpItem.y = strokeOneY;

        videoItem.y = strokeTwoY;
        airshowItem.y = strokeTwoY;
        gamesItem.y = strokeTwoY;
        settingsItem.y = strokeTwoY;

        audioItemTitle.opacity = 1;
        cameraItemTitle.opacity = 1;
        infoItemTitle.opacity = 1;
        helpItemTitle.opacity = 1;

        videoItemTitle.opacity = 1;
        airshowItemTitle.opacity = 1;
        gamesItemTitle.opacity = 1;
        settingsItemTitle.opacity = 1;

        topBar.opacity = 1;
    }

    function deactivate() {
        var itemSize = audioItem.size;

        audioItem.y = -itemSize - Screen.pixelDensity*10;
        cameraItem.y = -itemSize - Screen.pixelDensity*10;
        infoItem.y = -itemSize - Screen.pixelDensity*10;
        helpItem.y = -itemSize - Screen.pixelDensity*10;

        videoItem.y = mainMenuFrame.height + Screen.pixelDensity*10;
        airshowItem.y = mainMenuFrame.height + Screen.pixelDensity*10;
        gamesItem.y = mainMenuFrame.height + Screen.pixelDensity*10;
        settingsItem.y = mainMenuFrame.height + Screen.pixelDensity*10;

        audioItemTitle.opacity = 0;
        cameraItemTitle.opacity = 0;
        infoItemTitle.opacity = 0;
        helpItemTitle.opacity = 0;

        videoItemTitle.opacity = 0;
        airshowItemTitle.opacity = 0;
        gamesItemTitle.opacity = 0;
        settingsItemTitle.opacity = 0;

        topBar.opacity = 0;
    }

    id: mainMenu;

    TopBar {
        id: topBar;
        title: qsTr("интерактивная развлекательная информационная система") + SettingsManager.tsStr;
    }

    Item {
        id: mainMenuFrame;
        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.bottom: parent.bottom;
        anchors.top: topBar.bottom;

        /* first stroke */
        Button {
            id: audioItem;
            size: parent.height>>2;
            icon: "\uF025"
            itemTextSize: SettingsManager.iconFontH1;
            x: (parent.width - (size<<2) - 3*15*Screen.pixelDensity)/2;
            y: -size - Screen.pixelDensity*10;
            Behavior on y { NumberAnimation { easing.type: Easing.OutBounce; duration: 800; } }
            onItemClicked: mainMenu.parent.push(0);
        }

        Text {
            id: audioItemTitle;
            text: qsTr("Аудио") + SettingsManager.tsStr;
            anchors.horizontalCenter: audioItem.horizontalCenter;
            anchors.bottom: audioItem.top;
            anchors.bottomMargin: Screen.pixelDensity*5;
            font.family: SettingsManager.textFont;
            font.pointSize: SettingsManager.textFontH4;
            font.weight: Font.Thin;
            color: SettingsManager.fgInactiveColor;
            opacity: 0;
            Behavior on opacity { NumberAnimation { duration: 1600; } }
        }

        Button {
            id: cameraItem;
            size: parent.height>>2;
            icon: "\uF030";
            itemTextSize: SettingsManager.iconFontH1;
            x: audioItem.x + size + Screen.pixelDensity*15;
            y: -size - Screen.pixelDensity*10;
            onItemClicked: mainMenu.parent.push(1);
            Behavior on y { NumberAnimation { easing.type: Easing.OutBounce; duration: 1000; } }
        }

        Text {
            id: cameraItemTitle;
            text: qsTr("Видеокамера") + SettingsManager.tsStr;
            anchors.horizontalCenter: cameraItem.horizontalCenter;
            anchors.bottom: cameraItem.top;
            anchors.bottomMargin: Screen.pixelDensity*5;
            font.family: SettingsManager.textFont;
            font.pointSize: SettingsManager.textFontH4;
            font.weight: Font.Thin;
            color: SettingsManager.fgInactiveColor;
            opacity: 0;
            Behavior on opacity { NumberAnimation { duration: 1800; } }
        }

        Button {
            id: infoItem;
            size: parent.height>>2;
            icon: "\uF071";
            itemTextSize: SettingsManager.iconFontH1;
            x: cameraItem.x + size + Screen.pixelDensity*15;
            y: -size - Screen.pixelDensity*10;
            Behavior on y { NumberAnimation { easing.type: Easing.OutBounce; duration: 1200 } }
            onItemClicked: mainMenu.parent.push(2);
        }

        Text {
            id: infoItemTitle;
            text: qsTr("Информация") + SettingsManager.tsStr;
            anchors.horizontalCenter: infoItem.horizontalCenter;
            anchors.bottom: infoItem.top;
            anchors.bottomMargin: Screen.pixelDensity*5;
            font.family: SettingsManager.textFont;
            font.pointSize: SettingsManager.textFontH4;
            font.weight: Font.Thin;
            color: SettingsManager.fgInactiveColor;
            opacity: 0;
            Behavior on opacity { NumberAnimation { duration: 2000; } }
        }

        Button {
            id: helpItem;
            size: parent.height>>2;
            icon: "\uF19D"
            itemTextSize: SettingsManager.iconFontH1;
            x: infoItem.x + size + Screen.pixelDensity*15;
            y: -size - Screen.pixelDensity*10;
            onItemClicked: mainMenu.parent.push(3);
            Behavior on y { NumberAnimation { easing.type: Easing.OutBounce; duration: 1400; } }
        }

        Text {
            id: helpItemTitle;
            text: qsTr("Помощь") + SettingsManager.tsStr;
            anchors.horizontalCenter: helpItem.horizontalCenter;
            anchors.bottom: helpItem.top;
            anchors.bottomMargin: Screen.pixelDensity*5;
            font.family: SettingsManager.textFont;
            font.pointSize: SettingsManager.textFontH4;
            font.weight: Font.Thin;
            color: SettingsManager.fgInactiveColor;
            opacity: 0;
            Behavior on opacity { NumberAnimation { duration: 2200; } }
        }

        /* second stroke */
        Button {
            id: videoItem;
            size: parent.height>>2;
            icon: "\uF008"
            itemTextSize: SettingsManager.iconFontH1;
            x: audioItem.x;
            y: parent.height + Screen.pixelDensity*10;
            onItemClicked: mainMenu.parent.push(4);
            Behavior on y { NumberAnimation { easing.type: Easing.OutBounce; duration: 1400; } }

        }

        Text {
            id: videoItemTitle;
            text: qsTr("Видео") + SettingsManager.tsStr;
            anchors.horizontalCenter: videoItem.horizontalCenter;
            anchors.top: videoItem.bottom;
            anchors.topMargin: Screen.pixelDensity*5;
            font.family: SettingsManager.textFont;
            font.pointSize: SettingsManager.textFontH4;
            font.weight: Font.Thin;
            color: SettingsManager.fgInactiveColor;
            opacity: 0;
            Behavior on opacity { NumberAnimation { duration: 2200; } }
        }

        Button {
            id: airshowItem;
            size: parent.height>>2;
            icon: "\uF0AC";
            itemTextSize: SettingsManager.iconFontH1;
            x: cameraItem.x;
            y: parent.height + Screen.pixelDensity*10;
            onItemClicked: mainMenu.parent.push(5);
            Behavior on y { NumberAnimation { easing.type: Easing.OutBounce; duration: 1200; } }
        }

        Text {
            id: airshowItemTitle;
            text: qsTr("Аэрошоу") + SettingsManager.tsStr;
            anchors.horizontalCenter: airshowItem.horizontalCenter;
            anchors.top: airshowItem.bottom;
            anchors.topMargin: Screen.pixelDensity*5;
            font.family: SettingsManager.textFont;
            font.pointSize: SettingsManager.textFontH4;
            font.weight: Font.Thin;
            color: SettingsManager.fgInactiveColor;
            opacity: 0;
            Behavior on opacity { NumberAnimation { duration: 2000; } }
        }

        Button {
            id: gamesItem;
            size: parent.height>>2;
            icon: "\uF11B";
            itemTextSize: SettingsManager.iconFontH1;
            x: infoItem.x;
            y: parent.height + Screen.pixelDensity*10;
            Behavior on y { NumberAnimation { easing.type: Easing.OutBounce; duration: 1000; } }
            onItemClicked: mainMenu.parent.push(6);
        }

        Text {
            id: gamesItemTitle;
            text: qsTr("Игры") + SettingsManager.tsStr;
            anchors.horizontalCenter: gamesItem.horizontalCenter;
            anchors.top: gamesItem.bottom;
            anchors.topMargin: Screen.pixelDensity*5;
            font.family: SettingsManager.textFont;
            font.pointSize: SettingsManager.textFontH4;
            font.weight: Font.Thin;
            color: SettingsManager.fgInactiveColor;
            opacity: 0;
            Behavior on opacity { NumberAnimation { duration: 1800; } }
        }

        Button {
            id: settingsItem;
            size: parent.height>>2;
            icon: "\uF1DE";
            itemTextSize: SettingsManager.iconFontH1;
            x: helpItem.x;
            y: parent.height + Screen.pixelDensity*10;
            Behavior on y { NumberAnimation { easing.type: Easing.OutBounce; duration: 800; } }
            onItemClicked: mainMenu.parent.push(7);
        }

        Text {
            id: settingsItemTitle;
            text: qsTr("Настройки") + SettingsManager.tsStr;
            anchors.horizontalCenter: settingsItem.horizontalCenter;
            anchors.top: settingsItem.bottom;
            anchors.topMargin: Screen.pixelDensity*5;
            font.family: SettingsManager.textFont;
            font.pointSize: SettingsManager.textFontH4;
            font.weight: Font.Thin;
            color: SettingsManager.fgInactiveColor;
            opacity: 0;
            Behavior on opacity { NumberAnimation { duration: 1600; } }
        }

    }

    onVisibleChanged: if (visible) mainMenu.activate();
                      else mainMenu.deactivate();
}
