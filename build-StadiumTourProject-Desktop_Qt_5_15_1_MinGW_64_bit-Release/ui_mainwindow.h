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
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *mainPage;
    QPushButton *adminButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QLabel *projectTitle_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *dfsAndBfsButton_3;
    QPushButton *tripButton_3;
    QPushButton *tableViewButton_3;
    QWidget *tableViewPage;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 500);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 801, 481));
        mainPage = new QWidget();
        mainPage->setObjectName(QString::fromUtf8("mainPage"));
        adminButton = new QPushButton(mainPage);
        adminButton->setObjectName(QString::fromUtf8("adminButton"));
        adminButton->setGeometry(QRect(630, 30, 151, 27));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        adminButton->setFont(font);
        layoutWidget = new QWidget(mainPage);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(210, 170, 381, 201));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        projectTitle_3 = new QLabel(layoutWidget);
        projectTitle_3->setObjectName(QString::fromUtf8("projectTitle_3"));

        verticalLayout_4->addWidget(projectTitle_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        dfsAndBfsButton_3 = new QPushButton(layoutWidget);
        dfsAndBfsButton_3->setObjectName(QString::fromUtf8("dfsAndBfsButton_3"));
        dfsAndBfsButton_3->setFont(font);

        horizontalLayout_3->addWidget(dfsAndBfsButton_3);

        tripButton_3 = new QPushButton(layoutWidget);
        tripButton_3->setObjectName(QString::fromUtf8("tripButton_3"));
        tripButton_3->setFont(font);

        horizontalLayout_3->addWidget(tripButton_3);

        tableViewButton_3 = new QPushButton(layoutWidget);
        tableViewButton_3->setObjectName(QString::fromUtf8("tableViewButton_3"));
        tableViewButton_3->setFont(font);

        horizontalLayout_3->addWidget(tableViewButton_3);


        verticalLayout_4->addLayout(horizontalLayout_3);

        stackedWidget->addWidget(mainPage);
        tableViewPage = new QWidget();
        tableViewPage->setObjectName(QString::fromUtf8("tableViewPage"));
        stackedWidget->addWidget(tableViewPage);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        adminButton->setText(QCoreApplication::translate("MainWindow", "Admin Access", nullptr));
        projectTitle_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:600;\">Stadium Tour Project</span></p><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">by Scrum and Coke</span></p></body></html>", nullptr));
        dfsAndBfsButton_3->setText(QCoreApplication::translate("MainWindow", "DFS and BFS", nullptr));
        tripButton_3->setText(QCoreApplication::translate("MainWindow", "Build Trip", nullptr));
        tableViewButton_3->setText(QCoreApplication::translate("MainWindow", "View Data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
