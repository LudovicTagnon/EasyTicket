//
// Created by kudovic on 11/12/22.
//

#ifndef EASYTICKET_VUETECH_H
#define EASYTICKET_VUETECH_H

#include "../model/utilisateur/Technicien.h"
#include "../model/EasyTicket.h"
#include "vueingetech.h"

class VueTech : public VueIngeTech {
public:
    explicit VueTech(Technicien technicien, EasyTicket& easyTicket);

private:
    Technicien technicien;
};


#endif //EASYTICKET_VUETECH_H
