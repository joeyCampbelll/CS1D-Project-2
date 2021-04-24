#include "mainwindow.h"
#include "ui_mainwindow.h"

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

//void MainWindow::showAllSouvenirs()
//{
//    QSqlQueryModel* model = new QSqlQueryModel();

//    QSqlQuery* qry = new QSqlQuery();

//    qry->prepare("SELECT * FROM SOUVENIRS");

//    qry->exec();

//    model->setQuery(*qry);

//    ui->souvenirTableView->setModel(model);
//}

void MainWindow::fillTeamComboBox()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    QSqlQuery* qry = new QSqlQuery();

    qry->prepare("SELECT DISTINCT TEAM_NAME FROM SOUVENIRS");

    if(qry->exec())
    {
        qDebug() << "college table updated";
    }
    else
        qDebug() << "failed";

    model->setQuery(*qry);

    ui->selectTeamBox->setModel(model);
}

void MainWindow::fillSouvenirComboBox() {
//    QSqlQueryModel* model=new QSqlQueryModel();

//    QSqlQuery* qry = new QSqlQuery();

//    qry->prepare("SELECT DISTINCT TEAM_NAME FROM SOUVENIRS");

//    if(qry->exec())
//    {
//        qDebug() << "college table updated";
//    }
//    else
//        qDebug() << "failed";

//    model->setQuery(*qry);

//    ui->selectStadiumBox->setModel(model);
}

void MainWindow::on_editSouvenirsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    fillTeamComboBox();
}

void MainWindow::on_deleteSouvenirButton_clicked()
{

}

void MainWindow::on_addSouvenirButton_clicked()
{

}

void MainWindow::on_editSouvenirButton_clicked()
{
    QString teamName =  ui->selectTeamBox->currentText();
    QString souvenirName = ui->selectSouvenirBox->currentText();
    ui->stackedWidget->setCurrentIndex(4);
    editSouvenir(teamName, souvenirName);
}

void MainWindow::editSouvenir(QString teamName, QString souvenirName)
{
    ui->updateTeamLabel->setText(teamName);
    ui->updateSouvenirLabel->setText(souvenirName);

    // GET PRICE
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery();

    qry->prepare("SELECT SOUVENIR_PRICE FROM SOUVENIRS WHERE (TEAM_NAME, SOUVENIR_NAME) = (:teamname, :souvenirname)");
    qry->bindValue(":teamname", teamName);
    qry->bindValue(":souvenirname", souvenirName);
    qry->exec();

    model->setQuery(*qry);

    //ui->enterPriceBox->setPlaceholderText("00.00");
}


void MainWindow::on_selectTeamBox_currentIndexChanged(const QString &arg1)
{
    QString teamName = arg1;
    QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery* qry = new QSqlQuery();

    qry->prepare("SELECT * FROM SOUVENIRS WHERE TEAM_NAME = :teamname");

    qry->bindValue(":teamname", teamName);
    qry->exec();

    model->setQuery(*qry);

    ui->souvenirTableView->setModel(model);

    QSqlQueryModel* model2 = new QSqlQueryModel();

    QSqlQuery* qry2 = new QSqlQuery();

    qry2->prepare("SELECT SOUVENIR_NAME FROM SOUVENIRS WHERE TEAM_NAME = :teamname");

    qry2->bindValue(":teamname", teamName);
    qry2->exec();

    model2->setQuery(*qry2);
    ui->selectSouvenirBox->setModel(model2);
}

void MainWindow::on_cancelEditButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
