#ifndef MESSAGE_H
#define MESSAGE_H

#include <QtCore/QString>
#include <ctime>

class Message
{
    private:
        const QString date;
        const QString message;
    public:
        Message(const QString& date, const QString& message);
        ~Message();

        const QString& getMessage() const;
        const QString& getDate() const;
};

#endif /*MESSAGE_H*/