#include "Date.h"

Date::Date() : date(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()))
{

}

Date::~Date()
{

}
