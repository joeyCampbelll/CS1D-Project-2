/********************************************************************************
** Form generated from reading UI file 'tableview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEVIEW_H
#define UI_TABLEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tableview
{
public:

    void setupUi(QWidget *tableview)
    {
        if (tableview->objectName().isEmpty())
            tableview->setObjectName(QString::fromUtf8("tableview"));
        tableview->resize(400, 300);

        retranslateUi(tableview);

        QMetaObject::connectSlotsByName(tableview);
    } // setupUi

    void retranslateUi(QWidget *tableview)
    {
        tableview->setWindowTitle(QCoreApplication::translate("tableview", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tableview: public Ui_tableview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEVIEW_H
