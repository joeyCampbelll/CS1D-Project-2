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
    query->bindValue(":RoofType", list.at(9));

    //executes query
    if (query->exec()) {
        qDebug() << "Query was executed";
    } else {
        qDebug() << "Query was not executed";
    }
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
    if (query->exec()) {
        qDebug() << "Query was executed";
    } else {
        qDebug() << "Query was not executed";
    }
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

        query->prepare("DELETE FROM Souvenirs WHERE (TEAM_NAME) = (:teamName)");
        query->bindValue(":teamName", teamName);

        if(query->exec())
           qDebug() << "team3 delete success!";
        else
           qDebug() << "team3 delete failed!";
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
