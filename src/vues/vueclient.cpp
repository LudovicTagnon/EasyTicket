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
    filtre = 0;
    affichageTickets();

}

VueClient::~VueClient() {
    delete ui;
}

void VueClient::affichageTickets() {
    ui->listWidgetNomTicket->clear();
    ui->listWidgetCategorieTicket->clear();
    ui->listWidgetStatusResolutionTicket->clear();

    QStringList qstrlistTitle;
    QStringList qstrlistResume;
    QStringList qstrlistCategorie;
    QStringList qstrlistStatus;

    for(Ticket ticket: easyTicket.getTicketManager().getTickets()){

        if(filtre == 0){ // si pas de filtre
            if (ticket.getIsClosed()){
                qstrlistStatus << "Clos";
            }else {
                qstrlistStatus << "En cours";
            }
            qstrlistTitle << ticket.getTitle();

            if(ticket.getCategory()==ALL){
                qstrlistCategorie << (QString) "ALL";
            }else if(ticket.getCategory()==CREATION){
                qstrlistCategorie << (QString) "CREATION";
            }else if(ticket.getCategory()==VISUALISATION){
                qstrlistCategorie << (QString) "VISUALISATION";
            }else if(ticket.getCategory()==WINDOWS){
                qstrlistCategorie << (QString) "WINDOWS";
            }else if(ticket.getCategory()==RECLAMATION){
                qstrlistCategorie << (QString) "RECLAMATION";
            }
        }
        else if(filtre == 1){
            if (!ticket.getIsClosed()){
                qstrlistStatus << "En cours";
                qstrlistTitle << ticket.getTitle();

                if(ticket.getCategory()==ALL){
                    qstrlistCategorie << (QString) "ALL";
                }else if(ticket.getCategory()==CREATION){
                    qstrlistCategorie << (QString) "CREATION";
                }else if(ticket.getCategory()==VISUALISATION){
                    qstrlistCategorie << (QString) "VISUALISATION";
                }else if(ticket.getCategory()==WINDOWS){
                    qstrlistCategorie << (QString) "WINDOWS";
                }else if(ticket.getCategory()==RECLAMATION){
                    qstrlistCategorie << (QString) "RECLAMATION";
                }
            }
        }
        else if(filtre == -1){
            if (ticket.getIsClosed()){
                qstrlistStatus << "Clos";
                qstrlistTitle << ticket.getTitle();

                if(ticket.getCategory()==ALL){
                    qstrlistCategorie << (QString) "ALL";
                }else if(ticket.getCategory()==CREATION){
                    qstrlistCategorie << (QString) "CREATION";
                }else if(ticket.getCategory()==VISUALISATION){
                    qstrlistCategorie << (QString) "VISUALISATION";
                }else if(ticket.getCategory()==WINDOWS){
                    qstrlistCategorie << (QString) "WINDOWS";
                }else if(ticket.getCategory()==RECLAMATION){
                    qstrlistCategorie << (QString) "RECLAMATION";
                }
            }
        }




    }
    ui->listWidgetNomTicket->addItems(qstrlistTitle);
    ui->listWidgetCategorieTicket->addItems(qstrlistCategorie);
    ui->listWidgetStatusResolutionTicket->addItems(qstrlistStatus);
}

void VueClient::on_OuvrirButton_clicked() {
    easyTicket.pushWindow(new VueTicket(easyTicket));
}

void VueClient::on_NouveauButton_clicked() {
    easyTicket.pushWindow(new VueNouveauTicket(easyTicket, client));
}

void VueClient::on_ClosButton_clicked(){
    QMessageBox::information(this, "Status", "Affichage des tickets clos");
    if(filtre==1 || filtre == 0){
        filtre = -1;
    }else{
        filtre = 0;
    }
    affichageTickets();
}

void VueClient::on_EnCoursButton_clicked(){
    QMessageBox::information(this, "Status", "Affichage des tickets en cours");
    if(filtre==-1 || filtre == 0){
        filtre = 1;
    }else{
        filtre = 0;
    }
    affichageTickets();
}

void VueClient::on_RafraichirButton_clicked(){
    easyTicket.refreshTickets();
    affichageTickets();
}
