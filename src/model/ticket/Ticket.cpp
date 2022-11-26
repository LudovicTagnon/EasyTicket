#include "Ticket.h"

Ticket::Ticket(const std::string& ticketId, const std::string& title, const Date& dateDebut)
 : ticketId(ticketId)
 , title(title)
 , dateDebut(Date())
 , isClosed(false)
{

}

Ticket::~Ticket()
{

}
