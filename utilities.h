#ifndef UTILITIES_H
#define UTILITIES_H
#include <QString>
class utilities
{
public:
    utilities();
    static QString encrypt(QString str);
    static QString decrypt(QString str);
};

#endif // UTILITIES_H
