import QtQuick 2.0

Rectangle {
    color:"red"
    Rectangle{
        z:1
        width:parent.width/3*2
        height:parent.width/10
        anchors.centerIn: parent
        color:"lightgray"
        MouseArea{
            z:2
            anchors.fill: parent
        }
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
    }


    MouseArea{
        z:0
        anchors.fill: parent
        onClicked: {
            player.setMusicDir(ipt.text)
            settings.visible=false
            console.log(ipt.text)
        }
    }
}
