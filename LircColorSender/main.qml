import QtQuick 2.2
import QtQuick.Window 2.2

Window {
    visible: true
    //color: root.cmdStr.replace("0x",'#')
//    width: Screen.pixelDensity*70.08;
//    height: Screen.pixelDensity*52.56;
    flags: Qt.FramelessWindowHint
    width: Screen.desktopAvailableWidth
    height: Screen.desktopAvailableHeight


    Item{
        id: root
        width: Screen.desktopAvailableHeight
        height: Screen.desktopAvailableWidth
        MouseArea{
            //focus: false
            anchors.fill: parent
            enabled: true;
        }
//        width: Screen.pixelDensity*52.56;
//        height: Screen.pixelDensity*70.08;
        //anchors.fill: parent
        property int func: 1
        property string cmdStr: ""
        property int cmdIdx: driver.idxCmd+1
        function timerFunction(){
            if(root.func == 1){
                root.cmdStr = driver.getPrevCmd();}
            else {root.cmdStr = driver.getNextCmd();}
        }

        Timer{
            id: iterator
            interval: 20
            repeat: true
            running: false
            onTriggered: {
                root.timerFunction();
            }
        }

        Rectangle{
            color: "red"
            anchors.left: parent.left
            anchors.top: parent.top
            width: 100
            height: 40
            Text{
                text: "PREV"
                font.pointSize: 24
            }
            MouseArea{
                anchors.fill: parent
                onPressed:  {
                    console.log("Pressed prev");
                    root.cmdStr = driver.getPrevCmd();
                }
            }
        }



        Rectangle{
            id : idCmd
            anchors.centerIn: parent
            border.width: 2
            border.color: "black"
            width: 120
            height: 40
            Text{
                horizontalAlignment: Text.AlignHCenter;
                verticalAlignment: Text.AlignVCenter;
                text: root.cmdStr
                color: "black"
                font.pointSize: 20
            }
        }
        Text{
            anchors.bottom: idCmd.top
            anchors.bottomMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
            width: 50
            height: 50
            text: root.cmdIdx
            font.pointSize: 20
            horizontalAlignment: Text.AlignHCenter;
            verticalAlignment: Text.AlignVCenter;
        }

        Rectangle{
            anchors.verticalCenter: idCmd.verticalCenter
            anchors.right: idCmd.left
            anchors.rightMargin: 5
            border.width: 2
            border.color: "black"
            width: 50
            height: 50
            Text{
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter;
                verticalAlignment: Text.AlignVCenter;
                text: "D"
                color: "black"
                font.pointSize: 20
            }
            MouseArea{
                anchors.fill: parent
                onPressAndHold: {
                    root.func = 1;
                    iterator.start();
                }
                onReleased: {
                    console.log("iter stop")
                    iterator.stop();
                }
            }
        }

        Rectangle{
            anchors.verticalCenter: idCmd.verticalCenter
            anchors.left: idCmd.right
            anchors.leftMargin: 5
            border.width: 2
            border.color: "black"
            width: 50
            height: 50
            Text{
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter;
                verticalAlignment: Text.AlignVCenter;
                text: "U"
                color: "black"
                font.pointSize: 20
            }
            MouseArea{
                anchors.fill: parent
                onPressAndHold: {
                    root.func = 2;
                    iterator.start();
                }
                onReleased: {
                    console.log("iter stop")
                    iterator.stop();
                }
            }
        }

        Rectangle{
            color: "red"
            anchors.right: parent.right
            anchors.top: parent.top
            width: 100
            height: 40
            Text{
                text: "NEXT"
                font.pointSize: 24
            }
            MouseArea{
                anchors.fill: parent
                onPressed:  {
                    console.log("Pressed next");
                    root.cmdStr = driver.getNextCmd();
                }
            }
        }

        Rectangle{
            color: "red"
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 30
            anchors.horizontalCenter: parent.horizontalCenter

            width: 100
            height: 40
            Text{
                text: "SEND"
                font.pointSize: 24
            }
            MouseArea{
                anchors.fill: parent
                onPressed:{
                    driver.sendCommand("KEY_#"+root.cmdStr,"ColorMngr");
                    console.log("KEY_#"+root.cmdStr,"ColorMngr");
                }
                onPressAndHold: driver.startSend("KEY_#"+root.cmdStr,"colorMngr")
                onReleased: driver.stopSend("KEY_#"+root.cmdStr,"colorMngr")
            }
        }

        x: parent.width
        transform: Rotation { origin.x: 0; origin.y: 0; axis { x: 0; y: 0; z: 1 } angle: 90 }
}
}
