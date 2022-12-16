#include "User.h"

User::User(const int& userId, const QString& name, const QString& surname, const QString& email, EasyTicket& easyTicket)
            : userId(userId)
            , name(name)
            , surname(surname)
            , email(email)
            , easyTicket(easyTicket)
{

}

User::User(const User& user, EasyTicket& easyTicket)
            : userId(user.getUserID())
            , name(user.getName())
            , surname(user.getSurname())
            , email(user.getEmail())
            , easyTicket(easyTicket)
{
    
}

const int& User::getUserID() const
{
    return userId;
}

const QString& User::getName() const
{
    return name;
}

const QString& User::getSurname() const
{
    return surname;
}

const QString& User::getEmail() const
{
    return email;
}

User::~User()
{

}
