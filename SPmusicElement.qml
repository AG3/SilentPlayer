import QtQuick 2.0

Rectangle {
    id:musicElement
    color: "lightgray"
    border.color: "gray"
    width:parent.width
    height:80
    Text{
        text:musicName
        font.family: "微软雅黑"
        verticalAlignment: Text.AlignVCenter
        font.pointSize: 15
    }
    MouseArea{
        hoverEnabled: true
        anchors.fill: parent
        onClicked: {
            player.playMusic(playIndex,vol.value)
        }
        onPressed: {
            musicElement.color="gray"
        }
        onReleased: {
            musicElement.color="lightgray"
        }
        onExited: {
            musicElement.color="lightgray"
        }
    }
}
