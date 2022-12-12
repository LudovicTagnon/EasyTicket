//
// Created by kudovic on 12/12/22.
//

#ifndef EASYTICKET_VUETRANSFERER_H
#define EASYTICKET_VUETRANSFERER_H

#include <QWidget>
#include "../model/EasyTicket.h"

QT_BEGIN_NAMESPACE
namespace Ui { class VueTransferer; }
QT_END_NAMESPACE

class VueTransferer : public QWidget {
Q_OBJECT

public:
    explicit VueTransferer(EasyTicket& easyTicket, QWidget *parent = nullptr);

    ~VueTransferer() override;

private:
    Ui::VueTransferer *ui;
    EasyTicket& easyTicket;
};


#endif //EASYTICKET_VUETRANSFERER_H
