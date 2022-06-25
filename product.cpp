#include "product.h"
#include <QFile>
#include <QJsonDocument>
#include <QDebug>

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
