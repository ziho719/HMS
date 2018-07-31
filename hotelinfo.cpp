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

shared_ptr<HotelInfo> HotelInfo::add_comment(const QString &user, const QString &text, double mark)
{
    Comments.push_back(Comment(user,text,mark));
    return get_shared_ptr();
}

shared_ptr<HotelInfo> HotelInfo::add_room(Room *r)
{
    rooms.push_back(r);
    return get_shared_ptr();
}

shared_ptr<HotelInfo> HotelInfo::add_room(QString type, QString url, QString description, double price, int sum, double discount)
{
    rooms.push_back(new Room(type,url,description,price,sum,discount));
    return get_shared_ptr();
}

double HotelInfo::get_mark()
{
    size_t n=Comments.size();
    if(n==0) return 0;
    double count=0;
    for(int i=0;i<n;i++){
        count+=Comments[i].get_mark();
    }
    return count/n;
}

double HotelInfo::get_lowest_price()
{
    double res=1000000000;
    for(auto room:rooms){
        if(res>room->get_price()){
            res=room->get_price();
        }
    }
    return res;
}

void HotelInfo::add_roomSum(QString type)
{
    for(auto room:rooms){
        if(room->get_type()==type){
            room->add_sum();
        }
    }
}

void HotelInfo::reduce_roomSum(QString type)
{
    for(auto room:rooms){
        if(room->get_type()==type){
            room->reduce_sum();
        }
    }
}

bool HotelInfo::match(QString keyWord)
{
    QRegExp r("\\w*"+keyWord+"\\w*");
    if(r.exactMatch(name))
        return true;
    else{
        for(auto room:rooms){
            if(r.exactMatch(room->get_type()) ||r.exactMatch(room->get_description())){
                return true;
            }
        }
    }
    return false;
}

HotelInfo::HotelInfo(QString name, Location loca, QString phone, QString url)
    :name(name),location(loca),phone(phone),url(url){
    //什么都不做
}

void HotelInfo::initialize(shared_ptr<HotelInfo> ptr)
{
    thisWeakPtr=ptr;
}
