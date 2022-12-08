#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

#include "../Date.h"

class Message
{
    private:
        const Date date;
        std::string message;
    public:
        Message();
        ~Message();
};

#endif /*MESSAGE_H*/