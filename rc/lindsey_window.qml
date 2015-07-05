import QtQuick 2.1
import QtWebEngine 1.0
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0
import QtQuick.Window 2.1
import QtQuick.Controls.Styles 1.3

ApplicationWindow {
    id: browserWindow

    function loadUrl(url) { webEngineView.url = url }
    function setHomeUrl(url) { browserWindow.homeUrl = url }
    function scrollUp() {
        webEngineView.scrollViewUp()
        navigationBar.showBriefly()
    }
    function scrollDown() {
        webEngineView.scrollViewDown()
        navigationBar.showBriefly()
    }

    width: 480
    height: 272
    visible: true
    visibility: "FullScreen"
    title: webEngineView && webEngineView.title

    property url homeUrl: "http:/www.kipr.org"

    // Fullscreen shortcut
    Action {
        shortcut: "Ctrl+F"
        onTriggered: {
            browserWindow.visibility = browserWindow.visibility == Window.FullScreen ? Window.Windowed : Window.FullScreen
        }
    }

    WebEngineView {
        id: webEngineView
        objectName: "webEngineView"
        anchors.fill: parent
        focus: true

        ToolBar {
            id: navigationBar
            state: "hidden"

            states: [
                State {
                    name: "shown"
                    PropertyChanges { target: navigationBar; opacity: 1; visible: true}
                },
                State {
                    name: "hidden"
                    PropertyChanges { target: navigationBar; opacity: 0; visible: false}
                }
            ]

            transitions: Transition {
                from: "shown"
                to: "hidden"
                reversible: true
                SequentialAnimation {
                    NumberAnimation { target: navigationBar; property: "opacity"; duration: 200 }
                    PropertyAction { target: navigationBar; property: "visible" }
                }
            }

            // Timer to hide toolbar after some time
            Timer {
                id: hideTimer
                interval: 3000
                onTriggered: navigationBar.state = "hidden"
            }

            // Shows toolbar and starts hide timer
            function showBriefly() {
                state = "shown"
                hideTimer.restart()
            }

            // Empty mouse area
            // Prevents mouse events from going "through" the toolbar
            MouseArea { anchors.fill: parent }

            // Toolbar buttons
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

                Item { Layout.fillWidth: true }
            }
        }

        function scrollViewUp() { scrollView(-height/2) }
        function scrollViewDown() { scrollView(height/2) }
        function scrollView(amt) { runJavaScript("window.scrollBy(0, " + amt + ");") }
    }
}
