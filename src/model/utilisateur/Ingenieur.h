#ifndef INGENIEUR_H
#define INGENIEUR_H

#include "../Category.h"
#include "NonAdmin.h"

class User;
class Ticket;

class Ingenieur : NonAdmin
{
    protected:
        std::vector<Category> categories;
    public:
        Ingenieur(const std::string& userId, const std::string& name, const std::string& surname, const std::string& email, const TicketManager& ticketManager);
        void takeTicket(const Ticket& ticket);
        void changeCategory(const Category category, const Ticket& ticket);
        void transferTicket(const User& user, const Ticket& ticket);
        ~Ingenieur();
};

#endif /*INGENIEUR_H*/