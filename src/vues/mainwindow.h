#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../model/EasyTicket.h"
#include "../model/utilisateur/Client.h"
#include "../model/utilisateur/Technicien.h"
#include "../model/utilisateur/Ingenieur.h"
#include "../model/utilisateur/Admin.h"
#include "vueclient.h"
#include "vueinge.h"
#include "vuetech.h"
#include "vueadmin.h"

#define q2c(string) string.toStdString()

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(EasyTicket& easyTicket, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_connexionButton_clicked();
    void on_inscriptionButton_clicked();

private:
    Ui::MainWindow *ui;
    EasyTicket& easyTicket;
};

#endif // MAINWINDOW_H
