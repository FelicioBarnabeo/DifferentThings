import QtQuick 2.3
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0
import ColorSlider 1.0

Item {
    id: root;
    focus: true
    property int radius: 80
    property int spanAngle : -1;
    property alias centerX: circle.centerX
    property alias centerY: circle.centerY
    property string currentHue: "red"
    property string colorSend: "red"
    property int currentProcentLight: 50 // from 0 to 100
    property bool state: false
    signal sendcolor();
    signal onClicked();
    signal offClicked();
    property string offText: ""
    property string onText: ""


    ColorDefiner{
        id:colordefiner
        Component.onCompleted: {
            colordefiner.loadImage(":/circle.png",radius*2,radius*2);
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
        background.color = colordefiner.getColorByDegrees(root.radius-1, root.spanAngle);
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
        width: root.radius*2
        height: root.radius*2
        color: "transparent"
        Image
        {
            id: circle
            source: "circle.png"
            anchors.fill: parent
            antialiasing: true;
            smooth: true;
            property int centerX: x+root.radius
            property int centerY: y+root.radius
        }

        Image{
            id: hndl
            width: 36
            height: 36
            antialiasing: true;
            smooth: true;
            source: handleArea.pressed ? "handle_pressed.png" : "handle_inactive.png"
            // need remove 1 pixel from root.radius for avoid getting black pixels from the edge of the circle image texture
            x: (circle.centerX + ((dragObj.x - circle.centerX) * ((root.radius-1) / dragObj.dragRadius)))-width/2
            y: (circle.centerY + ((dragObj.y - circle.centerY) * ((root.radius-1) / dragObj.dragRadius)))-height/2

            MouseArea{
                id: handleArea
                anchors.margins: -10
                anchors.fill: parent
                drag.target: dragObj
                onPositionChanged: {
                    switcher.color = colordefiner.getColor(hndl.x+hndl.width/2,hndl.y+hndl.height/2);
                }
                onReleased:  {
                    var angle = colordefiner.getAngleByCoordinates(hndl.x+hndl.width/2.0, hndl.y+hndl.height/2.0, circle.centerX, circle.centerY);
                    angle = colordefiner.oddAngle(angle);
                    console.log("angle = ",angle);
                    //Порядок инициализации очень важен!
                    root.colorSend = colordefiner.getColorByDegrees(root.radius, root.radius, root.radius-1, angle);
                    root.currentHue = root.colorSend;
                    root.colorSend = colordefiner.getColorValue(root.colorSend,root.currentProcentLight - root.currentProcentLight%10);
                    switcher.color = root.colorSend;
                    console.log("color = ",switcher.color)
                    if(root.state) root.sendColor();

                }
            }
        }

        Item {
            id: dragObj
            readonly property real dragRadius: Math.sqrt(Math.pow(x - root.radius, 2) + Math.pow(y - root.radius, 2))
            x: circle.x
            y: circle.centerY
        }
//            Component.onCompleted: {
//                colorTick.start();
//            }
    }

    Rectangle
    {
        id: lightGradient
        anchors.top: background.bottom
        anchors.topMargin: Screen.pixelDensity*8
        anchors.horizontalCenter: parent.horizontalCenter
        //border.color: "black"
        //border.width: 2
        width:160
        height: 10
        LinearGradient {
            anchors.fill: parent
            start: Qt.point(0, 2)
            end: Qt.point(width, 2)
            gradient: Gradient {
            GradientStop { position: 0.0; color: "white" }
            GradientStop { position: 0.5; color: root.currentHue }
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
        x: lightGradient.x+lightGradient.width/2-marker.width/2
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
                root.colorSend = colordefiner.getColorValue(root.currentHue,root.currentProcentLight - root.currentProcentLight%10);
                switcher.color = root.colorSend;
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
