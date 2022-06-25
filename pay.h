#ifndef PAY_H
#define PAY_H
#include <QString>
#include <QJsonArray>

class pay
{
public:
    pay();
    static QJsonArray getAllPay();
    static qint64 getSumOfPay();
};

#endif // PAY_H
