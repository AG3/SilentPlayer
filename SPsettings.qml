import QtQuick 2.0

Rectangle {
    color:"lightblue"
    /*Rectangle{
        z:1
        width:parent.width/3*2
        height:parent.width/10
        anchors.centerIn: parent
        color:"lightgray"
        MouseArea{
            z:2
            anchors.fill: parent
        }
    }*/

    Text{
        anchors.horizontalCenter: ipt.horizontalCenter
        anchors.bottom: ipt.top
        anchors.bottomMargin: 50
        text:"请填写音乐目录，单击本窗口为确定"
    }

    TextInput{
        z:3
        id:ipt
        readOnly: false
        selectByMouse: true
        width:parent.width/3*2
        height:parent.width/10
        font.pointSize: 15
        anchors.centerIn: parent
        text:"D:/Music"
        font.family: "微软雅黑"
        horizontalAlignment: Text.AlignHCenter
    }


    MouseArea{
        z:0
        anchors.fill: parent
        onClicked: {
            player.setMusicDir(ipt.text)
            settings.visible=false
        }
    }
}
