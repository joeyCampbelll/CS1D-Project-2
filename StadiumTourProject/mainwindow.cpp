#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 500);

    //Check if database is open
//    if(!myDb.isOpen())
//    {
//        ui->dbStatus_label->setText("Failed to open database!");
//    }
//    else
//    {
//        ui->dbStatus_label->setText("Connected...");
//        showMLB();
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::showMLB()
//{
//    QSqlQueryModel* model = new QSqlQueryModel();

//    QSqlQuery* qry = new QSqlQuery();

//    qry->prepare("SELECT * FROM MLB_Information");

//    if(qry->exec())
//    {
//        qDebug() << "MLB Info updated and displayed to table";
//    }
//    else
//    {
//        qDebug() << "MLB info failed to display";
//    }

//    model->setQuery(*qry);

//    ui->mlb_tableView->setModel(model);
//    ui->mlb_tableView->resizeColumnsToContents();
//}

void MainWindow::on_tableButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    // JAKE AND JOEY - this is where we start implementing a table view
}

void MainWindow::on_adminButton_clicked()
{
    // RYAN AND KATE - this is where you guys are going to switch
    //   stacked widget indecies
}

void MainWindow::on_buildTripButton_clicked()
{
    //TODO - future build trip code
}

void MainWindow::on_dfsBfsButton_clicked()
{
    //TODO - future dfs/bfs code
}
