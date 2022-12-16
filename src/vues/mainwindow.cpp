#include "mainwindow.h"

#include "ui_mainwindow.h"

#include <QMessageBox>
#include <iostream>

MainWindow::MainWindow(EasyTicket& easyTicket, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , easyTicket(easyTicket)
{
    ui->setupUi(this);

    //std::cout << ui->graphicsView->isVisible() << std::endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_connexionButton_clicked()
{
    std::cout << "OK" << std::endl;

    easyTicket.openDB();
    if(easyTicket.isOpenDB() || true)
    {
        QMessageBox::information(this, "Connection", "Connected");
        
        easyTicket.pushWindow(new VueAdmin(easyTicket));
        easyTicket.start();
    }
    else
    {
        QMessageBox::information(this, "Connection", "Error");
    }
}

void MainWindow::on_inscriptionButton_clicked()
{
    //stateManager.push(new InscriptionWindow(*this));
}