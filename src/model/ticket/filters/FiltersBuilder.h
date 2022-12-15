#ifndef __FILTERSBUILDER_H__
#define __FILTERSBUILDER_H__

#include <string>
#include <chrono>
#include <vector>
#include <ctime>

#include "../Message.h"
#include "../Category.h"
#include "Filters.h"

class NonAdmin;

class FiltersBuilder
{
    private:
        QString ticketId;
        QString title;
        std::vector<Category> categories;
        std::time_t dateDebut;
        bool checkClosedState;
        bool isClosed;
        std::time_t dateFin;
        NonAdmin* employeeOnIt;
        
    public:
        FiltersBuilder();

        FiltersBuilder& setTicketId(QString ticketId);
        FiltersBuilder& setTitle(QString title);
        FiltersBuilder& addCategories(std::vector<Category> categories);
        FiltersBuilder& addCategory(Category category);
        FiltersBuilder& setDateDebut(std::time_t dateDebut);
        FiltersBuilder& setCheckClosedState(bool checkClosedState);
        FiltersBuilder& setIsClosed(bool isClosed);
        FiltersBuilder& setDateFin(std::time_t dateFin);
        FiltersBuilder& setEmployeeOnIt(NonAdmin* employeeOnIt);

        Filters toFilters();

        ~FiltersBuilder();
};

#endif /*__FILTERSBUILDER_H__*/
