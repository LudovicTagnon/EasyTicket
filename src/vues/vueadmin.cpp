//
// Created by kudovic on 11/12/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_VueAdmin.h" resolved

#include "vueadmin.h"
#include "ui_VueAdmin.h"


VueAdmin::VueAdmin(QWidget *parent) :
        QWidget(parent), ui(new Ui::VueAdmin) {
    ui->setupUi(this);
}

VueAdmin::~VueAdmin() {
    delete ui;
}
