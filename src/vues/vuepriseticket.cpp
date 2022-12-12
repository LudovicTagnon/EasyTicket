//
// Created by kudovic on 12/12/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_VuePriseTicket.h" resolved

#include "vuepriseticket.h"
#include "ui_VuePriseTicket.h"


VuePriseTicket::VuePriseTicket(EasyTicket& easyTicket,QWidget *parent) :
        QWidget(parent),
        ui(new Ui::VuePriseTicket),
        easyTicket(easyTicket)
        {
    ui->setupUi(this);
}

VuePriseTicket::~VuePriseTicket() {
    delete ui;
}

