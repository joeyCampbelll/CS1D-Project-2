/********************************************************************************
** Form generated from reading UI file 'tablefilter.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEFILTER_H
#define UI_TABLEFILTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tablefilter
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *tablefilter)
    {
        if (tablefilter->objectName().isEmpty())
            tablefilter->setObjectName(QString::fromUtf8("tablefilter"));
        tablefilter->resize(413, 484);
        pushButton = new QPushButton(tablefilter);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 240, 80, 25));

        retranslateUi(tablefilter);

        QMetaObject::connectSlotsByName(tablefilter);
    } // setupUi

    void retranslateUi(QWidget *tablefilter)
    {
        tablefilter->setWindowTitle(QCoreApplication::translate("tablefilter", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("tablefilter", "test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tablefilter: public Ui_tablefilter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEFILTER_H
