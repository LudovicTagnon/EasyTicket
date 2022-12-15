#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql>
#include <QSqlDatabase>

#include "../ticket/Category.h"

class Ticket;
class User;

class DBManager
{
    private:
        QSqlDatabase dbEasyTicket;

    public:
        DBManager();

        void open(const QString& user, const QString& password);
        bool isOpen() const;
        void close();

        void requestPostTicket(const Category category, const QString message);
        void requestTakeTicket(const Ticket& ticket);
        QString requestMessage(const Ticket& ticket);
        void requestPrendreTicket(const User& user, const Ticket& ticket);
        void requestTransfertTicket(const User& user, const Ticket& ticket);
        std::vector<QString> requestTicketsSummary(const int pageNum, const QString& filter);
        void requestChangeCategory(const Ticket& ticket, const Category category);
        void requestSendMessage(const Ticket& ticket, const QString& message);

        ~DBManager();

};

#endif /*DBMANAGER_H*/
