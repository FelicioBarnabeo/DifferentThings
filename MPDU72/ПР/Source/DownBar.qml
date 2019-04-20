import QtQuick 2.0
import QtQuick.Window 2.0
import "."

Item {
    id: root
    height: Screen.pixelDensity*7
    anchors.left: parent.left
    anchors.right: parent.right
    anchors.bottom: parent.bottom
    property bool isHome: true
    property bool isBack: true
    signal key();
    Rectangle{
        anchors.fill: root
        color: Style.barColor

//        Row{
//            spacing: (root.width - 2*Screen.pixelDensity*14)
//            anchors.centerIn: parent
            IconButton{
                id: home
                fontsize: Style.fontSizeH3
                anchors.left: parent.left
                anchors.leftMargin: Screen.pixelDensity*1
                anchors.verticalCenter: parent.verticalCenter
                height: Screen.pixelDensity*5.6;
                width: Screen.pixelDensity*13;
                text: "\uf38f"
                onClicked: pageStack.pop(null)
                topmargin: -15
                rightmargin: -15
                visible: isHome
            }

            IconButton{
                id: back
                fontsize: Style.fontSizeH3
                anchors.right: parent.right
                anchors.rightMargin: Screen.pixelDensity*1
                anchors.verticalCenter: parent.verticalCenter
                height: Screen.pixelDensity*5.6;
                width: Screen.pixelDensity*13;
                text: "\uf265"
                onClicked: {key(); pageStack.pop();}
                topmargin: -15
                leftmargin: -15
                visible: isBack

            }
    }
}
