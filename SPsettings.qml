import QtQuick 2.0
import "qrc:/qml"

Rectangle {
    color:"lightblue"
    Text{
        anchors.horizontalCenter: spcp.horizontalCenter
        anchors.bottom: spcp.top
        anchors.bottomMargin: 50
        text:"填写音乐目录，单击本窗口取消"
    }

    SPchoosePath{
        id:spcp
        z:1
        anchors.centerIn: parent
        width:parent.width/4*3
        height:parent.height/4*3
    }

    MouseArea{
        z:0
        anchors.fill: parent
        onClicked: {
            settings.visible=false
        }
    }
}
