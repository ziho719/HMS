#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <set>
#include <memory>
#include <QString>
#include <QDebug>
#include "administrater.h"
#include "manager.h"
#include "user.h"
#include "order.h"
#include "hotel.h"
#include "customer.h"
using namespace std;

class Hotel;
class Order;
class User;
class Customer;
class Manager;
class Administrater;

class System
{
public:
    //静态方法初始化
    static void initialize();
    static System *getSystem();
    ~System();

    //添加用户
    Customer* add_customer(const QString&name,const QString&pwd,const QString& phone);
    Manager* add_manager(const QString&name,const QString&pwd);
    Administrater* add_admin(const QString&name,const QString&pwd);

    //TODO:删除用户，有空添加

    //获取变量
    vector<Hotel*>& get_hotels();
    vector<Order*>& get_orders();
    set<Customer*>& get_customers();
    set<Manager*> & get_managers();
    set<Administrater*>&  get_admins();
    const vector<Hotel*>& get_hotels() const;
    const vector<Order*>& get_orders() const;
    const set<Customer*>& get_customers() const;
    const set<Manager*> & get_managers() const;
    const set<Administrater*>&  get_admins() const;
    User*           get_user();
    Customer* find_customer(const QString& name);
    Manager* find_manager(const QString& name);
    Administrater* find_admin(const QString& name);

    //登录、检查pwd
    Customer* check_customer_accout(const QString& name,const QString& pwd);
    Manager* check_manager_accout(const QString& name,const QString& pwd);
    Administrater* check_admin_accout(const QString& name,const QString& pwd);

    //检查重名
    bool check_name_available(const QString& name);

    void add_hotel(Hotel* newHotel);
    void add_order(Order* newOrder);



private:
    System();
    static System* system;

    vector<Hotel*> hotels; //酒店组
    vector<Order*> orders; //订单组

    set<Customer*> customers;   //用户信息组
    set<Manager*> managers;
    set<Administrater*> admins; //管理员账户

    User* user; //当前登录用户
};

#endif // SYSTEM_H
