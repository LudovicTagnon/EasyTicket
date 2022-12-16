#include "EasyTicket.h"

#include "ticket/Ticket.h"
#include "utilisateur/User.h"

#include "../vues/mainwindow.h"

EasyTicket::EasyTicket()
 : db(DBManager())
 , ticketManager(TicketManager(db))
{
    stateManager.push(new MainWindow(*this));
}

void EasyTicket::pushWindow(QWidget* state){
    stateManager.push(state);
}

void EasyTicket::popWindow()
{
    stateManager.pop();
}

bool EasyTicket::openDB()
{
    return db.open();
}

void EasyTicket::connectionDB(const QString username, const QString password)
{
    db.connection(username, password);
}

bool EasyTicket::isOpenDB() const
{
    return db.isOpen();
}

void EasyTicket::closeDB()
{
    db.close();
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

QStringList EasyTicket::getTicketsSummary(const int pageNum, const Filters& filters)
{
    return ticketManager.getTicketsSummary(pageNum, filters);
}

void EasyTicket::changeCategory(const Ticket& ticket, const Category category)
{
    ticketManager.changeCategory(ticket, category);
}

EasyTicket::~EasyTicket()
{

}
