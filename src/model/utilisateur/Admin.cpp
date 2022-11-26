#include "Admin.h"

Admin::Admin(const std::string& userId, const std::string& name, const std::string& surname, const std::string& email, const TicketManager& ticketManager)
: User(userId, name, surname, email, ticketManager)
{

}

/* TODO:
Stat& requestStats()
{

}
*/

Admin::~Admin()
{

}
