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
     * @brief Method to check if souvenir exists
     * @param souvenirName
     * @param teamName
     * @return true if exists, false if not
     */
    bool souvenirExists(const QString &souvenirName, const QString &teamName);

    void editSouvenir(const QString &souvenirName, const QString &teamName, const QString &price, const QString &newSouvenirName);
    void deleteSouvenir(const QString &souvenirName, const QString &teamName);
    void addSouvenir(const QString &souvenirName, const QString &teamName, const QString &price);

private:
    /**
    * @brief declaree database object
    */
    QSqlDatabase myDB;
};

#endif // DATABASE_H
