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
    ui->individualTeamEntry->setPlaceholderText("NONE");
    this->qry->prepare("SELECT TEAM_NAME FROM MLB_Information");
    this->qry->exec();
    this->model->setQuery(*qry);
    this->ui->individualTeamEntry->setModel(model);

    ui->sortByEntry->setPlaceholderText("NONE");
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

    ui->onlyShowEntry->setPlaceholderText("NONE");
    ui->onlyShowEntry->addItem("in the American League");
    ui->onlyShowEntry->addItem("in the National League");
    ui->onlyShowEntry->addItem("with the max length to CF");
    ui->onlyShowEntry->addItem("with the shortest length to CF");
    ui->onlyShowEntry->addItem("with a Retro Modern stadium");
    ui->onlyShowEntry->addItem("with a Retro Classic stadium");
    ui->onlyShowEntry->addItem("with a Jewel Box stadium");
    ui->onlyShowEntry->addItem("with a Modern stadium");
    ui->onlyShowEntry->addItem("with a Multipurpose stadium");
    ui->onlyShowEntry->addItem("with an open roof");
    ui->onlyShowEntry->addItem("with a retractable roof");
    ui->onlyShowEntry->addItem("with a fixed roof");

    individualTeamSelected = false;
    sorterSelected = false;
    filterSelected = false;
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
    individualTeamSelected = true;
    applyFilters(arg1, "", "");
}

void tablefilter::on_exitFiltersButton_clicked()
{
    this->close();
}

//void tablefilter::applyFilters(QString indiTeam, QString sorter, QString filter)
//{
//    this->model = new QSqlQueryModel();
//    this->qry = new QSqlQuery();

//    if(individualTeamSelected == false && sorterSelected == false && filterSelected == false)
//    {
//        return;
//    }
//    else if(individualTeamSelected == true && sorterSelected == false && filterSelected == false)
//    {
//        this->qry->prepare("SELECT * FROM MLB_Information WHERE TEAM_NAME = :teamname");
//        this->qry->bindValue(":teamname", indiTeam);
//    }

//    this->qry->exec();
//    this->model->setQuery(*qry);
//    this->tableView->setModel(model);
//}
