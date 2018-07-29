#ifndef MANAGER_H
#define MANAGER_H

#include"user.h"
class Manager : public User
{
public:
    Manager(const QString& name,const QString& pwd)
        :User(name,pwd){}
    Manager(const User& user)
        :User(user){}
    QString userType(){return "manager";}

    QString get_phone() {return phone;}
    void edit_phone(const QString& newPhone) {phone=newPhone;}

private:
    QString phone;
};

#endif // MANAGER_H
