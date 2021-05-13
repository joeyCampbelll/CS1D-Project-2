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

    /**
     * @brief Method to edit souvenir
     * @param souvenirName
     * @param teamName
     * @param price
     * @param newSouvenirName
     */
    void editSouvenir(const QString &souvenirName, const QString &teamName, const QString &price, const QString &newSouvenirName);

    /**
     * @brief Method to delete souvenir
     * @param souvenirName
     * @param teamName
     */
    void deleteSouvenir(const QString &souvenirName, const QString &teamName);

    /**
     * @brief Method to add souvenir
     * @param souvenirName
     * @param teamName
     * @param price
     */
    void addSouvenir(const QString &souvenirName, const QString &teamName, const QString &price);

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

    /**
    * @brief Method to edit a team's info
    *
    * edits team's info from database
    *
    * @param teamName - name of team to be edited
    * @param stadiumName - name of stadium to be edited
    */
    void updateStadiumInfo(const QString &teamName, const QString &stadiumName,
                           const QString &location, const QString &league,
                           const int &capacity, const int &date, const QString &surface,
                           const QString &roof, const QString &distanceCenter, const QString &typology);

    /**
    * @brief Method to clear team database info
    *
    * clears team database info
    *
    */
    void clearMLBInfo();

private:
    /**
    * @brief declare database object
    */
    QSqlDatabase myDB;
};

#endif // DATABASE_H
