//
// Created by kudovic on 12/12/22.
//

#ifndef EASYTICKET_VUEPRISETICKET_H
#define EASYTICKET_VUEPRISETICKET_H

#include <QWidget>
#include "../model/EasyTicket.h"


QT_BEGIN_NAMESPACE
namespace Ui { class VuePriseTicket; }
QT_END_NAMESPACE

class VuePriseTicket : public QWidget {
Q_OBJECT

public:
    explicit VuePriseTicket(EasyTicket& easyTicket, QWidget *parent = nullptr);

    ~VuePriseTicket() override;

private:
    Ui::VuePriseTicket *ui;
    EasyTicket& easyTicket;
};


#endif //EASYTICKET_VUEPRISETICKET_H
