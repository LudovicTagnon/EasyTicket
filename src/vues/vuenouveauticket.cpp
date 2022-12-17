//
// Created by kudovic on 12/12/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_VueNouveauTicket.h" resolved

#include <QMessageBox>
#include "vuenouveauticket.h"
#include "ui_VueNouveauTicket.h"


VueNouveauTicket::VueNouveauTicket(EasyTicket& easyTicket, Client client, QWidget *parent) :
        QWidget(parent), ui(new Ui::VueNouveauTicket), easyTicket(easyTicket), client(client) {
    ui->setupUi(this);
    ui->listWidgetCateg->clear();
    ui->listWidgetCateg->addItems(easyTicket.getCategories());
}

VueNouveauTicket::~VueNouveauTicket() {
    delete ui;
}

void VueNouveauTicket::on_ConfirmerButton_clicked() {
    easyTicket.postTicket(static_cast<Category>(ui->listWidgetCateg->row(ui->listWidgetCateg->selectedItems().at(0))), ui->textEditTicket->toPlainText(), ui->textEditResume->toPlainText(), client.getUserID());
    QMessageBox::information(this, "Status", "Ticket créé");
}

void VueNouveauTicket::on_RetourButton_clicked(){
    easyTicket.popWindow();
}

