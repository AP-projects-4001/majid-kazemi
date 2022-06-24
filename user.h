#ifndef USER_H
#define USER_H
#include <QString>

class user
{
public:
    user();
    static bool loginUser(QString username , QString password);
    static QString rememberMe(QString username , QString phone);
    static bool existUsername(QString username);
    static bool existPhone(QString phone);
    static bool save(QString name,QString username,QString password,QString phone,QString address);
    static QString getRole(QString username);
    static bool isActive(QString username);

};

#endif // USER_H
