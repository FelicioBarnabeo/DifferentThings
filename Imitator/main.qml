import QtQuick 2.3
import QtQuick.Window 2.1
import QtQuick.Controls 1.1



ApplicationWindow {
    visible: true
    width: 800
    height: 800
    title: qsTr("Imitator VSS")


    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

        GroupBox {
            id: config
            x: 9
            y: 50
            width: 700
            height: 700
            visible: true
            title: qsTr("Configuration")

            Label {
                id: label1
                x: 0
                y: 22
                text: qsTr("Скорость передачи (кб/с) мин:")
            }

            Label {
                id: label2
                x: 329
                y: 22
                text: qsTr("макс:")
            }

            TextField {
                id: lowSpeed
                x: 221
                y: 22
                placeholderText: qsTr("")
            }

            TextField {
                id: highSpeed
                x: 373
                y: 21
                placeholderText: qsTr("")
            }

            Label {
                id: label3
                x: 0
                y: 62
                text: qsTr("Общий интервал передачи ( мс ) мин:")
            }

            TextField {
                id: minInterval
                x: 221
                y: 58
                placeholderText: qsTr("")
            }

            Label {
                id: label4
                x: 329
                y: 62
                text: qsTr("макс:")
            }

            TextField {
                id: maxInterval
                x: 373
                y: 58
                placeholderText: qsTr("")
            }

//                ListModel
//                {
//                    id: listMod
//                    ListElement
//                    {
//                        data:"Latitude";
//                        value: 90;
//                        intervalmin:100;
//                        intervalmax:200;
//                    }
//                    ListElement
//                    {
//                        data:"Longitude";
//                        value: 10;
//                        intervalmin:100;
//                        intervalmax:200;
//                    }
//                    ListElement
//                    {
//                        data:"Alteration";
//                        value: 2000;
//                        intervalmin:250;
//                        intervalmax:500;
//                    }
//                    ListElement
//                    {
//                        data:"Distanse to destination";
//                        value: 2500;
//                        intervalmin:500;
//                        intervalmax:1000;
//                    }

//                    ListElement
//                    {
//                        data:"Time to destination";
//                        value: 350;
//                        intervalmin:500;
//                        intervalmax:1000;
//                    }
//                    ListElement
//                    {
//                        data:"Current speed";
//                        value: 890;
//                        intervalmin:100;
//                        intervalmax:200;
//                    }
//                    ListElement
//                    {
//                        data:"Grinvich Time";
//                        value: 100;
//                        intervalmin:125;
//                        intervalmax:500;
//                    }
//                    ListElement
//                    {
//                        data:"Output temperature";
//                        value: -10;
//                        intervalmin:250;
//                        intervalmax:500;
//                    }
//                    ListElement
//                    {
//                        data:"Data";
//                        value: 200;
//                        intervalmin:125;
//                        intervalmax:1000;
//                    }

//                }

                TableView
                {
                    id: vssSettings
                    anchors.rightMargin: 81
                    anchors.bottomMargin: 88
                    anchors.leftMargin: 0
                    anchors.topMargin: 108
                    anchors.fill: parent
                    clip: true
                    model: dataModel
                    TableViewColumn{
                        role:"geoname";
                        title:"Геоданные
                                        ";
                        width:100

                    }
                    TableViewColumn{
                        role:"geovalue";
                        title:"Значение
                                        ";
                        width:100
                        delegate: Item{
                            TextField{
                                anchors.fill: parent
                                text: styleData.value

                            }
                        }
                    }

                    TableViewColumn{
                        role:"sign";
                        title:"Знак";
                        width:100
                        delegate: Item{
                            ComboBox{
                                anchors.fill: parent
                                model: ["Cеверная","Южная"]
                            }
                        }
                    }

                    TableViewColumn{
                        role:"matrixSustain";
                        title:"Матрица состояния";
                        width:150
                        delegate: Item{
                            TextField{
                                anchors.fill: parent
                                text: styleData.value
                            }
                        }
                    }

                    TableViewColumn{
                        role:"parity";
                        title:"Четность";
                        width:100
                        delegate: Item{
                            CheckBox{
                                anchors.fill: parent
                                //text: styleData.value
                            }
                        }
                    }

                    rowDelegate : Rectangle
                    {
                        anchors.fill: parent
                        //selection.clear()
                        //vssSettings.selection.select(styleData.row)
                    }
            }



            Rectangle{
                id: button
                y: 630
                width: 100
                height: 40
                anchors.horizontalCenterOffset: -291
                anchors.horizontalCenter: parent.horizontalCenter
                border
                {
                    color: "black"
                    width: 1
                }
                Text
                {
                    anchors.centerIn: parent
                    text: "Начать передачу"
                }
                MouseArea
                {
                    anchors.fill: parent
                    onClicked:
                    {
                        //index = vssSettings.currentRow
                        //qDebug()<<"Started"
//                        vssSettings.selection.selectAll()
//                        vssSettings.selection.forEach(function(rowIndex)
//                        {console.log(dataModel.get(rowIndex).value)})
                        //console.log(dataModel.)
                        //vssSettings.model.sendDataFromTable(dataModel.get(index).value)
                        dataModel.getName(vssSettings.currentRow);
                    }
                }
            }

            Rectangle{
                id: removerow
                y: 630
                width: 100
                height: 40
                anchors.horizontalCenterOffset: -169
                anchors.horizontalCenter: parent.horizontalCenter
                border
                {
                    color: "black"
                    width: 1
                }
                Text
                {
                    anchors.centerIn: parent
                    text: "Удалить строку"
                }
                MouseArea
                {
                    anchors.fill: parent
                    onClicked: {
                        //ind =
                        //dataModel.remove(vssSettings.currentRow,1)
                        //vssSettings.removeColumn(1)

                    }
                }
            }
    }



}
