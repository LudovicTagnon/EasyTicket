#ifndef USER_H
#define USER_H

#include <QtCore/QString>

class EasyTicket;

class User
{
    friend class NonAdmin;
    friend class Client;
    friend class Ingenieur;
    friend class Technicien;

    protected:
        const int userId;
        const QString name;
        const QString surname;
        const QString email;

        EasyTicket& easyTicket;

    public:
        User(const int& userId, const QString& name, const QString& surname, const QString& email, EasyTicket& easyTicket);
        User(const User& user, EasyTicket& easyTicket);

        const int& getUserID() const;
        const QString& getName() const;
        const QString& getSurname() const;
        const QString& getEmail() const;

        ~User();
};

#endif /*USER_H*/
