//
// Created by kudovic on 12/12/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_VueTicket.h" resolved

#include "vueticket.h"
#include "ui_VueTicket.h"


VueTicket::VueTicket(EasyTicket& easyTicket, QWidget *parent) :
QWidget(parent), ui(new Ui::VueTicket), easyTicket(easyTicket) {
    ui->setupUi(this);
}

VueTicket::~VueTicket() {
    delete ui;
}
