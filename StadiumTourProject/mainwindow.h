#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

private:
    Ui::MainWindow *ui;

    tablefilter *filter;

    /**
    * @brief assigns myDb to predefined PROJECT_PATH constant
    */
    Database myDb = Database(PROJECT_PATH + "/Database/mlbDatabase.db");
};
#endif // MAINWINDOW_H
