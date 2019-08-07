import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: loginWindow
    visible: true
    width: 400
    height: 300
    title: qsTr("LogIn")

    Item {
        id: reg_btn
        objectName: qsTr("RegisterButtonObject")
        x: 223
        y: 210
        width: 121
        height: 54

        signal qmlSignalPressed()

        Image {
            id: regButtonUp
            source: "../buttons/buttons_login-1.png"
            anchors.fill: parent
            visible: true
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: regButtonDown
            source: "../buttons/buttons_login-2.png"
            anchors.fill: parent
            visible: regMouseArea.pressed
            fillMode: Image.PreserveAspectFit
        }

        Text {
            id: regText
            x: 0
            y: 0
            text: qsTr("Register")
            verticalAlignment: Text.AlignVCenter
            font.capitalization: Font.MixedCase
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 16
        }

        MouseArea {
            id: regMouseArea
            anchors.fill: parent
            onPressed: {
                reg_btn.qmlSignalPressed()
                InfoObject.status = qsTr("Registration...")
            }
        }
    }

    Item {
        id: login_btn
        objectName: qsTr("LoginButtonObject")
        width: 121
        height: 54
        x: 67
        y: 210

        signal qmlSignalPressed(string login, string pwd)

        Image {
            id: loginButtonUp
            visible: true
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            source: "../buttons/buttons_login-1.png"
        }

        Image {
            id: loginButtonDown
            visible: loginMouseArea.pressed
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            source: "../buttons/buttons_login-2.png"
        }

        Text {
            id: loginText
            x: 0
            y: 0
            width: 121
            text: "Login"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.capitalization: Font.MixedCase
            anchors.fill: parent
            font.pixelSize: 16
        }

        MouseArea {
            id: loginMouseArea
            anchors.fill: parent
            onPressed: {
                login_btn.qmlSignalPressed(login_input.text, pwd_input.text)
                InfoObject.status = qsTr("Loggin in...")
            }
        }
    }

    Rectangle {
        id: login_rect
        x: 140
        y: 98
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
            text: LoginObject.login
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
        x: 140
        y: 149
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
            text: LoginObject.password
            anchors.fill: parent
            opacity: 1
            cursorVisible: false
            clip: false
            font.pixelSize: 15
            horizontalAlignment: Text.AlignHCenter
        }

    }

    Text {
        id: statusText
        x: 15
        y: 20
        text: InfoObject.status
        font.pixelSize: 14
    }

    Text {
        id: versionLabel
        x: 294
        y: 20
        text: qsTr("Version:")
        font.pixelSize: 14
    }

    Text {
        id: versionText
        x: 350
        y: 20
        text: InfoObject.version
        font.pixelSize: 14
    }

}





/*##^## Designer {
    D{i:3;anchors_x:"-31";anchors_y:17}D{i:4;anchors_height:54;anchors_width:120;anchors_x:0;anchors_y:0}
D{i:2;anchors_x:"-148";anchors_y:"-107"}D{i:9;anchors_height:22;anchors_width:107;anchors_x:0;anchors_y:25}
D{i:12;anchors_height:22;anchors_width:107;anchors_x:0;anchors_y:25}
}
 ##^##*/
