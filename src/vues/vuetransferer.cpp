//
// Created by kudovic on 12/12/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_VueTransferer.h" resolved

#include <QMessageBox>
#include "vuetransferer.h"
#include "ui_VueTransferer.h"


VueTransferer::VueTransferer(EasyTicket& easyTicket, QWidget *parent) :
        QWidget(parent), ui(new Ui::VueTransferer), easyTicket(easyTicket)  {
    ui->setupUi(this);
}

VueTransferer::~VueTransferer() {
    delete ui;
}

void VueTransferer::on_ConfirmerButton_clicked(){
    QMessageBox::information(this, "Status", "Le ticket xxx a bien été transféré à l'employé yyy");
}

void VueTransferer::on_AnnulerButton_clicked(){
    this->close();
}