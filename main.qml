import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtCharts 2.2

ApplicationWindow {
    id:root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Button {
        id: button
        x: 181
        y: 68
        width: 278
        height: 40
        text:qsTr("show close values")
        onClicked:{

                        myfunction.loadWebPage();
                       var component = Qt.createComponent("window1.qml")
                       var window    = component.createObject(root)
                       window.show()

        }

    }

    Button {
        id: button1

                x: 181
                y: 176
                width: 278
                height: 40
                text: qsTr("show high values")
                onClicked:{

                                myfunction.loadWebPage();
                               var component = Qt.createComponent("window2.qml")
                               var window    = component.createObject(root)
                               window.show()


    }


}
    Button {
        id: button2

                x: 181
                y: 303
                width: 278
                height: 40
                text: qsTr("show volume values")
                onClicked:{

                                myfunction.loadWebPage();
                               var component = Qt.createComponent("window3.qml")
                               var window    = component.createObject(root)
                               window.show()
                }


            }
    }
