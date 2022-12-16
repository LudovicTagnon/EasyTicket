#include "TicketManager.h"

TicketManager::TicketManager(DBManager& db) : db(db)
{

}

void TicketManager::openDB(const QString username, const QString password)
{
    db.open();
}

bool TicketManager::isOpenDB() const
{
    return db.isOpen();
}

void TicketManager::connectionBD(const QString username, const QString password)
{
    db.connection(username, password);
}

void TicketManager::closeDB()
{
    db.close();
}

void TicketManager::postTicket(const Category category, const QString message, const QString title)
{
    int ticketNum = db.requestPostTicket(category, message, title);
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
