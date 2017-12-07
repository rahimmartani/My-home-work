import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtCharts 2.2

ApplicationWindow {

    visible: true
    width: 640
    height: 480
    title: qsTr("Volume Values chart")


    Connections {
        target: myfunction

        onValueUpdated3: {
            y = y/1000000
            series3.append(x, y)
            if (x > xAxis3.max) {
                xAxis3.max = x
            }
            if (y > yAxis3.max) {
                yAxis3.max = y
            }
        }
    }

    ChartView {
        id: chartView3
        title: "volume Values chart"
        anchors.fill: parent

        theme: ChartView.ChartThemeLight

        ValueAxis {
            id: yAxis3
            titleText: "y"
            titleVisible: true
            gridVisible: true
            tickCount: 11
            min: 0
            max: 87
        }

        ValueAxis{
            id: xAxis3
            min: 0
            max: 100
        }

        LineSeries {
            id: series3
            axisX: xAxis3
            axisY: yAxis3
            name: "Volume values series"
            visible: true
        }

    }



}

