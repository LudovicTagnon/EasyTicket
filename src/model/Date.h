#ifndef DATE_H
#define DATE_H

#include <ctime>

class Date
{
    private:
        const std::time_t date;

    public:
        Date();
        ~Date();
};

#endif /*DATE_H*/