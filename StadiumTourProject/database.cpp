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

//void Database::removeSouvenir(const QString &souvenirName, const QString &college)
//{
//    QSqlQuery *query = new QSqlQuery(myDB);

//    if(souvenirExists(souvenirName, college))
//    {
//        if(myDB.open())
//        {
//            query->prepare("DELETE FROM souvenirs WHERE (souvenirs) = (:souvenirs)");
//            query->bindValue(":souvenirs", souvenirName);

//            if(query->exec())
//                qDebug() << "souvenir delete success!";
//            else
//                qDebug() << "souvenir delete failed!";
//        }
//    }

//}

//void Database::addSouvenir(const QString &teamName, const QString &souvenirName, const QString &price)
//{
//    QSqlQuery *query = new QSqlQuery(myDB);

//    if(!souvenirExists(souvenirName, teamName))
//    {
//        if(myDB.open())
//        {
//            query->prepare("INSERT INTO souvenirs(TEAM_NAME, SOUVENIR_NAME, PRICE) VALUES(:college, :souvenirs, :cost)");
//            query->bindValue(":teamname", teamName);
//            query->bindValue(":souvenirname", souvenirName);
//            query->bindValue(":price", price);

//            if(query->exec())
//                qDebug() << "souvenir add success!";
//            else
//                qDebug() << "souvenir add failed!";
//        }
//    }
//    else
//    {
//        qDebug() << "name exists!";
//    }
//}

//void Database::updateSouvenir(const QString &souvenirName, const QString &teamName, const QString &price, const QString &newsouvenir)
//{
//    QSqlQuery *query = new QSqlQuery(myDB);


//    if(myDB.open())
//    {
//        query->prepare("UPDATE souvenirs SET (souvenirs, cost) = (:newsouvenirName, :cost) "
//                       "WHERE (college, souvenirs) = (:college, :souvenirs)");
//        query->bindValue(":newsouvenirName", newsouvenir);
//        query->bindValue(":college", college);
//        query->bindValue(":souvenirs", souvenirName);
//        query->bindValue(":cost", spin);

//        if(query->exec())
//        {
//            qDebug() << "UPDATE WORKED" << Qt::endl;
//        }
//        else
//        {
//            qDebug() << "UPDATE failed: " << query->lastError() << Qt::endl;
//        }
//    }
//}


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
