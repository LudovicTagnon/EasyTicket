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

    void on_PrendreButton_clicked() override;

private:
    Technicien technicien;
};


#endif //EASYTICKET_VUETECH_H
