/********************************************************************************
** Form generated from reading UI file 'tablefilter.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEFILTER_H
#define UI_TABLEFILTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tablefilter
{
public:
    QWidget *layoutWidget;
    QFormLayout *AddEditGeneralLayout;
    QLabel *ShapesLabel;
    QComboBox *individualTeamEntry;
    QLabel *ShapeTypeLabel;
    QComboBox *sortByEntry;
    QLabel *ShapeTypeLabel_2;
    QComboBox *onlyShowEntry;
    QPushButton *exitFiltersButton;

    void setupUi(QWidget *tablefilter)
    {
        if (tablefilter->objectName().isEmpty())
            tablefilter->setObjectName(QString::fromUtf8("tablefilter"));
        tablefilter->resize(413, 484);
        layoutWidget = new QWidget(tablefilter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 160, 371, 82));
        AddEditGeneralLayout = new QFormLayout(layoutWidget);
        AddEditGeneralLayout->setObjectName(QString::fromUtf8("AddEditGeneralLayout"));
        AddEditGeneralLayout->setContentsMargins(0, 0, 0, 0);
        ShapesLabel = new QLabel(layoutWidget);
        ShapesLabel->setObjectName(QString::fromUtf8("ShapesLabel"));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        ShapesLabel->setFont(font);

        AddEditGeneralLayout->setWidget(0, QFormLayout::LabelRole, ShapesLabel);

        individualTeamEntry = new QComboBox(layoutWidget);
        individualTeamEntry->setObjectName(QString::fromUtf8("individualTeamEntry"));

        AddEditGeneralLayout->setWidget(0, QFormLayout::FieldRole, individualTeamEntry);

        ShapeTypeLabel = new QLabel(layoutWidget);
        ShapeTypeLabel->setObjectName(QString::fromUtf8("ShapeTypeLabel"));
        ShapeTypeLabel->setFont(font);

        AddEditGeneralLayout->setWidget(1, QFormLayout::LabelRole, ShapeTypeLabel);

        sortByEntry = new QComboBox(layoutWidget);
        sortByEntry->setObjectName(QString::fromUtf8("sortByEntry"));

        AddEditGeneralLayout->setWidget(1, QFormLayout::FieldRole, sortByEntry);

        ShapeTypeLabel_2 = new QLabel(layoutWidget);
        ShapeTypeLabel_2->setObjectName(QString::fromUtf8("ShapeTypeLabel_2"));
        ShapeTypeLabel_2->setFont(font);

        AddEditGeneralLayout->setWidget(2, QFormLayout::LabelRole, ShapeTypeLabel_2);

        onlyShowEntry = new QComboBox(layoutWidget);
        onlyShowEntry->setObjectName(QString::fromUtf8("onlyShowEntry"));

        AddEditGeneralLayout->setWidget(2, QFormLayout::FieldRole, onlyShowEntry);

        exitFiltersButton = new QPushButton(tablefilter);
        exitFiltersButton->setObjectName(QString::fromUtf8("exitFiltersButton"));
        exitFiltersButton->setGeometry(QRect(130, 436, 161, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        exitFiltersButton->setFont(font1);

        retranslateUi(tablefilter);

        QMetaObject::connectSlotsByName(tablefilter);
    } // setupUi

    void retranslateUi(QWidget *tablefilter)
    {
        tablefilter->setWindowTitle(QCoreApplication::translate("tablefilter", "Form", nullptr));
        ShapesLabel->setText(QCoreApplication::translate("tablefilter", "Individual Team:", nullptr));
        ShapeTypeLabel->setText(QCoreApplication::translate("tablefilter", "Sort By: ", nullptr));
        ShapeTypeLabel_2->setText(QCoreApplication::translate("tablefilter", "Only show teams...", nullptr));
        exitFiltersButton->setText(QCoreApplication::translate("tablefilter", "Apply and Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tablefilter: public Ui_tablefilter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEFILTER_H
