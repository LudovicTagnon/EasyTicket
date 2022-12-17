#include <chrono>
#include "Message.h"

Message::Message(const QString& date, const QString& message)
 : date(date)
 , message(message)
{

}

const QString& Message::getMessage() const
{
    return message;
}

const QString& Message::getDate() const
{
    return date;
}


Message::~Message()
{
    
}