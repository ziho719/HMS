#include "system.h"

System* System::system=new System(); //初始化私有静态变量


void System::initialize()
{
    if(false){
        //连接到数据库后
    }
    else{
        //否则
        System::getSystem()->set_user(NULL);
        System::getSystem()->add_customer("ziho","ziho","18907851172");
        System::getSystem()->add_customer("frisk","frisk","12321412");
        System::getSystem()->add_manager("papyrus","papyrus");
        System::getSystem()->add_manager("sans","sans");
        System::getSystem()->add_manager("toriel","toriel");
        System::getSystem()->add_admin("boss","boss");
        System::getSystem()->add_admin("toby","toby");

        Order* o1 =new Order("ziho",QString::fromLocal8Bit("锦江之星"),QString::fromLocal8Bit("商务房B"),666);
        Order* o2 =new Order("ziho",QString::fromLocal8Bit("阳朔假日大酒店"),QString::fromLocal8Bit("缤纷大床房"),458);
        Order* o3 =new Order("ziho",QString::fromLocal8Bit("北京泰富酒店"),QString::fromLocal8Bit("行政至尊套房"),1228);
        Order* o4 =new Order("ziho",QString::fromLocal8Bit("涠洲岛海景酒店"),QString::fromLocal8Bit("海景亲子间"),858);
        Order* o5 =new Order("ziho",QString::fromLocal8Bit("锦江之星"),QString::fromLocal8Bit("商务房B"),667);
        Order* o6 =new Order("frisk",QString::fromLocal8Bit("锦江之星"),QString::fromLocal8Bit("商务房B"),668);
        Order* o7 =new Order("ziho",QString::fromLocal8Bit("锦江之星"),QString::fromLocal8Bit("商务房B"),669);
        Order* o8 =new Order("ziho",QString::fromLocal8Bit("锦江之星"),QString::fromLocal8Bit("商务房B"),670);
        Order* o9 =new Order("ziho",QString::fromLocal8Bit("锦江之星"),QString::fromLocal8Bit("商务房B"),671);
        Order* o10 =new Order("ziho",QString::fromLocal8Bit("锦江之星"),QString::fromLocal8Bit("商务房B"),672);
        o1->change_status_to_done();
        o2->change_status_to_have_cancel();
        o3->change_status_to_checking_payment();
        o4->change_status_to_have_refund();
        o5->change_status_to_pending_comment();
        o6->change_status_to_pending_checkin();
        o7->change_status_to_pending_checkin();
        o8->change_status_to_checking_payment();
        o9->change_status_to_pending_comment();
        o10->change_status_to_have_refund();
        System::getSystem()->add_order(o1);
        System::getSystem()->add_order(o2);
        System::getSystem()->add_order(o3);
        System::getSystem()->add_order(o4);
        System::getSystem()->add_order(o5);
        System::getSystem()->add_order(o6);
        System::getSystem()->add_order(o7);
        System::getSystem()->add_order(o8);
        System::getSystem()->add_order(o9);
        System::getSystem()->add_order(o10);

        Location l1(QString::fromLocal8Bit("北京"),QString::fromLocal8Bit("北京"),QString::fromLocal8Bit("朝阳区"));
        Location l2(QString::fromLocal8Bit("北京"),QString::fromLocal8Bit("北京"),QString::fromLocal8Bit("顺义区"));
        Location l3(QString::fromLocal8Bit("北京"),QString::fromLocal8Bit("北京"),QString::fromLocal8Bit("海淀区"));
        Location l4(QString::fromLocal8Bit("北京"),QString::fromLocal8Bit("北京"),QString::fromLocal8Bit("朝阳区"));
        Location l5(QString::fromLocal8Bit("广西"),QString::fromLocal8Bit("桂林"),QString::fromLocal8Bit("阳朔"));
        Location l6(QString::fromLocal8Bit("广西"),QString::fromLocal8Bit("北海"),QString::fromLocal8Bit("海城区"));

        Hotel* h1 =new Hotel(HotelInfo::newHotelInfo(QString::fromLocal8Bit("北京酒店式公寓"),l1,"11111",QString::fromLocal8Bit(":/pics/pic/北京机场酒店式公寓.jpg")),"sans");
        Hotel* h2 =new Hotel(HotelInfo::newHotelInfo(QString::fromLocal8Bit("锦江之星"),l2,"22222",QString::fromLocal8Bit(":/pics/pic/2-锦江之星.jpg")),"sans");
        Hotel* h3 =new Hotel(HotelInfo::newHotelInfo(QString::fromLocal8Bit("北京泰富酒店"),l3,"333333",QString::fromLocal8Bit(":/pics/pic/北京泰富酒店.jpg")),"papyrus");
        Hotel* h4 =new Hotel(HotelInfo::newHotelInfo(QString::fromLocal8Bit("桔子酒店"),l4,"444444",QString::fromLocal8Bit(":/pics/pic/桔子酒店.jpg")),"papyrus");
        Hotel* h5 =new Hotel(HotelInfo::newHotelInfo(QString::fromLocal8Bit("阳朔假日大酒店"),l5,"5555555",QString::fromLocal8Bit(":/pics/pic/阳朔.jpg")),"toriel");
        Hotel* h6 =new Hotel(HotelInfo::newHotelInfo(QString::fromLocal8Bit("涠洲岛海景酒店"),l6,"66666666",QString::fromLocal8Bit(":/pics/pic/涠洲岛.jpg")),"toriel");
        h1->change_status_to_checked();
        h2->change_status_to_checked();
        h3->change_status_to_checked();
        //h4->change_status_to_checked();
        h5->change_status_to_checked();
        h6->change_status_to_checked();

        //here...........
        h1->get_hotel_info()->add_room(QString::fromLocal8Bit("精品大床房"),QString::fromLocal8Bit(":/pics/pic/1-精.jpg"),QString::fromLocal8Bit("大床"),501,10);
        h1->get_hotel_info()->add_room(QString::fromLocal8Bit("温馨标准间"),QString::fromLocal8Bit(":/pics/pic/1-温.jpg"),QString::fromLocal8Bit("单床"),501,0);
        h1->get_hotel_info()->add_room(QString::fromLocal8Bit("豪华商务套房"),QString::fromLocal8Bit(":/pics/pic/1-豪华.jpg"),QString::fromLocal8Bit("大床"),578,3);
        h2->get_hotel_info()->add_room(QString::fromLocal8Bit("标准房"),QString::fromLocal8Bit(":/pics/pic/2-标.jpg"),QString::fromLocal8Bit("多床"),659,5,619);
        h2->get_hotel_info()->add_room(QString::fromLocal8Bit("商务房"),QString::fromLocal8Bit(":/pics/pic/2-商.jpg"),QString::fromLocal8Bit("大床"),657,10);
        h2->get_hotel_info()->add_room(QString::fromLocal8Bit("商务房B"),QString::fromLocal8Bit(":/pics/pic/商务房B.jpg"),QString::fromLocal8Bit("多床"),666,10);
        h3->get_hotel_info()->add_room(QString::fromLocal8Bit("豪华标准房"),QString::fromLocal8Bit(":/pics/pic/豪华.jpg"),QString::fromLocal8Bit("双床"),1228,1);
        h3->get_hotel_info()->add_room(QString::fromLocal8Bit("行政至尊套房"),QString::fromLocal8Bit(":/pics/pic/2-行政.jpg"),QString::fromLocal8Bit("多床"),4508,10);
        h4->get_hotel_info()->add_room(QString::fromLocal8Bit("森林狂欢"),QString::fromLocal8Bit(":/pics/pic/4-森林.jpg"),QString::fromLocal8Bit("大床"),835,10);
        h4->get_hotel_info()->add_room(QString::fromLocal8Bit("挪威森林"),QString::fromLocal8Bit(":/pics/pic/4-挪威.jpg"),QString::fromLocal8Bit("双床"),940,4);
        h5->get_hotel_info()->add_room(QString::fromLocal8Bit("缤纷大床房"),QString::fromLocal8Bit(":/pics/pic/阳朔-缤纷.jpg"),QString::fromLocal8Bit("大床"),458,11);
        h5->get_hotel_info()->add_room(QString::fromLocal8Bit("阳台商务房"),QString::fromLocal8Bit(":/pics/pic/阳朔-阳台.jpg"),QString::fromLocal8Bit("大床"),478,8);
        h6->get_hotel_info()->add_room(QString::fromLocal8Bit("海景标准间"),QString::fromLocal8Bit(":/pics/pic/涠洲岛-标.jpg"),QString::fromLocal8Bit("大床"),686,10);
        h6->get_hotel_info()->add_room(QString::fromLocal8Bit("海景亲子间"),QString::fromLocal8Bit(":/pics/pic/涠洲岛-亲.jpg"),QString::fromLocal8Bit("多床"),858,2);

        h1->get_hotel_info()->add_comment("ziho",QString::fromLocal8Bit("环境非常好"),5);
        h1->get_hotel_info()->add_comment("ziho",QString::fromLocal8Bit("位置难找"),3);
        h1->get_hotel_info()->add_comment("ziho",QString::fromLocal8Bit("态度不怎么好"),3.4);
        h2->get_hotel_info()->add_comment("ziho",QString::fromLocal8Bit("房间卫生不错"),4.4);
        h2->get_hotel_info()->add_comment("ziho",QString::fromLocal8Bit("性价比很高"),4.7);
        h2->get_hotel_info()->add_comment("ziho",QString::fromLocal8Bit("空间利用合理，服务也很周到"),5);
        h2->get_hotel_info()->add_comment("ziho",QString::fromLocal8Bit("距离机场很近，推荐"),4.8);
        h2->get_hotel_info()->add_comment("ziho",QString::fromLocal8Bit("帮助提行李，准时，热情"),5);
        h3->get_hotel_info()->add_comment("ziho",QString::fromLocal8Bit("五星级硬件，交通方便，门厅热情"),5);
        h3->get_hotel_info()->add_comment("ziho",QString::fromLocal8Bit("智能化设备，人性化服务"),5);
        h3->get_hotel_info()->add_comment("ziho",QString::fromLocal8Bit("值得信赖，就是价格不低"),4.7);
        h3->get_hotel_info()->add_comment("ziho",QString::fromLocal8Bit("酒店交通非常方便"),4.8);
        h4->get_hotel_info()->add_comment("ziho",QString::fromLocal8Bit("麻雀虽小，五脏俱全"),5);
        h4->get_hotel_info()->add_comment("ziho",QString::fromLocal8Bit("舒适干净又便利"),5);
        h4->get_hotel_info()->add_comment("ziho",QString::fromLocal8Bit("态度很好服务热情"),4.5);
        h4->get_hotel_info()->add_comment("ziho",QString::fromLocal8Bit("交通便利"),4.5);
        h5->get_hotel_info()->add_comment("ziho",QString::fromLocal8Bit("花园套房给我很大惊喜，格局设计独具匠心"),4.8);
        h5->get_hotel_info()->add_comment("ziho",QString::fromLocal8Bit("设计比较合理很方便"),4.9);
        h5->get_hotel_info()->add_comment("ziho",QString::fromLocal8Bit("酒店位置比较好找"),4.6);
        h5->get_hotel_info()->add_comment("ziho",QString::fromLocal8Bit("房间不吵，很安静"),5);
        h6->get_hotel_info()->add_comment("ziho",QString::fromLocal8Bit("住的舒服 老板热情"),5);
        h6->get_hotel_info()->add_comment("ziho",QString::fromLocal8Bit("出门小路走3-5分钟就到海边"),5);
        h6->get_hotel_info()->add_comment("ziho",QString::fromLocal8Bit("大海景色非常好"),4.7);

        System::getSystem()->add_hotel(h1);
        System::getSystem()->add_hotel(h2);
        System::getSystem()->add_hotel(h3);
        System::getSystem()->add_hotel(h4);
        System::getSystem()->add_hotel(h5);
        System::getSystem()->add_hotel(h6);
        //结束否则
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

Hotel *System::find_hotel(const QString &name)
{
    for(auto hotel:hotels){
        if(hotel->get_hotel_info()->get_name()==name){
            return hotel;
        }
    }
    return NULL;
}

vector<Order *> System::select_order()
{
    auto s=System::getSystem();
    vector<Order *> res;
    if(s->get_user()->userType()=="customer"){
        for(auto order:s->get_orders()){
            if(order->get_user()==s->get_user()->name()){
                res.push_back(order);
            }
        }
        return res;
    }
    else if(s->get_user()->userType()=="manager"){
        qDebug()<<"here?";
        for(auto order:s->get_orders()){
            if(s->find_hotel(order->get_hotel())->getManagerName()==s->get_user()->name()){
                res.push_back(order);
                qDebug()<<"here?";
            }
        }
        qDebug()<<"here?";
        return res;
    }
    else{
        qDebug()<<"System select order wrong";
        return res;
    }
}

Customer *System::check_customer_account(const QString &name, const QString &pwd)
{
    for(Customer* customer:customers){
        if(customer->name()==name){
            if(customer->pwd()==pwd) return customer;
            else return NULL;
        }
    }
    return NULL;
}

Manager *System::check_manager_account(const QString &name, const QString &pwd)
{
    for(Manager* manager: managers){
        if(manager->name()==name){
            if(manager->pwd()==pwd) return manager;
            else return NULL;
        }
    }
    return NULL;
}

Administrater *System::check_admin_account(const QString &name, const QString &pwd)
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

void System::set_user(User *u)
{
    user=u;
}

vector<shared_ptr<HotelInfo> > System::get_hotelinfo_checked()
{
    vector<shared_ptr<HotelInfo> > res;
    for(int i=0;i<hotels.size();i++){
        if(hotels[i]->get_status()=="checked")
            res.push_back(hotels[i]->get_hotel_info());
    }
    return res;
}

vector<shared_ptr<HotelInfo> > System::get_hotelinfo_unchecked()
{
    vector<shared_ptr<HotelInfo> > res;
    for(int i=0;i<hotels.size();i++){
        if(hotels[i]->get_status()=="unchecked")
            res.push_back(hotels[i]->get_hotel_info());
    }
    return res;
}

