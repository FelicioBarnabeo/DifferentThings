import QtQuick 2.6
import QtQuick.Window 2.0

Rectangle {
    signal editDone(var text);
    function close() {
        vkeyboard.editDone(vkeyboard.text);
        vkeyboard.visible = false;
    }

    function open(text) {
        vkeyboard.text = text;
        vkeyboard.visible = true;
    }

    property string text: ""
    onTextChanged: textInput.text = vkeyboard.text;

    id: vkeyboard;
    visible: false
    color: "#FFC2C2C2";

    Item {
        id: editFrame;
        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.top: parent.top;
        height: Screen.pixelDensity*20;

        Rectangle {
            anchors.centerIn: editFrame;
            width: editFrame.width*0.7;
            height: editFrame.height>>1;
            color: "#FFF2F2F2";
            border.color: "black"
            border.width: 1;
            radius: Screen.pixelDensity;

            TextInput {
                id: textInput;
                anchors.fill: parent;
                anchors.margins: Screen.pixelDensity*2;
                verticalAlignment: TextInput.AlignVCenter;
                horizontalAlignment: TextInput.AlignRight;
            }
        }
    }

    Item {
        property bool altLayout: false;

        id: vkeyFrame;
        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.top: editFrame.bottom;
        anchors.bottom: parent.bottom;
        anchors.margins: Screen.pixelDensity*5;

        Column {

            anchors.centerIn: parent;
            spacing: Screen.pixelDensity*3;

            Row {
                anchors.horizontalCenter: parent.horizontalCenter;
                spacing: Screen.pixelDensity*3;
                VKey {key:"1";altkey:"1";onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"2";altkey:"2";onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"3";altkey:"3";onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"4";altkey:"4";onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"5";altkey:"5";onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"6";altkey:"6";onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"7";altkey:"7";onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"8";altkey:"8";onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"9";altkey:"9";onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"0";altkey:"0";onKeyEvent:vkeyboard.text+=key;}
            }

            Row {
                anchors.horizontalCenter: parent.horizontalCenter;
                spacing: Screen.pixelDensity*3;
                VKey {key:"~";altkey:"_";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"!";altkey:"@";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:":";altkey:"#";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:";";altkey:"&";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:",";altkey:"?";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:".";altkey:"(";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"/";altkey:")";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"<";altkey:"+";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:">";altkey:"-";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"=";altkey:"'";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
            }

            Row {
                anchors.horizontalCenter: parent.horizontalCenter;
                spacing: Screen.pixelDensity*3;
                VKey {key:"q";altkey:"Q";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"w";altkey:"W";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"e";altkey:"E";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"r";altkey:"R";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"t";altkey:"T";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"y";altkey:"Y";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"u";altkey:"U";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"i";altkey:"I";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"o";altkey:"O";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"p";altkey:"P";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
            }

            Row {
                anchors.horizontalCenter: parent.horizontalCenter;
                spacing: Screen.pixelDensity*3;
                VKey {key:"a";altkey:"A";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"s";altkey:"S";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"d";altkey:"D";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"f";altkey:"F";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"g";altkey:"G";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"h";altkey:"H";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"j";altkey:"J";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"k";altkey:"K";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"l";altkey:"L";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
            }

            Row {
                anchors.horizontalCenter: parent.horizontalCenter;
                spacing: Screen.pixelDensity*3;
                VKey {
                    key:"Shift";altkey:"Shift";
                    onKeyEvent: vkeyFrame.altLayout=!vkeyFrame.altLayout
                }
                VKey {key:"z";altkey:"Z";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"x";altkey:"X";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"c";altkey:"C";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"v";altkey:"V";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"b";altkey:"B";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"n";altkey:"N";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}
                VKey {key:"m";altkey:"M";alt:vkeyFrame.altLayout;onKeyEvent:vkeyboard.text+=key;}

                VKey {key:"Del";altkey:"Del";onKeyEvent:vkeyboard.text=vkeyboard.text.slice(0,-1)}

            }
            Row {
                anchors.horizontalCenter: parent.horizontalCenter;
                spacing: Screen.pixelDensity*3;

                VKey {key:"Clear";altkey:"Clear";onKeyEvent:vkeyboard.text="";}
                VKey {
                    key:"Space";altkey:"Space";
                    height:_temp.height;
                    width: vkeyFrame.width>>1;
                    onKeyEvent:vkeyboard.text +=" ";
                }
                VKey {id: _temp;key:"Enter";altkey:"Enter";onKeyEvent: vkeyboard.close()}
            }
        }
    }
}
