import QtQuick 2.3
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0

Item{
    id: root;
    focus: true
    anchors.fill: parent
    property int radius: 80
    property int spanAngle : -1;
    property alias centerX: circle.centerX
    property alias centerY: circle.centerY
    property string currentHue: "white"
    property int currentProcentLight: 0 // from 0 to 100
    property bool state: false   //turn on-off color send
    signal onClicked();
    signal offClicked();
    signal sendColor();
    property string offText: "ВЫКЛ"
    property string onText: "ВКЛ"
    property string colorSend: "white"

    MouseArea{
        anchors.fill: parent
        enabled: true;
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
        background.color = ColorDefiner.getColorByDegrees(root.radius-1, root.spanAngle);
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
        //anchors.top: parent.top
        //anchors.topMargin: Screen.pixelDensity*3
        anchors.left: parent.left
        anchors.leftMargin: Screen.pixelDensity*10
        //anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        width: root.radius*2
        height: root.radius*2
        color: "transparent"
        Image
        {
            id: circle
            source: "images/ColorWheel/circle.png"
            anchors.fill: parent
            antialiasing: true;
            smooth: true;
            property int centerX: x+root.radius
            property int centerY: y+root.radius
        }


        Image{
            id: hndl
            width: 40
            height: 40
            antialiasing: true;
            smooth: true;
            source: handleArea.pressed ? "images/ColorWheel/handle_pressed.png" : "images/ColorWheel/handle_inactive.png"
            // need remove 1 pixel from root.radius for avoid getting black pixels from the edge of the circle image texture
            x: (circle.centerX + ((dragObj.x - circle.centerX) * ((root.radius-1) / dragObj.dragRadius)))-width/2
            y: (circle.centerY + ((dragObj.y - circle.centerY) * ((root.radius-1) / dragObj.dragRadius)))-height/2

            MouseArea{
                id: handleArea
                anchors.margins: -10
                anchors.fill: parent
                drag.target: dragObj
                onPositionChanged: {
                    switcher.color = ColorDefiner.getColor(hndl.x+20,hndl.y+20);
                    //console.log("pos change color = ",switcher.color);
                }

                onReleased:  {
                    var angle = ColorDefiner.getAngleByCoordinates(hndl.x+hndl.width/2.0, hndl.y+hndl.height/2.0, circle.centerX, circle.centerY);
                    angle = ColorDefiner.oddAngle(angle);
                    //console.log("angle = ",angle);
                    //Порядок инициализации очень важен!
                    root.colorSend = ColorDefiner.getColorByDegrees(root.radius, root.radius, root.radius-1, angle);
                    root.currentHue = root.colorSend;
                    root.colorSend = ColorDefiner.getColorValue(root.colorSend,root.currentProcentLight - root.currentProcentLight%10);
                    switcher.color = root.colorSend;
                    //console.log("color = ",switcher.color)
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
        //anchors.top: parent.top
        //anchors.topMargin: Screen.pixelDensity*3
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: Screen.pixelDensity*15
        border.color: "white"
        border.width: 2
        width:16
        height: 160
        gradient: Gradient{
            GradientStop { position: 0.0; color: root.currentHue }
            GradientStop { position: 1.0; color: "black" }
        }
//        MouseArea{
//            onClicked: {
//                marker.y = mouseY;
//                marker.
//            }
//        }
    }

    Rectangle{
        id: marker
        width: 28
        height: Screen.pixelDensity*4
        border.width: 2
        border.color: "black"
        radius: 4
        color: "transparent"
        x: lightGradient.x-6
        y: lightGradient.y
        MouseArea{
            id: markerArea
            anchors.fill: parent
            anchors.margins: -15
            drag.target: marker
            drag.axis: Drag.YAxis
            drag.minimumY: lightGradient.y
            drag.maximumY: lightGradient.y + lightGradient.height - marker.height
            onReleased: {
                root.currentProcentLight = 100 * ((marker.y-drag.minimumY) / (drag.maximumY-drag.minimumY))
                //not need 100% off lighting
                if(root.currentProcentLight==100)
                    root.currentProcentLight=root.currentProcentLight-1;
                //console.log("currentProcLight=",root.currentProcentLight);
                root.colorSend = ColorDefiner.getColorValue(root.currentHue,root.currentProcentLight - root.currentProcentLight%10);
                //console.log("Procent = ",root.currentProcentLight - root.currentProcentLight%10);
                //console.log("marker.y = ",marker.y, "maxy=", drag.maximumY);
                switcher.color = root.colorSend;
                //console.log("color = ",switcher.color)
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
        color: "white"
        border.width: 1
        property color unPress: "white"
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
                if(root.state)
                {
                    root.offClicked();
                    switcher.color = "white";
                }
                else
                {
                    root.onClicked();
                }
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
