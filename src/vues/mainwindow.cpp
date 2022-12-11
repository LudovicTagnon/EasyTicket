#include "mainwindow.h"

#include "ui_mainwindow.h"

#include <QMessageBox>

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
    easyTicket.openDB("root", "");
    if(easyTicket.isOpenDB())
    {
        QMessageBox::information(this, "Connection", "Connected");
        //easyTicket.closeDB();
        easyTicket.pushWindow(new VueClient(easyTicket));
        easyTicket.start();
    }
    else
    {
        QMessageBox::information(this, "Connection", "Error");

        easyTicket.pushWindow(new VueIngeTech(easyTicket));
        easyTicket.start();
    }
}

void MainWindow::on_inscriptionButton_clicked()
{
    //stateManager.push(new MainWindow(*this));
}