#include "validator.h"

validator::validator()
{

}
bool validator::userValidator(QString name, QString username, QString password, QString phone, QString address){
    if (name.length() >= 3) {
        if (username.length() >= 4) {
            if (password.length() >= 4) {
                if (phone.length() == 11) {
                    if (address.length() >= 4) {

                       return true;
                    }
                }
            }
        }
    }
    return false;
}
