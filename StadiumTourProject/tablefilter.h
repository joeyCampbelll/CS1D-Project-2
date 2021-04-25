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

    void resetFilters();

private slots:

    void on_exitFiltersButton_clicked();

    void applyFilters();

    void on_sortByEntry_currentIndexChanged(int index);

    void on_onlyShowEntry_currentIndexChanged(int index);

    void on_individualTeamEntry_currentTextChanged(const QString &arg1);

private:
    QTableView* tableView;
    QSqlQueryModel* model;
    QSqlQuery* qry;
    bool filterSelected;
    bool sorterSelected;
    bool individualTeamSelected;
    QString orderBy;
    QString filterBy;
    QString indiTeam;
    QString filterCol;
    Ui::tablefilter *ui;
};

#endif // TABLEFILTERS_H
