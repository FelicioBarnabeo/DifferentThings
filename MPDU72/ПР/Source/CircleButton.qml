import QtQuick 2.0
import "."

Item {
    id: root
    signal clicked();
    property alias text: label.text
    property alias fontsize: label.font.pointSize
    property alias radius: circle.radius

    //property alias bordercolor: circle.border.width

    Rectangle{
        id: circle
        anchors.fill: parent
        radius: width / 2
        color: Style.inactiveCircleBtnColor
        border.width: 1
        //anchors.margins: 2

        Text{
            id: label;
            color: Style.bgcolor
            font.family: Style.fontIcon
            font.pointSize: Style.fontSizeH4
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter;
            verticalAlignment: Text.AlignVCenter;
        }
        MouseArea{
            id: buttonArea;
            anchors.fill: parent;
            onClicked: root.clicked();
            onPressed:  {circle.color = Style.activeCircleBtnColor}
            onReleased: {label.color = Style.bgcolor; circle.color = Style.inactiveCircleBtnColor}
        }
    }
}
