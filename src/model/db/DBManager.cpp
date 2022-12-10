#include "DBManager.h"

#include "../ticket/Ticket.h"

DBManager::DBManager() : dbEasyTicket(QSqlDatabase::addDatabase("QMYSQL"))
{

}

void DBManager::open(const QString& user, const QString& password)
{
    dbEasyTicket.setHostName("127.0.0.1");
    dbEasyTicket.setDatabaseName("EasyTicket");
    dbEasyTicket.setUserName(user);
    dbEasyTicket.setPassword(password);
}

bool DBManager::isOpen() const
{
    return dbEasyTicket.isOpen();
}

void DBManager::close()
{
    dbEasyTicket.close();
}

void DBManager::requestPostTicket(const Category category, const QString message)
{
    //Make request
}

void DBManager::requestTakeTicket(const Ticket& ticket)
{
    //Make request
}

QString DBManager::requestMessage(const Ticket& ticket)
{    
    //Make request

    return "";
}

void DBManager::requestPrendreTicket(const User& user, const Ticket& ticket)
{
    //Make request
}

void DBManager::requestTransfertTicket(const User& user, const Ticket& ticket)
{
    //Make request
}

std::vector<QString> DBManager::requestTicketsSummary(const int pageNum, const QString& filter)
{
    //Make request

    return {};
}

void DBManager::requestChangeCategory(const Ticket& ticket, const Category category)
{
    //Make request
}

void DBManager::requestSendMessage(const Ticket& ticket, const QString& message)
{
    //Make request
}

DBManager::~DBManager()
{
    close();
}
