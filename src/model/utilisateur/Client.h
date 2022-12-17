#ifndef CLIENT_H
#define CLIENT_H

#include "NonAdmin.h"
#include "../ticket/Category.h"
#include "../EasyTicket.h"

class Client : public NonAdmin
{
    public:
        Client(const User* user, EasyTicket& easyTicket);
        void postTicket(const Category category, const QString message, const QString title, const int userId);
        ~Client();
};

#endif /*CLIENT_H*/
