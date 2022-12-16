//
// Created by kudovic on 11/12/22.
//

#ifndef EASYTICKET_VUEINGE_H
#define EASYTICKET_VUEINGE_H

#include "../model/utilisateur/Ingenieur.h"
#include "../model/EasyTicket.h"
#include "vueingetech.h"

namespace Ui {
    class VueInge;
}

class VueInge : public VueIngeTech {
public:
    explicit VueInge(Ingenieur ingenieur, EasyTicket& easyTicket);

private:
    Ingenieur ingenieur;

    int page;
};


#endif //EASYTICKET_VUEINGE_H
