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

const QString &Ticket::getTitle() const {
    return title;
}

const Category Ticket::getCategory() const {
    return category;
}

const bool Ticket::getIsClosed() const {
    return isClosed;
}

int Ticket::getTicketId() const
{
  return ticketId;
}

Ticket::~Ticket()
{

}
