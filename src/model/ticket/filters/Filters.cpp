#include "Filters.h"

Filters::Filters(const QString ticketId, const QString title, const std::vector<Category> categories
             , const std::time_t dateDebut, const bool checkClosedState, const bool isClosed, const std::time_t dateFin, const NonAdmin* employeeOnIt)
 : ticketId(ticketId)
 , title(title)
 , categories(categories)
 , dateDebut(dateDebut)
 , checkClosedState(checkClosedState)
 , isClosed(isClosed)
 , dateFin(dateFin)
 , employeeOnIt(employeeOnIt)
{
    
}

const QString& Filters::getTicketId(QString ticketId) const
{
    return ticketId;
}

const QString& Filters::getTitle(QString title) const
{
    return title;
}

const std::vector<Category>& Filters::addCategories(std::vector<Category> categories) const
{
    return categories;
}

const std::time_t& Filters::getDateDebut(std::time_t dateDebut) const
{
    return dateDebut;
}

const bool& Filters::getCheckClosedState(bool checkClosedState) const
{
    return checkClosedState;
}

const bool& Filters::getIsClosed(bool isClosed) const
{
    return isClosed;
}

const std::time_t& Filters::getDateFin(const std::time_t dateFin) const
{
    return dateFin;
}

const NonAdmin* Filters::getEmployeeOnIt(const NonAdmin* employeeOnIt) const
{
    return employeeOnIt;
}

Filters::~Filters()
{

}