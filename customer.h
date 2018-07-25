#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<QString>
#include "user.h"

class Customer:public User
{
public:
    Customer(const QString&name,const QString&pwd,const QString& phone)
        :User(name,pwd),phone(phone){}
    Customer(const User& user,const QString& phone)
        :User(user),phone(phone){}

    const QString& get_phone();
    void edit_phone(const QString& newPhone);

private:
    QString phone;
};

#endif // CUSTOMER_H
