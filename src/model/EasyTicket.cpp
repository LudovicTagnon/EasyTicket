#include "EasyTicket.h"

#include "../vues/mainwindow.h"

EasyTicket::EasyTicket()
{
    stateManager.push(new MainWindow(*this));
}

void EasyTicket::openDB(const QString username, const QString password)
{
    db.open(username, password);
}

bool EasyTicket::isOpenDB() const
{
    return db.isOpen();
}

void EasyTicket::closeDB()
{
    db.close();
}

void EasyTicket::start()
{
    stateManager.top()->show();
}

EasyTicket::~EasyTicket()
{

}