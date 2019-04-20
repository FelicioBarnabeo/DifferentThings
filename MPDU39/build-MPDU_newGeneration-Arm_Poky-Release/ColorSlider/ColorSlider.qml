import QtQuick 2.3
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0
import ColorSlider 1.0

Item {

    id: root;
    focus: true
    property int spanAngle : -1;
    property string currentHue: "red"
    property int currentProcentLight: 0 // from 0 to 100
    property bool state: false
    signal onClicked();
    signal offClicked();
    signal sendColor();
    property string offText: "ВЫКЛ"
    property string onText: "ВКЛ"
    property alias currentColor: switcher.color

    ColorDefiner{
        id:colordefiner
        rad: 80
        center: Qt.point(80,80)
        Component.onCompleted: {
            colordefiner.loadImage(":/circle.png",160,160);
        }
    }

    Keys.onLeftPressed: {
        //console.log("space pressed")
        root.spanAngle = root.spanAngle+1;
    }
    Keys.onRightPressed: {
        root.spanAngle = root.spanAngle-1
    }

    onSpanAngleChanged: {
        //console.log("span changed")
        background.color = colordefiner.getColorByDegrees(circle.radius-1, root.spanAngle);
    }

//        Timer{
//            id: colorTick
//            running: false;
//            repeat: true
//            interval: 10;
//            onTriggered: {
////                ColorDefiner.makeColorWheelMap(root.radius);
// //           }

//                if(root.spanAngle < 360){
//                    background.color = ColorDefiner.getColorByDegrees(root.radius, root.spanAngle);
//                    root.spanAngle = root.spanAngle+1;
//                    console.log(root.spanAngle, app.color);
//                }
//                else colorTick.stop();
//                }
//        }


    Rectangle{
        id: background
        anchors.top: parent.top
        anchors.topMargin: Screen.pixelDensity*3
        anchors.horizontalCenter: parent.horizontalCenter
        width: colordefiner.rad*2
        height: colordefiner.rad*2
        color: "transparent"
        Image
        {
            id: circle
            source: "circle.png"
            anchors.fill: parent
            antialiasing: true;
            smooth: true;
            property int radius: colordefiner.rad
            property int cX: x+colordefiner.center.x
            property int cY: y+colordefiner.center.y
        }

        Image{
            id: hndl
            width: 36
            height: 36
            antialiasing: true;
            smooth: true;
            source: handleArea.pressed ? "handle_pressed.png" : "handle_inactive.png"
            // need remove 1 pixel from root.radius for avoid getting black pixels from the edge of the circle image texture
            x: (circle.cX + ((dragObj.x - circle.cX) * ((circle.radius-1) / dragObj.dragRadius)))-width/2
            y: (circle.cY + ((dragObj.y - circle.cY) * ((circle.radius-1) / dragObj.dragRadius)))-height/2

            MouseArea{
                id: handleArea
                anchors.margins: -10
                anchors.fill: parent
                drag.target: dragObj
                onPositionChanged: {
                    switcher.color = colordefiner.getColor(hndl.x+hndl.width/2,hndl.y+hndl.height/2);
                }
                onReleased:  {
                    var angle = colordefiner.getAngleByCoordinates(hndl.x+hndl.width/2.0, hndl.y+hndl.height/2.0, circle.cX, circle.cY);
                    angle = colordefiner.oddAngle(angle);
                    root.currentHue = colordefiner.getColorByDegrees(angle);
                    switcher.color = colordefiner.getColorValue(root.currentHue,root.currentProcentLight - root.currentProcentLight%10);
                    console.log("angle = color = ",angle, switcher.color)
                    if(root.state) root.sendColor();
                }
            }
        }

        Item {
            id: dragObj
            readonly property real dragRadius: Math.sqrt(Math.pow(x - circle.radius, 2) + Math.pow(y - circle.radius, 2))
            x: circle.x
            y: circle.cY
        }

//        Component.onCompleted: {
//            //colorTick.start();
//            //colordefiner.makeColorWheelMap(2,10);
//        }
    }

    Rectangle
    {
        id: lightGradient
        anchors.top: background.bottom
        anchors.topMargin: Screen.pixelDensity*8
        anchors.horizontalCenter: parent.horizontalCenter
        width:circle.width
        height: 10
        LinearGradient {
            anchors.fill: parent
            start: Qt.point(0, 2)
            end: Qt.point(width, 2)
            gradient: Gradient {
            GradientStop { position: 0.0; color: root.currentHue }
            GradientStop { position: 1.0; color: "black" }
        }
        }
    }

    Rectangle{
        id: marker
        width: Screen.pixelDensity*4
        height: 28
        border.width: 2
        border.color: "black"
        radius: 4
        color: "transparent"
        x: lightGradient.x
        y: lightGradient.y-9
        MouseArea{
            id: markerArea
            anchors.fill: parent
            anchors.margins: -15
            drag.target: marker
            drag.axis: Drag.XAxis
            drag.minimumX: lightGradient.x
            drag.maximumX: lightGradient.x + lightGradient.width - marker.width
            onReleased: {
                root.currentProcentLight = 100 * ((marker.x-drag.minimumX) / (drag.maximumX-drag.minimumX))
                switcher.color = colordefiner.getColorValue(root.currentHue,root.currentProcentLight - root.currentProcentLight%10);
                console.log("color = ",switcher.color)
                if(root.state) root.sendColor();
            }
        }
    }

    Rectangle{
        id: switcher
        anchors.centerIn: background
        width: circle.width/2
        height: circle.height/2
        radius: width/2
        color: "red"
        border.width: 1
        property color unPress: "red"
        Rectangle{
            id: innerOff
            width: switcher.width/1.5
            height: switcher.height/1.5
            radius: width/2
            anchors.centerIn: switcher
            color: "#32434A"
            border.width: 1
            Text{
                id: innerText
                text: root.onText
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter;
                verticalAlignment: Text.AlignVCenter;
                font.pixelSize: 16
                color: "white"
            }
        }
        MouseArea{
            id: area
            anchors.fill: parent
            onPressed: {
                switcher.unPress = switcher.color;
                switcher.color = Qt.darker(switcher.color);
                innerText.text = (innerText.text===root.onText)? root.offText: root.onText
                root.state = !root.state
                if(state) root.onClicked(); else root.offClicked();
            }
            onReleased: {
                switcher.color = switcher.unPress;
            }
        }
    }

    DropShadow {
        anchors.fill: switcher
        horizontalOffset: 5
        verticalOffset: 5
        radius: 3
        samples: 17
        color: "#80000000"
        source: switcher
    }
}
