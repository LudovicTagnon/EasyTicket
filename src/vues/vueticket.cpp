//
// Created by kudovic on 12/12/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_VueTicket.h" resolved

#include <QMessageBox>
#include "vueticket.h"
#include "ui_VueTicket.h"


VueTicket::VueTicket(EasyTicket& easyTicket, QWidget *parent) :
QWidget(parent), ui(new Ui::VueTicket), easyTicket(easyTicket) {
    ui->setupUi(this);
}

VueTicket::~VueTicket() {
    delete ui;
}

void VueTicket::on_EnvoyerButton_clicked(){
    QMessageBox::information(this, "Status", "Message envoyé");
}

void VueTicket::on_RetourButton_clicked(){
    easyTicket.popWindow();
}