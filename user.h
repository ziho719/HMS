#ifndef USER_H
#define USER_H

#include<QString>
using namespace std;

class User
{
public:
    User(const QString& name, const QString& password)
        :_name(name), _password(password){}
    User(const User& user);
    virtual ~User(){}

    virtual QString userType(){return "user";}
    virtual QString get_phone(){return "";}
    virtual void edit_phone(const QString&){}

    const QString& name() const{return _name;}
    const QString& pwd() const{return _password;}
    void edit_name(const QString& newName);
    bool check_pwd(const QString& pwd);
    bool edit_pwd(const QString& oldpwd,const QString& newpwd);

private:
    QString _name;
    QString _password;
};

#endif // USER_H
