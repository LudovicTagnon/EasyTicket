//
// Created by kudovic on 11/12/22.
//

#ifndef EASYTICKET_VUEADMIN_H
#define EASYTICKET_VUEADMIN_H

#include <QWidget>
#include "../model/utilisateur/Admin.h"
#include "../model/EasyTicket.h"

QT_BEGIN_NAMESPACE
namespace Ui { class VueAdmin; }
QT_END_NAMESPACE

class VueAdmin : public QWidget {
Q_OBJECT

public:
    explicit VueAdmin(Admin admin, EasyTicket& easyTicket, QWidget *parent = nullptr);

    ~VueAdmin() override;

private slots:
    void on_RafraichirButton_clicked();

private:
    Ui::VueAdmin *ui;
    EasyTicket& easyTicket;
    Admin admin;

    int page;
};


#endif //EASYTICKET_VUEADMIN_H
