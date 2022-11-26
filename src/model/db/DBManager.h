#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <string>

#include <QtSql>
#include <QSqlDatabase>

class DBManager
{
    private:

    public:
        DBManager();
        void open(const std::string& user, const std::string& password);

        //TODO: Determine all command type

        void close();
        ~DBManager();

};

#endif /*DBMANAGER_H*/