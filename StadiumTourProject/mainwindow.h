#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include "database.h"
#include "tablefilter.h"
#include "graphal.h"
#include "grapham.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /**
    * @brief Class Method to update and show MLB info
    *
    * updates query for entire MLB info chart and sets ui Model
    */
    void showAllMLB();

    void fillTeamComboBox();
    void fillSouvenirComboBox();
    void updateSouvenirTableView();

private slots:

    void on_tableButton_clicked();

    void on_adminButton_clicked();

    void on_buildTripButton_clicked();

    void on_dfsBfsButton_clicked();

    void on_pushButton_cancel_clicked();

    void on_viewFiltersButton_clicked();

    void on_restoreTableButton_clicked();

    void on_exitTableViewButton_clicked();

    void on_editSouvenirsButton_clicked();

    void on_deleteSouvenirButton_clicked();

    void on_addSouvenirButton_clicked();

    void on_editSouvenirButton_clicked();

    void on_selectTeamBox_currentIndexChanged(const QString &arg1);

    void on_cancelEditButton_clicked();

    void on_enterEditButton_clicked();

    void on_exitEditButton_clicked();

    void on_cancelAddButton_clicked();

    void on_enterAddButton_clicked();
    void on_addButt_clicked();

    void on_pushButton_cancel_2_clicked();

    void on_treeView1_clicked(const QModelIndex &index);

    void on_fileView1_clicked(const QModelIndex &index);

    void on_FileSelector_clicked(const QModelIndex &index);

    void on_FileView_clicked(const QModelIndex &index);

    void on_pushButton_addDistances_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_login_clicked();

    void on_exit_button_clicked();

    void on_AddNewDistance_button_clicked();

    void on_AddNewStadium_button_clicked();

    void on_RemoveStadium_button_clicked();

    void on_Stadium_tableView_clicked(const QModelIndex &index);

    void on_editTeamInfo_button_clicked();

    void on_pushButton_saveChanges_clicked();

    void on_pushButton_cancelChanges_clicked();


    void on_pushButton_resetTeamInfo_clicked();

    void on_pushButton_quickAddStadium_clicked();

    void on_pushButton_quickAddDistances_clicked();

    void on_generateMST_clicked();

    void on_generateBFS_clicked();

    void on_generateDFS_clicked();

    void on_stadiumSelector_activated(const QString &arg1);

    void on_exitDfsBfsMstPage_clicked();

private:
    Ui::MainWindow *ui;

    tablefilter *filter;
    QString originalName;

    /**
    * @brief used for file directory
    */
    QFileSystemModel *dirModel;
    QFileSystemModel *dirModel2;

    /**
    * @brief used for file modal
    */
    QFileSystemModel *fileModel;
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

    //Used for storing data from tableView(used for editing college info)
    QString tempTeamName;
    QString tempStadiumName;
    QString tempLocation;
    QString tempLeague;
    int tempSeatingCapacity;
    int tempDateOpened;
    QString tempPlayingSurface;
    QString tempRoofType;
    QString tempDistToCenterField;
    QString tempTypology;

    // ======= DFS/BFS/MST Related =======

    QString selectedStadium;
    graphAL* graphAdjList;
    graphAM* graphAdjMatr;

    // ===================================

    /**
    * @brief assigns myDb to predefined PROJECT_PATH constant
    */
    Database myDb = Database(PROJECT_PATH + "/Database/mlbDatabase.db");
};
#endif // MAINWINDOW_H
