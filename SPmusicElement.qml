import QtQuick 2.0

Rectangle {
    id:musicElement
    color: "lightgray"
    border.color: "gray"
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
            console.log(parent.color)
            player.playMusic(playIndex,vol.value)
            if(parent.color=="#ffff00"){
                parent.color="lightgray"
            }else{
                parent.color="yellow"
            }
        }
    }
}
