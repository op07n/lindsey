import QtQuick 2.1
import QtWebEngine 1.0
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    id: browserWindow

    function load(url) { webEngineView.url = url }

    width: 800
    height: 600
    visible: true
    title: webEngineView && webEngineView.title

    toolBar: ToolBar {
        id: navigationBar
        RowLayout {
            anchors.fill: parent;
            ToolButton {
                id: backButton
                iconSource: "icons/go-previous.png"
                onClicked: webEngineView.goBack()
                enabled: webEngineView && webEngineView.canGoBack
            }
            ToolButton {
                id: forwardButton
                iconSource: "icons/go-next.png"
                onClicked: webEngineView.goForward()
                enabled: webEngineView && webEngineView.canGoForward
            }
            Item { Layout.fillWidth: true }
        }
    }

    WebEngineView {
        id: webEngineView
        anchors.fill: parent
        focus: true
    }
}
