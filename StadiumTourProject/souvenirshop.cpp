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

    teamList.push_back("Boston Red Sox");
    teamList.push_back("Chicago White Sox");
    teamList.push_back("Colorado Rockies");
    teamList.push_back("New York Mets");
    teamList.push_back("Minnesota Twins");

    teamName = teamList[0];

    ui->souvenirShopTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->updateTotalPrice->setText("$0.00");

    fillSelectStadiumBox();
}

souvenirshop::~souvenirshop()
{
    delete ui;
}


void souvenirshop::fillSelectStadiumBox()
{
    for(int i = 0; i < teamList.size(); i++)
    {
        ui->selectStadiumBox->addItem(teamList[i]);
        qDebug() << "Name added";
    }
}

void souvenirshop::updateSouvenirShopTableView(QString team) {
     QSqlQueryModel* model=new QSqlQueryModel();

     QSqlQuery* qry=new QSqlQuery();

     qry->prepare("SELECT SOUVENIR_NAME, SOUVENIR_PRICE FROM Souvenirs WHERE TEAM_NAME = :teamname");
     qry->bindValue(":teamname", teamName);

     if(qry->exec())
     {
         qDebug() << "Souvenirs updated";
     }

     model->setQuery(*qry);
     ui->souvenirShopTableView->setModel(model);
}

void souvenirshop::on_selectStadiumBox_currentIndexChanged(const QString &arg1)
{

    teamName = arg1;
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

    currentTotal = 0;
    if (cellClicked && ui->quantitySpinBox->value() != 0)
    {
        int quantity =  ui->quantitySpinBox->value();
        ui->quantitySpinBox->setValue(1);

        for (int i = 0; i< quantity; i++){
            currentTotal = currentTotal + price;
        }

        souvenirPrices.push_back(currentTotal);
        runningTotal += currentTotal;

        QString quantityStr = QString::number(quantity);
        QString currentTotalStr = QString::number(currentTotal);

        qDebug() << currentTotal;
        qDebug() << currentTotalStr;

        QString space = "";
        QString space2 = "";

        for (int i = 0; i < 27-tempSouvenir.length(); i++)
        {
            space = space + " ";
        }

        findStadiumName();
        QString souvenirName = (stadiumName + "-> " + teamName + "\n" + quantityStr + " x\t"+ tempSouvenir  +  space + "\n\t\t\t--> $" + currentTotalStr);

        souvenirNames.push_back(souvenirName);
        ui->purchaseListWidget->addItem(souvenirName);
        ui->updateTotalPrice->setText("$" + QString::number(runningTotal));
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

void souvenirshop::findStadiumName()
{
    QSqlQuery* qry=new QSqlQuery();
    qDebug() << teamName;

    qry->prepare("SELECT STADIUM_NAME FROM MLB_Information WHERE TEAM_NAME = :teamname");
    qry->bindValue(":teamname", teamName);
    qry->exec();

    if(qry->next())
    {
        qry->first();
        stadiumName = qry->value(0).toString();
        qDebug() << stadiumName;
        qDebug() << teamName;
    }
}

void souvenirshop::on_undoButton_clicked()
{
    if(souvenirNames.size() != 0)
    {
        for ( int a = 0; a < ui->purchaseListWidget->count()+1; a++ )
        {
            if ( ui->purchaseListWidget->item(a)->text() == souvenirNames.last() )
            {
                delete ui->purchaseListWidget->takeItem(a);
                souvenirNames.removeLast();
                runningTotal = runningTotal - souvenirPrices.last();
                souvenirPrices.removeLast();
                ui->updateTotalPrice->setText("$" + QString::number(runningTotal));
            }
        }
    }

    if(souvenirNames.size() == 0)
    {
        runningTotal = 0.00;
        ui->updateTotalPrice->setText("$0.00");
    }
}
