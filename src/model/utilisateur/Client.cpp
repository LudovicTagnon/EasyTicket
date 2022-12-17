#include "Client.h"

Client::Client(const User user, EasyTicket& easyTicket)
: NonAdmin(user, easyTicket)
{

}

void Client::postTicket(const Category category, const QString message, const QString title, const int userId)
{
    easyTicket.postTicket(category, message, title, userId);
}

Client::~Client()
{

}
