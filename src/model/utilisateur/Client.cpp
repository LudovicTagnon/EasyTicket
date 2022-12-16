#include "Client.h"

Client::Client(const User user, EasyTicket& easyTicket)
: NonAdmin(user, easyTicket)
{

}

void Client::postTicket(const Category category, const QString message, const QString title)
{
    easyTicket.postTicket(category, message, title);
}

Client::~Client()
{

}
