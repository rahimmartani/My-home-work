import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Button {
        id: button1
        x: 250
        y: 124
        text: "presshere"
        onClicked:{

            textArea.append(myfunction.networkfunction(button1.text));

        }

    }

    TextArea {
        id: textArea
        x: 217
        y: 251
        width: 188
        height: 158
        text: "Text Area"
    }


}
