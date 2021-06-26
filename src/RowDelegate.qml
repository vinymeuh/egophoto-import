import QtQuick

Item {
    width: filesListView.width
    height: 50

    Row {
        spacing: 10
        Text {
            text: filename
            font.pixelSize: 14
        }

        Text {
            text: targetdir
            font.pixelSize: 14
        }

        Text {
            text: targetname
            font.pixelSize: 14
        }
    }
}
