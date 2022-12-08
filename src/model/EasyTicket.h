#ifndef EASYTICKET_H
#define EASYTICKET_H

#include "states/StateManager.h"
#include "db/DBManager.h"

class EasyTicket
{
    private:
        StateManager stateManager;
        DBManager db;
    public:
        EasyTicket();

        void openDB(const QString username, const QString password);
        bool isOpenDB() const;
        void closeDB();

        void start();

        ~EasyTicket();
};

#endif /*EASYTICKET_H*/