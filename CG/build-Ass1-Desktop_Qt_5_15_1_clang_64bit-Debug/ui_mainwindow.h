/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <myLabel.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    myLabel *myScreen;
    QCheckBox *showAxes;
    QSpinBox *gridSize;
    QPushButton *showGrid;
    QLabel *gridSizeLabel;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *mouseMovementLabel;
    QLabel *mouseMovement;
    QLabel *mousePressedLabel;
    QLabel *mousePressed;
    QPushButton *setPoint1;
    QPushButton *setPoint2;
    QLabel *lineDrawingLabel;
    QComboBox *selectLineDrawAlgo;
    QPushButton *unsetPoint2;
    QPushButton *unsetPoint1;
    QLabel *selectLineDrawAlgoLabel;
    QPushButton *drawLine;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1920, 1080);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        myScreen = new myLabel(centralwidget);
        myScreen->setObjectName(QString::fromUtf8("myScreen"));
        myScreen->setGeometry(QRect(10, 10, 700, 700));
        myScreen->setMouseTracking(true);
        myScreen->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(0, 0, 0);"));
        showAxes = new QCheckBox(centralwidget);
        showAxes->setObjectName(QString::fromUtf8("showAxes"));
        showAxes->setGeometry(QRect(1020, 30, 131, 31));
        gridSize = new QSpinBox(centralwidget);
        gridSize->setObjectName(QString::fromUtf8("gridSize"));
        gridSize->setGeometry(QRect(1160, 30, 231, 31));
        gridSize->setMinimum(1);
        gridSize->setMaximum(500);
        showGrid = new QPushButton(centralwidget);
        showGrid->setObjectName(QString::fromUtf8("showGrid"));
        showGrid->setGeometry(QRect(1020, 270, 371, 51));
        gridSizeLabel = new QLabel(centralwidget);
        gridSizeLabel->setObjectName(QString::fromUtf8("gridSizeLabel"));
        gridSizeLabel->setGeometry(QRect(1160, 10, 55, 16));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(1020, 80, 371, 171));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        mouseMovementLabel = new QLabel(gridLayoutWidget);
        mouseMovementLabel->setObjectName(QString::fromUtf8("mouseMovementLabel"));

        gridLayout->addWidget(mouseMovementLabel, 0, 0, 1, 1);

        mouseMovement = new QLabel(gridLayoutWidget);
        mouseMovement->setObjectName(QString::fromUtf8("mouseMovement"));
        mouseMovement->setAutoFillBackground(false);
        mouseMovement->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);"));
        mouseMovement->setFrameShape(QFrame::Box);

        gridLayout->addWidget(mouseMovement, 1, 0, 1, 1);

        mousePressedLabel = new QLabel(gridLayoutWidget);
        mousePressedLabel->setObjectName(QString::fromUtf8("mousePressedLabel"));

        gridLayout->addWidget(mousePressedLabel, 2, 0, 1, 1);

        mousePressed = new QLabel(gridLayoutWidget);
        mousePressed->setObjectName(QString::fromUtf8("mousePressed"));
        mousePressed->setAutoFillBackground(false);
        mousePressed->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);"));
        mousePressed->setFrameShape(QFrame::Box);

        gridLayout->addWidget(mousePressed, 4, 0, 1, 1);

        setPoint1 = new QPushButton(centralwidget);
        setPoint1->setObjectName(QString::fromUtf8("setPoint1"));
        setPoint1->setGeometry(QRect(1020, 390, 181, 41));
        setPoint2 = new QPushButton(centralwidget);
        setPoint2->setObjectName(QString::fromUtf8("setPoint2"));
        setPoint2->setGeometry(QRect(1210, 390, 181, 41));
        lineDrawingLabel = new QLabel(centralwidget);
        lineDrawingLabel->setObjectName(QString::fromUtf8("lineDrawingLabel"));
        lineDrawingLabel->setGeometry(QRect(1020, 350, 191, 31));
        selectLineDrawAlgo = new QComboBox(centralwidget);
        selectLineDrawAlgo->addItem(QString());
        selectLineDrawAlgo->addItem(QString());
        selectLineDrawAlgo->setObjectName(QString::fromUtf8("selectLineDrawAlgo"));
        selectLineDrawAlgo->setGeometry(QRect(1020, 540, 371, 41));
        unsetPoint2 = new QPushButton(centralwidget);
        unsetPoint2->setObjectName(QString::fromUtf8("unsetPoint2"));
        unsetPoint2->setGeometry(QRect(1210, 440, 181, 41));
        unsetPoint1 = new QPushButton(centralwidget);
        unsetPoint1->setObjectName(QString::fromUtf8("unsetPoint1"));
        unsetPoint1->setGeometry(QRect(1020, 440, 181, 41));
        selectLineDrawAlgoLabel = new QLabel(centralwidget);
        selectLineDrawAlgoLabel->setObjectName(QString::fromUtf8("selectLineDrawAlgoLabel"));
        selectLineDrawAlgoLabel->setGeometry(QRect(1020, 500, 201, 41));
        drawLine = new QPushButton(centralwidget);
        drawLine->setObjectName(QString::fromUtf8("drawLine"));
        drawLine->setGeometry(QRect(1020, 590, 371, 71));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1920, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        myScreen->setText(QString());
        showAxes->setText(QCoreApplication::translate("MainWindow", "Show Axes", nullptr));
        showGrid->setText(QCoreApplication::translate("MainWindow", "Reset Grid", nullptr));
        gridSizeLabel->setText(QCoreApplication::translate("MainWindow", "Grid Size", nullptr));
        mouseMovementLabel->setText(QCoreApplication::translate("MainWindow", "Mouse Movement", nullptr));
        mouseMovement->setText(QString());
        mousePressedLabel->setText(QCoreApplication::translate("MainWindow", "Mouse Pressed", nullptr));
        mousePressed->setText(QString());
        setPoint1->setText(QCoreApplication::translate("MainWindow", "Set Point 1", nullptr));
        setPoint2->setText(QCoreApplication::translate("MainWindow", "Set Point 2", nullptr));
        lineDrawingLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Line Drawing</span></p></body></html>", nullptr));
        selectLineDrawAlgo->setItemText(0, QCoreApplication::translate("MainWindow", "DDA Line Drawing Alogrithm", nullptr));
        selectLineDrawAlgo->setItemText(1, QCoreApplication::translate("MainWindow", "Breshenham Line Drawing Algorithm", nullptr));

        unsetPoint2->setText(QCoreApplication::translate("MainWindow", "Unset Point 2", nullptr));
        unsetPoint1->setText(QCoreApplication::translate("MainWindow", "Unset Point 1", nullptr));
        selectLineDrawAlgoLabel->setText(QCoreApplication::translate("MainWindow", "Select Line Drawing Algorithm", nullptr));
        drawLine->setText(QCoreApplication::translate("MainWindow", "Draw Line", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
