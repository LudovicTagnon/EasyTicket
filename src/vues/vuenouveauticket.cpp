//
// Created by kudovic on 12/12/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_VueNouveauTicket.h" resolved

#include "vuenouveauticket.h"
#include "ui_VueNouveauTicket.h"


VueNouveauTicket::VueNouveauTicket(EasyTicket& easyTicket, QWidget *parent) :
        QWidget(parent), ui(new Ui::VueNouveauTicket), easyTicket(easyTicket) {
    ui->setupUi(this);
}

VueNouveauTicket::~VueNouveauTicket() {
    delete ui;
}
