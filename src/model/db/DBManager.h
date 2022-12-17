#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <memory>

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QListWidget>

#include "../ticket/Category.h"

class EasyTicket;
class Filters;

enum
{
	CLIENT,
	TECH,
	INGE,
	ADMIN
};

class Ticket;
class User;

class DBManager
{
	private:
		EasyTicket& easyTicket;
    int ticketId = -1;
		QSqlDatabase dbEasyTicket;

	public:
		DBManager(EasyTicket& easyTicket);
		QSqlQuery query;

		bool open();
		bool isOpen() const;
		void createIfNotExistsDataBase();
		std::pair<int, int> connection(const QString usermail, const QString password);
		void close();

    	std::unique_ptr<User> getUserInfo(const int userId);
		std::pair<int, QString> requestPostTicket(const Category category, const QString message, const QString title, const int userId);
		QString requestMessage(const Ticket& ticket);
		void requestPrendreTicket(const User& user, const Ticket& ticket);
		void requestTransfertTicket(const User& user, const Ticket& ticket);
		QStringList requestTicketsSummary(const int pageNum, const Filters& filters);
		void requestChangeCategory(const Ticket& ticket, const Category category);
		void requestSendMessage(const Ticket& ticket, const QString& message);
		QStringList getCategories();
		QStringList getEmployees();
		std::vector<Ticket> getTickets();

		~DBManager();
};

#endif /*DBMANAGER_H*/
