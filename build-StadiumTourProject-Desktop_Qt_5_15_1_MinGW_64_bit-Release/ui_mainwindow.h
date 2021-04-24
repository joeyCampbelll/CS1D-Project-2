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
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeView>
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
    QPushButton *restoreTableButton;
    QPushButton *exitTableViewButton;
    QWidget *adminLoginPage;
    QLabel *label_3;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_login;
    QLabel *label_2;
    QLineEdit *lineEdit_password;
    QLabel *label;
    QWidget *AdminStadiumsPage;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QTreeView *treeView1;
    QListView *fileView1;
    QTableWidget *fileTable;
    QLabel *ErrorLabel;
    QLabel *label_4;
    QPushButton *addButt;
    QPushButton *pushButton_cancel_2;
    QWidget *AdminDistancesPage;
    QLabel *label_5;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_2;
    QTreeView *FileSelector;
    QListView *FileView;
    QLabel *labelError;
    QTableWidget *DistanceTableWidget;
    QPushButton *pushButton_addDistances;
    QPushButton *pushButton_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 583);
        actionLogin = new QAction(MainWindow);
        actionLogin->setObjectName(QString::fromUtf8("actionLogin"));
        actionLogin_2 = new QAction(MainWindow);
        actionLogin_2->setObjectName(QString::fromUtf8("actionLogin_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 801, 551));
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
        viewFiltersButton->setGeometry(QRect(255, 50, 131, 27));
        viewFiltersButton->setFont(font);
        restoreTableButton = new QPushButton(tableViewPage);
        restoreTableButton->setObjectName(QString::fromUtf8("restoreTableButton"));
        restoreTableButton->setGeometry(QRect(390, 50, 151, 27));
        restoreTableButton->setFont(font);
        exitTableViewButton = new QPushButton(tableViewPage);
        exitTableViewButton->setObjectName(QString::fromUtf8("exitTableViewButton"));
        exitTableViewButton->setGeometry(QRect(10, 50, 71, 27));
        exitTableViewButton->setFont(font);
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
        AdminStadiumsPage = new QWidget();
        AdminStadiumsPage->setObjectName(QString::fromUtf8("AdminStadiumsPage"));
        layoutWidget_2 = new QWidget(AdminStadiumsPage);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 20, 781, 201));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        treeView1 = new QTreeView(layoutWidget_2);
        treeView1->setObjectName(QString::fromUtf8("treeView1"));

        horizontalLayout->addWidget(treeView1);

        fileView1 = new QListView(layoutWidget_2);
        fileView1->setObjectName(QString::fromUtf8("fileView1"));

        horizontalLayout->addWidget(fileView1);

        fileTable = new QTableWidget(AdminStadiumsPage);
        fileTable->setObjectName(QString::fromUtf8("fileTable"));
        fileTable->setGeometry(QRect(10, 250, 781, 171));
        fileTable->setAutoFillBackground(true);
        fileTable->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255)"));
        ErrorLabel = new QLabel(AdminStadiumsPage);
        ErrorLabel->setObjectName(QString::fromUtf8("ErrorLabel"));
        ErrorLabel->setGeometry(QRect(10, 220, 781, 31));
        ErrorLabel->setAutoFillBackground(false);
        ErrorLabel->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(AdminStadiumsPage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 0, 781, 20));
        label_4->setAlignment(Qt::AlignCenter);
        addButt = new QPushButton(AdminStadiumsPage);
        addButt->setObjectName(QString::fromUtf8("addButt"));
        addButt->setGeometry(QRect(270, 430, 121, 31));
        addButt->setAutoFillBackground(false);
        addButt->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255)"));
        pushButton_cancel_2 = new QPushButton(AdminStadiumsPage);
        pushButton_cancel_2->setObjectName(QString::fromUtf8("pushButton_cancel_2"));
        pushButton_cancel_2->setGeometry(QRect(420, 430, 121, 31));
        pushButton_cancel_2->setAutoFillBackground(false);
        pushButton_cancel_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255)"));
        stackedWidget->addWidget(AdminStadiumsPage);
        AdminDistancesPage = new QWidget();
        AdminDistancesPage->setObjectName(QString::fromUtf8("AdminDistancesPage"));
        label_5 = new QLabel(AdminDistancesPage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 10, 781, 20));
        label_5->setAlignment(Qt::AlignCenter);
        layoutWidget_3 = new QWidget(AdminDistancesPage);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 30, 781, 201));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        FileSelector = new QTreeView(layoutWidget_3);
        FileSelector->setObjectName(QString::fromUtf8("FileSelector"));

        horizontalLayout_2->addWidget(FileSelector);

        FileView = new QListView(layoutWidget_3);
        FileView->setObjectName(QString::fromUtf8("FileView"));

        horizontalLayout_2->addWidget(FileView);

        labelError = new QLabel(AdminDistancesPage);
        labelError->setObjectName(QString::fromUtf8("labelError"));
        labelError->setGeometry(QRect(10, 235, 781, 21));
        labelError->setAlignment(Qt::AlignCenter);
        DistanceTableWidget = new QTableWidget(AdminDistancesPage);
        DistanceTableWidget->setObjectName(QString::fromUtf8("DistanceTableWidget"));
        DistanceTableWidget->setGeometry(QRect(10, 260, 781, 171));
        pushButton_addDistances = new QPushButton(AdminDistancesPage);
        pushButton_addDistances->setObjectName(QString::fromUtf8("pushButton_addDistances"));
        pushButton_addDistances->setGeometry(QRect(270, 440, 121, 31));
        pushButton_2 = new QPushButton(AdminDistancesPage);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(410, 440, 111, 31));
        stackedWidget->addWidget(AdminDistancesPage);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(4);


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
        restoreTableButton->setText(QCoreApplication::translate("MainWindow", "Restore Table", nullptr));
        exitTableViewButton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Please Enter:", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        pushButton_login->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Please Enter:", nullptr));
        lineEdit_password->setText(QString());
        lineEdit_password->setPlaceholderText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Administrator Login", nullptr));
        ErrorLabel->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "Please select a .CSV file below:", nullptr));
        addButt->setText(QCoreApplication::translate("MainWindow", "Add Stadium", nullptr));
        pushButton_cancel_2->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Please select a .CSV file below:", nullptr));
        labelError->setText(QString());
        pushButton_addDistances->setText(QCoreApplication::translate("MainWindow", "Add Distances", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
