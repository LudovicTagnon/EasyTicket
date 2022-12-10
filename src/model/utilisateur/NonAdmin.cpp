#include "NonAdmin.h"

NonAdmin::NonAdmin(const QString userId, const QString name, const QString surname, const QString email, EasyTicket& easyTicket)
: User(userId, name, surname, email, easyTicket)
{

}

QString& NonAdmin::requestMessage(const Ticket& ticketId)
{
    //easyTicket.resquetMessage();

    //Useless (to avoid warning)
    QString s{ "ERROR" };
    return s;
}

std::vector<QString> NonAdmin::requestTicketsSummary(const int pageNum, const QString& filter)
{
    return {};
}

void NonAdmin::sendMessage(const Ticket& ticket, const QString& message)
{
    easyTicket.sendMessage(ticket, message);
}

NonAdmin::~NonAdmin()
{

}
