#include "system.h"

void System::initialize()
{
    system=new System();

    if(false){
        //连接到数据库后
    }
    else{
        //否则
        //do something
        System::system->add_customer("ziho","ziho","18907851172");
        System::system->add_customer("test","test","12321412");
        System::system->add_manager("lao","lao");
        System::system->add_manager("B","B");
        System::system->add_admin("boss","boss");

        Order* o1 =new Order("ziho","apple","S",233);
        Order* o2 =new Order("ziho","banana","R",344);
        Order* o3 =new Order("test","canada","A",455);
        Order* o4 =new Order("test","dog","s",566);
        o1->change_status_to_done();
        o2->change_status_to_have_cancel();
        o3->change_status_to_pending_comment();
        System::system->add_order(o1);
        System::system->add_order(o2);
        System::system->add_order(o3);
        System::system->add_order(o4);

        Hotel* h1 =new Hotel(HotelInfo::newHotelInfo("apple",Location("beijing","A","A"),"1"),"lao");
        Hotel* h2 =new Hotel(HotelInfo::newHotelInfo("apple",Location("beijing","A","A"),"1"),"lao");
        Hotel* h3 =new Hotel(HotelInfo::newHotelInfo("apple",Location("beijing","A","A"),"1"),"B");
        Hotel* h4 =new Hotel(HotelInfo::newHotelInfo("apple",Location("beijing","A","A"),"1"),"B");
        h1->change_status_to_checked();
        h2->change_status_to_checked();
        h1->get_hotel_info()->add_comment("ziho","rubbish",1);
        h2->get_hotel_info()->add_room("A","A","C",233,2,10);
        System::system->add_hotel(h1);
        System::system->add_hotel(h2);
        System::system->add_hotel(h3);
        System::system->add_hotel(h4);

    }

}
System::System()
{
    qDebug()<<"system create";
}
System *System::getSystem()
{
    return system;
}

System::~System()
{
    for(auto i : hotels)   { delete i; }
    for(auto i : orders)   {delete i;}
    for(auto i : customers){delete i;}
    for(auto i : managers) {delete i;}
    for(auto i : admins)    {delete i;}
    qDebug()<<"system destroy";
}

Customer *System::add_customer(const QString &name, const QString &pwd, const QString &phone)
{
    Customer* ptr=new Customer(name,pwd,phone);
    customers.insert(ptr);
    return ptr;
}

Manager *System::add_manager(const QString &name, const QString &pwd)
{
    Manager *ptr=new Manager(name,pwd);
    managers.insert(ptr);
    return ptr;
}

Administrater *System::add_admin(const QString &name, const QString &pwd)
{
    Administrater *ptr=new Administrater(name,pwd);
    admins.insert(ptr);
    return ptr;
}

vector<Hotel *> &System::get_hotels()
{
    return hotels;
}

vector<Order *> &System::get_orders()
{
    return orders;
}

set<Customer *> &System::get_customers()
{
    return customers;
}

set<Manager *> &System::get_managers()
{
    return managers;
}

set<Administrater *> &System::get_admins()
{
    return admins;
}

const vector<Hotel *> &System::get_hotels() const
{
    return hotels;
}

const vector<Order *> &System::get_orders() const
{
    return orders;
}

const set<Customer *> &System::get_customers() const
{
    return customers;
}

const set<Manager *> &System::get_managers() const
{
    return managers;
}

const set<Administrater *> &System::get_admins() const
{
    return admins;
}

User *System::get_user()
{
    return user;
}

Customer *System::find_customer(const QString &name)
{
    for(Customer* customer:customers){
        if(customer->name()==name){
            return customer;
        }
    }
    qDebug()<<"customer not found";
    return NULL;
}

Manager *System::find_manager(const QString &name)
{
    for(Manager* manager: managers){
        if(manager->name()==name){
            return manager;
        }
    }
    qDebug()<<"manager not found";
    return NULL;
}

Administrater *System::find_admin(const QString &name)
{
    for(Administrater* admin: admins){
        if(admin->name()==name){
            return admin;
        }
    }
    return NULL;
}

Customer *System::check_customer_accout(const QString &name, const QString &pwd)
{
    for(Customer* customer:customers){
        if(customer->name()==name){
            if(customer->pwd()==pwd) return customer;
            else return NULL;
        }
    }
    return NULL;
}

Manager *System::check_manager_accout(const QString &name, const QString &pwd)
{
    for(Manager* manager: managers){
        if(manager->name()==name){
            if(manager->pwd()==pwd) return manager;
            else return NULL;
        }
    }
    return NULL;
}

Administrater *System::check_admin_accout(const QString &name, const QString &pwd)
{
    for(Administrater* admin: admins){
        if(admin->name()==name){
            if(admin->pwd()==pwd) return admin;
            else return NULL;
        }
    }
    return NULL;
}

bool System::check_name_available(const QString &name)
{
    if(!find_customer(name) && !find_admin(name) && !find_manager(name)){
        return true;
    }
    else return false;
}

void System::add_hotel(Hotel *newHotel)
{
    hotels.push_back(newHotel);
}

void System::add_order(Order *newOrder)
{
    orders.push_back(newOrder);
}

