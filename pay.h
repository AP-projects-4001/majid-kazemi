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
    static QJsonArray getPayForCustomer(QString customer);
    static qint64 getTotoalPayForCustomer(QString customer);
};

#endif // PAY_H
