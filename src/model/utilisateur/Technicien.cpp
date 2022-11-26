#include "Technicien.h"

Technicien::Technicien(const std::string& userId, const std::string& name, const std::string& surname, const std::string& email, const TicketManager& ticketManager)
: Ingenieur(userId, name, surname, email, ticketManager)
{
    categories.clear();

    //todo: define categories here
}

Technicien::~Technicien()
{
    
}
