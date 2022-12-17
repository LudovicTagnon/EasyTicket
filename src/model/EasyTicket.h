#ifndef EASYTICKET_H
#define EASYTICKET_H

#include <QListWidget>

#include "ticket/TicketManager.h"
#include "db/DBManager.h"
#include "states/StateManager.h"
#include "ticket/Category.h"
#include "ticket/filters/Filters.h"

class User;

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
        std::pair<int, int> connectionDB(const QString username, const QString password);
        bool isOpenDB() const;
        void closeDB();

        User getUserInfo(const int userId);
        void postTicket(const Category category, const QString message, const QString title, const int userId);
        void sendMessage(const Ticket& ticket, const QString& message);
        QString getMessage(const Ticket& ticket);
        void prendreTicket(const User& user, const Ticket& ticket);
        void transfertTicket(const User& user, const Ticket& ticket);
        QStringList getTicketsSummary(const int pageNum, const Filters& filters);
        void changeCategory(const Ticket& ticket, const Category category);
        QStringList getCategories();
        QStringList getEmployees();
        void refreshTickets();

        ~EasyTicket();

    const TicketManager &getTicketManager() const;

};

#endif /*EASYTICKET_H*/
