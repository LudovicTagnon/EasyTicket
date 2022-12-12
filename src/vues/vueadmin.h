//
// Created by kudovic on 11/12/22.
//

#ifndef EASYTICKET_VUEADMIN_H
#define EASYTICKET_VUEADMIN_H

#include <QWidget>
#include "../model/EasyTicket.h"

QT_BEGIN_NAMESPACE
namespace Ui { class VueAdmin; }
QT_END_NAMESPACE

class VueAdmin : public QWidget {
Q_OBJECT

public:
    explicit VueAdmin(EasyTicket& easyTicket, QWidget *parent = nullptr);

    ~VueAdmin() override;

private:
    Ui::VueAdmin *ui;
    EasyTicket& easyTicket;
};


#endif //EASYTICKET_VUEADMIN_H
