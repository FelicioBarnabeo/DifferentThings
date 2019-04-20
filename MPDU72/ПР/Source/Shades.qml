import QtQuick 2.0
import QtQuick.Window 2.0
import "."

Item {
    id:root

    TopBar{
        id: topbar
        text: qsTr("ШТОРЫ")
    }

    MouseArea{
        anchors.fill: parent
        enabled: true;
    }

    Rectangle{
        anchors.top: topbar.bottom
        anchors.bottom: downbar.top
        anchors.left: root.left
        anchors.right: root.right
        color: Style.bgcolor

            Rectangle{
                id: up
                anchors.top: parent.top
                anchors.topMargin: Screen.pixelDensity*3
                anchors.horizontalCenter: parent.horizontalCenter
                height: Screen.pixelDensity*12
                width: Screen.pixelDensity*30
                radius: width/2
                color: Style.inactiveBtnColor
                border.color: Style.borderMenuBtnColor
                border.width: 3
                Text{
                    anchors.centerIn: parent
                    font.family: Style.fontIcon
                    text: "\uf126"
                    font.pointSize: 18
                    font.bold: true
                    color: Style.fgColor
                }
                MouseArea{
                    anchors.fill: parent
                    anchors.margins: -10
                    onPressed:{
                        parent.color = Style.activeBtnColor
                    }

                    onPressAndHold: {
                        driver.startSend("KEY_JAL_OPEN","msophex");
                        parent.color = Style.activeBtnColor
                    }
                    onReleased: {
                        driver.stopSend("KEY_JAL_OPEN","msophex");
                        parent.color = Style.inactiveBtnColor
                    }
                }
            }
            Image{
                //anchors.top: up.bottom
                //anchors.bottom: down.top
                source: "images/whiteShades.png"
                //anchors.centerIn: parent.Center
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                width: 70
                height: 70
                antialiasing: true
            }


            Rectangle{
                id:down
                anchors.bottom: parent.bottom
                anchors.bottomMargin: Screen.pixelDensity*3
                anchors.horizontalCenter: parent.horizontalCenter
                height: Screen.pixelDensity*12
                width: Screen.pixelDensity*30
                color: Style.inactiveBtnColor
                border.color: Style.borderMenuBtnColor
                border.width: 3
                radius: width/2
                Text{
                    anchors.centerIn: parent
                    font.family: Style.fontIcon
                    text: "\uf123"
                    font.bold: true
                    font.pointSize: 18
                    color: Style.fgColor
                }
                MouseArea{
                    anchors.fill: parent
                    anchors.margins: -10
                    onPressed:{
                        parent.color = Style.activeBtnColor
                    }
                    onPressAndHold: {
                        driver.startSend("KEY_JAL_CLOSE","msophex");
                        parent.color = Style.activeBtnColor
                    }
                    onReleased: {
                        driver.stopSend("KEY_JAL_CLOSE","msophex");
                        parent.color = Style.inactiveBtnColor
                    }
                }
            }
        }


    DownBar{
        id: downbar
    }
}
