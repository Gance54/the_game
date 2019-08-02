import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: loginWindow
    visible: true
    width: 320
    height: 240
    title: qsTr("LogIn")

    Item {
        id: login_btn
        width: 121
        height: 54

        Image {
            id: buttonUp
            x: -148
            y: -107
            visible: true
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            source: "buttons_login-1.png"
        }

        Image {
            id: buttonDown
            visible: mouseArea.pressed
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            source: "buttons_login-2.png"
        }

        Text {
            id: element
            x: 0
            y: 0
            text: qsTr("Log In")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.capitalization: Font.AllUppercase
            anchors.fill: parent
            font.pixelSize: 16
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
        }

        Connections {
            target: mouseArea
            onPressed: login_btn.clicked()
        }




        signal clicked
        x: 100
        y: 150

    }

    Rectangle {
        id: login_rect
        x: 100
        y: 32
        width: 120
        height: 25
        color: "#fefad3"
        radius: 5
        border.width: 1

        Text {
            id: login_label
            x: -58
            y: 6
            width: 44
            height: 14
            text: qsTr("Login")
            font.pixelSize: 12
        }

        TextInput {
            id: login_input
            text: qsTr("")
            anchors.bottomMargin: 0
            anchors.fill: parent
            clip: false
            opacity: 1
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 15
            cursorVisible: false
        }

    }

    Rectangle {
        id: pwd_rect
        x: 100
        y: 83
        width: 120
        height: 25
        color: "#fefad3"
        radius: 5
        border.width: 1

        Text {
            id: pwd_label
            x: -60
            y: 8
            width: 49
            height: 14
            text: qsTr("Password")
            font.pixelSize: 12
        }

        TextInput {
            id: pwd_input
            text: qsTr("")
            anchors.fill: parent
            opacity: 1
            cursorVisible: false
            clip: false
            font.pixelSize: 15
            horizontalAlignment: Text.AlignHCenter
        }

    }


}



















/*##^## Designer {
    D{i:2;anchors_x:"-148";anchors_y:"-107"}D{i:3;anchors_x:"-31";anchors_y:17}D{i:4;anchors_height:54;anchors_width:120;anchors_x:0;anchors_y:0}
D{i:9;anchors_height:22;anchors_width:107;anchors_x:0;anchors_y:25}D{i:12;anchors_height:22;anchors_width:107;anchors_x:0;anchors_y:25}
}
 ##^##*/
