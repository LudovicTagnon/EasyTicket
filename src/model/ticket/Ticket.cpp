#include "Ticket.h"

#include "../utilisateur/NonAdmin.h"

Ticket::Ticket(const int ticketId, const QString title, const Category category, const NonAdmin* employeeOnIt, const Message message, const QString dateDebut, const bool isClosed, const QString dateFin)
 : ticketId(ticketId)
 , title(title)
 , category(category)
 , dateDebut(dateDebut)
 , isClosed(isClosed)
 , dateFin(dateFin)
 , employeeOnIt(employeeOnIt)
{
    messages.push_back(Message(message.getDate(), message.getMessage()));
}

const QString &Ticket::getTitle() const {
    return title;
}

Category Ticket::getCategory() const {
    return category;
}

bool Ticket::getIsClosed() const {
    return isClosed;
}

int Ticket::getTicketId() const
{
  return ticketId;
}

const QString* Ticket::getEmployeeOnItName() const
{
    if(!employeeOnIt)
        return nullptr;

    return &employeeOnIt->getName();
}

void Ticket::addMessage(Message message)
{
    messages.push_back(message);
}

std::vector<Message>& Ticket::getMessages()
{
    return messages;
}

Ticket::~Ticket()
{

}
