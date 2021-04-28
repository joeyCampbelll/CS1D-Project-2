#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileInfo>
#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 525);
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

    //used to check if file has been added
    addedStadium = false;
    addedDistance = false;

    //hides add button and fileTable
    ui->addButt->hide();
    ui->pushButton_addDistances->hide();

    //sets up paths for the folder Trees
    QString sPath = "/Users";
    dirModel  = new QFileSystemModel(this);
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirModel->setRootPath(sPath);
    ui->treeView1->setModel(dirModel);
    fileModel = new QFileSystemModel(this);
    fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    fileModel->setRootPath(sPath);
    ui->fileView1->setModel(fileModel);

    ui->treeView1->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);

    //sets up paths for the folder Trees
    QString rPath = "/Users";
    dirModel2  = new QFileSystemModel(this);
    dirModel2->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirModel2->setRootPath(rPath);
    ui->FileSelector->setModel(dirModel2);
    fileModel2 = new QFileSystemModel(this);
    fileModel2->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    fileModel2->setRootPath(rPath);
    ui->FileView->setModel(fileModel2);

    ui->FileSelector->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
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
    ui->Stadium_tableView->setModel(model);
    ui->Stadium_tableView->resizeColumnsToContents();
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




void MainWindow::on_dfsBfsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
    ui->stadiumSelector->clear();

    // Gets each individual stadium name for combobox
    QSqlQuery* qryStadiums = new QSqlQuery();
    qryStadiums->prepare("SELECT DISTINCT ORIGINATED_STADIUM FROM Distances");
    qryStadiums->exec();

    ui->stadiumSelector->addItem("NONE");

    // iterates through the querys
    while (qryStadiums->next())
    {
        ui->stadiumSelector->addItem(qryStadiums->value(0).toString());
    }
}

void MainWindow::on_generateMST_clicked()
{

}

void MainWindow::on_generateBFS_clicked()
{
    if (selectedStadium != "NONE")
    {
        graphAdjMatr = new graphAM();
        graphAdjMatr->breadthFirstSearch(selectedStadium);
    }
}

void MainWindow::on_generateDFS_clicked()
{
    if (selectedStadium != "NONE")
    {
        graphAdjList = new graphAL();
        graphAdjList->depthFirstSearch(selectedStadium);
        QList<QString> temp = graphAdjList->getRoute();
        ui->displayRoute->append("DISTANCE: " + QString::number(graphAdjList->getDistance()));
        ui->displayRoute->append("\n");

        for(int i = 0; i < temp.length(); i++)
        {
            QString tempS = QString::number(i + 1) + ". ";
            ui->displayRoute->append(tempS + temp[i]);
//            ui->displayRoute->append(temp[i]);

        }
    }
}

void MainWindow::on_stadiumSelector_activated(const QString &arg1)
{
    selectedStadium = arg1;
}

void MainWindow::on_exitDfsBfsMstPage_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
