import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

Window {
    id: loginWindow
    visible: true
    width: 400
    height: 300
    title: qsTr("Login")

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
                reg_btn.qmlSignalPressed()    //mb delete?
                InfoObject.status = qsTr("Registration...")
                //reg_win.setVisible(true)
                /*
                var regComponent = Qt.createComponent("Registration.qml");
                if (regComponent.status == Component.Ready) {
                    var regWindow = regComponent.createObject(this);
                    regWindow.show()
                } else if (regComponent.status == Component.Error) {
                    console.log("Error loading Registration window:", regComponent.errorString());
                }*/
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
            objectName: qsTr("test")
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
                login_btn.qmlSignalPressed(input_login.text, input_pwd.text)
                InfoObject.status = qsTr("Loggin in...")
            }
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

    TextField {
        id: input_login
        x: 94
        y: 74
        text: qsTr("")
        placeholderText: "Your login"
    }

    TextField {
        id: input_pwd
        x: 94
        y: 140
        text: qsTr("")
        placeholderText: "Your password"
    }



}





/*##^##
Designer {
    D{i:2;anchors_x:"-148";anchors_y:"-107"}D{i:3;anchors_x:"-31";anchors_y:17}D{i:4;anchors_height:54;anchors_width:120;anchors_x:0;anchors_y:0}
D{i:9;anchors_height:22;anchors_width:107;anchors_x:0;anchors_y:25}
}
##^##*/
