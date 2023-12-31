#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <vector>

#include "User.h"
#include "Admin.h"
#include "../stat/Stat.h"
#include "../EasyTicket.h"

class Admin : public User
{
    private:
        std::vector<Stat*> stats;
    public:
        Admin(const User* user, EasyTicket& easyTicket);
        Stat& requestStats();
        ~Admin();
};

#endif /*ADMIN_H*/
