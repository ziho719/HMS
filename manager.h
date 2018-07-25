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
};

#endif // MANAGER_H
