#ifndef SYSTEM_H
#define SYSTEM_H


#include <algorithm>
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
#include "database.h"
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
    Customer* add_customer(const QString&name,const QString&pwd,QString phone="");
    Manager* add_manager(const QString&name,const QString&pwd,QString phone="");
    Administrater* add_admin(const QString&name,const QString&pwd);


    //获取变量
    vector<Hotel*>& get_hotels();   //从没用过的接口
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
    Hotel *find_hotel(const QString& name);

    vector<Order*> select_order(); //只返回当前用户的订单
    vector<Hotel *> select_hotel(); //对于酒店管理员，返回所有，对于平台，返回待确认的

    //登录、检查pwd
    Customer* check_customer_account(const QString& name,const QString& pwd);
    Manager* check_manager_account(const QString& name,const QString& pwd);
    Administrater* check_admin_account(const QString& name,const QString& pwd);

    //检查重名
    bool check_name_available(const QString& name);

    //新建操作
    void add_hotel(Hotel* newHotel);
    void add_order(Order* newOrder);

    //更改用户
    void set_user(User* u);

    //用于创建listwidget的select函数
    vector<shared_ptr<HotelInfo>> get_hotelinfo_checked(QString loca="",QString keyWord="",QString Mode="");
    vector<shared_ptr<HotelInfo>> get_hotelinfo_unchecked();


private:
    System();
    static System *system;

    vector<Hotel*> hotels; //酒店容器
    vector<Order*> orders; //订单容器

    set<Customer*> customers;   //用户信息容器
    set<Manager*> managers;
    set<Administrater*> admins; //管理员账户

    User* user; //当前登录用户
};

#endif // SYSTEM_H
