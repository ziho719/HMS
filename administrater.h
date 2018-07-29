#ifndef ADMINISTRATER_H
#define ADMINISTRATER_H

#include"user.h"

class Administrater : public User
{
public:
    Administrater(const QString& name,const QString& pwd)
        :User(name,pwd){}
    Administrater(const User& user)
        :User(user){}
    QString userType() {return "admin";}
};

#endif // ADMINISTRATER_H
