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
        const QString dateDebut;
        const bool isClosed;
        const QString dateFin;
        std::vector<Message> messages;
        const NonAdmin* employeeOnIt;

    public:
        Ticket(const int ticketId, const QString title, const Category category, const NonAdmin* employeeOnIt, const Message message,
                const QString dateDebut = "N/A",
                const bool isClosed = false,
                const QString dateFin = "N/A");

        int getTicketId() const;

        ~Ticket();

        const QString &getTitle() const;
        Category getCategory() const;
        bool getIsClosed() const;
        const QString* getEmployeeOnItName() const;
        std::vector<Message>& getMessages();
        void addMessage(Message message);
        void setEmployeeOnIt(NonAdmin* nonAdmin);
};

#endif /*TICKET_H*/
