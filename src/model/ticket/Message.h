#ifndef MESSAGE_H
#define MESSAGE_H

#include <QtCore/QString>
#include <ctime>

class Message
{
    private:
        const std::time_t date;
        QString message;
    public:
        Message();
        ~Message();
};

#endif /*MESSAGE_H*/