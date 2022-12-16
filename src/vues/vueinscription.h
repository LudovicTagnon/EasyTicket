//
// Created by kudovic on 16/12/22.
//

#ifndef EASYTICKET_VUEINSCRIPTION_H
#define EASYTICKET_VUEINSCRIPTION_H

#include <QWidget>
#include "../model/EasyTicket.h"


QT_BEGIN_NAMESPACE
namespace Ui { class VueInscription; }
QT_END_NAMESPACE

class VueInscription : public QWidget {
Q_OBJECT

public:
    explicit VueInscription(EasyTicket& easyTicket, QWidget *parent = nullptr);

    ~VueInscription() override;

private slots:
    void on_ConfirmerButton_clicked();
    void on_RetourButton_clicked();
private:
    Ui::VueInscription *ui;
    EasyTicket& easyTicket;

};


#endif //EASYTICKET_VUEINSCRIPTION_H
