#ifndef TABLEFILTERS_H
#define TABLEFILTERS_H

#include <QWidget>
#include <QTableView>
#include "database.h"


namespace Ui {
class tablefilter;
}

class tablefilter : public QWidget
{
    Q_OBJECT

public:
    explicit tablefilter(QWidget *parent = nullptr);
    ~tablefilter();

    void setTableView(QTableView *newTableView);

private slots:

    void on_individualTeamEntry_activated(const QString &arg1);

    void on_exitFiltersButton_clicked();

    void applyFilters(QString indiTeam, QString sorter, QString filter);

private:
    QTableView* tableView;
    QSqlQueryModel* model;
    QSqlQuery* qry;
    bool filterSelected;
    bool sorterSelected;
    bool individualTeamSelected;
    Ui::tablefilter *ui;
};

#endif // TABLEFILTERS_H
