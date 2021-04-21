#ifndef DATABASE_H
#define DATABASE_H

#include <QAbstractItemModel>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include "QSqlDatabase"
#include "QSqlQuery"
#include "QDebug"

//ryans path - "C:/Users/ryans/OneDrive/Documents/GitHub/CS1D-Project-2/StadiumTourProject/"
//joeys path - "C:/Source/Qt/CS1D-Project-2/StadiumTourProject/"
//kates path -

//jakes path -

//static const QString PROJECT_PATH = "C:/Source/Qt/CS1D-Project-2/StadiumTourProject/";

static const QString PROJECT_PATH = QDir::currentPath();

class Database
{
public:
    /**
    * @brief explicit default Constructor
    *
    * Constructor adds database
    * sets database path
    * checks if database is open
    *
    * @param &path - for database path
    */
    Database(const QString &path);

    /**
    * @brief Method to check if database is open
    *
    * checks to see if database is open
    */
    bool isOpen() const;

private:
    /**
    * @brief declaree database object
    */
    QSqlDatabase myDB;
};

#endif // DATABASE_H
