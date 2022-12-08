#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../model/EasyTicket.h"

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

private:
    Ui::MainWindow *ui;
    EasyTicket& easyTicket;
};

#endif // MAINWINDOW_H
