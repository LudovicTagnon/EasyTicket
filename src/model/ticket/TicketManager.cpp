#include "TicketManager.h"

TicketManager::TicketManager()
{

}

std::string_view& TicketManager::requestMessage(const Ticket& ticketId)
{

}

void TicketManager::prendreTicket(const User& user, const Ticket& ticket)
{

}

void TicketManager::transfertTicket(const User& user, const Ticket& ticket)
{

}

//TODO : have reflexions about differences between summary and complete ticket, for the implementation
std::string_view TicketManager::requestTicketsSummary(const int pageNum, const std::string_view& filter)
{

}

void TicketManager::changeCategory(const Ticket& ticket, const Category category)
{

}

void TicketManager::sendMessage(const Ticket& ticket, const std::string_view& message)
{

}

TicketManager::~TicketManager()
{
    
}
