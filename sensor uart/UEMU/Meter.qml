import QtQuick 2.0

Rectangle {
    id: meter
    property bool type: false;
    property real value: 0;
    property string ext: "I"
    property real max: 0;
    property real min: 0;
    property string title: "Input Voltage"
    property string fontFamily: "courier"

    width: back.width;
    height: back.height;
    color: "transparent";
    Image {
        id: back;
        source: "qrc:///images/temp.png";
        anchors.bottom: parent.bottom
    }

    Image {
        id: arrow;
        source: "qrc:///images/arrow.png"
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 56;
        transform: Rotation {
            origin.x: arrow.width/2;
            origin.y: arrow.height;
            axis { x: 0; y: 0; z: 1 }
            angle: {
                if (Math.abs(value)<=min) return (-114);
                if (Math.abs(value)>=max) return (114);
                var mid = (max-min)/2;
                return((114/mid*(Math.abs(value)-(max/2+min/2))).toFixed(4));
            }
            Behavior on angle {
                SpringAnimation { spring: 2; damping: 0.2; modulus: 360 }
            }
        }
    }

    Text {
        text: value.toFixed(4) + " " + ext;
        color: (type && value<0) ? "red" : "gray";
        font.pixelSize: 14;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 5;
        font.family: fontFamily
    }

}
