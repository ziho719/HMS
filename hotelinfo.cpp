#include "hotelinfo.h"

shared_ptr<HotelInfo> HotelInfo::newHotelInfo(QString name, Location loca, QString phone, QString url)
{
    shared_ptr<HotelInfo> p(new HotelInfo(name,loca,phone,url));
    p->initialize(p);
    return p;
}

shared_ptr<HotelInfo> HotelInfo::get_shared_ptr()
{
    auto s_ptr=thisWeakPtr.lock();
    //do sth
    return s_ptr;

}

void HotelInfo::edit_name(const QString &newname)
{
    name=newname;
}

void HotelInfo::edit_phone(const QString &newphone)
{
    phone=newphone;
}

void HotelInfo::edit_url(const QString &newurl)
{
    url=newurl;
}

void HotelInfo::edit_location(const Location &loca)
{
    location=loca;
}

shared_ptr<HotelInfo> HotelInfo::add_comment(const Comment &cm)
{
    Comments.push_back(cm);
    return get_shared_ptr();
}

shared_ptr<HotelInfo> HotelInfo::add_comment(const QString &user, const QString &text, int mark)
{
    Comments.push_back(Comment(user,text,mark));
    return get_shared_ptr();
}

shared_ptr<HotelInfo> HotelInfo::add_room(const Room &r)
{
    rooms.push_back(r);
    return get_shared_ptr();
}

shared_ptr<HotelInfo> HotelInfo::add_room(QString type, QString url, QString description, double price, int people, int sum, double discount)
{
    rooms.push_back(Room(type,url,description,price,people,sum,discount));
    return get_shared_ptr();
}

HotelInfo::HotelInfo(QString name, Location loca, QString phone, QString url)
    :name(name),location(loca),phone(phone),url(url){
    //什么都不做
}

void HotelInfo::initialize(shared_ptr<HotelInfo> ptr)
{
    thisWeakPtr=ptr;
}
