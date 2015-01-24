import QtQuick 2.0

Rectangle {
    color:"red"
    Rectangle{
        width:parent.width/3*2
        height:parent.width/10
        anchors.centerIn: parent
        color:"lightgray"
    }

    TextInput{
        id:ipt
        width:parent.width/3*2
        height:parent.width/10
        font.pointSize: 9
        anchors.centerIn: parent
        text:"D:/Music"
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            player.setMusicDir(ipt.text)
            settings.visible=false
            console.log(ipt.text)
        }
    }
}
