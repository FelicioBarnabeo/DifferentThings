import QtQuick 2.0
import QtQuick.Window 2.2
import "."
pragma Singleton

Item {
    id: root
    property color bgcolor: "#32434A"//"#263238"
    property color fgColor: "#FFFFFF";
    property color inactiveCircleBtnColor: "#F9BE33"
    property color activeCircleBtnColor: Qt.darker(inactiveCircleBtnColor)
    property color inactiveBtnColor: "transparent"
    property color activeBtnColor: "#E97F23"
    property color borderBtnColor: "#000000"
    property color borderMenuBtnColor: "#46505A"
    property color barColor: "black"
    property int fontSizeH1: 10
    property int fontSizeH2: 12
    property int fontSizeH3: 16
    property int fontSizeH4: 21
    property int fontSizeH5: 24
    property int fontSizeH6: 32
    property string fontIcon: "ionicons"
    property string fontText: "exofont"
}
