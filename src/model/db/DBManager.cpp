#include "DBManager.h"

#include "../ticket/Ticket.h"

DBManager::DBManager() : dbEasyTicket(QSqlDatabase::addDatabase("QSQLITE"))
{

}

void DBManager::open()
{
    QDir directoryPath;
    QString path = directoryPath.currentPath() + "/EasyTicket.db";

    dbEasyTicket.setDatabaseName(path);
    dbEasyTicket.open()
    if(!dbEasyTicket.isOpen())
    {
        exit(EXIT_FAILURE);
    }
}

int DBManager::connection(const QString usermail, const QString password)
{
  query.exec("SELECT user_level FROM User WHERE lower(user_email) like '" + usermail.toLower() + "'and user_password like '" + password + "';");
  if(!query.next()) return -1;
  else return query.values(0).toInt();
}

bool DBManager::isOpen() const
{
    return dbEasyTicket.isOpen();
}

void DBManager::createIfNotExistsDataBase()
{
    query.exec("CREATE TABLE IF NOT EXISTS Category (cat_id INT AUTO_INCREMENT, cat_name VARCHAR(25) NOT NULL UNIQUE, PRIMARY KEY (cat_id));");

    query.exec("CREATE TABLE IF NOT EXISTS Message (message_id INT AUTO_INCREMENT, message_text VARCHAR(200) NOT NULL, message_date DATE DEFAULT CURRENT_DATE, Tiicket_num INT NOT NULL, PRIMARY KEY (message_id), FOREIGN KEY (ticket_num)  REFERENCES Ticket(ticket_num) ON DELETE CASCADE);");

    query.exec("CREATE TABLE IF NOT EXISTS Ticket (ticket_num INT AUTO_INCREMENT, ticket_date Date NOT NULL DEFAULT CURRENT_DATE, user_id INT NOT NULL, cat_id INT NOT NULL, PRIMARY KEY (ticket_num), FOREIGN KEY (user_id)  REFERENCES User(user_id) ON DELETE CASCADE, FOREIGN KEY (cat_id)  REFERENCES Category(cat_id) ON DELETE CASCADE);");

    query.exec("CREATE TABLE IF NOT EXISTS User (user_id  INT AUTO_INCREMENT, user_email VARCHAR(200) NOT NULL, user_password VARCHAR(200) NOT NULL, user_name VARCHAR(200) NOT NULL, user_surname VARCHAR(200) NOT NULL, user_level INT NOT NULL DEFAULT 0, PRIMARY KEY (user_id));");

    query.exec("SELECT * FROM Category;");

    if(!query.next())
    {
      // qDebug() << "Pas encore créée";

        query.exec("INSERT INTO Category(cat_name) VALUES('ALL');");
        query.exec("INSERT INTO Category(cat_name) VALUES('CREATION');");
        query.exec("INSERT INTO Category(cat_name) VALUES('VISUALISATION');");
        query.exec("INSERT INTO Category(cat_name) VALUES('WINDOWS');");
        query.exec("INSERT INTO Category(cat_name) VALUES('RECLAMATION');");

        query.exec("INSERT INTO User(user_email, user_password, user_name, user_surname, user_level) VALUES('admin@admin.fr', 'admin', 'Henri', 'LeBigBoss', 2);");
        query.exec("INSERT INTO User(user_email, user_password, user_name, user_surname, user_level) VALUES('inge@inge.fr', 'inge', 'Harry', 'LeBoss', 1);");
        query.exec("INSERT INTO User(user_email, user_password, user_name, user_surname, user_level) VALUES('tech@tech.fr', 'tech', 'Harty', 'LApprenti', 1);");
        query.exec("INSERT INTO User(user_email, user_password, user_name, user_surname, user_level) VALUES('client@client.fr', 'client', 'Hugo', 'LeRandom', 0);");
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

QStringList DBManager::requestTicketsSummary(const int pageNum, const Filters& filters)
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
