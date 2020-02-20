import os
import sys
from PySide2.QtCore import QUrl
from PySide2.QtWidgets import QApplication, QMainWindow, QVBoxLayout, QWidget
from PySide2.QtWebEngineWidgets import QWebEngineView,QWebEnginePage

class WebPage(QWebEnginePage):
    """
    Makes it possible to use a Python logger to print javascript console messages
    """
    def __init__(self, parent=None):
        super(WebPage, self).__init__(parent)

    def javaScriptConsoleMessage(self, msg, lineNumber, sourceID, foo):
        print("TOTO JsConsole(%s:%s): %s" % (sourceID, lineNumber, msg))


class MainWindow(QMainWindow):
    def __init__(self, parent=None):
        super(MainWindow, self).__init__(parent)
        self.form_widget = FormWidget(self)
        _widget = QWidget()
        _layout = QVBoxLayout(_widget)
        _layout.addWidget(self.form_widget)
        self.setCentralWidget(_widget)


class FormWidget(QWidget):
    def __init__(self, parent):
        super(FormWidget, self).__init__(parent)
        self.__controls()
        self.__layout()

    def __controls(self):

        path = os.path.join(os.path.dirname(os.path.realpath(__file__)), "test2.html")
        print(path)
        #html = open('test2.html', 'r').read()
        self.browser = QWebEngineView()
        self.browser.setPage(  WebPage( self.browser ) )
        #self.browser.load(QUrl.fromLocalFile(path))
        self.browser.load(QUrl("http://localhost:5000"))
        #//self.browser.setHtml(")
        #self.browser.loadFinished.connect(self.onLoadFinished)

    """
    def onLoadFinished(self, ok):
	pass
        #if ok:
        #    #self.browser.page().runJavaScript("helloWorld(1, \"2\")", self.ready)
    """
    def __layout(self):
        self.vbox = QVBoxLayout()
        self.hBox = QVBoxLayout()
        self.hBox.addWidget(self.browser)
        self.vbox.addLayout(self.hBox)
        self.setLayout(self.vbox)

    def ready(self, returnValue):
        print(returnValue)

def main():
    app = QApplication(sys.argv)
    win = MainWindow()
    win.show()
    return app.exec_()


if __name__ == '__main__':
    sys.exit(main())
