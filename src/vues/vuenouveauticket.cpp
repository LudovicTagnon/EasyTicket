//
// Created by kudovic on 12/12/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_VueNouveauTicket.h" resolved

#include <QMessageBox>
#include <iostream>
#include "vuenouveauticket.h"
#include "ui_VueNouveauTicket.h"
#include "vueclient.h"


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
    if(ui->listWidgetCateg->selectedItems().isEmpty())
    {
        QMessageBox::information(this, "Status", "Veuillez selectionner une catégorie");
        return;
    }
    
    easyTicket.postTicket(static_cast<Category>(ui->listWidgetCateg->row(ui->listWidgetCateg->selectedItems().at(0))), ui->textEditTicket->toPlainText(), ui->lineEditTitreTicket->text(), client.getUserID());
    QMessageBox::information(this, "Status", "Ticket créé");
    easyTicket.popWindow();
}

void VueNouveauTicket::on_RetourButton_clicked(){
    easyTicket.popWindow();
}

QString VueNouveauTicket::removeAccents(QString s) {
    QString diacriticLetters_;
    QStringList noDiacriticLetters_;
    if (diacriticLetters_.isEmpty()) {
        diacriticLetters_ = QString::fromUtf8("ŠŒŽšœžŸ¥µÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖØÙÚÛÜÝßàáâãäåæçèéêëìíîïðñòóôõöøùúûüýÿ");
        noDiacriticLetters_ << "S"<<"OE"<<"Z"<<"s"<<"oe"<<"z"<<"Y"<<"Y"<<"u"<<"A"<<"A"<<"A"<<"A"<<"A"<<"A"<<"AE"<<"C"<<"E"<<"E"<<"E"<<"E"<<"I"<<"I"<<"I"<<"I"<<"D"<<"N"<<"O"<<"O"<<"O"<<"O"<<"O"<<"O"<<"U"<<"U"<<"U"<<"U"<<"Y"<<"s"<<"a"<<"a"<<"a"<<"a"<<"a"<<"a"<<"ae"<<"c"<<"e"<<"e"<<"e"<<"e"<<"i"<<"i"<<"i"<<"i"<<"o"<<"n"<<"o"<<"o"<<"o"<<"o"<<"o"<<"o"<<"u"<<"u"<<"u"<<"u"<<"y"<<"y";
    }

    QString output = "";
    for (int i = 0; i < s.length(); i++) {
        QChar c = s[i];
        int dIndex = diacriticLetters_.indexOf(c);
        if (dIndex < 0) {
            output.append(c);
        } else {
            QString replacement = noDiacriticLetters_[dIndex];
            output.append(replacement);
        }
    }
return output;
}