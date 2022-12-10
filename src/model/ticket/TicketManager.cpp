#include "TicketManager.h"

TicketManager::TicketManager()
{

}

void TicketManager::openDB(const QString username, const QString password)
{
    db.open(username, password);
}

bool TicketManager::isOpenDB() const
{
    return db.isOpen();
}

void TicketManager::closeDB()
{
    db.close();
}

void TicketManager::postTicket(const Category category, const QString message)
{
    db.requestPostTicket(category, message);
}

void TicketManager::takeTicket(const Ticket& ticket)
{
    db.requestTakeTicket(ticket);
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

std::vector<QString> TicketManager::getTicketsSummary(const int pageNum, const QString& filter)
{
    return db.requestTicketsSummary(pageNum, filter);
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
