//
// Created by kudovic on 11/12/22.
//

#ifndef EASYTICKET_VUECLIENT_H
#define EASYTICKET_VUECLIENT_H

#include <QWidget>
#include "../model/EasyTicket.h"


QT_BEGIN_NAMESPACE
namespace Ui { class VueClient; }
QT_END_NAMESPACE

class VueClient : public QWidget {
Q_OBJECT

    VueClient(QWidget *parent);


public:
    explicit VueClient(EasyTicket& easyTicket, QWidget *parent = nullptr);

    ~VueClient() override;

private:
    Ui::VueClient *ui;
    EasyTicket& easyTicket;

};


#endif //EASYTICKET_VUECLIENT_H
