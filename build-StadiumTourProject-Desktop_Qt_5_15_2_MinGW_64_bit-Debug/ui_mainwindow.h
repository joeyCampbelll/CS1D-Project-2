/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
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
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
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
    QWidget *AdminMainPage;
    QLabel *label_6;
    QTableView *Stadium_tableView;
    QPushButton *editTeamInfo_button;
    QPushButton *AddNewStadium_button;
    QPushButton *AddNewDistance_button;
    QPushButton *RemoveStadium_button;
    QPushButton *exit_button;
    QPushButton *editSouvenirsButton;
    QPushButton *pushButton_resetTeamInfo;
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
    QLabel *label_17;
    QPushButton *pushButton_quickAddStadium;
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
    QLabel *label_18;
    QPushButton *pushButton_quickAddDistances;
    QWidget *page;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_teamName;
    QLineEdit *lineEdit_stadiumName;
    QLineEdit *lineEdit_league;
    QLineEdit *lineEdit_roofType;
    QLineEdit *lineEdit_typology;
    QLineEdit *lineEdit_distanceToCenterField;
    QLineEdit *lineEdit_playingSurface;
    QLineEdit *lineEdit_location;
    QSpinBox *spinBox_dateOpened;
    QSpinBox *spinBox_seatingCapacity;
    QPushButton *pushButton_saveChanges;
    QPushButton *pushButton_cancelChanges;
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
    QWidget *addPage;
    QLabel *priceTitle_3;
    QDoubleSpinBox *enterPriceSpinBox_3;
    QLabel *teamNameTitle_3;
    QLabel *updateTeamLabel_3;
    QLabel *souvenirTitle_5;
    QPushButton *enterAddButton;
    QLineEdit *enterNameBox_3;
    QFrame *line_3;
    QPushButton *cancelAddButton;
    QLabel *label_19;
    QWidget *editPage;
    QPushButton *enterEditButton;
    QPushButton *cancelEditButton;
    QLabel *priceTitle;
    QLabel *souvenirTitle_2;
    QFrame *line;
    QLabel *teamNameTitle;
    QLabel *updateTeamLabel;
    QDoubleSpinBox *enterPriceSpinBox;
    QLineEdit *enterNameBox;
    QLabel *label_20;
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
        lineEdit_password->setClearButtonEnabled(true);
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
        AdminMainPage = new QWidget();
        AdminMainPage->setObjectName(QString::fromUtf8("AdminMainPage"));
        label_6 = new QLabel(AdminMainPage);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 5, 781, 61));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignCenter);
        Stadium_tableView = new QTableView(AdminMainPage);
        Stadium_tableView->setObjectName(QString::fromUtf8("Stadium_tableView"));
        Stadium_tableView->setGeometry(QRect(5, 61, 791, 371));
        editTeamInfo_button = new QPushButton(AdminMainPage);
        editTeamInfo_button->setObjectName(QString::fromUtf8("editTeamInfo_button"));
        editTeamInfo_button->setGeometry(QRect(10, 450, 151, 41));
        AddNewStadium_button = new QPushButton(AdminMainPage);
        AddNewStadium_button->setObjectName(QString::fromUtf8("AddNewStadium_button"));
        AddNewStadium_button->setGeometry(QRect(330, 450, 111, 41));
        AddNewDistance_button = new QPushButton(AdminMainPage);
        AddNewDistance_button->setObjectName(QString::fromUtf8("AddNewDistance_button"));
        AddNewDistance_button->setGeometry(QRect(450, 450, 111, 41));
        RemoveStadium_button = new QPushButton(AdminMainPage);
        RemoveStadium_button->setObjectName(QString::fromUtf8("RemoveStadium_button"));
        RemoveStadium_button->setGeometry(QRect(170, 450, 151, 41));
        exit_button = new QPushButton(AdminMainPage);
        exit_button->setObjectName(QString::fromUtf8("exit_button"));
        exit_button->setGeometry(QRect(10, 10, 121, 41));
        editSouvenirsButton = new QPushButton(AdminMainPage);
        editSouvenirsButton->setObjectName(QString::fromUtf8("editSouvenirsButton"));
        editSouvenirsButton->setGeometry(QRect(570, 450, 101, 41));
        pushButton_resetTeamInfo = new QPushButton(AdminMainPage);
        pushButton_resetTeamInfo->setObjectName(QString::fromUtf8("pushButton_resetTeamInfo"));
        pushButton_resetTeamInfo->setGeometry(QRect(680, 450, 111, 41));
        stackedWidget->addWidget(AdminMainPage);
        AdminStadiumsPage = new QWidget();
        AdminStadiumsPage->setObjectName(QString::fromUtf8("AdminStadiumsPage"));
        layoutWidget_2 = new QWidget(AdminStadiumsPage);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 90, 781, 171));
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
        fileTable->setGeometry(QRect(10, 290, 781, 151));
        fileTable->setAutoFillBackground(true);
        fileTable->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255)"));
        ErrorLabel = new QLabel(AdminStadiumsPage);
        ErrorLabel->setObjectName(QString::fromUtf8("ErrorLabel"));
        ErrorLabel->setGeometry(QRect(10, 260, 781, 31));
        ErrorLabel->setAutoFillBackground(false);
        ErrorLabel->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(AdminStadiumsPage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 60, 781, 20));
        label_4->setAlignment(Qt::AlignCenter);
        addButt = new QPushButton(AdminStadiumsPage);
        addButt->setObjectName(QString::fromUtf8("addButt"));
        addButt->setGeometry(QRect(270, 450, 121, 31));
        addButt->setAutoFillBackground(false);
        addButt->setStyleSheet(QString::fromUtf8(""));
        pushButton_cancel_2 = new QPushButton(AdminStadiumsPage);
        pushButton_cancel_2->setObjectName(QString::fromUtf8("pushButton_cancel_2"));
        pushButton_cancel_2->setGeometry(QRect(420, 450, 121, 31));
        pushButton_cancel_2->setAutoFillBackground(false);
        pushButton_cancel_2->setStyleSheet(QString::fromUtf8(""));
        label_17 = new QLabel(AdminStadiumsPage);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(0, 0, 801, 51));
        label_17->setFont(font2);
        label_17->setAlignment(Qt::AlignCenter);
        pushButton_quickAddStadium = new QPushButton(AdminStadiumsPage);
        pushButton_quickAddStadium->setObjectName(QString::fromUtf8("pushButton_quickAddStadium"));
        pushButton_quickAddStadium->setGeometry(QRect(10, 450, 201, 31));
        stackedWidget->addWidget(AdminStadiumsPage);
        AdminDistancesPage = new QWidget();
        AdminDistancesPage->setObjectName(QString::fromUtf8("AdminDistancesPage"));
        label_5 = new QLabel(AdminDistancesPage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 60, 781, 20));
        label_5->setAlignment(Qt::AlignCenter);
        layoutWidget_3 = new QWidget(AdminDistancesPage);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 90, 781, 191));
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
        labelError->setGeometry(QRect(10, 280, 781, 21));
        labelError->setAlignment(Qt::AlignCenter);
        DistanceTableWidget = new QTableWidget(AdminDistancesPage);
        DistanceTableWidget->setObjectName(QString::fromUtf8("DistanceTableWidget"));
        DistanceTableWidget->setGeometry(QRect(10, 300, 781, 161));
        pushButton_addDistances = new QPushButton(AdminDistancesPage);
        pushButton_addDistances->setObjectName(QString::fromUtf8("pushButton_addDistances"));
        pushButton_addDistances->setGeometry(QRect(270, 470, 121, 31));
        pushButton_2 = new QPushButton(AdminDistancesPage);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(410, 470, 111, 31));
        label_18 = new QLabel(AdminDistancesPage);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(0, 10, 801, 51));
        label_18->setFont(font2);
        label_18->setAlignment(Qt::AlignCenter);
        pushButton_quickAddDistances = new QPushButton(AdminDistancesPage);
        pushButton_quickAddDistances->setObjectName(QString::fromUtf8("pushButton_quickAddDistances"));
        pushButton_quickAddDistances->setGeometry(QRect(10, 470, 211, 31));
        stackedWidget->addWidget(AdminDistancesPage);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        label_7 = new QLabel(page);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(0, 10, 791, 51));
        QFont font3;
        font3.setPointSize(22);
        font3.setBold(true);
        font3.setWeight(75);
        label_7->setFont(font3);
        label_7->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(page);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(90, 110, 231, 31));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(page);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(440, 120, 231, 31));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(page);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(90, 180, 231, 31));
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(page);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(450, 200, 231, 31));
        label_11->setFont(font);
        label_11->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(page);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(80, 260, 231, 31));
        label_12->setFont(font);
        label_12->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(page);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(450, 280, 231, 31));
        label_13->setFont(font);
        label_13->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(page);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(80, 340, 231, 31));
        label_14->setFont(font);
        label_14->setAlignment(Qt::AlignCenter);
        label_15 = new QLabel(page);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(430, 350, 271, 31));
        label_15->setFont(font);
        label_15->setAlignment(Qt::AlignCenter);
        label_16 = new QLabel(page);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(80, 410, 231, 31));
        label_16->setFont(font);
        label_16->setAlignment(Qt::AlignCenter);
        label_teamName = new QLabel(page);
        label_teamName->setObjectName(QString::fromUtf8("label_teamName"));
        label_teamName->setGeometry(QRect(10, 70, 771, 31));
        label_teamName->setFont(font);
        label_teamName->setAlignment(Qt::AlignCenter);
        lineEdit_stadiumName = new QLineEdit(page);
        lineEdit_stadiumName->setObjectName(QString::fromUtf8("lineEdit_stadiumName"));
        lineEdit_stadiumName->setGeometry(QRect(70, 140, 271, 31));
        QFont font4;
        font4.setPointSize(10);
        lineEdit_stadiumName->setFont(font4);
        lineEdit_stadiumName->setAlignment(Qt::AlignCenter);
        lineEdit_league = new QLineEdit(page);
        lineEdit_league->setObjectName(QString::fromUtf8("lineEdit_league"));
        lineEdit_league->setGeometry(QRect(110, 220, 181, 31));
        lineEdit_league->setFont(font4);
        lineEdit_league->setAlignment(Qt::AlignCenter);
        lineEdit_roofType = new QLineEdit(page);
        lineEdit_roofType->setObjectName(QString::fromUtf8("lineEdit_roofType"));
        lineEdit_roofType->setGeometry(QRect(100, 370, 181, 31));
        lineEdit_roofType->setFont(font4);
        lineEdit_roofType->setAlignment(Qt::AlignCenter);
        lineEdit_typology = new QLineEdit(page);
        lineEdit_typology->setObjectName(QString::fromUtf8("lineEdit_typology"));
        lineEdit_typology->setGeometry(QRect(100, 450, 181, 31));
        lineEdit_typology->setFont(font4);
        lineEdit_typology->setAlignment(Qt::AlignCenter);
        lineEdit_distanceToCenterField = new QLineEdit(page);
        lineEdit_distanceToCenterField->setObjectName(QString::fromUtf8("lineEdit_distanceToCenterField"));
        lineEdit_distanceToCenterField->setGeometry(QRect(440, 390, 251, 31));
        lineEdit_distanceToCenterField->setFont(font4);
        lineEdit_distanceToCenterField->setAlignment(Qt::AlignCenter);
        lineEdit_playingSurface = new QLineEdit(page);
        lineEdit_playingSurface->setObjectName(QString::fromUtf8("lineEdit_playingSurface"));
        lineEdit_playingSurface->setGeometry(QRect(430, 320, 271, 31));
        lineEdit_playingSurface->setFont(font4);
        lineEdit_playingSurface->setAlignment(Qt::AlignCenter);
        lineEdit_location = new QLineEdit(page);
        lineEdit_location->setObjectName(QString::fromUtf8("lineEdit_location"));
        lineEdit_location->setGeometry(QRect(470, 160, 181, 31));
        lineEdit_location->setFont(font4);
        lineEdit_location->setAlignment(Qt::AlignCenter);
        spinBox_dateOpened = new QSpinBox(page);
        spinBox_dateOpened->setObjectName(QString::fromUtf8("spinBox_dateOpened"));
        spinBox_dateOpened->setGeometry(QRect(130, 300, 131, 31));
        spinBox_dateOpened->setFont(font4);
        spinBox_dateOpened->setAlignment(Qt::AlignCenter);
        spinBox_dateOpened->setMaximum(9999);
        spinBox_seatingCapacity = new QSpinBox(page);
        spinBox_seatingCapacity->setObjectName(QString::fromUtf8("spinBox_seatingCapacity"));
        spinBox_seatingCapacity->setGeometry(QRect(490, 240, 151, 31));
        spinBox_seatingCapacity->setFont(font4);
        spinBox_seatingCapacity->setAlignment(Qt::AlignCenter);
        spinBox_seatingCapacity->setMaximum(999999);
        pushButton_saveChanges = new QPushButton(page);
        pushButton_saveChanges->setObjectName(QString::fromUtf8("pushButton_saveChanges"));
        pushButton_saveChanges->setGeometry(QRect(450, 440, 121, 41));
        pushButton_saveChanges->setFont(font4);
        pushButton_cancelChanges = new QPushButton(page);
        pushButton_cancelChanges->setObjectName(QString::fromUtf8("pushButton_cancelChanges"));
        pushButton_cancelChanges->setGeometry(QRect(580, 440, 121, 41));
        pushButton_cancelChanges->setFont(font4);
        stackedWidget->addWidget(page);
        souvenirEditor = new QWidget();
        souvenirEditor->setObjectName(QString::fromUtf8("souvenirEditor"));
        addSouvenirButton = new QPushButton(souvenirEditor);
        addSouvenirButton->setObjectName(QString::fromUtf8("addSouvenirButton"));
        addSouvenirButton->setGeometry(QRect(530, 140, 111, 31));
        deleteSouvenirButton = new QPushButton(souvenirEditor);
        deleteSouvenirButton->setObjectName(QString::fromUtf8("deleteSouvenirButton"));
        deleteSouvenirButton->setGeometry(QRect(530, 240, 111, 31));
        editSouvenirButton = new QPushButton(souvenirEditor);
        editSouvenirButton->setObjectName(QString::fromUtf8("editSouvenirButton"));
        editSouvenirButton->setGeometry(QRect(530, 280, 111, 31));
        souvenirTableView = new QTableView(souvenirEditor);
        souvenirTableView->setObjectName(QString::fromUtf8("souvenirTableView"));
        souvenirTableView->setGeometry(QRect(10, 100, 501, 311));
        souvenirTableView->setSelectionMode(QAbstractItemView::MultiSelection);
        souvenirTitle = new QLabel(souvenirEditor);
        souvenirTitle->setObjectName(QString::fromUtf8("souvenirTitle"));
        souvenirTitle->setGeometry(QRect(0, 0, 211, 41));
        selectTeamBox = new QComboBox(souvenirEditor);
        selectTeamBox->setObjectName(QString::fromUtf8("selectTeamBox"));
        selectTeamBox->setGeometry(QRect(110, 70, 211, 22));
        selectTeamTitle = new QLabel(souvenirEditor);
        selectTeamTitle->setObjectName(QString::fromUtf8("selectTeamTitle"));
        selectTeamTitle->setGeometry(QRect(10, 60, 101, 41));
        selectSouvenirBox = new QComboBox(souvenirEditor);
        selectSouvenirBox->setObjectName(QString::fromUtf8("selectSouvenirBox"));
        selectSouvenirBox->setGeometry(QRect(530, 210, 211, 22));
        selectTeamTitle_2 = new QLabel(souvenirEditor);
        selectTeamTitle_2->setObjectName(QString::fromUtf8("selectTeamTitle_2"));
        selectTeamTitle_2->setGeometry(QRect(520, 180, 121, 31));
        exitEditButton = new QPushButton(souvenirEditor);
        exitEditButton->setObjectName(QString::fromUtf8("exitEditButton"));
        exitEditButton->setGeometry(QRect(630, 430, 111, 31));
        stackedWidget->addWidget(souvenirEditor);
        addPage = new QWidget();
        addPage->setObjectName(QString::fromUtf8("addPage"));
        priceTitle_3 = new QLabel(addPage);
        priceTitle_3->setObjectName(QString::fromUtf8("priceTitle_3"));
        priceTitle_3->setGeometry(QRect(340, 200, 47, 21));
        enterPriceSpinBox_3 = new QDoubleSpinBox(addPage);
        enterPriceSpinBox_3->setObjectName(QString::fromUtf8("enterPriceSpinBox_3"));
        enterPriceSpinBox_3->setGeometry(QRect(400, 200, 62, 22));
        enterPriceSpinBox_3->setMaximum(1000.000000000000000);
        teamNameTitle_3 = new QLabel(addPage);
        teamNameTitle_3->setObjectName(QString::fromUtf8("teamNameTitle_3"));
        teamNameTitle_3->setGeometry(QRect(310, 140, 81, 20));
        updateTeamLabel_3 = new QLabel(addPage);
        updateTeamLabel_3->setObjectName(QString::fromUtf8("updateTeamLabel_3"));
        updateTeamLabel_3->setGeometry(QRect(400, 140, 171, 16));
        souvenirTitle_5 = new QLabel(addPage);
        souvenirTitle_5->setObjectName(QString::fromUtf8("souvenirTitle_5"));
        souvenirTitle_5->setGeometry(QRect(280, 170, 111, 20));
        enterAddButton = new QPushButton(addPage);
        enterAddButton->setObjectName(QString::fromUtf8("enterAddButton"));
        enterAddButton->setGeometry(QRect(400, 290, 80, 22));
        enterNameBox_3 = new QLineEdit(addPage);
        enterNameBox_3->setObjectName(QString::fromUtf8("enterNameBox_3"));
        enterNameBox_3->setGeometry(QRect(400, 170, 161, 21));
        line_3 = new QFrame(addPage);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(230, 260, 311, 21));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        cancelAddButton = new QPushButton(addPage);
        cancelAddButton->setObjectName(QString::fromUtf8("cancelAddButton"));
        cancelAddButton->setGeometry(QRect(300, 290, 80, 22));
        label_19 = new QLabel(addPage);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(310, 60, 211, 41));
        stackedWidget->addWidget(addPage);
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
        priceTitle->setGeometry(QRect(320, 190, 47, 21));
        souvenirTitle_2 = new QLabel(editPage);
        souvenirTitle_2->setObjectName(QString::fromUtf8("souvenirTitle_2"));
        souvenirTitle_2->setGeometry(QRect(260, 160, 111, 21));
        line = new QFrame(editPage);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(210, 250, 311, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        teamNameTitle = new QLabel(editPage);
        teamNameTitle->setObjectName(QString::fromUtf8("teamNameTitle"));
        teamNameTitle->setGeometry(QRect(290, 130, 81, 20));
        updateTeamLabel = new QLabel(editPage);
        updateTeamLabel->setObjectName(QString::fromUtf8("updateTeamLabel"));
        updateTeamLabel->setGeometry(QRect(380, 130, 171, 16));
        enterPriceSpinBox = new QDoubleSpinBox(editPage);
        enterPriceSpinBox->setObjectName(QString::fromUtf8("enterPriceSpinBox"));
        enterPriceSpinBox->setGeometry(QRect(380, 190, 62, 22));
        enterPriceSpinBox->setMaximum(1000.000000000000000);
        enterNameBox = new QLineEdit(editPage);
        enterNameBox->setObjectName(QString::fromUtf8("enterNameBox"));
        enterNameBox->setGeometry(QRect(370, 160, 161, 21));
        label_20 = new QLabel(editPage);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(290, 60, 221, 41));
        stackedWidget->addWidget(editPage);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(5);


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
        label_6->setText(QCoreApplication::translate("MainWindow", "Administrator Window", nullptr));
        editTeamInfo_button->setText(QCoreApplication::translate("MainWindow", "Edit Selected Team Info", nullptr));
        AddNewStadium_button->setText(QCoreApplication::translate("MainWindow", "Add New Stadium", nullptr));
        AddNewDistance_button->setText(QCoreApplication::translate("MainWindow", "Add New Distance", nullptr));
        RemoveStadium_button->setText(QCoreApplication::translate("MainWindow", "Remove Selected Team", nullptr));
        exit_button->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        editSouvenirsButton->setText(QCoreApplication::translate("MainWindow", "Edit Souvenirs", nullptr));
        pushButton_resetTeamInfo->setText(QCoreApplication::translate("MainWindow", "Reset Team Info", nullptr));
        ErrorLabel->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "Please select a .CSV file below:", nullptr));
        addButt->setText(QCoreApplication::translate("MainWindow", "Add Stadium", nullptr));
        pushButton_cancel_2->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Add Stadium From Input File", nullptr));
        pushButton_quickAddStadium->setText(QCoreApplication::translate("MainWindow", "Quick Add Las Vegas Gamblers", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Please select a .CSV file below:", nullptr));
        labelError->setText(QString());
        pushButton_addDistances->setText(QCoreApplication::translate("MainWindow", "Add Distances", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Add Distances From Input File", nullptr));
        pushButton_quickAddDistances->setText(QCoreApplication::translate("MainWindow", "Quick Add Distances for Gamblers", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Edit Team Information", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Stadium Name", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Location", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "League", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Seating Capacity", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Date Opened", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Playing Surface", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Roof Type", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Distance to Center Field", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Ball Park Typology", nullptr));
        label_teamName->setText(QCoreApplication::translate("MainWindow", "[+] Team Name", nullptr));
        pushButton_saveChanges->setText(QCoreApplication::translate("MainWindow", "Save Changes", nullptr));
        pushButton_cancelChanges->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        addSouvenirButton->setText(QCoreApplication::translate("MainWindow", "Add Souvenir +", nullptr));
        deleteSouvenirButton->setText(QCoreApplication::translate("MainWindow", "Delete Souvenir", nullptr));
        editSouvenirButton->setText(QCoreApplication::translate("MainWindow", "Edit Souvenir", nullptr));
        souvenirTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">EDIT SOUVENIRS</span></p></body></html>", nullptr));
        selectTeamTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">SELECT TEAM </span></p></body></html>", nullptr));
        selectTeamTitle_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">SELECT SOUVENIR</span></p></body></html>", nullptr));
        exitEditButton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        priceTitle_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">PRICE</span></p></body></html>", nullptr));
        teamNameTitle_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">TEAM NAME</span></p></body></html>", nullptr));
        updateTeamLabel_3->setText(QCoreApplication::translate("MainWindow", "TEAM_NAME", nullptr));
        souvenirTitle_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">SOUVENIR NAME</span></p></body></html>", nullptr));
        enterAddButton->setText(QCoreApplication::translate("MainWindow", "Enter", nullptr));
        cancelAddButton->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">ADD SOUVENIR</span></p></body></html>", nullptr));
        enterEditButton->setText(QCoreApplication::translate("MainWindow", "Enter", nullptr));
        cancelEditButton->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        priceTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">PRICE</span></p></body></html>", nullptr));
        souvenirTitle_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">SOUVENIR NAME</span></p></body></html>", nullptr));
        teamNameTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">TEAM NAME</span></p></body></html>", nullptr));
        updateTeamLabel->setText(QCoreApplication::translate("MainWindow", "TEAM_NAME", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">EDIT SOUVENIR</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
