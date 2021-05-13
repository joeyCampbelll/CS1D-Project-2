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
    /**
    * @brief table filter constructor
    *
    * @param *parent
    */
    explicit tablefilter(QWidget *parent = nullptr);

    /**
    * @brief table filter destructor
    */
    ~tablefilter();

    /**
    * @brief sets table view
    *
    * initializes and sets up graph table view
    *
    * @param *newTableView
    */
    void setTableView(QTableView *newTableView);

    /**
    * @brief resets filters
    *
    * resets all table filters
    *
    */
    void resetFilters();

private slots:

    /**
    * @brief function to hand exit filters button clicked
    */
    void on_exitFiltersButton_clicked();

    /**
    * @brief function to apply filters
    *
    * applies currently selected filters
    *
    */
    void applyFilters();

    /**
    * @brief function to handle combo box changed
    *
    * @param index
    */
    void on_sortByEntry_currentIndexChanged(int index);

    /**
    * @brief function to handle combo box changed
    *
    * @param index
    */
    void on_onlyShowEntry_currentIndexChanged(int index);

    /**
    * @brief function to handle combo box activated
    *
    * @param index
    */
    void on_individualTeamEntry_activated(int index);


private:
    /**
    * @brief table view pointer
    */
    QTableView* tableView;

    /**
    * @brief pointer to set table model
    */
    QSqlQueryModel* model;

    /**
    * @brief pointer to access SQL query
    */
    QSqlQuery* qry;

    /**
    * @brief checks if filter is selected
    */
    bool filterSelected;

    /**
    * @brief checks if sorter is selected
    */
    bool sorterSelected;

    /**
    * @brief checks if individual team is selected
    */
    bool individualTeamSelected;

    /**
    * @brief value for ordered by filter
    */
    QString orderBy;

    /**
    * @brief value for filter by filter
    */
    QString filterBy;

    /**
    * @brief value for individual team filter
    */
    QString indiTeam;

    /**
    * @brief value for filtering by column
    */
    QString filterCol;

    /**
    * @brief pointer to access UI
    */
    Ui::tablefilter *ui;
};

#endif // TABLEFILTERS_H
