#ifndef TICKETMANAGER_H
#define TICKETMANAGER_H

#include <vector>
#include <memory>
#include <QtCore/QString>
#include <QListWidget>

#include "Ticket.h"
#include "Category.h"

class User;
class DBManager;
class Filters;

class TicketManager
{
    private:
        DBManager& db;
        std::vector<Ticket> tickets;

    public:
        TicketManager(DBManager& db);

        void postTicket(const Category category, const QString message, const QString title, const int userId);
        QString getMessage(const Ticket& ticket);
        void prendreTicket(const User& user, const Ticket& ticket);
        void transfertTicket(const User& user, const Ticket& ticket);
        //TODO : have reflexions about differences between summary and complete ticket, for the implementation
        QStringList getTicketsSummary(const int pageNum, const Filters& filters);
        void changeCategory(const Ticket& ticket, const Category category);
        void sendMessage(const Ticket& ticket, const QString& message);
        void refreshTickets();

        ~TicketManager();

    const std::vector<Ticket> &getTickets() const;
};

#endif /*TICKETMANAGER_H*/
