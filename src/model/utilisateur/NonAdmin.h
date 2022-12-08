#ifndef NONADMIN_H
#define NONADMIN_H

#include <string>
#include <string_view>
#include <vector>

#include "User.h"
#include "../Category.h"

#include "../ticket/Ticket.h"

class NonAdmin : public User
{
    public:
        NonAdmin(const std::string& userId, const std::string& name, const std::string& surname, const std::string& email, const TicketManager& ticketManager);
        std::string_view& requestMessage(const Ticket& ticket);
        //TODO: Have reflection about how to store Summary
        std::vector<std::string_view> requestTicketsSummary(const int pageNum, const std::string_view& filter);
        void sendMessage(const Ticket& ticket, const std::string_view& message);
        void prendreTicket(const std::string_view& employeeId, const Ticket& ticket);
        void transfererTicket(const std::string_view& employeeId, const Ticket& ticket);
        void changeCategory(const Ticket& ticket, const Category category);
        ~NonAdmin();
};

#endif /*NONADMIN_H*/