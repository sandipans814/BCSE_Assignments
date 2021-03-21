/********************************************************************************
** Form generated from reading UI file 'displayall.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYALL_H
#define UI_DISPLAYALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DisplayAll
{
public:
    QGridLayout *gridLayout;
    QPushButton *previous;
    QLabel *displayArea;
    QPushButton *next;

    void setupUi(QDialog *DisplayAll)
    {
        if (DisplayAll->objectName().isEmpty())
            DisplayAll->setObjectName(QString::fromUtf8("DisplayAll"));
        DisplayAll->resize(596, 161);
        gridLayout = new QGridLayout(DisplayAll);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        previous = new QPushButton(DisplayAll);
        previous->setObjectName(QString::fromUtf8("previous"));

        gridLayout->addWidget(previous, 1, 0, 1, 1);

        displayArea = new QLabel(DisplayAll);
        displayArea->setObjectName(QString::fromUtf8("displayArea"));

        gridLayout->addWidget(displayArea, 0, 0, 1, 2);

        next = new QPushButton(DisplayAll);
        next->setObjectName(QString::fromUtf8("next"));

        gridLayout->addWidget(next, 1, 1, 1, 1);


        retranslateUi(DisplayAll);

        QMetaObject::connectSlotsByName(DisplayAll);
    } // setupUi

    void retranslateUi(QDialog *DisplayAll)
    {
        DisplayAll->setWindowTitle(QCoreApplication::translate("DisplayAll", "Dialog", nullptr));
        previous->setText(QCoreApplication::translate("DisplayAll", "Previous", nullptr));
        displayArea->setText(QCoreApplication::translate("DisplayAll", "TextLabel", nullptr));
        next->setText(QCoreApplication::translate("DisplayAll", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DisplayAll: public Ui_DisplayAll {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYALL_H
