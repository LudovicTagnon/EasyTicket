#include "EasyTicket.h"

#include "ticket/Ticket.h"
#include "utilisateur/User.h"

#include "../vues/mainwindow.h"

EasyTicket::EasyTicket()
{
    stateManager.push(new MainWindow(*this));
}

void EasyTicket::openDB(const QString username, const QString password)
{
    ticketManager.openDB(username, password);
}

bool EasyTicket::isOpenDB() const
{
    return ticketManager.isOpenDB();
}

void EasyTicket::closeDB()
{
    ticketManager.closeDB();
}

void EasyTicket::postTicket(const Category category, const QString message)
{
    ticketManager.postTicket(category, message);
}

void EasyTicket::takeTicket(const Ticket& ticket)
{
    ticketManager.takeTicket(ticket);
}

void EasyTicket::sendMessage(const Ticket& ticket, const QString& message)
{
    ticketManager.sendMessage(ticket, message);
}

QString EasyTicket::getMessage(const Ticket& ticket)
{
    return ticketManager.getMessage(ticket);
}

void EasyTicket::prendreTicket(const User& user, const Ticket& ticket)
{
    ticketManager.prendreTicket(user, ticket);
}

void EasyTicket::transfertTicket(const User& user, const Ticket& ticket)
{
    ticketManager.transfertTicket(user, ticket);
}

std::vector<QString> EasyTicket::getTicketsSummary(const int pageNum, const QString& filter)
{
    return ticketManager.getTicketsSummary(pageNum, filter);
}

void EasyTicket::changeCategory(const Ticket& ticket, const Category category)
{
    ticketManager.changeCategory(ticket, category);
}

void EasyTicket::start()
{
    stateManager.top()->show();
}

EasyTicket::~EasyTicket()
{

}