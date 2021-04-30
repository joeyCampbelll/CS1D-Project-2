#include "souvenirshop.h"
#include "ui_souvenirshop.h"

souvenirshop::souvenirshop(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::souvenirshop)
{
    ui->setupUi(this);

    cellClicked = false;

    currentTotal = 0;
    runningTotal = 0;

    stadiumList.push_back("Dodger Stadium");
    stadiumList.push_back("Minute Maid Park");
    stadiumList.push_back("Great American Ball Park");
    stadiumList.push_back("Target Field");

    ui->souvenirShopTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    container = new QWidget;
    vBoxLayout = new QVBoxLayout;

    container->setLayout(vBoxLayout);

    ui->purchasedArea->setWidget(container);

    ui->updateTotalPrice->setText("$0.00");

    fillSelectStadiumBox();
}

souvenirshop::~souvenirshop()
{
    delete ui;
}


void souvenirshop::fillSelectStadiumBox()
{
    for(int i = 0; i < stadiumList.size(); i++)
    {
        ui->selectStadiumBox->addItem(stadiumList[i]);
    }
}

void souvenirshop::updateSouvenirShopTableView(QString stadiumName) {

     QSqlQueryModel* model=new QSqlQueryModel();

     QSqlQuery* qry=new QSqlQuery();

     qry->prepare("SELECT SOUVENIR_NAME, SOUVENIR_PRICE FROM Souvenirs WHERE TEAM_NAME = (SELECT TEAM_NAME FROM MLB_Information WHERE STADIUM_NAME = :stadiumName)");
     qry->bindValue(":stadiumName", stadiumName);

     if(qry->exec())
     {
         qDebug() << "Souvenirs updated";
     }

     model->setQuery(*qry);
     ui->souvenirShopTableView->setModel(model);
}

void souvenirshop::on_selectStadiumBox_currentIndexChanged(const QString &arg1)
{
    updateSouvenirShopTableView(arg1);
}

void souvenirshop::on_souvenirShopTableView_clicked(const QModelIndex &index)
{
    cellClicked = true;

    if(index.isValid())
    {
        int row = index.row();
        tempSouvenir = index.sibling(row, 0).data().toString();
        price = index.sibling(row, 1).data().toString().replace("$", "").toDouble();
        priceStr = index.sibling(row, 1).data().toString();

        qDebug() << tempSouvenir << Qt::endl << priceStr << Qt::endl;
    }
}

void souvenirshop::on_buyButton_clicked()
{
    if (cellClicked && ui->quantitySpinBox->value() != 0)
    {
        int quantity =  ui->quantitySpinBox->value();
        ui->quantitySpinBox->setValue(1);

        for (int i = 0; i< quantity; i++){
            currentTotal = currentTotal + price;
        }

        runningTotal += currentTotal;

        QString quantityStr = QString::number(quantity);
        QString currentTotalStr = QString::number(currentTotal);

        QString space = "";
        QString space2 = "";

        for (int i = 0; i < 27-tempSouvenir.length(); i++)
        {
            space = space + " ";
        }

        for (int i = 0; i < 8 - currentTotalStr.length(); i++)
        {
            space2 = space2 + " ";
        }

        QString stadiumName = ui->selectStadiumBox->currentText();

        QLabel *souvenirName = new QLabel(stadiumName + "\n" + quantityStr + " x\t"+ tempSouvenir  +  space + "$" + space2 + currentTotalStr);

        ui->updateTotalPrice->setText("$" + QString::number(runningTotal));

        vBoxLayout->addWidget(souvenirName);

        //ui->label_purchasedSouvAtCampus->setText("Souvenirs Purchased Here: " + QVariant(purchasedSouvAtCampus).toString());
        //ui->label_subCostAtCampus->setText("Cost of Souvenirs Purchased Here: $" + QString::number(subCostAtCampus, 'f', 2));

    }


    if(!cellClicked)
    {
        QMessageBox::information(this, "Warning", "No Souvenir Selected");
    }

    if(ui->quantitySpinBox->value() == 0)
    {
        QMessageBox::information(this, "Warning", "Select Quantity Desired");
    }
}



void souvenirshop::on_finishButton_clicked()
{
    this->close();
}
