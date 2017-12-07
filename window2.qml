import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtCharts 2.2

ApplicationWindow {

    visible: true
    width: 640
    height: 480
    title: qsTr("High Values chart")

    Connections {
        target: myfunction
        onValueUpdated2: {
            series2.append(x, y)
            if (x > xAxis2.max) {
                xAxis2.max = x
            }
            if (y > yAxis2.max) {
                yAxis2.max = y
            }
        }
    }


    ChartView {
        id: chartView2
        title: "high Values chart"
        anchors.fill: parent

        theme: ChartView.ChartThemeLight

        ValueAxis {
            id: yAxis2
            titleText: "y"
            titleVisible: true
            gridVisible: true
            tickCount: 11
            min: 0
            max: 87
        }

        ValueAxis{
            id: xAxis2
            min: 0
            max: 100
        }

        LineSeries {
            id: series2
            axisX: xAxis2
            axisY: yAxis2
            name: "high values series"
            visible: true
        }

    }


}

