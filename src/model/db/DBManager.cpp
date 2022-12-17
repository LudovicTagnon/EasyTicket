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

/**
 * @brief Opens a connection to the EasyTicket database.
 *
 * @return `true` if the connection was successfully established, `false` otherwise.
 *
 * This function opens a connection to the EasyTicket database using the `QSqlDatabase` class.
 * If the connection is successfully established, the function also checks if the database file exists and is a regular file.
 * If the database file does not exist or is not a regular file, the function calls `createIfNotExistsDataBase` to create it.
 */
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

/**
 * @brief Attempts to establish a connection to the database using the given email and password.
 *
 * @param usermail The email of the user trying to connect.
 * @param password The password of the user trying to connect.
 *
 * @return A pair of integers representing the user level and user ID.
 *
 * If the connection is successful, the function returns a pair of integers containing the user level and user ID of the user.
 * If the connection fails, the function returns a pair of -1.
 *
 * The connection is established by executing a SQL query on the `User` table using the `QSqlQuery` class.
 */
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

/**
 * @brief Creates the EasyTicket database if it does not exist.
 *
 * This function creates the EasyTicket database using the `QSqlQuery` class.
 * It creates four tables: `Category`, `Message`, `Ticket`, and `User`.
 * It also inserts some default values into the `Category` and `User` tables.
 *
 * The function checks if the `Category` table already exists by executing a `SELECT` query on it.
 * If the table does not exist, the function creates the tables and inserts the default values.
 */
void DBManager::createIfNotExistsDataBase()
{
    query.exec("CREATE TABLE IF NOT EXISTS Category (cat_id INT, cat_name STRING NOT NULL UNIQUE, PRIMARY KEY (cat_id));");

    query.exec("CREATE TABLE IF NOT EXISTS Message (message_text STRING NOT NULL, message_date DATE DEFAULT CURRENT_DATE, ticket_num INT NOT NULL, FOREIGN KEY (ticket_num)  REFERENCES Ticket(ticket_num) ON DELETE CASCADE);");

    query.exec("CREATE TABLE IF NOT EXISTS Ticket (ticket_num INT, ticket_title STRING NOT NULL, ticket_date_post Date DEFAULT CURRENT_DATE, ticket_date_end Date DEFAULT NULL, user_id INT NOT NULL, cat_id INT NOT NULL, status INT DEFAULT 0, employee_on_it_id INT, PRIMARY KEY (ticket_num), FOREIGN KEY (user_id) REFERENCES User(user_id) ON DELETE CASCADE, FOREIGN KEY (employee_on_it_id) REFERENCES User(user_id) ON DELETE CASCADE, FOREIGN KEY (cat_id)  REFERENCES Category(cat_id) ON DELETE CASCADE);");

    query.exec("CREATE TABLE IF NOT EXISTS User (user_id  INT, user_email STRING NOT NULL, user_password STRING NOT NULL, user_name STRING NOT NULL, user_surname STRING NOT NULL, user_level INT NOT NULL DEFAULT 0, PRIMARY KEY (user_id));");

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

/**
 * @brief Retrieves information about a user from the database.
 *
 * @param userId The ID of the user to retrieve information about.
 *
 * @return A `std::unique_ptr` to a `User` object containing the information about the user.
 *
 * This function retrieves the name, surname, and email of the user with the given ID from the `User` table in the database.
 * It then constructs a `User` object with this information and returns a `std::unique_ptr` to it.
 * If no user with the given ID exists in the database, the function returns a `nullptr`.
 */
std::unique_ptr<User> DBManager::getUserInfo(const int userId)
{
    query.exec("SELECT user_name, user_surname, user_email FROM User WHERE user_id = " + QString::number(userId) + ";");
    if(!query.next()) return nullptr;
    return std::unique_ptr<User>{new User(userId, query.value(0).toString(), query.value(1).toString(), query.value(2).toString(), easyTicket)};
}

/**
 * @brief Posts a new ticket to the database.
 *
 * @param category The category of the ticket.
 * @param message The message of the ticket.
 * @param title The title of the ticket.
 * @param userId The ID of the user posting the ticket.
 *
 * @return A pair of integers representing the ticket ID and the date the ticket was posted.
 *
 * This function inserts a new row into the `Ticket` table and a new row into the `Message` table in the database.
 * The function increments the ticket ID before inserting the new ticket.
 * The function also sets the `employee_on_it_id` field in the `Ticket` table to -1, indicating that no employee is currently assigned to the ticket.
 * If either of the insertions fails, the function returns a pair of -1.
 * Otherwise, the function returns a pair containing the ticket ID and the date the ticket was posted.
 */
std::pair<int, QString> DBManager::requestPostTicket(const Category category, const QString message, const QString title, const int userId)
{
  ++ticketId;

  char buff[20];
  std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  strftime(buff, 20, "%Y-%m-%d", localtime(&now));
  QString date(buff);

  if(!query.exec("INSERT INTO Ticket(ticket_num, ticket_title, user_id, cat_id, employee_on_it_id) VALUES(" + QString::number(ticketId) + ", '" + title + "', " + QString::number(userId) + ", " + QString::number(category) + ", -1);"))
    return {-1, ""};
  if(!query.exec("INSERT INTO Message(message_date, message_text, ticket_num) VALUES('" + date + "', '" + message + "', " + QString::number(ticketId) + ");"))
    return {-1, ""};

  return {ticketId, date};
}

/**
 * @brief Retrieves the message of a ticket from the database.
 *
 * @param ticket The ticket to retrieve the message of.
 *
 * @return The message of the ticket as a `QString`.
 *
 * This function retrieves the message of the given ticket from the `Message` table in the database.
 * It does this by executing a `SELECT` query on the `message_text` field using the ticket ID of the given ticket.
 * If the ticket does not exist in the database, the function returns an empty string.
 */
QString DBManager::requestMessage(const Ticket& ticket)
{
  query.exec("SELECT message_text FROM Message WHERE ticket_num = " + QString::number(ticket.getTicketId()) + ";");
  if(!query.next()) return "";
  return query.value(0).toString();
}

/**
 * @brief Assigns a ticket to an employee in the database.
 *
 * @param user The employee who will be assigned the ticket.
 * @param ticket The ticket to be assigned.
 *
 * This function updates the `employee_on_it` field in the `Ticket` table in the database to the ID of the given employee.
 * It does this by executing an `UPDATE` query using the ticket ID of the given ticket.
 */
void DBManager::requestPrendreTicket(const User& user, const Ticket& ticket)
{
  query.exec("UPDATE Ticket SET employee_on_it = " + QString::number(user.getUserID()) + "WHERE ticket_num = " + QString::number(ticket.getTicketId()) +";");
}

/**
 * @brief Transfer a ticket from one user to another
 * @param user The user to transfer the ticket to
 * @param ticket The ticket to be transferred
 *
 * This function updates the database to reflect the transfer of the ticket from one user to another.
 */
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

/**
 * @brief Retrieves a list of categories from the database.
 *
 * @return A `QStringList` containing the names of the categories.
 *
 * This function retrieves the names of all categories from the `Category` table in the database and stores them in a `QStringList`.
 * It does this by executing a `SELECT` query on the `cat_name` field and iterating through the query results using a `while` loop.
 * The function returns the `QStringList` containing the names of the categories.
 */
QStringList DBManager::getCategories()
{
  QStringList listCategory;

  query.exec("SELECT cat_name FROM Category ORDER BY cat_id;");
  while(query.next())
  {
    listCategory.append(query.value(0).toString());
  }
  return listCategory;
}

/**
 * @brief Get a list of all employees
 * @return A list of strings containing the names of all employees
 *
 * This function retrieves the names of all employees from the database and returns them as a list of strings.
 * Each string in the list is formatted as "first_name, last_name".
 */
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

/**
 * @brief Retrieves a list of tickets from the database.
 *
 * @return A `std::vector` of `Ticket` objects containing the tickets.
 *
 * This function retrieves the tickets from the `Ticket` table in the database and stores them in a `std::vector`.
 * It does this by executing a `SELECT` query on the `ticket_num`, `ticket_title`, `cat_id`, and `employee_on_it_id` fields and iterating through the query results using a `while` loop.
 * For each ticket, the function retrieves the messages associated with the ticket from the `Message` table and adds them to the `Ticket` object using the `addMessage` function.
 * The function returns the `std::vector` containing the `Ticket` objects.
 */
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

bool DBManager::setEmployeeOntIt(const Ticket& ticket, const NonAdmin& nonAdmin)
{
  query.exec("SELECT cat_id FROM Ticket WHERE ticket_num = " + QString::number(ticket.getTicketId()) + " and user_id = " + QString::number(nonAdmin.getUserID()) + ";");
  if(!query.next()) return false;
  return true;
}

DBManager::~DBManager()
{
    close();
}
