#include "User.h"

User::User(const int& userId, const QString& name, const QString& surname, const QString& email, EasyTicket& easyTicket)
            : userId(userId)
            , name(name)
            , surname(surname)
            , email(email)
            , easyTicket(easyTicket)
{

}

int User::getUserId()
{
  return userId;
}

User::~User()
{

}
