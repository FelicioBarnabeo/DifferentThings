import QtQuick 2.0
import QtGraphicalEffects 1.0
import "."

Item {
    id: root
    signal key(var key);
    signal release(var key);
    signal holdKey(var key);
    property string baseKey: "";
    property alias text: label.text
    property alias fontsize: label.font.pointSize
    Rectangle{

        RectangularGlow {
             id: effect
             anchors.fill: button;
             glowRadius: 20;
             spread: 0.4;
             color: Style.activeBtnColor;
             cornerRadius: button.radius + glowRadius - 5
             visible: false;
        }

        id: button
        anchors.fill: parent
        //radius: width/2
        color: "transparent"
        //border.width: 1
        //border.color: Style.borderMenuBtnColor
        Text{
            id: label;
            color: Style.fgColor
            font.family: Style.fontIcon
            font.pointSize: Style.fontSizeH4
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter;
            verticalAlignment: Text.AlignVCenter;
        }
        MouseArea{
            id: buttonArea;
            anchors.fill: parent;
            anchors.leftMargin: -18
            anchors.rightMargin: -18
            anchors.topMargin: -18
            anchors.bottomMargin: -14         
            onPressed: {
                //label.color = Style.activeBtnColor;
                effect.visible = true
                key(baseKey);
            }
            onReleased: {
                //label.color = Style.fgColor;
                 effect.visible = false
                release(baseKey);
            }
            onPressAndHold: {
                effect.visible = true
                holdKey(baseKey);
            }
        }
    }
}
