//
// Created by kudovic on 12/12/22.
//

#ifndef EASYTICKET_VUECHANGECATEGORIE_H
#define EASYTICKET_VUECHANGECATEGORIE_H

#include <QWidget>
#include "../model/EasyTicket.h"


QT_BEGIN_NAMESPACE
namespace Ui { class VueChangeCategorie; }
QT_END_NAMESPACE

class VueChangeCategorie : public QWidget {
Q_OBJECT

public:
    explicit VueChangeCategorie(EasyTicket& easyTicket, QWidget *parent = nullptr);

    ~VueChangeCategorie() override;

private:
    Ui::VueChangeCategorie *ui;
    EasyTicket& easyTicket;
};


#endif //EASYTICKET_VUECHANGECATEGORIE_H
