import QtQuick 2.0
import QtQuick.Window 2.0
import "."

Item {
    id: root
    property alias text: label.text
    //property int batteryLevel: batteryClass.currentVolt*100
    height: Screen.pixelDensity*5
    anchors.left: parent.left
    anchors.right: parent.right
    anchors.top: parent.top

//    onBatteryLevelChanged: {
//        console.log("Charge = ",batteryLevel);
//        if(batteryLevel >= 80) battery.state = "full";
//        else if(batteryLevel >= 50) battery.state = "half";
//        else if(batteryLevel >= 25) battery.state = "low";
//        else battery.state = "empty";
//        console.log("state = ", battery.state);
//    }

    Rectangle{
        anchors.fill: root
        color: Style.barColor
        Text{
            id: label
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: Screen.pixelDensity*3
            font.pointSize: Style.fontSizeH1
            font.bold: true
            font.family: exofont.name//Style.fontText
            color: Style.fgColor
        }

        Battery{
            id: battery
            anchors.right: parent.right
            anchors.rightMargin: Screen.pixelDensity*1
            anchors.verticalCenter: parent.verticalCenter
            width: Screen.pixelDensity*5
            height: Screen.pixelDensity*3
        }

        Image{
            id: wave
            anchors.right: battery.left
            anchors.rightMargin: Screen.pixelDensity*2
            anchors.verticalCenter: parent.verticalCenter
            width: Screen.pixelDensity*4
            height: Screen.pixelDensity*4
            source: "images/rss-6x.png"
            visible: false
        }

//        Text{
//            id: wave
//            anchors.right: battery.left
//            anchors.rightMargin: Screen.pixelDensity*2
//            anchors.verticalCenter: parent.verticalCenter
//            font.pointSize: 12
//            font.family: Style.fontIcon
//            color: "white"
//            text: "\uf25c"
//            visible: false
//        }

        Timer{
            id: timerWave
            interval: 500
            running: true
            repeat: false
            onTriggered: wave.visible = false

        }

        Connections{
            target: driver
            onSendedOnce:{
                wave.visible = true;
                timerWave.start();
            }
            onSendStarted: {
                wave.visible = true;
            }
            onSendStopped: {
                wave.visible = false;

            }
        }

//        Text{
//            id: battery
//            anchors.right: parent.right
//            anchors.verticalCenter: parent.verticalCenter
//            anchors.rightMargin: Screen.pixelDensity*1
//            font.family: Style.fontIcon
//            font.pointSize: 16
//            text: "&#xf113";
//            color: "#00B600"
//            state: "full"
//            states: [
//                State {
//                    name: "empty"
//                    PropertyChanges { target: battery; color: "red" ; text:"\uf112"}
//                },
//                State {
//                    name: "low"
//                    PropertyChanges { target: battery; color: "orange"; text:"\uf115" }
//                },
//                State {
//                    name: "half"
//                    PropertyChanges { target: battery; color: "yellow"; text:"\uf114"}
//                },
//                State {
//                    name: "full"
//                    PropertyChanges { target: battery; color: "#00B600"; text:"\uf113" }
//                }
//            ]

//            MouseArea{
//                anchors.fill: parent
//                onPressed: {
//                    console.log("BATTERY LEVEL = ",root.batteryLevel)
//                }
//            }

//        }


    }
}
