#ifndef TICKETMANAGER_H
#define TICKETMANAGER_H

#include <vector>
#include <string_view>
#include <memory>

#include "Ticket.h"
#include "../Category.h"

class User;

class TicketManager
{
    private:
        std::vector<std::unique_ptr<Ticket>> tickets;

    public:
        TicketManager();

        std::string_view& requestMessage(const Ticket& ticketId);
        void prendreTicket(const User& user, const Ticket& ticket);
        void transfertTicket(const User& user, const Ticket& ticket);
        //TODO : have reflexions about differences between summary and complete ticket, for the implementation
        std::string_view requestTicketsSummary(const int pageNum, const std::string_view& filter);
        void changeCategory(const Ticket& ticket, const Category category);
        void sendMessage(const Ticket& ticket, const std::string_view& message);

        ~TicketManager();
};

#endif /*TICKETMANAGER_H*/