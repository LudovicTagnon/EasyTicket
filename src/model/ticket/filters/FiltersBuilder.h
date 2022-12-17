#ifndef __FILTERSBUILDER_H__
#define __FILTERSBUILDER_H__

#include <string>
#include <chrono>
#include <set>
#include <ctime>
#include <algorithm>

#include "../Message.h"
#include "../Category.h"
#include "Filters.h"

class NonAdmin;

class FiltersBuilder
{
    private:
        int ticketId;
        QString title;
        std::set<Category> categories;
        std::time_t dateDebut;
        bool checkClosedState;
        bool isClosed;
        std::time_t dateFin;
        NonAdmin* employeeOnIt;

    public:
        FiltersBuilder();

        FiltersBuilder& setTicketId(int ticketId);
        FiltersBuilder& setTitle(QString title);
        FiltersBuilder& addCategories(std::set<Category> categories);
        FiltersBuilder& addCategory(Category category);
        FiltersBuilder& removeCategories(std::set<Category> categories);
        FiltersBuilder& removeCategory(Category category);
        FiltersBuilder& setDateDebut(std::time_t dateDebut);
        FiltersBuilder& setCheckClosedState(bool checkClosedState);
        FiltersBuilder& setIsClosed(bool isClosed);
        FiltersBuilder& setDateFin(std::time_t dateFin);
        FiltersBuilder& setEmployeeOnIt(NonAdmin* employeeOnIt);

        Filters toFilters();

        ~FiltersBuilder();
};

#endif /*__FILTERSBUILDER_H__*/
