import QtQuick 2.1
import QtWebEngine 1.0
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    id: browserWindow

    function loadUrl(url) { webEngineView.url = url }
    function setHomeUrl(url) { browserWindow.homeUrl = url }

    width: 800
    height: 600
    visible: true
    visibility: "FullScreen"
    title: webEngineView && webEngineView.title

    property url homeUrl: "http:/www.kipr.org"

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
            ToolButton {
                id: homeButton
                iconSource: "icons/go-home.png"
                onClicked: browserWindow.loadUrl(browserWindow.homeUrl)
            }
            ToolButton {
                id: upButton
                iconSource: "icons/go-up.png"
                onClicked: webEngineView.scrollUp()
            }
            ToolButton {
                id: downButton
                iconSource: "icons/go-down.png"
                onClicked: webEngineView.scrollDown()
            }

            Item { Layout.fillWidth: true }
        }
    }

    WebEngineView {
        id: webEngineView
        anchors.fill: parent
        focus: true

        function scrollUp() { scroll(-height/2) }
        function scrollDown() { scroll(height/2) }
        function scroll(amt) { runJavaScript("window.scrollBy(0, " + amt + ");") }
    }
}
