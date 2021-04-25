#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 500);
    ui->stackedWidget->setCurrentIndex(0);

//    Check if database is open
    if(!myDb.isOpen())
    {
        qDebug() << "DATABASE FAILED TO OPEN" << Qt::endl;
    }
    else
    {
        qDebug() << "DATABASE SUCCESSFULLY CONNECTED" << Qt::endl;
        showAllMLB();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showAllMLB()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery* qry = new QSqlQuery();

    qry->prepare("SELECT * FROM MLB_Information");

    qry->exec();

    model->setQuery(*qry);

    ui->mlbTableView->setModel(model);
    ui->mlbTableView->resizeColumnsToContents();
}

void MainWindow::on_tableButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    this->filter = new tablefilter();
    this->filter->setTableView(ui->mlbTableView);
    // JAKE AND JOEY - this is where we start implementing a table view
}

void MainWindow::on_adminButton_clicked()
{
    // RYAN AND KATE - this is where you guys are going to switch
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_buildTripButton_clicked()
{
    //TODO - future build trip code
}

void MainWindow::on_dfsBfsButton_clicked()
{
    //TODO - future dfs/bfs code
}

void MainWindow::on_pushButton_cancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_viewFiltersButton_clicked()
{
    filter->show();
    filter->resetFilters();
    on_restoreTableButton_clicked();
}

void MainWindow::on_exitTableViewButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    on_restoreTableButton_clicked();
}

void MainWindow::on_restoreTableButton_clicked()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery* qry = new QSqlQuery();

    qry->prepare("SELECT * FROM MLB_Information");

    qry->exec();

    model->setQuery(*qry);

    ui->mlbTableView->setModel(model);
    ui->mlbTableView->resizeColumnsToContents();
}

