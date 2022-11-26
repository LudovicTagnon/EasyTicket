#include "NonAdmin.h"

NonAdmin::NonAdmin(const std::string& userId, const std::string& name, const std::string& surname, const std::string& email, const TicketManager& ticketManager)
: User(userId, name, surname, email, ticketManager)
{

}

/*TODO:
std::string_view& NonAdmin::requestMessage(const Ticket& ticketId)
{
    //ticketManager.resquetMessage();
}

std::vector<std::string_view&> NonAdmin::requestTicketsSummary(const int pageNum, const std::string_view& filter)
{

}
*/

void NonAdmin::sendMessage(const Ticket& ticketId, const std::string_view& message)
{

}

/*
void NonAdmin::prendreTicket(const std::string_view& employeeId, const Ticket& ticketId)
{

}

void NonAdmin::transfererTicket(const std::string_view& employeeId, const Ticket& ticketId)
{

}
*/

void NonAdmin::changeCategory(const Ticket& ticketId, const Category category)
{

}

NonAdmin::~NonAdmin()
{

}
