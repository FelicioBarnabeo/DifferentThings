import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Layouts 1.1
import "."

Item {
    id: root
    width: parent.width
    height: parent.height
    //anchors.fill: parent
    property string header: ""
    property bool isHall: false
    property bool isZal: false

    MouseArea{
        anchors.fill: parent
        enabled: true;
    }

    TopBar{
        id: topbar
        text: qsTr(header)
    }

    Rectangle{
        anchors.top: topbar.bottom
        anchors.bottom: root.bottom
        anchors.left: root.left
        anchors.right: root.right
        color: Style.bgcolor

        GridLayout{
            id: grid
            columns: 2
            rows: 2
            anchors.top: parent.top
            anchors.topMargin: Screen.pixelDensity*4
            anchors.horizontalCenter: parent.horizontalCenter
            property int cellWidth: root.width*0.44 ;
            property int cellHeight: root.height/3;
            rowSpacing: Screen.pixelDensity*4
            columnSpacing: Screen.pixelDensity*4

            MenuButton{
               id: cell
               state: (isZal ? Settings.lightUpperState : Settings.lightHallUpperState);
               isCheckable: true
               width: parent.cellWidth
               height: parent.cellHeight
               text: qsTr("ПОТОЛОЧНОЕ")+Settings.qstrUpdateHook
               fontsize: Style.fontSizeH1
               onClicked: {
                   if(cell.state)
                   {
                       if(isZal)
                           SerialDevice.sendCommand(Configurator.lightUpperOff, Configurator.lightDirectUpperOff);
                       else
                           SerialDevice.sendCommand(Configurator.lightHallUpperOff, Configurator.lightHallDirectUpperOff);
                   }
                   else{
                       if(isZal)
                           SerialDevice.sendCommand(Configurator.lightUpperOn, Configurator.lightDirectUpperOn);
                       else
                           SerialDevice.sendCommand(Configurator.lightHallUpperOn,Configurator.lightHallDirectUpperOn);
                   }
               }
            }

            MenuButton{
               id: bort
               isCheckable: true
               state: (isZal ? Settings.lightBortState : Settings.lightHallBortState);
               width: parent.cellWidth
               height: parent.cellHeight
               text: qsTr("БОРТОВОЕ")+Settings.qstrUpdateHook
               fontsize: Style.fontSizeH1
               onClicked: {
                   if(bort.state)
                   {
                       if(isZal)
                       {
                           SerialDevice.sendCommand(Configurator.lightBortOff, Configurator.lightDirectBortOff);
                       }
                       else
                       {
                           SerialDevice.sendCommand(Configurator.lightHallBortOff, Configurator.lightHallDirectBortOff);
                       }
                   }
                   else
                   {
                       if(isZal)
                       {
                           SerialDevice.sendCommand(Configurator.lightBortOn, Configurator.lightDirectBortOn);
                       }
                       else
                       {
                           SerialDevice.sendCommand(Configurator.lightHallBortOn, Configurator.lightHallDirectBortOn);
                       }
                   }
               }
            }
            MenuButton{
                id: decor
                state: (isZal ? Settings.lightDecorState : Settings.lightHallDecorState);
                isCheckable: true
                width: parent.cellWidth
                height: parent.cellHeight
                text: qsTr("ДЕКОРАТИВНОЕ")+Settings.qstrUpdateHook;
                anchors.horizontalCenter: parent.horizontalCenter;
                fontsize: Style.fontSizeH1
                onClicked: {
                    //Settings.lightDecorState
                    pageStack.push(Qt.resolvedUrl("DecorLight.qml"))
                }
            }
        }
    }

}
