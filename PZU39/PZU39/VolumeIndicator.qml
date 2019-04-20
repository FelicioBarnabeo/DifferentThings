import QtQuick 2.0
import QtQuick.Window 2.0
import "."

Item {
    id: indicator;
    property int size: 5;
    property int value: Settings.currentVolume;
    property int yline: line.y
    onValueChanged: {
        //SerialDevice.sendCommand(Configurator.callVolumeFunc(Configurator, value));
        SerialDevice.sendCommand(Configurator.outVlm.replace('$',value==10?"A":value));
        Settings.setCurrentVolume(value);
    }
    Row{
        id: line
        anchors.centerIn: parent;
        spacing: Screen.pixelDensity*1;
        Repeater{
            model: 10
            Rectangle{
                y: yline-2-index+17
                width: size
                height: size+2+index
                radius: size/2
                color: (value>(index)) ? "#55ff55" : Style.fgColor;

            }
        }
    }

//    Column {
//        id: col;
//        anchors.centerIn: parent;
//        spacing: Screen.pixelDensity*1;

//        Text {
//            text: "\uf111";
//            font.family: _Settings.iconFont;
//            font.pointSize: indicator.size
//            color: (value>9) ? "#55ff55" : _Settings.fgColor;
//        }

//        Text {
//            text: "\uf111";
//            font.family: _Settings.iconFont;
//            font.pointSize: indicator.size
//            color: (value>8) ? "#55ff55" : _Settings.fgColor;
//        }

//        Text {
//            text: "\uf111";
//            font.family: _Settings.iconFont;
//            font.pointSize: indicator.size
//            color: (value>7) ? "#55ff55" : _Settings.fgColor;
//        }

//        Text {
//            text: "\uf111";
//            font.family: _Settings.iconFont;
//            font.pointSize: indicator.size
//            color: (value>6) ? "#55ff55" : _Settings.fgColor;
//        }

//        Text {
//            text: "\uf111";
//            font.family: _Settings.iconFont;
//            font.pointSize: indicator.size
//            color: (value>5) ? "#55ff55" : _Settings.fgColor;
//        }

//        Text {
//            text: "\uf111";
//            font.family: _Settings.iconFont;
//            font.pointSize: indicator.size
//            color: (value>4) ? "#55ff55" : _Settings.fgColor;
//        }

//        Text {
//            text: "\uf111";
//            font.family: _Settings.iconFont;
//            font.pointSize: indicator.size;
//            color: (value>3) ? "#55ff55" : _Settings.fgColor;
//        }

//        Text {
//            text: "\uf111";
//            font.family: _Settings.iconFont;
//            font.pointSize: indicator.size
//            color: (value>2) ? "#55ff55" : _Settings.fgColor;
//        }

//        Text {
//            text: "\uf111";
//            font.family: _Settings.iconFont;
//            font.pointSize: indicator.size
//            color: (value>1) ? "#55ff55" : _Settings.fgColor;
//        }

//        Text {
//            text: "\uf111";
//            font.family: _Settings.iconFont;
//            font.pointSize: indicator.size
//            color: (value>0) ? "#55ff55" : _Settings.fgColor;
//        }
//    }
    Component.onCompleted: indicator.size = Screen.pixelDensity*2;

//    Connections{
//        target: SerialDevice;
//        onCmdSended:  topbar.text = cmd;
//    }
}
