//
// Created by kudovic on 16/12/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_VueInscription.h" resolved

#include <QMessageBox>
#include "vueinscription.h"
#include "ui_VueInscription.h"


VueInscription::VueInscription(EasyTicket& easyTicket, QWidget *parent) :
        QWidget(parent), ui(new Ui::VueInscription), easyTicket(easyTicket) {
    ui->setupUi(this);
}

VueInscription::~VueInscription() {
    delete ui;
}

void VueInscription::on_ConfirmerButton_clicked(){
    QMessageBox::information(this, "Status", "Inscription bien prise en compte");
}

void VueInscription::on_RetourButton_clicked(){
    //QMessageBox::information(this, "Status", "Affichage des tickets en cours");
}