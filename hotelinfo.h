#ifndef HOTELINFO_H
#define HOTELINFO_H

#include <QString>
#include <vector>
#include <memory>
#include "comment.h"
#include "room.h"
#include "location.h"

using namespace std;

class HotelInfo
{
public:
    static shared_ptr<HotelInfo> newHotelInfo(QString name,Location loca,QString phone,QString url="NULL");
    shared_ptr<HotelInfo> get_shared_ptr();

    HotelInfo(const HotelInfo &) =delete;
    HotelInfo & operator=(const HotelInfo &)=delete;

    void edit_name(const QString &newname);
    void edit_phone(const QString & newphone);
    void edit_url(const QString &newurl);
    void edit_location(const Location &loca);

    shared_ptr<HotelInfo> add_comment(const Comment& cm);
    shared_ptr<HotelInfo> add_comment(const QString &user,const QString &text,int mark);
    shared_ptr<HotelInfo> add_room(const Room& r);
    shared_ptr<HotelInfo> add_room(QString type,QString url,QString description,double price,int people,int sum,double discount=1);

    const vector<Comment>& get_comments() const {return Comments;}
    const vector<Room>&    get_rooms() const {return rooms;}
    const QString&         get_name() const {return name;}
    const QString&         get_phone() const {return phone;}
    const QString&         get_url() const {return url;}
    const Location&        get_location() const {return location;}


private:
    HotelInfo(QString name,Location loca,QString phone,QString url="NULL");
    void initialize(shared_ptr<HotelInfo> ptr);//让类自身保存一个weak引用

    QString name;
    Location location;
    QString phone;
    vector<Comment> Comments;
    vector<Room> rooms;
    QString url;

    weak_ptr<HotelInfo> thisWeakPtr;//自身信息的指针

    double price_average; //计算得出
};

#endif // HOTELINFO_H
