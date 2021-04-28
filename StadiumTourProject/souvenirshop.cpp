#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::on_souvenirShopButton_clicked()
{
    cellClicked = false;
    stadiumCount = 0;
    runningTotal = 0.00;
    currentTotal = 0.00;
    stadiumList.push_back("Dodger Stadium");
    stadiumList.push_back("Minute Maid Park");
    stadiumList.push_back("Great American Ball Park");
    stadiumList.push_back("Target Field");

    ui->stackedWidget->setCurrentIndex(10);
    ui->souvenirShopTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->stadiumLabel_2->setText(stadiumList[stadiumCount]);

     QSqlQueryModel* model=new QSqlQueryModel();

     QSqlQuery* qry=new QSqlQuery();

     qry->prepare("SELECT SOUVENIR_NAME, SOUVENIR_PRICE FROM Souvenirs WHERE TEAM_NAME = (SELECT TEAM_NAME FROM MLB_Information WHERE STADIUM_NAME = :stadiumName)");
     qry->bindValue(":stadiumName", stadiumList[stadiumCount]);

     if(qry->exec())
     {
         qDebug() << "Souvenirs updated";
     }

     model->setQuery(*qry);

     ui->souvenirShopTableView->setModel(model);

//     ui->updatePriceLabel->setText(currentTotal);
//     ui->updateTotalLabel->setText(total);


     stadiumCount++;


}

void MainWindow::on_nextStadiumButton_clicked()
{
    if(stadiumCount == stadiumList.size()) {
        ui->stackedWidget->setCurrentIndex(0);
    }
    else {
        updateSouvenirShopTableView();
    }
}

void MainWindow::updateSouvenirShopTableView() {
    ui->stadiumLabel_2->setText(stadiumList[stadiumCount]);

     QSqlQueryModel* model=new QSqlQueryModel();

     QSqlQuery* qry=new QSqlQuery();

     qry->prepare("SELECT SOUVENIR_NAME, SOUVENIR_PRICE FROM Souvenirs WHERE TEAM_NAME = (SELECT TEAM_NAME FROM MLB_Information WHERE STADIUM_NAME = :stadiumName)");
     qry->bindValue(":stadiumName", stadiumList[stadiumCount]);

     if(qry->exec())
     {
         qDebug() << "Souvenirs updated";
     }

     model->setQuery(*qry);

     ui->souvenirShopTableView->setModel(model);

//     ui->updatePriceLabel->setText(currentTotal);
//     ui->updateTotalLabel->setText(runningTotal);

     stadiumCount++;
}

void MainWindow::on_souvenirShopTableView_clicked(const QModelIndex &index)
{
    cellClicked = true;

    if(index.isValid())
    {
        int row = index.row();
        tempSouvenir = index.sibling(row, 0).data().toString();
        price = index.sibling(row, 1).data().toString().replace("$", "").toDouble();

        qDebug() << tempSouvenir << Qt::endl << price << Qt::endl;
    }
}

void MainWindow::on_buyButton_clicked()
{
//    if (cellClicked){
//        customAmount =  ui->customInput->value();

//        ui->customInput->setValue(1);

//        for (int i = 0; i<customAmount; i++){
//            grandTotal = grandTotal + souvenirCost;
//            purchasedSouvAtCampus++;
//            subCostAtCampus += souvenirCost;
//        }

//        QString customAmountStr = QString::number(customAmount);
//        QString customItemPrice = QString::number(souvenirCost*customAmount);

//        QString space = "";
//        QString space2 = "";

//        for (int i = 0; i<27-tempSouvenir.length(); i++)
//            space = space + " ";

//        for (int i = 0; i<8-customItemPrice.length(); i++)
//            space2 = space2 + " ";

//        QLabel *souvenirName = new QLabel(customAmountStr + " x\t"+ tempSouvenir  +  space + "$" + space2 + customItemPrice);

//        vBoxLayout->addWidget(souvenirName);


//        ui->label_purchasedSouvAtCampus->setText("Souvenirs Purchased Here: " + QVariant(purchasedSouvAtCampus).toString());
//        ui->label_subCostAtCampus->setText("Cost of Souvenirs Purchased Here: $" + QString::number(subCostAtCampus, 'f', 2));

//    }
//    else
//    {
//        QMessageBox::information(this, "Warning", "No Souvenir Selected");
//    }
}
