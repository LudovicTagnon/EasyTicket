#ifndef TICKET_H
#define TICKET_H

#include <string>
#include <chrono>
#include <vector>

#include "../Date.h"
#include "Message.h"

class NonAdmin;
class NonAdmin;

class Ticket
{
    private:
        const std::string ticketId;
        const std::string title;
        const Date dateDebut;
        const Date dateFin;
        std::vector<Message> messages;
        const NonAdmin* employeeOnIt;
        bool isClosed;
    public:
        Ticket(const std::string& ticketId, const std::string& title, const Date& dateDebut);
        ~Ticket();
};

#endif /*TICKET_H*/