#ifndef TICKET_H
#define TICKET_H

#include <string>
#include <chrono>
#include <vector>
#include <ctime>

#include "Message.h"
#include "Category.h"

class NonAdmin;

class Ticket
{
    private:
        const int ticketId;
        const QString title;
        const Category category;
        const std::time_t dateDebut;
        const bool isClosed;
        const std::time_t dateFin;
        std::vector<Message> messages;
        const NonAdmin* employeeOnIt;

    public:
        Ticket(const int ticketId, const QString title, const Category category,
                const std::time_t dateDebut = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()),
                const bool isClosed = false,
                const std::time_t dateFin = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));

        int getTicketId() const;

        ~Ticket();

    const QString &getTitle() const;

    const Category getCategory() const;

    const bool getIsClosed() const;
};

#endif /*TICKET_H*/
