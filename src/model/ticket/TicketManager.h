#ifndef TICKETMANAGER_H
#define TICKETMANAGER_H

#include <vector>
#include <memory>
#include <QtCore/QString>

#include "../db/DBManager.h"
#include "Ticket.h"
#include "../Category.h"

class User;

class TicketManager
{
    private:
        DBManager db;
        std::vector<Ticket> tickets;

    public:
        TicketManager();

        void openDB(const QString username, const QString password);
        bool isOpenDB() const;
        void closeDB();

        void postTicket(const Category category, const QString message);
        void takeTicket(const Ticket& ticket);
        QString getMessage(const Ticket& ticket);
        void prendreTicket(const User& user, const Ticket& ticket);
        void transfertTicket(const User& user, const Ticket& ticket);
        //TODO : have reflexions about differences between summary and complete ticket, for the implementation
        std::vector<QString> getTicketsSummary(const int pageNum, const QString& filter);
        void changeCategory(const Ticket& ticket, const Category category);
        void sendMessage(const Ticket& ticket, const QString& message);

        ~TicketManager();
};

#endif /*TICKETMANAGER_H*/