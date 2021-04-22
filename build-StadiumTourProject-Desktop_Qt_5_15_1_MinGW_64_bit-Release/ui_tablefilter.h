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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tablefilter
{
public:
    QWidget *layoutWidget;
    QFormLayout *AddEditGeneralLayout;
    QLabel *ShapesLabel;
    QComboBox *individualTeamEntry;
    QLabel *ShapeIdLabel;
    QSpinBox *ShapeIdEntry;
    QLabel *ShapeTypeLabel;
    QComboBox *ShapeTypeEntry;
    QLabel *ShapeDimensionsLabel;
    QTextEdit *ShapeDimensionsEntry;
    QPushButton *exitFiltersButton;

    void setupUi(QWidget *tablefilter)
    {
        if (tablefilter->objectName().isEmpty())
            tablefilter->setObjectName(QString::fromUtf8("tablefilter"));
        tablefilter->resize(413, 484);
        layoutWidget = new QWidget(tablefilter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 354, 160));
        AddEditGeneralLayout = new QFormLayout(layoutWidget);
        AddEditGeneralLayout->setObjectName(QString::fromUtf8("AddEditGeneralLayout"));
        AddEditGeneralLayout->setContentsMargins(0, 0, 0, 0);
        ShapesLabel = new QLabel(layoutWidget);
        ShapesLabel->setObjectName(QString::fromUtf8("ShapesLabel"));

        AddEditGeneralLayout->setWidget(0, QFormLayout::LabelRole, ShapesLabel);

        individualTeamEntry = new QComboBox(layoutWidget);
        individualTeamEntry->setObjectName(QString::fromUtf8("individualTeamEntry"));

        AddEditGeneralLayout->setWidget(0, QFormLayout::FieldRole, individualTeamEntry);

        ShapeIdLabel = new QLabel(layoutWidget);
        ShapeIdLabel->setObjectName(QString::fromUtf8("ShapeIdLabel"));

        AddEditGeneralLayout->setWidget(1, QFormLayout::LabelRole, ShapeIdLabel);

        ShapeIdEntry = new QSpinBox(layoutWidget);
        ShapeIdEntry->setObjectName(QString::fromUtf8("ShapeIdEntry"));

        AddEditGeneralLayout->setWidget(1, QFormLayout::FieldRole, ShapeIdEntry);

        ShapeTypeLabel = new QLabel(layoutWidget);
        ShapeTypeLabel->setObjectName(QString::fromUtf8("ShapeTypeLabel"));

        AddEditGeneralLayout->setWidget(2, QFormLayout::LabelRole, ShapeTypeLabel);

        ShapeTypeEntry = new QComboBox(layoutWidget);
        ShapeTypeEntry->setObjectName(QString::fromUtf8("ShapeTypeEntry"));

        AddEditGeneralLayout->setWidget(2, QFormLayout::FieldRole, ShapeTypeEntry);

        ShapeDimensionsLabel = new QLabel(layoutWidget);
        ShapeDimensionsLabel->setObjectName(QString::fromUtf8("ShapeDimensionsLabel"));

        AddEditGeneralLayout->setWidget(3, QFormLayout::LabelRole, ShapeDimensionsLabel);

        ShapeDimensionsEntry = new QTextEdit(layoutWidget);
        ShapeDimensionsEntry->setObjectName(QString::fromUtf8("ShapeDimensionsEntry"));

        AddEditGeneralLayout->setWidget(3, QFormLayout::FieldRole, ShapeDimensionsEntry);

        exitFiltersButton = new QPushButton(tablefilter);
        exitFiltersButton->setObjectName(QString::fromUtf8("exitFiltersButton"));
        exitFiltersButton->setGeometry(QRect(166, 446, 81, 27));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        exitFiltersButton->setFont(font);

        retranslateUi(tablefilter);

        QMetaObject::connectSlotsByName(tablefilter);
    } // setupUi

    void retranslateUi(QWidget *tablefilter)
    {
        tablefilter->setWindowTitle(QCoreApplication::translate("tablefilter", "Form", nullptr));
        ShapesLabel->setText(QCoreApplication::translate("tablefilter", "Individual Team:", nullptr));
        ShapeIdLabel->setText(QCoreApplication::translate("tablefilter", "Shape ID:", nullptr));
        ShapeTypeLabel->setText(QCoreApplication::translate("tablefilter", "Shape Type:", nullptr));
        ShapeDimensionsLabel->setText(QCoreApplication::translate("tablefilter", "Shape Dimensions:", nullptr));
        exitFiltersButton->setText(QCoreApplication::translate("tablefilter", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tablefilter: public Ui_tablefilter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEFILTER_H
