#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>

#include "../ticket/Category.h"
#include "../ticket/filters/Filters.h"

class Ticket;
class User;

class DBManager
{
    private:
        QSqlDatabase dbEasyTicket;

    public:
        DBManager();
        QSqlQuery query;

        bool open();
        bool isOpen() const;
        void createIfNotExistsDataBase();
        void connection(const QString username, const QString password);
        void close();

        void requestPostTicket(const Category category, const QString message);
        void requestTakeTicket(const Ticket& ticket);
        QString requestMessage(const Ticket& ticket);
        void requestPrendreTicket(const User& user, const Ticket& ticket);
        void requestTransfertTicket(const User& user, const Ticket& ticket);
        std::vector<QString> requestTicketsSummary(const int pageNum, const Filters& filters);
        void requestChangeCategory(const Ticket& ticket, const Category category);
        void requestSendMessage(const Ticket& ticket, const QString& message);

        ~DBManager();

};

#endif /*DBMANAGER_H*/
