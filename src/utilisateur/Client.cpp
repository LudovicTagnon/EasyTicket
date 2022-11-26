#include "Client.h"

Client::Client(const std::string& userId, const std::string& name, const std::string& surname, const std::string& email, const TicketManager& ticketManager)
: NonAdmin(userId, name, surname, email, ticketManager)
{

}

void Client::postTicket(const Category category, const std::string& message)
{

}

Client::~Client()
{

}
