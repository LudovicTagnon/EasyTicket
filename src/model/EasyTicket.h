#ifndef EASYTICKET_H
#define EASYTICKET_H

#include "ticket/TicketManager.h"
#include "states/StateManager.h"
#include "Category.h"

class EasyTicket
{
    private:
        TicketManager ticketManager;
        StateManager stateManager;
    public:
        EasyTicket();

        void openDB(const QString username, const QString password);
        bool isOpenDB() const;
        void closeDB();

        void postTicket(const Category category, const QString message);
        void takeTicket(const Ticket& ticket);
        void sendMessage(const Ticket& ticket, const QString& message);
        QString getMessage(const Ticket& ticket);
        void prendreTicket(const User& user, const Ticket& ticket);
        void transfertTicket(const User& user, const Ticket& ticket);
        std::vector<QString> getTicketsSummary(const int pageNum, const QString& filter);
        void changeCategory(const Ticket& ticket, const Category category);

        void start();

        ~EasyTicket();
};

#endif /*EASYTICKET_H*/