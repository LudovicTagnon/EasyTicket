#include "Client.h"

Client::Client(const User user, EasyTicket& easyTicket)
: NonAdmin(user, easyTicket)
{

}

void Client::postTicket(const Category category, const QString message)
{
    easyTicket.postTicket(category, message);
}

Client::~Client()
{

}
