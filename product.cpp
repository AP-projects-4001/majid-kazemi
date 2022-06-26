#include "product.h"
#include <QFile>
#include <QJsonDocument>
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include "user.h"

product::product()
{

}

QJsonArray product::getAllProduct()
{
    QFile f("product.json");
    f.open(QIODevice::ReadOnly);
    QByteArray data = f.readAll();
    QJsonDocument json = QJsonDocument::fromJson(data);
    f.close();
    return json.array();
}

qint64 product::getProductCount()
{
    QFile f("product.json");
    f.open(QIODevice::ReadOnly);
    QByteArray data = f.readAll();
    QJsonDocument json = QJsonDocument::fromJson(data);
    QJsonArray product = json.array();

    f.close();
    return product.size();
}

QJsonArray product::getAvailableProduct()
{
    QJsonArray availableProduct;
    QFile f("product.json");
    f.open(QIODevice::ReadOnly);
    QByteArray data = f.readAll();
    QJsonDocument json = QJsonDocument::fromJson(data);
    QJsonArray products = json.array();
    for (int i = 0; i < products.size(); i++) {
        if(products.at(i)["count"].toInt() > 0){
            availableProduct.append(products.at(i));
        }
    }

    f.close();
    return availableProduct;
}

QJsonObject product::getDetail(QString productName)
{
    QJsonArray availableProduct;
    QFile f("product.json");
    f.open(QIODevice::ReadOnly);
    QByteArray data = f.readAll();
    QJsonDocument json = QJsonDocument::fromJson(data);
    QJsonArray products = json.array();
    for (int i = 0; i < products.size(); i++) {
        if(products.at(i)["name"].toString() == productName){
            return products.at(i)["options"].toObject();
        }
    }

    f.close();
    return {};
}

qint64 product::getPrice(QString productName)
{
    QJsonArray availableProduct;
    QFile f("product.json");
    f.open(QIODevice::ReadOnly);
    QByteArray data = f.readAll();
    QJsonDocument json = QJsonDocument::fromJson(data);
    QJsonArray products = json.array();
    for (int i = 0; i < products.size(); i++) {
        if(products.at(i)["name"].toString() == productName){

            return products.at(i)["price"].toInt();
        }
    }

    f.close();
    return 0;
}

qint64 product::getAllAvailableProduct(QString productName)
{
    QJsonArray availableProduct;
    QFile f("product.json");
    f.open(QIODevice::ReadOnly);
    QByteArray data = f.readAll();
    QJsonDocument json = QJsonDocument::fromJson(data);
    QJsonArray products = json.array();
    for (int i = 0; i < products.size(); i++) {
        if(products.at(i)["name"].toString() == productName){

            return products.at(i)["count"].toInt();
        }
    }

    f.close();
    return 0;
}

bool product::updateAfterBuy(QString productName, qint64 count)
{
    QString customer,brand,weight,size,category;
    QJsonObject options;
    int productId,oldCount;
    qint64 price;

    QJsonArray newProducts;
    QFile f("product.json");
    f.open(QIODevice::ReadOnly);
    QByteArray data = f.readAll();
    QJsonDocument json = QJsonDocument::fromJson(data);
    QJsonArray products = json.array();
    for (int i = 0; i < products.size(); i++) {
        if(products.at(i)["name"] == productName){
            customer = products.at(i)["customer"].toString();
            price = products.at(i)["price"].toInt();
            brand = products.at(i)["brand"].toString();
            size = products.at(i)["size"].toString();
            weight = products.at(i)["weight"].toString();
            category = products.at(i)["category"].toString();
            productId = products.at(i)["id"].toInt();
            options = products.at(i)["options"].toObject();
            oldCount = products.at(i)["count"].toInt();
            QJsonObject newProduct = { {"id", productId},{"name", productName},{"customer", customer},{"count",(oldCount-count)},{"price",price} ,{"brand",brand}, {"weight",weight} ,{"size",size},{"category",category},{"options",options}};
            newProducts.append(newProduct);
        }else{
            newProducts.append(products.at(i));
        }
    }

    f.close();


    QJsonDocument doc(newProducts);
    QFile j("product.json");

    if( !j.open( QIODevice::ReadWrite | QIODevice::Truncate )  ){
        return false;
    }

    j.write(doc.toJson());
    j.close();

    user::updateAcount(customer,(count * price));
    return true;
}
