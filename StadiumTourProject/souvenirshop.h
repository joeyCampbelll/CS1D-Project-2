#ifndef SOUVENIRSHOP_H
#define SOUVENIRSHOP_H

#include <QWidget>
#include "database.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QListWidget>

namespace Ui {
class souvenirshop;
}

class souvenirshop : public QWidget
{
    Q_OBJECT

public:
    /**
    * @brief souvenir shop constructor
    *
    * constructs souvenir shop and initializes value to
    * passed in parameters
    *
    * @param selectedTeamNames
    * @param *parent
    */
    explicit souvenirshop(QVector<QString> selectedTeamNames, QWidget *parent = nullptr);

    /**
    * @brief souvenir shop destructor
    */
    ~souvenirshop();

    /**
    * @brief updates table view
    *
    * updates souvenir table in souvenir
    * shop
    *
    * @param team
    */
    void updateSouvenirShopTableView(QString team);

    /**
    * @brief fills stadium combo box
    *
    * fills combo box with all current team
    * names
    *
    */
    void fillSelectStadiumBox();

    /**
    * @brief finds stadium using team
    *
    * uses team name to find the stadium
    * name and retrieve souvenirs
    *
    */
    void findStadiumName();

private slots:
    /**
    * @brief function to handle combo box activation
    *
    * @param arg1
    */
    void on_selectStadiumBox_currentIndexChanged(const QString &arg1);

    /**
    * @brief function to handle finish button clicked
    */
    void on_finishButton_clicked();

    /**
    * @brief function to handle table view clicked
    *
    * @param index
    */
    void on_souvenirShopTableView_clicked(const QModelIndex &index);

    /**
    * @brief function to handle buy button clicked
    */
    void on_buyButton_clicked();

    /**
    * @brief function to handle undo button clicked
    */
    void on_undoButton_clicked();

private:
    /**
    * @brief vector to hold team names
    */
    QVector<QString> teamList;

    /**
    * @brief current price total
    */
    double currentTotal;

    /**
    * @brief current price running total
    */
    double runningTotal;

    /**
    * @brief quantity of souvenirs
    */
    int quantity;

    /**
    * @brief temporary souvenir name
    */
    QString tempSouvenir;

    /**
    * @brief souvenir price
    */
    double price;

    /**
    * @brief souvenir price as a string
    */
    QString priceStr;

    /**
    * @brief checks if souvenir table cell was clicked
    */
    bool cellClicked;

    /**
    * @brief team name
    */
    QString teamName;

    /**
    * @brief stadium name
    */
    QString stadiumName;

    /**
    * @brief vector of purchased souvenir names
    */
    QVector<QString> souvenirNames;

    /**
    * @brief vector of purchased souvenir prices
    */
    QVector<double> souvenirPrices;

    /**
    * @brief pointer to access UI
    */
    Ui::souvenirshop *ui;
};

#endif // SOUVENIRSHOP_H
