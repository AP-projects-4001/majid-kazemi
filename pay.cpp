#include "pay.h"
#include <QFile>
#include <QJsonDocument>
#include <QDebug>
#include <QDateTime>

pay::pay()
{

}

QJsonArray pay::getAllPay()
{
    QFile f("pay.json");
    f.open(QIODevice::ReadOnly);
    QByteArray data = f.readAll();
    QJsonDocument json = QJsonDocument::fromJson(data);
    f.close();
    return json.array();

}

qint64 pay::getSumOfPay()
{
    QFile f("pay.json");
    qint64 sum = 0;
    f.open(QIODevice::ReadOnly);
    QByteArray data = f.readAll();
    QJsonDocument json = QJsonDocument::fromJson(data);
    QJsonArray pay = json.array();
    for (int i = 0; i < pay.size(); i++) {
        sum += pay.at(i)["amount"].toInt();
    }
    f.close();
    return sum;

}

QJsonArray pay::getPayForCustomer(QString customer)
{
    QJsonArray newPay;
    QFile f("pay.json");
    f.open(QIODevice::ReadOnly);
    QByteArray data = f.readAll();
    QJsonDocument json = QJsonDocument::fromJson(data);
    QJsonArray pay = json.array();
    for (int i = 0; i < pay.size(); i++) {
        if(pay.at(i)["customer"] == customer){
            newPay.append(pay.at(i));
        }
    }
    f.close();
    return newPay;
}

qint64 pay::getTotoalPayForCustomer(QString customer)
{
    qint64 sum = 0;
    QFile f("pay.json");
    f.open(QIODevice::ReadOnly);
    QByteArray data = f.readAll();
    QJsonDocument json = QJsonDocument::fromJson(data);
    QJsonArray pay = json.array();
    for (int i = 0; i < pay.size(); i++) {
        if(pay.at(i)["customer"] == customer){
            sum += pay.at(i)["amount"].toInt();
        }
    }
    f.close();
    return sum;
}


