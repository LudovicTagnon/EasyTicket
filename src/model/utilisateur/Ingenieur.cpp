#include "Ingenieur.h"

Ingenieur::Ingenieur(const std::string& userId, const std::string& name, const std::string& surname, const std::string& email, const TicketManager& ticketManager)
: NonAdmin(userId, name, surname, email, ticketManager)
{

}

void Ingenieur::takeTicket(const Ticket& ticket)
{

}

void Ingenieur::changeCategory(const Category category, const Ticket& ticket)
{

}

void Ingenieur::transferTicket(const User& user, const Ticket& ticket)
{

}

Ingenieur::~Ingenieur()
{

}
