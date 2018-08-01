#include "database.h"

bool Database::connect(QSqlDatabase &db)
{
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("hms");

    if(!db.open())
        return false;
    qDebug()<<"db opened!";
    return true;
}

void Database::write_all()
{
    write_hotel();
    write_room();
    write_comment();
    write_user();
    write_order();
    write_hotelmanager();
}

void Database::read_all()
{
    read_hotel();
    read_room();
    read_comment();
    read_user();
    read_order();
    read_hotelmanager();
}

void Database::write_hotel()
{
    QSqlQuery q;
    if(!q.exec("CREATE TABLE hotels"
               "("
               "ht_status     VARCHAR(100)   NOT NULL,"
               "ht_name       VARCHAR(100)   NOT NULL,"
               "ht_phone      VARCHAR(100)   NOT NULL,"
               "ht_url        VARCHAR(100)   NOT NULL,"
               "ht_province   VARCHAR(100)   NOT NULL,"
               "ht_city       VARCHAR(100)   NOT NULL,"
               "ht_district   VARCHAR(100)   NOT NULL"
               ")")){
        qDebug()<<q.lastError(); //表存在时出错
    }
    q.exec("DELETE FROM hotels");
    qDebug()<<q.lastError();

    for(auto hotel:System::getSystem()->get_hotels()){
        q.exec(QString("INSERT INTO hotels "
                       "VALUES('%1','%2','%3','%4','%5','%6','%7')")
               .arg(hotel->get_status())
               .arg(hotel->get_hotel_info()->get_name())
               .arg(hotel->get_hotel_info()->get_phone())
               .arg(hotel->get_hotel_info()->get_url())
               .arg(hotel->get_hotel_info()->get_location().get_province())
               .arg(hotel->get_hotel_info()->get_location().get_city())
               .arg(hotel->get_hotel_info()->get_location().get_district()));
    }

    qDebug()<<"write hotel success";
}

void Database::write_room()
{
    QSqlQuery q;
    if(!q.exec("CREATE TABLE rooms"
               "("
               "rm_hotel      VARCHAR(100)   NOT NULL,"
               "rm_name       VARCHAR(100)   NOT NULL,"
               "rm_desc       VARCHAR(100)   NOT NULL,"
               "rm_url        VARCHAR(100)   NOT NULL,"
               "rm_price      FLOAT          NOT NULL,"
               "rm_discount   FLOAT          NOT NULL,"
               "rm_sum        INT            NOT NULL"
               ")")){
        qDebug()<<q.lastError(); //表存在时出错
    }
    q.exec("DELETE FROM rooms");

    for(auto hotel:System::getSystem()->get_hotels()){
        for(Room *room:hotel->get_hotel_info()->get_rooms())
        {
            q.exec(QString("INSERT INTO rooms "
                           "VALUES('%1','%2','%3','%4',%5,%6,%7)")
                   .arg(hotel->get_hotel_info()->get_name())
                   .arg(room->get_type())
                   .arg(room->get_description())
                   .arg(room->get_url())
                   .arg(room->get_price())
                   .arg(room->get_discount())
                   .arg(room->get_sum()));
        }
    }
    qDebug()<<"write room success";
}

void Database::write_comment()
{
    QSqlQuery q;
    if(!q.exec("CREATE TABLE comments"
               "("
               "cm_hotel      VARCHAR(100)   NOT NULL,"
               "cm_name       VARCHAR(100)   NOT NULL,"
               "cm_text       VARCHAR(500)   NOT NULL,"
               "cm_mark       DOUBLE         NOT NULL"
               ")")){
        qDebug()<<q.lastError(); //表存在时出错
    }
    q.exec("DELETE FROM comments");

    for(auto hotel:System::getSystem()->get_hotels()){
        for(Comment comment:hotel->get_hotel_info()->get_comments())
        {
            q.exec(QString("INSERT INTO comments "
                           "VALUES('%1','%2','%3',%4)")
                   .arg(hotel->get_hotel_info()->get_name())
                   .arg(comment.get_userName())
                   .arg(comment.get_content())
                   .arg(comment.get_mark()));
        }
    }
    qDebug()<<"write comment success";
}

void Database::write_user()
{
    QSqlQuery q;
    //把顾客写进数据库
    if(!q.exec("CREATE TABLE customers"
               "("
               "cm_name       VARCHAR(100)   NOT NULL,"
               "cm_pwd        VARCHAR(100)   NOT NULL,"
               "cm_phone      VARCHAR(100)   NOT NULL"
               ")")){
        qDebug()<<q.lastError(); //表存在时出错
    }
    q.exec("DELETE FROM customers");
    for(Customer* customer:System::getSystem()->get_customers()){
            q.exec(QString("INSERT INTO customers "
                           "VALUES('%1','%2','%3')")
                   .arg(customer->name())
                   .arg(customer->pwd())
                   .arg(customer->get_phone()));
    }


    if(!q.exec("CREATE TABLE managers"
               "("
               "mn_name       VARCHAR(100)   NOT NULL,"
               "mn_pwd        VARCHAR(100)   NOT NULL,"
               "mn_phone      VARCHAR(100)   NOT NULL"
               ")")){
        qDebug()<<q.lastError(); //表存在时出错
    }
    q.exec("DELETE FROM managers");
    for(Manager* manager:System::getSystem()->get_managers()){
            q.exec(QString("INSERT INTO managers "
                           "VALUES('%1','%2','%3')")
                   .arg(manager->name())
                   .arg(manager->pwd())
                   .arg(manager->get_phone()));
    }

    if(!q.exec("CREATE TABLE admins"
               "("
               "op_name       VARCHAR(100)   NOT NULL,"
               "op_pwd        VARCHAR(100)   NOT NULL"
               ")")){
        qDebug()<<q.lastError(); //表存在时出错
    }
    q.exec("DELETE FROM admins");
    for(Administrater* admin:System::getSystem()->get_admins()){
            q.exec(QString("INSERT INTO admins "
                           "VALUES('%1','%2')")
                   .arg(admin->name())
                   .arg(admin->pwd()));
    }

    qDebug()<<"write user success";
}

void Database::write_order()
{
    QSqlQuery q;
    if(!q.exec("CREATE TABLE orders"
               "("
               "od_hotel      VARCHAR(100)   NOT NULL,"
               "od_userName   VARCHAR(100)   NOT NULL,"
               "od_roomType   VARCHAR(500)   NOT NULL,"
               "od_price      DOUBLE         NOT NULL,"
               "od_status     VARCHAR(100)   NOT NULL"
               ")")){
        qDebug()<<q.lastError(); //表存在时出错
    }
    q.exec("DELETE FROM orders");

    for(auto order:System::getSystem()->get_orders()){
        q.exec(QString("INSERT INTO orders "
                       "VALUES('%1','%2','%3',%4,'%5')")
               .arg(order->get_hotel())
               .arg(order->get_user())
               .arg(order->get_roomType())
               .arg(order->get_money())
               .arg(order->get_status()));
    }
    qDebug()<<"write order success";
}

void Database::write_hotelmanager()
{
    QSqlQuery q;
    if(!q.exec("CREATE TABLE hotelmanagers"
               "("
               "hm_hotel      VARCHAR(100)   NOT NULL,"
               "hm_mName   VARCHAR(100)   NOT NULL"
               ")")){
        qDebug()<<q.lastError(); //表存在时出错
    }
    q.exec("DELETE FROM hotelmanagers");

    for(auto hotel:System::getSystem()->get_hotels()){
        for(auto manager:hotel->get_manager())
        {
            q.exec(QString("INSERT INTO hotelmanagers "
                           "VALUES('%1','%2')")
                   .arg(hotel->get_hotel_info()->get_name())
                   .arg(manager));
        }
    }
    qDebug()<<"write mn success";
}

void Database::read_hotel()
{
    QSqlQuery q;
    q.exec("SELECT ht_status,ht_name,ht_phone,ht_url,"
                    "ht_province,ht_city,ht_district   "
           "FROM hotels");
     qDebug()<<q.lastError();

    auto s=System::getSystem();
    while(q.next()) {
        Location l(q.value(4).toString(),q.value(5).toString(),q.value(6).toString());
        Hotel *h=new Hotel(HotelInfo::newHotelInfo(q.value(1).toString(),l,q.value(2).toString(),q.value(3).toString()),vector<QString>{});
        QString status=q.value(0).toString();
        if(status=="checked") h->change_status_to_checked();
        else if(status=="unchecked") h->change_status_to_unchecked();
        else if(status=="changed") h->change_status_to_changed();
        s->add_hotel(h);
        qDebug()<<"read hotel";
        qDebug()<<h->get_hotel_info()->get_name();
    }
    qDebug()<<"read hotel success";
}

void Database::read_room()
{
    QSqlQuery q;
    q.exec("SELECT  rm_hotel,rm_name,rm_desc,rm_url,rm_price,rm_discount,rm_sum   "
           "FROM rooms");
    qDebug()<<q.lastError();
    auto s=System::getSystem();
    while (q.next()) {
        auto hotel=s->find_hotel(q.value(0).toString());
        hotel->get_hotel_info()->add_room(q.value(1).toString(),q.value(3).toString(),
                                          q.value(2).toString(),q.value(4).toDouble(),q.value(6).toInt(),q.value(5).toDouble());
    }
    qDebug()<<"read room success";
}

void Database::read_comment()
{
    QSqlQuery q;
    q.exec("SELECT  cm_hotel,cm_name,cm_text,cm_mark  "
           "FROM comments");
    qDebug()<<q.lastError();
    auto s=System::getSystem();
    while (q.next()) {
        auto hotel=s->find_hotel(q.value(0).toString());
        hotel->get_hotel_info()->add_comment(q.value(1).toString(),q.value(2).toString(),q.value(3).toDouble());
    }
    qDebug()<<"read hotel success";
}

void Database::read_user()
{
    QSqlQuery q;
    auto s=System::getSystem();

    q.exec("SELECT  cm_name,cm_pwd,cm_phone  "
           "FROM customers");
    while (q.next()) {
        s->add_customer(q.value(0).toString(),q.value(1).toString(),q.value(2).toString());
    }
    q.exec("SELECT  mn_name,mn_pwd,mn_phone  "
           "FROM managers");
    while (q.next()) {
        s->add_manager(q.value(0).toString(),q.value(1).toString(),q.value(2).toString());
    }
    q.exec("SELECT  op_name,op_pwd "
           "FROM admins");
    while (q.next()) {
        s->add_admin(q.value(0).toString(),q.value(1).toString());
    }
    qDebug()<<"read user success";
}

void Database::read_order()
{
    QSqlQuery q;
    auto s=System::getSystem();

    q.exec("SELECT  od_hotel,od_userName,od_roomType,od_price,od_status  "
           "FROM orders");

    while (q.next()) {
        Order *o=new Order(q.value(1).toString(),q.value(0).toString(),q.value(2).toString(),q.value(3).toDouble());
        QString status=q.value(4).toString();
        if(status=="pending_checkin"){
            o->change_status_to_pending_checkin();
        }
        else if(status=="checking_payment"){
            o->change_status_to_checking_payment();
        }
        else if(status=="pending_comment"){
            o->change_status_to_pending_comment();
        }
        else if(status=="have_refund"){
            o->change_status_to_have_refund();
        }
        else if(status=="have_cancel"){
            o->change_status_to_have_cancel();
        }
        else if(status=="done"){
            o->change_status_to_done();
        }
        else qDebug()<<"read order wrong";
        s->add_order(o);
    }
    qDebug()<<"read o success";
}


void Database::read_hotelmanager()
{
    QSqlQuery q;
    q.exec("SELECT  hm_hotel,hm_mName "
           "FROM hotelmanagers");
    auto s=System::getSystem();
    while (q.next()) {
        auto hotel=s->find_hotel(q.value(0).toString());
        hotel->add_manager(q.value(1).toString());
    }
    qDebug()<<"read mn success";
}
