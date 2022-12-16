#ifndef DBMANAGER_H
#define DBMANAGER_H

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

    	User getUserInfo(const int userId);
		int requestPostTicket(const Category category, const QString message, const QString title);
		QString requestMessage(const Ticket& ticket);
		void requestPrendreTicket(const User& user, const Ticket& ticket);
		void requestTransfertTicket(const User& user, const Ticket& ticket);
		QStringList requestTicketsSummary(const int pageNum, const Filters& filters);
		void requestChangeCategory(const Ticket& ticket, const Category category);
		void requestSendMessage(const Ticket& ticket, const QString& message);
		QStringList getCategories();

		~DBManager();
>>>>>>> 47c8c446576152dcd03caa041a0efb3f4c45a330
};

#endif /*DBMANAGER_H*/
