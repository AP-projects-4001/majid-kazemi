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

};

#endif // PRODUCT_H
