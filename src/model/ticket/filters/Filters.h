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
        const QString dateDebut;
        const bool checkClosedState;
        const bool isClosed;
        const QString dateFin;
        const NonAdmin* employeeOnIt;

    public:
        Filters(const int& ticketId, const QString& title, const std::set<Category>& categories
             , const QString& dateDebut = "N/A", const bool& checkClosedState = false, const bool& isClosed = false
             , const QString& dateFin = "N/A", const NonAdmin* employeeOnIt = nullptr);

        const int& getTicketId() const;
        const QString& getTitle() const;
        const std::set<Category>& addCategories() const;
        const QString& getDateDebut() const;
        const bool& getCheckClosedState() const;
        const bool& getIsClosed() const;
        const QString& getDateFin() const;
        const NonAdmin* getEmployeeOnIt() const;

        //https://stackoverflow.com/questions/24702235/c-stdmap-holding-any-type-of-value
        const std::map<std::string, std::any> toMap();

        ~Filters();
};

#endif /*__FILTERS_H__*/
