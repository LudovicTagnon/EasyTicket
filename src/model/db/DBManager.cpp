#include "DBManager.h"

DBManager::DBManager()
{
    this->dbEasyTicket = QSqlDatabase::addDatabase("QMYSQL");
}

void DBManager::open(const std::string& user, const std::string& password)
{
    this->dbEasyTicket.setHostName("127.0.0.1");
    this->dbEasyTicket.setDatabaseName("EasyTicket");
    this->dbEasyTicket.setUserName(user);
    this->dbEasyTicket.setPassword(password);
}

//TODO: Determine all command type

void DBManager::close()
{

}

DBManager::~DBManager()
{
    close();
}
