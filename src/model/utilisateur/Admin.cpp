#include "Admin.h"

Admin::Admin(const QString userId, const QString name, const QString surname, const QString email, EasyTicket& easyTicket)
: User(userId, name, surname, email, easyTicket)
{

}

/* TODO:
Stat& requestStats()
{

}
*/

Admin::~Admin()
{

}
