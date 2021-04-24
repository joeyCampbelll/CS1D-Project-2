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
