#ifndef TECHNICIEN_H
#define TECHNICIEN_H

#include "Ingenieur.h"

class Technicien: public Ingenieur
{
    public:
        Technicien::Technicien(const std::string& userId, const std::string& name, const std::string& surname, const std::string& email, const TicketManager& ticketManager);
        ~Technicien();
};

#endif /*TECHNICIEN_H*/