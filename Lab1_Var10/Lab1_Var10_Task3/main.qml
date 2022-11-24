import QtQuick 2.12
import QtQuick.Window 2.12
import QtWebEngine 1.0
import QtWebView 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Window")
    WebEngineView {
        anchors.fill: parent
        url: "https://www.qt.io"
    }
}
