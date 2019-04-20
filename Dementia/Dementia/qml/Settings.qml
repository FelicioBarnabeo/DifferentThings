import QtQuick 2.0
import QtQuick.Window 2.0

Item {
    property int idx: 7;

    function activate() {
        _topBar.opacity = 1;
        _saveBtn.x = Screen.pixelDensity*10;
        _rootBtn.x = _settings.width - _rootBtn.width - Screen.pixelDensity*10;
    }

    function deactivate() {
        _topBar.opacity = 0;
        _saveBtn.x = -_saveBtn.width-Screen.pixelDensity*10;
        _rootBtn.x = _settings.width+Screen.pixelDensity*10;
    }

    function initUI() {
        _audioVol.value = SettingsManager.audioVolume;
        _videoVol.value = SettingsManager.videoVolume;
        _gameVol.value = SettingsManager.gameVolume;
        _brightness.value = SettingsManager.screenBrightness;
        if (SettingsManager.language === "ru") _langRu.check();
        else if (SettingsManager.language === "en") _langEn.check();
    }

    function apply() {
        note.show();
        SettingsManager.audioVolume = _audioVol.value;
        SettingsManager.videoVolume = _videoVol.value;
        SettingsManager.gameVolume = _gameVol.value;
        SettingsManager.screenBrightness = _brightness.value;
        if (_langRu.checked) SettingsManager.language = "ru";
        else if (_langEn.checked) SettingsManager.language = "en";
        unblocker.start(); // workaround
    }
////////////////////////////////////////////////////////////////
    // workaround timer to stop ui freeze
    Timer {
       id: unblocker;
       interval: 50;
       onTriggered: {
           SettingsManager.save();
           SettingsManager.apllyTranslation();
           note.hide();
       }
    }
////////////////////////////////////////////////////////////////
    id: _settings;

    TopBar {
        id: _topBar;
        iconEnable: true;
        title: qsTr("Настройки") + SettingsManager.tsStr;
    }

    Grid {
        id: _optionsGrid;
        anchors.centerIn: parent;
        columns: 2;
        rows: 5;
        spacing: Screen.pixelDensity*5;

        Text {
            text: qsTr("Язык")+":"+ SettingsManager.tsStr;
            font.family: SettingsManager.textFont;
            font.pointSize: SettingsManager.textFontH4;
            color: SettingsManager.fgInactiveColor;
            width: parent.width*0.4;
            height: Screen.pixelDensity*10;
            verticalAlignment: Text.AlignVCenter;
        }

        Row {
            id: _langsRow;
            ToogleButton {
                id: _langRu;
                width: Screen.pixelDensity*30;
                height: Screen.pixelDensity*10;
                itemTextSize: SettingsManager.textFontH5;
                text: qsTr("Русский") + SettingsManager.tsStr;
                onButtonClicked: {
                    _langEn.uncheck();
                }

            }

            Item { width: Screen.pixelDensity*5; height: 1;}

            ToogleButton {
                id: _langEn;
                width: Screen.pixelDensity*30;
                height: Screen.pixelDensity*10;
                itemTextSize: SettingsManager.textFontH5;
                text: qsTr("English") + SettingsManager.tsStr;
                onButtonClicked: {
                    _langRu.uncheck();
                }
            }
        }

        Text {
            text: qsTr("Громкость аудио")+":"+ SettingsManager.tsStr;
            font.family: SettingsManager.textFont;
            font.pointSize: SettingsManager.textFontH4;
            color: SettingsManager.fgInactiveColor;
            width: parent.width*0.4;
            height: Screen.pixelDensity*10;
            verticalAlignment: Text.AlignVCenter;
        }

        Item {
            width: _langsRow.width;
            height: _langsRow.height;
            NaviBar {
                id: _audioVol;
                maxVal: 100;
                width: parent.width;
                anchors.verticalCenter: parent.verticalCenter;
            }
        }

        Text {
            text: qsTr("Громкость видео")+":"+ SettingsManager.tsStr;
            font.family: SettingsManager.textFont;
            font.pointSize: SettingsManager.textFontH4;
            color: SettingsManager.fgInactiveColor;
            width: parent.width*0.4;
            height: Screen.pixelDensity*10;
            verticalAlignment: Text.AlignVCenter;
        }

        Item {
            width: _langsRow.width;
            height: _langsRow.height;
            NaviBar {
                id: _videoVol;
                maxVal: 100;
                width: parent.width;
                anchors.verticalCenter: parent.verticalCenter;
            }
        }

        Text {
            text: qsTr("Громкость игр")+":"+ SettingsManager.tsStr;
            font.family: SettingsManager.textFont;
            font.pointSize: SettingsManager.textFontH4;
            color: SettingsManager.fgInactiveColor;
            width: parent.width*0.4;
            height: Screen.pixelDensity*10;
            verticalAlignment: Text.AlignVCenter;
        }

        Item {
            width: _langsRow.width;
            height: _langsRow.height;
            NaviBar {
                id: _gameVol;
                maxVal: 100;
                width: parent.width;
                anchors.verticalCenter: parent.verticalCenter;
            }
        }

        Text {
            text: qsTr("Яркость")+":"+ SettingsManager.tsStr;
            font.family: SettingsManager.textFont;
            font.pointSize: SettingsManager.textFontH4;
            color: SettingsManager.fgInactiveColor;
            width: parent.width*0.4;
            height: Screen.pixelDensity*10;
            verticalAlignment: Text.AlignVCenter;
        }

        Item {
            width: _langsRow.width;
            height: _langsRow.height;
            NaviBar {
                id: _brightness;
                maxVal: 7;
                width: parent.width;
                anchors.verticalCenter: parent.verticalCenter;
            }
        }
    }

    Auth {
        id: _auth;
        visible: !_optionsGrid.visible;
        onBack: _optionsGrid.visible = true;
        onAuthSuccess: _settings.parent.push(71);
    }

    Button {
        id: _saveBtn;
        width: parent.width*0.3;
        height: Screen.pixelDensity*10;
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: Screen.pixelDensity*5;
        circleType: false;
        itemTextSize: SettingsManager.textFontH5;
        itemFont: SettingsManager.textFont;
        icon: qsTr("Применить") + SettingsManager.tsStr;
        onItemClicked: apply();
        visible: _optionsGrid.visible;

        Behavior on x { NumberAnimation { duration: 600; } }
    }

    Button {
        id: _rootBtn;
        width: parent.width*0.3;
        height: Screen.pixelDensity*10;
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: Screen.pixelDensity*5;
        circleType: false;
        itemTextSize: SettingsManager.textFontH5;
        itemFont: SettingsManager.textFont;
        icon: qsTr("Администрирование") + SettingsManager.tsStr;
        onItemClicked: _optionsGrid.visible = false;
        visible: _optionsGrid.visible;

        Behavior on x { NumberAnimation { duration: 600; } }
    }

    Note {
        id: note;
        text: qsTr("Применение изменений")+"..."+SettingsManager.tsStr;
    }

    onVisibleChanged: (visible) ? activate() : deactivate();
    Component.onCompleted: {
        initUI();
        deactivate();
    }
}
