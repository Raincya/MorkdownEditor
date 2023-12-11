import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    height: 600
    visible: true
    width: 1080

    Rectangle {
        id: mainRec
        anchors.fill: parent
        color: "yellow"

        ColumnLayout {
            anchors.fill: parent
            spacing: 0

            Rectangle {
                //顶部菜单
                Layout.alignment: Qt.AlignTop
                Layout.fillWidth: true
                color: "pink"
                height: 15
            }
            RowLayout {
                height: parent.height - 15
                spacing: 0
                width: parent.width

                Rectangle {
                    id: sideMenu
                    Layout.fillHeight: true
                    color: "#1c1c1c"
                    width: 47

                    Button {
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.top: parent.top
                        anchors.topMargin: 10
                        height: width
                        // icon.height:height
                        // icon.width:width
                        icon.color: "#1296db"
                        icon.source: "../../Src/icons/icon-dirlist.png"
                        width: parent.width - 10

                        // hoverEnabled:false
                        onClicked: {
                            sideBar.folded = !sideBar.folded;
                            // sideBar.folded?editingField.width=editingField.width+150:editingField.width=editingField.width-150
                        }

                        background: Rectangle {
                            anchors.fill: parent
                            opacity: 0.0
                        }
                    }
                }
                Rectangle {
                    //Dir list
                    id: sideBar
                    property bool folded: true

                    Layout.fillHeight: true
                    Layout.preferredWidth: folded ? 0 : 180
                    clip: true
                    color: "#E0FFFF"

                    ColumnLayout {
                        anchors.fill: parent
                    }
                }
                Rectangle {
                    //Editing Field
                    id: editingField
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    RowLayout {
                        id: idxrow
                        anchors.fill: parent
                        spacing: 0

                        ScrollView {
                            id: lineIndex
                            Layout.fillHeight: true
                            ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
                            ScrollBar.vertical.policy: ScrollBar.AlwaysOff
                            ScrollBar.vertical.position: tascro.ScrollBar.vertical.position
                            contentHeight: tascro.contentHeight
                            width: 38

                            MouseArea {
                                anchors.fill: parent
                            }
                            Repeater {
                                id: rep
                                model: textArea.lineCount

                                Rectangle {
                                    id: lineBolck
                                    color: "#FFE4C4"
                                    height: textArea.contentHeight / textArea.lineCount
                                    width: parent.width
                                    y: index * height

                                    Text {
                                        anchors.right: parent.right
                                        font.pointSize: 12
                                        text: index + 1 + " | "
                                    }
                                }
                            }

                            background: Rectangle {
                                anchors.fill: parent
                                color: "#CDBA96"
                            }
                        }
                        ScrollView {
                            id: tascro
                            Layout.fillHeight: true
                            Layout.fillWidth: true
                            contentHeight: textArea.contentHeight + 2 * (textArea.contentHeight / textArea.lineCount)

                            TextArea {
                                id: textArea
                                font.pointSize: 12
                                height: parent.height
                                width: parent.width
                                font.family: "Microsoft YaHei"
                                text: "测试"

                                background: Rectangle {
                                    anchors.fill: parent
                                    color: "#F5FFFA"
                                }

                                Keys.onReturnPressed: {
                                    console.log("test")
                                    textArea.text += '\n'
                                    textArea.cursorPosition = textArea.text.length

                                    htmlDisplay.text = main.toHtml(textArea.text)
                                }
                            }
                        }
                    }
                }
                Rectangle {
                    //Preview Field
                    id: preViewField
                    Layout.fillHeight: true
                    Layout.preferredWidth: (mainRec.width - sideMenu.width - sideBar.width) * 0.5
                    color: "#EEE9E9"

                    TextArea {
                        id: htmlDisplay
                        anchors.fill: parent
                        font.pixelSize: 14
                        readOnly: true

                        // 设置HTML内容
                        text: ""
                        textFormat: TextEdit.RichText
                        wrapMode: TextEdit.WordWrap
                    }
                }
            }
        }
    }
}