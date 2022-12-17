//
// Created by kudovic on 11/12/22.
//

#ifndef EASYTICKET_VUECLIENT_H
#define EASYTICKET_VUECLIENT_H

#include <QWidget>
#include "../model/utilisateur/Client.h"
#include "../model/EasyTicket.h"
#include "vuenouveauticket.h"
#include "vueticket.h"


QT_BEGIN_NAMESPACE
namespace Ui { class VueClient; }
QT_END_NAMESPACE

class VueClient : public QWidget {
Q_OBJECT

public:
    explicit VueClient(Client client, EasyTicket& easyTicket, QWidget *parent = nullptr);

    ~VueClient() override;

    void affichageTickets();

private slots:
    void on_OuvrirButton_clicked();
    void on_NouveauButton_clicked();
    void on_ClosButton_clicked();
    void on_EnCoursButton_clicked();
    void on_RafraichirButton_clicked();

private:
    Ui::VueClient *ui;
    EasyTicket& easyTicket;
    Client client;

    int page;
};


#endif //EASYTICKET_VUECLIENT_H
