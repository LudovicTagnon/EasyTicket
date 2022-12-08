#include "DBManager.h"

DBManager::DBManager() : dbEasyTicket(QSqlDatabase::addDatabase("QMYSQL"))
{

}

void DBManager::open(const QString& user, const QString& password)
{
    this->dbEasyTicket.setHostName("127.0.0.1");
    this->dbEasyTicket.setDatabaseName("EasyTicket");
    this->dbEasyTicket.setUserName(user);
    this->dbEasyTicket.setPassword(password);
}

bool DBManager::isOpen() const
{
    return dbEasyTicket.isOpen();
}

//TODO: Determine all command type

void DBManager::close()
{
    dbEasyTicket.close();
}

DBManager::~DBManager()
{
    close();
}
