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

void VueIngeTech::on_OuvrirButton_clicked() {
    easyTicket.pushWindow(new VueTicket(easyTicket));
    easyTicket.start();
}

void VueIngeTech::on_PrendreButton_clicked() {
    easyTicket.pushWindow(new VuePriseTicket(easyTicket));
    easyTicket.start();
}

void VueIngeTech::on_ChangeCatButton_clicked() {
    easyTicket.pushWindow(new VueChangeCategorie(easyTicket));
    easyTicket.start();
}

void VueIngeTech::on_TransfererButton_clicked() {
    easyTicket.pushWindow(new VueTransferer(easyTicket));
    easyTicket.start();
}