#include "buy.h"
#include <QFile>
#include <QJsonDocument>
#include <QDebug>
#include <QDateTime>
buy::buy()
{

}

QJsonArray buy::getAllBuy()
{
    QFile f("buy.json");
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

qint64 buy::getSumOfBuy()
{
    QFile f("buy.json");
    qint64 sum = 0;
    f.open(QIODevice::ReadOnly);
    QByteArray data = f.readAll();
    QJsonDocument json = QJsonDocument::fromJson(data);
    QJsonArray buy = json.array();
    for (int i = 0; i < buy.size(); i++) {
        sum += buy.at(i)["price"].toInt();
    }
    f.close();
    return sum;
}
