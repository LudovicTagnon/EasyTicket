#ifndef EASYTICKET_H
#define EASYTICKET_H

#include <QStringList>

#include "ticket/TicketManager.h"
#include "states/StateManager.h"
#include "ticket/Category.h"
#include "ticket/filters/Filters.h"

class EasyTicket
{
    private:
        DBManager db;
        TicketManager ticketManager;
        StateManager stateManager;
    public:
        EasyTicket();
        void pushWindow(QWidget* state);
        void popWindow();
        bool openDB();
        void connectionDB(const QString username, const QString password);
        bool isOpenDB() const;
        void closeDB();

        void postTicket(const Category category, const QString message);
        void takeTicket(const Ticket& ticket);
        void sendMessage(const Ticket& ticket, const QString& message);
        QString getMessage(const Ticket& ticket);
        void prendreTicket(const User& user, const Ticket& ticket);
        void transfertTicket(const User& user, const Ticket& ticket);
        QStringList getTicketsSummary(const int pageNum, const Filters& filters);
        void changeCategory(const Ticket& ticket, const Category category);

        ~EasyTicket();

};

#endif /*EASYTICKET_H*/