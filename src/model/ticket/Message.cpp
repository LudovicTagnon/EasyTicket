#include "Message.h"

Message::Message() : date(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()))
{

}

Message::~Message()
{
    
}