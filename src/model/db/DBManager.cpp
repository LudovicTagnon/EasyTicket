#include "DBManager.h"

#include <QFileInfo>
#include <iostream>

#include "../utilisateur/User.h"
#include "../utilisateur/NonAdmin.h"
#include "../ticket/Ticket.h"
#include "../ticket/Message.h"

DBManager::DBManager(EasyTicket& easyTicket) : easyTicket(easyTicket), dbEasyTicket(QSqlDatabase::addDatabase("QSQLITE"))
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

    query.exec("CREATE TABLE IF NOT EXISTS Ticket (ticket_num INT, ticket_title VARCHAR(50) NOT NULL, ticket_date_post Date DEFAULT CURRENT_DATE, ticket_date_end Date DEFAULT NULL, user_id INT NOT NULL, cat_id INT NOT NULL, status INT DEFAULT 0, employee_on_it_id INT, PRIMARY KEY (ticket_num), FOREIGN KEY (user_id) REFERENCES User(user_id) ON DELETE CASCADE, FOREIGN KEY (employee_on_it_id) REFERENCES User(user_id) ON DELETE CASCADE, FOREIGN KEY (cat_id)  REFERENCES Category(cat_id) ON DELETE CASCADE);");

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
        query.exec("INSERT INTO Category(cat_id, cat_name) VALUES(5, 'OTHER');");


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

std::unique_ptr<User> DBManager::getUserInfo(const int userId)
{
    query.exec("SELECT user_name, user_surname, user_email FROM User WHERE user_id = " + QString::number(userId) + ";");
    if(!query.next()) return nullptr;
    return std::unique_ptr<User>{new User(userId, query.value(0).toString(), query.value(1).toString(), query.value(2).toString(), easyTicket)};
}

std::pair<int, QString> DBManager::requestPostTicket(const Category category, const QString message, const QString title, const int userId)
{
  ++ticketId;

  char buff[20];
  std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  strftime(buff, 20, "%Y-%m-%d", localtime(&now));
  QString date(buff);

  std::cout << "INSERT INTO Message(message_date, message_text, ticket_num) VALUES('" + date.toStdString() + ", " + message.toStdString() + "', " + QString::number(ticketId).toStdString() + ");" << std::endl;

  if(!query.exec("INSERT INTO Ticket(ticket_num, ticket_title, user_id, cat_id, employee_on_it_id) VALUES(" + QString::number(ticketId) + ", '" + title + "', " + QString::number(userId) + ", " + QString::number(category) + ", -1);"
                + "INSERT INTO Message(message_date, message_text, ticket_num) VALUES(" + date + ", " + message + ", " + QString::number(ticketId) + ");"))
    return {-1, ""};

  return {ticketId, date};
}

QString DBManager::requestMessage(const Ticket& ticket)
{
  query.exec("SELECT message_text FROM Message WHERE ticket_num = " + QString::number(ticket.getTicketId()) + ";");
  if(!query.next()) return "";
  return query.value(0).toString();
}

void DBManager::requestPrendreTicket(const User& user, const Ticket& ticket)
{
  query.exec("UPDATE Ticket SET employee_on_it = " + QString::number(user.getUserID()) + "WHERE ticket_num = " + QString::number(ticket.getTicketId()) +";");
}

void DBManager::requestTransfertTicket(const User& user, const Ticket& ticket)
{
  query.exec("UPDATE Ticket SET employee_on_it = " + QString::number(user.getUserID()) + "WHERE ticket_num = " + QString::number(ticket.getTicketId()) +";");
}

QStringList DBManager::requestTicketsSummary(const int pageNum, const Filters& filters)
{

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

QStringList DBManager::getCategories()
{
  QStringList listCategory;

  query.exec("SELECT cat_name FROM Category;");
  while(query.next())
  {
    listCategory.append(query.value(0).toString());
  }
  return listCategory;
}

QStringList DBManager::getEmployees()
{
  QStringList listEmployees;
  query.exec("SELECT user_name, user_surname FROM User WHERE user_level > 0;");

  while(query.next())
  {
    listEmployees.append(query.value(0).toString() + ", " + query.value(1).toString());
  }
    return listEmployees;
}

std::vector<Ticket> DBManager::getTickets() {
    std::vector<Ticket> Tickets;

    query.exec("SELECT ticket_num, ticket_title, cat_id, employee_on_it_id FROM Ticket;");

    while(query.next())
    {
      NonAdmin* employeeOnIt = nullptr;
      if(query.value(3).toInt() != -1)
      {
        employeeOnIt = std::unique_ptr<NonAdmin>{new NonAdmin(getUserInfo(query.value(3).toInt()).get(), easyTicket)}.get();
      }

      Ticket ticket = Ticket(query.value(0).toInt(), query.value(1).toString(), (Category) query.value(2).toInt(), employeeOnIt, Message(QString(""), QString("")));
      Tickets.push_back(ticket);

      QSqlQuery tmp;
      tmp.exec("SELECT message_text, message_date FROM Message where ticket_num=" + QString::number(query.value(0).toInt()) + ";");
      while(tmp.next())
        Tickets.back().addMessage(Message(tmp.value(0).toString(), tmp.value(1).toString()));
      //Tickets.back().getMessages().erase(Tickets.back().getMessages().begin());
    }

    return Tickets;
}

DBManager::~DBManager()
{
    close();
}
