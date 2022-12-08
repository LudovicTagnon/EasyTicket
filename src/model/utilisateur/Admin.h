#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <vector>

#include "User.h"
#include "Admin.h"
#include "Stat.h"

class Admin : public User
{
    private:
        std::vector<Stat*> stats;
    public:
        Admin(const std::string& userId, const std::string& name, const std::string& surname, const std::string& email, const TicketManager& ticketManager);
        Stat& requestStats();
        ~Admin();
};

#endif /*ADMIN_H*/