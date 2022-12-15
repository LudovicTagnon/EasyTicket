//
// Created by kudovic on 11/12/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_vueadmin.h" resolved

#include <QMessageBox>
#include "vueadmin.h"
#include "ui_VueAdmin.h"


VueAdmin::VueAdmin(EasyTicket& easyTicket, QWidget *parent) :
        QWidget(parent), ui(new Ui::VueAdmin), easyTicket(easyTicket) {
    ui->setupUi(this);
}

VueAdmin::~VueAdmin() {
    delete ui;
}

void VueAdmin::on_RafraichirButton_clicked(){
    QMessageBox::information(this, "Status", "La page a bien été rafraîchie");
}
