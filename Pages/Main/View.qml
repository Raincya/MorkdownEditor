import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item{
    width: 1080
    height: 607.5
    visible:true
    Rectangle{
        anchors.fill:parent
        id:mainRec
        color:"yellow"
        ColumnLayout{
            anchors.fill:parent
            spacing: 0
            Rectangle{//顶部菜单
                Layout.alignment: Qt.AlignTop
                Layout.fillWidth:true
                height:15
                color: "pink"
            }
            RowLayout{
                height: parent.height-15
                width: parent.width
                spacing: 0
                Rectangle{
                    id: sideMenu
                    Layout.fillHeight:true
                    width: 50
                    color: "#1c1c1c"
                    Button{
                        width: parent.width-10
                        height: width
                        anchors.horizontalCenter:parent.horizontalCenter
                        anchors.top:parent.top
                        anchors.topMargin:10
                        background:Rectangle{
                            anchors.fill:parent
                            opacity:0.0
                        }
                        icon.source:"../../Src/icons/icon-dirlist.png"
                        // icon.height:height
                        // icon.width:width
                        icon.color:"#1296db"
                        // hoverEnabled:false
                        onClicked:{
                            sideBar.folded = !sideBar.folded
                            // sideBar.folded?editingField.width=editingField.width+150:editingField.width=editingField.width-150
                        }
                    }
                }


                Rectangle{//Dir list
                    id: sideBar
                    Layout.fillHeight:true
                    Layout.preferredWidth: folded?0:150
                    color:"#444444"
                    property bool folded: true
                    clip:true
                    ColumnLayout{
                        anchors.fill: parent
                    }
                }


                Rectangle{//Editing Field
                    id: editingField
                    Layout.fillHeight:true
                    Layout.fillWidth:true
                    RowLayout{
                        id: idxrow
                        anchors.fill:parent
                        spacing:0
                        ScrollView{
                            id: lineIndex
                            Layout.fillHeight:true
                            contentHeight:tascro.contentHeight
                            width:60
                            background: Rectangle{
                                anchors.fill:parent
                                color:"grey"
                            }
                            ScrollBar.vertical.policy: ScrollBar.AlwaysOff
                            ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
                            ScrollBar.vertical.position: tascro.ScrollBar.vertical.position
                            MouseArea{
                                anchors.fill:parent
                            }
                            Repeater{
                                id: rep
                                model:textArea.lineCount
                                Rectangle{
                                    id:lineBolck
                                    width:parent.width
                                    height:textArea.contentHeight/textArea.lineCount
                                    color:"grey"
                                    y:index*height
                                    Text{
                                        anchors.right:parent.right
                                        text:index+1+" | "
                                        font.pointSize:12
                                    }
                                }
                            }
                        }
                        ScrollView{
                            id: tascro
                            Layout.fillHeight:true
                            Layout.fillWidth:true
                            contentHeight:textArea.contentHeight+2*(textArea.contentHeight/textArea.lineCount)
                            TextArea{
                                id: textArea
                                width:parent.width
                                height:parent.height
                                font.pointSize:12

                                background: Rectangle{
                                    anchors.fill:parent
                                    color:"#d5d5d5"
                                }
                            }

                        }
                    }
                }


                Rectangle{//Preview Field
                    id: preViewField
                    Layout.fillHeight: true
                    Layout.preferredWidth:(mainRec.width-sideMenu.width-sideBar.width)*0.4
                    color:"purple"
                }
            }
        }
    }
}