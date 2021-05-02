#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextBrowser>

void MainWindow::fillStartTeam()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    QSqlQuery* qry = new QSqlQuery();

    qry->prepare("SELECT TEAM_NAME FROM MLB_Information");

    if(qry->exec())
    {
        qDebug() << "start team combo box loaded";
    }
    else
        qDebug() << "start team combo box failed";

    while(qry->next())//loads the combo box on the CTO page
    {
        allTeamsList.push_back(qry->value(0).toString());
    }

    model->setQuery(*qry);

    ui->comboBox_startingTeam->setModel(model);
    ui->comboBox_startingTeamChooseTeams->setModel(model);
    for(int i = 0; i <allTeamsList.size(); i++)
    {
        ui->CTO_comboBox->addItem(allTeamsList[i]);
    }
}

void MainWindow::on_backButton_tripPlanner_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_comboBox_startingTeam_activated(const QString &startingTeam)
{
    QSqlQueryModel* model=new QSqlQueryModel();

    QSqlQuery* qry = new QSqlQuery();

    qDebug() << "STARTING TEAM: " << startingTeam << Qt::endl;

    qry->prepare("SELECT TEAM_NAME FROM MLB_Information WHERE TEAM_NAME != :startingTeam");
    qry->bindValue(":startingTeam", startingTeam);

    if(qry->exec())
    {
        qDebug() << "end team combo box loaded";
    }
    else
        qDebug() << "end team combo box failed";

    model->setQuery(*qry);

    ui->comboBox_endingTeam->setDisabled(false);
    ui->comboBox_endingTeam->setModel(model);

    if(SSRstartClicked == true)
    {
        inputValues.clear();
        ui->textBrowser_SSR->clear();
        SSRstartClicked = false;
    }
}

//Start Single Stadium Route(SSR) trip
void MainWindow::on_pushButton_SSRplanTrip_clicked()
{
    inputValues.clear();
    ui->textBrowser_SSR->clear();
    SSRstartClicked = true;
    inputValues.push_back(ui->comboBox_startingTeam->currentText());
    inputValues.push_back(ui->comboBox_endingTeam->currentText());

    dijkstras = new graphAM();
    fastestRoute = dijkstras->dijkstra1to1(inputValues[0], inputValues[1]);

    for(int i = 0; i < fastestRoute.size(); i++)
    {
        if(i > 0)
        {
            ui->textBrowser_SSR->append(QString::number(i) + ". " + fastestRoute.at(i) + '\n');
        }
        else
        {
            ui->textBrowser_SSR->append("Distance: " + fastestRoute.at(i) + '\n');
        }
    }

    ui->textBrowser_SSR->selectAll();
    ui->textBrowser_SSR->setAlignment(Qt::AlignCenter);
    ui->pushButton_SSRstartTrip->show();
}

void MainWindow::on_pushButton_SSRstartTrip_clicked()
{
    //TO-DO connect with souvenir shop
}

void MainWindow::initializeList()
{
    QSqlQuery *query = new QSqlQuery();

    checkBoxVector.clear();
    tempTeamNamesVector.clear();
    teamNamesVector.clear();

    QWidget *container = new QWidget;
    QVBoxLayout *vBoxLayout = new QVBoxLayout;

    container->setLayout(vBoxLayout);

    ui->scrollArea_displayAllStadiumsSSR->setWidget(container);

    query->prepare("SELECT TEAM_NAME FROM MLB_Information");
    if(!query->exec())
    {
        qDebug() << "Custom path initializeList query failed";
    }
    else
    {
        startTeamName = ui->comboBox_startingTeamChooseTeams->currentText();

        while(query->next())
        {
            if(startTeamName != query->value(0).toString())
            {
                QCheckBox* checkBox = new QCheckBox(query->value(0).toString());
                QString tempTeam = (query->value(0).toString());
                checkBox->setCheckState(Qt::CheckState::Unchecked);
                checkBoxVector.push_back(checkBox);
                tempTeamNamesVector.push_back(tempTeam);
            }
        }

        for(int i = 0; i < checkBoxVector.size(); i++)
        {
            vBoxLayout->addWidget(checkBoxVector[i]);
        }
    }
}

void MainWindow::CheckboxChanged()
{
    qDebug() << "Signal caught";

    int checkedCount = 0;

    for(int i = 0; i < checkBoxVector.size(); i++)
    {
        if(checkBoxVector[i]->checkState() == Qt::CheckState::Checked)
        {
            qDebug() << tempTeamNamesVector[i] << Qt::endl;
            teamNamesVector.push_back(tempTeamNamesVector[i]);
            checkedCount++;
        }
    }

    if(checkedCount == 11)
    {
        for(int i = 0; i < checkBoxVector.size(); i++)
        {
            if(checkBoxVector[i]->checkState() == Qt::CheckState::Unchecked)
            {
                checkBoxVector[i]->setDisabled(true);
            }
            qDebug() << checkBoxVector[i] << Qt::endl;
        }
    }
    else
    {
        for(int i = 0; i < checkBoxVector.size(); i++)
        {
            checkBoxVector[i]->setDisabled(false);
        }
    }
}

void MainWindow::on_comboBox_startingTeamChooseTeams_activated()
{
    initializeList();
}

void MainWindow::on_pushButton_generateRouteChooseTeams_clicked()
{
    ui->textBrowser_ChooseTeams->clear();
    teamNamesVector.clear();
    startTeamName = ui->comboBox_startingTeamChooseTeams->currentText();
    teamNamesVector.push_back(startTeamName);

    CheckboxChanged();
    //CALL DIJKSTRAS ALGO HERE

    for(int i = 0; i < teamNamesVector.size(); i++)
    {
        ui->textBrowser_ChooseTeams->append(QString::number(i + 1) + ". " + teamNamesVector.at(i));
    }

    ui->pushButton_startTripChooseTeams->show();
}

void MainWindow::on_planTripButton_MiamiMarlins_clicked()
{
    teamNamesVector.clear();

    marlinsParkDFS = new graphAL();
    marlinsParkDFS->depthFirstSearch("Marlins Park");
    QList<QString> temp = marlinsParkDFS->getRoute();
    ui->textBrowser_MiamiMarlins->append("DISTANCE: " + QString::number(marlinsParkDFS->getDistance()));
    ui->textBrowser_MiamiMarlins->append("\n");

    for(int i = 0; i < temp.length(); i++)
    {
        QString tempS = QString::number(i + 1) + ". ";
        ui->textBrowser_MiamiMarlins->append(tempS + temp[i]);
    }
    ui->startTripButton_MiamiMarlins->show();

}

void MainWindow::on_startTripButton_MiamiMarlins_clicked()
{
    //TO-DO connect trip planner with souvenir shop
}

void MainWindow::on_addButton_CTO_clicked()
{
    if(CTOstartButtonClicked)//if start button is clicked the output widget is cleared and startbuttonClicked is set to false
        {
            ui->textBrowser_CTO->clear();
            CTOstartButtonClicked = false;
        }

        if(customTeamNameList.size() != allTeamsList.size())
        {
            customTeamNameList.push_back(ui->CTO_comboBox->currentText());//gets the school being removed
            ui->textBrowser_CTO->append((QString::number(counter+1) + ". " + ui->CTO_comboBox->currentText()));//adds the last item added the customNameList to the List widget
            qDebug() << ui->CTO_comboBox->currentText();
            ui->CTO_comboBox->removeItem(ui->CTO_comboBox->currentIndex());//removes the school selected from the list
            ui->planTripButton_CTO->show();
            counter++;
        }
        else
        {
            QMessageBox::information(this, "Error", "Nothing to Add");
        }

}

void MainWindow::on_startButton_CTO_clicked()
{
    //routes to souvenir
    qDebug() << "Will Take you to souvenir page" << Qt::endl;
}

void MainWindow::on_removeButton_CTO_clicked()
{
    if(!customTeamNameList.empty())
    {
        ui->CTO_comboBox->addItem(customTeamNameList[customTeamNameList.size()-1]);
        ui->CTO_comboBox->model()->sort(0);
        customTeamNameList.pop_back();
        ui->textBrowser_CTO->clear();
        counter--;

        if(customTeamNameList.empty())
        {
            ui->planTripButton_CTO->hide();
        }

        for(int i = 0; i<customTeamNameList.size(); i++)//outputs the order of school visited on tripPLan page
        {

            ui->textBrowser_CTO->append(QString::number(i+1) + ". " + customTeamNameList[i]);
        }
    }
    else
    {
        QMessageBox::information(this, "Error", "Nothing to Remove");
    }
}

void MainWindow::on_resetButton_CTO_clicked()
{
    ui->CTO_comboBox->clear();
    for(int i = 0; i <allTeamsList.size(); i++)
    {
        ui->CTO_comboBox->addItem(allTeamsList[i]);
    }

    ui->textBrowser_CTO->clear();

    ui->planTripButton_CTO->hide();

    ui->addButton_CTO->show();

    ui->startButton_CTO->hide();

    ui->removeButton_CTO->show();

    customTeamNameList.clear();

    fastestRoute.clear();

    counter = 0;
}

void MainWindow::on_planTripButton_CTO_clicked()
{
    double totalDistance;

    counter = 0;

    fastestRoute.clear();
    //totalDistance = shortDistance(startingSchool, tempList.size());//Add dijkstras here
    fastestRoute = customTeamNameList;

    ui->textBrowser_CTO->clear();//clears the wigit each time before displaying the shortest distances

    for(int i = 0; i<fastestRoute.size(); i++)//outputs the order of school visited on tripPLan page
    {

        ui->textBrowser_CTO->append(QString::number(i+1) + ". " + fastestRoute[i]);
    }

    customTeamNameList.clear();//clears the custom name list after the start button is clicked
    ui->CTO_comboBox->clear();//clears the combo box and reloads it
    fillStartTeam();
    CTOstartButtonClicked  = true;//getting flag to true
    ui->planTripButton_CTO->hide();
    ui->addButton_CTO->hide();
    ui->removeButton_CTO->hide();
    ui->startButton_CTO->show();

}
