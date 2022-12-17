#ifndef INGENIEUR_H
#define INGENIEUR_H

#include <set>

#include "../ticket/Category.h"
#include "NonAdmin.h"
#include "../EasyTicket.h"

class Ingenieur : public NonAdmin
{
    protected:
        bool isAllCategories;
        std::set<Category> categories;
    public:
        Ingenieur(const User* user, EasyTicket& easyTicket);
        Ingenieur(const User* user, EasyTicket& easyTicket, bool isAllCategories, std::set<Category> categories);
        void changeCategory(const Ticket& ticket, const Category category);
        void transferTicket(const User& user, const Ticket& ticket);
        ~Ingenieur();
};

#endif /*INGENIEUR_H*/
