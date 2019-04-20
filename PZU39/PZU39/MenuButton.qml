import QtQuick 2.0
import QtQuick.Window 2.2
import "."

Item {
    id: root
    signal clicked();
    property alias text: label.text
    property int fontsize: 12
    property bool state: false
    property bool isCheckable: false

    Rectangle
    {
        id: button
        anchors.fill: parent
        color: if(!isCheckable) {return Style.inactiveBtnColor;}
               else{  return root.state ? Style.activeBtnColor : Style.inactiveBtnColor }

        border.color: Style.borderMenuBtnColor
        border.width: 2
        radius: width/6

        Text{
            id: label;
            color: Style.fgColor
            font.pointSize: root.fontsize
            font.family: dejavuFont.name
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter;
            verticalAlignment: Text.AlignVCenter;
        }
        MouseArea{
            id: buttonArea;
            anchors.fill: parent;
//            anchors.leftMargin: 30
//            anchors.rightMargin: 30
//            anchors.topMargin: 20
//            anchors.bottomMargin: 20
            onClicked: root.clicked();
            onPressed:  {
                if(root.isCheckable) return;
                button.color = Style.activeBtnColor;
            }
            onReleased: {
                if(root.isCheckable) return;
                button.color = Style.inactiveBtnColor;
            }
        }
    }
}
