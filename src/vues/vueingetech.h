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

protected slots:
    void affichageTickets();
    void on_OuvrirButton_clicked();
    void on_PrendreButton_clicked();
    void on_ChangeCatButton_clicked();
    void on_TransfererButton_clicked();
    void on_ATraiterButton_clicked();
    void on_ClosButton_clicked();
    void on_EnCoursButton_clicked();
protected:
    Ui::VueIngeTech *ui;
    EasyTicket& easyTicket;
};


#endif //EASYTICKET_VUEINGETECH_H
