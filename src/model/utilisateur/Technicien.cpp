#include "Technicien.h"

#include "../EasyTicket.h"

Technicien::Technicien(const User user, EasyTicket& easyTicket, const std::set<Category> categories)
: Ingenieur(user, easyTicket, false, categories)
{

    //todo: define categories here
}

Technicien::~Technicien()
{

}
