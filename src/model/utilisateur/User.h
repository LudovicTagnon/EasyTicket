#ifndef USER_H
#define USER_H

#include <QtCore/QString>

class EasyTicket;

class User
{
    protected:
        const int userId;
        const QString name;
        const QString surname;
        const QString email;

        EasyTicket& easyTicket;

    public:
        User(const int& userId,
             const QString& name,
             const QString& surname,
             const QString& email,
             EasyTicket& easyTicket);

        int getUserId();

        ~User();
};

#endif /*USER_H*/
