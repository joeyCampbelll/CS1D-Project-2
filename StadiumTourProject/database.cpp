#include "database.h"

Database::Database(const QString &path)
{
    myDB = QSqlDatabase::addDatabase("QSQLITE");

    myDB.setDatabaseName(path);

    if(!myDB.open())
    {
        qDebug() << path << Qt::endl;
        qDebug() << "Error: can't connect to database!" << Qt::endl;
    }
    else
    {
        qDebug() << "Database: Connected" << Qt::endl;
    }

    QSqlQuery query;
    query.prepare("PRAGMA foreign_keys = ON");

    if(query.exec())
    {
        qDebug() << "Query Ready";
    }
    else
    {
        qDebug() << "Query Failed";
    }
}

bool Database::isOpen() const
{
    return myDB.isOpen();
}

void Database::deleteSouvenir(const QString &souvenirName, const QString &teamName)
{
    QSqlQuery *query = new QSqlQuery(myDB);

    if(souvenirExists(souvenirName, teamName))
    {
        if(myDB.open())
        {
            query->prepare("DELETE FROM Souvenirs WHERE (SOUVENIR_NAME, TEAM_NAME) = (:souvenirname, :teamname)");
            query->bindValue(":souvenirname", souvenirName);
            query->bindValue(":teamname", teamName);

            if(query->exec())
                qDebug() << "souvenir delete success!";
            else
                qDebug() << "souvenir delete failed!";
        }
    }

}

void Database::addSouvenir(const QString &souvenirName, const QString &teamName, const QString &price)
{
    QSqlQuery *query = new QSqlQuery(myDB);

    if(!souvenirExists(souvenirName, teamName))
    {
        if(myDB.open())
        {
            query->prepare("INSERT INTO Souvenirs(TEAM_NAME, SOUVENIR_NAME, SOUVENIR_PRICE) VALUES(:teamname, :souvenirname, :price)");
            query->bindValue(":teamname", teamName);
            query->bindValue(":souvenirname", souvenirName);
            query->bindValue(":price", "$ " + price);

            if(query->exec())
                qDebug() << "souvenir add success!";
            else
                qDebug() << "souvenir add failed!";
        }
    }
    else
    {
        qDebug() << "name exists!";
    }
}

void Database::editSouvenir(const QString &souvenirName, const QString &teamName, const QString &price, const QString &newSouvenirName) {
    QSqlQuery *query = new QSqlQuery(myDB);


    if(myDB.open())
    {
        query->prepare("UPDATE SOUVENIRS SET (SOUVENIR_NAME, SOUVENIR_PRICE) = (:newsouvenirname, :price) "
                       "WHERE (TEAM_NAME, SOUVENIR_NAME) = (:teamname, :souvenirname)");
        query->bindValue(":newsouvenirname", newSouvenirName);
        query->bindValue(":teamname", teamName);
        query->bindValue(":souvenirname", souvenirName);
        query->bindValue(":price", "$ " +  price);

        if(query->exec())
        {
            qDebug() << "UPDATE WORKED" << Qt::endl;
        }
        else
        {
            qDebug() << "UPDATE failed: " << query->lastError() << Qt::endl;
        }
    }
}

QStringList Database::parseFile(QString &string) {
    enum State {Normal, Quote} state = Normal;
    QStringList fields;
    QString value;

    for (int i = 0; i < string.size(); i++)
    {
        QChar current = string.at(i);

        // Normal state
        if (state == Normal)
        {
            // Comma
            if (current == ',')
            {
                // Save field
                fields.append(value);
                value.clear();
            }

            // Double-quote
            else if (current == '"')
                state = Quote;

            // Other character
            else
                value += current;
        }

        // In-quote state
        else if (state == Quote)
        {
            // Another double-quote
            if (current == '"')
            {
                if (i+1 < string.size())
                {
                    QChar next = string.at(i+1);

                    // A double double-quote?
                    if (next == '"')
                    {
                        value += '"';
                        i++;
                    }
                    else
                        state = Normal;
                }
            }

            // Other character
            else
                value += current;
        }
    }
    if (!value.isEmpty())
        fields.append(value);

    return fields;
}

void Database::addNewStadium(QStringList list) {
    QSqlQuery* query = new QSqlQuery(myDB);

    //adds stadium to MLB_Information Table
    query->prepare("INSERT INTO MLB_Information (TEAM_NAME, STADIUM_NAME, SEATING_CAPACITY, LOCATION,"
                   "PLAYING_SURFACE, LEAGUE, DATE_OPENED, DISTANCE_TO_CENTER_FIELD, BALLPARK_TYPOLOGY, ROOF_TYPE)"
                   " VALUES (:TeamName, :StadiumName, :SeatingCapacity, :Location, :PlayingSurface, :League,"
                   ":DateOpened, :DistanceToCenterField, :BallParkTypology, :RoofType)");

    //binds values
    query->bindValue(":TeamName", list.at(0));
    query->bindValue(":StadiumName", list.at(1));
    query->bindValue(":SeatingCapacity", list.at(2));
    query->bindValue(":Location", list.at(3));
    query->bindValue(":PlayingSurface", list.at(4));
    query->bindValue(":League", list.at(5));
    query->bindValue(":DateOpened", list.at(6));
    query->bindValue(":DistanceToCenterField", list.at(7));
    query->bindValue(":BallParkTypology", list.at(8));
    query->bindValue(":RoofType", list.at(9).trimmed());

    query->exec();
}

void Database::addNewDistance(QStringList list) {
    QSqlQuery* query = new QSqlQuery(myDB);

    //adds stadium to Distances Table
    query->prepare("INSERT INTO Distances (ORIGINATED_STADIUM, DESTINATION_STADIUM, DISTANCE)"
                   " VALUES (:StartStadium, :EndStadium, :Distance)");

    //binds values
    query->bindValue(":StartStadium", list.at(0));
    query->bindValue(":EndStadium", list.at(1));
    query->bindValue(":Distance", list.at(2));

    //executes query
    query->exec();
}

void Database::removeTeam(const QString &stadiumName, const QString &teamName)
{
    QSqlQuery *query = new QSqlQuery(myDB);

    if(myDB.open())
    {
        query->prepare("DELETE FROM MLB_Information WHERE (STADIUM_NAME) = (:stadiumName)");
        query->bindValue(":stadiumName", stadiumName);

        if(query->exec())
           qDebug() << "team1 delete success!";
        else
           qDebug() << "team1 delete failed!";

        query->prepare("DELETE FROM Distances WHERE (ORIGINATED_STADIUM) = (:stadiumName) OR (DESTINATION_STADIUM) = (:stadiumName)");
        query->bindValue(":stadiumName", stadiumName);

        if(query->exec())
           qDebug() << "team2 delete success!";
        else
           qDebug() << "team2 delete failed!";

//        query->prepare("DELETE FROM Souvenirs WHERE (TEAM_NAME) = (:teamName)");
//        query->bindValue(":teamName", teamName);

//        if(query->exec())
//           qDebug() << "team3 delete success!";
//        else
//           qDebug() << "team3 delete failed!";
    }
}

void Database::updateStadiumInfo(const QString &teamName, const QString &stadiumName,
                                 const QString &location, const QString &league,
                                 const int &capacity, const int &date, const QString &surface,
                                 const QString &roof, const QString &distanceCenter, const QString &typology)
{
    QSqlQuery *query = new QSqlQuery(myDB);


    if(myDB.open())
    {
        query->prepare("UPDATE MLB_Information "
                       "SET STADIUM_NAME = :stadium, LOCATION = :location, LEAGUE = :league, "
                       "SEATING_CAPACITY = :capacity, DATE_OPENED = :date, PLAYING_SURFACE = :surface, "
                       "ROOF_TYPE = :roof, DISTANCE_TO_CENTER_FIELD = :distance, BALLPARK_TYPOLOGY = :typology "
                       "WHERE TEAM_NAME = :teamName");
        query->bindValue(":teamName", teamName);
        query->bindValue(":stadium", stadiumName);
        query->bindValue(":location", location);
        query->bindValue(":league", league);
        query->bindValue(":capacity", capacity);
        query->bindValue(":date", date);
        query->bindValue(":surface", surface);
        query->bindValue(":roof", roof);
        query->bindValue(":distance", distanceCenter);
        query->bindValue(":typology", typology);

        if(query->exec())
        {
            qDebug() << "UPDATE WORKED" << Qt::endl;
        }
        else
        {
            qDebug() << "UPDATE failed: " << query->lastError() << Qt::endl;
        }
    }
}


bool Database::souvenirExists(const QString &souvenirName, const QString &teamName)
{
    bool exists = false;

    QSqlQuery *checkQuery = new QSqlQuery(myDB);

    checkQuery->prepare("SELECT SOUVENIR_NAME FROM SOUVENIRS WHERE (TEAM_NAME, SOUVENIR_NAME) = (:teamname, :souvenirname)");
    checkQuery->bindValue(":teamname", teamName);
    checkQuery->bindValue(":souvenirname", souvenirName);


    if(checkQuery->exec())
    {
        if(checkQuery->next())
        {
            exists = true;
            QString souvenir = checkQuery->value("teamname").toString();
            QString team = checkQuery->value("souvenirname").toString();
            qDebug() << souvenir << " " << team;
        }
    }
    else
    {
        qDebug() << "souvenir exists failed: " << checkQuery->lastError();
    }

    return exists;
}

void Database::clearMLBInfo()
{
    QSqlQuery *query = new QSqlQuery(myDB);

    query->prepare("DELETE FROM MLB_Information");

    if(query->exec())
    {
        qDebug() << "MLB info Cleared" << Qt::endl;
    }
    else
    {
        qDebug() << "ERROR - MLB info NOT Cleared" << Qt::endl;
    }

    query->prepare("DELETE FROM Distances");

    if(query->exec())
    {
        qDebug() << "Distances Cleared" << Qt::endl;
    }
    else
    {
        qDebug() << "ERROR - Distances NOT Cleared" << Qt::endl;
    }

//    query->prepare("DELETE FROM Souvenirs");

//    if(query->exec())
//    {
//        qDebug() << "Souvenirs Cleared" << Qt::endl;
//    }
//    else
//    {
//        qDebug() << "ERROR - Souvenirs NOT Cleared" << Qt::endl;
//    }
}
