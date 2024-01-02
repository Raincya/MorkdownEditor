import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    id: loginWindow
    height: 480
    visible: true
    width: 350

    Rectangle {
        anchors.fill: parent
        color: "#f3f3f3"

        ColumnLayout {
            height: parent.height
            width: parent.width

            Rectangle {
                Layout.alignment: Qt.AlignHCenter
                Layout.preferredHeight: 40
                Layout.preferredWidth: 180
                Layout.topMargin: 20

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

                        onClicked: {
                            sw1.currentIndex = 0;
                        }

                        Image {
                            anchors.centerIn: parent
                            height: 22
                            source: "../../Src/icons/icon-login.png"
                            width: 50
                        }
                    }
                    Button {
                        id: regBtn

                        Layout.alignment: Qt.AlignHCenter
                        Layout.fillHeight: true
                        Layout.preferredWidth: 100
                        checkable: true
                        font.bold: true
                        font.pointSize: 26

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

                        // text: "注册"

                        onClicked: {
                            sw1.currentIndex = 1;
                        }

                        Image {
                            anchors.centerIn: parent
                            height: 22
                            source: "../../Src/icons/icon-reg.png"
                            width: 50
                        }
                    }
                }
            }
            Rectangle {
                Layout.fillHeight: true
                Layout.fillWidth: true

                SwipeView {
                    id: sw1

                    anchors.fill: parent
                    currentIndex: 0
                    interactive: false

                    Rectangle {
                        id: loginPage

                        color: "#f3f3f3"
                        height: 300
                        width: 200

                        // color:"yellow"
                        ColumnLayout {
                            height: parent.height
                            spacing: 0
                            width: parent.width

                            Rectangle {
                                id: loginInput

                                // color:"pink"
                                Layout.alignment: Qt.AlignHCenter
                                color: "#f3f3f3"
                                height: 220
                                radius: 5
                                width: 240

                                ColumnLayout {
                                    anchors.fill: parent

                                    Rectangle {
                                        Layout.alignment: Qt.AlignHCenter
                                        Layout.preferredHeight: 60
                                        Layout.preferredWidth: 240
                                        color: "#f3f3f3"

                                        // color:"red"
                                        RowLayout {
                                            height: parent.height
                                            spacing: 10
                                            width: parent.width

                                            Rectangle {
                                                Layout.leftMargin: 10
                                                color: "#f3f3f3"
                                                height: 30
                                                radius: 5
                                                width: 40

                                                // color:"orange"
                                                Text {
                                                    anchors.right: parent.right
                                                    anchors.verticalCenter: parent.verticalCenter
                                                    text: "用户名"
                                                }
                                            }
                                            Rectangle {
                                                color: "#f3f3f3"
                                                height: 40
                                                width: 160

                                                TextField {
                                                    id: loginUsername

                                                    anchors.verticalCenter: parent.verticalCenter
                                                    font.pointSize: 12
                                                    height: 30
                                                    width: parent.width

                                                    background: Rectangle {
                                                        anchors.fill: parent
                                                        border.width: 2
                                                        radius: 6
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    Rectangle {
                                        Layout.alignment: Qt.AlignHCenter
                                        Layout.preferredHeight: 50
                                        Layout.preferredWidth: 240
                                        color: "#f3f3f3"

                                        RowLayout {
                                            height: parent.height
                                            spacing: 10
                                            width: parent.width

                                            Rectangle {
                                                Layout.leftMargin: 10
                                                color: "#f3f3f3"
                                                height: 30
                                                radius: 5
                                                width: 40

                                                // color:"orange"
                                                Text {
                                                    anchors.right: parent.right
                                                    anchors.verticalCenter: parent.verticalCenter
                                                    text: "密码"
                                                }
                                            }
                                            Rectangle {
                                                color: "#f3f3f3"
                                                height: 40
                                                width: 160

                                                TextField {
                                                    id: loginPassword

                                                    anchors.verticalCenter: parent.verticalCenter
                                                    echoMode: loginPsswordBtn.checked ? TextInput.Password : TextInput.Normal
                                                    font.pointSize: 12
                                                    height: 30
                                                    width: parent.width

                                                    background: Rectangle {
                                                        anchors.fill: parent
                                                        border.width: 2
                                                        radius: 6
                                                    }

                                                    Button {
                                                        id: loginPsswordBtn

                                                        anchors.right: parent.right
                                                        anchors.rightMargin: 3
                                                        anchors.verticalCenter: parent.verticalCenter
                                                        checkable: true
                                                        checked: true
                                                        height: 20
                                                        width: 20

                                                        background: Image {
                                                            anchors.fill: parent
                                                            source: loginPsswordBtn.checked ? "../../Src/icons/icon-showpassword.png" : "../../Src/icons/icon-hidepassword.png"
                                                        }

                                                        onClicked: {
                                                            checked: loginPsswordBtn.checked ? false : true;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }

                                    Rectangle {
                                        Layout.alignment: Qt.AlignHCenter
                                        Layout.preferredHeight: 40
                                        Layout.preferredWidth: 100
                                        color: "#f3f3f3"

                                        RowLayout {
                                            id: loginrow

                                            anchors.fill: parent

                                            Button {
                                                id: submitlogin

                                                Layout.fillHeight: true
                                                checkable: true
                                                font.bold: true
                                                font.pointSize: 14
                                                text: "登录"
                                                width: parent.width

                                                background: Rectangle {
                                                    color: "#32AAE6"
                                                    radius: 6
                                                }

                                                onClicked: //登录功能  ids:   longinusername   longinpassword
                                                {
                                                    // console.log("test")
                                                    // let msg = loginAndReg.login(loginUsername.text, loginPassword.text)
                                                    // console.log(msg)
                                                    // let msgs = msg.split(":");
                                                    // if(msg.indexOf("success") !== -1)
                                                    // {
                                                    //     console.log("success: " + msgs[1])
                                                    // } else
                                                    // {
                                                    //     console.log("fail: " + msgs[1])
                                                    // }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    Rectangle {
                        id: regPage

                        color: "#f3f3f3"

                        ColumnLayout {
                            height: parent.height
                            spacing: 0
                            width: parent.width

                            Rectangle {
                                id: regInput

                                Layout.alignment: Qt.AlignHCenter
                                color: "#f3f3f3"
                                height: 220
                                // color: "pink"
                                radius: 5
                                width: 240

                                ColumnLayout {
                                    anchors.fill: parent

                                    Rectangle {
                                        Layout.alignment: Qt.AlignHCenter
                                        Layout.preferredHeight: 50
                                        Layout.preferredWidth: 240
                                        color: "#f3f3f3"

                                        RowLayout {
                                            height: parent.height
                                            spacing: 10
                                            width: parent.width

                                            Rectangle {
                                                Layout.leftMargin: 10
                                                color: "#f3f3f3"
                                                height: 30
                                                radius: 5
                                                width: 40

                                                // color:"orange"
                                                Text {
                                                    anchors.right: parent.right
                                                    anchors.verticalCenter: parent.verticalCenter
                                                    text: "用户名"
                                                }
                                            }
                                            Rectangle {
                                                color: "#f3f3f3"
                                                height: 40
                                                width: 160

                                                TextField {
                                                    id: regUsername

                                                    anchors.verticalCenter: parent.verticalCenter
                                                    font.pointSize: 12
                                                    height: 30
                                                    width: parent.width

                                                    background: Rectangle {
                                                        anchors.fill: parent
                                                        border.width: 2
                                                        radius: 6
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    Rectangle {
                                        Layout.alignment: Qt.AlignHCenter
                                        Layout.preferredHeight: 50
                                        Layout.preferredWidth: 240
                                        color: "#f3f3f3"

                                        RowLayout {
                                            height: parent.height
                                            spacing: 10
                                            width: parent.width

                                            Rectangle {
                                                Layout.leftMargin: 10
                                                color: "#f3f3f3"
                                                height: 30
                                                radius: 5
                                                width: 40

                                                // color:"orange"
                                                Text {
                                                    anchors.right: parent.right
                                                    anchors.verticalCenter: parent.verticalCenter
                                                    text: "密码"
                                                }
                                            }
                                            Rectangle {
                                                color: "#f3f3f3"
                                                height: 40
                                                width: 160

                                                TextField {
                                                    id: regPassword

                                                    anchors.verticalCenter: parent.verticalCenter
                                                    echoMode: regPsswordBtn.checked ? TextInput.Password : TextInput.Normal
                                                    font.pointSize: 12
                                                    height: 30
                                                    width: parent.width

                                                    background: Rectangle {
                                                        anchors.fill: parent
                                                        border.width: 2
                                                        radius: 6
                                                    }

                                                    Button {
                                                        id: regPsswordBtn

                                                        anchors.right: parent.right
                                                        anchors.rightMargin: 3
                                                        anchors.verticalCenter: parent.verticalCenter
                                                        checkable: true
                                                        checked: true
                                                        height: 20
                                                        width: 20

                                                        background: Image {
                                                            anchors.fill: parent
                                                            source: regPsswordBtn.checked ? "../../Src/icons/icon-showpassword.png" : "../../Src/icons/icon-hidepassword.png"
                                                        }

                                                        onClicked: {
                                                            checked: regPsswordBtn.checked ? false : true;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    Rectangle {
                                        Layout.alignment: Qt.AlignHCenter
                                        Layout.preferredHeight: 50
                                        Layout.preferredWidth: 240
                                        color: "#f3f3f3"

                                        RowLayout {
                                            height: parent.height
                                            spacing: 10
                                            width: parent.width

                                            Rectangle {
                                                Layout.leftMargin: 10
                                                color: "#f3f3f3"
                                                height: 30
                                                radius: 5
                                                width: 40

                                                // color:"orange"
                                                Text {
                                                    anchors.right: parent.right
                                                    anchors.verticalCenter: parent.verticalCenter
                                                    text: "确认密码"
                                                }
                                            }
                                            Rectangle {
                                                color: "#f3f3f3"
                                                height: 40
                                                width: 160

                                                TextField {
                                                    id: regPasswordCheck

                                                    anchors.verticalCenter: parent.verticalCenter
                                                    echoMode: regPsswordCheckBtn.checked ? TextInput.Password : TextInput.Normal
                                                    font.pointSize: 12
                                                    height: 30
                                                    width: parent.width

                                                    background: Rectangle {
                                                        anchors.fill: parent
                                                        border.width: 2
                                                        radius: 6
                                                    }

                                                    Button {
                                                        id: regPsswordCheckBtn

                                                        anchors.right: parent.right
                                                        anchors.rightMargin: 3
                                                        anchors.verticalCenter: parent.verticalCenter
                                                        checkable: true
                                                        checked: true
                                                        height: 20
                                                        width: 20

                                                        background: Image {
                                                            anchors.fill: parent
                                                            source: regPsswordCheckBtn.checked ? "../../Src/icons/icon-showpassword.png" : "../../Src/icons/icon-hidepassword.png"
                                                        }

                                                        onClicked: {
                                                            checked: regPsswordCheckBtn.checked ? false : true;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    Rectangle {
                                        Layout.alignment: Qt.AlignHCenter
                                        Layout.preferredHeight: 40
                                        Layout.preferredWidth: 100
                                        color: "#f3f3f3"

                                        RowLayout {
                                            id: regrow

                                            anchors.fill: parent

                                            Button {
                                                id: submitreg

                                                Layout.fillHeight: true
                                                checkable: true
                                                font.bold: true
                                                font.pointSize: 14
                                                text: "申请注册"
                                                width: parent.width

                                                background: Rectangle {
                                                    color: "#32AAE6"
                                                    radius: 6
                                                }

                                                onClicked: //注册功能  ids: regUsername,regPassword,regPasswordCheck

                                                {
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}