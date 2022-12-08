#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql>
#include <QSqlDatabase>

class DBManager
{
    private:
        QSqlDatabase dbEasyTicket;

    public:
        DBManager();

        void open(const QString& user, const QString& password);
        bool isOpen() const;
        void close();

        ~DBManager();

};

#endif /*DBMANAGER_H*/
