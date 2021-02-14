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
#include <QtWidgets/QFrame>
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
    QPushButton *setPoint1;
    QPushButton *setPoint2;
    QLabel *lineDrawingLabel;
    QComboBox *selectLineDrawAlgo;
    QPushButton *unsetPoint2;
    QPushButton *unsetPoint1;
    QLabel *selectLineDrawAlgoLabel;
    QPushButton *drawLine;
    QLabel *timeElapsedLine;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QLabel *circleDrawingLabel;
    QComboBox *selectCircleDrawAlgo;
    QLabel *selectCircleDrawAlgoLabel;
    QLabel *timeElapsedCircle;
    QSpinBox *radius;
    QPushButton *setCentre;
    QPushButton *unsetCentre;
    QLabel *radiusLabel;
    QCheckBox *checkBox;
    QCheckBox *checkBoxCircle;
    QPushButton *drawCircle;
    QLabel *mouseMovementLabel;
    QLabel *mouseMovement;
    QLabel *mousePressedLabel;
    QLabel *mousePressed;
    QFrame *line_4;
    QCheckBox *checkBoxEllipse;
    QLabel *ellipseDrawingLabel;
    QLabel *timeElapsedEllipse;
    QSpinBox *ry;
    QSpinBox *rx;
    QLabel *rxLabel;
    QLabel *ryLabel;
    QComboBox *selectEllipseDrawAlgo;
    QPushButton *drawEllipse;
    QPushButton *unsetCentreEllipse;
    QPushButton *setCentreEllipse;
    QCheckBox *checkBoxPolygon;
    QLabel *polyDrawingLabel;
    QPushButton *addPointPoly;
    QPushButton *RemovePointPoly;
    QPushButton *drawPolygon;
    QCheckBox *checkBoxFill;
    QLabel *FillLabel;
    QPushButton *boundaryFill;
    QPushButton *floodFill;
    QPushButton *ScanLineFill;
    QSpinBox *scaleX;
    QSpinBox *scaleY;
    QLabel *label;
    QLabel *label_2;
    QPushButton *scale;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1920, 1080);
        MainWindow->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(13, 17, 23);\n"
"background-color: rgb(13, 17, 23);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        myScreen = new myLabel(centralwidget);
        myScreen->setObjectName(QString::fromUtf8("myScreen"));
        myScreen->setGeometry(QRect(10, 10, 750, 750));
        myScreen->setMouseTracking(true);
        myScreen->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(0, 0, 0);"));
        showAxes = new QCheckBox(centralwidget);
        showAxes->setObjectName(QString::fromUtf8("showAxes"));
        showAxes->setGeometry(QRect(770, 20, 131, 31));
        showAxes->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        gridSize = new QSpinBox(centralwidget);
        gridSize->setObjectName(QString::fromUtf8("gridSize"));
        gridSize->setGeometry(QRect(910, 20, 141, 31));
        gridSize->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        gridSize->setMinimum(1);
        gridSize->setMaximum(500);
        showGrid = new QPushButton(centralwidget);
        showGrid->setObjectName(QString::fromUtf8("showGrid"));
        showGrid->setGeometry(QRect(770, 220, 281, 41));
        showGrid->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        gridSizeLabel = new QLabel(centralwidget);
        gridSizeLabel->setObjectName(QString::fromUtf8("gridSizeLabel"));
        gridSizeLabel->setGeometry(QRect(910, 0, 55, 16));
        gridSizeLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        setPoint1 = new QPushButton(centralwidget);
        setPoint1->setObjectName(QString::fromUtf8("setPoint1"));
        setPoint1->setGeometry(QRect(770, 320, 131, 30));
        setPoint1->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        setPoint2 = new QPushButton(centralwidget);
        setPoint2->setObjectName(QString::fromUtf8("setPoint2"));
        setPoint2->setGeometry(QRect(910, 320, 141, 30));
        setPoint2->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        lineDrawingLabel = new QLabel(centralwidget);
        lineDrawingLabel->setObjectName(QString::fromUtf8("lineDrawingLabel"));
        lineDrawingLabel->setGeometry(QRect(790, 280, 61, 31));
        lineDrawingLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        selectLineDrawAlgo = new QComboBox(centralwidget);
        selectLineDrawAlgo->addItem(QString());
        selectLineDrawAlgo->addItem(QString());
        selectLineDrawAlgo->setObjectName(QString::fromUtf8("selectLineDrawAlgo"));
        selectLineDrawAlgo->setGeometry(QRect(770, 430, 281, 41));
        selectLineDrawAlgo->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);\n"
"selection-background-color: rgb(22, 27, 34);"));
        unsetPoint2 = new QPushButton(centralwidget);
        unsetPoint2->setObjectName(QString::fromUtf8("unsetPoint2"));
        unsetPoint2->setGeometry(QRect(910, 350, 141, 30));
        unsetPoint2->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        unsetPoint1 = new QPushButton(centralwidget);
        unsetPoint1->setObjectName(QString::fromUtf8("unsetPoint1"));
        unsetPoint1->setGeometry(QRect(770, 350, 131, 30));
        unsetPoint1->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        selectLineDrawAlgoLabel = new QLabel(centralwidget);
        selectLineDrawAlgoLabel->setObjectName(QString::fromUtf8("selectLineDrawAlgoLabel"));
        selectLineDrawAlgoLabel->setGeometry(QRect(770, 390, 201, 41));
        selectLineDrawAlgoLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        drawLine = new QPushButton(centralwidget);
        drawLine->setObjectName(QString::fromUtf8("drawLine"));
        drawLine->setGeometry(QRect(770, 460, 281, 51));
        drawLine->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        timeElapsedLine = new QLabel(centralwidget);
        timeElapsedLine->setObjectName(QString::fromUtf8("timeElapsedLine"));
        timeElapsedLine->setGeometry(QRect(870, 280, 181, 31));
        timeElapsedLine->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(0, 0, 0);"));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(1300, -200, 20, 1021));
        line->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(770, 510, 281, 20));
        line_2->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(770, 260, 281, 20));
        line_3->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"border-color: rgb(178, 192, 206);\n"
"gridline-color: rgb(178, 192, 206);"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        circleDrawingLabel = new QLabel(centralwidget);
        circleDrawingLabel->setObjectName(QString::fromUtf8("circleDrawingLabel"));
        circleDrawingLabel->setGeometry(QRect(790, 530, 71, 31));
        circleDrawingLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        selectCircleDrawAlgo = new QComboBox(centralwidget);
        selectCircleDrawAlgo->addItem(QString());
        selectCircleDrawAlgo->addItem(QString());
        selectCircleDrawAlgo->addItem(QString());
        selectCircleDrawAlgo->addItem(QString());
        selectCircleDrawAlgo->setObjectName(QString::fromUtf8("selectCircleDrawAlgo"));
        selectCircleDrawAlgo->setGeometry(QRect(770, 680, 281, 41));
        selectCircleDrawAlgo->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);\n"
"selection-background-color:  rgb(22, 27, 34);"));
        selectCircleDrawAlgoLabel = new QLabel(centralwidget);
        selectCircleDrawAlgoLabel->setObjectName(QString::fromUtf8("selectCircleDrawAlgoLabel"));
        selectCircleDrawAlgoLabel->setGeometry(QRect(770, 660, 201, 21));
        selectCircleDrawAlgoLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        timeElapsedCircle = new QLabel(centralwidget);
        timeElapsedCircle->setObjectName(QString::fromUtf8("timeElapsedCircle"));
        timeElapsedCircle->setGeometry(QRect(870, 530, 181, 31));
        timeElapsedCircle->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(0, 0, 0);"));
        radius = new QSpinBox(centralwidget);
        radius->setObjectName(QString::fromUtf8("radius"));
        radius->setGeometry(QRect(770, 620, 281, 31));
        radius->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        setCentre = new QPushButton(centralwidget);
        setCentre->setObjectName(QString::fromUtf8("setCentre"));
        setCentre->setGeometry(QRect(770, 560, 131, 30));
        setCentre->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        unsetCentre = new QPushButton(centralwidget);
        unsetCentre->setObjectName(QString::fromUtf8("unsetCentre"));
        unsetCentre->setGeometry(QRect(910, 560, 141, 30));
        unsetCentre->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        radiusLabel = new QLabel(centralwidget);
        radiusLabel->setObjectName(QString::fromUtf8("radiusLabel"));
        radiusLabel->setGeometry(QRect(780, 600, 201, 16));
        radiusLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(770, 280, 16, 31));
        checkBox->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        checkBoxCircle = new QCheckBox(centralwidget);
        checkBoxCircle->setObjectName(QString::fromUtf8("checkBoxCircle"));
        checkBoxCircle->setGeometry(QRect(770, 530, 21, 31));
        drawCircle = new QPushButton(centralwidget);
        drawCircle->setObjectName(QString::fromUtf8("drawCircle"));
        drawCircle->setGeometry(QRect(770, 710, 281, 51));
        drawCircle->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        mouseMovementLabel = new QLabel(centralwidget);
        mouseMovementLabel->setObjectName(QString::fromUtf8("mouseMovementLabel"));
        mouseMovementLabel->setGeometry(QRect(770, 50, 281, 31));
        mouseMovementLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        mouseMovement = new QLabel(centralwidget);
        mouseMovement->setObjectName(QString::fromUtf8("mouseMovement"));
        mouseMovement->setGeometry(QRect(770, 90, 281, 41));
        mouseMovement->setAutoFillBackground(false);
        mouseMovement->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"border-color: rgb(178, 192, 206);"));
        mouseMovement->setFrameShape(QFrame::Box);
        mousePressedLabel = new QLabel(centralwidget);
        mousePressedLabel->setObjectName(QString::fromUtf8("mousePressedLabel"));
        mousePressedLabel->setGeometry(QRect(770, 140, 281, 31));
        mousePressedLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
""));
        mousePressed = new QLabel(centralwidget);
        mousePressed->setObjectName(QString::fromUtf8("mousePressed"));
        mousePressed->setGeometry(QRect(770, 180, 281, 41));
        mousePressed->setAutoFillBackground(false);
        mousePressed->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"border-color: rgb(178, 192, 206);"));
        mousePressed->setFrameShape(QFrame::Box);
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(1631, 0, 20, 1021));
        line_4->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        checkBoxEllipse = new QCheckBox(centralwidget);
        checkBoxEllipse->setObjectName(QString::fromUtf8("checkBoxEllipse"));
        checkBoxEllipse->setGeometry(QRect(1060, 10, 21, 31));
        ellipseDrawingLabel = new QLabel(centralwidget);
        ellipseDrawingLabel->setObjectName(QString::fromUtf8("ellipseDrawingLabel"));
        ellipseDrawingLabel->setGeometry(QRect(1080, 10, 81, 31));
        ellipseDrawingLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        timeElapsedEllipse = new QLabel(centralwidget);
        timeElapsedEllipse->setObjectName(QString::fromUtf8("timeElapsedEllipse"));
        timeElapsedEllipse->setGeometry(QRect(1170, 200, 181, 31));
        timeElapsedEllipse->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(0, 0, 0);"));
        ry = new QSpinBox(centralwidget);
        ry->setObjectName(QString::fromUtf8("ry"));
        ry->setGeometry(QRect(1200, 70, 141, 31));
        ry->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        rx = new QSpinBox(centralwidget);
        rx->setObjectName(QString::fromUtf8("rx"));
        rx->setGeometry(QRect(1060, 70, 136, 31));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(rx->sizePolicy().hasHeightForWidth());
        rx->setSizePolicy(sizePolicy);
        rx->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        rxLabel = new QLabel(centralwidget);
        rxLabel->setObjectName(QString::fromUtf8("rxLabel"));
        rxLabel->setGeometry(QRect(1057, 49, 136, 21));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(rxLabel->sizePolicy().hasHeightForWidth());
        rxLabel->setSizePolicy(sizePolicy1);
        rxLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        ryLabel = new QLabel(centralwidget);
        ryLabel->setObjectName(QString::fromUtf8("ryLabel"));
        ryLabel->setGeometry(QRect(1200, 49, 136, 21));
        ryLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        selectEllipseDrawAlgo = new QComboBox(centralwidget);
        selectEllipseDrawAlgo->addItem(QString());
        selectEllipseDrawAlgo->setObjectName(QString::fromUtf8("selectEllipseDrawAlgo"));
        selectEllipseDrawAlgo->setGeometry(QRect(1060, 130, 281, 41));
        selectEllipseDrawAlgo->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);\n"
"selection-background-color:  rgb(22, 27, 34);"));
        drawEllipse = new QPushButton(centralwidget);
        drawEllipse->setObjectName(QString::fromUtf8("drawEllipse"));
        drawEllipse->setGeometry(QRect(1060, 160, 281, 31));
        drawEllipse->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        unsetCentreEllipse = new QPushButton(centralwidget);
        unsetCentreEllipse->setObjectName(QString::fromUtf8("unsetCentreEllipse"));
        unsetCentreEllipse->setGeometry(QRect(1190, 100, 141, 31));
        unsetCentreEllipse->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        setCentreEllipse = new QPushButton(centralwidget);
        setCentreEllipse->setObjectName(QString::fromUtf8("setCentreEllipse"));
        setCentreEllipse->setGeometry(QRect(1060, 100, 131, 31));
        setCentreEllipse->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        checkBoxPolygon = new QCheckBox(centralwidget);
        checkBoxPolygon->setObjectName(QString::fromUtf8("checkBoxPolygon"));
        checkBoxPolygon->setGeometry(QRect(1060, 200, 21, 31));
        polyDrawingLabel = new QLabel(centralwidget);
        polyDrawingLabel->setObjectName(QString::fromUtf8("polyDrawingLabel"));
        polyDrawingLabel->setGeometry(QRect(1080, 200, 81, 31));
        polyDrawingLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        addPointPoly = new QPushButton(centralwidget);
        addPointPoly->setObjectName(QString::fromUtf8("addPointPoly"));
        addPointPoly->setGeometry(QRect(1060, 240, 131, 31));
        addPointPoly->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        RemovePointPoly = new QPushButton(centralwidget);
        RemovePointPoly->setObjectName(QString::fromUtf8("RemovePointPoly"));
        RemovePointPoly->setGeometry(QRect(1200, 240, 141, 31));
        RemovePointPoly->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        drawPolygon = new QPushButton(centralwidget);
        drawPolygon->setObjectName(QString::fromUtf8("drawPolygon"));
        drawPolygon->setGeometry(QRect(1060, 270, 281, 31));
        drawPolygon->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        checkBoxFill = new QCheckBox(centralwidget);
        checkBoxFill->setObjectName(QString::fromUtf8("checkBoxFill"));
        checkBoxFill->setGeometry(QRect(1060, 310, 21, 31));
        FillLabel = new QLabel(centralwidget);
        FillLabel->setObjectName(QString::fromUtf8("FillLabel"));
        FillLabel->setGeometry(QRect(1080, 310, 91, 31));
        FillLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        boundaryFill = new QPushButton(centralwidget);
        boundaryFill->setObjectName(QString::fromUtf8("boundaryFill"));
        boundaryFill->setGeometry(QRect(1060, 340, 111, 51));
        boundaryFill->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        floodFill = new QPushButton(centralwidget);
        floodFill->setObjectName(QString::fromUtf8("floodFill"));
        floodFill->setGeometry(QRect(1180, 340, 111, 51));
        floodFill->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        ScanLineFill = new QPushButton(centralwidget);
        ScanLineFill->setObjectName(QString::fromUtf8("ScanLineFill"));
        ScanLineFill->setGeometry(QRect(1310, 340, 121, 51));
        ScanLineFill->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        scaleX = new QSpinBox(centralwidget);
        scaleX->setObjectName(QString::fromUtf8("scaleX"));
        scaleX->setGeometry(QRect(1180, 430, 42, 22));
        scaleY = new QSpinBox(centralwidget);
        scaleY->setObjectName(QString::fromUtf8("scaleY"));
        scaleY->setGeometry(QRect(1260, 430, 41, 22));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1150, 430, 31, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1230, 430, 21, 16));
        scale = new QPushButton(centralwidget);
        scale->setObjectName(QString::fromUtf8("scale"));
        scale->setGeometry(QRect(1070, 430, 71, 32));
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
        setPoint1->setText(QCoreApplication::translate("MainWindow", "Set Point 1", nullptr));
        setPoint2->setText(QCoreApplication::translate("MainWindow", "Set Point 2", nullptr));
        lineDrawingLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Draw Line</p></body></html>", nullptr));
        selectLineDrawAlgo->setItemText(0, QCoreApplication::translate("MainWindow", "DDA Line Drawing Alogrithm", nullptr));
        selectLineDrawAlgo->setItemText(1, QCoreApplication::translate("MainWindow", "Breshenham Line Drawing Algorithm", nullptr));

        unsetPoint2->setText(QCoreApplication::translate("MainWindow", "Unset Point 2", nullptr));
        unsetPoint1->setText(QCoreApplication::translate("MainWindow", "Unset Point 1", nullptr));
        selectLineDrawAlgoLabel->setText(QCoreApplication::translate("MainWindow", "Select Line Drawing Algorithm", nullptr));
        drawLine->setText(QCoreApplication::translate("MainWindow", "Draw Line", nullptr));
        timeElapsedLine->setText(QCoreApplication::translate("MainWindow", "Time elapsed (in ms): ", nullptr));
        circleDrawingLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Draw Circle</p></body></html>", nullptr));
        selectCircleDrawAlgo->setItemText(0, QCoreApplication::translate("MainWindow", "Mid-point Circle Algorithm", nullptr));
        selectCircleDrawAlgo->setItemText(1, QCoreApplication::translate("MainWindow", "Polar Circle Algorithm", nullptr));
        selectCircleDrawAlgo->setItemText(2, QCoreApplication::translate("MainWindow", "Parametric Circle Algorithm", nullptr));
        selectCircleDrawAlgo->setItemText(3, QCoreApplication::translate("MainWindow", "Bresenham's Circle Drawing Algorithm", nullptr));

        selectCircleDrawAlgoLabel->setText(QCoreApplication::translate("MainWindow", "Select Circle Drawing Algorithm", nullptr));
        timeElapsedCircle->setText(QCoreApplication::translate("MainWindow", "Time elapsed (in ms): ", nullptr));
        setCentre->setText(QCoreApplication::translate("MainWindow", "Set Centre", nullptr));
        unsetCentre->setText(QCoreApplication::translate("MainWindow", "Unset Centre", nullptr));
        radiusLabel->setText(QCoreApplication::translate("MainWindow", "Radius", nullptr));
        checkBox->setText(QString());
        checkBoxCircle->setText(QString());
        drawCircle->setText(QCoreApplication::translate("MainWindow", "Draw Circle", nullptr));
        mouseMovementLabel->setText(QCoreApplication::translate("MainWindow", "Mouse Movement", nullptr));
        mouseMovement->setText(QString());
        mousePressedLabel->setText(QCoreApplication::translate("MainWindow", "Mouse Pressed", nullptr));
        mousePressed->setText(QString());
        checkBoxEllipse->setText(QString());
        ellipseDrawingLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Draw Ellipse</p></body></html>", nullptr));
        timeElapsedEllipse->setText(QCoreApplication::translate("MainWindow", "Time elapsed (in ms): ", nullptr));
        rxLabel->setText(QCoreApplication::translate("MainWindow", "XRadius", nullptr));
        ryLabel->setText(QCoreApplication::translate("MainWindow", "YRadius", nullptr));
        selectEllipseDrawAlgo->setItemText(0, QCoreApplication::translate("MainWindow", "Mid-point Ellipse Algorithm", nullptr));

        drawEllipse->setText(QCoreApplication::translate("MainWindow", "Draw Ellipse", nullptr));
        unsetCentreEllipse->setText(QCoreApplication::translate("MainWindow", "Unset Centre", nullptr));
        setCentreEllipse->setText(QCoreApplication::translate("MainWindow", "Set Centre", nullptr));
        checkBoxPolygon->setText(QString());
        polyDrawingLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Draw Polygon</p></body></html>", nullptr));
        addPointPoly->setText(QCoreApplication::translate("MainWindow", "Add Point", nullptr));
        RemovePointPoly->setText(QCoreApplication::translate("MainWindow", "Remove Last Point", nullptr));
        drawPolygon->setText(QCoreApplication::translate("MainWindow", "Draw Polygon", nullptr));
        checkBoxFill->setText(QString());
        FillLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Fill Algorithms</p></body></html>", nullptr));
        boundaryFill->setText(QCoreApplication::translate("MainWindow", "Boundary Fill", nullptr));
        floodFill->setText(QCoreApplication::translate("MainWindow", "Flood Fill", nullptr));
        ScanLineFill->setText(QCoreApplication::translate("MainWindow", "Scan Line Fill", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        scale->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
