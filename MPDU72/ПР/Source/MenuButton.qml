import QtQuick 2.0
import QtQuick.Window 2.2
import "."

Item {
    id: root
    signal clicked();
    property alias text: label.text
    property color color: Style.inactiveBtnColor;
//    Rectangle{
//        id: botLine
//        color: Style.lineColor
//        height: 1
//        anchors.left: root.left
//        anchors.right: root.right
//        anchors.bottom: root.bottom
//        anchors.leftMargin: Screen.pixelDensity*5
//        anchors.rightMargin: Screen.pixelDensity*3

//    }
    Rectangle
    {
        id: button
        anchors.fill: parent
        color: root.color//Style.inactiveBtnColor;
        border.color: Style.borderMenuBtnColor
        border.width: 2
        radius: width/6

        Text{
            id: label;
            color: Style.fgColor
            font.pointSize: Style.fontSizeH2
            font.family: exofont.name//Style.fontText
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter;
            verticalAlignment: Text.AlignVCenter;
        }
        MouseArea{
            id: buttonArea;
            enabled: !pageStack.busy
            anchors.fill: parent;
            onClicked: root.clicked();
            onPressed:  {button.color = Style.activeBtnColor;}
            onReleased: {button.color = Style.inactiveBtnColor;}
        }
    }
}
