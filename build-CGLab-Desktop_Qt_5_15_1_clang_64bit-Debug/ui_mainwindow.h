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
    QPushButton *scale;
    QSpinBox *scale_x;
    QSpinBox *scale_y;
    QLabel *scaleXLabel;
    QLabel *scaleYLabel;
    QLabel *scaleLabel;
    QLabel *transX;
    QSpinBox *tX;
    QSpinBox *tY;
    QLabel *transY;
    QPushButton *translate;
    QLabel *transLabel;
    QPushButton *rotate;
    QLabel *rotateAngleLabel;
    QSpinBox *rotdeg;
    QPushButton *reflect;
    QLabel *label;
    QLabel *shearX;
    QLabel *lshearY;
    QSpinBox *sh_X;
    QSpinBox *sh_Y;
    QPushButton *shear;
    QSpinBox *x_max;
    QSpinBox *y_min;
    QLabel *label_18;
    QLabel *label_19;
    QSpinBox *x_min;
    QSpinBox *y_max;
    QLabel *label_17;
    QLabel *label_16;
    QPushButton *clip_line;
    QPushButton *clr_bound;
    QPushButton *set_bound;
    QPushButton *clip_poly;
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
        myScreen->setGeometry(QRect(10, 10, 700, 700));
        myScreen->setMouseTracking(true);
        myScreen->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(0, 0, 0);"));
        showAxes = new QCheckBox(centralwidget);
        showAxes->setObjectName(QString::fromUtf8("showAxes"));
        showAxes->setGeometry(QRect(720, 40, 131, 31));
        showAxes->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        gridSize = new QSpinBox(centralwidget);
        gridSize->setObjectName(QString::fromUtf8("gridSize"));
        gridSize->setGeometry(QRect(860, 40, 141, 31));
        gridSize->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        gridSize->setMinimum(1);
        gridSize->setMaximum(500);
        showGrid = new QPushButton(centralwidget);
        showGrid->setObjectName(QString::fromUtf8("showGrid"));
        showGrid->setGeometry(QRect(720, 190, 281, 31));
        showGrid->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        gridSizeLabel = new QLabel(centralwidget);
        gridSizeLabel->setObjectName(QString::fromUtf8("gridSizeLabel"));
        gridSizeLabel->setGeometry(QRect(860, 20, 55, 16));
        gridSizeLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        setPoint1 = new QPushButton(centralwidget);
        setPoint1->setObjectName(QString::fromUtf8("setPoint1"));
        setPoint1->setGeometry(QRect(710, 280, 131, 30));
        setPoint1->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        setPoint2 = new QPushButton(centralwidget);
        setPoint2->setObjectName(QString::fromUtf8("setPoint2"));
        setPoint2->setGeometry(QRect(850, 280, 141, 30));
        setPoint2->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        lineDrawingLabel = new QLabel(centralwidget);
        lineDrawingLabel->setObjectName(QString::fromUtf8("lineDrawingLabel"));
        lineDrawingLabel->setGeometry(QRect(730, 240, 61, 31));
        lineDrawingLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        selectLineDrawAlgo = new QComboBox(centralwidget);
        selectLineDrawAlgo->addItem(QString());
        selectLineDrawAlgo->addItem(QString());
        selectLineDrawAlgo->setObjectName(QString::fromUtf8("selectLineDrawAlgo"));
        selectLineDrawAlgo->setGeometry(QRect(720, 370, 281, 41));
        selectLineDrawAlgo->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);\n"
"selection-background-color: rgb(22, 27, 34);"));
        unsetPoint2 = new QPushButton(centralwidget);
        unsetPoint2->setObjectName(QString::fromUtf8("unsetPoint2"));
        unsetPoint2->setGeometry(QRect(850, 310, 141, 30));
        unsetPoint2->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        unsetPoint1 = new QPushButton(centralwidget);
        unsetPoint1->setObjectName(QString::fromUtf8("unsetPoint1"));
        unsetPoint1->setGeometry(QRect(710, 310, 131, 30));
        unsetPoint1->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        selectLineDrawAlgoLabel = new QLabel(centralwidget);
        selectLineDrawAlgoLabel->setObjectName(QString::fromUtf8("selectLineDrawAlgoLabel"));
        selectLineDrawAlgoLabel->setGeometry(QRect(730, 340, 201, 21));
        selectLineDrawAlgoLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        drawLine = new QPushButton(centralwidget);
        drawLine->setObjectName(QString::fromUtf8("drawLine"));
        drawLine->setGeometry(QRect(720, 420, 281, 31));
        drawLine->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        timeElapsedLine = new QLabel(centralwidget);
        timeElapsedLine->setObjectName(QString::fromUtf8("timeElapsedLine"));
        timeElapsedLine->setGeometry(QRect(810, 240, 181, 31));
        timeElapsedLine->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(0, 0, 0);"));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(1300, -60, 20, 1021));
        line->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        circleDrawingLabel = new QLabel(centralwidget);
        circleDrawingLabel->setObjectName(QString::fromUtf8("circleDrawingLabel"));
        circleDrawingLabel->setGeometry(QRect(40, 720, 41, 31));
        circleDrawingLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        selectCircleDrawAlgo = new QComboBox(centralwidget);
        selectCircleDrawAlgo->addItem(QString());
        selectCircleDrawAlgo->addItem(QString());
        selectCircleDrawAlgo->addItem(QString());
        selectCircleDrawAlgo->setObjectName(QString::fromUtf8("selectCircleDrawAlgo"));
        selectCircleDrawAlgo->setGeometry(QRect(600, 720, 111, 41));
        selectCircleDrawAlgo->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);\n"
"selection-background-color:  rgb(22, 27, 34);"));
        selectCircleDrawAlgoLabel = new QLabel(centralwidget);
        selectCircleDrawAlgoLabel->setObjectName(QString::fromUtf8("selectCircleDrawAlgoLabel"));
        selectCircleDrawAlgoLabel->setGeometry(QRect(480, 730, 101, 21));
        selectCircleDrawAlgoLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        timeElapsedCircle = new QLabel(centralwidget);
        timeElapsedCircle->setObjectName(QString::fromUtf8("timeElapsedCircle"));
        timeElapsedCircle->setGeometry(QRect(100, 720, 71, 31));
        timeElapsedCircle->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(0, 0, 0);"));
        radius = new QSpinBox(centralwidget);
        radius->setObjectName(QString::fromUtf8("radius"));
        radius->setGeometry(QRect(410, 730, 61, 21));
        radius->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        setCentre = new QPushButton(centralwidget);
        setCentre->setObjectName(QString::fromUtf8("setCentre"));
        setCentre->setGeometry(QRect(180, 720, 71, 30));
        setCentre->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        unsetCentre = new QPushButton(centralwidget);
        unsetCentre->setObjectName(QString::fromUtf8("unsetCentre"));
        unsetCentre->setGeometry(QRect(250, 720, 61, 30));
        unsetCentre->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        radiusLabel = new QLabel(centralwidget);
        radiusLabel->setObjectName(QString::fromUtf8("radiusLabel"));
        radiusLabel->setGeometry(QRect(320, 730, 71, 16));
        radiusLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(710, 240, 16, 31));
        checkBox->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        checkBoxCircle = new QCheckBox(centralwidget);
        checkBoxCircle->setObjectName(QString::fromUtf8("checkBoxCircle"));
        checkBoxCircle->setGeometry(QRect(10, 720, 21, 31));
        drawCircle = new QPushButton(centralwidget);
        drawCircle->setObjectName(QString::fromUtf8("drawCircle"));
        drawCircle->setGeometry(QRect(720, 730, 141, 31));
        drawCircle->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        mouseMovementLabel = new QLabel(centralwidget);
        mouseMovementLabel->setObjectName(QString::fromUtf8("mouseMovementLabel"));
        mouseMovementLabel->setGeometry(QRect(720, 80, 281, 31));
        mouseMovementLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        mouseMovement = new QLabel(centralwidget);
        mouseMovement->setObjectName(QString::fromUtf8("mouseMovement"));
        mouseMovement->setGeometry(QRect(720, 110, 281, 16));
        mouseMovement->setAutoFillBackground(false);
        mouseMovement->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"border-color: rgb(178, 192, 206);"));
        mouseMovement->setFrameShape(QFrame::Box);
        mousePressedLabel = new QLabel(centralwidget);
        mousePressedLabel->setObjectName(QString::fromUtf8("mousePressedLabel"));
        mousePressedLabel->setGeometry(QRect(720, 130, 281, 21));
        mousePressedLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
""));
        mousePressed = new QLabel(centralwidget);
        mousePressed->setObjectName(QString::fromUtf8("mousePressed"));
        mousePressed->setGeometry(QRect(720, 170, 281, 16));
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
        checkBoxEllipse->setGeometry(QRect(720, 480, 21, 31));
        ellipseDrawingLabel = new QLabel(centralwidget);
        ellipseDrawingLabel->setObjectName(QString::fromUtf8("ellipseDrawingLabel"));
        ellipseDrawingLabel->setGeometry(QRect(740, 480, 71, 31));
        ellipseDrawingLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        timeElapsedEllipse = new QLabel(centralwidget);
        timeElapsedEllipse->setObjectName(QString::fromUtf8("timeElapsedEllipse"));
        timeElapsedEllipse->setGeometry(QRect(820, 480, 181, 31));
        timeElapsedEllipse->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(0, 0, 0);"));
        ry = new QSpinBox(centralwidget);
        ry->setObjectName(QString::fromUtf8("ry"));
        ry->setGeometry(QRect(860, 540, 141, 31));
        ry->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        rx = new QSpinBox(centralwidget);
        rx->setObjectName(QString::fromUtf8("rx"));
        rx->setGeometry(QRect(720, 540, 136, 31));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(rx->sizePolicy().hasHeightForWidth());
        rx->setSizePolicy(sizePolicy);
        rx->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        rxLabel = new QLabel(centralwidget);
        rxLabel->setObjectName(QString::fromUtf8("rxLabel"));
        rxLabel->setGeometry(QRect(717, 519, 136, 21));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(rxLabel->sizePolicy().hasHeightForWidth());
        rxLabel->setSizePolicy(sizePolicy1);
        rxLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        ryLabel = new QLabel(centralwidget);
        ryLabel->setObjectName(QString::fromUtf8("ryLabel"));
        ryLabel->setGeometry(QRect(860, 519, 136, 21));
        ryLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        selectEllipseDrawAlgo = new QComboBox(centralwidget);
        selectEllipseDrawAlgo->addItem(QString());
        selectEllipseDrawAlgo->setObjectName(QString::fromUtf8("selectEllipseDrawAlgo"));
        selectEllipseDrawAlgo->setGeometry(QRect(720, 610, 281, 41));
        selectEllipseDrawAlgo->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);\n"
"selection-background-color:  rgb(22, 27, 34);"));
        drawEllipse = new QPushButton(centralwidget);
        drawEllipse->setObjectName(QString::fromUtf8("drawEllipse"));
        drawEllipse->setGeometry(QRect(720, 660, 281, 31));
        drawEllipse->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        unsetCentreEllipse = new QPushButton(centralwidget);
        unsetCentreEllipse->setObjectName(QString::fromUtf8("unsetCentreEllipse"));
        unsetCentreEllipse->setGeometry(QRect(860, 580, 141, 30));
        unsetCentreEllipse->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        setCentreEllipse = new QPushButton(centralwidget);
        setCentreEllipse->setObjectName(QString::fromUtf8("setCentreEllipse"));
        setCentreEllipse->setGeometry(QRect(720, 580, 131, 30));
        setCentreEllipse->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        checkBoxPolygon = new QCheckBox(centralwidget);
        checkBoxPolygon->setObjectName(QString::fromUtf8("checkBoxPolygon"));
        checkBoxPolygon->setGeometry(QRect(1020, 30, 21, 31));
        polyDrawingLabel = new QLabel(centralwidget);
        polyDrawingLabel->setObjectName(QString::fromUtf8("polyDrawingLabel"));
        polyDrawingLabel->setGeometry(QRect(1040, 30, 81, 31));
        polyDrawingLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        addPointPoly = new QPushButton(centralwidget);
        addPointPoly->setObjectName(QString::fromUtf8("addPointPoly"));
        addPointPoly->setGeometry(QRect(1010, 70, 101, 30));
        addPointPoly->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        RemovePointPoly = new QPushButton(centralwidget);
        RemovePointPoly->setObjectName(QString::fromUtf8("RemovePointPoly"));
        RemovePointPoly->setGeometry(QRect(1120, 70, 131, 30));
        RemovePointPoly->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        drawPolygon = new QPushButton(centralwidget);
        drawPolygon->setObjectName(QString::fromUtf8("drawPolygon"));
        drawPolygon->setGeometry(QRect(1010, 110, 231, 31));
        drawPolygon->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        checkBoxFill = new QCheckBox(centralwidget);
        checkBoxFill->setObjectName(QString::fromUtf8("checkBoxFill"));
        checkBoxFill->setGeometry(QRect(1280, 20, 21, 31));
        FillLabel = new QLabel(centralwidget);
        FillLabel->setObjectName(QString::fromUtf8("FillLabel"));
        FillLabel->setGeometry(QRect(1320, 20, 81, 31));
        FillLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        boundaryFill = new QPushButton(centralwidget);
        boundaryFill->setObjectName(QString::fromUtf8("boundaryFill"));
        boundaryFill->setGeometry(QRect(1290, 60, 111, 31));
        boundaryFill->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        floodFill = new QPushButton(centralwidget);
        floodFill->setObjectName(QString::fromUtf8("floodFill"));
        floodFill->setGeometry(QRect(1290, 100, 121, 31));
        floodFill->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        ScanLineFill = new QPushButton(centralwidget);
        ScanLineFill->setObjectName(QString::fromUtf8("ScanLineFill"));
        ScanLineFill->setGeometry(QRect(1290, 140, 131, 31));
        ScanLineFill->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        scale = new QPushButton(centralwidget);
        scale->setObjectName(QString::fromUtf8("scale"));
        scale->setGeometry(QRect(1180, 200, 141, 31));
        scale->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        scale_x = new QSpinBox(centralwidget);
        scale_x->setObjectName(QString::fromUtf8("scale_x"));
        scale_x->setGeometry(QRect(1020, 200, 71, 21));
        sizePolicy.setHeightForWidth(scale_x->sizePolicy().hasHeightForWidth());
        scale_x->setSizePolicy(sizePolicy);
        scale_x->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        scale_x->setMinimum(-250);
        scale_x->setMaximum(250);
        scale_x->setValue(0);
        scale_y = new QSpinBox(centralwidget);
        scale_y->setObjectName(QString::fromUtf8("scale_y"));
        scale_y->setGeometry(QRect(1110, 200, 61, 21));
        sizePolicy.setHeightForWidth(scale_y->sizePolicy().hasHeightForWidth());
        scale_y->setSizePolicy(sizePolicy);
        scale_y->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        scale_y->setMinimum(-250);
        scale_y->setMaximum(250);
        scale_y->setValue(0);
        scaleXLabel = new QLabel(centralwidget);
        scaleXLabel->setObjectName(QString::fromUtf8("scaleXLabel"));
        scaleXLabel->setGeometry(QRect(1020, 180, 51, 16));
        scaleXLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        scaleYLabel = new QLabel(centralwidget);
        scaleYLabel->setObjectName(QString::fromUtf8("scaleYLabel"));
        scaleYLabel->setGeometry(QRect(1110, 180, 51, 16));
        scaleYLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        scaleLabel = new QLabel(centralwidget);
        scaleLabel->setObjectName(QString::fromUtf8("scaleLabel"));
        scaleLabel->setGeometry(QRect(1020, 150, 231, 21));
        scaleLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        transX = new QLabel(centralwidget);
        transX->setObjectName(QString::fromUtf8("transX"));
        transX->setGeometry(QRect(1020, 250, 31, 16));
        transX->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        tX = new QSpinBox(centralwidget);
        tX->setObjectName(QString::fromUtf8("tX"));
        tX->setGeometry(QRect(1020, 280, 71, 21));
        sizePolicy.setHeightForWidth(tX->sizePolicy().hasHeightForWidth());
        tX->setSizePolicy(sizePolicy);
        tX->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        tX->setMinimum(-50);
        tX->setMaximum(50);
        tY = new QSpinBox(centralwidget);
        tY->setObjectName(QString::fromUtf8("tY"));
        tY->setGeometry(QRect(1110, 280, 61, 21));
        sizePolicy.setHeightForWidth(tY->sizePolicy().hasHeightForWidth());
        tY->setSizePolicy(sizePolicy);
        tY->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        tY->setMinimum(-50);
        tY->setMaximum(50);
        transY = new QLabel(centralwidget);
        transY->setObjectName(QString::fromUtf8("transY"));
        transY->setGeometry(QRect(1110, 250, 21, 16));
        transY->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        translate = new QPushButton(centralwidget);
        translate->setObjectName(QString::fromUtf8("translate"));
        translate->setGeometry(QRect(1180, 270, 141, 31));
        translate->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        transLabel = new QLabel(centralwidget);
        transLabel->setObjectName(QString::fromUtf8("transLabel"));
        transLabel->setGeometry(QRect(1020, 230, 211, 16));
        transLabel->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);"));
        rotate = new QPushButton(centralwidget);
        rotate->setObjectName(QString::fromUtf8("rotate"));
        rotate->setGeometry(QRect(1020, 390, 71, 32));
        rotateAngleLabel = new QLabel(centralwidget);
        rotateAngleLabel->setObjectName(QString::fromUtf8("rotateAngleLabel"));
        rotateAngleLabel->setGeometry(QRect(1110, 390, 58, 16));
        rotdeg = new QSpinBox(centralwidget);
        rotdeg->setObjectName(QString::fromUtf8("rotdeg"));
        rotdeg->setGeometry(QRect(1200, 390, 71, 21));
        sizePolicy.setHeightForWidth(rotdeg->sizePolicy().hasHeightForWidth());
        rotdeg->setSizePolicy(sizePolicy);
        rotdeg->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        rotdeg->setMinimum(-180);
        rotdeg->setMaximum(180);
        reflect = new QPushButton(centralwidget);
        reflect->setObjectName(QString::fromUtf8("reflect"));
        reflect->setGeometry(QRect(1020, 430, 231, 32));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1020, 310, 151, 16));
        shearX = new QLabel(centralwidget);
        shearX->setObjectName(QString::fromUtf8("shearX"));
        shearX->setGeometry(QRect(1020, 330, 41, 16));
        lshearY = new QLabel(centralwidget);
        lshearY->setObjectName(QString::fromUtf8("lshearY"));
        lshearY->setGeometry(QRect(1110, 330, 41, 16));
        sh_X = new QSpinBox(centralwidget);
        sh_X->setObjectName(QString::fromUtf8("sh_X"));
        sh_X->setGeometry(QRect(1030, 360, 42, 22));
        sh_X->setMinimum(-200);
        sh_X->setMaximum(200);
        sh_Y = new QSpinBox(centralwidget);
        sh_Y->setObjectName(QString::fromUtf8("sh_Y"));
        sh_Y->setGeometry(QRect(1110, 360, 42, 22));
        sh_Y->setMinimum(-200);
        sh_Y->setMaximum(200);
        shear = new QPushButton(centralwidget);
        shear->setObjectName(QString::fromUtf8("shear"));
        shear->setGeometry(QRect(1180, 350, 141, 31));
        shear->setStyleSheet(QString::fromUtf8("color: rgb(178, 192, 206);\n"
"background-color: rgb(22, 27, 34);"));
        x_max = new QSpinBox(centralwidget);
        x_max->setObjectName(QString::fromUtf8("x_max"));
        x_max->setGeometry(QRect(1080, 480, 46, 20));
        x_max->setMinimum(-20);
        x_max->setMaximum(40);
        y_min = new QSpinBox(centralwidget);
        y_min->setObjectName(QString::fromUtf8("y_min"));
        y_min->setGeometry(QRect(1190, 510, 46, 20));
        y_min->setMinimum(-20);
        y_min->setMaximum(40);
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(1150, 510, 41, 20));
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(1040, 510, 41, 20));
        x_min = new QSpinBox(centralwidget);
        x_min->setObjectName(QString::fromUtf8("x_min"));
        x_min->setGeometry(QRect(1190, 480, 46, 20));
        x_min->setMinimum(-20);
        x_min->setMaximum(40);
        y_max = new QSpinBox(centralwidget);
        y_max->setObjectName(QString::fromUtf8("y_max"));
        y_max->setGeometry(QRect(1080, 510, 46, 20));
        y_max->setMinimum(-20);
        y_max->setMaximum(40);
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(1150, 480, 41, 20));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(1040, 480, 41, 20));
        clip_line = new QPushButton(centralwidget);
        clip_line->setObjectName(QString::fromUtf8("clip_line"));
        clip_line->setGeometry(QRect(1030, 600, 81, 31));
        clr_bound = new QPushButton(centralwidget);
        clr_bound->setObjectName(QString::fromUtf8("clr_bound"));
        clr_bound->setGeometry(QRect(1020, 550, 121, 31));
        set_bound = new QPushButton(centralwidget);
        set_bound->setObjectName(QString::fromUtf8("set_bound"));
        set_bound->setGeometry(QRect(1150, 550, 131, 31));
        clip_poly = new QPushButton(centralwidget);
        clip_poly->setObjectName(QString::fromUtf8("clip_poly"));
        clip_poly->setGeometry(QRect(1130, 600, 121, 31));
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
        selectCircleDrawAlgo->setItemText(0, QCoreApplication::translate("MainWindow", "Bresenham's Mid-point Circle Algorithm", nullptr));
        selectCircleDrawAlgo->setItemText(1, QCoreApplication::translate("MainWindow", "Polar Circle Algorithm", nullptr));
        selectCircleDrawAlgo->setItemText(2, QCoreApplication::translate("MainWindow", "Parametric Circle Algorithm", nullptr));

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
        scale->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        scaleXLabel->setText(QCoreApplication::translate("MainWindow", "X Factor", nullptr));
        scaleYLabel->setText(QCoreApplication::translate("MainWindow", "Y Factor", nullptr));
        scaleLabel->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        transX->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        transY->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        translate->setText(QCoreApplication::translate("MainWindow", "Translate", nullptr));
        transLabel->setText(QCoreApplication::translate("MainWindow", "Translate", nullptr));
        rotate->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        rotateAngleLabel->setText(QCoreApplication::translate("MainWindow", "angle", nullptr));
        reflect->setText(QCoreApplication::translate("MainWindow", "Reflect About Last line drawn", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Shear", nullptr));
        shearX->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        lshearY->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        shear->setText(QCoreApplication::translate("MainWindow", "Shear", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "y_min:", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "y_max:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "x_min:", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "x_max:", nullptr));
        clip_line->setText(QCoreApplication::translate("MainWindow", "Clip Line", nullptr));
        clr_bound->setText(QCoreApplication::translate("MainWindow", "Clear Boundary", nullptr));
        set_bound->setText(QCoreApplication::translate("MainWindow", "Draw Boundary", nullptr));
        clip_poly->setText(QCoreApplication::translate("MainWindow", "Clip Polygon", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
