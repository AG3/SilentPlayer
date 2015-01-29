import QtQuick 2.0
import QtQuick.Controls 1.2
import "qrc:/qml"

Item {
    ListView{
        width:parent.width
        height:parent.height-parent.height/9-parent.height/80

        model:playList
        delegate: SPmusicElement{}
    }

    ProgressBar{
        objectName: "progressBar"
        id:playProgress
        height:parent.height/80
        width:parent.width
        anchors.bottom: vol.top
        maximumValue: 100
        value:0
    }

    Slider{
        z:1
        id:vol
        height:parent.height/9
        anchors.left: forward.right
        width:parent.width-(parent.height/9)*4
        y:parent.height/9*8
        maximumValue: 100
        minimumValue: 0
        value:100
        stepSize: 1
        onValueChanged: {
            player.changeVolume(value)
        }

    }
    Rectangle{
        height:parent.height/9
        width:parent.width-parent.height/9
        y:parent.height/9*8
        color:"white"
        z:0
    }

    Rectangle{
        id:back
        height:parent.height/9
        width:parent.height/9
        anchors.bottom: parent.bottom
        MouseArea{
            anchors.fill: parent
            onClicked: {
                player.perMusic()
            }
            onPressed: {
                parent.opacity=0.6
            }
            onReleased: {
                parent.opacity=1
            }
        }
        Image {
            anchors.centerIn: parent
            width: parent.width*0.8
            height:parent.height*0.8
            source: "qrc:/icon/rewind.png"
        }
    }
    Rectangle{
        id:playpause
        height:parent.height/9
        width:parent.height/9
        anchors.left:back.right
        anchors.bottom: parent.bottom
        MouseArea{
            anchors.fill: parent
            onClicked: {
                player.playMusic(-1,vol.value)
                if(img.source=="qrc:/icon/play.png")
                    img.source="qrc:/icon/pause.png"
                else
                    img.source="qrc:/icon/play.png"
            }
            onPressed: {
                parent.opacity=0.6
            }
            onReleased: {
                parent.opacity=1
            }
        }
        Image {
            id:img
            anchors.centerIn: parent
            width: parent.width*0.8
            height:parent.height*0.8
            source: "qrc:/icon/play.png"
        }
    }
    Rectangle{
        id:forward
        height:parent.height/9
        width:parent.height/9
        anchors.left: playpause.right
        anchors.bottom: parent.bottom
        MouseArea{
            anchors.fill: parent
            onClicked: {
                player.nextMusic()
            }
            onPressed: {
                parent.opacity=0.6
            }
            onReleased: {
                parent.opacity=1
            }
        }
        Image {
            anchors.centerIn: parent
            width: parent.width*0.8
            height:parent.height*0.8
            source: "qrc:/icon/forward.png"
        }
    }

    SPsettings{
        id:settings
        visible: false
        anchors.centerIn: parent
        width: parent.width/4*3
        height: parent.height/4*3
    }

    Rectangle{
        height:parent.height/9
        width:parent.height/9
        y:parent.height/9*8
        x:parent.width-parent.height/9
        MouseArea{
            anchors.fill: parent
            onClicked: {
                settings.visible=!settings.visible
            }
            onPressed: {
                parent.opacity=0.6
            }
            onReleased: {
                parent.opacity=1
            }
        }
        Image {
            anchors.centerIn: parent
            width: parent.width*0.8
            height:parent.height*0.8
            source: "qrc:/icon/settings.png"
        }
    }
}
