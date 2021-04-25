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

//static const QString PROJECT_PATH = "C:/Users/ryans/OneDrive/Documents/1D-Project-2/StadiumTourProject/";

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

    /**
    * @brief Method to parse a CSV file
    *
    * parses a CSV file and extracts information
    *
    * @param &string - string to parse
    */
    QStringList parseFile(QString &string);

    /**
    * @brief Method to add new stadium
    *
    * adds new stadium to database
    *
    * @param list - list of stadiums to add
    */
    void addNewStadium(QStringList list);

    /**
    * @brief Method to add new distance
    *
    * adds new distance to database
    *
    * @param list - list of distances to add
    */
    void addNewDistance(QStringList list);

    /**
    * @brief Method to remove a team
    *
    * removes team from database
    *
    * @param teamName - name of team to be deleted
    * @param stadiumName - name of stadium to be deleted
    */
    void removeTeam(const QString &stadiumName, const QString &teamName);

private:
    /**
    * @brief declaree database object
    */
    QSqlDatabase myDB;
};

#endif // DATABASE_H
