#include "FiltersBuilder.h"

FiltersBuilder::FiltersBuilder()
{

}

FiltersBuilder& FiltersBuilder::setTicketId(QString ticketId)
{
    this->ticketId = ticketId;
}

FiltersBuilder& FiltersBuilder::setTitle(QString title)
{
    this->title = title;
}

FiltersBuilder& FiltersBuilder::addCategories(std::vector<Category> categories)
{
    this->categories.insert(this->categories.end(), categories.begin(), categories.end());
}

FiltersBuilder& FiltersBuilder::addCategory(Category category)
{
    this->categories.push_back(category);
}

FiltersBuilder& FiltersBuilder::setDateDebut(std::time_t dateDebut)
{
    this->dateDebut = dateDebut;
}

FiltersBuilder& FiltersBuilder::setCheckClosedState(bool checkClosedState)
{
    this->checkClosedState = checkClosedState;
}

FiltersBuilder& FiltersBuilder::setIsClosed(bool isClosed)
{
    this->isClosed = isClosed;
}

FiltersBuilder& FiltersBuilder::setDateFin(std::time_t dateFin)
{
    this->dateFin = dateFin;
}

FiltersBuilder& FiltersBuilder::setEmployeeOnIt(NonAdmin* employeeOnIt)
{
    this->employeeOnIt = employeeOnIt;
}

Filter FiltersBuilder::toFilter()
{
    return Filter(ticketId, title, categories, dateDebut, checkClosedState, isClosed, dateFin, employeeOnIt);
}

FiltersBuilder::~FiltersBuilder()
{

}
