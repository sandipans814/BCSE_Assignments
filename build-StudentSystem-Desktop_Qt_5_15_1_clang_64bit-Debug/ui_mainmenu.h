/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *addStudent;
    QPushButton *displayAll;
    QPushButton *editStudent;
    QPushButton *deleteStudent;
    QPushButton *search;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QString::fromUtf8("MainMenu"));
        MainMenu->resize(400, 400);
        centralwidget = new QWidget(MainMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        addStudent = new QPushButton(centralwidget);
        addStudent->setObjectName(QString::fromUtf8("addStudent"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addStudent->sizePolicy().hasHeightForWidth());
        addStudent->setSizePolicy(sizePolicy);

        gridLayout->addWidget(addStudent, 0, 0, 1, 1);

        displayAll = new QPushButton(centralwidget);
        displayAll->setObjectName(QString::fromUtf8("displayAll"));
        sizePolicy.setHeightForWidth(displayAll->sizePolicy().hasHeightForWidth());
        displayAll->setSizePolicy(sizePolicy);

        gridLayout->addWidget(displayAll, 4, 0, 1, 1);

        editStudent = new QPushButton(centralwidget);
        editStudent->setObjectName(QString::fromUtf8("editStudent"));
        sizePolicy.setHeightForWidth(editStudent->sizePolicy().hasHeightForWidth());
        editStudent->setSizePolicy(sizePolicy);

        gridLayout->addWidget(editStudent, 2, 0, 1, 1);

        deleteStudent = new QPushButton(centralwidget);
        deleteStudent->setObjectName(QString::fromUtf8("deleteStudent"));
        sizePolicy.setHeightForWidth(deleteStudent->sizePolicy().hasHeightForWidth());
        deleteStudent->setSizePolicy(sizePolicy);

        gridLayout->addWidget(deleteStudent, 3, 0, 1, 1);

        search = new QPushButton(centralwidget);
        search->setObjectName(QString::fromUtf8("search"));
        sizePolicy.setHeightForWidth(search->sizePolicy().hasHeightForWidth());
        search->setSizePolicy(sizePolicy);

        gridLayout->addWidget(search, 1, 0, 1, 1);

        MainMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainMenu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 25));
        MainMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(MainMenu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainMenu->setStatusBar(statusbar);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "MainMenu", nullptr));
        addStudent->setText(QCoreApplication::translate("MainMenu", "Add Student", nullptr));
        displayAll->setText(QCoreApplication::translate("MainMenu", "Display All", nullptr));
        editStudent->setText(QCoreApplication::translate("MainMenu", "Edit Student", nullptr));
        deleteStudent->setText(QCoreApplication::translate("MainMenu", "Delete Student", nullptr));
        search->setText(QCoreApplication::translate("MainMenu", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
