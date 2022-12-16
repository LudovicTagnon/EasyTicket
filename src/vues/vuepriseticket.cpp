//
// Created by kudovic on 12/12/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_VuePriseTicket.h" resolved

#include <QMessageBox>
#include "vuepriseticket.h"
#include "ui_VuePriseTicket.h"


VuePriseTicket::VuePriseTicket(EasyTicket& easyTicket,QWidget *parent) :
        QWidget(parent),
        ui(new Ui::VuePriseTicket),
        easyTicket(easyTicket)
        {
    ui->setupUi(this);
}

VuePriseTicket::~VuePriseTicket() {
    delete ui;
}

void VuePriseTicket::on_ConfirmerButton_clicked(){
    QMessageBox::information(this, "Status", "La prise en charge du ticket vous a bien été attribuée");
}

void VuePriseTicket::on_AnnulerButton_clicked(){
    easyTicket.popWindow();
}