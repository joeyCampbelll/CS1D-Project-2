#include "tablefilter.h"
#include "ui_tablefilter.h"

tablefilter::tablefilter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tablefilter)
{
    ui->setupUi(this);
    this->setFixedHeight(525);

    // assigns the classes model and query objects
    this->model = new QSqlQueryModel();
    this->qry = new QSqlQuery();

    // Gets each individual team name for combobox
    this->qry->prepare("SELECT TEAM_NAME FROM MLB_Information");
    this->qry->exec();

    ui->individualTeamEntry->clear();

    ui->individualTeamEntry->addItem("NONE");

    while (qry->next())
    {
        ui->individualTeamEntry->addItem(qry->value(0).toString());
    }

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
    ui->sortByEntry->addItem("NONE");

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
    ui->onlyShowEntry->addItem("with a grass field");
    ui->onlyShowEntry->addItem("with a turf field");
    ui->onlyShowEntry->addItem("with a 3D turf field");
    ui->onlyShowEntry->addItem("NONE");

    individualTeamSelected = false;
    sorterSelected = false;
    filterSelected = false;
    orderBy = "NONE";
    filterBy = "NONE";
    filterCol = "";
    indiTeam = "";
}

tablefilter::~tablefilter()
{
    delete ui;
}

void tablefilter::setTableView(QTableView *newTableView)
{
    this->tableView = newTableView;
}

void tablefilter::on_individualTeamEntry_activated(int index)
{
    individualTeamSelected = true;
    indiTeam = ui->individualTeamEntry->currentText();
}

void tablefilter::on_exitFiltersButton_clicked()
{
    applyFilters();
    this->close();
}

void tablefilter::applyFilters()
{
    this->model = new QSqlQueryModel();
    this->qry = new QSqlQuery();


    // individual team is selected
    if((individualTeamSelected == true && sorterSelected == false && filterSelected == false) ||
            (individualTeamSelected == true && sorterSelected == true && filterSelected == false)  ||
            (individualTeamSelected == true && sorterSelected == true && filterSelected == true)   ||
            (individualTeamSelected == true && sorterSelected == false && filterSelected == true)  )
    {

        this->qry->prepare("SELECT * FROM MLB_Information WHERE TEAM_NAME = :teamname");
        this->qry->bindValue(":teamname", indiTeam);
    }
    // no filters are selected
    else if((individualTeamSelected == false && sorterSelected == false && filterSelected == false) ||
       (filterBy == "NONE" && orderBy == "NONE"))

    {

        this->qry->prepare("SELECT * FROM MLB_Information");
    }
    // only a sorter is selected
    else if(individualTeamSelected == false && sorterSelected == true && filterSelected == false)
    {

        QString temp = "SELECT * FROM MLB_Information ORDER BY " + orderBy;
        this->qry->prepare(temp);
    }
    // sorter and filter are selected
    else if(individualTeamSelected == false && sorterSelected == true && filterSelected == true)
    {

        QString temp;
        if(filterBy == "max")
        {
            temp = "SELECT  * FROM MLB_Information WHERE " + filterCol +
                    " = (SELECT MAX("+ filterCol +") FROM MLB_Information)";

        }
        else if(filterBy == "min")
        {
            temp = "SELECT  * FROM MLB_Information WHERE " + filterCol +
                    " = (SELECT MIN("+ filterCol +") FROM MLB_Information)";
        }
        else
        {
            temp = "SELECT * FROM MLB_Information WHERE " + filterCol +
                    " = '" + filterBy + "' ORDER BY " + orderBy;
        }
        this->qry->prepare(temp);
    }
    // only filtering
    else if(individualTeamSelected == false && sorterSelected == false && filterSelected == true)
    {

        QString temp;
        if(filterBy == "max")
        {
            temp = "SELECT  * FROM MLB_Information WHERE " + filterCol +
                    " = (SELECT MAX("+ filterCol +") FROM MLB_Information)";
        }
        else if(filterBy == "min")
        {
            temp = "SELECT  * FROM MLB_Information WHERE " + filterCol +
                    " = (SELECT MIN("+ filterCol +") FROM MLB_Information)";
        }
        else
        {
            temp = "SELECT * FROM MLB_Information WHERE " + filterCol + " = '" + filterBy + "'";
        }
        this->qry->prepare(temp);
    }

    this->qry->exec();
    this->model->setQuery(*qry);
    this->tableView->setModel(model);


}

void tablefilter::resetFilters()
{
    ui->individualTeamEntry->clear();
    ui->sortByEntry->setCurrentIndex(10);
    ui->onlyShowEntry->setCurrentIndex(15);
    ui->individualTeamEntry->setCurrentIndex(0);
    individualTeamSelected = false;
    sorterSelected = false;
    filterSelected = false;
    orderBy = "NONE";
    filterBy = "NONE";
    filterCol = "";
    indiTeam = "";
    // resets individual team selection
    this->qry->prepare("SELECT TEAM_NAME FROM MLB_Information");
    this->qry->exec();

    ui->individualTeamEntry->addItem("NONE");

    while (qry->next())
    {
        ui->individualTeamEntry->addItem(qry->value(0).toString());
    }
}

void tablefilter::on_sortByEntry_currentIndexChanged(int index)
{
    switch (index)
    {
        case 0: orderBy = "TEAM_NAME"; break;
        case 1: orderBy = "STADIUM_NAME"; break;
        case 2: orderBy = "DATE_OPENED"; break;
        case 3: orderBy = "LOCATION"; break;
        case 4: orderBy = "LEAGUE"; break;
        case 5: orderBy = "SEATING_CAPACITY"; break;
        case 6: orderBy = "DISTANCE_TO_CENTER_FIELD"; break;
        case 7: orderBy = "BALLPARK_TYPOLOGY"; break;
        case 8: orderBy = "PLAYING_SURFACE"; break;
        case 9: orderBy = "ROOF_TYPE"; break;
        case 10: orderBy = "NONE"; sorterSelected = false; return;
    }
    sorterSelected = true;
    return;
}

void tablefilter::on_onlyShowEntry_currentIndexChanged(int index)
{
    switch (index)
    {
        case 0:  filterBy = "American"; filterCol = "LEAGUE"; break;
        case 1:  filterBy = "National"; filterCol = "LEAGUE"; break;
        case 2:  filterBy = "max"; filterCol = "DISTANCE_TO_CENTER_FIELD"; break;
        case 3:  filterBy = "min"; filterCol = "DISTANCE_TO_CENTER_FIELD"; break;
        case 4:  filterBy = "Retro Modern"; filterCol = "BALLPARK_TYPOLOGY"; break;
        case 5:  filterBy = "Retro Classic"; filterCol = "BALLPARK_TYPOLOGY"; break;
        case 6:  filterBy = "Jewel Box"; filterCol = "BALLPARK_TYPOLOGY"; break;
        case 7:  filterBy = "Modern"; filterCol = "BALLPARK_TYPOLOGY"; break;
        case 8:  filterBy = "Multipurpose"; filterCol = "BALLPARK_TYPOLOGY"; break;
        case 9:  filterBy = "Open"; filterCol = "ROOF_TYPE"; break;
        case 10: filterBy = "Retractable"; filterCol = "ROOF_TYPE"; break;
        case 11: filterBy = "Fixed"; filterCol = "ROOF_TYPE"; break;
        case 12: filterBy = "Grass"; filterCol = "PLAYING_SURFACE"; break;
        case 13: filterBy = "AstroTurf GameDay Grass"; filterCol = "PLAYING_SURFACE"; break;
        case 14: filterBy = "AstroTurf GameDay Grass 3D"; filterCol = "PLAYING_SURFACE"; break;
        case 15: filterBy = "NONE"; filterSelected = false; return;
    }
    filterSelected = true;
    return;
}




