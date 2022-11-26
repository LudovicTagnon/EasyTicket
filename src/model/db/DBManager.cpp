#include "DBManager.h"

DBManager::DBManager()
{
    
}

void DBManager::open(const std::string& user, const std::string& password)
{

}

//TODO: Determine all command type

void DBManager::close()
{

}

DBManager::~DBManager()
{
    close();
}