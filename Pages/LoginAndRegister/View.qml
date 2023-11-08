import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Templates

Item {
    height: 600
    width: 400

    ColumnLayout {
        height: parent.height
        width: parent.width

        Rectangle {
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredHeight: 40
            Layout.preferredWidth: 180

            ButtonGroup {
                buttons: rows.children
            }
            RowLayout {
                id: rows

                anchors.fill: parent
                spacing: 0

                Button {
                    id: loginBtn

                    Layout.fillHeight: true
                    Layout.preferredWidth: 100
                    checkable: true
                    checked: true
                    font.bold: true
                    font.pointSize: 26
                    text: "登录"

                    Image {
                        anchors.centerIn: parent
                        width: 50
                        height: 22
                        source: "../../Src/icons/icon-login.png"
                    }

                    background: Rectangle {
                        color: loginBtn.checked ? "#32AAE6" : "#205068"
                        radius: 6

                        Rectangle {
                            id: rightRect

                            anchors.right: parent.right
                            color: loginBtn.checked ? "#32AAE6" : "#205068"
                            height: parent.height
                            width: 10
                        }
                    }
                }
                Button {
                    id: regBtn

                    Layout.fillHeight: true
                    Layout.preferredWidth: 100
                    checkable: true
                    font.bold: true
                    font.pointSize: 26
                    text: "注册"

                    Image {
                        anchors.centerIn: parent
                        width: 50
                        height: 22
                        source: "../../Src/icons/icon-reg.png"
                    }

                    background: Rectangle {
                        color: regBtn.checked ? "#32AAE6" : "#205068"
                        radius: 6

                        Rectangle {
                            id: leftRect

                            anchors.left: parent.left
                            color: regBtn.checked ? "#32AAE6" : "#205068"
                            height: parent.height
                            width: 10
                        }
                    }
                }
            }
        }

        Rectangle {
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredHeight: 220
            Layout.preferredWidth: 200

            SwipeView {
                id: loginOrReg

                x: 0
                y: 0

                Rectangle {

                }

                Rectangle {

                }
            }
        }
    }
}