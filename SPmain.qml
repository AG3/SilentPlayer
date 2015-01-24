import QtQuick 2.0
import QtQuick.Controls 1.2
import "qrc:/qml"

Rectangle {
    width:700
    height:900
    ListView{
        width:parent.width
        height:parent.height/9*7

        model:playList

        delegate: SPmusicElement{}
    }

    Slider{
        id:playProgress
        height:parent.height/9
        width:parent.width
        y:parent.height/9*7
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
            player.changeVolume(vol.value)
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
