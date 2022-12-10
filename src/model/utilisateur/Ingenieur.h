#ifndef INGENIEUR_H
#define INGENIEUR_H

#include <set>

#include "../Category.h"
#include "NonAdmin.h"
#include "../EasyTicket.h"

class Ingenieur : NonAdmin
{
    protected:
        bool isAllCategories;
        std::set<Category> categories;
    public:
        Ingenieur(const QString userId, const QString name, const QString surname, const QString email, EasyTicket& easyTicket);
        Ingenieur(const QString userId, const QString name, const QString surname, const QString email, EasyTicket& easyTicket, bool isAllCategories, std::set<Category> categories);
        void takeTicket(const Ticket& ticket);
        void changeCategory(const Ticket& ticket, const Category category);
        void transferTicket(const User& user, const Ticket& ticket);
        ~Ingenieur();
};

#endif /*INGENIEUR_H*/