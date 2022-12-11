//
// Created by kudovic on 11/12/22.
//

#ifndef EASYTICKET_VUEADMIN_H
#define EASYTICKET_VUEADMIN_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class VueAdmin; }
QT_END_NAMESPACE

class VueAdmin : public QWidget {
Q_OBJECT

public:
    explicit VueAdmin(QWidget *parent = nullptr);

    ~VueAdmin() override;

private:
    Ui::VueAdmin *ui;
};


#endif //EASYTICKET_VUEADMIN_H
