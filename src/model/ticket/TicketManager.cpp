#include "TicketManager.h"

#include "../db/DBManager.h"

TicketManager::TicketManager(DBManager& db) : db(db)
{
    refreshTickets();
}

void TicketManager::refreshTickets() {
    if (db.isOpen()){
        tickets = db.getTickets();
    }
}

const std::vector<Ticket> &TicketManager::getTickets() const {
    return tickets;
}

void TicketManager::postTicket(const Category category, const QString message, const QString title, const int userId)
{
    int ticketNum = db.requestPostTicket(category, message, title, userId);
    tickets.push_back(Ticket(ticketNum, title, category));
}

QString TicketManager::getMessage(const Ticket& ticket)
{
    return db.requestMessage(ticket);
}

void TicketManager::prendreTicket(const User& user, const Ticket& ticket)
{
    db.requestPrendreTicket(user, ticket);
}

void TicketManager::transfertTicket(const User& user, const Ticket& ticket)
{
    db.requestTransfertTicket(user, ticket);
}

QStringList TicketManager::getTicketsSummary(const int pageNum, const Filters& filters)
{
    return db.requestTicketsSummary(pageNum, filters);
}

void TicketManager::changeCategory(const Ticket& ticket, const Category category)
{
    db.requestChangeCategory(ticket, category);
}

void TicketManager::sendMessage(const Ticket& ticket, const QString& message)
{
    db.requestSendMessage(ticket, message);
}

TicketManager::~TicketManager()
{

}
