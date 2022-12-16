#include "NonAdmin.h"

NonAdmin::NonAdmin(const User user, EasyTicket& easyTicket)
: User(user, easyTicket)
{

}

QString& NonAdmin::requestMessage(const Ticket& ticketId)
{
    //easyTicket.resquetMessage();

    //Useless (to avoid warning)
    QString s{ "ERROR" };
    return s;
}

std::vector<QString> NonAdmin::requestTicketsSummary(const int pageNum, const Filters& filers)
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
