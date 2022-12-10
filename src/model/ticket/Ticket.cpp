#include "Ticket.h"

Ticket::Ticket(const QString ticketId, const QString title, const std::time_t dateDebut, const bool isClosed, const std::time_t dateFin)
 : ticketId(ticketId)
 , title(title)
 , dateDebut(dateDebut)
 , isClosed(isClosed)
 , dateFin(dateFin)
{

}

Ticket::~Ticket()
{

}
