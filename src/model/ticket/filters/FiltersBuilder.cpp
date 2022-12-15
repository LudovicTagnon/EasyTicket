#include "FiltersBuilder.h"

FiltersBuilder::FiltersBuilder()
{

}

FiltersBuilder& FiltersBuilder::setTicketId(QString ticketId)
{
    this->ticketId = ticketId;
    return *this;
}

FiltersBuilder& FiltersBuilder::setTitle(QString title)
{
    this->title = title;
    return *this;
}

FiltersBuilder& FiltersBuilder::addCategories(std::vector<Category> categories)
{
    this->categories.insert(this->categories.end(), categories.begin(), categories.end());
    return *this;
}

FiltersBuilder& FiltersBuilder::addCategory(Category category)
{
    this->categories.push_back(category);
    return *this;
}

FiltersBuilder& FiltersBuilder::setDateDebut(std::time_t dateDebut)
{
    this->dateDebut = dateDebut;
    return *this;
}

FiltersBuilder& FiltersBuilder::setCheckClosedState(bool checkClosedState)
{
    this->checkClosedState = checkClosedState;
    return *this;
}

FiltersBuilder& FiltersBuilder::setIsClosed(bool isClosed)
{
    this->isClosed = isClosed;
    return *this;
}

FiltersBuilder& FiltersBuilder::setDateFin(std::time_t dateFin)
{
    this->dateFin = dateFin;
    return *this;
}

FiltersBuilder& FiltersBuilder::setEmployeeOnIt(NonAdmin* employeeOnIt)
{
    this->employeeOnIt = employeeOnIt;
    return *this;
}

Filters FiltersBuilder::toFilters()
{
    return Filters(ticketId, title, categories, dateDebut, checkClosedState, isClosed, dateFin, employeeOnIt);
}

FiltersBuilder::~FiltersBuilder()
{

}
