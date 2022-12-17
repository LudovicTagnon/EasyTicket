#ifndef __FILTERS_H__
#define __FILTERS_H__

#include <string>
#include <chrono>
#include <set>
#include <ctime>
#include <any>
#include <map>

#include "../Message.h"
#include "../Category.h"

class NonAdmin;

class Filters
{
    private:
        const int ticketId;
        const QString title;
        const std::set<Category> categories;
        const std::time_t dateDebut;
        const bool checkClosedState;
        const bool isClosed;
        const std::time_t dateFin;
        const NonAdmin* employeeOnIt;

    public:
        Filters(const int& ticketId, const QString& title, const std::set<Category>& categories
             , const std::time_t& dateDebut = -1, const bool& checkClosedState = false, const bool& isClosed = false
             , const std::time_t& dateFin = -1, const NonAdmin* employeeOnIt = nullptr);

        const int& getTicketId() const;
        const QString& getTitle() const;
        const std::set<Category>& addCategories() const;
        const std::time_t& getDateDebut() const;
        const bool& getCheckClosedState() const;
        const bool& getIsClosed() const;
        const std::time_t& getDateFin() const;
        const NonAdmin* getEmployeeOnIt() const;

        //https://stackoverflow.com/questions/24702235/c-stdmap-holding-any-type-of-value
        const std::map<std::string, std::any> toMap();

        ~Filters();
};

#endif /*__FILTERS_H__*/
