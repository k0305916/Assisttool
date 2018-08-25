import sys
from PyQt5 import QtCore, QtGui, QtWidgets
from Ui_mainwindow import Ui_MainWindow


class MyApp(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.CalcBtn.clicked.connect(self.CalculateTax)

    def CalculateTax(self):
        #python exception? i do not know how to.
        price = int(self.Price_edit.toPlainText())
        tax = float(self.TexRate_edit.toPlainText())
        total_price = price + (tax*price)
        total_price_str = "The total price with tax is:" + str(total_price)
        self.FinalPriceResult.setText(total_price_str)


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    firstapp = MyApp()
    firstapp.show()
    sys.exit(app.exec_())
