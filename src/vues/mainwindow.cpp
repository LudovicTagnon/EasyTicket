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

    switch (easyTicket.connectionDB(ui->AdresseMail->text(), ui->MDP->text())) {
        case -1:
            QMessageBox::information(this, "Connection", "Mauvais Login ou MDP");
            break;
        case CLIENT:
            easyTicket.pushWindow(new VueClient(easyTicket));
            break;
        case TECH:
            //Init tech
            easyTicket.pushWindow(new VueIngeTech(easyTicket));
            break;
        case INGE:
            //Init inge
            easyTicket.pushWindow(new VueIngeTech(easyTicket));
            break;
        case ADMIN:
            easyTicket.pushWindow(new VueAdmin(easyTicket));
            break;
    }
}

void MainWindow::on_inscriptionButton_clicked()
{
    easyTicket.pushWindow(new VueInscription(easyTicket));
}