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
    property int fontsize: 10
    Rectangle{
        id: button
        anchors.fill: parent
        color: "transparent"
        border.width: 1
        border.color: Style.fgColor
        radius: width/2
        RectangularGlow {
             id: effect
             anchors.fill: button;
             glowRadius: 20;
             spread: 0.4;
             color: Style.activeBtnColor;
             cornerRadius: button.radius + glowRadius - 5
             visible: false;
        }
        Text{
            id: label;
            color: Style.fgColor
            font.family: Style.fontIcon
            font.pointSize: root.fontsize
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
                effect.visible = true
                key(baseKey);
            }
            onReleased: {
                 effect.visible = false
                release(baseKey);
            }
            onPressAndHold: {
                effect.visible = true
                holdKey(baseKey);
            }
        }
    }

    Component.onCompleted: root.fontsize = Style.fontSizeH3;
}
