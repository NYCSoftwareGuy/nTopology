/********************************************************************************
** Form generated from reading UI file 'EdNewTextDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDNEWTEXTDIALOG_H
#define UI_EDNEWTEXTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EdNewTextDialog
{
public:
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QLabel *label01;
    QLineEdit *editNewText;

    void setupUi(QDialog *EdNewTextDialog)
    {
        if (EdNewTextDialog->objectName().isEmpty())
            EdNewTextDialog->setObjectName(QString::fromUtf8("EdNewTextDialog"));
        EdNewTextDialog->resize(425, 186);
        QFont font;
        font.setPointSize(10);
        EdNewTextDialog->setFont(font);
        btnOK = new QPushButton(EdNewTextDialog);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        btnOK->setGeometry(QRect(230, 140, 75, 23));
        btnCancel = new QPushButton(EdNewTextDialog);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(320, 140, 75, 23));
        label01 = new QLabel(EdNewTextDialog);
        label01->setObjectName(QString::fromUtf8("label01"));
        label01->setGeometry(QRect(20, 10, 391, 20));
        label01->setAlignment(Qt::AlignCenter);
        editNewText = new QLineEdit(EdNewTextDialog);
        editNewText->setObjectName(QString::fromUtf8("editNewText"));
        editNewText->setGeometry(QRect(20, 50, 381, 21));

        retranslateUi(EdNewTextDialog);

        QMetaObject::connectSlotsByName(EdNewTextDialog);
    } // setupUi

    void retranslateUi(QDialog *EdNewTextDialog)
    {
        EdNewTextDialog->setWindowTitle(QApplication::translate("EdNewTextDialog", "Dialog", nullptr));
        btnOK->setText(QApplication::translate("EdNewTextDialog", "OK", nullptr));
        btnCancel->setText(QApplication::translate("EdNewTextDialog", "Cancel", nullptr));
        label01->setText(QApplication::translate("EdNewTextDialog", "Type In New Text for Node Name:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EdNewTextDialog: public Ui_EdNewTextDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDNEWTEXTDIALOG_H
