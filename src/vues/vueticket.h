//
// Created by kudovic on 12/12/22.
//

#ifndef EASYTICKET_VUETICKET_H
#define EASYTICKET_VUETICKET_H

#include <QWidget>
#include "../model/EasyTicket.h"

QT_BEGIN_NAMESPACE
namespace Ui { class VueTicket; }
QT_END_NAMESPACE

class VueTicket : public QWidget {
Q_OBJECT
    VueTicket(QWidget *parent);
public:
    explicit VueTicket(EasyTicket& easyTicket, QWidget *parent = nullptr);

    ~VueTicket() override;

private:
    Ui::VueTicket *ui;
    EasyTicket& easyTicket;
};


#endif //EASYTICKET_VUETICKET_H
