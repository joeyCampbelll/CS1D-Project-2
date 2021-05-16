#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QCheckBox>
#include "database.h"
#include "souvenirshop.h"
#include "tablefilter.h"
#include "graphal.h"
#include "grapham.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
    * @brief main window constructor
    *
    * @param *parent
    */
    MainWindow(QWidget *parent = nullptr);

    /**
    * @brief main window destructor
    */
    ~MainWindow();

    /**
    * @brief Class Method to update and show MLB info
    *
    * updates query for entire MLB info chart and sets ui Model
    *
    */
    void showAllMLB();

    /**
    * @brief fills team combo box
    *
    * fills team combo box with the names
    * of all current teams
    *
    */
    void fillTeamComboBox();

    /**
    * @brief fills souvenir combo box
    *
    * fills souvenir combo box with all
    * current souvenirs
    *
    */
    void fillSouvenirComboBox();

    /**
    * @brief updates souvenir table
    *
    * updates souvenir table with new information
    * from database
    *
    */
    void updateSouvenirTableView();
    void tripPlannerBack();

private slots:

    /**
    * @brief function to handle table button clicked
    */
    void on_tableButton_clicked();

    /**
    * @brief function to handle admin button clicked
    */
    void on_adminButton_clicked();

    /**
    * @brief function to handle build trip button clicked
    */
    void on_buildTripButton_clicked();

    /**
    * @brief function to handle DFS/BFS/MST button clicked
    */
    void on_dfsBfsButton_clicked();

    /**
    * @brief function to handle cancel button 1 clicked
    */
    void on_pushButton_cancel_clicked();

    /**
    * @brief function to handle view filters button clicked
    */
    void on_viewFiltersButton_clicked();

    /**
    * @brief function to handle restore table button clicked
    */
    void on_restoreTableButton_clicked();

    /**
    * @brief function to handle exit table view button clicked
    */
    void on_exitTableViewButton_clicked();

    /**
    * @brief function to handle edit souvenirs button clicked
    */
    void on_editSouvenirsButton_clicked();

    /**
    * @brief function to handle delete souvenir button clicked
    */
    void on_deleteSouvenirButton_clicked();

    /**
    * @brief function to handle add souvenir button clicked
    */
    void on_addSouvenirButton_clicked();

    /**
    * @brief function to handle edit souvenir button clicked
    */
    void on_editSouvenirButton_clicked();

    /**
    * @brief function to handle select team combo box changed
    *
    * @param arg1
    */
    void on_selectTeamBox_currentIndexChanged(const QString &arg1);

    /**
    * @brief function to handle cancel edit button clicked
    */
    void on_cancelEditButton_clicked();

    /**
    * @brief function to handle enter edit button clicked
    */
    void on_enterEditButton_clicked();

    /**
    * @brief function to handle exit edit button clicked
    */
    void on_exitEditButton_clicked();

    /**
    * @brief function to handle cancel add button clicked
    */
    void on_cancelAddButton_clicked();

    /**
    * @brief function to handle enter add button clicked
    */
    void on_enterAddButton_clicked();

    /**
    * @brief function to handle add button clicked
    */
    void on_addButt_clicked();

    /**
    * @brief function to handle cancel button 2 clicked
    */
    void on_pushButton_cancel_2_clicked();

    /**
    * @brief function to handle tree view clicked
    *
    * @param index
    */
    void on_treeView1_clicked(const QModelIndex &index);

    /**
    * @brief function to handle file view clicked
    *
    * @param index
    */
    void on_fileView1_clicked(const QModelIndex &index);

    /**
    * @brief function to handle file selector clicked
    *
    * @param index
    */
    void on_FileSelector_clicked(const QModelIndex &index);

    /**
    * @brief function to handle file view clicked
    *
    * @param index
    */
    void on_FileView_clicked(const QModelIndex &index);

    /**
    * @brief function to handle add distances button clicked
    */
    void on_pushButton_addDistances_clicked();

    /**
    * @brief function to handle push button 2 clicked
    */
    void on_pushButton_2_clicked();

    /**
    * @brief function to handle login button clicked
    */
    void on_pushButton_login_clicked();

    /**
    * @brief function to handle exit button clicked
    */
    void on_exit_button_clicked();

    /**
    * @brief function to handle add new distance button clicked
    */
    void on_AddNewDistance_button_clicked();

    /**
    * @brief function to handle add new stadium button clicked
    */
    void on_AddNewStadium_button_clicked();

    /**
    * @brief function to handle remove stadium button clicked
    */
    void on_RemoveStadium_button_clicked();

    /**
    * @brief function to handle stadium table view clicked
    *
    * @param index
    */
    void on_Stadium_tableView_clicked(const QModelIndex &index);

    /**
    * @brief function to handle edit team info button clicked
    */
    void on_editTeamInfo_button_clicked();

    /**
    * @brief function to handle save changed button clicked
    */
    void on_pushButton_saveChanges_clicked();

    /**
    * @brief function to handle cancel changes button clicked
    */
    void on_pushButton_cancelChanges_clicked();

    /**
    * @brief function to handle 1 to 1 plan trip button clicked
    */
    void on_pushButton_SSRplanTrip_clicked();

    /**
    * @brief function to handle 1 to 1 start trip button clicked
    */
    void on_pushButton_SSRstartTrip_clicked();

    /**
    * @brief function to fill starting team combo boxes
    */
    void fillStartTeam();

    /**
    * @brief function to initialize table views with database info
    */
    void initializeList();

    /**
    * @brief function to handle check boxes
    */
    void CheckboxChanged();

    /**
    * @brief function to handle combo box activated
    */
    void on_comboBox_startingTeamChooseTeams_activated();

    /**
    * @brief function to handle generate route button clicked
    */
    void on_pushButton_generateRouteChooseTeams_clicked();

    /**
    * @brief function to handle starting team combo box activated
    *
    * @param startingTeam
    */
    void on_comboBox_startingTeam_activated(const QString &startingTeam);

    /**
    * @brief function to handle reset team info button clicked
    */
    void on_pushButton_resetTeamInfo_clicked();

    /**
    * @brief function to handle quick add stadium button clicked
    */
    void on_pushButton_quickAddStadium_clicked();

    /**
    * @brief function to handle quick add distances button clicked
    */
    void on_pushButton_quickAddDistances_clicked();

    /**
    * @brief function to handle generate MST button clicked
    */
    void on_generateMST_clicked();

    /**
    * @brief function to handle generate BFS button clicked
    */
    void on_generateBFS_clicked();

    /**
    * @brief function to handle generate DFS button clicked
    */
    void on_generateDFS_clicked();

    /**
    * @brief function to handle stadium selector combo box activated
    *
    * @param arg1
    */
    void on_stadiumSelector_activated(const QString &arg1);

    /**
    * @brief function to handle exit DFS BFS MST page button clicked
    */
    void on_exitDfsBfsMstPage_clicked();

    /**
    * @brief function to handle Marlins plan trip button clicked
    */
    void on_planTripButton_MiamiMarlins_clicked();

    /**
    * @brief function to handle Marlins start trip button clicked
    */
    void on_startTripButton_MiamiMarlins_clicked();

    /**
    * @brief function to handle back button trip planner clicked
    */
    void on_backButton_tripPlanner_clicked();

    /**
    * @brief function to convert stadium name to team name
    *
    * @param stadiumName
    *
    * @returns team name
    */
    QString stadiumToTeam(QString stadiumName);

    /**
    * @brief function to convert team name to stadium name
    *
    * @param teamName
    *
    * @returns stadium name
    */
    QString teamToStadium(QString teamName);

    /**
    * @brief function to handle choose teams start button clicked
    */
    void on_startButton_CTO_clicked();

    /**
    * @brief function to handle choose teams add button clicked
    */
    void on_addButton_CTO_clicked();

    /**
    * @brief function to handle choose teams remove team button clicked
    */
    void on_removeButton_CTO_clicked();

    /**
    * @brief function to handle choose teams reset button clicked
    */
    void on_resetButton_CTO_clicked();

    /**
    * @brief function to handle choose teams plan trip button clicked
    */
    void on_planTripButton_CTO_clicked();

    /**
    * @brief function to handle choose teams start trip button clicked
    */
    void on_pushButton_startTripChooseTeams_clicked();

private:
    /**
    * @brief pointer to access UI
    */
    Ui::MainWindow *ui;

    /**
    * @brief pointer used to filter data table
    */
    tablefilter *filter;

    /**
    * @brief original team name
    */
    QString originalName;

    /**
    * @brief used for file directory
    */
    QFileSystemModel *dirModel;

    /**
    * @brief used for file directory
    */
    QFileSystemModel *dirModel2;

    /**
    * @brief used for file modal
    */
    QFileSystemModel *fileModel;

    /**
    * @brief used for file modal
    */
    QFileSystemModel *fileModel2;

    /**
    * @brief used to store path to input file
    */
    QString pathToFile;

    /**
    * @brief used to see if file has already been added
    */
    bool addedStadium;

    /**
    * @brief used to see if file has already been added
    */
    bool addedDistance;

    /**
    * @brief temporary team name
    */
    QString tempTeamName;

    /**
    * @brief temporary stadium name
    */
    QString tempStadiumName;

    /**
    * @brief temporary location
    */
    QString tempLocation;

    /**
    * @brief temporary league
    */
    QString tempLeague;

    /**
    * @brief temporary seating capacity
    */
    int tempSeatingCapacity;

    /**
    * @brief temporary date opened
    */
    int tempDateOpened;

    /**
    * @brief temporary playing surface
    */
    QString tempPlayingSurface;

    /**
    * @brief temporary roof type
    */
    QString tempRoofType;

    /**
    * @brief temporary distance to center field
    */
    QString tempDistToCenterField;

    /**
    * @brief temporary ballpark typology
    */
    QString tempTypology;

    /**
    * @brief graph adjacency list used for marlins park route
    */
    graphAL* marlinsParkDFS;

    // ======= DFS/BFS/MST Related =======

    /**
    * @brief selected stadium name
    */
    QString selectedStadium;

    /**
    * @brief adjacency list
    */
    graphAL* graphAdjList;

    /**
    * @brief adjacency matrix
    */
    graphAM* graphAdjMatr;

    // ===================================

    //==========DIJKSTRAS=================

    /**
    * @brief dijkstras graph for 1 to 1 trip
    */
    graphAM* dijkstras;

    /**
    * @brief dijkstras graph for choose teams trip
    */
    graphAM* dijkstrasChooseTeams;

    /**
    * @brief dijkstras graph for choose order trip
    */
    graphAM* chooseOrder;

    /**
    * @brief vector to hold the fastest route
    */
    QVector<QString> fastestRoute;

    //====================================

    /**
    * @brief vector to hold input values
    */
    QVector<QString> inputValues;

    /**
    * @brief vector for check box elements
    */
    QVector<QCheckBox*> checkBoxVector;

    /**
    * @brief vector for selected team names
    */
    QVector<QString> teamNamesVector;

    /**
    * @brief vector for all team names
    */
    QVector<QString> tempTeamNamesVector;

    /**
    * @brief name for current campus
    */
    QString startTeamName;

    /**
    * @brief vector to hold selected teams
    */
    QVector<QString>customTeamNameList;

    /**
    * @brief vector to hold all teams
    */
    QVector<QString>allTeamsList;

    /**
    * @brief team counter
    */
    int counter = 0;

    /**
    * @brief total distance
    */
    int totalDistance;

    /**
    * @brief checks if 1 to 1 start button was clicked
    */
    bool SSRstartClicked = false;

    /**
    * @brief checks if choose teams start button was clicked
    */
    bool CTOstartButtonClicked = false;

    /**
    * @brief assigns myDb to predefined PROJECT_PATH constant
    */
    Database myDb = Database(PROJECT_PATH + "/Database/mlbDatabase.db");
};
#endif // MAINWINDOW_H
