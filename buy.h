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
};

#endif // BUY_H
