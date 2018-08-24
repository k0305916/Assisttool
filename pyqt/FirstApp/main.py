import sys
from PyQt5 import QtCore, QtGui,QtWidgets
from Ui_mainwindow import Ui_MainWindow

class MyApp(QtWidgets.QMainWindow,Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        




if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    firstapp = MyApp()
    firstapp.show()
    sys.exit(app.exec_())