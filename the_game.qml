import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Item {
        id: login_btn
        width: 120
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

        MouseArea {
            id: mouseArea
            anchors.fill: parent
        }

        Connections {
            target: mouseArea
            onPressed: login_btn.clicked()
        }


        signal clicked
        x: 248
        y: 191

    }
}





/*##^## Designer {
    D{i:2;anchors_x:-148;anchors_y:-107}D{i:3;anchors_x:-31;anchors_y:17}
}
 ##^##*/
