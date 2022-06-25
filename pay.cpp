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

//    QDateTime date = QDateTime::currentDateTime();
//    QString formattedTime = date.toString("hh:mm:ss | yyyy.MM.dd");
//    QByteArray formattedTimeMsg = formattedTime.toLocal8Bit();
//    qDebug() << formattedTimeMsg;

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


