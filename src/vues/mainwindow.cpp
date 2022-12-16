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
    if(!easyTicket.openDB())
    {
        QMessageBox::information(this, "Connection", "Error");
        return;
    }

    QMessageBox::information(this, "Connection", "Connected");
    
    easyTicket.pushWindow(new VueAdmin(easyTicket));
    easyTicket.start();
}

void MainWindow::on_inscriptionButton_clicked()
{
    //stateManager.push(new InscriptionWindow(*this));
}