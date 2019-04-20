import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import "."

Window {
    id: window
    visible: true;
    //width: Screen.pixelDensity*70*1.2;
    //height: Screen.pixelDensity*55*1.2;
    width: Screen.desktopAvailableWidth
    height: Screen.desktopAvailableHeight

//    width: Screen.pixelDensity*70;
//    height: Screen.pixelDensity*52;
    color: Style.bgcolor
    flags: Qt.FramelessWindowHint
    property int choosenZone: Settings.currentZone;
    Item{
        id: root
        width: Screen.desktopAvailableWidth
        height: Screen.desktopAvailableHeight
        //width: Screen.pixelDensity*70*1.2;
        //height: Screen.pixelDensity*55*1.2;
        FontLoader{id:cons; source: "qrc:/font/ionicons.ttf"}
        FontLoader{id:dejavuFont; source:"qrc:/font/DejaVuSans.ttf"}

        StackView{
            id: pageStack
            anchors.fill: parent
        }

//        Component{
//            id : mainView
//            BaseMenu{
//                anchors.fill: parent
//            }
//        }

        Component.onCompleted: {
            pageStack.initialItem
            console.log("WIDTH = ", window.width, " Height = ", window.height)
            console.log("Screen pixe density = ", Screen.pixelDensity)
            console.log("screen.width = ",Screen.width, "screen.height = ",Screen.height)
            pageStack.push(Qt.resolvedUrl("BaseMenu.qml"))
        }
    }

}
