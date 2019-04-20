import QtQuick 2.2
import QtQuick.Window 2.1

Window {
    visible: true;
    color: "black";
    width: 800;
    height: 680;
    maximumHeight: height
    maximumWidth: width;

    function currentScale(val) {
        if (Math.abs(val)<0.038) return(val*24);
        if (Math.abs(val)<0.052) return(val*27);
        if (Math.abs(val)<0.065) return(val*31);
        if (Math.abs(val)<0.078) return(val*32);
        if (Math.abs(val)<0.091) return(val*33);
        if (Math.abs(val)<0.118) return(val*34);
        return(val*35);
    }

    FontLoader {
        id: webFont;
        source: "qrc:///Exo2.0-Medium.otf"
    }


    ListView {
        id: deviceList;
        width: 80;
        height: childrenRect.height;
        anchors.verticalCenter: parent.verticalCenter;
        anchors.right: parent.right;
        anchors.rightMargin: 5;
        spacing: 5
        model: Devices
        delegate: Rectangle {
            id: wrapper;
            width: 80;
            height: 50;
            color:"#333333"
            border.color: "#FF64DCFC";
            border.width: ListView.isCurrentItem ? "1" : "0"
            Text {
                color: wrapper.ListView.isCurrentItem ? "#FF64DCFC" : "grey"
                font.pixelSize: 16;
                text: model.modelData.address
                anchors.centerIn: parent
                font.family: webFont.name
            }
            MouseArea {
                onClicked: {deviceList.currentIndex = index}
                anchors.fill: parent;
            }
        }
        focus: true
    }

    Rectangle {
        color: "#FF64DCFC";
        width:  1;
        height: parent.height - 40;
        anchors.verticalCenter: parent.verticalCenter;
        anchors.right: deviceList.left;
        anchors.rightMargin: 20;
    }

    Column {
        id: sensorPanel
        spacing: 20
        anchors.verticalCenter: parent.verticalCenter;
        anchors.left: parent.left;
        anchors.leftMargin: 20;

        Meter {
            title: "Напряжение"
            value: deviceList.model[deviceList.currentIndex].outputVoltage;
            ext: "В"; min: 0; max: 1.65; type: false;
            fontFamily: webFont.name;
        }

        Rectangle {
            color: "#FF64DCFC";
            width:  parent.width*2/3;
            anchors.horizontalCenter: parent.horizontalCenter;
            height: 1
        }

        Meter {
            title: "Выходной ток"
            value: deviceList.model[deviceList.currentIndex].outputCurrent;
            ext: "А"; min: 0; max: 3.3; type: true;
            fontFamily: webFont.name;
        }

        Rectangle {
            color: "#FF64DCFC";
            width:  parent.width*2/3;
            anchors.horizontalCenter: parent.horizontalCenter;
            height: 1
        }

        Meter {
            title: "Температура"
            value: deviceList.model[deviceList.currentIndex].temperature;
            ext: "\u2103"; min: 0; max: 3.3; type: false;
            fontFamily: webFont.name;
        }
    }

    Rectangle {
        color: "#FF64DCFC";
        width:  1;
        height: parent.height - 40;
        anchors.verticalCenter: parent.verticalCenter;
        anchors.left: sensorPanel.right;
        anchors.leftMargin: 20;
    }

    Grid {
        id: paramtable;
        columns: 2
        anchors.verticalCenter: parent.verticalCenter;
        anchors.topMargin: 40;
        columnSpacing: 40;
        rowSpacing: 5;
        anchors.left: sensorPanel.right;
        anchors.leftMargin: 60;

        Text {
            text: "Адрес:"
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name
        }

        Text {
            text: deviceList.model[deviceList.currentIndex].address;
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name
        }

        Text {
            text: "Состояние:"
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name
        }

        Text {
            text: deviceList.model[deviceList.currentIndex].state;
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name
        }


        Text {
            text: "Состояние(UI):"
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name
        }

        Text {
            text: deviceList.model[deviceList.currentIndex].stateUI;
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name
        }

        Rectangle {
            color: "black";
            width:  1
            height: 10
        }

        Rectangle {
            color: "black";
            width:  1
            height: 10
        }

        Text {
            text: "Напряжение:"
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name
        }

        Text {
            text: deviceList.model[deviceList.currentIndex].outputVoltage.toFixed(4);
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name
        }


        Text {
            text: "Выходной ток:";
            font.pixelSize: 16;
            color: currentValue.color;
            font.family:  webFont.name
        }

        Text {
            id: currentValue;
            text: currentScale(deviceList.model[deviceList.currentIndex].outputCurrent).toFixed(4);
            font.pixelSize: 16;
            color: (text.charAt(0) == "-") ? "red":"grey";
            font.family:  webFont.name
        }

        Text {
            text: "Температура:";
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name
        }

        Text {
            text: deviceList.model[deviceList.currentIndex].temperature.toFixed(4);
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name
        }

        Rectangle {
            color: "black";
            width:  1
            height: 10
        }

        Rectangle {
            color: "black";
            width:  1
            height: 10
        }

        Text {
            text: "Напряжение (Manifold):"
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name
        }

        Text {
            text: deviceList.model[deviceList.currentIndex].voltageManifold.toFixed(4);
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name
        }


        Text {
            text: "Ток (Manifold):";
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name
        }

        Text {
            text: deviceList.model[deviceList.currentIndex].currentManifold.toFixed(4);
            font.pixelSize: 16;
            color: (text.charAt(0) == "-") ? "red":"grey";
            font.family:  webFont.name
        }

        Text {
            text: "Счетчик направления тока:";
            font.pixelSize: 16;
            color: currentValue.color;
            font.family:  webFont.name
        }

        Text {
            text: deviceList.model[deviceList.currentIndex].currentDirection.toFixed(4);
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name
        }

        Text {
            text: "Корректор ШИМа (Delta Duty):";
            font.pixelSize: 16;
            color: "grey";
            font.family:  webFont.name
        }

        Text {
            text: deviceList.model[deviceList.currentIndex].deltaDuty.toFixed(4);
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name
        }

        Rectangle {
            color: "black";
            width:  1
            height: 10
        }

        Rectangle {
            color: "black";
            width:  1
            height: 10
        }

        Text {
            text: "Замеры (Напряжение):";
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name
        }

        Text {
            text: deviceList.model[deviceList.currentIndex].voltageSamplesCount;
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name
        }

        Text {
            text: "Замеры (Выходной ток):";
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name
        }

        Text {
            text: deviceList.model[deviceList.currentIndex].currentSamplesCount;
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name
        }

        Text {
            text: "Замеры (Температура):";
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name
        }

        Text {
            text: deviceList.model[deviceList.currentIndex].temperatureSamplesCount;
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name
        }

        Rectangle {
            color: "black";
            width:  1
            height: 10
        }

        Rectangle {
            color: "black";
            width:  1
            height: 10
        }

        Text {
            text: "Напряжение (Raw):";
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name
        }

        Text {
            text: deviceList.model[deviceList.currentIndex].rawVoltage;
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name
        }

        Text {
            text: "Выходной ток (Raw):";
            font.pixelSize: 16;
            color: currentValue.color;
            font.family:  webFont.name
        }

        Text {
            text: deviceList.model[deviceList.currentIndex].rawCurrent;
            font.pixelSize: 16;
            color: currentValue.color;
            font.family:  webFont.name
        }

        Text {
            text: "Температура (Raw):";
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name
        }

        Text {
            text: deviceList.model[deviceList.currentIndex].rawTemperature;
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name
        }

        Text {
            text: "Напряжение (Manifold) (Raw):";
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name
        }

        Text {
            text: deviceList.model[deviceList.currentIndex].rawVoltageManifold;
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name

        }

        Text {
            text: "Ток (Manifold) (Raw):";
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name
        }

        Text {
            text: deviceList.model[deviceList.currentIndex].rawCurrentManifold;
            font.pixelSize: 16;
            color: "grey"
            font.family:  webFont.name
        }

        Text {
            text: "Счетчик направ. тока (Raw):";
            font.pixelSize: 16;
            color: currentValue.color;
            font.family:  webFont.name
        }

        Text {
            text: deviceList.model[deviceList.currentIndex].rawCurrentDirection;
            font.pixelSize: 16;
            color: currentValue.color;
            font.family:  webFont.name
        }
    }

//    Text {
//        text: deviceList.model[deviceList.currentIndex].rawData;
//        font.pixelSize: 16;
//        color: "white"
//        font.family:  webFont.name
//        anchors.horizontalCenter: parent.horizontalCenter;
//        anchors.bottom: parent.bottom;
//        anchors.bottomMargin: 10;
//    }
}
