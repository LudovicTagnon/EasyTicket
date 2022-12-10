#include "User.h"

User::User(const QString& userId, const QString& name, const QString& surname, const QString& email, EasyTicket& easyTicket)
            : userId(userId)
            , name(name)
            , surname(surname)
            , email(email)
            , easyTicket(easyTicket)
{
    
}

User::~User()
{

}