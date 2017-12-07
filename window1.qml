import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtCharts 2.2

ApplicationWindow {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Close Values chart")

    Connections {
        target: myfunction
        onValueUpdated: {
            series.append(x, y)
            if (x > xAxis.max) {
                xAxis.max = x
            }
            if (y > yAxis.max) {
                yAxis.max = y
            }
        }
    }


    ChartView {
        id: chartView
        title: "Close Values chart"
        anchors.fill: parent
        antialiasing: true

        theme: ChartView.ChartThemeLight

        ValueAxis {
            id: yAxis
            titleText: "y"
            titleVisible: true
            gridVisible: true
            tickCount: 11

            min: 0
            max: 87
        }

        ValueAxis{
            id: xAxis
            min: 0
            max: 100
        }

        LineSeries {
            id: series
            axisX: xAxis
            axisY: yAxis
            name: "Close values series"
            visible: true
        }

    }

}

