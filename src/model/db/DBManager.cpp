#include "DBManager.h"

#include "../ticket/Ticket.h"

DBManager::DBManager() : dbEasyTicket(QSqlDatabase::addDatabase("QMYSQL"))
{

}

bool DBManager::open()
{
   QDir directoryPath;
   QString path = directoryPath.currentPath() + "/EasyTicket.db";

   this->dbEasyTicket.setDatabaseName(path);
   this->dbEasyTicket.open();

   return dbEasyTicket.isOpen();
}

void createIfNotExistsDataBase()
{
   this->query.exec("CREATE TABLE IF NOT EXISTS Category (cat_id INT AUTO_INCREMENT, cat_name VARCHAR(25) NOT NULL UNIQUE, PRIMARY KEY (cat_id))");

   this->query.exec("CREATE TABLE IF NOT EXISTS Message (message_id INT AUTO_INCREMENT, message_text VARCHAR(200) NOT NULL, message_date DATE DEFAULT CURRENT_DATE, Tiicket_num INT NOT NULL, PRIMARY KEY (message_id), FOREIGN KEY (ticket_num)  REFERENCES Ticket(ticket_num) ON DELETE CASCADE)");

   this->query.exec("CREATE TABLE IF NOT EXISTS Ticket (ticket_num INT AUTO_INCREMENT, ticket_date Date NOT NULL DEFAULT CURRENT_DATE, user_id INT NOT NULL, cat_id INT NOT NULL, PRIMARY KEY (ticket_num), FOREIGN KEY (user_id)  REFERENCES User(user_id) ON DELETE CASCADE, FOREIGN KEY (cat_id)  REFERENCES Category(cat_id) ON DELETE CASCADE)");

   this->query.exec("CREATE TABLE IF NOT EXISTS User (user_id  INT AUTO_INCREMENT, user_email VARCHAR(200) NOT NULL, user_name VARCHAR(200) NOT NULL, user_level INT NOT NULL DEFAULT 0, PRIMARY KEY (user_id))");

   this->query.exec("SELECT * FROM Category;");

   if(!this->query.next())
   {
     // qDebug() << "Pas encore créée";
      this->query.exec("INSERT INTO Category(cat_name) VALUES('Création');");
      this->query.exec("INSERT INTO Category(cat_name) VALUES('Visualisation');");
      this->query.exec("INSERT INTO Category(cat_name) VALUES('Windows');");
      this->query.exec("INSERT INTO Category(cat_name) VALUES('Réclamation');");

      this->query.exec("INSERT INTO User(user_email, user_name, user_level) VALUES('admin@admin.fr', 'LeBigBoss', 2);");
      this->query.exec("INSERT INTO User(user_email, user_name, user_level) VALUES('inge@inge.fr', 'LeBoss', 1);");
      this->query.exec("INSERT INTO User(user_email, user_name, user_level) VALUES('tech@tech.fr', 'LApprenti', 1);");
      this->query.exec("INSERT INTO User(user_email, user_name, user_level) VALUES('client@client.fr', 'LeRandom', 0);");
   }
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

std::vector<QString> DBManager::requestTicketsSummary(const int pageNum, const Filters& filters)
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
