# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '/Users/lifan/local/Python/Assisttool/pyqt/FirstApp/mainwindow.ui'
#
# Created by: PyQt5 UI code generator 5.11.2
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(456, 339)
        self.centralWidget = QtWidgets.QWidget(MainWindow)
        self.centralWidget.setObjectName("centralWidget")
        self.Title = QtWidgets.QLabel(self.centralWidget)
        self.Title.setGeometry(QtCore.QRect(60, 10, 351, 71))
        font = QtGui.QFont()
        font.setPointSize(28)
        font.setItalic(True)
        self.Title.setFont(font)
        self.Title.setObjectName("Title")
        self.CalcBtn = QtWidgets.QPushButton(self.centralWidget)
        self.CalcBtn.setGeometry(QtCore.QRect(330, 90, 99, 121))
        self.CalcBtn.setObjectName("CalcBtn")
        self.horizontalLayoutWidget_2 = QtWidgets.QWidget(self.centralWidget)
        self.horizontalLayoutWidget_2.setGeometry(QtCore.QRect(30, 160, 261, 31))
        self.horizontalLayoutWidget_2.setObjectName("horizontalLayoutWidget_2")
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout(self.horizontalLayoutWidget_2)
        self.horizontalLayout_2.setContentsMargins(11, 11, 11, 11)
        self.horizontalLayout_2.setSpacing(6)
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.TexRate = QtWidgets.QLabel(self.horizontalLayoutWidget_2)
        self.TexRate.setObjectName("TexRate")
        self.horizontalLayout_2.addWidget(self.TexRate)
        self.TexRate_edit = QtWidgets.QTextEdit(self.horizontalLayoutWidget_2)
        self.TexRate_edit.setObjectName("TexRate_edit")
        self.horizontalLayout_2.addWidget(self.TexRate_edit)
        self.horizontalLayoutWidget = QtWidgets.QWidget(self.centralWidget)
        self.horizontalLayoutWidget.setGeometry(QtCore.QRect(30, 110, 261, 31))
        self.horizontalLayoutWidget.setObjectName("horizontalLayoutWidget")
        self.horizontalLayout = QtWidgets.QHBoxLayout(self.horizontalLayoutWidget)
        self.horizontalLayout.setContentsMargins(11, 11, 11, 11)
        self.horizontalLayout.setSpacing(6)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.Price = QtWidgets.QLabel(self.horizontalLayoutWidget)
        self.Price.setObjectName("Price")
        self.horizontalLayout.addWidget(self.Price)
        self.Price_edit = QtWidgets.QTextEdit(self.horizontalLayoutWidget)
        self.Price_edit.setObjectName("Price_edit")
        self.horizontalLayout.addWidget(self.Price_edit)
        self.FinalPrice = QtWidgets.QLabel(self.centralWidget)
        self.FinalPrice.setGeometry(QtCore.QRect(30, 210, 81, 17))
        self.FinalPrice.setObjectName("FinalPrice")
        self.FinalPriceResult = QtWidgets.QLabel(self.centralWidget)
        self.FinalPriceResult.setGeometry(QtCore.QRect(120, 210, 171, 17))
        self.FinalPriceResult.setText("")
        self.FinalPriceResult.setObjectName("FinalPriceResult")
        MainWindow.setCentralWidget(self.centralWidget)
        self.menuBar = QtWidgets.QMenuBar(MainWindow)
        self.menuBar.setGeometry(QtCore.QRect(0, 0, 456, 31))
        self.menuBar.setObjectName("menuBar")
        self.menuWhat = QtWidgets.QMenu(self.menuBar)
        self.menuWhat.setObjectName("menuWhat")
        MainWindow.setMenuBar(self.menuBar)
        self.mainToolBar = QtWidgets.QToolBar(MainWindow)
        self.mainToolBar.setObjectName("mainToolBar")
        MainWindow.addToolBar(QtCore.Qt.TopToolBarArea, self.mainToolBar)
        self.statusBar = QtWidgets.QStatusBar(MainWindow)
        self.statusBar.setObjectName("statusBar")
        MainWindow.setStatusBar(self.statusBar)
        self.menuBar.addAction(self.menuWhat.menuAction())

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.Title.setText(_translate("MainWindow", "Sales Tex Calculater"))
        self.CalcBtn.setText(_translate("MainWindow", "Calculate Tax"))
        self.TexRate.setText(_translate("MainWindow", "TexRate"))
        self.Price.setText(_translate("MainWindow", "Price"))
        self.FinalPrice.setText(_translate("MainWindow", "Final Price"))
        self.menuWhat.setTitle(_translate("MainWindow", "what?"))

