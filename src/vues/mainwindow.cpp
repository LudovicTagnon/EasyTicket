#include "mainwindow.h"

#include "ui_mainwindow.h"
#include "vueinscription.h"

#include <QMessageBox>
#include <iostream>

MainWindow::MainWindow(EasyTicket& easyTicket, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , easyTicket(easyTicket)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_connexionButton_clicked()
{
    if(!easyTicket.openDB())
    {
        QMessageBox::information(this, "Connection", "Error");
        return;
    }

    std::pair<int, int> ret = easyTicket.connectionDB(ui->AdresseMail->text(), ui->MDP->text());

    easyTicket.refreshTickets();

    if(ret.first == -1)
    {
        QMessageBox::information(this, "Connection", "Mauvais Login ou MDP");
        return;
    }

    std::unique_ptr<User> user = easyTicket.getUserInfo(ret.second);
    if(!user)
    {
        QMessageBox::information(this, "Connection", "Erreur lors de la connexion");
        return; 
    }

    switch (ret.first) {
        case CLIENT:
            easyTicket.pushWindow(new VueClient(Client(user.get(), easyTicket), easyTicket));
            break;
        case TECH:
            easyTicket.pushWindow(new VueTech(Technicien(user.get(), easyTicket, {ALL}), easyTicket));
            break;
        case INGE:
            easyTicket.pushWindow(new VueInge(Ingenieur(user.get(), easyTicket), easyTicket));
            break;
        case ADMIN:
            easyTicket.pushWindow(new VueAdmin(Admin(user.get(), easyTicket), easyTicket));
            break;
    }
}

void MainWindow::on_inscriptionButton_clicked()
{
    easyTicket.pushWindow(new VueInscription(easyTicket));
}
