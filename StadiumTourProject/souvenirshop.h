#ifndef SOUVENIRSHOP_H
#define SOUVENIRSHOP_H

#include <QWidget>
#include "database.h"

#include <QMessageBox>
#include <QVBoxLayout>

namespace Ui {
class souvenirshop;
}

class souvenirshop : public QWidget
{
    Q_OBJECT

public:
    explicit souvenirshop(QWidget *parent = nullptr);
    ~souvenirshop();

    void updateSouvenirShopTableView(QString stadiumName);

    void fillSelectStadiumBox();

private slots:
    void on_selectStadiumBox_currentIndexChanged(const QString &arg1);

    void on_finishButton_clicked();

    void on_souvenirShopTableView_clicked(const QModelIndex &index);

    void on_buyButton_clicked();


private:
    QVector<QString> stadiumList;
    double currentTotal;
    double runningTotal;
    int quantity;
    QString tempSouvenir;
    double price;
    QString priceStr;
    bool cellClicked;
    Ui::souvenirshop *ui;

    QWidget *container;
    QVBoxLayout *vBoxLayout;
};

#endif // SOUVENIRSHOP_H
