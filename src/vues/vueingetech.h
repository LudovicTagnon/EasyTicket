//
// Created by kudovic on 11/12/22.
//

#ifndef EASYTICKET_VUEINGETECH_H
#define EASYTICKET_VUEINGETECH_H

#include <QWidget>
#include "../model/EasyTicket.h"
#include "vueticket.h"
#include "vuepriseticket.h"
#include "vuechangecategorie.h"
#include "vuetransferer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class VueIngeTech; }
QT_END_NAMESPACE

class VueIngeTech : public QWidget {
Q_OBJECT

public:
    explicit VueIngeTech(EasyTicket& easyTicket, QWidget *parent = nullptr);

    ~VueIngeTech() override;

private slots:
    void on_OuvrirButton_clicked();
    void on_PrendreButton_clicked();
    void on_ChangeCatButton_clicked();
    void on_TransfererButton_clicked();

private:
    Ui::VueIngeTech *ui;
    EasyTicket& easyTicket;
};


#endif //EASYTICKET_VUEINGETECH_H
