import QtQuick 2.0

Rectangle {
    id:musicElement
    color: "red"
    border.color: "lightgray"
    //anchors.fill: parent
    width:parent.width
    height:80
    Text{
        text:musicName
        font.family: "微软雅黑"
        verticalAlignment: Text.AlignVCenter
        font.pointSize: 15
    }
    MouseArea{
        anchors.fill: parent
        onClicked: {
            console.log(vol.value)
            player.playMusic(fileUrl,vol.value)
        }
    }
}
