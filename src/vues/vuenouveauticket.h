//
// Created by kudovic on 12/12/22.
//

#ifndef EASYTICKET_VUENOUVEAUTICKET_H
#define EASYTICKET_VUENOUVEAUTICKET_H

#include <QWidget>
#include "../model/EasyTicket.h"
#include "../model/utilisateur/Client.h"


QT_BEGIN_NAMESPACE
namespace Ui { class VueNouveauTicket; }
QT_END_NAMESPACE

class VueNouveauTicket : public QWidget {
Q_OBJECT

public:
    explicit VueNouveauTicket(EasyTicket& easyTicket, Client client, QWidget *parent = nullptr);

    ~VueNouveauTicket() override;

private slots:
    void on_ConfirmerButton_clicked();
    void on_RetourButton_clicked();

private:
    Ui::VueNouveauTicket *ui;
    EasyTicket& easyTicket;
    Client client;
};


#endif //EASYTICKET_VUENOUVEAUTICKET_H
