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

void VueIngeTech::affichageTickets() {
    ui->listWidgetTitreTicket->clear();
    ui->listWidgetCategoryTicket->clear();
    ui->listWidgetStatusTicket->clear();

    QStringList qstrlistTitle;
    QStringList qstrlistResume;
    QStringList qstrlistCategorie;
    QStringList qstrlistStatus;

    for(Ticket ticket: easyTicket.getTicketManager().getTickets()){
        qstrlistTitle << ticket.getTitle();

        if(ticket.getCategory()==ALL) qstrlistCategorie << (QString) "ALL";
        else if(ticket.getCategory()==CREATION) qstrlistCategorie << (QString) "CREATION";
        else if(ticket.getCategory()==VISUALISATION) qstrlistCategorie << (QString) "VISUALISATION";
        else if(ticket.getCategory()==WINDOWS) qstrlistCategorie << (QString) "WINDOWS";
        else if(ticket.getCategory()==RECLAMATION) qstrlistCategorie << (QString) "RECLAMATION";
        else if(ticket.getCategory()==OTHER) qstrlistCategorie << (QString) "OTHER";
        if(ticket.getIsClosed())  qstrlistStatus << "Clos";
        else  qstrlistStatus << "En cours";
    }
    ui->listWidgetTitreTicket->addItems(qstrlistTitle);
    ui->listWidgetCategoryTicket->addItems(qstrlistCategorie);
    ui->listWidgetStatusTicket->addItems(qstrlistStatus);
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
