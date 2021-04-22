#include "tablefilter.h"
#include "ui_tablefilter.h"

tablefilter::tablefilter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tablefilter)
{
    ui->setupUi(this);

    // assigns the classes model and query objects
    this->model = new QSqlQueryModel();
    this->qry = new QSqlQuery();

    // Gets each individual team name for combobox
    this->qry->prepare("SELECT TEAM_NAME FROM MLB_Information");
    this->qry->exec();
    this->model->setQuery(*qry);
    this->ui->individualTeamEntry->setModel(model);

    ui->sortByEntry->addItem("Team Name");
    ui->sortByEntry->addItem("Stadium Name");
    ui->sortByEntry->addItem("Date Opened");
    ui->sortByEntry->addItem("Location");
    ui->sortByEntry->addItem("League");
    ui->sortByEntry->addItem("Seating Capacity");
    ui->sortByEntry->addItem("Distance to Center Field");
    ui->sortByEntry->addItem("Ballpark Typology");
    ui->sortByEntry->addItem("Playing Surface");
    ui->sortByEntry->addItem("Roof Type");

}

tablefilter::~tablefilter()
{
    delete ui;
}

void tablefilter::setTableView(QTableView *newTableView)
{
    this->tableView = newTableView;
}

void tablefilter::on_individualTeamEntry_activated(const QString &arg1)
{
    this->model = new QSqlQueryModel();

    this->qry = new QSqlQuery();

    // Gets each individual team name for combobox
    this->qry->prepare("SELECT * FROM MLB_Information WHERE TEAM_NAME = :teamname");
    this->qry->bindValue(":teamname", arg1);

    this->qry->exec();
    this->model->setQuery(*qry);
    this->tableView->setModel(model);
}

void tablefilter::on_exitFiltersButton_clicked()
{
    this->close();
}

