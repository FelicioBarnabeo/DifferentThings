import QtQuick 2.0
import QtQuick.Window 2.2
pragma Singleton

Item {
    id: root
    property color bgcolor:            Settings.bgColor
    property color fgColor:            Settings.fgColor;
    property color inactiveBtnColor:   Settings.inactiveBtnClr
    property color activeBtnColor:     Settings.activeBtnClr
    property color borderMenuBtnColor: Settings.borderMenuBtnClr
    property color barColor:           Settings.barClr
    property int fontSizeH1:           Settings.iconFontH1
    property int fontSizeH2:           Settings.iconFontH2
    property int fontSizeH3:           Settings.iconFontH3
    property int fontSizeH4:           Settings.iconFontH4
    property int fontSizeH5:           Settings.iconFontH5
    property int fontSizeH6:           Settings.iconFontH6
    property string fontIcon:          Settings.iconFont
}
