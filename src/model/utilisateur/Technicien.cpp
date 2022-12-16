#include "Technicien.h"

#include "../EasyTicket.h"

Technicien::Technicien(const int& userId, const QString& name, const QString& surname, const QString& email, EasyTicket& easyTicket, const std::set<Category> categories)
: Ingenieur(userId, name, surname, email, easyTicket, false, categories)
{

    //todo: define categories here
}

Technicien::~Technicien()
{

}
