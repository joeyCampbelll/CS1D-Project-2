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
    if (!addedStadium)
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
            addedStadium = true;

            showAllMLB();
             ui->stackedWidget->setCurrentIndex(3);
        }
    }
}

void MainWindow::on_pushButton_cancel_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
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
    headers << "Team" << "Stadium" << "Capacity" << "Location"
            << "Surface" << "League" << "Date" << "Distance"
            << "Typology" << "Roof";
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

void MainWindow::on_FileSelector_clicked(const QModelIndex &index)
{
    QString sPath = dirModel2->fileInfo(index).absoluteFilePath();
    ui->FileView->setRootIndex(fileModel2->setRootPath(sPath));
}

void MainWindow::on_FileView_clicked(const QModelIndex &index)
{
        //clear errorLabel
        ui->labelError->clear();

        //sets up tableWidget
        ui->DistanceTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->DistanceTableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->DistanceTableWidget->setColumnCount(3);
        QStringList headers;
        headers << "Start" << "End" << "Distance";
        ui->DistanceTableWidget->setHorizontalHeaderLabels(headers);

        //sets path
        QString path = fileModel2->fileInfo(index).absoluteFilePath();
        pathToFile = path;
        bool correctFileType = path.endsWith(".csv");
        qDebug() << path;
        //checks if file is correct
        if (!correctFileType)
            ui->labelError->setText("Please select a .csv file");
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

                    QTableWidgetItem *StartStadium = new QTableWidgetItem(toAdd.at(0));
                    QTableWidgetItem *EndStadium = new QTableWidgetItem(toAdd.at(1));
                    QTableWidgetItem *Distance = new QTableWidgetItem(toAdd.at(2));

                    ui->DistanceTableWidget->insertRow(ui->DistanceTableWidget->rowCount());
                    ui->DistanceTableWidget->setItem(ui->DistanceTableWidget->rowCount() - 1, 0, StartStadium);
                    ui->DistanceTableWidget->setItem(ui->DistanceTableWidget->rowCount() - 1, 1, EndStadium);
                    ui->DistanceTableWidget->setItem(ui->DistanceTableWidget->rowCount() - 1, 2, Distance);

                    ui->labelError->setText("Click 'Add' to add the information below to the database");
                }
                ui->pushButton_addDistances->show();
            }

        }
}

void MainWindow::on_pushButton_addDistances_clicked()
{
        //parses and added file contents if not yet added
        if (!addedDistance)
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
                    myDb.addNewDistance(toAdd);
                }

                //confirmation message
                ui->labelError->setText("New Distances added to database");
                addedDistance = true;

                showAllMLB();
                ui->stackedWidget->setCurrentIndex(3);
            }
        }
}

void MainWindow::on_pushButton_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_login_clicked()
{
    if(ui->lineEdit_password->text() == "admin")
    {
        ui->stackedWidget->setCurrentIndex(3);
    }
    else
    {
        QMessageBox::information(this, "Login", "Incorrect Password");
    }
    ui->lineEdit_password->clear();
}

void MainWindow::on_exit_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_AddNewDistance_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_AddNewStadium_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_RemoveStadium_button_clicked()
{
    myDb.removeTeam(tempStadiumName, tempTeamName);
    showAllMLB();
}

void MainWindow::on_Stadium_tableView_clicked(const QModelIndex &index)
{
    if(index.isValid())
    {
        int row = index.row();
        tempTeamName = index.sibling(row, 0).data().toString();
        tempStadiumName = index.sibling(row, 1).data().toString();
        tempLocation = index.sibling(row, 2).data().toString();
        tempLeague = index.sibling(row, 3).data().toString();
        tempSeatingCapacity = index.sibling(row, 4).data().toString().replace(",", "").toInt();
        tempDateOpened = index.sibling(row, 5).data().toInt();
        tempPlayingSurface = index.sibling(row, 6).data().toString();
        tempRoofType = index.sibling(row, 7).data().toString();
        tempDistToCenterField = index.sibling(row, 8).data().toString();
        tempTypology = index.sibling(row, 9).data().toString();
    }
}

void MainWindow::on_editTeamInfo_button_clicked()
{
    ui->label_teamName->setText(tempTeamName);
    ui->lineEdit_stadiumName->setText(tempStadiumName);
    ui->lineEdit_location->setText(tempLocation);
    ui->lineEdit_league->setText(tempLeague);
    ui->spinBox_seatingCapacity->setValue(tempSeatingCapacity);
    ui->spinBox_dateOpened->setValue(tempDateOpened);
    ui->lineEdit_playingSurface->setText(tempPlayingSurface);
    ui->lineEdit_roofType->setText(tempRoofType);
    ui->lineEdit_distanceToCenterField->setText(tempDistToCenterField);
    ui->lineEdit_typology->setText(tempTypology);

    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_saveChanges_clicked()
{
    tempStadiumName = ui->lineEdit_stadiumName->text();
    tempLocation = ui->lineEdit_location->text();
    tempLeague = ui->lineEdit_league->text();
    tempSeatingCapacity = ui->spinBox_seatingCapacity->value();
    tempDateOpened = ui->spinBox_dateOpened->value();
    tempPlayingSurface = ui->lineEdit_playingSurface->text();
    tempRoofType = ui->lineEdit_roofType->text();
    tempDistToCenterField = ui->lineEdit_distanceToCenterField->text();
    tempTypology = ui->lineEdit_typology->text();

    myDb.updateStadiumInfo(tempTeamName, tempStadiumName, tempLocation, tempLeague,
                           tempSeatingCapacity, tempDateOpened, tempPlayingSurface,
                           tempRoofType, tempDistToCenterField, tempTypology);
    showAllMLB();
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_cancelChanges_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

