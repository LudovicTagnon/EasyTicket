#ifndef USER_H
#define USER_H

#include <string>

class TicketManager;

class User
{
    protected:
        const std::string userId;
        const std::string name;
        const std::string surname;
        const std::string email;

        const TicketManager& ticketManager;
    
    public:
        User(const std::string& userId,
             const std::string& name,
             const std::string& surname,
             const std::string& email,
             const TicketManager& ticketManager);
        ~User();
};

#endif /*USER_H*/