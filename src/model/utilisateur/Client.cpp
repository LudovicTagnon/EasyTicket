#include "Client.h"

Client::Client(const QString userId, const QString name, const QString surname, const QString email, EasyTicket& easyTicket)
: NonAdmin(userId, name, surname, email, easyTicket)
{

}

void Client::postTicket(const Category category, const QString message)
{
    easyTicket.postTicket(category, message);
}

Client::~Client()
{

}
