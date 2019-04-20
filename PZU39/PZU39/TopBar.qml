import QtQuick 2.0
import QtQuick.Window 2.0
import "."

Item {
    id: root
    property alias text: label.text
    //property int batteryLevel: batteryClass.currentVolt*100
    height: Screen.pixelDensity*8
    anchors.left: parent.left
    anchors.right: parent.right
    anchors.top: parent.top

    property bool isHome: true
    property bool isBack: true

    Rectangle{
        anchors.fill: root
        color: Style.barColor

        IconButton{
            id: home
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            anchors.margins: 1
            fontsize: Style.fontSizeH3
            height: Screen.pixelDensity*7;
            width: Screen.pixelDensity*13;
            text: "\uf38f"
            onClicked: pageStack.pop(null)
            topmargin: -15
            rightmargin: -15
            botmargin: -15
            visible: isHome
        }

        Text{
            id: label
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            //anchors.left: parent.left
            //anchors.leftMargin: Screen.pixelDensity*3
            font.pointSize: Style.fontSizeH1
            font.family: dejavuFont.name
            font.bold: true
            color: Style.fgColor
        }

        IconButton{
            id: back
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.margins: 1
            fontsize: Style.fontSizeH3
            height: Screen.pixelDensity*7;
            width: Screen.pixelDensity*13;
            text: "\uf265"
            onClicked: pageStack.pop();
            topmargin: -20
            leftmargin: -20
            botmargin: -20
            visible: isBack
        }
    }
}
