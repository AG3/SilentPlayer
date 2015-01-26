import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.1
import "qrc:/qml"

Item {
    height:800
    width:720

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
        id:vol
        height:parent.height/9
        width:parent.width-parent.height/9
        y:parent.height/9*8
        maximumValue: 100
        minimumValue: 0
        stepSize: 1
        onValueChanged: {
            player.changeVolume(value)
        }
    }

    SPsettings{
        id:settings
        visible: false
        anchors.centerIn: parent
        width: parent.width/2
        height: parent.height/2
    }

    Rectangle{
        height:parent.height/9
        width:parent.height/9
        y:parent.height/9*8
        x:parent.width-parent.height/9
        color:"red"
        MouseArea{
            anchors.fill: parent
            onClicked: {
                settings.visible=!settings.visible
            }
        }
    }
}
