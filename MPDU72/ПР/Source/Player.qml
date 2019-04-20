import QtQuick 2.0
import QtQuick.Window 2.0

import "."

Item {
    id: root
    property bool isDvdMenu: false
    property bool isSlideShow: false
    property string header: qsTr("")

    MouseArea{
        anchors.fill: parent
        enabled: true;
    }

    TopBar{
        id: topbar
        text: qsTr(header)
    }

    Rectangle{
        id: window
        anchors.top: topbar.bottom
        anchors.bottom: root.bottom
        anchors.left: root.left
        anchors.right: root.right
        color: Style.bgcolor


        Rectangle{
            id: navigateRect
            color: Style.inactiveBtnColor
            width: parent.width/2+1
            height: parent.width/2+1
            rotation: 45
            //anchors.centerIn: parent
            anchors.top: window.top
            anchors.topMargin: Screen.pixelDensity*10
            anchors.horizontalCenter: parent.horizontalCenter
            border.width: 4
            border.color: Style.borderMenuBtnColor
            property real diag: width*0.7
        }

        PlayerButton{
            id: playpause
            width: Screen.pixelDensity*7
            height: Screen.pixelDensity*7
            anchors.centerIn: navigateRect
            property bool state: true
            Image{
                anchors.fill: parent
                source: "images/playpause.png"
            }
            onKey: {
                //if(state) driver.sendCommand("KEY_7","vista_mce");
                //else driver.sendCommand("KEY_8","vista_mce");
                //state = !state;
                driver.sendCommand("KEY_8", "vista_mce");
                //if(text=="\uf215") driver.sendCommand("KEY_7","vista_mce");
                //else driver.sendCommand("KEY_8","vista_mce")
                //text==="\uf215" ? text="\uf478" : text="\uf215"
            }
        }


        PlayerButton{
            id: up
            width: Screen.pixelDensity*5
            height: Screen.pixelDensity*5
            anchors.top: playpause.top
            anchors.topMargin: -navigateRect.diag+14
            anchors.horizontalCenter: parent.horizontalCenter
            //anchors.verticalCenter: navigateRect.verticalCenter
            text: "\uf126"
            onKey: driver.sendCommand("KEY_UP","vista_mce")
            onRelease: driver.stopSend("KEY_UP","vista_mce")
            onHoldKey: driver.startSend("KEY_UP","vista_mce")
        }
        PlayerButton{
            id: left
            width: Screen.pixelDensity*5
            height: Screen.pixelDensity*5
            anchors.verticalCenter: navigateRect.verticalCenter
            anchors.left: playpause.left
            anchors.leftMargin: -navigateRect.diag+14
            text: "\uf124"
            onKey: driver.sendCommand("KEY_LEFT","vista_mce")
            onRelease: driver.stopSend("KEY_LEFT","vista_mce")
            onHoldKey: driver.startSend("KEY_LEFT","vista_mce")
        }
        PlayerButton{
            id: right
            width: Screen.pixelDensity*5
            height: Screen.pixelDensity*5
            anchors.verticalCenter: navigateRect.verticalCenter
            anchors.right: playpause.right
            anchors.rightMargin: -navigateRect.diag+14
            text: "\uf125"
            onKey: driver.sendCommand("KEY_RIGHT","vista_mce")
            onRelease: driver.stopSend("KEY_RIGHT","vista_mce")
            onHoldKey: driver.startSend("KEY_RIGHT","vista_mce")
        }
        PlayerButton{
            id: down
            width: Screen.pixelDensity*5
            height: Screen.pixelDensity*5
            anchors.bottom: playpause.bottom
            anchors.bottomMargin: -navigateRect.diag+14
            anchors.horizontalCenter: navigateRect.horizontalCenter
            text: "\uf123"
            onKey: driver.sendCommand("KEY_DOWN","vista_mce")
            onRelease: driver.stopSend("KEY_DOWN","vista_mce")
            onHoldKey: driver.startSend("KEY_DOWN","vista_mce")
        }

        PlayerButton{
            visible: isDvdMenu
            id: eject
            width: Screen.pixelDensity*5
            height: Screen.pixelDensity*5
            x: left.x
            y: up.y
            text: "\uf131"
            onKey: driver.sendCommand("KEY_BACK","vista_mce");
        }

        PlayerButton{
            id: menuSlide
            visible: isDvdMenu || isSlideShow
            width: Screen.pixelDensity*5
            height: Screen.pixelDensity*5
            x: right.x
            y: up.y
            text: isDvdMenu ? "\uf394" : "\uf2d3"
            onKey: {
                if(isDvdMenu) driver.sendCommand("KEY_MENU","vista_mce");
                else driver.sendCommand("KEY_STOP","vista_mce"); //Код открытие слайдшоу по нажатию кнопки стоп с пульта
            }
        }

        PlayerButton{
            id: rightForward
            width: Screen.pixelDensity*5
            height: Screen.pixelDensity*5
            x: right.x
            y: down.y
            text: "\uf427"

            onKey:  {if(isDvdMenu) driver.sendCommand("KEY_FORWARD","vista_mce");
                    else driver.sendCommand("KEY_FASTFORWARD","vista_mce");}
            onRelease: {if(isDvdMenu) driver.stopSend("KEY_FORWARD","vista_mce");
                    else driver.stopSend("KEY_FASTFORWARD","vista_mce");}
            onHoldKey: {if(isDvdMenu) driver.startSend("KEY_FORWARD","vista_mce");
                    else driver.startSend("KEY_FASTFORWARD","vista_mce");}
        }
        PlayerButton{
            id: leftForward
            width: Screen.pixelDensity*5
            height: Screen.pixelDensity*5
            x: left.x
            y: down.y
            text: "\uf4a1"
            onKey:  {if(isDvdMenu) driver.sendCommand("Rwd","vista_mce");
                    else driver.sendCommand("KEY_REWIND","vista_mce");}
            onRelease: {if(isDvdMenu) driver.stopSend("Rwd","vista_mce");
                    else driver.stopSend("KEY_REWIND","vista_mce");}
            onHoldKey: {if(isDvdMenu) driver.startSend("Rwd","vista_mce");
                    else driver.startSend("KEY_REWIND","vista_mce");}

        }

        PlayerButton{
            id: stop
            width: Screen.pixelDensity*5
            height: Screen.pixelDensity*5
            x: playpause.x
            y: playpause.y + navigateRect.diag + 40
            text: "\uf24f"
            onKey: driver.sendCommand("KEY_9","vista_mce");
        }

        PlayerButton{
            id: fastRightForward
            width: Screen.pixelDensity*5
            height: Screen.pixelDensity*5
            x: right.x
            y: stop.y
            text: "\uf4ad"
            onKey:  {if(isDvdMenu) driver.sendCommand("KEY_FASTFORWARD","vista_mce");
                    else driver.sendCommand("KEY_FORWARD","mypr");}
            onRelease: {if(isDvdMenu) driver.stopSend("KEY_FASTFORWARD","vista_mce");
                    else driver.stopSend("KEY_FORWARD","mypr");}
            onHoldKey: {
                if(isDvdMenu)
                {
                    driver.startSend("KEY_FASTFORWARD","vista_mce");
                }
                else driver.startSend("KEY_FORWARD","mypr");}
        }
        PlayerButton{
            id: fastLeftForward
            width: Screen.pixelDensity*5
            height: Screen.pixelDensity*5
            x: left.x
            y: stop.y
            text: "\uf4ab"
            onKey:  {if(isDvdMenu) driver.sendCommand("KEY_REWIND","vista_mce");
                    else driver.sendCommand("KEY_REWIND","mypr");}
            onRelease: {if(isDvdMenu) driver.stopSend("KEY_REWIND","vista_mce");
                    else driver.stopSend("KEY_REWIND","mypr");}
            onHoldKey: {if(isDvdMenu) driver.startSend("KEY_REWIND","vista_mce");
                    else driver.startSend("KEY_REWIND","mypr");}
        }
    }

    DownBar{
        id: downbar
    }
}
