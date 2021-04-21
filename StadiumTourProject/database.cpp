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
