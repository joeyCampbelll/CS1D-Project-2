#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include "database.h"
#include "tablefilter.h"

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

private slots:

    void on_tableButton_clicked();

    void on_adminButton_clicked();

    void on_buildTripButton_clicked();

    void on_dfsBfsButton_clicked();

    void on_pushButton_cancel_clicked();

    void on_viewFiltersButton_clicked();

    void on_restoreTableButton_clicked();

    void on_exitTableViewButton_clicked();

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

    void on_SaveChanged_button_clicked();

private:
    Ui::MainWindow *ui;

    tablefilter *filter;

    /**
    * @brief used for file directory
    */
    QFileSystemModel *dirModel;

    /**
    * @brief used for file modal
    */
    QFileSystemModel *fileModel;

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
    * @brief assigns myDb to predefined PROJECT_PATH constant
    */
    Database myDb = Database(PROJECT_PATH + "/Database/mlbDatabase.db");
};
#endif // MAINWINDOW_H
