#ifndef CLIENT_H
#define CLIENT_H

#include "NonAdmin.h"
#include "../Category.h"

class TicketManager;

class Client : NonAdmin
{
    public:
        Client(const std::string& userId, const std::string& name, const std::string& surname, const std::string& email, const TicketManager& ticketManager);
        void postTicket(const Category category, const std::string& message);
        ~Client();
};

#endif /*CLIENT_H*/