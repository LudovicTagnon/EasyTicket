#ifndef NONADMIN_H
#define NONADMIN_H

#include <string>
#include <vector>

#include <QtCore/QString>

#include "User.h"
#include "../Category.h"
#include "../ticket/Ticket.h"
#include "../EasyTicket.h"


class NonAdmin : public User
{
    public:
        NonAdmin(const QString userId, const QString name, const QString surname, const QString email, EasyTicket& easyTicket);
        QString& requestMessage(const Ticket& ticket);
        //TODO: Have reflection about how to store Summary
        std::vector<QString> requestTicketsSummary(const int pageNum, const QString& filter);
        void sendMessage(const Ticket& ticket, const QString& message);
        ~NonAdmin();
};

#endif /*NONADMIN_H*/