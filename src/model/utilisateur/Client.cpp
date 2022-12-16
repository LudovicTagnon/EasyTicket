#include "Client.h"

Client::Client(const int& userId, const QString& name, const QString& surname, const QString& email, EasyTicket& easyTicket)
: NonAdmin(userId, name, surname, email, easyTicket)
{

}

void Client::postTicket(const Category category, const QString message, const QString title)
{
    easyTicket.postTicket(category, message, title);
}

Client::~Client()
{

}
