#ifndef CLIENT_H
#define CLIENT_H

#include "NonAdmin.h"
#include "../ticket/Category.h"
#include "../EasyTicket.h"

class Client : NonAdmin
{
    public:
        Client(const int& userId, const QString& name, const QString& surname, const QString& email, EasyTicket& easyTicket);
        void postTicket(const Category category, const QString message, const QString title);
        ~Client();
};

#endif /*CLIENT_H*/
