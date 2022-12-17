//
// Created by kudovic on 12/12/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_VuePriseTicket.h" resolved

#include <QMessageBox>

#include "vuepriseticket.h"
#include "ui_VuePriseTicket.h"

#include "../model/utilisateur/NonAdmin.h"

VuePriseTicket::VuePriseTicket(EasyTicket& easyTicket, NonAdmin& nonAdmin, Ticket& ticket, QWidget *parent) :
        ticket(ticket),
        nonAdmin(nonAdmin),
        easyTicket(easyTicket),
        ui(new Ui::VuePriseTicket),
        QWidget(parent)
{
    ui->setupUi(this);
}

VuePriseTicket::~VuePriseTicket() {
    delete ui;
}

void VuePriseTicket::on_ConfirmerButton_clicked(){
    bool ret = easyTicket.setEmployeeOntIt(ticket, nonAdmin);

    if(!ret)
        QMessageBox::information(this, "Status", "Impossible de prendre en charge le ticket");
    else
        QMessageBox::information(this, "Status", "La prise en charge du ticket vous a bien été attribuée");
}

void VuePriseTicket::on_AnnulerButton_clicked(){
    easyTicket.popWindow();
}