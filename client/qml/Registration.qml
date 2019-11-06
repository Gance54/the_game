import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5


Window {
    visible: true               //true for developing. False for release
    width: 500
    height: 400
    title: qsTr("Registration")

    TextField {
        id: login
        x: 150
        y: 51
        placeholderText: "Your login"
    }

    TextField {
        id: pwd
        x: 150
        y: 113
        placeholderText: "Your password"
    }

    TextField {
        id: pwd_rpt
        x: 150
        y: 174
        placeholderText: "Repeat password"
    }

    TextField {
        id: email
        x: 150
        y: 236
        placeholderText: "Your email"
    }

    ComboBox {
        visible: false
        id: sec_quest
        x: 150
        y: 277
        width: 200
        height: 40
        displayText: "Security question"
        wheelEnabled: false
        enabled: true
        hoverEnabled: true
        focusPolicy: Qt.StrongFocus
        font.pointSize: 10
        clip: false
        font.capitalization: Font.MixedCase
        flat: false
        editable: false
        textRole: "Security question"
        currentIndex: 0
        model: [ "Banana", "Apple", "Coconut" ]
        delegate: ItemDelegate {
            text: modelData
            width: parent.width
            onClicked:
                console.log("clicked:", modelData)
        }

    }

    Button {
        id: register
        objectName: qsTr("Register")
        x: 267
        y: 306
        text: qsTr("Register")
        font.family: "Verdana"
        signal registerMe()

        onClicked: {
            RegistrationObject.login = login.text
            RegistrationObject.password = pwd.text
            RegistrationObject.password_rpt = pwd_rpt.text
            RegistrationObject.email = email.text
            register.registerMe()
        }
    }

    Button {
        id: cancel
        x: 127
        y: 306
        text: qsTr("Cancel")
    }

    Text {
        id: status
        x: 13
        y: 10
        text: statusObject.status
        font.pixelSize: 12
    }

    TextArea {
        id: err_login
        x: 160
        y: 90
        width: 181
        height: 17
        text: qsTr("test")
        leftPadding: 4
        color: "#E4000F"
        topPadding: 3
        bottomPadding: 0
        visible: true
        font.pointSize: 8
    }

}





























/*##^##
Designer {
    D{i:3;anchors_height:20;anchors_width:80;anchors_x:2}
}
##^##*/
