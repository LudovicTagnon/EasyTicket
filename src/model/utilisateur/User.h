#ifndef USER_H
#define USER_H

#include <QtCore/QString>

class EasyTicket;

class User
{
    protected:
        const QString userId;
        const QString name;
        const QString surname;
        const QString email;

        EasyTicket& easyTicket;
    
    public:
        User(const QString& userId,
             const QString& name,
             const QString& surname,
             const QString& email,
             EasyTicket& easyTicket);
        ~User();
};

#endif /*USER_H*/