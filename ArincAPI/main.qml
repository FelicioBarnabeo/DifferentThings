import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    visible: true
    width: 800
    height: 600
    color: "#000000"

    MouseArea {
        anchors.bottomMargin: -136
        anchors.leftMargin: -58
        anchors.rightMargin: -210
        anchors.topMargin: -176
        anchors.fill: parent
        visible: true
        z: 0
        hoverEnabled: false
        transformOrigin: Item.Center
        onClicked: {
            Qt.quit();
        }

        Rectangle {
            id: rectangle1
            x: 154
            y: 189
            width: 258
            height: 576
            color: "#ffffff"

            Text {
                id: text1
                x: 8
                y: 20
                width: 97
                height: 22
                text: qsTr("CurrentMessage: ")
                font.pixelSize: 12
            }

            TextEdit {
                id: textEdit1
                x: 123
                y: 22
                width: 103
                height: 20
                text: qsTr("")
                readOnly: true
                font.pixelSize: 12
            }
        }


    }
}
