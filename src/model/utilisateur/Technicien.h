#ifndef TECHNICIEN_H
#define TECHNICIEN_H

#include "Ingenieur.h"

class EasyTicket;

class Technicien: public Ingenieur
{
    public:
        Technicien(const int& userId, const QString& name, const QString& surname, const QString& email, EasyTicket& easyTicket, const std::set<Category> categories);
        ~Technicien();
};

#endif /*TECHNICIEN_H*/
