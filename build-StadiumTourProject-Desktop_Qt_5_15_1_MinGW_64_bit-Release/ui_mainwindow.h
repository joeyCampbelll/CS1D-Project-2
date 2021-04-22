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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLogin;
    QAction *actionLogin_2;
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *mainPage;
    QPushButton *adminButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QLabel *mainTitle;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *dfsBfsButton;
    QPushButton *buildTripButton;
    QPushButton *tableButton;
    QWidget *tableViewPage;
    QTableView *mlbTableView;
    QPushButton *viewFiltersButton;
    QWidget *adminLoginPage;
    QLabel *label_3;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_login;
    QLabel *label_2;
    QLineEdit *lineEdit_password;
    QLabel *label;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 500);
        actionLogin = new QAction(MainWindow);
        actionLogin->setObjectName(QString::fromUtf8("actionLogin"));
        actionLogin_2 = new QAction(MainWindow);
        actionLogin_2->setObjectName(QString::fromUtf8("actionLogin_2"));
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
        mainTitle = new QLabel(layoutWidget);
        mainTitle->setObjectName(QString::fromUtf8("mainTitle"));

        verticalLayout_4->addWidget(mainTitle);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        dfsBfsButton = new QPushButton(layoutWidget);
        dfsBfsButton->setObjectName(QString::fromUtf8("dfsBfsButton"));
        dfsBfsButton->setFont(font);

        horizontalLayout_3->addWidget(dfsBfsButton);

        buildTripButton = new QPushButton(layoutWidget);
        buildTripButton->setObjectName(QString::fromUtf8("buildTripButton"));
        buildTripButton->setFont(font);

        horizontalLayout_3->addWidget(buildTripButton);

        tableButton = new QPushButton(layoutWidget);
        tableButton->setObjectName(QString::fromUtf8("tableButton"));
        tableButton->setFont(font);

        horizontalLayout_3->addWidget(tableButton);


        verticalLayout_4->addLayout(horizontalLayout_3);

        stackedWidget->addWidget(mainPage);
        tableViewPage = new QWidget();
        tableViewPage->setObjectName(QString::fromUtf8("tableViewPage"));
        mlbTableView = new QTableView(tableViewPage);
        mlbTableView->setObjectName(QString::fromUtf8("mlbTableView"));
        mlbTableView->setGeometry(QRect(10, 90, 781, 371));
        viewFiltersButton = new QPushButton(tableViewPage);
        viewFiltersButton->setObjectName(QString::fromUtf8("viewFiltersButton"));
        viewFiltersButton->setGeometry(QRect(335, 50, 131, 27));
        viewFiltersButton->setFont(font);
        stackedWidget->addWidget(tableViewPage);
        adminLoginPage = new QWidget();
        adminLoginPage->setObjectName(QString::fromUtf8("adminLoginPage"));
        label_3 = new QLabel(adminLoginPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(4, 207, 791, 20));
        label_3->setFont(font);
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAlignment(Qt::AlignCenter);
        pushButton_cancel = new QPushButton(adminLoginPage);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(404, 280, 101, 41));
        pushButton_login = new QPushButton(adminLoginPage);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        pushButton_login->setGeometry(QRect(294, 280, 101, 41));
        label_2 = new QLabel(adminLoginPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(594, 177, 611, 20));
        label_2->setFont(font);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignCenter);
        lineEdit_password = new QLineEdit(adminLoginPage);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(294, 240, 211, 31));
        lineEdit_password->setEchoMode(QLineEdit::Password);
        label = new QLabel(adminLoginPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 60, 791, 51));
        QFont font1;
        font1.setPointSize(22);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setKerning(true);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(adminLoginPage);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionLogin->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        actionLogin_2->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        adminButton->setText(QCoreApplication::translate("MainWindow", "Admin Access", nullptr));
        mainTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:600;\">Stadium Tour Project</span></p><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">by Scrum and Coke</span></p></body></html>", nullptr));
        dfsBfsButton->setText(QCoreApplication::translate("MainWindow", "DFS and BFS", nullptr));
        buildTripButton->setText(QCoreApplication::translate("MainWindow", "Build Trip", nullptr));
        tableButton->setText(QCoreApplication::translate("MainWindow", "View Data", nullptr));
        viewFiltersButton->setText(QCoreApplication::translate("MainWindow", "View Filters", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Please Enter:", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        pushButton_login->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Please Enter:", nullptr));
        lineEdit_password->setText(QString());
        lineEdit_password->setPlaceholderText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Administrator Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
