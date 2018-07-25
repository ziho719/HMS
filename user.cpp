#include "user.h"

User::User(const User &user)
{
    _name=user.name();
    _password=user.pwd();
}

void User::edit_name(const QString &newName)
{
    _name=newName;
}

bool User::check_pwd(const QString &pwd)
{
    return pwd==_password;
}

bool User::edit_pwd(const QString &oldpwd, const QString &newpwd)
{
    if(check_pwd(oldpwd)){
        _password=newpwd;
        return true;
    }
    else return false;
}
