//
// Created by kudovic on 11/12/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_VueIngeTech.h" resolved

#include "vueingetech.h"
#include "ui_VueIngeTech.h"


VueIngeTech::VueIngeTech(EasyTicket& easyTicket, QWidget *parent) :
        QWidget(parent), ui(new Ui::VueIngeTech), easyTicket(easyTicket) {
    ui->setupUi(this);
}

VueIngeTech::~VueIngeTech() {
    delete ui;
}
