#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_connexionButton_clicked()
{
    findChild<QPushButton*>("connexionButton")->setText("Bonjour le monde !");

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("qt5test");
    db.setUserName("root");
    db.setPassword("");
    if(db.open())
    {
        QMessageBox::information(this, "Connection", "Connected");
        db.close();
    }
    else
    {
        QMessageBox::information(this, "Connection", "Error");
    }

    std::cout << std::flush;
}
