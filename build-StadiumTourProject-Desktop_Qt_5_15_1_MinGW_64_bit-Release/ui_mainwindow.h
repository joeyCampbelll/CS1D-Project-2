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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *adminButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *projectTitle;
    QHBoxLayout *horizontalLayout;
    QPushButton *dfsAndBfsButton;
    QPushButton *tripButton;
    QPushButton *tableViewButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 500);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        adminButton = new QPushButton(centralwidget);
        adminButton->setObjectName(QString::fromUtf8("adminButton"));
        adminButton->setGeometry(QRect(630, 10, 151, 27));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        adminButton->setFont(font);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(210, 160, 381, 201));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        projectTitle = new QLabel(widget);
        projectTitle->setObjectName(QString::fromUtf8("projectTitle"));

        verticalLayout_2->addWidget(projectTitle);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        dfsAndBfsButton = new QPushButton(widget);
        dfsAndBfsButton->setObjectName(QString::fromUtf8("dfsAndBfsButton"));
        dfsAndBfsButton->setFont(font);

        horizontalLayout->addWidget(dfsAndBfsButton);

        tripButton = new QPushButton(widget);
        tripButton->setObjectName(QString::fromUtf8("tripButton"));
        tripButton->setFont(font);

        horizontalLayout->addWidget(tripButton);

        tableViewButton = new QPushButton(widget);
        tableViewButton->setObjectName(QString::fromUtf8("tableViewButton"));
        tableViewButton->setFont(font);

        horizontalLayout->addWidget(tableViewButton);


        verticalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
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
        adminButton->setText(QCoreApplication::translate("MainWindow", "Admin Access", nullptr));
        projectTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:600;\">Stadium Tour Project</span></p><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">by Scrum and Coke</span></p></body></html>", nullptr));
        dfsAndBfsButton->setText(QCoreApplication::translate("MainWindow", "DFS and BFS", nullptr));
        tripButton->setText(QCoreApplication::translate("MainWindow", "Build Trip", nullptr));
        tableViewButton->setText(QCoreApplication::translate("MainWindow", "View Data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
