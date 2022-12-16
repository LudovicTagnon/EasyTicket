#include "Ticket.h"

Ticket::Ticket(const int ticketId, const QString title, const Category category, const std::time_t dateDebut, const bool isClosed, const std::time_t dateFin)
 : ticketId(ticketId)
 , title(title)
 , category(category)
 , dateDebut(dateDebut)
 , isClosed(isClosed)
 , dateFin(dateFin)
{

}

int getTicketId()
{
  return ticketId;
}

Ticket::~Ticket()
{

}
