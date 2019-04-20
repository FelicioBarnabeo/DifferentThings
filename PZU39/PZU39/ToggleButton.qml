import QtQuick 2.0
import QtQuick.Window 2.2
import "."

Item {
    id: root
    signal clicked();
    property alias text: label.text
    property int fontsize: 12
    property bool active: false
    onActiveChanged: button.color = active ? Style.activeBtnColor : Style.inactiveBtnColor

    Rectangle
    {
        id: button
        anchors.fill: parent
        color: Style.inactiveBtnColor;
        border.color: Style.borderMenuBtnColor
        border.width: 2
        radius: width/6

        Text{
            id: label;
            color: Style.fgColor
            font.pointSize: fontsize
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter;
            verticalAlignment: Text.AlignVCenter;
        }
        MouseArea{
            id: buttonArea;
            anchors.fill: parent;
            onClicked: root.clicked();
            onPressed:  {
                active = !active
            }

        }
}
}
