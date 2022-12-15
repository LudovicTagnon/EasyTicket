//
// Created by kudovic on 12/12/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_VueChangeCategorie.h" resolved

#include <QMessageBox>
#include "vuechangecategorie.h"
#include "ui_VueChangeCategorie.h"


VueChangeCategorie::VueChangeCategorie(EasyTicket& easyTicket, QWidget *parent) :
        QWidget(parent), ui(new Ui::VueChangeCategorie), easyTicket(easyTicket) {
    ui->setupUi(this);
}

VueChangeCategorie::~VueChangeCategorie() {
    delete ui;
}

void VueChangeCategorie::on_ConfirmerButton_clicked(){
    QMessageBox::information(this, "Status", "La nouvelle catégorie a bien été appliquée à ce ticket");
}

void VueChangeCategorie::on_AnnulerButton_clicked(){
    this->close();
}
