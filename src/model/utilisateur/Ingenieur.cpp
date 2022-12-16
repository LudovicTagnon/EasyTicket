#include "Ingenieur.h"

Ingenieur::Ingenieur(const int& userId, const QString& name, const QString& surname, const QString& email, EasyTicket& easyTicket)
: NonAdmin(userId, name, surname, email, easyTicket), isAllCategories(true)
{

}

Ingenieur::Ingenieur(const int& userId, const QString& name, const QString& surname, const QString& email, EasyTicket& easyTicket, bool isAllCategories, std::set<Category> categories)
: NonAdmin(userId, name, surname, email, easyTicket), isAllCategories(isAllCategories), categories(categories)
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
