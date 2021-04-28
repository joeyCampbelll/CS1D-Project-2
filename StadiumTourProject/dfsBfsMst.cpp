#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_dfsBfsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);

    ui->stadiumSelector->clear();
    ui->displayRoute->clear();

    // Gets each individual stadium name for combobox
    QSqlQuery* qryStadiums = new QSqlQuery();
    qryStadiums->prepare("SELECT DISTINCT ORIGINATED_STADIUM FROM Distances");
    qryStadiums->exec();

    ui->stadiumSelector->addItem("NONE");

    // iterates through the querys
    while (qryStadiums->next())
    {
        ui->stadiumSelector->addItem(qryStadiums->value(0).toString());
    }

    selectedStadium = "NONE";
}

void MainWindow::on_generateMST_clicked()
{

}

void MainWindow::on_generateBFS_clicked()
{
    ui->displayRoute->clear();
    if (selectedStadium != "NONE")
    {
        graphAdjMatr = new graphAM();
        graphAdjMatr->breadthFirstSearch(selectedStadium);

        QList<QString> temp = graphAdjMatr->getRoute();
        ui->displayRoute->append("DISTANCE: " + QString::number(graphAdjMatr->getDistance()));
        ui->displayRoute->append("\n");

        for(int i = 0; i < temp.length(); i++)
        {
            QString tempS = QString::number(i + 1) + ". ";
            ui->displayRoute->append(tempS + temp[i]);
        }
    }
    else
    {
        return;
    }
}

void MainWindow::on_generateDFS_clicked()
{
    ui->displayRoute->clear();

    if (selectedStadium != "NONE")
    {
        graphAdjList = new graphAL();
        graphAdjList->depthFirstSearch(selectedStadium);
        QList<QString> temp = graphAdjList->getRoute();
        ui->displayRoute->append("DISTANCE: " + QString::number(graphAdjList->getDistance()));
        ui->displayRoute->append("\n");

        for(int i = 0; i < temp.length(); i++)
        {
            QString tempS = QString::number(i + 1) + ". ";
            ui->displayRoute->append(tempS + temp[i]);
        }
    }
    else
    {
        return;
    }
}

void MainWindow::on_stadiumSelector_activated(const QString &arg1)
{
    selectedStadium = arg1;
}

void MainWindow::on_exitDfsBfsMstPage_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
