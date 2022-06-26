#ifndef BUY_H
#define BUY_H
#include <QString>
#include <QJsonArray>
class buy
{
public:
    buy();
    static QJsonArray getAllBuy();
    static qint64 getSumOfBuy();
    static bool checkout(qint64 productCount , qint64 productPrice);

private:
    static int getLastId();
};

#endif // BUY_H
