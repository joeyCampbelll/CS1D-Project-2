#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileInfo>
#include <QDir>

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

    //used to check if file has been added
    added = false;

    //hides add button and fileTable
    ui->addButt->hide();

    //sets up paths for the folder Trees
    QString sPath = "";
    dirModel  = new QFileSystemModel(this);
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirModel->setRootPath(sPath);
    ui->treeView1->setModel(dirModel);
    fileModel = new QFileSystemModel(this);
    fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    fileModel->setRootPath(sPath);
    ui->fileView1->setModel(fileModel);

    ui->treeView1->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
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
    ui->stackedWidget->setCurrentIndex(3);
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

void MainWindow::on_addButt_clicked()
{
    //parses and added file contents if not yet added
    if (!added)
    {
        //checks if file can open
        QFile file(pathToFile);
        if (!file.open(QIODevice::ReadOnly))
        {
            qDebug() << file.errorString();
        }
        else
        {
            qDebug() << "File is open";

            //reads each line of the file and parses the contents to DB
            while (!file.atEnd())
            {
                QString test = QString(file.readLine());
                QStringList toAdd = myDb.parseFile(test);
                myDb.addNewStadium(toAdd);
            }

            //confirmation message
            ui->ErrorLabel->setText("New Stadium added to database");
            added = true;

//            admin->updateColleges();
//            admin->show();
            ui->stackedWidget->setCurrentIndex(0);
        }
    }
}

void MainWindow::on_pushButton_cancel_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_treeView1_clicked(const QModelIndex &index)
{
    QString sPath = dirModel->fileInfo(index).absoluteFilePath();
    ui->fileView1->setRootIndex(fileModel->setRootPath(sPath));
}

void MainWindow::on_fileView1_clicked(const QModelIndex &index)
{
    //clear errorLabel
    ui->ErrorLabel->clear();

    //sets up tableWidget
    ui->fileTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->fileTable->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->fileTable->setColumnCount(10);
    QStringList headers;
    headers << "TeamName" << "StadiumName" << "SeatingCapacity" << "Location"
            << "PlayingSurface" << "League" << "DateOpened" << "DistanceToCenterField"
            << "BallParkTypology" << "RoofType";
    ui->fileTable->setHorizontalHeaderLabels(headers);

    //sets path
    QString path = fileModel->fileInfo(index).absoluteFilePath();
    pathToFile = path;
    bool correctFileType = path.endsWith(".csv");
    qDebug() << path;
    //checks if file is correct
    if (!correctFileType)
        ui->ErrorLabel->setText("Please select a .csv file");
    else {
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly)) {
                qDebug() << file.errorString();
            }
        else {
            qDebug() << "file opened";

            //reads file and outputs info to table
            while (!file.atEnd())
            {
                QString test = QString(file.readLine());
                QStringList toAdd = myDb.parseFile(test);

                QTableWidgetItem *TeamName = new QTableWidgetItem(toAdd.at(0));
                QTableWidgetItem *StadiumName = new QTableWidgetItem(toAdd.at(1));
                QTableWidgetItem *SeatingCapacity = new QTableWidgetItem(toAdd.at(2));
                QTableWidgetItem *Location = new QTableWidgetItem(toAdd.at(3));
                QTableWidgetItem *PlayingSurface = new QTableWidgetItem(toAdd.at(4));
                QTableWidgetItem *League = new QTableWidgetItem(toAdd.at(5));
                QTableWidgetItem *DateOpened = new QTableWidgetItem(toAdd.at(6));
                QTableWidgetItem *DistanceToCenterField = new QTableWidgetItem(toAdd.at(7));
                QTableWidgetItem *Typology = new QTableWidgetItem(toAdd.at(8));
                QTableWidgetItem *RoofType = new QTableWidgetItem(toAdd.at(9));

                ui->fileTable->insertRow(ui->fileTable->rowCount());
                ui->fileTable->setItem(ui->fileTable->rowCount() - 1, 0, TeamName);
                ui->fileTable->setItem(ui->fileTable->rowCount() - 1, 1, StadiumName);
                ui->fileTable->setItem(ui->fileTable->rowCount() - 1, 2, SeatingCapacity);
                ui->fileTable->setItem(ui->fileTable->rowCount() - 1, 3, Location);
                ui->fileTable->setItem(ui->fileTable->rowCount() - 1, 4, PlayingSurface);
                ui->fileTable->setItem(ui->fileTable->rowCount() - 1, 5, League);
                ui->fileTable->setItem(ui->fileTable->rowCount() - 1, 6, DateOpened);
                ui->fileTable->setItem(ui->fileTable->rowCount() - 1, 7, DistanceToCenterField);
                ui->fileTable->setItem(ui->fileTable->rowCount() - 1, 8, Typology);
                ui->fileTable->setItem(ui->fileTable->rowCount() - 1, 9, RoofType);

                ui->ErrorLabel->setText("Click 'Add' to add the information below to the database");
            }
            ui->addButt->show();
        }

    }
}
