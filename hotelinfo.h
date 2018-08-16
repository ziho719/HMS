#ifndef HOTELINFO_H
#define HOTELINFO_H

#include <QString>
#include <vector>
#include <memory>
#include "comment.h"
#include "room.h"
#include "location.h"
#include <QRegExp>

//一个酒店有且只有一个酒店信息，返回指针供外部使用

using namespace std;
class Comment;
class Room;
class Location;

class HotelInfo
{
public:
    static shared_ptr<HotelInfo> newHotelInfo(QString name="",Location loca=Location(),QString phone="",QString url="");
    shared_ptr<HotelInfo> get_shared_ptr();  //返回指针供外部使用

    HotelInfo(const HotelInfo &) =delete;
    HotelInfo & operator=(const HotelInfo &)=delete;

    void edit_name(const QString &newname);
    void edit_phone(const QString & newphone);
    void edit_url(const QString &newurl);
    void edit_location(const Location &loca);

    shared_ptr<HotelInfo> add_comment(const Comment& cm);
    shared_ptr<HotelInfo> add_comment(const QString &user,const QString &text,double mark);
    shared_ptr<HotelInfo> add_room(Room *r);
    shared_ptr<HotelInfo> add_room(QString type,QString url,QString description,double price,int sum,double discount=1);

    const vector<Comment>& get_comments() {return Comments;}
    const vector<Room *>&    get_rooms()  {return rooms;}
    const QString&         get_name() {return name;}
    const QString&         get_phone() {return phone;}
    const QString&         get_url()     {return url;}
          Location&        get_location()  {return location;}
            double         get_mark();                         //计算酒店评分
            double         get_lowest_price();                 //得到酒店最低价格供排序使用

    void add_roomSum(QString type);     //订单完成时，多出空房间
    void reduce_roomSum(QString type);  //新建订单时减少房间

    bool match(QString keyWord);   //判断关键词与酒店有无关系，用于搜索

private:
    HotelInfo(QString name="",Location loca=Location(),QString phone="",QString url=""); //私有构造函数
    void initialize(shared_ptr<HotelInfo> ptr);//让类自身保存一个weak引用

    QString name;
    Location location;
    QString phone;
    vector<Comment> Comments;
    vector<Room *> rooms;
    QString url;

    weak_ptr<HotelInfo> thisWeakPtr;   //自身信息的指针

};

#endif // HOTELINFO_H
