#ifndef NONADMIN_H
#define NONADMIN_H

#include <string>
#include <vector>

#include <QtCore/QString>

#include "User.h"
#include "../ticket/Category.h"
#include "../ticket/Ticket.h"
#include "../EasyTicket.h"
#include "../ticket/filters/Filters.h"


class NonAdmin : public User
{
    public:
    NonAdmin(const User user, EasyTicket& easyTicket);
        QString& requestMessage(const Ticket& ticket);
        //TODO: Have reflection about how to store Summary
        std::vector<QString> requestTicketsSummary(const int pageNum, const Filters& filters);
        void sendMessage(const Ticket& ticket, const QString& message);
        ~NonAdmin();
};

#endif /*NONADMIN_H*/
