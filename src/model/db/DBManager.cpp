#include "DBManager.h"

#include <QFileInfo>
#include <iostream>

#include "../ticket/Ticket.h"

DBManager::DBManager() : dbEasyTicket(QSqlDatabase::addDatabase("QSQLITE"))
{

}

bool DBManager::open()
{
    QDir directoryPath;
    QString path = directoryPath.currentPath() + "/EasyTicket.db";

    dbEasyTicket.setDatabaseName(path);

    QFileInfo check_file(path);
    bool fillFile = !(check_file.exists() && check_file.isFile());

    if(!dbEasyTicket.open()) return false;

    if(fillFile) createIfNotExistsDataBase();

    return true;
}

std::pair<int, int> DBManager::connection(const QString usermail, const QString password)
{
  query.exec("SELECT user_level, user_id FROM User WHERE lower(user_email) like '" + usermail.toLower() + "'and user_password like '" + password + "';");
  if(!query.next()) return {-1, -1};
  return {query.value(0).toInt(), query.value(1).toInt()};
}

bool DBManager::isOpen() const
{
    return dbEasyTicket.isOpen();
}

void DBManager::createIfNotExistsDataBase()
{
    query.exec("CREATE TABLE IF NOT EXISTS Category (cat_id INT, cat_name VARCHAR(25) NOT NULL UNIQUE, PRIMARY KEY (cat_id));");

    query.exec("CREATE TABLE IF NOT EXISTS Message (message_text VARCHAR(200) NOT NULL, message_date DATE DEFAULT CURRENT_DATE, ticket_num INT NOT NULL, FOREIGN KEY (ticket_num)  REFERENCES Ticket(ticket_num) ON DELETE CASCADE);");

    query.exec("CREATE TABLE IF NOT EXISTS Ticket (ticket_num INT, ticket_title VARCHAR(50) NOT NULL, ticket_date_post Date DEFAULT CURRENT_DATE, ticket_date_end Date DEFAULT NULL, user_id INT, cat_id INT NOT NULL, PRIMARY KEY (ticket_num), FOREIGN KEY (user_id)  REFERENCES User(user_id) ON DELETE CASCADE, FOREIGN KEY (cat_id)  REFERENCES Category(cat_id) ON DELETE CASCADE);");

    query.exec("CREATE TABLE IF NOT EXISTS User (user_id  INT, user_email VARCHAR(200) NOT NULL, user_password VARCHAR(200) NOT NULL, user_name VARCHAR(200) NOT NULL, user_surname VARCHAR(200) NOT NULL, user_level INT NOT NULL DEFAULT 0, PRIMARY KEY (user_id));");

    query.exec("SELECT * FROM Category;");

    if(!query.next())
    {
      // qDebug() << "Pas encore créée";

        query.exec("INSERT INTO Category(cat_id, cat_name) VALUES(0, 'ALL');");
        query.exec("INSERT INTO Category(cat_id, cat_name) VALUES(1, 'CREATION');");
        query.exec("INSERT INTO Category(cat_id, cat_name) VALUES(2, 'VISUALISATION');");
        query.exec("INSERT INTO Category(cat_id, cat_name) VALUES(3, 'WINDOWS');");
        query.exec("INSERT INTO Category(cat_id, cat_name) VALUES(4, 'RECLAMATION');");

        query.exec("INSERT INTO User(user_id, user_email, user_password, user_name, user_surname, user_level) VALUES(1, 'admin@admin.fr', 'admin', 'Henri', 'LeBigBoss', 3);");
        query.exec("INSERT INTO User(user_id, user_email, user_password, user_name, user_surname, user_level) VALUES(2, 'inge@inge.fr', 'inge', 'Harry', 'LeBoss', 2);");
        query.exec("INSERT INTO User(user_id, user_email, user_password, user_name, user_surname, user_level) VALUES(3, 'tech@tech.fr', 'tech', 'Harty', 'LApprenti', 1);");
        query.exec("INSERT INTO User(user_id, user_email, user_password, user_name, user_surname, user_level) VALUES(4, 'client@client.fr', 'client', 'Hugo', 'LeRandom', 0);");
    }
}

void DBManager::close()
{
    dbEasyTicket.close();
}

int DBManager::requestPostTicket(const Category category, const QString message, const QString title)
{
  ++ticketId;
  query.exec("INSERT INTO Ticket(ticket_num, ticket_title, cat_id) VALUES(" + QString::number(ticketId) + ", '" + title + "', " + QString::number(category) + ");");
  query.exec("INSERT INTO Message(message_text, ticket_num) VALUES('" + message + "', " + QString::number(ticketId) + ");");
  return ticketId;
}

QString DBManager::requestMessage(const Ticket& ticket)
{
  query.exec("SELECT message_text FROM Message WHERE ticket_num = " + QString::number(ticket.getTicketId()) + ";");
  if(!query.next()) return "";
  return query.value(0).toString();
}

void DBManager::requestPrendreTicket(const User& user, const Ticket& ticket)
{
  query.exec("UPDATE Ticket SET user_id = " + QString::number(user.getUserId()) + "WHERE ticket_num = " + QString::number(ticket.getTicketId()) +";");
}

void DBManager::requestTransfertTicket(const User& user, const Ticket& ticket)
{
  query.exec("UPDATE Ticket SET user_id = " + QString::number(user.getUserId()) + "WHERE ticket_num = " + QString::number(ticket.getTicketId()) +";");
}

QStringList DBManager::requestTicketsSummary(const int pageNum, const Filters& filters)
{
    //Make request

    return {};
}

void DBManager::requestChangeCategory(const Ticket& ticket, const Category category)
{
  query.exec("UPDATE Ticket SET car_id = " + QString::number(category) + "WHERE ticket_num = " + QString::number(ticket.getTicketId()) + ";");
}

void DBManager::requestSendMessage(const Ticket& ticket, const QString& message)
{
  query.exec("INSERT INTO Message(message_text, ticket_num) VALUES('" + message + "', " + QString::number(ticket.getTicketId()) + ");");
}

QStringList getCategories()
{
  return {};
}

DBManager::~DBManager()
{
    close();
}
