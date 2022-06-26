#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>
#include <QJsonArray>

class product
{
public:
    product();
    static QJsonArray getAllProduct();
    static qint64 getProductCount();
    static QJsonArray getAvailableProduct();
    static QJsonObject getDetail(QString productName);
    static qint64 getPrice(QString productName);
    static qint64 getAllAvailableProduct(QString productName);
    static bool updateAfterBuy(QString productName , qint64 count);

};

#endif // PRODUCT_H
