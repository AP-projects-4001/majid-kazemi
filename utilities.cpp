#include "utilities.h"
#include <QString>
#include <QDateTime>

utilities::utilities()
{

}
QString utilities::encrypt(QString str){

}
QString utilities::decrypt(QString str){

}

QString utilities::getDataAndTime()
{
    QDateTime date = QDateTime::currentDateTime();
    QString formattedTime = date.toString("hh:mm:ss | yyyy.MM.dd");
    QByteArray formattedTimeMsg = formattedTime.toLocal8Bit();
    return formattedTimeMsg;
}

