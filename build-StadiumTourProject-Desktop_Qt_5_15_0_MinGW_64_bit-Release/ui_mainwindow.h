/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
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
    QPushButton *restoreTableButton;
    QPushButton *exitTableViewButton;
    QWidget *adminLoginPage;
    QLabel *label_3;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_login;
    QLabel *label_2;
    QLineEdit *lineEdit_password;
    QLabel *label;
    QPushButton *editSouvenirsButton;
    QWidget *souvenirEditor;
    QPushButton *addSouvenirButton;
    QPushButton *deleteSouvenirButton;
    QPushButton *editSouvenirButton;
    QTableView *souvenirTableView;
    QLabel *souvenirTitle;
    QComboBox *selectTeamBox;
    QLabel *selectTeamTitle;
    QComboBox *selectSouvenirBox;
    QLabel *selectTeamTitle_2;
    QPushButton *exitEditButton;
    QWidget *editPage;
    QPushButton *enterEditButton;
    QPushButton *cancelEditButton;
    QLabel *priceTitle;
    QLabel *updateSouvenirLabel;
    QLabel *souvenirTitle_2;
    QFrame *line;
    QLabel *teamNameTitle;
    QLabel *updateTeamLabel;
    QDoubleSpinBox *enterPriceSpinBox;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(760, 496);
        actionLogin = new QAction(MainWindow);
        actionLogin->setObjectName(QString::fromUtf8("actionLogin"));
        actionLogin_2 = new QAction(MainWindow);
        actionLogin_2->setObjectName(QString::fromUtf8("actionLogin_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(20, 0, 831, 481));
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
        editSouvenirsButton = new QPushButton(adminLoginPage);
        editSouvenirsButton->setObjectName(QString::fromUtf8("editSouvenirsButton"));
        editSouvenirsButton->setGeometry(QRect(600, 190, 80, 22));
        stackedWidget->addWidget(adminLoginPage);
        souvenirEditor = new QWidget();
        souvenirEditor->setObjectName(QString::fromUtf8("souvenirEditor"));
        addSouvenirButton = new QPushButton(souvenirEditor);
        addSouvenirButton->setObjectName(QString::fromUtf8("addSouvenirButton"));
        addSouvenirButton->setGeometry(QRect(410, 100, 111, 31));
        deleteSouvenirButton = new QPushButton(souvenirEditor);
        deleteSouvenirButton->setObjectName(QString::fromUtf8("deleteSouvenirButton"));
        deleteSouvenirButton->setGeometry(QRect(410, 240, 111, 31));
        editSouvenirButton = new QPushButton(souvenirEditor);
        editSouvenirButton->setObjectName(QString::fromUtf8("editSouvenirButton"));
        editSouvenirButton->setGeometry(QRect(410, 200, 111, 31));
        souvenirTableView = new QTableView(souvenirEditor);
        souvenirTableView->setObjectName(QString::fromUtf8("souvenirTableView"));
        souvenirTableView->setGeometry(QRect(10, 100, 371, 331));
        souvenirTitle = new QLabel(souvenirEditor);
        souvenirTitle->setObjectName(QString::fromUtf8("souvenirTitle"));
        souvenirTitle->setGeometry(QRect(240, 20, 211, 21));
        selectTeamBox = new QComboBox(souvenirEditor);
        selectTeamBox->setObjectName(QString::fromUtf8("selectTeamBox"));
        selectTeamBox->setGeometry(QRect(170, 70, 211, 22));
        selectTeamTitle = new QLabel(souvenirEditor);
        selectTeamTitle->setObjectName(QString::fromUtf8("selectTeamTitle"));
        selectTeamTitle->setGeometry(QRect(60, 70, 101, 21));
        selectSouvenirBox = new QComboBox(souvenirEditor);
        selectSouvenirBox->setObjectName(QString::fromUtf8("selectSouvenirBox"));
        selectSouvenirBox->setGeometry(QRect(410, 160, 211, 22));
        selectTeamTitle_2 = new QLabel(souvenirEditor);
        selectTeamTitle_2->setObjectName(QString::fromUtf8("selectTeamTitle_2"));
        selectTeamTitle_2->setGeometry(QRect(410, 140, 121, 21));
        exitEditButton = new QPushButton(souvenirEditor);
        exitEditButton->setObjectName(QString::fromUtf8("exitEditButton"));
        exitEditButton->setGeometry(QRect(550, 440, 80, 22));
        stackedWidget->addWidget(souvenirEditor);
        editPage = new QWidget();
        editPage->setObjectName(QString::fromUtf8("editPage"));
        enterEditButton = new QPushButton(editPage);
        enterEditButton->setObjectName(QString::fromUtf8("enterEditButton"));
        enterEditButton->setGeometry(QRect(380, 280, 80, 22));
        cancelEditButton = new QPushButton(editPage);
        cancelEditButton->setObjectName(QString::fromUtf8("cancelEditButton"));
        cancelEditButton->setGeometry(QRect(280, 280, 80, 22));
        priceTitle = new QLabel(editPage);
        priceTitle->setObjectName(QString::fromUtf8("priceTitle"));
        priceTitle->setGeometry(QRect(320, 190, 47, 14));
        updateSouvenirLabel = new QLabel(editPage);
        updateSouvenirLabel->setObjectName(QString::fromUtf8("updateSouvenirLabel"));
        updateSouvenirLabel->setGeometry(QRect(380, 160, 171, 16));
        souvenirTitle_2 = new QLabel(editPage);
        souvenirTitle_2->setObjectName(QString::fromUtf8("souvenirTitle_2"));
        souvenirTitle_2->setGeometry(QRect(260, 160, 101, 20));
        line = new QFrame(editPage);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(210, 250, 311, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        teamNameTitle = new QLabel(editPage);
        teamNameTitle->setObjectName(QString::fromUtf8("teamNameTitle"));
        teamNameTitle->setGeometry(QRect(290, 130, 71, 20));
        updateTeamLabel = new QLabel(editPage);
        updateTeamLabel->setObjectName(QString::fromUtf8("updateTeamLabel"));
        updateTeamLabel->setGeometry(QRect(380, 130, 171, 16));
        enterPriceSpinBox = new QDoubleSpinBox(editPage);
        enterPriceSpinBox->setObjectName(QString::fromUtf8("enterPriceSpinBox"));
        enterPriceSpinBox->setGeometry(QRect(380, 190, 62, 22));
        enterPriceSpinBox->setMaximum(1000.000000000000000);
        stackedWidget->addWidget(editPage);
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
        editSouvenirsButton->setText(QCoreApplication::translate("MainWindow", "Edit Souvenir", nullptr));
        addSouvenirButton->setText(QCoreApplication::translate("MainWindow", "Add Souvenir", nullptr));
        deleteSouvenirButton->setText(QCoreApplication::translate("MainWindow", "Delete Souvenir", nullptr));
        editSouvenirButton->setText(QCoreApplication::translate("MainWindow", "Edit Souvenir", nullptr));
        souvenirTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">EDIT SOUVENIRS</span></p></body></html>", nullptr));
        selectTeamTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">SELECT TEAM </span></p></body></html>", nullptr));
        selectTeamTitle_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">SELECT SOUVENIR</span></p></body></html>", nullptr));
        exitEditButton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        enterEditButton->setText(QCoreApplication::translate("MainWindow", "Enter", nullptr));
        cancelEditButton->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        priceTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">PRICE</span></p></body></html>", nullptr));
        updateSouvenirLabel->setText(QCoreApplication::translate("MainWindow", "SOUVENIR_NAME", nullptr));
        souvenirTitle_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">SOUVENIR NAME</span></p></body></html>", nullptr));
        teamNameTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">TEAM NAME</span></p></body></html>", nullptr));
        updateTeamLabel->setText(QCoreApplication::translate("MainWindow", "TEAM_NAME", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
