#include "Filters.h"

Filters::Filters(const int& ticketId, const QString& title, const std::set<Category>& categories
             , const std::time_t& dateDebut, const bool& checkClosedState, const bool& isClosed, const std::time_t& dateFin, const NonAdmin* employeeOnIt)
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

const int& Filters::getTicketId() const
{
    return ticketId;
}

const QString& Filters::getTitle() const
{
    return title;
}

const std::set<Category>& Filters::addCategories() const
{
    return categories;
}

const std::time_t& Filters::getDateDebut() const
{
    return dateDebut;
}

const bool& Filters::getCheckClosedState() const
{
    return checkClosedState;
}

const bool& Filters::getIsClosed() const
{
    return isClosed;
}

const std::time_t& Filters::getDateFin() const
{
    return dateFin;
}

const NonAdmin* Filters::getEmployeeOnIt() const
{
    return employeeOnIt;
}

const std::map<std::string, std::any> Filters::toMap()
{
    //std::string, std::string, std::set<Category>*, std::time_t, std::time_t, bool, bool, NonAdmin*
    return std::map<std::string, std::any>{
        {"ticketId", ticketId},
        {"title", title},
        {"categories", &categories},
        {"dateDebut", dateDebut},
        {"checkClosedState", checkClosedState},
        {"isClosed", isClosed},
        {"dateFin", dateFin},
        {"employeeOnIt", employeeOnIt}};
}

Filters::~Filters()
{

}
