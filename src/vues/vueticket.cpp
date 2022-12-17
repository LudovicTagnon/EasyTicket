//
// Created by kudovic on 12/12/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_VueTicket.h" resolved

#include "vueticket.h"
#include "ui_VueTicket.h"

#include <iostream>

#include <QMessageBox>

#include "../model/ticket/Ticket.h"

VueTicket::VueTicket(EasyTicket& easyTicket, Ticket& ticket, QWidget *parent) :
QWidget(parent), ui(new Ui::VueTicket), easyTicket(easyTicket), ticket(ticket) {
    ui->setupUi(this);

    ui->listWidget->clear();
    ui->listWidget_2->clear();

    const QString* tmp = ticket.getEmployeeOnItName();
    QString employeeOnIt = "N/A";
    if(tmp) employeeOnIt = *tmp;

    ui->labelTech_2->setText(employeeOnIt);

    QStringList qstrlistWidget;
    QStringList qstrlistWidget_2;

    for(Message& m : ticket.getMessages())
    {
        qstrlistWidget << m.getMessage();
        qstrlistWidget_2 << m.getDate();
    }

    ui->listWidget->addItems(qstrlistWidget);
    ui->listWidget_2->addItems(qstrlistWidget_2);
}

VueTicket::~VueTicket() {
    delete ui;
}

void VueTicket::on_EnvoyerButton_clicked(){
    QMessageBox::information(this, "Status", "Message envoyé");
    //easyTicket.requestSendMessage();
    easyTicket.popWindow();
}

void VueTicket::on_RetourButton_clicked(){
    easyTicket.popWindow();
}