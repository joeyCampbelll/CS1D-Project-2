#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

void MainWindow::fillTeamComboBox()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    QSqlQuery* qry = new QSqlQuery();

    qry->prepare("SELECT DISTINCT TEAM_NAME FROM SOUVENIRS");

    if(qry->exec())
    {
        qDebug() << "college table updated";
    }
    else
        qDebug() << "failed";

    model->setQuery(*qry);

    ui->selectTeamBox->setModel(model);
}

void MainWindow::on_editSouvenirsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->souvenirTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    fillTeamComboBox();
}

void MainWindow::on_exitEditButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_deleteSouvenirButton_clicked()
{
    QString souvenirName = ui->selectSouvenirBox->currentText();
    QString teamName =  ui->selectTeamBox->currentText();
    QMessageBox msgBox;
    msgBox.setInformativeText("Would you like to delete " + souvenirName + " from " + teamName + "?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int ret = msgBox.exec();

    if(ret == QMessageBox::Yes)
    {
        myDb.deleteSouvenir(souvenirName, teamName);
        QMessageBox msgBox2;
        msgBox2.setText(souvenirName + " deleted from " + teamName + '.');
        msgBox2.exec();
        updateSouvenirTableView();
    }
}

void MainWindow::on_addSouvenirButton_clicked()
{
    QString teamName =  ui->selectTeamBox->currentText();
    QString souvenirName = ui->selectSouvenirBox->currentText();
    ui->stackedWidget->setCurrentIndex(4);
    ui->updateTeamLabel_3->setText(teamName);
}

void MainWindow::on_editSouvenirButton_clicked()
{
    QString teamName =  ui->selectTeamBox->currentText();
    QString souvenirName = ui->selectSouvenirBox->currentText();
    ui->stackedWidget->setCurrentIndex(5);
    ui->updateTeamLabel->setText(teamName);
    originalName = souvenirName;
    ui->enterNameBox->setText(souvenirName);
}


void MainWindow::on_selectTeamBox_currentIndexChanged(const QString &arg1)
{
    QString teamName = arg1;
    QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery* qry = new QSqlQuery();

    qry->prepare("SELECT * FROM SOUVENIRS WHERE TEAM_NAME = :teamname");

    qry->bindValue(":teamname", teamName);
    qry->exec();

    model->setQuery(*qry);

    ui->souvenirTableView->setModel(model);

    updateSouvenirTableView();
}

void MainWindow::updateSouvenirTableView() {

    //ui->souvenirTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // update table view

    QString teamName = ui->selectTeamBox->currentText();

    QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery* qry = new QSqlQuery();

    qry->prepare("SELECT * FROM SOUVENIRS WHERE TEAM_NAME = :teamname");

    qry->bindValue(":teamname", teamName);
    qry->exec();

    model->setQuery(*qry);

    ui->souvenirTableView->setModel(model);

    // UPDATE combo box

    QSqlQueryModel* model2 = new QSqlQueryModel();

    QSqlQuery* qry2 = new QSqlQuery();

    qry2->prepare("SELECT SOUVENIR_NAME FROM SOUVENIRS WHERE TEAM_NAME = :teamname");

    qry2->bindValue(":teamname", teamName);
    qry2->exec();

    model2->setQuery(*qry2);
    ui->selectSouvenirBox->setModel(model2);
}

void MainWindow::on_cancelEditButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_enterEditButton_clicked()
{
    if(ui->enterNameBox->text() == "" || ui->enterNameBox->text().isEmpty()) // text field is empty
    {
        QMessageBox msgBox;
        msgBox.setText("ERROR - Please enter in the souvenir name!");
        msgBox.exec();
    }
    else if(ui->enterPriceSpinBox->text() == "0.00") // spin box is empty
    {
        QMessageBox msgBox;
        msgBox.setText("ERROR - Please enter in the souvenir price!");
        msgBox.exec();
    }
    else
    {
        // edit souvenir
        QString newSouvenirName = ui->enterNameBox->text();
        QString teamName = ui->updateTeamLabel->text();
        QString price = ui->enterPriceSpinBox->text();
        myDb.editSouvenir(originalName, teamName, price, newSouvenirName);

        // return to souvenir editor
        ui->stackedWidget->setCurrentIndex(3);

        // clear fields
        ui->enterNameBox->clear();
        ui->enterPriceSpinBox->clear();

        // update table view and combo box
        fillTeamComboBox();
        updateSouvenirTableView();
    }
}

void MainWindow::on_cancelAddButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_enterAddButton_clicked()
{
    if(ui->enterNameBox_3->text() == "" || ui->enterNameBox_3->text().isEmpty()) // text field empty
    {
        QMessageBox msgBox;
        msgBox.setText("ERROR - Please enter in the souvenir name!");
        msgBox.exec();
        ui->enterNameBox_3->clear();
    }
    else if(ui->enterPriceSpinBox_3->text() == "0.00") // spin box empty
    {
        QMessageBox msgBox;
        msgBox.setText("ERROR - Please enter in the souvenir price!");
        msgBox.exec();
        ui->enterPriceSpinBox_3->clear();
    }
    else
    {
        // add souvenir
        QString souvenirName = ui->enterNameBox_3->text();
        QString teamName = ui->updateTeamLabel_3->text();
        QString price = ui->enterPriceSpinBox_3->text();
        myDb.addSouvenir(souvenirName, teamName, price);

        // return to souvenir editor screen
        ui->stackedWidget->setCurrentIndex(3);

        // clear all fields
        ui->enterNameBox_3->clear();
        ui->enterPriceSpinBox_3->clear();

        // update tables and combo box
        fillTeamComboBox();
        updateSouvenirTableView();
    }
}
