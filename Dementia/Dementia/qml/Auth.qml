import QtQuick 2.0
import QtQuick.Window 2.0

Item {
    property alias pwd: _authText.text;
    signal authSuccess();
    signal back();

    anchors.centerIn: parent;
    width: childrenRect.width;
    height: childrenRect.height;

    Text {
        id: _authText;
        anchors.horizontalCenter: _authGrid.horizontalCenter;
        font.family: "Digital-7";
        font.pointSize: SettingsManager.textFontH3;
        color: SettingsManager.fgInactiveColor;
        height: Screen.pixelDensity*10;
        text: "";
    }

    Grid {
        id: _authGrid;
        anchors.top: _authText.bottom;
        anchors.topMargin: Screen.pixelDensity*5;
        columns: 3;
        rows: 4;
        spacing: Screen.pixelDensity*5;

        AuthButton { text: "1"; onButtonClicked: pwd = pwd + data;}
        AuthButton { text: "2"; onButtonClicked: pwd = pwd + data;}
        AuthButton { text: "3"; onButtonClicked: pwd = pwd + data;}

        AuthButton { text: "4"; onButtonClicked: pwd = pwd + data;}
        AuthButton { text: "5"; onButtonClicked: pwd = pwd + data;}
        AuthButton { text: "6"; onButtonClicked: pwd = pwd + data;}

        AuthButton { text: "7"; onButtonClicked: pwd = pwd + data;}
        AuthButton { text: "8"; onButtonClicked: pwd = pwd + data;}
        AuthButton { text: "9"; onButtonClicked: pwd = pwd + data;}

        AuthButton { text: "X"; onButtonClicked: pwd = "";}
        AuthButton { text: "0"; onButtonClicked: pwd = pwd + data;}
        AuthButton {
            text: "V";
            onButtonClicked: if (pwd == SettingsManager.password)
                                 authSuccess();
        }
    }

    AuthButton {
        anchors.top: _authGrid.bottom;
        anchors.topMargin: Screen.pixelDensity*5;
        anchors.left: _authGrid.left;
        anchors.right: _authGrid.right;
        text: qsTr("Назад") + SettingsManager.tsStr;
        onButtonClicked: back();
    }
}
