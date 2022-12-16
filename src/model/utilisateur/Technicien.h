#ifndef TECHNICIEN_H
#define TECHNICIEN_H

#include "Ingenieur.h"
#include "User.h"

class EasyTicket;

class Technicien: public Ingenieur
{
    public:
        Technicien(const User user, EasyTicket& easyTicket, const std::set<Category> categories);
        ~Technicien();
};

#endif /*TECHNICIEN_H*/
