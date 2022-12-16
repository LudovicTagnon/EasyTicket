#include "Ingenieur.h"

Ingenieur::Ingenieur(const User user, EasyTicket& easyTicket)
: NonAdmin(user, easyTicket), isAllCategories(true)
{

}

Ingenieur::Ingenieur(const User user, EasyTicket& easyTicket, bool isAllCategories, std::set<Category> categories)
: NonAdmin(user, easyTicket), isAllCategories(isAllCategories), categories(categories)
{

}

void Ingenieur::changeCategory(const Ticket& ticket, const Category category)
{
    easyTicket.changeCategory(ticket, category);
}

void Ingenieur::transferTicket(const User& user, const Ticket& ticket)
{
    easyTicket.transfertTicket(user, ticket);
}

Ingenieur::~Ingenieur()
{

}
