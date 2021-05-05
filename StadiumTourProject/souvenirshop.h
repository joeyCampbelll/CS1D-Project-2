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
    explicit souvenirshop(QVector<QString> selectedTeamNames, QWidget *parent = nullptr);
    ~souvenirshop();

    void updateSouvenirShopTableView(QString team);

    void fillSelectStadiumBox();

    void findStadiumName();

private slots:
    void on_selectStadiumBox_currentIndexChanged(const QString &arg1);

    void on_finishButton_clicked();

    void on_souvenirShopTableView_clicked(const QModelIndex &index);

    void on_buyButton_clicked();


    void on_undoButton_clicked();

private:
    QVector<QString> teamList;
    double currentTotal;
    double runningTotal;
    int quantity;
    QString tempSouvenir;
    double price;
    QString priceStr;
    bool cellClicked;
    QString teamName;
    QString stadiumName;
    QVector<QString> souvenirNames;
    QVector<double> souvenirPrices;
    Ui::souvenirshop *ui;
};

#endif // SOUVENIRSHOP_H
