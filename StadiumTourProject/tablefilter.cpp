#include "tablefilter.h"
#include "ui_tablefilter.h"

tablefilter::tablefilter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tablefilter)
{
    ui->setupUi(this);

    QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery* qry = new QSqlQuery();

    // Gets each individual team name for combobox
    qry->prepare("SELECT TEAM_NAME FROM MLB_Information");
    qry->exec();
    model->setQuery(*qry);

    this->ui->individualTeamEntry->setModel(model);
}

tablefilter::~tablefilter()
{
    delete ui;
}

void tablefilter::setTableView(QTableView *newTableView)
{
    this->tableView = newTableView;
}

//void tablefilter::on_pushButton_clicked()
//{
//    QSqlQueryModel* model = new QSqlQueryModel();

//    QSqlQuery* qry = new QSqlQuery();

//    qry->prepare("SELECT * FROM MLB_Information WHERE TEAM_NAME = 'Los Angeles Angels'");

////    if(qry->exec())
////    {
////        qDebug() << "MLB Info updated and displayed to table";
////    }
////    else
////    {
////        qDebug() << "MLB info failed to display";
////    }
//    qry->exec();

//    model->setQuery(*qry);

//    this->tableView->setModel(model);
//    this->tableView->resizeColumnsToContents();
//}

void tablefilter::on_individualTeamEntry_activated(const QString &arg1)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery* qry = new QSqlQuery();

    QString temp =  "\'" + arg1 + "\'";
    // Gets each individual team name for combobox
    qry->prepare("SELECT * FROM MLB_Information WHERE TEAM_NAME = " + temp);
    qry->exec();
    model->setQuery(*qry);

    this->tableView->setModel(model);
}

void tablefilter::on_exitFiltersButton_clicked()
{
    this->close();
}
