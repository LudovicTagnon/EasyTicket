//
// Created by kudovic on 12/12/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_VueChangeCategorie.h" resolved

#include "vuechangecategorie.h"
#include "ui_VueChangeCategorie.h"


VueChangeCategorie::VueChangeCategorie(EasyTicket& easyTicket, QWidget *parent) :
        QWidget(parent), ui(new Ui::VueChangeCategorie), easyTicket(easyTicket) {
    ui->setupUi(this);
}

VueChangeCategorie::~VueChangeCategorie() {
    delete ui;
}
