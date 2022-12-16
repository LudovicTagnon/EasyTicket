//
// Created by kudovic on 11/12/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_VueIngeTech.h" resolved

#include <QMessageBox>
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
}

void VueIngeTech::on_PrendreButton_clicked() {
    easyTicket.pushWindow(new VuePriseTicket(easyTicket));
}

void VueIngeTech::on_ChangeCatButton_clicked() {
    easyTicket.pushWindow(new VueChangeCategorie(easyTicket));
}

void VueIngeTech::on_TransfererButton_clicked() {
    easyTicket.pushWindow(new VueTransferer(easyTicket));
}

void VueIngeTech::on_ATraiterButton_clicked(){
    QMessageBox::information(this, "Status", "Affichage des tickets à traiter");
}

void VueIngeTech::on_ClosButton_clicked(){
    QMessageBox::information(this, "Status", "Affichage des tickets clos");
}

void VueIngeTech::on_EnCoursButton_clicked(){
    QMessageBox::information(this, "Status", "Affichage des tickets en cours");
}