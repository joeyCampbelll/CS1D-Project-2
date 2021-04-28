#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    ui->comboBox_endingTeam->setModel(model);

    if(SSRstartClicked == true)
    {
        inputValues.clear();
        ui->textBrowser_SSR->clear();
        SSRstartClicked = false;
    }
}

//Start Single Stadium Route(SSR) trip
void MainWindow::on_pushButton_SSRstart_clicked()
{
    SSRstartClicked = true;
    inputValues.push_back(ui->comboBox_startingTeam->currentText());
    inputValues.push_back(ui->comboBox_endingTeam->currentText());

    for(int i = 0; i < inputValues.size(); i++)
    {
        ui->textBrowser_SSR->append(inputValues.at(i));
    }

    ui->label_tripRouteSSR->show();
    ui->textBrowser_SSR->show();
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
        teamNamesVector.push_back(startTeamName);

        while(query->next())
        {
            if(startTeamName != query->value(0).toString())
            {
                QCheckBox* checkBox = new QCheckBox(query->value(0).toString());
                QString collegeName = (query->value(0).toString());
                checkBox->setCheckState(Qt::CheckState::Unchecked);
                checkBoxVector.push_back(checkBox);
                tempTeamNamesVector.push_back(collegeName);
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
