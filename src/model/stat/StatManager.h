#ifndef STATMANAGER_H
#define STATMANAGER_H

#include "../db/DBManager.h"

class StatManager
{
    private:
        const DBManager& dbManager;
    public:
        StatManager(const DBManager& dbManager);
        ~StatManager();
};

#endif /*STATMANAGER_H*/