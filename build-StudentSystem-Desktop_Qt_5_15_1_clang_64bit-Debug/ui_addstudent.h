/********************************************************************************
** Form generated from reading UI file 'addstudent.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTUDENT_H
#define UI_ADDSTUDENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AddStudent
{
public:
    QFormLayout *formLayout_2;
    QLabel *nameLabel;
    QLineEdit *name;
    QLabel *rollLabel;
    QLineEdit *roll;
    QLabel *deptLabel;
    QComboBox *depts;
    QLabel *addressLabel;
    QTextEdit *address;
    QLabel *phoneLabel;
    QLineEdit *phone;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddStudent)
    {
        if (AddStudent->objectName().isEmpty())
            AddStudent->setObjectName(QString::fromUtf8("AddStudent"));
        AddStudent->resize(600, 400);
        formLayout_2 = new QFormLayout(AddStudent);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        nameLabel = new QLabel(AddStudent);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, nameLabel);

        name = new QLineEdit(AddStudent);
        name->setObjectName(QString::fromUtf8("name"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, name);

        rollLabel = new QLabel(AddStudent);
        rollLabel->setObjectName(QString::fromUtf8("rollLabel"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, rollLabel);

        roll = new QLineEdit(AddStudent);
        roll->setObjectName(QString::fromUtf8("roll"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, roll);

        deptLabel = new QLabel(AddStudent);
        deptLabel->setObjectName(QString::fromUtf8("deptLabel"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, deptLabel);

        depts = new QComboBox(AddStudent);
        depts->setObjectName(QString::fromUtf8("depts"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, depts);

        addressLabel = new QLabel(AddStudent);
        addressLabel->setObjectName(QString::fromUtf8("addressLabel"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, addressLabel);

        address = new QTextEdit(AddStudent);
        address->setObjectName(QString::fromUtf8("address"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, address);

        phoneLabel = new QLabel(AddStudent);
        phoneLabel->setObjectName(QString::fromUtf8("phoneLabel"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, phoneLabel);

        phone = new QLineEdit(AddStudent);
        phone->setObjectName(QString::fromUtf8("phone"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, phone);

        buttonBox = new QDialogButtonBox(AddStudent);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout_2->setWidget(5, QFormLayout::FieldRole, buttonBox);


        retranslateUi(AddStudent);

        QMetaObject::connectSlotsByName(AddStudent);
    } // setupUi

    void retranslateUi(QDialog *AddStudent)
    {
        AddStudent->setWindowTitle(QCoreApplication::translate("AddStudent", "Dialog", nullptr));
        nameLabel->setText(QCoreApplication::translate("AddStudent", "Name", nullptr));
        rollLabel->setText(QCoreApplication::translate("AddStudent", "Roll", nullptr));
        deptLabel->setText(QCoreApplication::translate("AddStudent", "Department", nullptr));
        addressLabel->setText(QCoreApplication::translate("AddStudent", "Address", nullptr));
        phoneLabel->setText(QCoreApplication::translate("AddStudent", "Phone Number", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddStudent: public Ui_AddStudent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTUDENT_H
