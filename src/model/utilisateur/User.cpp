#include "User.h"

User::User(const std::string& userId, const std::string& name, const std::string& surname, const std::string& email, const TicketManager& ticketManager)
            : userId(userId)
            , name(name)
            , surname(surname)
            , email(email)
            , ticketManager(ticketManager)
{
    
}

User::~User()
{

}