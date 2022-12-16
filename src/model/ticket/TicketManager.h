#ifndef TICKETMANAGER_H
#define TICKETMANAGER_H

#include <vector>
#include <memory>
#include <QtCore/QString>
#include <QListWidget>

#include "../db/DBManager.h"
#include "Ticket.h"
#include "Category.h"
#include "filters/Filters.h"

class User;

class TicketManager
{
    private:
        DBManager& db;
        std::vector<Ticket> tickets;

    public:
        TicketManager(DBManager& db);

        void openDB(const QString username, const QString password);
        void connectionBD(const QString username, const QString password);
        bool isOpenDB() const;
        void closeDB();

        void postTicket(const Category category, const QString message);
        void takeTicket(const Ticket& ticket);
        QString getMessage(const Ticket& ticket);
        void prendreTicket(const User& user, const Ticket& ticket);
        void transfertTicket(const User& user, const Ticket& ticket);
        //TODO : have reflexions about differences between summary and complete ticket, for the implementation
        QStringList getTicketsSummary(const int pageNum, const Filters& filters);
        void changeCategory(const Ticket& ticket, const Category category);
        void sendMessage(const Ticket& ticket, const QString& message);

        ~TicketManager();
};

#endif /*TICKETMANAGER_H*/