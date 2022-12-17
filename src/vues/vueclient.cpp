//
// Created by kudovic on 11/12/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_VueClient.h" resolved

#include <QMessageBox>
#include <iostream>
#include "vueclient.h"
#include "ui_VueClient.h"


VueClient::VueClient(Client client, EasyTicket& easyTicket, QWidget *parent) :
QWidget(parent), ui(new Ui::VueClient), easyTicket(easyTicket), client(client), page(1){
    ui->setupUi(this);

    affichageTickets();

}

VueClient::~VueClient() {
    delete ui;
}

void VueClient::affichageTickets() {
    ui->listWidgetNomTicket->clear();
    ui->listWidgetResumeTicket->clear();
    ui->listWidgetCategorieTicket->clear();
    ui->listWidgetStatusResolutionTicket->clear();

    QStringList qstrlistTitle;
    for(Ticket ticket: easyTicket.getTicketManager().getTickets()){
        qstrlistTitle << ticket.getTitle();
    }
    ui->listWidgetNomTicket->addItems(qstrlistTitle);
}

void VueClient::on_OuvrirButton_clicked() {
    easyTicket.pushWindow(new VueTicket(easyTicket));
}

void VueClient::on_NouveauButton_clicked() {
    easyTicket.pushWindow(new VueNouveauTicket(easyTicket, client));
}

void VueClient::on_ClosButton_clicked(){
    QMessageBox::information(this, "Status", "Affichage des tickets clos");
}

void VueClient::on_EnCoursButton_clicked(){
    QMessageBox::information(this, "Status", "Affichage des tickets en cours");
}

void VueClient::on_RafraichirButton_clicked(){
    affichageTickets();
}
