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

    model->setQuery(*qry);

    ui->comboBox_startingTeam->setModel(model);
    ui->comboBox_startingTeamChooseTeams->setModel(model);
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
    fastestRoute.clear();
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

    if(checkedCount == 29)
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
    dijkstrasChooseTeams = new graphAM();
    fastestRoute.clear();
    fastestRoute = dijkstrasChooseTeams->dijkstraAll(teamNamesVector);

    //GET RID OF THIS AFTER IMPLEMENTING DIJKSTRAS
//    fastestRoute = teamNamesVector;

    for(int i = 0; i < fastestRoute.size(); i++)
    {
        if(i > 0)
        {
            ui->textBrowser_ChooseTeams->append(QString::number(i) + ". " + fastestRoute.at(i));
        }
        else
        {
            ui->textBrowser_ChooseTeams->append("Distance: " + fastestRoute.at(i));
        }
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

    //convert stadium names to team names
    for(int i = 0; i < temp.size(); i++)
    {
        teamNamesVector.push_back(stadiumToTeam(temp[i]));
    }

    for(int i = 0; i < temp.length(); i++)
    {
        QString tempS = QString::number(i + 1) + ". ";
        ui->textBrowser_MiamiMarlins->append(tempS + temp[i] + "(" + teamNamesVector[i] + ")");
    }
    ui->startTripButton_MiamiMarlins->show();
}

void MainWindow::on_startTripButton_MiamiMarlins_clicked()
{
    //TO-DO connect trip planner with souvenir shop
}

QString MainWindow::stadiumToTeam(QString stadiumName)
{
    QString teamName;
    QSqlQuery* query = new QSqlQuery();

    query->prepare("SELECT TEAM_NAME FROM MLB_Information WHERE STADIUM_NAME = :stadiumName");

    //binds values
    query->bindValue(":stadiumName", stadiumName);

    //executes query
    if (query->exec()) {
        qDebug() << "Team Name found";
    } else {
        qDebug() << "Team name NOT found";
    }

    if(query->next())
    {
        teamName = query->value(0).toString();
    }

    return teamName;
}
