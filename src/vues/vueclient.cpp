//
// Created by kudovic on 11/12/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_VueClient.h" resolved

#include "vueclient.h"
#include "ui_VueClient.h"


VueClient::VueClient(EasyTicket& easyTicket, QWidget *parent) :
QWidget(parent), ui(new Ui::VueClient), easyTicket(easyTicket) {
    ui->setupUi(this);
}

VueClient::~VueClient() {
    delete ui;
}

void VueClient::on_OuvrirButton_clicked() {
    easyTicket.pushWindow(new VueTicket(easyTicket));
    easyTicket.start();
}

void VueClient::on_NouveauButton_clicked() {
    easyTicket.pushWindow(new VueNouveauTicket(easyTicket));
    easyTicket.start();

}