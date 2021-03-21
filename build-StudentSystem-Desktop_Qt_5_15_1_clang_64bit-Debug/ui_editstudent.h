/********************************************************************************
** Form generated from reading UI file 'editstudent.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITSTUDENT_H
#define UI_EDITSTUDENT_H

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

class Ui_EditStudent
{
public:
    QFormLayout *formLayout;
    QLabel *nameLabel;
    QLineEdit *name;
    QLabel *deptLabel;
    QComboBox *depts;
    QLabel *phoneLabel;
    QLineEdit *phone;
    QLabel *addressLabel;
    QTextEdit *address;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *EditStudent)
    {
        if (EditStudent->objectName().isEmpty())
            EditStudent->setObjectName(QString::fromUtf8("EditStudent"));
        EditStudent->resize(600, 400);
        formLayout = new QFormLayout(EditStudent);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        nameLabel = new QLabel(EditStudent);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, nameLabel);

        name = new QLineEdit(EditStudent);
        name->setObjectName(QString::fromUtf8("name"));

        formLayout->setWidget(0, QFormLayout::FieldRole, name);

        deptLabel = new QLabel(EditStudent);
        deptLabel->setObjectName(QString::fromUtf8("deptLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, deptLabel);

        depts = new QComboBox(EditStudent);
        depts->setObjectName(QString::fromUtf8("depts"));

        formLayout->setWidget(1, QFormLayout::FieldRole, depts);

        phoneLabel = new QLabel(EditStudent);
        phoneLabel->setObjectName(QString::fromUtf8("phoneLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, phoneLabel);

        phone = new QLineEdit(EditStudent);
        phone->setObjectName(QString::fromUtf8("phone"));

        formLayout->setWidget(2, QFormLayout::FieldRole, phone);

        addressLabel = new QLabel(EditStudent);
        addressLabel->setObjectName(QString::fromUtf8("addressLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, addressLabel);

        address = new QTextEdit(EditStudent);
        address->setObjectName(QString::fromUtf8("address"));

        formLayout->setWidget(3, QFormLayout::FieldRole, address);

        buttonBox = new QDialogButtonBox(EditStudent);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(4, QFormLayout::SpanningRole, buttonBox);


        retranslateUi(EditStudent);

        QMetaObject::connectSlotsByName(EditStudent);
    } // setupUi

    void retranslateUi(QDialog *EditStudent)
    {
        EditStudent->setWindowTitle(QCoreApplication::translate("EditStudent", "Dialog", nullptr));
        nameLabel->setText(QCoreApplication::translate("EditStudent", "Name", nullptr));
        deptLabel->setText(QCoreApplication::translate("EditStudent", "Department", nullptr));
        phoneLabel->setText(QCoreApplication::translate("EditStudent", "Phone", nullptr));
        addressLabel->setText(QCoreApplication::translate("EditStudent", "Address", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditStudent: public Ui_EditStudent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITSTUDENT_H
