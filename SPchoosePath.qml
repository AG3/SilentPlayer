import QtQuick 2.0

Rectangle {
    Rectangle{
        z:1
        color:"white"
        width:parent.width
        height:parent.height/10
        Text{
            id:nowDirTxt
            text:"/sdcard"
        }
    }

    ListView{
        z:0
        y:parent.height/10
        width:parent.width
        height:parent.height/10*8
        model: dirList
        delegate: Rectangle {
                 width: parent.width
                 height:50
                 color:"lightgray"
                 border.color: "gray"
                 border.width: 1
                 Text {
                     text: modelData
                 }
                 MouseArea{
                     anchors.fill: parent
                     onClicked: {
                         if(modelData!="..")
                         {
                            nowDirTxt.text+=("/"+modelData)
                         }
                         else
                         {
                            nowDirTxt.text=nowDirTxt.text.substring(0,nowDirTxt.text.lastIndexOf("/"))
                         }

                         urlSelectorr.appendDir(modelData)
                     }
                 }
             }
    }

    Rectangle{
        y:parent.height/10*9
        width:parent.width
        height:parent.height/10
        color:"gray"
        Text {
            anchors.centerIn: parent
            text: "Apply"
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                if(nowDirTxt.text.length>0)
                    player.setMusicDir(nowDirTxt.text)
                else
                    player.setMusicDir("/")

                parent.parent.parent.visible=false
            }
        }
    }

}
