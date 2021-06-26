import QtQuick
import QtQuick.Controls

ApplicationWindow {
    id: root

    visible: true
    minimumHeight: Screen.height * 0.5
    minimumWidth: Screen.width * 0.5

    Rectangle {
        id: controlBar
        height: 100
        width: parent.width
        anchors.top: parent.top

        TextField {
            id: sourceDirectory
            text: "/home/viny/Import"
            width: 300
            anchors {
                left: controlBar.left; leftMargin: 50
                verticalCenter: parent.verticalCenter
            }
            onEditingFinished: {
                console.log("TextField changed: " + text)
                myModel.prepareImport(text, targetDirectory.text)
            }
        }

        TextField {
            id: targetDirectory
            text: "/home/viny/MesRAWs"
            width: 300
            anchors {
                left: sourceDirectory.right; leftMargin: 100
                verticalCenter: parent.verticalCenter
            }
        }

        Button {
            text: "Import"
            anchors {
                right: controlBar.right; rightMargin: 50
                verticalCenter: parent.verticalCenter
            }
            onClicked: {
                console.log("Button clicked")
                myModel.import()
            }
        }
    }

    Frame {
        id: filesFrame
        width: parent.width
        anchors {
            top: controlBar.bottom
            bottom: toolBar.top
        }

        ListView {
            id: filesListView
            anchors.fill: parent
            clip: true

            model: myModel
            delegate: RowDelegate {}

            ScrollBar.vertical: ScrollBar {
                parent: filesFrame
                policy: ScrollBar.AlwaysOn
                anchors {
                    top: parent.top; topMargin: filesFrame.topPadding
                    bottom: parent.bottom; bottomMargin: filesFrame.bottomPadding
                    right: parent.right; rightMargin: 1
                }
            }
        }
    }


    footer: ToolBar{
        id: toolBar
    }
}
