#ifndef VALIDATOR_H
#define VALIDATOR_H
#include <QString>

class validator
{
public:
    validator();
    static bool userValidator(QString name,QString username,QString password,QString phone,QString address);
};

#endif // VALIDATOR_H
