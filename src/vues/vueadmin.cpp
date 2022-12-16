//
// Created by kudovic on 11/12/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_vueadmin.h" resolved

#include "vueadmin.h"
#include "ui_VueAdmin.h"

#include <QMessageBox>
#include <QListWidget>

#include "../model/ticket/filters/FiltersBuilder.h"

VueAdmin::VueAdmin(EasyTicket& easyTicket, QWidget *parent) :
        QWidget(parent), ui(new Ui::VueAdmin), easyTicket(easyTicket),
        page(1) {
    ui->setupUi(this);
}

VueAdmin::~VueAdmin() {
    delete ui;
}

void VueAdmin::on_RafraichirButton_clicked(){
    //EXPERIMENTAL
    /*
    auto tmp = easyTicket.getTicketsSummary(page,
        FiltersBuilder()
            .addCategory(ALL)
            .setCheckClosedState(false)
            .toFilters()
    );
    */

    QStringList tmp{"AAA", "BBB", "CCC"};

    QListWidget* list = findChild<QListWidget*>("listWidgetStats");

    list->clear();
    list->addItems(tmp);

    QMessageBox::information(this, "Status", "La page a bien été rafraîchie");
}
