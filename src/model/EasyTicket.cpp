#include "EasyTicket.h"

#include <iostream>

#include "ticket/Ticket.h"
#include "utilisateur/User.h"

#include "../vues/mainwindow.h"

EasyTicket::EasyTicket()
 : db(DBManager(*this))
 , ticketManager(TicketManager(db))
{
    stateManager.push(new MainWindow(*this));
}

TicketManager &EasyTicket::getTicketManager() {
    return ticketManager;
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

std::pair<int, int> EasyTicket::connectionDB(const QString username, const QString password)
{
    return db.connection(username, password);
}

bool EasyTicket::isOpenDB() const
{
    return db.isOpen();
}

void EasyTicket::closeDB()
{
    db.close();
}

std::unique_ptr<User> EasyTicket::getUserInfo(const int userId)
{
    return db.getUserInfo(userId);
}

void EasyTicket::postTicket(const Category category, const QString message, const QString title, const int userId)
{
    ticketManager.postTicket(category, message, title, userId);
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

QStringList EasyTicket::getCategories()
{
    return db.getCategories();
}

QStringList EasyTicket::getEmployees()
{
    return db.getEmployees();
}

bool EasyTicket::setEmployeeOntIt(Ticket& ticket, NonAdmin& nonAdmin)
{
    bool ret = db.setEmployeeOntIt(ticket, nonAdmin);
    if(ret) ticket.setEmployeeOnIt(&nonAdmin);

    return ret;
}

EasyTicket::~EasyTicket()
{

}

void EasyTicket::refreshTickets() {
    ticketManager.refreshTickets();
}
