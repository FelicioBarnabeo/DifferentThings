import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Layouts 1.1
import "."

Item {
    id: root
    width: parent.width
    height: parent.height
    //anchors.fill: parent
    property bool isCell: false
    property bool isBort: false
    property bool isBed: false
    property bool isDecor: false
    property bool isGlavZal: false

    MouseArea{
        anchors.fill: parent
        enabled: true;
    }

    TopBar{
        id: topbar
        text: qsTr("ОСВЕЩЕНИЕ")
    }



    Rectangle{
        anchors.top: topbar.bottom
        anchors.bottom: parent.bottom
        anchors.left: root.left
        anchors.right: root.right
        color: Style.bgcolor

        Column{
            visible: isGlavZal
            spacing: Screen.pixelDensity*4
            anchors.centerIn:  parent
            property int cellWidth: root.width*0.7;
            property int cellHeight: root.height/5;
            MenuButton{
               id: glavzal
               width: parent.cellWidth
               height: parent.cellHeight
               text: qsTr("ГЛАВНЫЙ ЗАЛ");
               //onClicked: pageStack.push(Qt.resolvedUrl("LightSwitch.qml"))
               onClicked: {
                   Configurator.switchToLightGlavzal();
                   SerialDevice.sendCommand(Configurator.msopLocalAnswer);
                   pageStack.push(comp3,{"header":qsTr("ГЛАВНЫЙ ЗАЛ"),"isZal":true})
               }
            }
            MenuButton{
               id: koridor
               width: parent.cellWidth
               height: parent.cellHeight
               text: qsTr("КОРИДОР")
               //onClicked: pageStack.push(Qt.resolvedUrl("LightSwitch.qml"))
               onClicked: {
                   //SerialDevice.sendCommand("9140");
                   SerialDevice.sendCommand(Configurator.msopLocalAnswer);
                   Configurator.switchToLightKoridor();
                   pageStack.push(comp3,{"header":qsTr("КОРИДОР"),"isHall":true})
               }
            }
        }

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
               state: Settings.lightUpperState;
               isCheckable: true
               width: parent.cellWidth
               height: parent.cellHeight
               text: qsTr("ПОТОЛОЧНОЕ")+Settings.qstrUpdateHook;
               fontsize: Style.fontSizeH1
               visible: root.isCell;
               onClicked: {
                   if(Settings.lightUpperState)
                   {
                       //SerialDevice.sendCommand(Configurator.lightUpperOn, Configurator.lightDirectUpperOn);
                       SerialDevice.sendCommand(Configurator.lightUpperOff, Configurator.lightDirectUpperOff);
                   }
                   else{
                       //SerialDevice.sendCommand(Configurator.lightUpperOff, Configurator.lightDirectUpperOff);
                       SerialDevice.sendCommand(Configurator.lightUpperOn, Configurator.lightDirectUpperOn);
                   }
               }
            }
            MenuButton{
               id: bort
               state: Settings.lightBortState;
               isCheckable: true
               width: parent.cellWidth
               height: parent.cellHeight
               text: qsTr("БОРТОВОЕ")+Settings.qstrUpdateHook;
               fontsize: Style.fontSizeH1
               visible: root.isBort;
               onClicked: {
                   if(Settings.lightBortState)
                   {
                       //SerialDevice.sendCommand(Configurator.lightBortOn, Configurator.lightDirectBortOn);
                       SerialDevice.sendCommand(Configurator.lightBortOff, Configurator.lightDirectBortOff);
                   }
                   else{
                       //SerialDevice.sendCommand(Configurator.lightBortOff, Configurator.lightDirectBortOff);
                       SerialDevice.sendCommand(Configurator.lightBortOn, Configurator.lightDirectBortOn);
                   }
               }
            }
            MenuButton{
               id:bed
               state: Settings.lightNicheState;
               isCheckable: true
               width: parent.cellWidth
               height: parent.cellHeight
               text: qsTr("ПОДСВЕТ НИШИ")+Settings.qstrUpdateHook;
               fontsize: Style.fontSizeH1
               visible: root.isBed;
               onClicked: {
                   if(Settings.lightNicheState)
                   {
                       //SerialDevice.sendCommand(Configurator.lightOverBedOn, Configurator.lightDirectOverBedOn);
                       SerialDevice.sendCommand(Configurator.lightOverBedOff,Configurator.lightDirectOverBedOff);
                   }
                   else{
                       //SerialDevice.sendCommand(Configurator.lightOverBedOff, Configurator.lightDirectOverBedOff);
                       SerialDevice.sendCommand(Configurator.lightOverBedOn,Configurator.lightDirectOverBedOn);
                   }
               }
            }
            MenuButton{
               id: decor
               state: Settings.lightDecorState;
               isCheckable: true
               width: parent.cellWidth
               height: parent.cellHeight
               text: qsTr("ДЕКОРАТИВНОЕ")+Settings.qstrUpdateHook;
               fontsize: Style.fontSizeH1
               anchors.horizontalCenter: Settings.currentZone===2 ? parent.horizontalCenter : undefined;
               visible: root.isDecor;
               onClicked: {
                   pageStack.push(Qt.resolvedUrl("DecorLight.qml"))
               }
            }
        }
    }

    Component{
        id: comp3
        LightSwitch{

        }
    }

//    Text{
//        id: recCmd;
//        width: 100
//        height: 100
//        font.pointSize: 24
//        //color: Qt.transparent.toString();
//        color: "black"
//        text: SerialDevice.currentCmd;
//        anchors.centerIn: parent
//    }

    Component.onCompleted: {
        //SerialDevice.write(Configurator.askDirectState)
        //SerialDevice.sendCommand(Configurator.askDirectState)
    }

}
