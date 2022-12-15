#ifndef __FILTERS_H__
#define __FILTERS_H__

#include <string>
#include <chrono>
#include <vector>
#include <ctime>
#include <any>
#include <map>

#include "../Message.h"
#include "../Category.h"

class NonAdmin;

class Filters
{
    friend class FiltersBuilder;

    private:
        const QString ticketId;
        const QString title;
        const std::vector<Category> categories;
        const std::time_t dateDebut;
        const bool checkClosedState;
        const bool isClosed;
        const std::time_t dateFin;
        const NonAdmin* employeeOnIt;

        Filters(const QString ticketId, const QString title, const std::vector<Category> categories
             , const std::time_t dateDebut = -1, const bool checkClosedState = false, const bool isClosed = false
             , const std::time_t dateFin = -1, const NonAdmin* employeeOnIt = nullptr);
        
        const QString& getTicketId(const QString ticketId) const;
        const QString& getTitle(const QString title) const;
        const std::vector<Category>& addCategories(const std::vector<Category> categories) const;
        const std::time_t& getDateDebut(const std::time_t dateDebut) const;
        const bool& getCheckClosedState(const bool checkClosedState) const;
        const bool& getIsClosed(const bool isClosed) const;
        const std::time_t& getDateFin(const std::time_t dateFin) const;
        const NonAdmin* getEmployeeOnIt(const NonAdmin* employeeOnIt) const;

        //https://stackoverflow.com/questions/24702235/c-stdmap-holding-any-type-of-value
        const std::map<std::string, std::any> toMap();

        ~Filters();
};

#endif /*__FILTERS_H__*/
