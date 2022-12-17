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
    switch (ret.first) {
        case -1:
            QMessageBox::information(this, "Connection", "Mauvais Login ou MDP");
            break;
        case CLIENT:
            easyTicket.pushWindow(new VueClient(Client(easyTicket.getUserInfo(ret.second), easyTicket), easyTicket));
            break;
        case TECH:
            easyTicket.pushWindow(new VueTech(Technicien(easyTicket.getUserInfo(ret.second), easyTicket, {ALL}), easyTicket));
            break;
        case INGE:
            easyTicket.pushWindow(new VueInge(Ingenieur(easyTicket.getUserInfo(ret.second), easyTicket), easyTicket));
            break;
        case ADMIN:
            easyTicket.pushWindow(new VueAdmin(Admin(easyTicket.getUserInfo(ret.second), easyTicket), easyTicket));
            break;
    }
}

void MainWindow::on_inscriptionButton_clicked()
{
    easyTicket.pushWindow(new VueInscription(easyTicket));
}
